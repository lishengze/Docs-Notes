// OfpData.cpp: 
//
//////////////////////////////////////////////////////////////////////

#include "OfpData.h"


void dumpOFPField(COFPPingRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPPingRequest = {\n");
	char buffer[1024];
		pField->Date.getString(buffer);
		NET_PACKAGE_LOG1("\tDate = %s [���������]\n",buffer);
		pField->Time.getString(buffer);
		NET_PACKAGE_LOG1("\tTime = %s [�����ʱ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLoginRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPLoginRequest = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [����]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLoginV2RequestField *pField)
{
	NET_PACKAGE_LOG0("COFPLoginV2Request = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [����]\n",buffer);
		pField->Transferid.getString(buffer);
		NET_PACKAGE_LOG1("\tTransferid = %s [˽���������]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLoginResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPLoginResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա]\n",buffer);
		pField->Password.getString(buffer);
		NET_PACKAGE_LOG1("\tPassword = %s [����]\n",buffer);
		pField->Usernm.getString(buffer);
		NET_PACKAGE_LOG1("\tUsernm = %s [����Ա����]\n",buffer);
		pField->Localno0.getString(buffer);
		NET_PACKAGE_LOG1("\tLocalno0 = %s [����Ա����󱾵ر��]\n",buffer);
		pField->Time.getString(buffer);
		NET_PACKAGE_LOG1("\tTime = %s [����ϵͳʱ��]\n",buffer);
		pField->Sysstat.getString(buffer);
		NET_PACKAGE_LOG1("\tSysstat = %s [����ϵͳ״̬]\n",buffer);
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [������Ա]\n",buffer);
		pField->Section.getString(buffer);
		NET_PACKAGE_LOG1("\tSection = %s [��ǰ���״���]\n",buffer);
		pField->Sstatus.getString(buffer);
		NET_PACKAGE_LOG1("\tSstatus = %s [���׽�״̬]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLoginV2ResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPLoginV2Response = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա]\n",buffer);
		pField->Password.getString(buffer);
		NET_PACKAGE_LOG1("\tPassword = %s [����]\n",buffer);
		pField->Usernm.getString(buffer);
		NET_PACKAGE_LOG1("\tUsernm = %s [����Ա����]\n",buffer);
		pField->Date.getString(buffer);
		NET_PACKAGE_LOG1("\tDate = %s [��������]\n",buffer);
		pField->Time.getString(buffer);
		NET_PACKAGE_LOG1("\tTime = %s [����ϵͳʱ��]\n",buffer);
		pField->Sysstat.getString(buffer);
		NET_PACKAGE_LOG1("\tSysstat = %s [����ϵͳ״̬]\n",buffer);
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [������Ա]\n",buffer);
		pField->Section.getString(buffer);
		NET_PACKAGE_LOG1("\tSection = %s [��ǰ���״���]\n",buffer);
		pField->Sstatus.getString(buffer);
		NET_PACKAGE_LOG1("\tSstatus = %s [���׽�״̬]\n",buffer);
		pField->Localno0.getString(buffer);
		NET_PACKAGE_LOG1("\tLocalno0 = %s [����Ա����󱨵����ر��]\n",buffer);
		pField->Transferid.getString(buffer);
		NET_PACKAGE_LOG1("\tTransferid = %s [˽���������]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLoginErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPLoginErrorResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [����]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLoginV2ErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPLoginV2ErrorResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [����]\n",buffer);
		pField->Transferid.getString(buffer);
		NET_PACKAGE_LOG1("\tTransferid = %s [˽���������]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLogoutRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPLogoutRequest = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [����]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLogoutResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPLogoutResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [����]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLogoutErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPLogoutErrorResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [����]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPPasswordUpdateRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPPasswordUpdateRequest = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա]\n",buffer);
		pField->OldPasswd.getString(buffer);
		NET_PACKAGE_LOG1("\tOldPasswd = %s [�ɿ���]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [����]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPPasswordUpdateResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPPasswordUpdateResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա]\n",buffer);
		pField->OldPasswd.getString(buffer);
		NET_PACKAGE_LOG1("\tOldPasswd = %s [�ɿ���]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [����]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPPasswordUpdateErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPPasswordUpdateErrorResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա]\n",buffer);
		pField->OldPasswd.getString(buffer);
		NET_PACKAGE_LOG1("\tOldPasswd = %s [�ɿ���]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [����]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPSystemWarningField *pField)
{
	NET_PACKAGE_LOG0("COFPSystemWarning = {\n");
	char buffer[1024];
		pField->Content.getString(buffer);
		NET_PACKAGE_LOG1("\tContent = %s [������Ϣ]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderInsertRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderInsertRequest = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ���]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [�걨�۸�]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�걨����]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�����]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա����]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [���ر��]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [��������]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [��ƽ�ֱ�־]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [Ͷ����ֵ��־]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [δ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderInsertNotUseRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderInsertNotUseRequest = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ���]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [�걨�۸�]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�걨����]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�����]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա����]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [���ر��]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [��������]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [��ƽ�ֱ�־]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [Ͷ����ֵ��־]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [δ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderInsertResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderInsertResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ���]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [�걨�۸�]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�걨����]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�����]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա����]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [���ر��]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [��������]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [��ƽ�ֱ�־]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [Ͷ����ֵ��־]\n",buffer);
		pField->Back.getString(buffer);
		NET_PACKAGE_LOG1("\tBack = %s [δ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderInsertErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderInsertErrorResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ���]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [�걨�۸�]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�걨����]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�����]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա����]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [���ر��]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [��������]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [��ƽ�ֱ�־]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [Ͷ����ֵ��־]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [δ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderDelRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderDelRequest = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ���]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա����]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderDelResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderDelResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ���]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [�걨�۸�]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�걨����]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�����]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա����]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [���ر��]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [��������]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [��ƽ�ֱ�־]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [Ͷ����ֵ��־]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [δ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderDelErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderDelErrorResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ���]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [�걨�۸�]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�걨����]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�����]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա����]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [���ر��]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [��������]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [��ƽ�ֱ�־]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [Ͷ����ֵ��־]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [δ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderDelNotFoundResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderDelNotFoundResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ���]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա����]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPAuthorizedOrderDelRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPAuthorizedOrderDelRequest = {\n");
	char buffer[1024];
		pField->orderid.getString(buffer);
		NET_PACKAGE_LOG1("\torderid = %s [����ϵͳ��ţ�������]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPAuthorizedOrderDelResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPAuthorizedOrderDelResponse = {\n");
	char buffer[1024];
		pField->orderid.getString(buffer);
		NET_PACKAGE_LOG1("\torderid = %s [����ϵͳ��ţ�������]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [�걨�۸�]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�걨����]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�����]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա����]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [���ر��]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [��������]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [��ƽ�ֱ�־]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [Ͷ����ֵ��־]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [δ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPAuthorizedOrderDelErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPAuthorizedOrderDelErrorResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ��ţ�������]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [�걨�۸�]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�걨����]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�����]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա����]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [���ر��]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [��������]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [��ƽ�ֱ�־]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [Ͷ����ֵ��־]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [δ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInternationalMarketRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInternationalMarketRequest = {\n");
	char buffer[1024];
		pField->userid.getString(buffer);
		NET_PACKAGE_LOG1("\tuserid = %s [���������Ա]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInternationalMarketResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInternationalMarketResponse = {\n");
	char buffer[1024];
		pField->content.getString(buffer);
		NET_PACKAGE_LOG1("\tcontent = %s [�ı���Ϣ]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInternationalMarketErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInternationalMarketErrorResponse = {\n");
	char buffer[1024];
		pField->userid.getString(buffer);
		NET_PACKAGE_LOG1("\tuserid = %s [���������Ա]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryRubberMarketRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryRubberMarketRequest = {\n");
	char buffer[1024];
		pField->userid.getString(buffer);
		NET_PACKAGE_LOG1("\tuserid = %s [���������Ա]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryRubberMarketResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryRubberMarketResponse = {\n");
	char buffer[1024];
		pField->content.getString(buffer);
		NET_PACKAGE_LOG1("\tcontent = %s [�ı���Ϣ]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryRubberMarketErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryRubberMarketErrorResponse = {\n");
	char buffer[1024];
		pField->userid.getString(buffer);
		NET_PACKAGE_LOG1("\tuserid = %s [���������Ա]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPMBackOrderField *pField)
{
	NET_PACKAGE_LOG0("COFPMBackOrder = {\n");
	char buffer[1024];
		pField->mqid.getString(buffer);
		NET_PACKAGE_LOG1("\tmqid = %s [˽�������к�]\n",buffer);
		pField->cmd.getString(buffer);
		NET_PACKAGE_LOG1("\tcmd = %s [��Ϣ����]\n",buffer);
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ���]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [�걨�۸�]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�걨����]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�����]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա����]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [���ر��]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [��������]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [��ƽ�ֱ�־]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [Ͷ����ֵ��־]\n",buffer);
		pField->Orderf.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderf = %s [����״̬]\n",buffer);
		pField->Orderd.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderd = %s [����¼������]\n",buffer);
		pField->Ordert.getString(buffer);
		NET_PACKAGE_LOG1("\tOrdert = %s [����¼��ʱ��]\n",buffer);
		pField->Orderdt.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderdt = %s [����ɾ��ʱ��]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [δ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPMBackOrderErrorField *pField)
{
	NET_PACKAGE_LOG0("COFPMBackOrderError = {\n");
	char buffer[1024];
		pField->mqid.getString(buffer);
		NET_PACKAGE_LOG1("\tmqid = %s [˽�������к�]\n",buffer);
		pField->cmd.getString(buffer);
		NET_PACKAGE_LOG1("\tcmd = %s [��Ϣ����]\n",buffer);
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ���]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [�걨�۸�]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�걨����]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�����]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա����]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [���ر��]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [��������]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [��ƽ�ֱ�־]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [Ͷ����ֵ��־]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [δ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPTradeInsertField *pField)
{
	NET_PACKAGE_LOG0("COFPTradeInsert = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ���]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [��������]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�����걨����]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [�����걨�۸�]\n",buffer);
		pField->Compv.getString(buffer);
		NET_PACKAGE_LOG1("\tCompv = %s [������ǰ�ɽ�����]\n",buffer);
		pField->Compp.getString(buffer);
		NET_PACKAGE_LOG1("\tCompp = %s [������ǰ�ɽ��۸�]\n",buffer);
		pField->Balance.getString(buffer);
		NET_PACKAGE_LOG1("\tBalance = %s [����δ�ɽ�ʣ������]\n",buffer);
		pField->Comps.getString(buffer);
		NET_PACKAGE_LOG1("\tComps = %s [δ��]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�����]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա����]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [���ر��]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [��ƽ�ֱ�־]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [Ͷ����ֵ��־]\n",buffer);
		pField->Matcno.getString(buffer);
		NET_PACKAGE_LOG1("\tMatcno = %s [��ǰ��ϱ��]\n",buffer);
		pField->Compd.getString(buffer);
		NET_PACKAGE_LOG1("\tCompd = %s [�������]\n",buffer);
		pField->Compt.getString(buffer);
		NET_PACKAGE_LOG1("\tCompt = %s [���ʱ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPMBackTradeField *pField)
{
	NET_PACKAGE_LOG0("COFPMBackTrade = {\n");
	char buffer[1024];
		pField->mqid.getString(buffer);
		NET_PACKAGE_LOG1("\tmqid = %s [˽�������к�]\n",buffer);
		pField->cmd.getString(buffer);
		NET_PACKAGE_LOG1("\tcmd = %s [��Ϣ����]\n",buffer);
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ���]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [��������]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�����걨����]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [�����걨�۸�]\n",buffer);
		pField->Compv.getString(buffer);
		NET_PACKAGE_LOG1("\tCompv = %s [������ǰ�ɽ�����]\n",buffer);
		pField->Compp.getString(buffer);
		NET_PACKAGE_LOG1("\tCompp = %s [������ǰ�ɽ��۸�]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�����]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա����]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [���ر��]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [��ƽ�ֱ�־]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [Ͷ����ֵ��־]\n",buffer);
		pField->Matcno.getString(buffer);
		NET_PACKAGE_LOG1("\tMatcno = %s [��ǰ��ϱ��]\n",buffer);
		pField->Compd.getString(buffer);
		NET_PACKAGE_LOG1("\tCompd = %s [�������]\n",buffer);
		pField->Compt.getString(buffer);
		NET_PACKAGE_LOG1("\tCompt = %s [���ʱ��]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [δ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryDepositRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryDepositRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryDepositResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryDepositResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��Ա]\n",buffer);
		pField->Margit.getString(buffer);
		NET_PACKAGE_LOG1("\tMargit = %s [�ճ��ʽ�]\n",buffer);
		pField->Credii.getString(buffer);
		NET_PACKAGE_LOG1("\tCredii = %s [δʹ��]\n",buffer);
		pField->Buymar.getString(buffer);
		NET_PACKAGE_LOG1("\tBuymar = %s [����ʹ���ʽ�]\n",buffer);
		pField->Sellma.getString(buffer);
		NET_PACKAGE_LOG1("\tSellma = %s [����ʹ���ʽ�]\n",buffer);
		pField->Totall.getString(buffer);
		NET_PACKAGE_LOG1("\tTotall = %s [����ʹ���ʽ�]\n",buffer);
		pField->Closec.getString(buffer);
		NET_PACKAGE_LOG1("\tClosec = %s [ʣ������ʽ�]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryDepositErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryDepositErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryHedgeRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryHedgeRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryHedgeResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryHedgeResponse = {\n");
	char buffer[1024];
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [����Ա������Ա�Ŀͻ�����]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Brequam.getString(buffer);
		NET_PACKAGE_LOG1("\tBrequam = %s [��ֵ����������]\n",buffer);
		pField->Buseram.getString(buffer);
		NET_PACKAGE_LOG1("\tBuseram = %s [��ֵ���ʹ�ö���]\n",buffer);
		pField->Bbalance.getString(buffer);
		NET_PACKAGE_LOG1("\tBbalance = %s [��ֵ���ʣ�����]\n",buffer);
		pField->Srequam.getString(buffer);
		NET_PACKAGE_LOG1("\tSrequam = %s [����ֵ����������]\n",buffer);
		pField->Suseram.getString(buffer);
		NET_PACKAGE_LOG1("\tSuseram = %s [����ֵ���ʹ�ö���]\n",buffer);
		pField->Sbalance.getString(buffer);
		NET_PACKAGE_LOG1("\tSbalance = %s [����ֵ���ʣ�����]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryHedgeErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryHedgeErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryHedgeV2RequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryHedgeV2Request = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryHedgeV2ResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryHedgeV2Response = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [����Ա������Ա����]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [����Ա������Ա�Ŀͻ�����]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Brequam.getString(buffer);
		NET_PACKAGE_LOG1("\tBrequam = %s [��ֵ����������]\n",buffer);
		pField->Buseram.getString(buffer);
		NET_PACKAGE_LOG1("\tBuseram = %s [��ֵ���ʹ�ö���]\n",buffer);
		pField->Bbalance.getString(buffer);
		NET_PACKAGE_LOG1("\tBbalance = %s [��ֵ���ʣ�����]\n",buffer);
		pField->Srequam.getString(buffer);
		NET_PACKAGE_LOG1("\tSrequam = %s [����ֵ����������]\n",buffer);
		pField->Suseram.getString(buffer);
		NET_PACKAGE_LOG1("\tSuseram = %s [����ֵ���ʹ�ö���]\n",buffer);
		pField->Sbalance.getString(buffer);
		NET_PACKAGE_LOG1("\tSbalance = %s [����ֵ���ʣ�����]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryHedgeV2ErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryHedgeV2ErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryClientRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryClientRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryClientResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryClientResponse = {\n");
	char buffer[1024];
		pField->Rstus.getString(buffer);
		NET_PACKAGE_LOG1("\tRstus = %s [δ��]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�����]\n",buffer);
		pField->Custnm.getString(buffer);
		NET_PACKAGE_LOG1("\tCustnm = %s [�ͻ�����]\n",buffer);
		pField->Custad.getString(buffer);
		NET_PACKAGE_LOG1("\tCustad = %s [�ͻ���ַ]\n",buffer);
		pField->Custtel.getString(buffer);
		NET_PACKAGE_LOG1("\tCusttel = %s [�ͻ���ϵ�绰]\n",buffer);
		pField->Tradtp.getString(buffer);
		NET_PACKAGE_LOG1("\tTradtp = %s [�ͻ���ҵ����]\n",buffer);
		pField->Reprnm.getString(buffer);
		NET_PACKAGE_LOG1("\tReprnm = %s [���˴���]\n",buffer);
		pField->custle.getString(buffer);
		NET_PACKAGE_LOG1("\tcustle = %s [�ͻ���־]\n",buffer);
		pField->Emplid.getString(buffer);
		NET_PACKAGE_LOG1("\tEmplid = %s [������Ա]\n",buffer);
		pField->Credit.getString(buffer);
		NET_PACKAGE_LOG1("\tCredit = %s [δ��]\n",buffer);
		pField->Trades.getString(buffer);
		NET_PACKAGE_LOG1("\tTrades = %s [�Ƿ�������]\n",buffer);
		pField->Tradau.getString(buffer);
		NET_PACKAGE_LOG1("\tTradau = %s [δ��]\n",buffer);
		pField->Indate.getString(buffer);
		NET_PACKAGE_LOG1("\tIndate = %s [��������]\n",buffer);
		pField->Modate.getString(buffer);
		NET_PACKAGE_LOG1("\tModate = %s [δ��]\n",buffer);
		pField->Instaff.getString(buffer);
		NET_PACKAGE_LOG1("\tInstaff = %s [δ��]\n",buffer);
		pField->Mostaff.getString(buffer);
		NET_PACKAGE_LOG1("\tMostaff = %s [δ��]\n",buffer);
		pField->Comple.getString(buffer);
		NET_PACKAGE_LOG1("\tComple = %s [�ͻ�����]\n",buffer);
		pField->Regisf.getString(buffer);
		NET_PACKAGE_LOG1("\tRegisf = %s [ע�ᣯӪ���ʽ�]\n",buffer);
		pField->Floortr.getString(buffer);
		NET_PACKAGE_LOG1("\tFloortr = %s [δ��]\n",buffer);
		pField->Zjhm.getString(buffer);
		NET_PACKAGE_LOG1("\tZjhm = %s [֤����������֤����]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryClientErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryClientErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInstrumentRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInstrumentRequest = {\n");
	char buffer[1024];
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInstrumentResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInstrumentResponse = {\n");
	char buffer[1024];
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ�ִ���]\n",buffer);
		pField->Commnm.getString(buffer);
		NET_PACKAGE_LOG1("\tCommnm = %s [����Ʒ������]\n",buffer);
		pField->Delim.getString(buffer);
		NET_PACKAGE_LOG1("\tDelim = %s [�����·ݣ���ʽΪyymm��space��2��]\n",buffer);
		pField->Abbr.getString(buffer);
		NET_PACKAGE_LOG1("\tAbbr = %s [����Ʒ�ֵ����ֱ��룬�确01��Ϊͭ]\n",buffer);
		pField->Trade.getString(buffer);
		NET_PACKAGE_LOG1("\tTrade = %s [ÿ���������֣�]\n",buffer);
		pField->Tick.getString(buffer);
		NET_PACKAGE_LOG1("\tTick = %s [��С�䶯��λ]\n",buffer);
		pField->Daill.getString(buffer);
		NET_PACKAGE_LOG1("\tDaill = %s [δ�ã�Ӧ�����ǵ�ͣ����]\n",buffer);
		pField->Closed.getString(buffer);
		NET_PACKAGE_LOG1("\tClosed = %s [δ�ã�Ӧ���Ǳ�ֵƽ������ʼ����]\n",buffer);
		pField->Commtp.getString(buffer);
		NET_PACKAGE_LOG1("\tCommtp = %s [Ʒ�����ͣ���f����F���ڻ�������]\n",buffer);
		pField->Stard.getString(buffer);
		NET_PACKAGE_LOG1("\tStard = %s [��ʼ��������]\n",buffer);
		pField->Delid.getString(buffer);
		NET_PACKAGE_LOG1("\tDelid = %s [��ʼ��������]\n",buffer);
		pField->Stopd.getString(buffer);
		NET_PACKAGE_LOG1("\tStopd = %s [������������]\n",buffer);
		pField->Posil.getString(buffer);
		NET_PACKAGE_LOG1("\tPosil = %s [������������걨����]\n",buffer);
		pField->Commst.getString(buffer);
		NET_PACKAGE_LOG1("\tCommst = %s [Ʒ�ֽ���״̬����a����������������]\n",buffer);
		pField->Lastde.getString(buffer);
		NET_PACKAGE_LOG1("\tLastde = %s [������������]\n",buffer);
		pField->Margin.getString(buffer);
		NET_PACKAGE_LOG1("\tMargin = %s [δ�ã�Ϊ��1��00��]\n",buffer);
		pField->Sxfl.getString(buffer);
		NET_PACKAGE_LOG1("\tSxfl = %s [δ�ã�Ϊ��0��00��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInstrumentErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInstrumentErrorResponse = {\n");
	char buffer[1024];
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryAuthorizedOrderRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryAuthorizedOrderRequest = {\n");
	char buffer[1024];
		pField->username.getString(buffer);
		NET_PACKAGE_LOG1("\tusername = %s [ָ������Ա���Ա�ı���]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryAuthorizedOrderResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryAuthorizedOrderResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ���]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [�������򣬡�b���򣯡�s����]\n",buffer);
		pField->Orderf.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderf = %s [����״̬����o����Ч����]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [��ƽ�ֱ�־]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [Ͷ����ֵ��־����0����ֵ����1��Ͷ��]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�����걨����]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [�����걨�۸�]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�]\n",buffer);
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��Ա]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա]\n",buffer);
		pField->Compv.getString(buffer);
		NET_PACKAGE_LOG1("\tCompv = %s [�ܳɽ�����]\n",buffer);
		pField->Compp.getString(buffer);
		NET_PACKAGE_LOG1("\tCompp = %s [���һ�ʳɽ��۸�]\n",buffer);
		pField->Ordert.getString(buffer);
		NET_PACKAGE_LOG1("\tOrdert = %s [����ʱ��]\n",buffer);
		pField->DOrdt.getString(buffer);
		NET_PACKAGE_LOG1("\tDOrdt = %s [����ɾ��ʱ��]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [�������ر��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryAuthorizedOrderErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryAuthorizedOrderErrorResponse = {\n");
	char buffer[1024];
		pField->username.getString(buffer);
		NET_PACKAGE_LOG1("\tusername = %s [ָ������Ա���Ա�ı���]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryOrderRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryOrderRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryAllOrderRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryAllOrderRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryOrderResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryOrderResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ���]\n",buffer);
		pField->Ordert.getString(buffer);
		NET_PACKAGE_LOG1("\tOrdert = %s [�����걨ʱ��]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Delim.getString(buffer);
		NET_PACKAGE_LOG1("\tDelim = %s [�����·ݣ�δ��]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [�������򣬡�b���򣯡�s����]\n",buffer);
		pField->Orderf.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderf = %s [����״̬����o����Ч����]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�����걨����]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [�����걨�۸�]\n",buffer);
		pField->Compv.getString(buffer);
		NET_PACKAGE_LOG1("\tCompv = %s [�ܳɽ�����]\n",buffer);
		pField->Compp.getString(buffer);
		NET_PACKAGE_LOG1("\tCompp = %s [���һ�ʳɽ��۸�]\n",buffer);
		pField->Balance.getString(buffer);
		NET_PACKAGE_LOG1("\tBalance = %s [����ʣ������]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�����]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [�������ر��]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [��ƽ�ֱ�־]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [Ͷ����ֵ��־����0����ֵ����1��Ͷ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryOrderErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryOrderErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryTradeRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryTradeRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryTradeResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryTradeResponse = {\n");
	char buffer[1024];
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [�������ر��]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [������־����b���򣯡�s����]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [��ƽ�ֱ�־]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [Ͷ����ֵ��־����0����ֵ����1��Ͷ��]\n",buffer);
		pField->Compv.getString(buffer);
		NET_PACKAGE_LOG1("\tCompv = %s [�ܳɽ�����]\n",buffer);
		pField->Compp.getString(buffer);
		NET_PACKAGE_LOG1("\tCompp = %s [���һ�ʳɽ��۸�]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ�����]\n",buffer);
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [����Ա]\n",buffer);
		pField->Compd.getString(buffer);
		NET_PACKAGE_LOG1("\tCompd = %s [�ɽ����ڣ���ʽccyymmdd]\n",buffer);
		pField->Compt.getString(buffer);
		NET_PACKAGE_LOG1("\tCompt = %s [�ɽ�ʱ�䣬��ʽhhmmssuu]\n",buffer);
		pField->Matcno.getString(buffer);
		NET_PACKAGE_LOG1("\tMatcno = %s [��ϱ��]\n",buffer);
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [����ϵͳ���]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�����걨����]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [�����걨�۸�]\n",buffer);
		pField->Ordert.getString(buffer);
		NET_PACKAGE_LOG1("\tOrdert = %s [����ʱ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryTradeErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryTradeErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryPPositionRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryPPositionRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [��ѯѡ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryPPositionResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryPPositionResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��Ա����]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ����룬ΪASCII�ո�]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Buyvb.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvb = %s [��ֵ����]\n",buffer);
		pField->Buyvt.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvt = %s [��Ͷ������]\n",buffer);
		pField->Sellvb.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvb = %s [����ֵ����]\n",buffer);
		pField->Sellvt.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvt = %s [��Ͷ������]\n",buffer);
		pField->Openbvb.getString(buffer);
		NET_PACKAGE_LOG1("\tOpenbvb = %s [����ֵ�¿�������]\n",buffer);
		pField->Openbvt.getString(buffer);
		NET_PACKAGE_LOG1("\tOpenbvt = %s [����Ͷ���¿�������]\n",buffer);
		pField->Opensvb.getString(buffer);
		NET_PACKAGE_LOG1("\tOpensvb = %s [������ֵ�¿�������]\n",buffer);
		pField->Opensvt.getString(buffer);
		NET_PACKAGE_LOG1("\tOpensvt = %s [����Ͷ���¿�������]\n",buffer);
		pField->Fbuyvb.getString(buffer);
		NET_PACKAGE_LOG1("\tFbuyvb = %s [��ֵ����ֲ�����]\n",buffer);
		pField->Fbuyvt.getString(buffer);
		NET_PACKAGE_LOG1("\tFbuyvt = %s [��Ͷ������ֲ�����]\n",buffer);
		pField->Fsellvb.getString(buffer);
		NET_PACKAGE_LOG1("\tFsellvb = %s [����ֵ����ֲ�����]\n",buffer);
		pField->Fsellvt.getString(buffer);
		NET_PACKAGE_LOG1("\tFsellvt = %s [��Ͷ������ֲ�����]\n",buffer);
		pField->Clearp.getString(buffer);
		NET_PACKAGE_LOG1("\tClearp = %s [ǰ�����ս����]\n",buffer);
		pField->Margamb.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamb = %s [δ�ã���ֵʹ�ñ�֤�𣨸�ʽ��15��2f��]\n",buffer);
		pField->Margamt.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamt = %s [δ�ã�Ͷ��ʹ�ñ�֤�𣨸�ʽ��15��2f��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryPPositionErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryPPositionErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [��ѯѡ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryBriefPPositionRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryBriefPPositionRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [��ѯѡ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryBriefPPositionResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryBriefPPositionResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��Ա����]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Buyvb.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvb = %s [��ֵ����]\n",buffer);
		pField->Buyvt.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvt = %s [��Ͷ������]\n",buffer);
		pField->Sellvb.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvb = %s [����ֵ����]\n",buffer);
		pField->Sellvt.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvt = %s [��Ͷ������]\n",buffer);
		pField->Clearp.getString(buffer);
		NET_PACKAGE_LOG1("\tClearp = %s [ǰ�����ս����]\n",buffer);
		pField->Margamb.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamb = %s [δ�ã���ֵʹ�ñ�֤�𣨸�ʽ��15��2f��]\n",buffer);
		pField->Margamt.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamt = %s [δ�ã�Ͷ��ʹ�ñ�֤�𣨸�ʽ��15��2f��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryBriefPPositionErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryBriefPPositionErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [��ѯѡ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryPositionRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryPositionRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [��ѯ��ʼ�ͻ�]\n",buffer);
		pField->Custidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCustidt = %s [��ѯ�����ͻ�]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [��ѯѡ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryPositionResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryPositionResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��Ա����]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ����룬ΪASCII�ո�]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Buyvb.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvb = %s [��ֵ����]\n",buffer);
		pField->Buyvt.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvt = %s [��Ͷ������]\n",buffer);
		pField->Sellvb.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvb = %s [����ֵ����]\n",buffer);
		pField->Sellvt.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvt = %s [��Ͷ������]\n",buffer);
		pField->Openbvb.getString(buffer);
		NET_PACKAGE_LOG1("\tOpenbvb = %s [����ֵ�¿�������]\n",buffer);
		pField->Openbvt.getString(buffer);
		NET_PACKAGE_LOG1("\tOpenbvt = %s [����Ͷ���¿�������]\n",buffer);
		pField->Opensvb.getString(buffer);
		NET_PACKAGE_LOG1("\tOpensvb = %s [������ֵ�¿�������]\n",buffer);
		pField->Opensvt.getString(buffer);
		NET_PACKAGE_LOG1("\tOpensvt = %s [����Ͷ���¿�������]\n",buffer);
		pField->Fbuyvb.getString(buffer);
		NET_PACKAGE_LOG1("\tFbuyvb = %s [��ֵ����ֲ�����]\n",buffer);
		pField->Fbuyvt.getString(buffer);
		NET_PACKAGE_LOG1("\tFbuyvt = %s [��Ͷ������ֲ�����]\n",buffer);
		pField->Fsellvb.getString(buffer);
		NET_PACKAGE_LOG1("\tFsellvb = %s [����ֵ����ֲ�����]\n",buffer);
		pField->Fsellvt.getString(buffer);
		NET_PACKAGE_LOG1("\tFsellvt = %s [��Ͷ������ֲ�����]\n",buffer);
		pField->Clearp.getString(buffer);
		NET_PACKAGE_LOG1("\tClearp = %s [ǰ�����ս����]\n",buffer);
		pField->Margamb.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamb = %s [δ�ã���ֵʹ�ñ�֤�𣨸�ʽ��15��2f��]\n",buffer);
		pField->Margamt.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamt = %s [δ�ã�Ͷ��ʹ�ñ�֤�𣨸�ʽ��15��2f��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryPositionErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryPositionErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [��ѯ��ʼ�ͻ�]\n",buffer);
		pField->Custidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCustidt = %s [��ѯ�����ͻ�]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [��ѯѡ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryBriefPositionRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryBriefPositionRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [��ѯ��ʼ�ͻ�]\n",buffer);
		pField->Custidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCustidt = %s [��ѯ�����ͻ�]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [��ѯѡ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryBriefPositionResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryBriefPositionResponse = {\n");
	char buffer[1024];
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [�ͻ����룬ΪASCII�ո�]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Buyvb.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvb = %s [��ֵ����]\n",buffer);
		pField->Buyvt.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvt = %s [��Ͷ������]\n",buffer);
		pField->Sellvb.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvb = %s [����ֵ����]\n",buffer);
		pField->Sellvt.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvt = %s [��Ͷ������]\n",buffer);
		pField->Clearp.getString(buffer);
		NET_PACKAGE_LOG1("\tClearp = %s [ǰ�����ս����]\n",buffer);
		pField->Margamb.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamb = %s [δ�ã���ֵʹ�ñ�֤�𣨸�ʽ��15��2f��]\n",buffer);
		pField->Margamt.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamt = %s [δ�ã�Ͷ��ʹ�ñ�֤�𣨸�ʽ��15��2f��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryBriefPositionErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryBriefPositionErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��ѯ��ʼ��Ա]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [��ѯ������Ա]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [��ѯ��ʼ�ͻ�]\n",buffer);
		pField->Custidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCustidt = %s [��ѯ�����ͻ�]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [��ѯѡ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInstrumentPriceRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInstrumentPriceRequest = {\n");
	char buffer[1024];
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [��ѯѡ��]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInstrumentPriceResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInstrumentPriceResponse = {\n");
	char buffer[1024];
		pField->Bsflag.getString(buffer);
		NET_PACKAGE_LOG1("\tBsflag = %s [�������ۣ���b���򣯡�s����]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [����Ʒ��]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [����]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [�����걨����]\n",buffer);
		pField->Compv.getString(buffer);
		NET_PACKAGE_LOG1("\tCompv = %s [���гɽ�����]\n",buffer);
		pField->Cancelv.getString(buffer);
		NET_PACKAGE_LOG1("\tCancelv = %s [���г�������]\n",buffer);
		pField->Currentv.getString(buffer);
		NET_PACKAGE_LOG1("\tCurrentv = %s [������Ч����]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInstrumentPriceErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInstrumentPriceErrorResponse = {\n");
	char buffer[1024];
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [��ѯ��ʼ����Ʒ��]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [��ѯ��������Ʒ��]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [��ѯѡ��]\n",buffer);
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
		NET_PACKAGE_LOG1("\trstus = %s [δ�ã�Ϊ������]\n",buffer);
		pField->comm.getString(buffer);
		NET_PACKAGE_LOG1("\tcomm = %s [����Ʒ�ִ�����룬�确cu������al����]\n",buffer);
		pField->abbrev.getString(buffer);
		NET_PACKAGE_LOG1("\tabbrev = %s [����Ʒ�ִ������ִ��룬�确01������02����]\n",buffer);
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
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա�û�]\n",buffer);
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��Ա���]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryTrasnferIdResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryTrasnferIdResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա�û�]\n",buffer);
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��Ա���]\n",buffer);
		pField->Transferid.getString(buffer);
		NET_PACKAGE_LOG1("\tTransferid = %s [����ϵͳ��Ա˽�����ر�Ŀǰ�����]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryTrasnferIdErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryTrasnferIdErrorResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [����Ա�û�]\n",buffer);
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [��Ա���]\n",buffer);
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
		NET_PACKAGE_LOG1("\trstatus = %s [δʹ�ã�Ϊ������]\n",buffer);
		pField->sectid.getString(buffer);
		NET_PACKAGE_LOG1("\tsectid = %s [���׽�]\n",buffer);
		pField->desc.getString(buffer);
		NET_PACKAGE_LOG1("\tdesc = %s [���׽�����]\n",buffer);
		pField->sects0.getString(buffer);
		NET_PACKAGE_LOG1("\tsects0 = %s [���׽�״̬]\n",buffer);
		pField->sects1.getString(buffer);
		NET_PACKAGE_LOG1("\tsects1 = %s [���׽��Ƿ����̼��Ͼ��۳�ʼ����־����1���ǣ�������]\n",buffer);
		pField->f2.getString(buffer);
		NET_PACKAGE_LOG1("\tf2 = %s [δʹ�ã�Ϊ������]\n",buffer);
		pField->starttime.getString(buffer);
		NET_PACKAGE_LOG1("\tstarttime = %s [�ͻ��˲���֪������]\n",buffer);
		pField->endtime.getString(buffer);
		NET_PACKAGE_LOG1("\tendtime = %s [�ͻ��˲���֪������]\n",buffer);
		pField->cu.getString(buffer);
		NET_PACKAGE_LOG1("\tcu = %s [����ͭ�Ƿ��ף���1�����ף�������]\n",buffer);
		pField->al.getString(buffer);
		NET_PACKAGE_LOG1("\tal = %s [�������Ƿ��ף���1�����ף�������]\n",buffer);
		pField->ru.getString(buffer);
		NET_PACKAGE_LOG1("\tru = %s [�������Ƿ��ף���1�����ף�������]\n",buffer);
		pField->pw.getString(buffer);
		NET_PACKAGE_LOG1("\tpw = %s [���ڼװ��Ƿ��ף���1�����ף�������]\n",buffer);
		pField->rc.getString(buffer);
		NET_PACKAGE_LOG1("\trc = %s [���������Ƿ��ף���1�����ף�������]\n",buffer);
		pField->f3.getString(buffer);
		NET_PACKAGE_LOG1("\tf3 = %s [δʹ�ã�Ϊ������]\n",buffer);
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

