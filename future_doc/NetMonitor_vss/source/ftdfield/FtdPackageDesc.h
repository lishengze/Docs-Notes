// FtdPackageDesc.h: 
//
//////////////////////////////////////////////////////////////////////

#if !defined(_FTDPACKAGEDESC_H)
#define _FTDPACKAGEDESC_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FtdData.h"
#include "FieldSet.h"


#define FTD_VERSION 4

const WORD TSS_DIALOG = 1;		//�Ի���
const WORD TSS_PRIVATE = 2;		//��Ա˽����
const WORD TSS_PUBLIC = 3;		//������
const WORD TSS_QUERY = 4;		//��ѯ
const WORD TSS_USER = 5;		//����Ա˽����


//����Ӧ��
const DWORD FTD_TID_RspError=0x00000001;
//�û���¼����
const DWORD FTD_TID_ReqUserLogin=0x00001001;
//�û���¼Ӧ��
const DWORD FTD_TID_RspUserLogin=0x00001002;
//�û��˳�����
const DWORD FTD_TID_ReqUserLogout=0x00001003;
//�û��˳�Ӧ��
const DWORD FTD_TID_RspUserLogout=0x00001004;
//����¼������
const DWORD FTD_TID_ReqOrderInsert=0x00001005;
//����¼��Ӧ��
const DWORD FTD_TID_RspOrderInsert=0x00001006;
//������������
const DWORD FTD_TID_ReqOrderAction=0x00001007;
//��������Ӧ��
const DWORD FTD_TID_RspOrderAction=0x00001008;
//����¼������
const DWORD FTD_TID_ReqQuoteInsert=0x00001009;
//����¼��Ӧ��
const DWORD FTD_TID_RspQuoteInsert=0x0000100A;
//���۲�������
const DWORD FTD_TID_ReqQuoteAction=0x0000100B;
//���۲���Ӧ��
const DWORD FTD_TID_RspQuoteAction=0x0000100C;
//OTC����¼������
const DWORD FTD_TID_ReqOTCOrderInsert=0x0000100D;
//OTC����¼��Ӧ��
const DWORD FTD_TID_RspOTCOrderInsert=0x0000100E;
//�û������޸�����
const DWORD FTD_TID_ReqUserPasswordUpdate=0x0000100F;
//�û������޸�Ӧ��
const DWORD FTD_TID_RspUserPasswordUpdate=0x00001010;
//ִ������¼������
const DWORD FTD_TID_ReqExecOrderInsert=0x00001011;
//ִ������¼��Ӧ��
const DWORD FTD_TID_RspExecOrderInsert=0x00001012;
//ִ�������������
const DWORD FTD_TID_ReqExecOrderAction=0x00001013;
//ִ���������Ӧ��
const DWORD FTD_TID_RspExecOrderAction=0x00001014;
//������¼������
const DWORD FTD_TID_ReqAdminOrderInsert=0x00001015;
//������¼��Ӧ��
const DWORD FTD_TID_RspAdminOrderInsert=0x00001016;
//�Ǳ���ϱ���¼������
const DWORD FTD_TID_ReqCombOrderInsert=0x00001017;
//�Ǳ���ϱ���¼��Ӧ��
const DWORD FTD_TID_RspCombOrderInsert=0x00001018;
//������������
const DWORD FTD_TID_ReqSubscribeTopic=0x00001F01;
//��������Ӧ��
const DWORD FTD_TID_RspSubscribeTopic=0x00001F02;
//��������������
const DWORD FTD_TID_ReqBulletin=0x00002005;
//��������������Ӧ��
const DWORD FTD_TID_RspBulletin=0x00002006;
//��������Ϣ����
const DWORD FTD_TID_ReqInformation=0x00002805;
//������������ϢӦ��
const DWORD FTD_TID_RspInformation=0x00002806;
//��Լ����״̬�ı�����
const DWORD FTD_TID_ReqInstrumentStatusUpdate=0x00002007;
//��Լ����״̬�ı�Ӧ��
const DWORD FTD_TID_RspInstrumentStatusUpdate=0x00002008;
//ǿ���û��˳�����
const DWORD FTD_TID_ReqForceUserExit=0x0000200B;
//ǿ���û��˳�Ӧ��
const DWORD FTD_TID_RspForceUserExit=0x0000200C;
//�û��Ựɾ������
const DWORD FTD_TID_ReqForceUserLogout=0x0000200D;
//�û��Ựɾ��Ӧ��
const DWORD FTD_TID_RspForceUserLogout=0x0000200E;
//����������ͬ��״̬�ı�����
const DWORD FTD_TID_ReqExchangeDataSyncStatusUpdate=0x00002013;
//����������ͬ��״̬�ı�Ӧ��
const DWORD FTD_TID_RspExchangeDataSyncStatusUpdate=0x00002014;
//����������ͬ��״̬�ı�����
const DWORD FTD_TID_ReqSGDataSyncStatusUpdate=0x00002015;
//����������ͬ��״̬�ı�Ӧ��
const DWORD FTD_TID_RspSGDataSyncStatusUpdate=0x00002016;
//��Ա�ʽ��ѯ����
const DWORD FTD_TID_ReqQryPartAccount=0x00004001;
//��Ա�ʽ��ѯӦ��
const DWORD FTD_TID_RspQryPartAccount=0x00004002;
//������ѯ����
const DWORD FTD_TID_ReqQryOrder=0x00004003;
//������ѯӦ��
const DWORD FTD_TID_RspQryOrder=0x00004004;
//���۲�ѯ����
const DWORD FTD_TID_ReqQryQuote=0x00004005;
//���۲�ѯӦ��
const DWORD FTD_TID_RspQryQuote=0x00004006;
//�ɽ�����ѯ����
const DWORD FTD_TID_ReqQryTrade=0x00004007;
//�ɽ�����ѯӦ��
const DWORD FTD_TID_RspQryTrade=0x00004008;
//��Ա�ͻ���ѯ����
const DWORD FTD_TID_ReqQryClient=0x00004009;
//��Ա�ͻ���ѯӦ��
const DWORD FTD_TID_RspQryClient=0x0000400A;
//��Ա�ֲֲ�ѯ����
const DWORD FTD_TID_ReqQryPartPosition=0x0000400B;
//��Ա�ֲֲ�ѯӦ��
const DWORD FTD_TID_RspQryPartPosition=0x0000400C;
//�ͻ��ֲֲ�ѯ����
const DWORD FTD_TID_ReqQryClientPosition=0x0000400D;
//�ͻ��ֲֲ�ѯӦ��
const DWORD FTD_TID_RspQryClientPosition=0x0000400E;
//��Լ��ѯ����
const DWORD FTD_TID_ReqQryInstrument=0x0000400F;
//��Լ��ѯӦ��
const DWORD FTD_TID_RspQryInstrument=0x00004010;
//��Լ����״̬��ѯ����
const DWORD FTD_TID_ReqQryInstrumentStatus=0x00004011;
//��Լ����״̬��ѯӦ��
const DWORD FTD_TID_RspQryInstrumentStatus=0x00004012;
//������״̬��ѯ����
const DWORD FTD_TID_ReqQrySGDataSyncStatus=0x00004013;
//������״̬��ѯӦ��
const DWORD FTD_TID_RspQrySGDataSyncStatus=0x00004014;
//��ֵ��Ȳ�ѯ
const DWORD FTD_TID_ReqQryHedgeVolume=0x00004015;
//��ֵ���Ӧ��
const DWORD FTD_TID_RspQryHedgeVolume=0x00004016;
//�����޶��ѯ����
const DWORD FTD_TID_ReqQryCreditLimit=0x00004017;
//�����޶��ѯӦ��
const DWORD FTD_TID_RspQryCreditLimit=0x00004018;
//�Ǳ���ϱ�����ѯ����
const DWORD FTD_TID_ReqQryCombOrder=0x00004019;
//�Ǳ���ϱ�����ѯӦ��
const DWORD FTD_TID_RspQryCombOrder=0x0000401A;
//ִ�������ѯ����
const DWORD FTD_TID_ReqQryExecOrder=0x00004020;
//ִ�������ѯӦ��
const DWORD FTD_TID_RspQryExecOrder=0x00004021;
//��ͨ�����ѯ����
const DWORD FTD_TID_ReqQryMarketData=0x00004101;
//��ͨ�����ѯӦ��
const DWORD FTD_TID_RspQryMarketData=0x00004102;
//�����������ѯ����
const DWORD FTD_TID_ReqQryBulletin=0x00004103;
//�����������ѯ����Ӧ��
const DWORD FTD_TID_RspQryBulletin=0x00004104;
//�����ѯ����
const DWORD FTD_TID_ReqQryTopic=0x00004201;
//�����ѯӦ��
const DWORD FTD_TID_RspQryTopic=0x00004202;
//�û����߲�ѯ����
const DWORD FTD_TID_ReqQryUserSession=0x000043D1;
//�û����߲�ѯӦ��
const DWORD FTD_TID_RspQryUserSession=0x000043D2;
//�û���ѯ����
const DWORD FTD_TID_ReqQryUser=0x000043D3;
//�û���ѯӦ��
const DWORD FTD_TID_RspQryUser=0x000043D4;
//��Ա��ѯ����
const DWORD FTD_TID_ReqQryParticipant=0x000043D5;
//��Ա��ѯӦ��
const DWORD FTD_TID_RspQryParticipant=0x000043D6;
//��Լ��λ��ѯ
const DWORD FTD_TID_ReqQryMBLMarketData=0x000043E1;
//��Լ��λ��ѯӦ��
const DWORD FTD_TID_RspQryMBLMarketData=0x000043E2;
//��Ϣ��ѯ
const DWORD FTD_TID_ReqQryInformation=0x000043E3;
//��Ϣ��ѯӦ��
const DWORD FTD_TID_RspQryInformation=0x000043E4;
//�ɽ��ر�
const DWORD FTD_TID_RtnTrade=0x00005001;
//�����ر�
const DWORD FTD_TID_RtnOrder=0x00005002;
//ִ������ر�
const DWORD FTD_TID_RtnExecOrder=0x00005003;
//���ۻر�
const DWORD FTD_TID_RtnQuote=0x00005004;
//�Ǳ���ϱ����ر�
const DWORD FTD_TID_RtnCombOrder=0x00005005;
//��Լ����״̬֪ͨ
const DWORD FTD_TID_RtnInstrumentStatus=0x00005011;
//���Ӻ�Լ֪ͨ
const DWORD FTD_TID_RtnInsInstrument=0x00005101;
//ɾ����Լ֪ͨ
const DWORD FTD_TID_RtnDelInstrument=0x00005102;
//���Ӻ�Լ����֪ͨ
const DWORD FTD_TID_RtnInsCombinationLeg=0x00005103;
//ɾ����Լ����֪ͨ
const DWORD FTD_TID_RtnDelCombinationLeg=0x00005104;
//��������֪ͨ
const DWORD FTD_TID_RtnAliasDefine=0x0000510A;
//����������֪ͨ
const DWORD FTD_TID_RtnFlowMessageCancel=0x00005201;
//����֪ͨ
const DWORD FTD_TID_RtnBulletin=0x00005801;
//��ͨ����֪ͨ
const DWORD FTD_TID_RtnMarketData=0x00005802;
//�������֪ͨ
const DWORD FTD_TID_RtnDepthMarketData=0x00005803;
//�ڲ��ַ���Ϣ֪ͨ
const DWORD FTD_TID_IntlRtnDissemination=0x00005901;
//�ڲ��������֪ͨ
const DWORD FTD_TID_IntlRtnDepthMarketData=0x00005902;
//������֪ͨ
const DWORD FTD_TID_RtnAdminOrder=0x00005A01;
//����¼�����ر�
const DWORD FTD_TID_ErrRtnOrderInsert=0x00006081;
//������������ر�
const DWORD FTD_TID_ErrRtnOrderAction=0x00006082;
//����¼�����ر�
const DWORD FTD_TID_ErrRtnQuoteInsert=0x00006083;
//���۲�������ر�
const DWORD FTD_TID_ErrRtnQuoteAction=0x00006084;
//ִ������¼�����ر�
const DWORD FTD_TID_ErrRtnExecOrderInsert=0x00006085;
//ִ�������������ر�
const DWORD FTD_TID_ErrRtnExecOrderAction=0x00006086;
//������¼�����ر�
const DWORD FTD_TID_ErrAdminOrderInsert=0x00006087;
//�Ǳ���ϱ���¼�����ر�
const DWORD FTD_TID_ErrRtnCombOrderInsert=0x00006088;
//�ͻ��ֲֲ�ѯ����
const DWORD FTD_TID_ReqQryClientPositionV1=0x0000400D;
//���ʲ�ѯ����
const DWORD FTD_TID_ReqQryExchangeRate=0x00006089;
//���ʲ�ѯӦ��
const DWORD FTD_TID_RspQryExchangeRate=0x0000608A;
//��·����
const DWORD FTD_TID_IntlLoopMeasureData=0x0000608B;
//CPU��ѯ
const DWORD FTD_TID_ReqQryTopCpuInfoTopic=0x00009001;
//CPUӦ��
const DWORD FTD_TID_RspQryTopCpuInfoTopic=0x00009002;
//CPUӦ��
const DWORD FTD_TID_RtnTopCpuInfoTopic=0x00009003;
//Mem��ѯ
const DWORD FTD_TID_ReqQryTopMemInfoTopic=0x00009004;
//MemӦ��
const DWORD FTD_TID_RspQryTopMemInfoTopic=0x00009005;
//MemӦ��
const DWORD FTD_TID_RtnTopMemInfoTopic=0x00009006;
//process��ѯ
const DWORD FTD_TID_ReqQryTopProcessInfoTopic=0x00009007;
//processӦ��
const DWORD FTD_TID_RspQryTopProcessInfoTopic=0x00009008;
//processӦ��
const DWORD FTD_TID_RtnTopProcessInfoTopic=0x00009009;
//filesystem��ѯ
const DWORD FTD_TID_ReqQryFileSystemInfoTopic=0x0000900A;
//filesystemӦ��
const DWORD FTD_TID_RspQryFileSystemInfoTopic=0x0000900B;
//filesystemӦ��
const DWORD FTD_TID_RtnFileSystemInfoTopic=0x0000900C;
//network��ѯ
const DWORD FTD_TID_ReqQryNetworkInfoTopic=0x0000900D;
//networkӦ��
const DWORD FTD_TID_RspQryNetworkInfoTopic=0x0000900E;
//networkӦ��
const DWORD FTD_TID_RtnNetworkInfoTopic=0x0000900F;
//����������Ϣ��ѯ
const DWORD FTD_TID_ReqQryHostEnvTopic=0x00009022;
//�ͻ��˵�¼��ѯ
const DWORD FTD_TID_ReqQryClientLoginTopic=0x00009025;
//�ͻ��˵�¼Ӧ��
const DWORD FTD_TID_RspQryClientLoginTopic=0x00009026;
//��ü�ض�����Ϣ��ѯ
const DWORD FTD_TID_ReqQryMonitorObjectTopic=0x00009028;
//��ü�ض�����ϢӦ��
const DWORD FTD_TID_RspQryMonitorObjectTopic=0x00009029;
//��ü�ض�����ϢӦ��
const DWORD FTD_TID_RtnMonitorObjectTopic=0x0000902A;
//���ҵ����̺������Ķ�Ӧ��ϵ��ѯ
const DWORD FTD_TID_ReqQryObjectRationalTopic=0x0000902B;
//���ҵ����̺������Ķ�Ӧ��ϵӦ��
const DWORD FTD_TID_RspQryObjectRationalTopic=0x0000902C;
//���ҵ����̺������Ķ�Ӧ��ϵӦ��
const DWORD FTD_TID_RtnObjectRationalTopic=0x0000902D;
//��־�ļ����ݲ�ѯ
const DWORD FTD_TID_ReqQrySyslogInfoTopic=0x00009034;
//��־�ļ�����Ӧ��
const DWORD FTD_TID_RspQrySyslogInfoTopic=0x00009035;
//��־�ļ�����Ӧ��
const DWORD FTD_TID_RtnSyslogInfoTopic=0x00009036;
//������ݶ�������
const DWORD FTD_TID_ReqQrySubscriberTopic=0x00009037;
//������ݶ���Ӧ��
const DWORD FTD_TID_RspQrySubscriberTopic=0x00009038;
//�����ϵ��ѯ
const DWORD FTD_TID_ReqQryOidRelationTopic=0x00009196;
//�����ϵ��ѯӦ��
const DWORD FTD_TID_RspQryOidRelationTopic=0x00009197;
//�����ϵ��ѯӦ��
const DWORD FTD_TID_RtnOidRelationTopic=0x00009198;
//�û���Ϣ��ѯ����
const DWORD FTD_TID_ReqQryUserInfoTopic=0x00009212;
//�û���Ϣ��ѯ����Ӧ��
const DWORD FTD_TID_RspQryUserInfoTopic=0x00009213;
//�û���Ϣ��ѯ����Ӧ��
const DWORD FTD_TID_RtnUserInfoTopic=0x00009214;
//�����û���Ϣ��ѯ����
const DWORD FTD_TID_ReqQryOnlineUserInfoTopic=0x00009215;
//�����û���Ϣ��ѯ����Ӧ��
const DWORD FTD_TID_RspQryOnlineUserInfoTopic=0x00009216;
//�����û���Ϣ��ѯ����Ӧ��
const DWORD FTD_TID_RtnOnlineUserInfoTopic=0x00009217;
//�澯�¼���ѯ����
const DWORD FTD_TID_ReqQryWarningEventTopic=0x00009221;
//�澯�¼���ѯ����Ӧ��
const DWORD FTD_TID_RspQryWarningEventTopic=0x00009222;
//�澯�¼���ѯ����Ӧ��
const DWORD FTD_TID_RtnWarningEventTopic=0x00009223;
//CPUʹ���ʲ�ѯ����
const DWORD FTD_TID_ReqQryCPUUsageTopic=0x00009227;
//CPUʹ���ʲ�ѯ����Ӧ��
const DWORD FTD_TID_RspQryCPUUsageTopic=0x00009228;
//CPUʹ���ʲ�ѯ����Ӧ��
const DWORD FTD_TID_RtnCPUUsageTopic=0x00009229;
//�ڴ�ʹ���ʲ�ѯ����
const DWORD FTD_TID_ReqQryMemoryUsageTopic=0x00009230;
//�ڴ�ʹ���ʲ�ѯ����Ӧ��
const DWORD FTD_TID_RspQryMemoryUsageTopic=0x00009231;
//�ڴ�ʹ���ʲ�ѯ����Ӧ��
const DWORD FTD_TID_RtnMemoryUsageTopic=0x00009232;
//Ӳ��ʹ���ʲ�ѯ����
const DWORD FTD_TID_ReqQryDiskUsageTopic=0x00009233;
//Ӳ��ʹ���ʲ�ѯ����Ӧ��
const DWORD FTD_TID_RspQryDiskUsageTopic=0x00009234;
//Ӳ��ʹ���ʲ�ѯ����Ӧ��
const DWORD FTD_TID_RtnDiskUsageTopic=0x00009235;
//����״ָ̬���ѯ
const DWORD FTD_TID_ReqQryObjectAttrTopic=0x00009236;
//����״ָ̬���ѯӦ��
const DWORD FTD_TID_RspQryObjectAttrTopic=0x00009237;
//����״ָ̬���ѯӦ��
const DWORD FTD_TID_RtnObjectAttrTopic=0x00009238;
//KeyFile��ѯ����
const DWORD FTD_TID_ReqQryKeyFileInfoTopic=0x00009224;
//HostMonitorCfg��ѯ����
const DWORD FTD_TID_ReqQryHostMonitorCfgTopic=0x00009225;
//AppMonitorCfg��ѯ����
const DWORD FTD_TID_ReqQryAppMonitorCfgTopic=0x00009226;
//HostConfig��ѯ����
const DWORD FTD_TID_ReqQryHostConfigTopic=0x00009242;
//��Ч������ѯ
const DWORD FTD_TID_ReqQryInvalidateOrderTopic=0x00009400;
//��Ч������ѯӦ��
const DWORD FTD_TID_RspQryInvalidateOrderTopic=0x00009401;
//��Ч������ѯӦ��
const DWORD FTD_TID_RtnInvalidateOrderTopic=0x00009402;
//����״̬��ѯ
const DWORD FTD_TID_ReqQryOrderStatusTopic=0x00009403;
//����״̬��ѯӦ��
const DWORD FTD_TID_RspQryOrderStatusTopic=0x00009404;
//����״̬��ѯӦ��
const DWORD FTD_TID_RtnOrderStatusTopic=0x00009405;
//�����ɽ���ѯ
const DWORD FTD_TID_ReqQryBargainOrderTopic=0x00009406;
//�����ɽ���ѯӦ��
const DWORD FTD_TID_RspQryBargainOrderTopic=0x00009407;
//�����ɽ���ѯӦ��
const DWORD FTD_TID_RtnBargainOrderTopic=0x00009408;
//��Լ�������Բ�ѯ
const DWORD FTD_TID_ReqQryInstPropertyTopic=0x00009409;
//��Լ�������Բ�ѯӦ��
const DWORD FTD_TID_RspQryInstPropertyTopic=0x00009410;
//��Լ�������Բ�ѯӦ��
const DWORD FTD_TID_RtnInstPropertyTopic=0x00009411;
//��Լ��֤���ʲ�ѯ
const DWORD FTD_TID_ReqQryMarginRateTopic=0x00009412;
//��Լ��֤���ʲ�ѯӦ��
const DWORD FTD_TID_RspQryMarginRateTopic=0x00009413;
//��Լ��֤���ʲ�ѯӦ��
const DWORD FTD_TID_RtnMarginRateTopic=0x00009414;
//��Լ�ǵ�ͣ���ѯ
const DWORD FTD_TID_ReqQryPriceLimitTopic=0x00009415;
//��Լ�ǵ�ͣ���ѯӦ��
const DWORD FTD_TID_RspQryPriceLimitTopic=0x00009416;
//��Լ�ǵ�ͣ���ѯӦ��
const DWORD FTD_TID_RtnPriceLimitTopic=0x00009417;
//��Ա�޲ֲ�ѯ
const DWORD FTD_TID_ReqQryPartPosiLimitTopic=0x00009418;
//��Ա�޲ֲ�ѯӦ��
const DWORD FTD_TID_RspQryPartPosiLimitTopic=0x00009419;
//��Ա�޲ֲ�ѯӦ��
const DWORD FTD_TID_RtnPartPosiLimitTopic=0x00009420;
//�ͻ��޲ֲ�ѯ
const DWORD FTD_TID_ReqQryClientPosiLimitTopic=0x00009421;
//�ͻ��޲ֲ�ѯӦ��
const DWORD FTD_TID_RspQryClientPosiLimitTopic=0x00009422;
//�ͻ��޲ֲ�ѯӦ��
const DWORD FTD_TID_RtnClientPosiLimitTopic=0x00009423;
//����ͻ��޲ֲ�ѯ
const DWORD FTD_TID_ReqQrySpecialPosiLimitTopic=0x00009424;
//����ͻ��޲ֲ�ѯӦ��
const DWORD FTD_TID_RspQrySpecialPosiLimitTopic=0x00009425;
//����ͻ��޲ֲ�ѯӦ��
const DWORD FTD_TID_RtnSpecialPosiLimitTopic=0x00009426;
//�˻�������ѯ
const DWORD FTD_TID_ReqQryTransactionChgTopic=0x00009427;
//�˻�������ѯӦ��
const DWORD FTD_TID_RspQryTransactionChgTopic=0x00009428;
//�˻�������ѯӦ��
const DWORD FTD_TID_RtnTransactionChgTopic=0x00009429;
//�ͻ����ݱ䶯��ѯ
const DWORD FTD_TID_ReqQryClientChgTopic=0x00009430;
//�ͻ����ݱ䶯��ѯӦ��
const DWORD FTD_TID_RspQryClientChgTopic=0x00009431;
//�ͻ����ݱ䶯��ѯӦ��
const DWORD FTD_TID_RtnClientChgTopic=0x00009432;
//��Ա�ͻ����ձ䶯��ѯ
const DWORD FTD_TID_ReqQryPartClientChgTopic=0x00009433;
//��Ա�ͻ����ձ䶯��ѯӦ��
const DWORD FTD_TID_RspQryPartClientChgTopic=0x00009434;
//��Ա�ͻ����ձ䶯��ѯӦ��
const DWORD FTD_TID_RtnPartClientChgTopic=0x00009435;
//�޲����ݱ䶯��ѯ
const DWORD FTD_TID_ReqQryPosiLimitChgTopic=0x00009436;
//�޲����ݱ䶯��ѯӦ��
const DWORD FTD_TID_RspQryPosiLimitChgTopic=0x00009437;
//�޲����ݱ䶯��ѯӦ��
const DWORD FTD_TID_RtnPosiLimitChgTopic=0x00009438;
//��ֵ��ȱ䶯��ѯ
const DWORD FTD_TID_ReqQryHedgeDetailChgTopic=0x00009439;
//��ֵ��ȱ䶯��ѯӦ��
const DWORD FTD_TID_RspQryHedgeDetailChgTopic=0x00009440;
//��ֵ��ȱ䶯��ѯӦ��
const DWORD FTD_TID_RtnHedgeDetailChgTopic=0x00009441;
//��Ա�䶯��ѯ
const DWORD FTD_TID_ReqQryParticipantChgTopic=0x00009442;
//��Ա�䶯��ѯӦ��
const DWORD FTD_TID_RspQryParticipantChgTopic=0x00009443;
//��Ա�䶯��ѯӦ��
const DWORD FTD_TID_RtnParticipantChgTopic=0x00009444;
//��֤���ʱ䶯��ѯ
const DWORD FTD_TID_ReqQryMarginRateChgTopic=0x00009445;
//��֤���ʱ䶯��ѯӦ��
const DWORD FTD_TID_RspQryMarginRateChgTopic=0x00009446;
//��֤���ʱ䶯��ѯӦ��
const DWORD FTD_TID_RtnMarginRateChgTopic=0x00009447;
//IP��ַ�䶯��ѯ
const DWORD FTD_TID_ReqQryUserIpChgTopic=0x00009448;
//IP��ַ�䶯��ѯӦ��
const DWORD FTD_TID_RspQryUserIpChgTopic=0x00009449;
//IP��ַ�䶯��ѯӦ��
const DWORD FTD_TID_RtnUserIpChgTopic=0x00009450;
//�޲����ݱ䶯��ѯ
const DWORD FTD_TID_ReqQryClientPosiLimitChgTopic=0x00009451;
//�޲����ݱ䶯��ѯӦ��
const DWORD FTD_TID_RspQryClientPosiLimitChgTopic=0x00009452;
//�޲����ݱ䶯��ѯӦ��
const DWORD FTD_TID_RtnClientPosiLimitChgTopic=0x00009453;
//�޲����ݱ䶯��ѯ
const DWORD FTD_TID_ReqQrySpecPosiLimitChgTopic=0x00009454;
//�޲����ݱ䶯��ѯӦ��
const DWORD FTD_TID_RspQrySpecPosiLimitChgTopic=0x00009455;
//�޲����ݱ䶯��ѯӦ��
const DWORD FTD_TID_RtnSpecPosiLimitChgTopic=0x00009456;
//��ʷ����״ָ̬���ѯ
const DWORD FTD_TID_ReqQryHistoryObjectAttrTopic=0x00009457;
//��ʷ����״ָ̬���ѯӦ��
const DWORD FTD_TID_RspQryHistoryObjectAttrTopic=0x00009458;
//��ʷ����״ָ̬���ѯӦ��
const DWORD FTD_TID_RtnHistoryObjectAttrTopic=0x00009459;
//ǰ����Ӧ��Ϣ��ѯ
const DWORD FTD_TID_ReqQryFrontInfoTopic=0x00009460;
//ǰ����Ӧ��Ϣ��ѯӦ��
const DWORD FTD_TID_RspQryFrontInfoTopic=0x00009461;
//ǰ����Ӧ��Ϣ��ѯӦ��
const DWORD FTD_TID_RtnFrontInfoTopic=0x00009462;
//�û���¼
const DWORD FTD_TID_ReqQrySysUserLoginTopic=0x00009463;
//�û���¼Ӧ��
const DWORD FTD_TID_RspQrySysUserLoginTopic=0x00009464;
//�û��ǳ�
const DWORD FTD_TID_ReqQrySysUserLogoutTopic=0x00009465;
//�û��ǳ�Ӧ��
const DWORD FTD_TID_RspQrySysUserLogoutTopic=0x00009466;
//�û��޸�����
const DWORD FTD_TID_ReqQrySysUserPasswordUpdateTopic=0x00009467;
//�û��޸�����Ӧ��
const DWORD FTD_TID_RspQrySysUserPasswordUpdateTopic=0x00009468;
//ע���û�
const DWORD FTD_TID_ReqQrySysUserRegisterTopic=0x00009469;
//ע���û�Ӧ��
const DWORD FTD_TID_RspQrySysUserRegisterTopic=0x00009470;
//ɾ���û�
const DWORD FTD_TID_ReqQrySysUserDeleteTopic=0x00009471;
//ɾ���û�Ӧ��
const DWORD FTD_TID_RspQrySysUserDeleteTopic=0x00009472;
//��Ա��ʼ��Ӧ��
const DWORD FTD_TID_RspQryParticipantInitTopic=0x00009474;
//��Ա��ʼ��Ӧ��
const DWORD FTD_TID_RtnParticipantInitTopic=0x00009475;
//��ϯ��ʼ��Ӧ��
const DWORD FTD_TID_RspQryUserInitTopic=0x00009476;
//��ϯ��ʼ��Ӧ��
const DWORD FTD_TID_RtnUserInitTopic=0x00009477;
//�ͻ���ʼ��Ӧ��
const DWORD FTD_TID_RspQryClientInitTopic=0x00009478;
//�ͻ���ʼ��Ӧ��
const DWORD FTD_TID_RtnClientInitTopic=0x00009479;
//������־��ѯ
const DWORD FTD_TID_ReqQryTradeLogTopic=0x00009480;
//������־��ѯӦ��
const DWORD FTD_TID_RspQryTradeLogTopic=0x00009481;
//������־��ѯӦ��
const DWORD FTD_TID_RtnTradeLogTopic=0x00009482;
//�澯�¼��޸�
const DWORD FTD_TID_ReqQryWarningEventUpdateTopic=0x00009485;
//����ϵͳ��¼��Ϣ��ѯ
const DWORD FTD_TID_ReqQryTradeUserLoginInfoTopic=0x00009486;
//����ϵͳ��¼��Ϣ
const DWORD FTD_TID_RspQryTradeUserLoginInfoTopic=0x00009487;
//����ϵͳ��¼��Ϣ
const DWORD FTD_TID_RtnTradeUserLoginInfoTopic=0x00009488;
//��Ա���ײ�ѯ
const DWORD FTD_TID_ReqQryPartTradeTopic=0x00009489;
//��Ա���ײ�ѯӦ��
const DWORD FTD_TID_RspQryPartTradeTopic=0x00009490;
//���׷�ֵ��ѯ
const DWORD FTD_TID_ReqQryTradepeakTopic=0x00009491;
//���׷�ֵ��ѯӦ��
const DWORD FTD_TID_RspQryTradepeakTopic=0x00009492;
//
const DWORD FTD_TID_RtnUpdateSysConfigTopic=0x00009493;
//
const DWORD FTD_TID_RtnSysUser=0x00009494;
//
const DWORD FTD_TID_RtnPriceLimitChgTopic=0x00009495;
//����ƽ̨��ʼ����Ϣ��ѯ
const DWORD FTD_TID_ReqQryParticipantInitTopic=0x00009496;
//����ƽ̨��ʼ����Ϣ��ѯ
const DWORD FTD_TID_ReqQryUserInitTopic=0x00009497;
//
const DWORD FTD_TID_ReqQryHistoryCpuInfoTopic=0x00009500;
//
const DWORD FTD_TID_RspQryHistoryCpuInfoTopic=0x00009501;
//
const DWORD FTD_TID_ReqQryHistoryMemInfoTopic=0x00009502;
//
const DWORD FTD_TID_RspQryHistoryMemInfoTopic=0x00009503;
//
const DWORD FTD_TID_ReqQryHistoryNetworkInfoTopic=0x00009504;
//
const DWORD FTD_TID_RspQryHistoryNetworkInfoTopic=0x00009505;
//HostConfig��ѯ����Ӧ��
const DWORD FTD_TID_RspQryHostConfig=0x00009506;
//���ϵͳ�����û���ѯ
const DWORD FTD_TID_ReqQryMonitorOnlineUser=0x00009507;
//���ϵͳ�����û�Ӧ��
const DWORD FTD_TID_RspQryMonitorOnlineUser=0x00009508;
//����ϵͳǰ��ͳ�Ʋ�ѯ
const DWORD FTD_TID_ReqQryFrontStat=0x00009509;
//����ϵͳǰ��ͳ��Ӧ��
const DWORD FTD_TID_RspQryFrontStat=0x00009510;
//���ϵͳʱ��ͬ��
const DWORD FTD_TID_RtnSysTimeSyncTopic=0x00009511;
//���������л�֪ͨ
const DWORD FTD_TID_RtnDataCenterChgTopic=0x00009512;
//��ʷ��ֵ��ѯ
const DWORD FTD_TID_ReqQryHistoryTradePeakTopic=0x00009513;
//��ʷ��ֵ��ѯӦ��
const DWORD FTD_TID_RspQryHistoryTradePeakTopic=0x00009514;
//��ʷ��ֵ��ѯӦ��
const DWORD FTD_TID_RtnHistoryTradePeakTopic=0x00009515;
//��־�¼���ѯ
const DWORD FTD_TID_ReqQrySyslogEventTopic=0x00009516;
//��־�¼���ѯӦ��
const DWORD FTD_TID_RspQrySyslogEventTopic=0x00009517;
//��־�¼�Ӧ��
const DWORD FTD_TID_RtnSyslogEventTopic=0x00009518;
//��־�¼���������
const DWORD FTD_TID_ReqQrySyslogEventSubcriberTopic=0x00009519;
//�������л�֪ͨ
const DWORD FTD_TID_ReqQryTradeDayChangeTopic=0x00009520;
//�������л�֪ͨ
const DWORD FTD_TID_RspQryTradeDayChangeTopic=0x00009521;
//tomcat��Ϣ��ѯ
const DWORD FTD_TID_ReqQryTomcatInfoTopic=0x00009522;
//WebӦ����Ϣ
const DWORD FTD_TID_RspQryWebAppInfoTopic=0x00009523;
//WebӦ����Ϣ
const DWORD FTD_TID_RtnWebAppInfoTopic=0x00009524;
//Ӧ��servlet��Ϣ
const DWORD FTD_TID_RspQryServletInfoTopic=0x00009525;
//Ӧ��servlet��Ϣ
const DWORD FTD_TID_RtnServletInfoTopic=0x00009526;
//�ļ���Ϣ
const DWORD FTD_TID_RspQryFileInfoTopic=0x00009527;
//�ļ���Ϣ
const DWORD FTD_TID_RtnFileInfoTopic=0x00009528;
//Ӧ�ûỰ��Ϣ
const DWORD FTD_TID_RspQrySessionInfoTopic=0x00009529;
//Ӧ�ûỰ��Ϣ
const DWORD FTD_TID_RtnSessionInfoTopic=0x00009530;
//JDBC��Ϣ
const DWORD FTD_TID_RspQryJDBCInfoTopic=0x00009531;
//JDBC��Ϣ
const DWORD FTD_TID_RtnJDBCInfoTopic=0x00009532;
//�߳���Ϣ
const DWORD FTD_TID_RspQryThreadInfoTopic=0x00009533;
//�߳���Ϣ
const DWORD FTD_TID_RtnThreadInfoTopic=0x00009534;
//�������Ϣ��ѯ
const DWORD FTD_TID_ReqQryVMInfoTopic=0x00009535;
//�������Ϣ
const DWORD FTD_TID_RspQryVMInfoTopic=0x00009536;
//�������Ϣ
const DWORD FTD_TID_RtnVMInfoTopic=0x00009537;
//ϵͳ������Ϣ��ѯ
const DWORD FTD_TID_ReqQryPropertyInfoTopic=0x00009538;
//ϵͳ������Ϣ
const DWORD FTD_TID_RspQryPropertyInfoTopic=0x00009539;
//ϵͳ������Ϣ
const DWORD FTD_TID_RtnPropertyInfoTopic=0x00009540;
//ϵͳ�ڴ����Ϣ��ѯ
const DWORD FTD_TID_ReqQryMemPoolInfoTopic=0x00009541;
//ϵͳ�ڴ����Ϣ
const DWORD FTD_TID_RspQryMemPoolInfoTopic=0x00009542;
//ϵͳ�ڴ����Ϣ
const DWORD FTD_TID_RtnMemPoolInfoTopic=0x00009543;
//�ļ�������Ϣ��ѯ
const DWORD FTD_TID_ReqQryFileContentInfoTopic=0x00009544;
//�ļ�������Ϣ
const DWORD FTD_TID_RspQryFileContentInfoTopic=0x00009545;
//�ļ�������Ϣ
const DWORD FTD_TID_RtnFileContentInfoTopic=0x00009546;
//������Ϣ��ѯ
const DWORD FTD_TID_ReqQryConnectionInfoTopic=0x00009547;
//������Ϣ
const DWORD FTD_TID_RspQryConnectionInfoTopic=0x00009548;
//������Ϣ
const DWORD FTD_TID_RtnConnectionInfoTopic=0x00009549;
//��������Ϣ��ѯ
const DWORD FTD_TID_ReqQryConnectorInfoTopic=0x00009550;
//��������Ϣ
const DWORD FTD_TID_RspQryConnectorInfoTopic=0x00009551;
//��������Ϣ
const DWORD FTD_TID_RtnConnectorInfoTopic=0x00009552;
//���ݿ��ѯ
const DWORD FTD_TID_ReqQryDBQueryTopic=0x00009553;
//���ݿ��ѯӦ��
const DWORD FTD_TID_RspQryDBQueryTopic=0x00009554;
//���ݿ��ѯӦ��
const DWORD FTD_TID_RtnDBQueryTopic=0x00009555;
//ͨ�÷���Ӧ��
const DWORD FTD_TID_RspQryGeneralFieldTopic=0x00009556;
//ͨ�÷���Ӧ��
const DWORD FTD_TID_RtnGeneralFieldTopic=0x00009557;
//�ļ���������
const DWORD FTD_TID_ReqQryGetFileTopic=0x00009558;
//�ļ�����Ӧ��
const DWORD FTD_TID_RspQryGetFileTopic=0x00009559;
//��־�¼��޸�����
const DWORD FTD_TID_ReqQrySyslogEventUpdateTopic=0x00009560;
//�澯��ϸ��ѯ
const DWORD FTD_TID_ReqQryWarningQueryTopic=0x00009561;
//�澯��ϸ
const DWORD FTD_TID_RspQryWarningQueryTopic=0x00009562;
//�澯��ϸ
const DWORD FTD_TID_RtnWarningQueryTopic=0x00009563;
//��վ���ʲ�ѯ
const DWORD FTD_TID_ReqQryWebVisitTopic=0x00009564;
//HostConfig����Ӧ��
const DWORD FTD_TID_RtnHostConfig=0x00009565;
//�澯������
const DWORD FTD_TID_ReqQryWarningActiveChange=0x00009566;
//�澯������
const DWORD FTD_TID_RspQryWarningActiveChange=0x00009567;
//�澯������
const DWORD FTD_TID_RtnWarningActiveChange=0x00009568;
//ͨ�ò���
const DWORD FTD_TID_ReqQryGeneralOperateTopic=0x00009569;
//ͨ�ò���
const DWORD FTD_TID_RspQryGeneralOperateTopic=0x00009570;
//ͨ�ò���
const DWORD FTD_TID_RtnGeneralOperateTopic=0x00009571;
//�����豸���ӹ�ϵ����
const DWORD FTD_TID_ReqQryNetDeviceLinkedTopic=0x00009572;
//�����豸���ӹ�ϵ
const DWORD FTD_TID_RspQryNetDeviceLinkedTopic=0x00009573;
//�����豸���ӹ�ϵ
const DWORD FTD_TID_RtnNetDeviceLinkedTopic=0x00009574;
//����ϵͳ��¼��Ϣ����
const DWORD FTD_TID_ReqQryTradeUserLoginStatTopic=0x00009575;
//����ϵͳ��¼��Ϣ
const DWORD FTD_TID_RspQryTradeUserLoginStatTopic=0x00009576;
//����ϵͳǰ�ñ�����Ӧ��Ϣ
const DWORD FTD_TID_ReqQryTradeFrontOrderRttStatTopic=0x00009577;
//����ϵͳǰ�ñ�����Ӧ��Ϣ
const DWORD FTD_TID_RspQryTradeFrontOrderRttStatTopic=0x00009578;
//����ϵͳǰ�ñ�����Ӧ��Ϣ
const DWORD FTD_TID_RtnTradeFrontOrderRttStatTopic=0x00009579;
//��Աϯλ����״̬
const DWORD FTD_TID_ReqQryParticTradeOrderStatesTopic=0x0000957a;
//��Աϯλ����״̬
const DWORD FTD_TID_RspQryParticTradeOrderStatesTopic=0x0000957b;
//��Աϯλ����״̬
const DWORD FTD_TID_RtnParticTradeOrderStatesTopic=0x0000957c;
//ϵͳ·����Ϣ
const DWORD FTD_TID_ReqQryRouterInfoTopic=0x0000957d;
//ϵͳ·����Ϣ
const DWORD FTD_TID_RspQryRouterInfoTopic=0x0000957e;
//ϵͳ·����Ϣ
const DWORD FTD_TID_RtnRouterInfoTopic=0x0000957f;
//����I/O��Ϣ
const DWORD FTD_TID_ReqQryDiskIOTopic=0x00009580;
//����I/O��Ϣ
const DWORD FTD_TID_RspQryDiskIOTopic=0x00009581;
//����I/O��Ϣ
const DWORD FTD_TID_RtnDiskIOTopic=0x00009582;
//ϵͳ״̬��Ϣ
const DWORD FTD_TID_ReqQryStatInfoTopic=0x00009583;
//ϵͳ״̬��Ϣ
const DWORD FTD_TID_RspQryStatInfoTopic=0x00009584;
//ϵͳ״̬��Ϣ
const DWORD FTD_TID_RtnStatInfoTopic=0x00009585;
//����ϵͳǰ�ñ����ֲ�����
const DWORD FTD_TID_ReqQryTradeOrderRttCutLineTopic=0x00009586;
//����ϵͳǰ�ñ����ֲ�����
const DWORD FTD_TID_RspQryTradeOrderRttCutLineTopic=0x00009587;
//����ϵͳǰ�ñ����ֲ�����
const DWORD FTD_TID_RtnTradeOrderRttCutLineTopic=0x00009588;
//��Ա�ͻ���Ϣ
const DWORD FTD_TID_ReqQryClientInfoTopic=0x00009589;
//��Ա�ͻ���Ϣ
const DWORD FTD_TID_RspQryClientInfoTopic=0x0000958a;
//��Ա�ͻ���Ϣ
const DWORD FTD_TID_RtnClientInfoTopic=0x0000958b;
//�����¼�����
const DWORD FTD_TID_ReqQryEventDescriptionTopic=0x0000958c;
//Ӧ���¼�����
const DWORD FTD_TID_RspQryEventDescriptionTopic=0x0000958d;
//�����¼�����
const DWORD FTD_TID_RtnEventDescriptionTopic=0x0000958e;
//����ǰ��ΨһID��Ϣ
const DWORD FTD_TID_ReqQryFrontUniqueIDTopic=0x0000958f;
//Ӧ��ǰ��ΨһID��Ϣ
const DWORD FTD_TID_RspQryFrontUniqueIDTopic=0x00009590;
//����ǰ��ΨһID��Ϣ
const DWORD FTD_TID_RtnFrontUniqueIDTopic=0x00009591;
//��Ա��·��ַ�������
const DWORD FTD_TID_ReqQryNetPartyLinkAddrChangeTopic=0x00009592;
//��Ա��·��ַ�����Ӧ
const DWORD FTD_TID_RspQryNetPartyLinkAddrChangeTopic=0x00009593;
//���Ļ�Ա��·��ַ�����Ϣ
const DWORD FTD_TID_RtnNetPartyLinkAddrChangeTopic=0x00009594;
//������ɾ����Ա�б���Ϣ
const DWORD FTD_TID_ReqQryNetDelPartyLinkInfoTopic=0x00009595;
//Ӧ����ɾ����Ա�б���Ϣ
const DWORD FTD_TID_RspQryNetDelPartyLinkInfoTopic=0x00009596;
//������ɾ����Ա�б���Ϣ
const DWORD FTD_TID_RtnNetDelPartyLinkInfoTopic=0x00009597;
//����������������
const DWORD FTD_TID_ReqQryPerformanceTopTopic=0x00009598;
//����������������
const DWORD FTD_TID_RspQryPerformanceTopTopic=0x00009599;
//����������������
const DWORD FTD_TID_RtnPerformanceTopTopic=0x0000959a;
//����Լ״̬�л�����
const DWORD FTD_TID_ReqQryInstrumentStatusTopic=0x0000959b;
//����Լ״̬�л�����
const DWORD FTD_TID_RspQryInstrumentStatusTopic=0x0000959c;
//����Լ״̬�л�����
const DWORD FTD_TID_RtnInstrumentStatusTopic=0x0000959d;
//�����Լ���׽���Ϣ
const DWORD FTD_TID_ReqQryCurrTradingSegmentAttrTopic=0x0000959e;
//���غ�Լ���׽���Ϣ
const DWORD FTD_TID_RspQryCurrTradingSegmentAttrTopic=0x0000959f;
//���ĺ�Լ���׽���Ϣ
const DWORD FTD_TID_RtnCurrTradingSegmentAttrTopic=0x000095a0;
//��������ָ���ѯ
const DWORD FTD_TID_ReqQryRealTimeNetObjectAttrTopic=0x00100003;
//����������ֲ�ѯ
const DWORD FTD_TID_ReqQryNetAreaTopic=0x00100010;
//�����������Ӧ��
const DWORD FTD_TID_RspQryNetAreaTopic=0x00100011;
//�����������Ӧ��
const DWORD FTD_TID_RtnNetAreaTopic=0x00100012;
//����������ѯ
const DWORD FTD_TID_ReqQryNetSubAreaTopic=0x00100013;
//��������Ӧ��
const DWORD FTD_TID_RspQryNetSubAreaTopic=0x00100014;
//��������Ӧ��
const DWORD FTD_TID_RtnNetSubAreaTopic=0x00100015;
//��������IP��ѯ
const DWORD FTD_TID_ReqQryNetSubAreaIPTopic=0x00100016;
//��������IPӦ��
const DWORD FTD_TID_RspQryNetSubAreaIPTopic=0x00100017;
//��������IPӦ��
const DWORD FTD_TID_RtnNetSubAreaIPTopic=0x00100018;
//�����豸̽������
const DWORD FTD_TID_ReqQryNetDeviceDetectTopic=0x00100019;
//�����豸��ѯ����
const DWORD FTD_TID_ReqQryNetDeviceRequestTopic=0x00100020;
//�����豸
const DWORD FTD_TID_RspQryNetDeviceTopic=0x00100021;
//�����豸
const DWORD FTD_TID_RtnNetDeviceTopic=0x00100022;
//�����豸̽������Ӧ��
const DWORD FTD_TID_RspQryNetDeviceDetectTopic=0x00100023;
//��¥��ѯ
const DWORD FTD_TID_ReqQryNetBuildingTopic=0x00100024;
//��¥
const DWORD FTD_TID_RspQryNetBuildingTopic=0x00100025;
//��¥
const DWORD FTD_TID_RtnNetBuildingTopic=0x00100026;
//������ѯ
const DWORD FTD_TID_ReqQryNetRoomTopic=0x00100027;
//����
const DWORD FTD_TID_RspQryNetRoomTopic=0x00100028;
//����
const DWORD FTD_TID_RtnNetRoomTopic=0x00100029;
//�����ѯ
const DWORD FTD_TID_ReqQryNetCabinetsTopic=0x00100030;
//����
const DWORD FTD_TID_RspQryNetCabinetsTopic=0x00100031;
//����
const DWORD FTD_TID_RtnNetCabinetsTopic=0x00100032;
//OID
const DWORD FTD_TID_ReqQryNetOIDTopic=0x00100033;
//OID
const DWORD FTD_TID_RspQryNetOIDTopic=0x00100034;
//OID
const DWORD FTD_TID_RtnNetOIDTopic=0x00100035;
//ʱ�����
const DWORD FTD_TID_ReqQryNetTimePolicyTopic=0x00100036;
//ʱ�����
const DWORD FTD_TID_RspQryNetTimePolicyTopic=0x00100037;
//ʱ�����
const DWORD FTD_TID_RtnNetTimePolicyTopic=0x00100038;
//�ɼ������ѯ
const DWORD FTD_TID_ReqQryNetGatherTaskTopic=0x00100039;
//�ɼ�����
const DWORD FTD_TID_RspQryNetGatherTaskTopic=0x00100040;
//�ɼ�����
const DWORD FTD_TID_RtnNetGatherTaskTopic=0x00100041;
//�豸�������
const DWORD FTD_TID_ReqQryNetDeviceChgTopic=0x00100042;
//�豸���
const DWORD FTD_TID_RspQryNetDeviceChgTopic=0x00100043;
//�豸���
const DWORD FTD_TID_RtnNetDeviceChgTopic=0x00100044;
//�����豸�ͺ�����
const DWORD FTD_TID_ReqQryNetDeviceTypeTopic=0x00100045;
//�����豸�ͺ�
const DWORD FTD_TID_RspQryNetDeviceTypeTopic=0x00100046;
//�����豸�ͺ�
const DWORD FTD_TID_RtnNetDeviceTypeTopic=0x00100047;
//�����豸�������
const DWORD FTD_TID_ReqQryNetDeviceCategoryTopic=0x00100048;
//�����豸���
const DWORD FTD_TID_RspQryNetDeviceCategoryTopic=0x00100049;
//�����豸���
const DWORD FTD_TID_RtnNetDeviceCategoryTopic=0x00100050;
//�豸��������
const DWORD FTD_TID_ReqQryNetManufactoryTopic=0x00100051;
//�豸����
const DWORD FTD_TID_RspQryNetManufactoryTopic=0x00100052;
//�豸����
const DWORD FTD_TID_RtnNetManufactoryTopic=0x00100053;
//�豸��ͬ������
const DWORD FTD_TID_ReqQryNetCommunityTopic=0x00100054;
//�豸��ͬ��
const DWORD FTD_TID_RspQryNetCommunityTopic=0x00100055;
//�豸��ͬ��
const DWORD FTD_TID_RtnNetCommunityTopic=0x00100056;
//�˿���������
const DWORD FTD_TID_ReqQryNetPortTypeTopic=0x00100057;
//�˿�����
const DWORD FTD_TID_RspQryNetPortTypeTopic=0x00100058;
//�˿�����
const DWORD FTD_TID_RtnNetPortTypeTopic=0x00100059;
//��Ա����ص�����
const DWORD FTD_TID_ReqQryNetPartAccessSpotTopic=0x00100060;
//��Ա����ص�
const DWORD FTD_TID_RspQryNetPartAccessSpotTopic=0x00100061;
//��Ա����ص�
const DWORD FTD_TID_RtnNetPartAccessSpotTopic=0x00100062;
//�˿�����
const DWORD FTD_TID_ReqQryNetInterfaceTopic=0x00100063;
//�˿�
const DWORD FTD_TID_RspQryNetInterfaceTopic=0x00100064;
//�˿�
const DWORD FTD_TID_RtnNetInterfaceTopic=0x00100065;
//GeneralOID����
const DWORD FTD_TID_ReqQryNetGeneralOIDTopic=0x00100066;
//GeneralOID
const DWORD FTD_TID_RspQryNetGeneralOIDTopic=0x00100067;
//GeneralOID
const DWORD FTD_TID_RtnNetGeneralOIDTopic=0x00100068;
//��ض������
const DWORD FTD_TID_ReqQryNetMonitorTypeTopic=0x00100069;
//��ض������
const DWORD FTD_TID_RspQryNetMonitorTypeTopic=0x00100070;
//��ض������
const DWORD FTD_TID_RtnNetMonitorTypeTopic=0x00100071;
//ָ��ͳ��
const DWORD FTD_TID_ReqQryNetMonitorAttrScopeTopic=0x00100072;
//ָ��ͳ��
const DWORD FTD_TID_RspQryNetMonitorAttrScopeTopic=0x00100073;
//ָ��ͳ��
const DWORD FTD_TID_RtnNetMonitorAttrScopeTopic=0x00100074;
//���ָ���
const DWORD FTD_TID_ReqQryNetMonitorAttrTypeTopic=0x00100075;
//���ָ���
const DWORD FTD_TID_RspQryNetMonitorAttrTypeTopic=0x00100076;
//���ָ���
const DWORD FTD_TID_RtnNetMonitorAttrTypeTopic=0x00100077;
//��ض���ָ���
const DWORD FTD_TID_ReqQryNetMonitorObjectAttrTopic=0x00100078;
//��ض���ָ���
const DWORD FTD_TID_RspQryNetMonitorObjectAttrTopic=0x00100079;
//��ض���ָ���
const DWORD FTD_TID_RtnNetMonitorObjectAttrTopic=0x00100080;
//ְ����
const DWORD FTD_TID_ReqQryNetFuncAreaTopic=0x00100081;
//ְ����
const DWORD FTD_TID_RspQryNetFuncAreaTopic=0x00100082;
//ְ����
const DWORD FTD_TID_RtnNetFuncAreaTopic=0x00100083;
//���ָ���
const DWORD FTD_TID_ReqQryNetMonitorCommandTypeTopic=0x00100084;
//���ָ���
const DWORD FTD_TID_RspQryNetMonitorCommandTypeTopic=0x00100085;
//���ָ���
const DWORD FTD_TID_RtnNetMonitorCommandTypeTopic=0x00100086;
//�������
const DWORD FTD_TID_ReqQryNetMonitorActionGroupTopic=0x00100087;
//�������
const DWORD FTD_TID_RspQryNetMonitorActionGroupTopic=0x00100088;
//�������
const DWORD FTD_TID_RtnNetMonitorActionGroupTopic=0x00100089;
//�豸�������
const DWORD FTD_TID_ReqQryNetMonitorDeviceGroupTopic=0x00100090;
//�豸�������
const DWORD FTD_TID_RspQryNetMonitorDeviceGroupTopic=0x00100091;
//�豸�������
const DWORD FTD_TID_RtnNetMonitorDeviceGroupTopic=0x00100092;
//������Ϣ��
const DWORD FTD_TID_ReqQryNetMonitorTaskInfoTopic=0x00100093;
//������Ϣ��
const DWORD FTD_TID_RspQryNetMonitorTaskInfoTopic=0x00100094;
//������Ϣ��
const DWORD FTD_TID_RtnNetMonitorTaskInfoTopic=0x00100095;
//��������
const DWORD FTD_TID_ReqQryNetMonitorTaskResultTopic=0x00100096;
//��������
const DWORD FTD_TID_RspQryNetMonitorTaskResultTopic=0x00100097;
//��������
const DWORD FTD_TID_RtnNetMonitorTaskResultTopic=0x00100098;
//�������
const DWORD FTD_TID_ReqQryNetMonitorTaskObjectSetTopic=0x00100099;
//�������
const DWORD FTD_TID_RspQryNetMonitorTaskObjectSetTopic=0x00100100;
//�������
const DWORD FTD_TID_RtnNetMonitorTaskObjectSetTopic=0x00100101;
//��Ա��·��Ϣ��
const DWORD FTD_TID_ReqQryNetPartyLinkInfoTopic=0x00100102;
//��Ա��·��Ϣ��
const DWORD FTD_TID_RspQryNetPartyLinkInfoTopic=0x00100103;
//��Ա��·��Ϣ��
const DWORD FTD_TID_RtnNetPartyLinkInfoTopic=0x00100104;
//��ض���ָ����ձ�
const DWORD FTD_TID_ReqQryNetMonitorActionAttrTopic=0x00100105;
//��ض���ָ����ձ�
const DWORD FTD_TID_RspQryNetMonitorActionAttrTopic=0x00100106;
//��ض���ָ����ձ�
const DWORD FTD_TID_RtnNetMonitorActionAttrTopic=0x00100107;
//ģ��
const DWORD FTD_TID_ReqQryNetModuleTopic=0x00100111;
//ģ��
const DWORD FTD_TID_RspQryNetModuleTopic=0x00100112;
//ģ��
const DWORD FTD_TID_RtnNetModuleTopic=0x00100113;
//�澯���ʽ��Ϣ��
const DWORD FTD_TID_ReqQryNetEventExprTopic=0x00100114;
//�澯���ʽ��Ϣ��
const DWORD FTD_TID_RspQryNetEventExprTopic=0x00100115;
//�澯���ʽ��Ϣ��
const DWORD FTD_TID_RtnNetEventExprTopic=0x00100116;
//�¼�����
const DWORD FTD_TID_ReqQryNetEventTypeTopic=0x00100117;
//�¼�����
const DWORD FTD_TID_RspQryNetEventTypeTopic=0x00100118;
//�¼�����
const DWORD FTD_TID_RtnNetEventTypeTopic=0x00100119;
//�¼�������
const DWORD FTD_TID_ReqQryNetSubEventTypeTopic=0x00100120;
//�¼�������
const DWORD FTD_TID_RspQryNetSubEventTypeTopic=0x00100121;
//�¼�������
const DWORD FTD_TID_RtnNetSubEventTypeTopic=0x00100122;
//�¼�����
const DWORD FTD_TID_ReqQryNetEventLevelTopic=0x00100123;
//�¼�����
const DWORD FTD_TID_RspQryNetEventLevelTopic=0x00100124;
//�¼�����
const DWORD FTD_TID_RtnNetEventLevelTopic=0x00100125;
//������״̬��
const DWORD FTD_TID_ReqQryNetMonitorTaskStatusResultTopic=0x00100126;
//������״̬��
const DWORD FTD_TID_RspQryNetMonitorTaskStatusResultTopic=0x00100127;
//������״̬��
const DWORD FTD_TID_RtnNetMonitorTaskStatusResultTopic=0x00100128;
//��½���÷��������
const DWORD FTD_TID_ReqConfigLoginTopic=0x00100129;
//���÷���Ե�½����Ӧ
const DWORD FTD_TID_RspConfigLoginTopic=0x00100130;
//�Ե�ǰ��¼���õķ����ɫ����Ӧ
const DWORD FTD_TID_RspServerTypeTopic=0x00100131;
//��֪���������˳�
const DWORD FTD_TID_ReqSysServerExitTopic=0x00100150;
//�豸���ñ�
const DWORD FTD_TID_ReqQryNetCfgFileTopic=0x00100151;
//�豸���ñ�
const DWORD FTD_TID_RspQryNetCfgFileTopic=0x00100152;
//�豸���ñ�
const DWORD FTD_TID_RtnNetCfgFileTopic=0x00100153;
//���������������
const DWORD FTD_TID_ReqQryNetMonitorDeviceTaskTopic=0x00100154;
//���������������
const DWORD FTD_TID_RspQryNetMonitorDeviceTaskTopic=0x00100155;
//���������������
const DWORD FTD_TID_RtnNetMonitorDeviceTaskTopic=0x00100156;
//����ָ��ָ�꼯��
const DWORD FTD_TID_ReqQryNetMonitorTaskInstAttrsTopic=0x00100157;
//����ָ��ָ�꼯��
const DWORD FTD_TID_RspQryNetMonitorTaskInstAttrsTopic=0x00100158;
//����ָ��ָ�꼯��
const DWORD FTD_TID_RtnNetMonitorTaskInstAttrsTopic=0x00100159;
//�ļ�ͨ�ò���
const DWORD FTD_TID_ReqQryFileGeneralOperTopic=0x00100160;
//�ļ�ͨ�ò���
const DWORD FTD_TID_RspQryFileGeneralOperTopic=0x00100161;
//�ļ�ͨ�ò���
const DWORD FTD_TID_RtnFileGeneralOperTopic=0x00100162;
//���߱�
const DWORD FTD_TID_ReqQryNetBaseLineTopic=0x00100163;
//���߱�
const DWORD FTD_TID_RspQryNetBaseLineTopic=0x00100164;
//���߱�
const DWORD FTD_TID_RtnNetBaseLineTopic=0x00100165;
//���������
const DWORD FTD_TID_ReqQryNetBaseLineTaskTopic=0x00100166;
//���������
const DWORD FTD_TID_RspQryNetBaseLineTaskTopic=0x00100167;
//���������
const DWORD FTD_TID_RtnNetBaseLineTaskTopic=0x00100168;
//���߽����
const DWORD FTD_TID_ReqQryNetBaseLineResultTopic=0x00100169;
//���߽����
const DWORD FTD_TID_RspQryNetBaseLineResultTopic=0x00100170;
//���߽����
const DWORD FTD_TID_RtnNetBaseLineResultTopic=0x00100171;
//��Ա��·״̬��Ϣ��
const DWORD FTD_TID_ReqQryNetPartyLinkStatusInfoTopic=0x00100172;
//��Ա��·״̬��Ϣ��
const DWORD FTD_TID_RspQryNetPartyLinkStatusInfoTopic=0x00100173;
//��Ա��·״̬��Ϣ��
const DWORD FTD_TID_RtnNetPartyLinkStatusInfoTopic=0x00100174;
//��ԱSDH��·��ϸ��
const DWORD FTD_TID_ReqQryNetMemberSDHLineInfoTopic=0x00100175;
//��ԱSDH��·��ϸ��
const DWORD FTD_TID_RspQryNetMemberSDHLineInfoTopic=0x00100176;
//��ԱSDH��·��ϸ��
const DWORD FTD_TID_RtnNetMemberSDHLineInfoTopic=0x00100177;
//DDN��·��Ϣ��
const DWORD FTD_TID_ReqQryNetDDNLinkInfoTopic=0x00100178;
//DDN��·��Ϣ��
const DWORD FTD_TID_RspQryNetDDNLinkInfoTopic=0x00100179;
//DDN��·��Ϣ��
const DWORD FTD_TID_RtnNetDDNLinkInfoTopic=0x0010017a;
//�ǻ�Ա��·ʹ����Ϣ
const DWORD FTD_TID_ReqQryNetPseudMemberLinkInfoTopic=0x0010017b;
//�ǻ�Ա��·ʹ����Ϣ
const DWORD FTD_TID_RspQryNetPseudMemberLinkInfoTopic=0x0010017c;
//�ǻ�Ա��·ʹ����Ϣ
const DWORD FTD_TID_RtnNetPseudMemberLinkInfoTopic=0x0010017d;
//Զ���豸��Ϣ
const DWORD FTD_TID_ReqQryOuterDeviceInfTopic=0x0010017e;
//Զ���豸��Ϣ
const DWORD FTD_TID_RspQryOuterDeviceInfTopic=0x0010017f;
//Զ���豸��Ϣ
const DWORD FTD_TID_RtnNetOuterDeviceInfTopic=0x00100180;
//����ping���
const DWORD FTD_TID_ReqQryNetLocalPingResultInfoTopic=0x00100181;
//����ping���
const DWORD FTD_TID_RspQryNetLocalPingResultInfoTopic=0x00100182;
//����ping���
const DWORD FTD_TID_RtnNetLocalPingResultInfoTopic=0x00100183;
//Զ��ping���
const DWORD FTD_TID_ReqQryNetRomotePingResultInfoTopic=0x00100184;
//Զ��ping���
const DWORD FTD_TID_RspQryNetRomotePingResultInfoTopic=0x00100185;
//Զ��ping���
const DWORD FTD_TID_RtnNetRomotePingResultInfoTopic=0x00100186;
//������Ϣ���ݿ�ר��
const DWORD FTD_TID_RtnMonitorTopProcessInfo=0x00100187;
//ϵͳ�ڲ�������ϵ
const DWORD FTD_TID_ReqQrySysInternalTopologyTopic=0x00100188;
//ϵͳ�ڲ�������ϵ
const DWORD FTD_TID_RspQrySysInternalTopologyTopic=0x00100189;
//ϵͳ�ڲ�������ϵ
const DWORD FTD_TID_RtnSysInternalTopologyTopic=0x00100190;
//�����Ա��·���ñ�
const DWORD FTD_TID_ReqQryMemberLinkCostTopic=0x00100191;
//���ػ�Ա��·���ñ�
const DWORD FTD_TID_RspQryMemberLinkCostTopic=0x00100192;
//���Ļ�Ա��·���ñ�
const DWORD FTD_TID_RtnMemberLinkCostTopic=0x00100193;
//�����Ա��·�����
const DWORD FTD_TID_ReqQryNetPartylinkMonthlyRentTopic=0x00100194;
//���ػ�Ա��·�����
const DWORD FTD_TID_RspQryNetPartylinkMonthlyRentTopic=0x00100195;
//���Ļ�Ա��·�����
const DWORD FTD_TID_RtnNetPartylinkMonthlyRentTopic=0x00100196;
//����ǻ�Ա��·����Ϣ
const DWORD FTD_TID_ReqQryNetNonPartyLinkInfoTopic=0x00100197;
//���طǻ�Ա��·����Ϣ
const DWORD FTD_TID_RspQryNetNonPartyLinkInfoTopic=0x00100198;
//���ķǻ�Ա��·����Ϣ
const DWORD FTD_TID_RtnNetNonPartyLinkInfoTopic=0x00100199;

#ifndef FIELD_USE_DEFINE
#define FIELD_USE_DEFINE

#define UNLIMITED_FIELD_OCCUR 1000

typedef struct
{
	DWORD fid;
	CFieldDescribe *pFieldDescribe;
	int minOccur;
	int maxOccur;
}	TFieldUse;

typedef struct
{
	DWORD tid;
	int fieldUseCount;
	TFieldUse *fieldUse;
}	TPackageDefine;

#endif

extern TPackageDefine FTDPackageDefines[];

void FTDC_DEBUG_BODY(DWORD tid, CFieldSet *pPackage, CLogger *pLogger);

#endif
