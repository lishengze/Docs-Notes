// OfpData.h: 
//
//////////////////////////////////////////////////////////////////////

#if !defined(_OFPDATA_H)
#define _OFPDATA_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OFPDataType.h"

//����ָ��
const WORD OFP_VARY_PingRequest = 0x9999;

struct COFPPingRequestField
{
	//���������
	COFPStringType<8> Date;
	//�����ʱ��
	COFPStringType<6> Time;
};

void dumpOFPField(COFPPingRequestField *pField);

//�û���¼ָ��
const WORD OFP_VARY_LoginRequest = 0x0401;

struct COFPLoginRequestField
{
	//����Ա
	COFPStringType<15> Userid;
	//����
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPLoginRequestField *pField);

//�û���¼ָ��
const WORD OFP_VARY_LoginV2Request = 0x0401;

struct COFPLoginV2RequestField
{
	//����Ա
	COFPStringType<15> Userid;
	//����
	COFPStringType<40> Passwd;
	//˽���������
	COFPNumberType<8> Transferid;
};

void dumpOFPField(COFPLoginV2RequestField *pField);

//�û���¼Ӧ��
const WORD OFP_VARY_LoginResponse = 0x0501;

struct COFPLoginResponseField
{
	//����Ա
	COFPStringType<15> Userid;
	//����
	COFPStringType<40> Password;
	//����Ա����
	COFPStringType<8> Usernm;
	//����Ա����󱾵ر��
	COFPStringType<8> Localno0;
	//����ϵͳʱ��
	COFPStringType<8> Time;
	//����ϵͳ״̬
	COFPNumberType<8> Sysstat;
	//������Ա
	COFPStringType<8> Membid;
	//��ǰ���״���
	COFPStringType<2> Section;
	//���׽�״̬
	COFPCharType Sstatus;
};

void dumpOFPField(COFPLoginResponseField *pField);

//�û���¼Ӧ��
const WORD OFP_VARY_LoginV2Response = 0x0501;

struct COFPLoginV2ResponseField
{
	//����Ա
	COFPStringType<15> Userid;
	//����
	COFPStringType<40> Password;
	//����Ա����
	COFPStringType<8> Usernm;
	//��������
	COFPStringType<8> Date;
	//����ϵͳʱ��
	COFPStringType<8> Time;
	//����ϵͳ״̬
	COFPNumberType<8> Sysstat;
	//������Ա
	COFPStringType<8> Membid;
	//��ǰ���״���
	COFPStringType<2> Section;
	//���׽�״̬
	COFPCharType Sstatus;
	//����Ա����󱨵����ر��
	COFPStringType<8> Localno0;
	//˽���������
	COFPNumberType<8> Transferid;
};

void dumpOFPField(COFPLoginV2ResponseField *pField);

//�û���¼ʧ��Ӧ��
const WORD OFP_VARY_LoginErrorResponse = 0x0501;

struct COFPLoginErrorResponseField
{
	//����Ա
	COFPStringType<15> Userid;
	//����
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPLoginErrorResponseField *pField);

//�û���¼ʧ��Ӧ��
const WORD OFP_VARY_LoginV2ErrorResponse = 0x0501;

struct COFPLoginV2ErrorResponseField
{
	//����Ա
	COFPStringType<15> Userid;
	//����
	COFPStringType<40> Passwd;
	//˽���������
	COFPNumberType<8> Transferid;
};

void dumpOFPField(COFPLoginV2ErrorResponseField *pField);

//�û���¼�˳�ָ��
const WORD OFP_VARY_LogoutRequest = 0x0407;

struct COFPLogoutRequestField
{
	//����Ա
	COFPStringType<15> Userid;
	//����
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPLogoutRequestField *pField);

//�û���¼�˳�Ӧ��
const WORD OFP_VARY_LogoutResponse = 0x0507;

struct COFPLogoutResponseField
{
	//����Ա
	COFPStringType<15> Userid;
	//����
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPLogoutResponseField *pField);

//�û���¼�˳�ʧ��Ӧ��
const WORD OFP_VARY_LogoutErrorResponse = 0x0507;

struct COFPLogoutErrorResponseField
{
	//����Ա
	COFPStringType<15> Userid;
	//����
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPLogoutErrorResponseField *pField);

//�û������޸�ָ��
const WORD OFP_VARY_PasswordUpdateRequest = 0x0220;

struct COFPPasswordUpdateRequestField
{
	//����Ա
	COFPStringType<15> Userid;
	//�ɿ���
	COFPStringType<40> OldPasswd;
	//����
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPPasswordUpdateRequestField *pField);

//�û������޸�Ӧ��
const WORD OFP_VARY_PasswordUpdateResponse = 0x0320;

struct COFPPasswordUpdateResponseField
{
	//����Ա
	COFPStringType<15> Userid;
	//�ɿ���
	COFPStringType<40> OldPasswd;
	//����
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPPasswordUpdateResponseField *pField);

//�û������޸�ʧ��Ӧ��
const WORD OFP_VARY_PasswordUpdateErrorResponse = 0x0320;

struct COFPPasswordUpdateErrorResponseField
{
	//����Ա
	COFPStringType<15> Userid;
	//�ɿ���
	COFPStringType<40> OldPasswd;
	//����
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPPasswordUpdateErrorResponseField *pField);

//ϵͳ����
const WORD OFP_VARY_SystemWarning = 0x2310;

struct COFPSystemWarningField
{
	//������Ϣ
	COFPStringType<70> Content;
};

void dumpOFPField(COFPSystemWarningField *pField);

//����¼��ָ��
const WORD OFP_VARY_OrderInsertRequest = 0x0202;

struct COFPOrderInsertRequestField
{
	//����ϵͳ���
	COFPStringType<8> Orderid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//�걨�۸�
	COFPNumberType<6> Orderp;
	//�걨����
	COFPNumberType<6> Orderv;
	//�ͻ�����
	COFPStringType<8> Custid;
	//����Ա����
	COFPStringType<15> Userid;
	//���ر��
	COFPStringType<8> Lorderid;
	//��������
	COFPCharType Posit;
	//��ƽ�ֱ�־
	COFPCharType Closef;
	//Ͷ����ֵ��־
	COFPCharType Tjbz;
	//δ��
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPOrderInsertRequestField *pField);

//����¼��ָ��
const WORD OFP_VARY_OrderInsertNotUseRequest = 0x0202;

struct COFPOrderInsertNotUseRequestField
{
	//����ϵͳ���
	COFPStringType<8> Orderid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//�걨�۸�
	COFPNumberType<6> Orderp;
	//�걨����
	COFPNumberType<6> Orderv;
	//�ͻ�����
	COFPStringType<8> Custid;
	//����Ա����
	COFPStringType<15> Userid;
	//���ر��
	COFPStringType<8> Lorderid;
	//��������
	COFPCharType Posit;
	//��ƽ�ֱ�־
	COFPCharType Closef;
	//Ͷ����ֵ��־
	COFPCharType Tjbz;
	//δ��
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPOrderInsertNotUseRequestField *pField);

//����¼��Ӧ��
const WORD OFP_VARY_OrderInsertResponse = 0x0302;

struct COFPOrderInsertResponseField
{
	//����ϵͳ���
	COFPStringType<8> Orderid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//�걨�۸�
	COFPNumberType<6> Orderp;
	//�걨����
	COFPNumberType<6> Orderv;
	//�ͻ�����
	COFPStringType<8> Custid;
	//����Ա����
	COFPStringType<15> Userid;
	//���ر��
	COFPStringType<8> Lorderid;
	//��������
	COFPCharType Posit;
	//��ƽ�ֱ�־
	COFPCharType Closef;
	//Ͷ����ֵ��־
	COFPCharType Tjbz;
	//δ��
	COFPStringType<10> Back;
};

void dumpOFPField(COFPOrderInsertResponseField *pField);

//����¼��ʧ��Ӧ��
const WORD OFP_VARY_OrderInsertErrorResponse = 0x0302;

struct COFPOrderInsertErrorResponseField
{
	//����ϵͳ���
	COFPStringType<8> Orderid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//�걨�۸�
	COFPNumberType<6> Orderp;
	//�걨����
	COFPNumberType<6> Orderv;
	//�ͻ�����
	COFPStringType<8> Custid;
	//����Ա����
	COFPStringType<15> Userid;
	//���ر��
	COFPStringType<8> Lorderid;
	//��������
	COFPCharType Posit;
	//��ƽ�ֱ�־
	COFPCharType Closef;
	//Ͷ����ֵ��־
	COFPCharType Tjbz;
	//δ��
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPOrderInsertErrorResponseField *pField);

//����ɾ��ָ��
const WORD OFP_VARY_OrderDelRequest = 0x0203;

struct COFPOrderDelRequestField
{
	//����ϵͳ���
	COFPStringType<8> Orderid;
	//����Ա����
	COFPStringType<15> Userid;
};

void dumpOFPField(COFPOrderDelRequestField *pField);

//����ɾ��Ӧ��
const WORD OFP_VARY_OrderDelResponse = 0x0303;

struct COFPOrderDelResponseField
{
	//����ϵͳ���
	COFPStringType<8> Orderid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//�걨�۸�
	COFPNumberType<6> Orderp;
	//�걨����
	COFPNumberType<6> Orderv;
	//�ͻ�����
	COFPStringType<8> Custid;
	//����Ա����
	COFPStringType<15> Userid;
	//���ر��
	COFPStringType<8> Lorderid;
	//��������
	COFPCharType Posit;
	//��ƽ�ֱ�־
	COFPCharType Closef;
	//Ͷ����ֵ��־
	COFPCharType Tjbz;
	//δ��
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPOrderDelResponseField *pField);

//����ɾ��ʧ��Ӧ��
const WORD OFP_VARY_OrderDelErrorResponse = 0x0303;

struct COFPOrderDelErrorResponseField
{
	//����ϵͳ���
	COFPStringType<8> Orderid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//�걨�۸�
	COFPNumberType<6> Orderp;
	//�걨����
	COFPNumberType<6> Orderv;
	//�ͻ�����
	COFPStringType<8> Custid;
	//����Ա����
	COFPStringType<15> Userid;
	//���ر��
	COFPStringType<8> Lorderid;
	//��������
	COFPCharType Posit;
	//��ƽ�ֱ�־
	COFPCharType Closef;
	//Ͷ����ֵ��־
	COFPCharType Tjbz;
	//δ��
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPOrderDelErrorResponseField *pField);

//����ɾ���Ҳ���ʧ��Ӧ��
const WORD OFP_VARY_OrderDelNotFoundResponse = 0x0303;

struct COFPOrderDelNotFoundResponseField
{
	//����ϵͳ���
	COFPStringType<8> Orderid;
	//����Ա����
	COFPStringType<15> Userid;
};

void dumpOFPField(COFPOrderDelNotFoundResponseField *pField);

//��Ȩ����ɾ��
const WORD OFP_VARY_AuthorizedOrderDelRequest = 0x0250;

struct COFPAuthorizedOrderDelRequestField
{
	//����ϵͳ��ţ�������
	COFPStringType<8> orderid;
};

void dumpOFPField(COFPAuthorizedOrderDelRequestField *pField);

//��Ȩ����ɾ��Ӧ��
const WORD OFP_VARY_AuthorizedOrderDelResponse = 0x0350;

struct COFPAuthorizedOrderDelResponseField
{
	//����ϵͳ��ţ�������
	COFPStringType<8> orderid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//�걨�۸�
	COFPNumberType<6> Orderp;
	//�걨����
	COFPNumberType<6> Orderv;
	//�ͻ�����
	COFPStringType<8> Custid;
	//����Ա����
	COFPStringType<15> Userid;
	//���ر��
	COFPStringType<8> Lorderid;
	//��������
	COFPCharType Posit;
	//��ƽ�ֱ�־
	COFPCharType Closef;
	//Ͷ����ֵ��־
	COFPCharType Tjbz;
	//δ��
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPAuthorizedOrderDelResponseField *pField);

//��Ȩ����ɾ��ʧ��Ӧ��
const WORD OFP_VARY_AuthorizedOrderDelErrorResponse = 0x0350;

struct COFPAuthorizedOrderDelErrorResponseField
{
	//����ϵͳ��ţ�������
	COFPStringType<8> Orderid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//�걨�۸�
	COFPNumberType<6> Orderp;
	//�걨����
	COFPNumberType<6> Orderv;
	//�ͻ�����
	COFPStringType<8> Custid;
	//����Ա����
	COFPStringType<15> Userid;
	//���ر��
	COFPStringType<8> Lorderid;
	//��������
	COFPCharType Posit;
	//��ƽ�ֱ�־
	COFPCharType Closef;
	//Ͷ����ֵ��־
	COFPCharType Tjbz;
	//δ��
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPAuthorizedOrderDelErrorResponseField *pField);

//���������ѯ
const WORD OFP_VARY_QryInternationalMarketRequest = 0x0205;

struct COFPQryInternationalMarketRequestField
{
	//���������Ա
	COFPStringType<15> userid;
};

void dumpOFPField(COFPQryInternationalMarketRequestField *pField);

//���������ѯӦ��
const WORD OFP_VARY_QryInternationalMarketResponse = 0x0305;

struct COFPQryInternationalMarketResponseField
{
	//�ı���Ϣ
	COFPStringType<500> content;
};

void dumpOFPField(COFPQryInternationalMarketResponseField *pField);

//���������ѯʧ��Ӧ��
const WORD OFP_VARY_QryInternationalMarketErrorResponse = 0x0305;

struct COFPQryInternationalMarketErrorResponseField
{
	//���������Ա
	COFPStringType<15> userid;
};

void dumpOFPField(COFPQryInternationalMarketErrorResponseField *pField);

//�������ѯ
const WORD OFP_VARY_QryRubberMarketRequest = 0x0206;

struct COFPQryRubberMarketRequestField
{
	//���������Ա
	COFPStringType<15> userid;
};

void dumpOFPField(COFPQryRubberMarketRequestField *pField);

//�������ѯӦ��
const WORD OFP_VARY_QryRubberMarketResponse = 0x0306;

struct COFPQryRubberMarketResponseField
{
	//�ı���Ϣ
	COFPStringType<500> content;
};

void dumpOFPField(COFPQryRubberMarketResponseField *pField);

//�������ѯʧ��Ӧ��
const WORD OFP_VARY_QryRubberMarketErrorResponse = 0x0306;

struct COFPQryRubberMarketErrorResponseField
{
	//���������Ա
	COFPStringType<15> userid;
};

void dumpOFPField(COFPQryRubberMarketErrorResponseField *pField);

//�����޸�����
const WORD OFP_VARY_MBackOrder = 0x0701;

struct COFPMBackOrderField
{
	//˽�������к�
	COFPNumberType<8> mqid;
	//��Ϣ����
	COFPNumberType<4> cmd;
	//����ϵͳ���
	COFPStringType<8> Orderid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//�걨�۸�
	COFPNumberType<6> Orderp;
	//�걨����
	COFPNumberType<6> Orderv;
	//�ͻ�����
	COFPStringType<8> Custid;
	//����Ա����
	COFPStringType<15> Userid;
	//���ر��
	COFPStringType<8> Lorderid;
	//��������
	COFPCharType Posit;
	//��ƽ�ֱ�־
	COFPCharType Closef;
	//Ͷ����ֵ��־
	COFPCharType Tjbz;
	//����״̬
	COFPCharType Orderf;
	//����¼������
	COFPStringType<8> Orderd;
	//����¼��ʱ��
	COFPStringType<8> Ordert;
	//����ɾ��ʱ��
	COFPStringType<8> Orderdt;
	//δ��
	COFPStringType<20> Filler;
};

void dumpOFPField(COFPMBackOrderField *pField);

//�����޸�ʧ������
const WORD OFP_VARY_MBackOrderError = 0x0701;

struct COFPMBackOrderErrorField
{
	//˽�������к�
	COFPNumberType<8> mqid;
	//��Ϣ����
	COFPNumberType<4> cmd;
	//����ϵͳ���
	COFPStringType<8> Orderid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//�걨�۸�
	COFPNumberType<6> Orderp;
	//�걨����
	COFPNumberType<6> Orderv;
	//�ͻ�����
	COFPStringType<8> Custid;
	//����Ա����
	COFPStringType<15> Userid;
	//���ر��
	COFPStringType<8> Lorderid;
	//��������
	COFPCharType Posit;
	//��ƽ�ֱ�־
	COFPCharType Closef;
	//Ͷ����ֵ��־
	COFPCharType Tjbz;
	//δ��
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPMBackOrderErrorField *pField);

//�ɽ��ر�
const WORD OFP_VARY_TradeInsert = 0x0702;

struct COFPTradeInsertField
{
	//����ϵͳ���
	COFPStringType<8> Orderid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//��������
	COFPCharType Posit;
	//�����걨����
	COFPNumberType<6> Orderv;
	//�����걨�۸�
	COFPNumberType<6> Orderp;
	//������ǰ�ɽ�����
	COFPNumberType<6> Compv;
	//������ǰ�ɽ��۸�
	COFPNumberType<6> Compp;
	//����δ�ɽ�ʣ������
	COFPNumberType<6> Balance;
	//δ��
	COFPStringType<2> Comps;
	//�ͻ�����
	COFPStringType<8> Custid;
	//����Ա����
	COFPStringType<15> Userid;
	//���ر��
	COFPStringType<8> Lorderid;
	//��ƽ�ֱ�־
	COFPCharType Closef;
	//Ͷ����ֵ��־
	COFPCharType Tjbz;
	//��ǰ��ϱ��
	COFPStringType<8> Matcno;
	//�������
	COFPStringType<8> Compd;
	//���ʱ��
	COFPStringType<8> Compt;
};

void dumpOFPField(COFPTradeInsertField *pField);

//�ɽ��ر�
const WORD OFP_VARY_MBackTrade = 0x0701;

struct COFPMBackTradeField
{
	//˽�������к�
	COFPNumberType<8> mqid;
	//��Ϣ����
	COFPNumberType<4> cmd;
	//����ϵͳ���
	COFPStringType<8> Orderid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//��������
	COFPCharType Posit;
	//�����걨����
	COFPNumberType<6> Orderv;
	//�����걨�۸�
	COFPNumberType<6> Orderp;
	//������ǰ�ɽ�����
	COFPNumberType<6> Compv;
	//������ǰ�ɽ��۸�
	COFPNumberType<6> Compp;
	//�ͻ�����
	COFPStringType<8> Custid;
	//����Ա����
	COFPStringType<15> Userid;
	//���ر��
	COFPStringType<8> Lorderid;
	//��ƽ�ֱ�־
	COFPCharType Closef;
	//Ͷ����ֵ��־
	COFPCharType Tjbz;
	//��ǰ��ϱ��
	COFPStringType<8> Matcno;
	//�������
	COFPStringType<8> Compd;
	//���ʱ��
	COFPStringType<8> Compt;
	//δ��
	COFPStringType<20> Filler;
};

void dumpOFPField(COFPMBackTradeField *pField);

//��Ա��֤���ѯָ��
const WORD OFP_VARY_QryDepositRequest = 0x0207;

struct COFPQryDepositRequestField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
};

void dumpOFPField(COFPQryDepositRequestField *pField);

//��Ա��֤���ѯӦ��
const WORD OFP_VARY_QryDepositResponse = 0x0307;

struct COFPQryDepositResponseField
{
	//��Ա
	COFPStringType<8> Membid;
	//�ճ��ʽ�
	COFPFloatType Margit;
	//δʹ��
	COFPStringType<15> Credii;
	//����ʹ���ʽ�
	COFPFloatType Buymar;
	//����ʹ���ʽ�
	COFPFloatType Sellma;
	//����ʹ���ʽ�
	COFPFloatType Totall;
	//ʣ������ʽ�
	COFPFloatType Closec;
};

void dumpOFPField(COFPQryDepositResponseField *pField);

//��Ա��֤���ѯʧ��Ӧ��
const WORD OFP_VARY_QryDepositErrorResponse = 0x0307;

struct COFPQryDepositErrorResponseField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
};

void dumpOFPField(COFPQryDepositErrorResponseField *pField);

//��ֵ��Ȳ�ѯָ��
const WORD OFP_VARY_QryHedgeRequest = 0x0724;

struct COFPQryHedgeRequestField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryHedgeRequestField *pField);

//��ֵ��Ȳ�ѯӦ��
const WORD OFP_VARY_QryHedgeResponse = 0x0824;

struct COFPQryHedgeResponseField
{
	//����Ա������Ա�Ŀͻ�����
	COFPStringType<8> Custid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//��ֵ����������
	COFPNumberType<8> Brequam;
	//��ֵ���ʹ�ö���
	COFPNumberType<8> Buseram;
	//��ֵ���ʣ�����
	COFPNumberType<8> Bbalance;
	//����ֵ����������
	COFPNumberType<8> Srequam;
	//����ֵ���ʹ�ö���
	COFPNumberType<8> Suseram;
	//����ֵ���ʣ�����
	COFPNumberType<8> Sbalance;
};

void dumpOFPField(COFPQryHedgeResponseField *pField);

//��ֵ��Ȳ�ѯʧ��Ӧ��
const WORD OFP_VARY_QryHedgeErrorResponse = 0x0824;

struct COFPQryHedgeErrorResponseField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryHedgeErrorResponseField *pField);

//��ֵ��Ȳ�ѯָ��
const WORD OFP_VARY_QryHedgeV2Request = 0x501a;

struct COFPQryHedgeV2RequestField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryHedgeV2RequestField *pField);

//��ֵ��Ȳ�ѯӦ��
const WORD OFP_VARY_QryHedgeV2Response = 0x511a;

struct COFPQryHedgeV2ResponseField
{
	//����Ա������Ա����
	COFPStringType<8> Membid;
	//����Ա������Ա�Ŀͻ�����
	COFPStringType<8> Custid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//��ֵ����������
	COFPNumberType<8> Brequam;
	//��ֵ���ʹ�ö���
	COFPNumberType<8> Buseram;
	//��ֵ���ʣ�����
	COFPNumberType<8> Bbalance;
	//����ֵ����������
	COFPNumberType<8> Srequam;
	//����ֵ���ʹ�ö���
	COFPNumberType<8> Suseram;
	//����ֵ���ʣ�����
	COFPNumberType<8> Sbalance;
};

void dumpOFPField(COFPQryHedgeV2ResponseField *pField);

//��ֵ��Ȳ�ѯʧ��Ӧ��
const WORD OFP_VARY_QryHedgeV2ErrorResponse = 0x511a;

struct COFPQryHedgeV2ErrorResponseField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryHedgeV2ErrorResponseField *pField);

//�ͻ����ϲ�ѯָ��
const WORD OFP_VARY_QryClientRequest = 0x1010;

struct COFPQryClientRequestField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
};

void dumpOFPField(COFPQryClientRequestField *pField);

//�ͻ����ϲ�ѯӦ��
const WORD OFP_VARY_QryClientResponse = 0x1110;

struct COFPQryClientResponseField
{
	//δ��
	COFPCharType Rstus;
	//�ͻ�����
	COFPStringType<8> Custid;
	//�ͻ�����
	COFPStringType<50> Custnm;
	//�ͻ���ַ
	COFPStringType<50> Custad;
	//�ͻ���ϵ�绰
	COFPStringType<18> Custtel;
	//�ͻ���ҵ����
	COFPCharType Tradtp;
	//���˴���
	COFPStringType<8> Reprnm;
	//�ͻ���־
	COFPCharType custle;
	//������Ա
	COFPStringType<8> Emplid;
	//δ��
	COFPCharType Credit;
	//�Ƿ�������
	COFPCharType Trades;
	//δ��
	COFPCharType Tradau;
	//��������
	COFPStringType<8> Indate;
	//δ��
	COFPStringType<8> Modate;
	//δ��
	COFPStringType<8> Instaff;
	//δ��
	COFPStringType<8> Mostaff;
	//�ͻ�����
	COFPCharType Comple;
	//ע�ᣯӪ���ʽ�
	COFPStringType<15> Regisf;
	//δ��
	COFPStringType<8> Floortr;
	//֤����������֤����
	COFPStringType<20> Zjhm;
};

void dumpOFPField(COFPQryClientResponseField *pField);

//�ͻ����ϲ�ѯʧ��Ӧ��
const WORD OFP_VARY_QryClientErrorResponse = 0x1110;

struct COFPQryClientErrorResponseField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
};

void dumpOFPField(COFPQryClientErrorResponseField *pField);

//����Ʒ�ֲ�ѯָ��
const WORD OFP_VARY_QryInstrumentRequest = 0x1000;

struct COFPQryInstrumentRequestField
{
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryInstrumentRequestField *pField);

//����Ʒ�ֲ�ѯӦ��
const WORD OFP_VARY_QryInstrumentResponse = 0x1100;

struct COFPQryInstrumentResponseField
{
	//����Ʒ�ִ���
	COFPStringType<6> Commid;
	//����Ʒ������
	COFPStringType<8> Commnm;
	//�����·ݣ���ʽΪyymm��space��2��
	COFPStringType<6> Delim;
	//����Ʒ�ֵ����ֱ��룬�确01��Ϊͭ
	COFPStringType<2> Abbr;
	//ÿ���������֣�
	COFPNumberType<6> Trade;
	//��С�䶯��λ
	COFPNumberType<6> Tick;
	//δ�ã�Ӧ�����ǵ�ͣ����
	COFPStringType<6> Daill;
	//δ�ã�Ӧ���Ǳ�ֵƽ������ʼ����
	COFPStringType<8> Closed;
	//Ʒ�����ͣ���f����F���ڻ�������
	COFPCharType Commtp;
	//��ʼ��������
	COFPStringType<8> Stard;
	//��ʼ��������
	COFPStringType<8> Delid;
	//������������
	COFPStringType<8> Stopd;
	//������������걨����
	COFPNumberType<6> Posil;
	//Ʒ�ֽ���״̬����a����������������
	COFPCharType Commst;
	//������������
	COFPStringType<8> Lastde;
	//δ�ã�Ϊ��1��00��
	COFPStringType<4> Margin;
	//δ�ã�Ϊ��0��00��
	COFPStringType<4> Sxfl;
};

void dumpOFPField(COFPQryInstrumentResponseField *pField);

//����Ʒ�ֲ�ѯʧ��Ӧ��
const WORD OFP_VARY_QryInstrumentErrorResponse = 0x1100;

struct COFPQryInstrumentErrorResponseField
{
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryInstrumentErrorResponseField *pField);

//��Ȩ������ѯ����
const WORD OFP_VARY_QryAuthorizedOrderRequest = 0x0251;

struct COFPQryAuthorizedOrderRequestField
{
	//ָ������Ա���Ա�ı���
	COFPStringType<15> username;
};

void dumpOFPField(COFPQryAuthorizedOrderRequestField *pField);

//��Ȩ������ѯӦ��
const WORD OFP_VARY_QryAuthorizedOrderResponse = 0x0351;

struct COFPQryAuthorizedOrderResponseField
{
	//����ϵͳ���
	COFPStringType<8> Orderid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//�������򣬡�b���򣯡�s����
	COFPCharType Posit;
	//����״̬����o����Ч����
	COFPCharType Orderf;
	//��ƽ�ֱ�־
	COFPCharType Closef;
	//Ͷ����ֵ��־����0����ֵ����1��Ͷ��
	COFPCharType Tjbz;
	//�����걨����
	COFPNumberType<6> Orderv;
	//�����걨�۸�
	COFPNumberType<6> Orderp;
	//�ͻ�
	COFPStringType<8> Custid;
	//��Ա
	COFPStringType<8> Membid;
	//����Ա
	COFPStringType<15> Userid;
	//�ܳɽ�����
	COFPNumberType<6> Compv;
	//���һ�ʳɽ��۸�
	COFPNumberType<6> Compp;
	//����ʱ��
	COFPStringType<8> Ordert;
	//����ɾ��ʱ��
	COFPStringType<8> DOrdt;
	//�������ر��
	COFPStringType<8> Lorderid;
};

void dumpOFPField(COFPQryAuthorizedOrderResponseField *pField);

//��Ȩ������ѯʧ��Ӧ��
const WORD OFP_VARY_QryAuthorizedOrderErrorResponse = 0x0351;

struct COFPQryAuthorizedOrderErrorResponseField
{
	//ָ������Ա���Ա�ı���
	COFPStringType<15> username;
};

void dumpOFPField(COFPQryAuthorizedOrderErrorResponseField *pField);

//������ѯָ��
const WORD OFP_VARY_QryOrderRequest = 0x0208;

struct COFPQryOrderRequestField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
};

void dumpOFPField(COFPQryOrderRequestField *pField);

//������ѯָ��
const WORD OFP_VARY_QryAllOrderRequest = 0x0208;

struct COFPQryAllOrderRequestField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
};

void dumpOFPField(COFPQryAllOrderRequestField *pField);

//������ѯӦ��
const WORD OFP_VARY_QryOrderResponse = 0x0308;

struct COFPQryOrderResponseField
{
	//����ϵͳ���
	COFPStringType<8> Orderid;
	//�����걨ʱ��
	COFPStringType<8> Ordert;
	//����Ʒ��
	COFPStringType<6> Commid;
	//�����·ݣ�δ��
	COFPStringType<6> Delim;
	//�������򣬡�b���򣯡�s����
	COFPCharType Posit;
	//����״̬����o����Ч����
	COFPCharType Orderf;
	//�����걨����
	COFPNumberType<6> Orderv;
	//�����걨�۸�
	COFPNumberType<6> Orderp;
	//�ܳɽ�����
	COFPNumberType<6> Compv;
	//���һ�ʳɽ��۸�
	COFPNumberType<6> Compp;
	//����ʣ������
	COFPNumberType<6> Balance;
	//�ͻ�����
	COFPStringType<8> Custid;
	//����Ա
	COFPStringType<15> Userid;
	//�������ر��
	COFPStringType<8> Lorderid;
	//��ƽ�ֱ�־
	COFPCharType Closef;
	//Ͷ����ֵ��־����0����ֵ����1��Ͷ��
	COFPCharType Tjbz;
};

void dumpOFPField(COFPQryOrderResponseField *pField);

//������ѯʧ��Ӧ��
const WORD OFP_VARY_QryOrderErrorResponse = 0x0308;

struct COFPQryOrderErrorResponseField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
};

void dumpOFPField(COFPQryOrderErrorResponseField *pField);

//�ɽ�����ѯָ��
const WORD OFP_VARY_QryTradeRequest = 0x5201;

struct COFPQryTradeRequestField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryTradeRequestField *pField);

//�ɽ�����ѯӦ��
const WORD OFP_VARY_QryTradeResponse = 0x5301;

struct COFPQryTradeResponseField
{
	//�������ر��
	COFPStringType<8> Lorderid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//������־����b���򣯡�s����
	COFPCharType Posit;
	//��ƽ�ֱ�־
	COFPCharType Closef;
	//Ͷ����ֵ��־����0����ֵ����1��Ͷ��
	COFPCharType Tjbz;
	//�ܳɽ�����
	COFPNumberType<6> Compv;
	//���һ�ʳɽ��۸�
	COFPNumberType<6> Compp;
	//�ͻ�����
	COFPStringType<8> Custid;
	//����Ա
	COFPStringType<8> Membid;
	//�ɽ����ڣ���ʽccyymmdd
	COFPStringType<8> Compd;
	//�ɽ�ʱ�䣬��ʽhhmmssuu
	COFPStringType<8> Compt;
	//��ϱ��
	COFPStringType<8> Matcno;
	//����ϵͳ���
	COFPStringType<8> Orderid;
	//�����걨����
	COFPNumberType<6> Orderv;
	//�����걨�۸�
	COFPNumberType<6> Orderp;
	//����ʱ��
	COFPStringType<8> Ordert;
};

void dumpOFPField(COFPQryTradeResponseField *pField);

//�ɽ�����ѯʧ��Ӧ��
const WORD OFP_VARY_QryTradeErrorResponse = 0x5301;

struct COFPQryTradeErrorResponseField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryTradeErrorResponseField *pField);

//��Ա�ֲֲ�ѯָ��
const WORD OFP_VARY_QryPPositionRequest = 0x1007;

struct COFPQryPPositionRequestField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
	//��ѯѡ��
	COFPCharType Option;
};

void dumpOFPField(COFPQryPPositionRequestField *pField);

//��Ա�ֲֲ�ѯӦ��
const WORD OFP_VARY_QryPPositionResponse = 0x1107;

struct COFPQryPPositionResponseField
{
	//��Ա����
	COFPStringType<8> Membid;
	//�ͻ����룬ΪASCII�ո�
	COFPStringType<8> Custid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//��ֵ����
	COFPNumberType<6> Buyvb;
	//��Ͷ������
	COFPNumberType<6> Buyvt;
	//����ֵ����
	COFPNumberType<6> Sellvb;
	//��Ͷ������
	COFPNumberType<6> Sellvt;
	//����ֵ�¿�������
	COFPNumberType<6> Openbvb;
	//����Ͷ���¿�������
	COFPNumberType<6> Openbvt;
	//������ֵ�¿�������
	COFPNumberType<6> Opensvb;
	//����Ͷ���¿�������
	COFPNumberType<6> Opensvt;
	//��ֵ����ֲ�����
	COFPNumberType<6> Fbuyvb;
	//��Ͷ������ֲ�����
	COFPNumberType<6> Fbuyvt;
	//����ֵ����ֲ�����
	COFPNumberType<6> Fsellvb;
	//��Ͷ������ֲ�����
	COFPNumberType<6> Fsellvt;
	//ǰ�����ս����
	COFPNumberType<6> Clearp;
	//δ�ã���ֵʹ�ñ�֤�𣨸�ʽ��15��2f��
	COFPFloatType Margamb;
	//δ�ã�Ͷ��ʹ�ñ�֤�𣨸�ʽ��15��2f��
	COFPFloatType Margamt;
};

void dumpOFPField(COFPQryPPositionResponseField *pField);

//��Ա�ֲֲ�ѯʧ��Ӧ��
const WORD OFP_VARY_QryPPositionErrorResponse = 0x1107;

struct COFPQryPPositionErrorResponseField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
	//��ѯѡ��
	COFPCharType Option;
};

void dumpOFPField(COFPQryPPositionErrorResponseField *pField);

//��Ҫ��Ա�ֲֲ�ѯָ��
const WORD OFP_VARY_QryBriefPPositionRequest = 0x2007;

struct COFPQryBriefPPositionRequestField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
	//��ѯѡ��
	COFPCharType Option;
};

void dumpOFPField(COFPQryBriefPPositionRequestField *pField);

//��Ҫ��Ա�ֲֲ�ѯӦ��
const WORD OFP_VARY_QryBriefPPositionResponse = 0x2107;

struct COFPQryBriefPPositionResponseField
{
	//��Ա����
	COFPStringType<8> Membid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//��ֵ����
	COFPNumberType<6> Buyvb;
	//��Ͷ������
	COFPNumberType<6> Buyvt;
	//����ֵ����
	COFPNumberType<6> Sellvb;
	//��Ͷ������
	COFPNumberType<6> Sellvt;
	//ǰ�����ս����
	COFPNumberType<6> Clearp;
	//δ�ã���ֵʹ�ñ�֤�𣨸�ʽ��15��2f��
	COFPFloatType Margamb;
	//δ�ã�Ͷ��ʹ�ñ�֤�𣨸�ʽ��15��2f��
	COFPFloatType Margamt;
};

void dumpOFPField(COFPQryBriefPPositionResponseField *pField);

//��Ҫ��Ա�ֲֲ�ѯʧ��Ӧ��
const WORD OFP_VARY_QryBriefPPositionErrorResponse = 0x2107;

struct COFPQryBriefPPositionErrorResponseField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
	//��ѯѡ��
	COFPCharType Option;
};

void dumpOFPField(COFPQryBriefPPositionErrorResponseField *pField);

//��Ա�ͻ��ֲֲ�ѯָ��
const WORD OFP_VARY_QryPositionRequest = 0x1009;

struct COFPQryPositionRequestField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
	//��ѯ��ʼ�ͻ�
	COFPStringType<8> Custid;
	//��ѯ�����ͻ�
	COFPStringType<8> Custidt;
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
	//��ѯѡ��
	COFPCharType Option;
};

void dumpOFPField(COFPQryPositionRequestField *pField);

//��Ա�ͻ��ֲֲ�ѯӦ��
const WORD OFP_VARY_QryPositionResponse = 0x1109;

struct COFPQryPositionResponseField
{
	//��Ա����
	COFPStringType<8> Membid;
	//�ͻ����룬ΪASCII�ո�
	COFPStringType<8> Custid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//��ֵ����
	COFPNumberType<6> Buyvb;
	//��Ͷ������
	COFPNumberType<6> Buyvt;
	//����ֵ����
	COFPNumberType<6> Sellvb;
	//��Ͷ������
	COFPNumberType<6> Sellvt;
	//����ֵ�¿�������
	COFPNumberType<6> Openbvb;
	//����Ͷ���¿�������
	COFPNumberType<6> Openbvt;
	//������ֵ�¿�������
	COFPNumberType<6> Opensvb;
	//����Ͷ���¿�������
	COFPNumberType<6> Opensvt;
	//��ֵ����ֲ�����
	COFPNumberType<6> Fbuyvb;
	//��Ͷ������ֲ�����
	COFPNumberType<6> Fbuyvt;
	//����ֵ����ֲ�����
	COFPNumberType<6> Fsellvb;
	//��Ͷ������ֲ�����
	COFPNumberType<6> Fsellvt;
	//ǰ�����ս����
	COFPNumberType<6> Clearp;
	//δ�ã���ֵʹ�ñ�֤�𣨸�ʽ��15��2f��
	COFPFloatType Margamb;
	//δ�ã�Ͷ��ʹ�ñ�֤�𣨸�ʽ��15��2f��
	COFPFloatType Margamt;
};

void dumpOFPField(COFPQryPositionResponseField *pField);

//��Ա�ͻ��ֲֲ�ѯʧ��Ӧ��
const WORD OFP_VARY_QryPositionErrorResponse = 0x1109;

struct COFPQryPositionErrorResponseField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
	//��ѯ��ʼ�ͻ�
	COFPStringType<8> Custid;
	//��ѯ�����ͻ�
	COFPStringType<8> Custidt;
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
	//��ѯѡ��
	COFPCharType Option;
};

void dumpOFPField(COFPQryPositionErrorResponseField *pField);

//��Ҫ��Ա�ͻ��ֲֲ�ѯָ��
const WORD OFP_VARY_QryBriefPositionRequest = 0x2009;

struct COFPQryBriefPositionRequestField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
	//��ѯ��ʼ�ͻ�
	COFPStringType<8> Custid;
	//��ѯ�����ͻ�
	COFPStringType<8> Custidt;
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
	//��ѯѡ��
	COFPCharType Option;
};

void dumpOFPField(COFPQryBriefPositionRequestField *pField);

//��Ҫ��Ա�ͻ��ֲֲ�ѯӦ��
const WORD OFP_VARY_QryBriefPositionResponse = 0x2109;

struct COFPQryBriefPositionResponseField
{
	//�ͻ����룬ΪASCII�ո�
	COFPStringType<8> Custid;
	//����Ʒ��
	COFPStringType<6> Commid;
	//��ֵ����
	COFPNumberType<6> Buyvb;
	//��Ͷ������
	COFPNumberType<6> Buyvt;
	//����ֵ����
	COFPNumberType<6> Sellvb;
	//��Ͷ������
	COFPNumberType<6> Sellvt;
	//ǰ�����ս����
	COFPNumberType<6> Clearp;
	//δ�ã���ֵʹ�ñ�֤�𣨸�ʽ��15��2f��
	COFPFloatType Margamb;
	//δ�ã�Ͷ��ʹ�ñ�֤�𣨸�ʽ��15��2f��
	COFPFloatType Margamt;
};

void dumpOFPField(COFPQryBriefPositionResponseField *pField);

//��Ҫ��Ա�ͻ��ֲֲ�ѯʧ��Ӧ��
const WORD OFP_VARY_QryBriefPositionErrorResponse = 0x2109;

struct COFPQryBriefPositionErrorResponseField
{
	//��ѯ��ʼ��Ա
	COFPStringType<8> Membid;
	//��ѯ������Ա
	COFPStringType<8> Membidt;
	//��ѯ��ʼ�ͻ�
	COFPStringType<8> Custid;
	//��ѯ�����ͻ�
	COFPStringType<8> Custidt;
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
	//��ѯѡ��
	COFPCharType Option;
};

void dumpOFPField(COFPQryBriefPositionErrorResponseField *pField);

//Ʒ�ּ�λ��ѯָ��
const WORD OFP_VARY_QryInstrumentPriceRequest = 0x1006;

struct COFPQryInstrumentPriceRequestField
{
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
	//��ѯѡ��
	COFPCharType Option;
};

void dumpOFPField(COFPQryInstrumentPriceRequestField *pField);

//Ʒ�ּ�λ��ѯӦ��
const WORD OFP_VARY_QryInstrumentPriceResponse = 0x1106;

struct COFPQryInstrumentPriceResponseField
{
	//�������ۣ���b���򣯡�s����
	COFPCharType Bsflag;
	//����Ʒ��
	COFPStringType<6> Commid;
	//����
	COFPNumberType<6> Orderp;
	//�����걨����
	COFPNumberType<8> Orderv;
	//���гɽ�����
	COFPNumberType<8> Compv;
	//���г�������
	COFPNumberType<8> Cancelv;
	//������Ч����
	COFPNumberType<8> Currentv;
};

void dumpOFPField(COFPQryInstrumentPriceResponseField *pField);

//Ʒ�ּ�λ��ѯʧ��Ӧ��
const WORD OFP_VARY_QryInstrumentPriceErrorResponse = 0x1106;

struct COFPQryInstrumentPriceErrorResponseField
{
	//��ѯ��ʼ����Ʒ��
	COFPStringType<6> Commid;
	//��ѯ��������Ʒ��
	COFPStringType<6> Commidt;
	//��ѯѡ��
	COFPCharType Option;
};

void dumpOFPField(COFPQryInstrumentPriceErrorResponseField *pField);

//����Ʒ�����ֱ����ѯ����
const WORD OFP_VARY_QryInstrumentNumberRequest = 0x1001;

struct COFPQryInstrumentNumberRequestField
{
};

void dumpOFPField(COFPQryInstrumentNumberRequestField *pField);

//����Ʒ�����ֱ����ѯӦ��
const WORD OFP_VARY_QryInstrumentNumberResponse = 0x1101;

struct COFPQryInstrumentNumberResponseField
{
	//δ�ã�Ϊ������
	COFPCharType rstus;
	//����Ʒ�ִ�����룬�确cu������al����
	COFPStringType<2> comm;
	//����Ʒ�ִ������ִ��룬�确01������02����
	COFPStringType<2> abbrev;
};

void dumpOFPField(COFPQryInstrumentNumberResponseField *pField);

//����Ʒ�����ֱ����ʧ��Ӧ��
const WORD OFP_VARY_QryInstrumentNumberErrorResponse = 0x1101;

struct COFPQryInstrumentNumberErrorResponseField
{
};

void dumpOFPField(COFPQryInstrumentNumberErrorResponseField *pField);

//��Ա˽�����ر���Ų�ѯָ��
const WORD OFP_VARY_QryTrasnferIdRequest = 0x1016;

struct COFPQryTrasnferIdRequestField
{
	//����Ա�û�
	COFPStringType<15> Userid;
	//��Ա���
	COFPStringType<8> Membid;
};

void dumpOFPField(COFPQryTrasnferIdRequestField *pField);

//��Ա˽�����ر���Ų�ѯӦ��
const WORD OFP_VARY_QryTrasnferIdResponse = 0x1116;

struct COFPQryTrasnferIdResponseField
{
	//����Ա�û�
	COFPStringType<15> Userid;
	//��Ա���
	COFPStringType<8> Membid;
	//����ϵͳ��Ա˽�����ر�Ŀǰ�����
	COFPNumberType<8> Transferid;
};

void dumpOFPField(COFPQryTrasnferIdResponseField *pField);

//��Ա˽�����ر���Ų�ѯʧ��Ӧ��
const WORD OFP_VARY_QryTrasnferIdErrorResponse = 0x1116;

struct COFPQryTrasnferIdErrorResponseField
{
	//����Ա�û�
	COFPStringType<15> Userid;
	//��Ա���
	COFPStringType<8> Membid;
};

void dumpOFPField(COFPQryTrasnferIdErrorResponseField *pField);

//ϵͳ���У�֮��������Ա���ͻ��ˣ���¼������ϵͳ
const WORD OFP_VARY_Start = 0x0502;

struct COFPStartField
{
};

void dumpOFPField(COFPStartField *pField);

//ϵͳ���̣���һ�ο���ʱ��ǰ���׽�����Ϊ������
const WORD OFP_VARY_Open = 0x0503;

struct COFPOpenField
{
};

void dumpOFPField(COFPOpenField *pField);

//ϵͳ��ͣ
const WORD OFP_VARY_Pause = 0x0504;

struct COFPPauseField
{
};

void dumpOFPField(COFPPauseField *pField);

//ϵͳ���̣�֮��������Ա���ͻ��ˣ���¼������ϵͳ
const WORD OFP_VARY_Close = 0x0505;

struct COFPCloseField
{
};

void dumpOFPField(COFPCloseField *pField);

//ϵͳ����
const WORD OFP_VARY_End = 0x0506;

struct COFPEndField
{
	//δʹ�ã�Ϊ������
	COFPCharType rstatus;
	//���׽�
	COFPStringType<2> sectid;
	//���׽�����
	COFPStringType<20> desc;
	//���׽�״̬
	COFPCharType sects0;
	//���׽��Ƿ����̼��Ͼ��۳�ʼ����־����1���ǣ�������
	COFPCharType sects1;
	//δʹ�ã�Ϊ������
	COFPStringType<24> f2;
	//�ͻ��˲���֪������
	COFPStringType<8> starttime;
	//�ͻ��˲���֪������
	COFPStringType<8> endtime;
	//����ͭ�Ƿ��ף���1�����ף�������
	COFPCharType cu;
	//�������Ƿ��ף���1�����ף�������
	COFPCharType al;
	//�������Ƿ��ף���1�����ף�������
	COFPCharType ru;
	//���ڼװ��Ƿ��ף���1�����ף�������
	COFPCharType pw;
	//���������Ƿ��ף���1�����ף�������
	COFPCharType rc;
	//δʹ�ã�Ϊ������
	COFPStringType<35> f3;
};

void dumpOFPField(COFPEndField *pField);

//ϵͳ�ڳ�ʼ��
const WORD OFP_VARY_Presect = 0x0521;

struct COFPPresectField
{
};

void dumpOFPField(COFPPresectField *pField);

//ϵͳ�ڿ���
const WORD OFP_VARY_SectionStart = 0x0522;

struct COFPSectionStartField
{
};

void dumpOFPField(COFPSectionStartField *pField);

//ϵͳ������
const WORD OFP_VARY_SectionStop = 0x0523;

struct COFPSectionStopField
{
};

void dumpOFPField(COFPSectionStopField *pField);

//ϵͳ�ڿ��̼��Ͼ��ۿ�ʼ
const WORD OFP_VARY_OpenAuctionSectionStart = 0x0524;

struct COFPOpenAuctionSectionStartField
{
};

void dumpOFPField(COFPOpenAuctionSectionStartField *pField);

//ϵͳ�ڿ��̼��Ͼ��۽���
const WORD OFP_VARY_OpenAuctionSectionStop = 0x0525;

struct COFPOpenAuctionSectionStopField
{
};

void dumpOFPField(COFPOpenAuctionSectionStopField *pField);

//ϵͳ�����̼��Ͼ��ۿ�ʼ
const WORD OFP_VARY_CloseAuctionSectionStart = 0x0526;

struct COFPCloseAuctionSectionStartField
{
};

void dumpOFPField(COFPCloseAuctionSectionStartField *pField);

//ϵͳ�ڿ��̼��Ͼ��۽���
const WORD OFP_VARY_CloseAuctionSectionStop = 0x0527;

struct COFPCloseAuctionSectionStopField
{
};

void dumpOFPField(COFPCloseAuctionSectionStopField *pField);


///��ȡ��������Ӧ��Ӧ��varyֵ
///@param	command	������
///@return	��Ӧ��varyֵ
WORD GetOFPVary(const char *command);

#endif
