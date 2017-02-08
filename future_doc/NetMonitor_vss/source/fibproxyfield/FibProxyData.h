// FibProxyData.h: 
//
// 20110413 ����   NT-0129-�����������л�ʱ��ˮ�쳣���������
//////////////////////////////////////////////////////////////////////

#if !defined(_FIBPROXYDATA_H)
#define _FIBPROXYDATA_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FieldDescribe.h"

#define FPP_FTD_VERSION 200

//����Ӧ��
const DWORD FPP_TID_RspError=0x00000001;
//�û���¼����
const DWORD FPP_TID_ReqUserLogin=0x00001001;
//�û���¼Ӧ��
const DWORD FPP_TID_RspUserLogin=0x00001002;

const DWORD FPP_TID_ReqSubscribe = 0x00001003;

const DWORD FPP_TID_RspSubscribe = 0x00001004;

const DWORD FPP_TID_ReqQryFlow = 0x00001005;

const DWORD FPP_TID_RspQryFlow = 0x00001006;

// �û��ǳ�����
const DWORD FPP_TID_ReqUserLogout=0x00001007;

// �û��ǳ�Ӧ��
const DWORD FPP_TID_RspUserLogout=0x00001008;

const DWORD FPP_TID_TRANSFER = 0x0000A001;


DefineUFType(UFIntType,FPPErrorIDType)
DefineUFType(UFWordType,FPPSequenceSeriesType)
DefineUFType(UFIntType,FPPSequenceNoType)
DefineStringType(80,FPPErrorMsgType)
DefineStringType(15,FPPUserIDType)
DefineStringType(40,FPPPasswordType)
DefineStringType(8,FPPDateType)
DefineStringType(8,FPPTimeType)
DefineStringType(40,FPPProductInfoType)

///��Ϣ�ַ�
class CFPPDisseminationField
{
public:
	///����ϵ�к�
	CFPPSequenceSeriesType	SequenceSeries;
	///���к�
	CFPPSequenceNoType	SequenceNo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SequenceSeries)
		,
		TYPE_DESC(SequenceNo)
	));
};
const DWORD FPP_Dissemination=0x0001;

///��Ӧ��Ϣ
class CFPPRspInfoField
{
public:
	///�������
	CFPPErrorIDType	ErrorID;
	///������Ϣ
	CFPPErrorMsgType	ErrorMsg;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ErrorID)
		,
		TYPE_DESC(ErrorMsg)
	));
};
const DWORD FPP_FID_RspInfo=0x0003;

///�û���¼����
class CFPPReqUserLoginField
{
public:
	///������
	CFPPDateType	TradingDay;
	///�����û�����
	CFPPUserIDType	UserID;
	///����
	CFPPPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	CFPPProductInfoType	UserProductInfo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(Password)
		,
		TYPE_DESC(UserProductInfo)
	));
};
const DWORD FPP_FID_ReqUserLogin=0x000A;

///�û���¼Ӧ��
class CFPPRspUserLoginField
{
public:
	///������
	CFPPDateType	TradingDay;
	///��¼�ɹ�ʱ��
	CFPPTimeType	LoginTime;
	///�����û�����
	CFPPUserIDType	UserID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(LoginTime)
		,
		TYPE_DESC(UserID)
	));
};
const DWORD FPP_FID_RspUserLogin=0x000B;

///�û��ǳ�����
class CFPPReqUserLogoutField
{
public:
	///�����û�����
	CFPPUserIDType	UserID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
	));
};
const DWORD FPP_FID_ReqUserLogout=0x000C;

///�û��ǳ�Ӧ��
class CFPPRspUserLogoutField
{
public:
	///�����û�����
	CFPPUserIDType	UserID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
	));
};
const DWORD FPP_FID_RspUserLogout=0x000D;

#endif