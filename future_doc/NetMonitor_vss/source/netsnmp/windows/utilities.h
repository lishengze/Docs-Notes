#ifndef NET_SNMP_UTILITIES_H
#define NET_SNMP_UTILITIES_H

    /**
     *  Library API routines not specifically concerned with SNMP directly,
     *    but used more generally within the library, agent and other applications.
     *
     *  This also includes "standard" system routines, which are missing on
     *    particular O/S distributiones.
     */

#ifndef NET_SNMP_CONFIG_H
#error "Please include <windows/net-snmp-config.h> before this file"
#endif

#include <windows/types.h>

    /*
     *  For the initial release, this will just refer to the
     *  relevant UCD header files.
     *    In due course, the routines relevant to this area of the
     *  API will be identified, and listed here directly.
     *
     *  But for the time being, this header file is a placeholder,
     *  to allow application writers to adopt the new header file names.
     */

#include <windows/library/snmp_api.h>
#include <windows/library/snmp_client.h>
#if HAVE_GETOPT_H
#include <getopt.h>
#else
#include <windows/library/getopt.h>
#endif

#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>         /* for in_addr_t */
#endif
#include <windows/library/system.h>
#include <windows/library/tools.h>
#include <windows/library/asn1.h>      /* for counter64 */
#include <windows/library/int64.h>

#include <windows/library/mt_support.h>
/*  #include <windows/library/snmp_locking.h>  */
#include <windows/library/snmp_alarm.h>
#include <windows/library/callback.h>
#include <windows/library/data_list.h>
#include <windows/library/oid_stash.h>
#include <windows/library/snmp.h>
#include <windows/library/snmp_impl.h>
#include <windows/library/snmp-tc.h>
#include <windows/library/check_varbind.h>
#include <windows/library/container.h>
#include <windows/library/container_binary_array.h>
#include <windows/library/container_list_ssll.h>
#include <windows/library/container_iterator.h>

#include <windows/library/snmp_assert.h>

#include <windows/version.h>

#endif                          /* NET_SNMP_UTILITIES_H */
