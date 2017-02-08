/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CGetDeviceCdp.h
///@brief	������CGetDeviceCdpʹ�õ���
///@history
///20100920	�ܽ���		�������ļ�
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
