// 20110413 ����   NT-0129-�����������л�ʱ��ˮ�쳣���������

#include "public.h"
#include "FibProxyData.h"

/*** Ӧ��ҵ��FieldID ***/
REGISTER_FIELD(FPP_FID_RspInfo, CFPPRspInfoField, "��Ӧ��Ϣ");
REGISTER_FIELD(FPP_Dissemination, CFPPDisseminationField, "��Ϣ�ַ�");
REGISTER_FIELD(FPP_FID_ReqUserLogin, CFPPReqUserLoginField, "�û���¼����");
REGISTER_FIELD(FPP_FID_RspUserLogin, CFPPRspUserLoginField, "�û���¼Ӧ��");
REGISTER_FIELD(FPP_FID_ReqUserLogout, CFPPReqUserLogoutField, "�û��ǳ�����");
REGISTER_FIELD(FPP_FID_RspUserLogout, CFPPRspUserLogoutField, "�û��ǳ�Ӧ��");
