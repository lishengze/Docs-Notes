/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CGetDeviceCdp.h
///@brief	定义了CGetDeviceCdp使用的类
///@history
///20100920	周建军		创建该文件
#ifndef REF_CGETDEVICECDP_H
#define REF_CGETDEVICECDP_H

#include "platform.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "net_snmp.h"

#include <string>
#include <list>
#include <map>
#include <iostream>
using namespace std;

#define SNMPSYSNAMEOID	"1.3.6.1.2.1.1.5.0"

int cdpwalk(
		char *pHostIp,
		char *pCommKey,
		char *pRootOid,
		map<string, string> &cdrMap);
#endif
