// SCPPackageDesc.cpp: implementation of the CSCPPackageDesc class.
//
// 20110119 江鹏   NT-0121：front不用重启换号
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "SCPPackageDesc.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

REGISTER_FIELD(0x0001,CSCPLoginReqField, "CSCPLoginReqField");
REGISTER_FIELD(0x0003,CSCPLinkStateField, "CSCPLinkStateField");
REGISTER_FIELD(0x0004,CSCPLsaHeadField, "CSCPLsaHeadField");
REGISTER_FIELD(0x0006,CSCPSubscribeField, "CSCPSubscribeField");
REGISTER_FIELD(0x0008,CSCPPublishField, "CSCPPublishField");
REGISTER_FIELD(0x000A,CSCPPublishReqField, "CSCPPublishReqField");
REGISTER_FIELD(0x000B,CSCPPublishRspField, "CSCPPublishRspField");

