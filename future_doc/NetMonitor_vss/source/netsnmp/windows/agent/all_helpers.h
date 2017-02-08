#ifndef ALL_HANDLERS_H
#define ALL_HANDLERS_H

#ifdef __cplusplus
extern          "C" {
#endif

#include <windows/agent/instance.h>
#include <windows/agent/baby_steps.h>
#include <windows/agent/scalar.h>
#include <windows/agent/scalar_group.h>
#include <windows/agent/watcher.h>
#include <windows/agent/multiplexer.h>
#include <windows/agent/null.h>
#include <windows/agent/debug_handler.h>
#include <windows/agent/cache_handler.h>
#include <windows/agent/old_api.h>
#include <windows/agent/read_only.h>
#include <windows/agent/row_merge.h>
#include <windows/agent/serialize.h>
#include <windows/agent/bulk_to_next.h>
#include <windows/agent/mode_end_call.h>
/*
 * #include <windows/agent/set_helper.h> 
 */
#include <windows/agent/table.h>
#include <windows/agent/table_data.h>
#include <windows/agent/table_dataset.h>
#include <windows/agent/table_tdata.h>
#include <windows/agent/table_iterator.h>
#include <windows/agent/table_container.h>
#include <windows/agent/table_array.h> 

#include <windows/agent/mfd.h>


void            netsnmp_init_helpers(void);

#ifdef __cplusplus
}
#endif
#endif                          /* ALL_HANDLERS_H */
