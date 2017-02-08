#ifndef SFIT_NET_SNMP_H
#define SFIT_NET_SNMP_H

#ifdef WINDOWS
#define WIN32
#endif

#ifdef WIN32
#define NETSNMP_TOOLS_C
#endif

#ifdef WINDOWS
#include <windows/net-snmp-config.h>
#include <windows/net-snmp-includes.h>
#else
#include <unix/net-snmp-config.h>
#include <unix/net-snmp-includes.h>
#endif


#endif
