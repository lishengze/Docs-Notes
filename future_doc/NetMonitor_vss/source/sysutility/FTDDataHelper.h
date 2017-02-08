/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file FTDDataHelper.h
///@brief 提供了封装FTD数据类型的一些宏，以及操作FTD数据的便利方法
///@history 
///20110713	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef __FTD_DATA_HELPER_H
#define __FTD_DATA_HELPER_H

#include "PrjCommon.h"

extern CBufferLogger* g_bufferLogger;

//定义一些与FTD类相关的宏
#define FTD_FIELD(tag) CFTDSys##tag##Field

#define FTD_WRITABLE(tag) CWriteableSys##tag

#define FTD_SysClass(tag) CSys##tag

#define FTD_SysName(tag) "Sys"#tag 

#define FTD_FACTORY(tag) CSys##tag##Factory
#define FTD_FACTORY_OBJ(tag) m_Sys##tag##Factory

#define FTD_TABLE(tag) "t_Sys"#tag

#define FTD_REQ(tag) CFTDReqQry##tag##Field
#define FTD_REQ_ID(tag) FTD_TID_ReqQry##tag##Topic

#define FTD_RSP(tag) CFTDRspQry##tag##Field
#define FTD_RSP_ID(tag) FTD_TID_RspQry##tag##Topic

#define FTD_RTN(tag) CFTDRtn##tag##Field
#define FTD_RTN_ID(tag) FTD_TID_Rtn##tag##Topic

#define COPY_FTD_ENTITY(tag, target, source) CopySys##tag##Entity(target, source)

#define COPY_FTD_REQ_ENTITY(tag, target, source) CopyReqQry##tag##Entity(target, source)

#define COPY_FTD_RSP_ENTITY(tag, target, source) CopyRspQry##tag##Entity(target, source)

#define COPY_FTD_RTN_ENTITY(tag, target, source) CopyRtn##tag##Entity(target, source)


// W2F : FTD_WRITABLE(tag) to FTD_FIELD(tag)，反之则为F2W
#define FTD_OBJ_COPIER_W2F(tag) tag##ObjCopier_W2F
#define FTD_OBJ_COPIER_W2F_T(tag) tag##ObjCopier_W2F_t

#define FTD_OBJ_COPIER_F2W(tag) tag##ObjCopier_F2W
#define FTD_OBJ_COPIER_F2W_T(tag) tag##ObjCopier_F2W_t

// F2RTN : FTD_FIELD(tag) to FTD_RTN(tag)
#define FTD_OBJ_COPIER_F2RTN(tag) tag##ObjCopier_F2RTN
#define FTD_OBJ_COPIER_F2RTN_T(tag) tag##ObjCopier_F2RTN_t

// RSP2RTN : FTD_RSP(tag) to FTD_RTN(tag)
#define FTD_OBJ_COPIER_RSP2RTN(tag) tag##ObjCopier_RSP2RTN
#define FTD_OBJ_COPIER_RSP2RTN_T(tag) tag##ObjCopier_RSP2RTN_t

// 定义了工具函数来封装COPY_FTD_ENTITY宏
#define DEFINE_FTD_OBJ_COPIER(tag) \
    typedef void (* FTD_OBJ_COPIER_W2F_T(tag))(FTD_FIELD(tag) *pTarget,  FTD_WRITABLE(tag) * pSource);\
    static void FTD_OBJ_COPIER_W2F(tag)(FTD_FIELD(tag) *pTarget,  FTD_WRITABLE(tag) * pSource) \
    {\
        COPY_FTD_ENTITY(tag, pTarget, pSource);\
    }\
    \
    typedef void (* FTD_OBJ_COPIER_F2W_T(tag))(FTD_WRITABLE(tag) * pTarget, FTD_FIELD(tag) * pSource);\
    static void FTD_OBJ_COPIER_F2W(tag)(FTD_WRITABLE(tag) * pTarget, FTD_FIELD(tag) * pSource) \
    {\
        COPY_FTD_ENTITY(tag, pTarget, pSource);\
    }\
    \
    typedef void (* FTD_OBJ_COPIER_F2RTN_T(tag))(FTD_RTN(tag) * pTarget, FTD_FIELD(tag) * pSource);\
    static void FTD_OBJ_COPIER_F2RTN(tag)(FTD_RTN(tag) * pTarget, FTD_FIELD(tag) * pSource) \
    {\
        COPY_FTD_ENTITY(tag, pTarget, pSource);\
    }\
    \
    typedef void (* FTD_OBJ_COPIER_RSP2RTN_T(tag))(FTD_RTN(tag) * pTarget, FTD_RSP(tag) * pSource);\
    static void FTD_OBJ_COPIER_RSP2RTN(tag)(FTD_RTN(tag) * pTarget, FTD_RSP(tag) * pSource) \
    {\
        COPY_FTD_ENTITY(tag, pTarget, pSource);\
    }\


// 定义操作数据库的宏
#define WRAP_FTD_OBJ(tag, field) \
    FTD_FIELD(tag) obj;\
    COPY_FTD_ENTITY(tag, &obj, &field);\
    CFtdData wrappedObj(&obj, &FTD_FIELD(tag)::m_Describe);

// 往数据库中插入一条数据
///@param	tag 该数据的类型
///@param	obj 数据对象
///@param	hdb 数据库操作器
///@return 	result 插入结果，成功为true，失败为false
#define INSERT_OBJ_TO_DB(tag, obj, hdb, result) \
    do {\
        WRAP_FTD_OBJ(tag, obj);\
        SqlGenerator sql;\
        result = (hdb).InsertRecord(FTD_TABLE(tag), &wrappedObj);\
    } while(0)

// 删除表中某条记录，删除条件为obj.attr = obj.attr
#define DELETE_OBJ_FROM_DB(tag, obj, attr, hdb, result) \
    do {\
        WRAP_FTD_OBJ(tag, obj);\
        SqlGenerator sql;\
        result = (hdb).DeleteRecord(FTD_TABLE(tag), &wrappedObj, attr);\
    } while(0)

// 将obj的内容做为数据源更新记录，更新条件为obj.attr = obj.attr
#define UPDATE_OBJ_TO_DB(tag, obj, attr, hdb, result) \
    do {\
        WRAP_FTD_OBJ(tag, obj);\
        result = (hdb).UpdateRecord(FTD_TABLE(tag), &wrappedObj, attr);\
    } while(0)

// 将obj1的内容做为数据源更新记录，其中更新条件为obj1.attr1 == obj2.attr2
// 其中obj1为tag1相关对象，obj2为tag2相关对象
#define UPDATE_OBJ_TO_DB_WITH_COMPOBJ(tag1, obj1, attr1, tag2, obj2, attr2, hdb, result) \
    do {\
        FTD_FIELD(tag1) o1;\
        COPY_FTD_ENTITY(tag1, &o1, &obj1);\
        CFtdData wrappedObj1(&o1, &FTD_FIELD(tag1)::m_Describe);\
        FTD_FIELD(tag2) o2;\
        COPY_FTD_ENTITY(tag2, &o2, &obj2);\
        CFtdData wrappedObj2(&o2, &FTD_FIELD(tag2)::m_Describe);\
        DBOperator::ColumnArray recordValues;\
        recordValues.push_back(DBOperator::Column(&wrappedObj1, attr1));\
        DBOperator::ColumnArray cmpValues;\
        cmpValues.push_back(DBOperator::Column(&wrappedObj2, attr2));\
        result = (hdb).UpdateRecord(FTD_TABLE(tag1), recordValues, cmpValues);\
    } while(0)


// 定义迭代内存数据库的宏
#define ITERATE_MEMORYDB_BYALL_BEGIN(tag) \
    do {\
        FTD_SysClass(tag) * pField = pMemoryDB->FTD_FACTORY_OBJ(tag)->startFindByAll();\
        while (pField) {\
            FTD_SysClass(tag) * nextField = pMemoryDB->FTD_FACTORY_OBJ(tag)->findNextByAll();\
            
#define ITERATE_MEMORYDB_BYALL_END(tag) \
            pField = nextField;\
        }\
        pMemoryDB->FTD_FACTORY_OBJ(tag)->endFindByAll();\
    } while (0);


#define ITERATE_MEMORYDB_BYKEY_BEGIN(tag, key, v, k) \
    do {\
        FTD_SysClass(tag) * pField = pMemoryDB->FTD_FACTORY_OBJ(tag)->startFindBy##key((v).k);\
        while (pField) {\
            FTD_SysClass(tag) * nextField = pMemoryDB->FTD_FACTORY_OBJ(tag)->findNextBy##key();

#define ITERATE_MEMORYDB_BYKEY_END(tag, key) \
            pField = nextField;\
        }\
        pMemoryDB->FTD_FACTORY_OBJ(tag)->endFindBy##key();\
    } while(0);


// 定义增、删、改内存数据库的宏
#define INSERT_RECORD_INTO_MEMORYDB(tag, record) \
    do {\
        static FTD_WRITABLE(tag) r;\
        COPY_FTD_ENTITY(tag, &r, &(record));\
        pMemoryDB->FTD_FACTORY_OBJ(tag)->add(&r);\
    } while(0)


#define FIND_RECORD_BYKEY_FROM_MEMORYDB(tag, record, key, hasRecord, result) \
        FTD_SysClass(tag) * result = pMemoryDB->FTD_FACTORY_OBJ(tag)->findByOne((record).key);\
        if (result) {\
            hasRecord = true;\
        }\
        else {\
            hasRecord = false;\
        }

#define DELETE_RECORD_BYKEY_FROM_MEMORYDB(tag, record) \
    do {\
        pMemoryDB->FTD_FACTORY_OBJ(tag)->remove(record);\
    } while(0)

#define UPDATAE_RECORD_FROM_MEMORYDB(tag, oldR, newR) \
    do {\
        static FTD_WRITABLE(tag) r;\
        COPY_FTD_ENTITY(tag, &r, &(newR));\
        pMemoryDB->FTD_FACTORY_OBJ(tag)->update(oldR, &r);\
    } while(0)

// 定义迭代package中field的宏
#define FOREACH_FIELD(pkg, fieldType, field) \
    for ( CNamedFieldIterator itor= (pkg)->GetNamedFieldIterator(&(fieldType::m_Describe)); \
        !itor.IsEnd() && itor.Retrieve(&(field)) ; \
        itor.Next() )


#define NEW_PKG_WITH_FIELD(pkg, req, tid, chain, field) \
    do {\
        (pkg)->PrepareResponse(req, tid, chain, FTD_VERSION);\
        FTDC_ADD_FIELD(pkg, &(field));\
    } while (0)

#define BUILD_LAST_PKG_BY_FIELD(type, tag, req, rsp, src) \
    BUILD_PKG_BY_FIELD_INTERNAL(type, tag, req, rsp, src, FTDC_CHAIN_LAST)

#define BUILD_CONTINUE_PKG_BY_FIELD(type, tag, req, rsp, src) \
    BUILD_PKG_BY_FIELD_INTERNAL(type, tag, req, rsp, src, FTDC_CHAIN_CONTINUE)

#define BUILD_PKG_BY_FIELD_INTERNAL(type, tag, req, rsp, src, chain) \
    do {\
        static FTD_##type(tag) type##Field;\
        COPY_FTD_##type##_ENTITY(tag, &type##Field ,&(src));\
        NEW_PKG_WITH_FIELD(rsp, req, FTD_##type##_ID(tag), chain, type##Field);\
    } while (0)


// 操作码数值，和GOT_* 系列对应。
enum OperType
{
    OT_QUERY = 1,
    OT_ADD = 2,
    OT_DELETE = 3,
    OT_UPDATE = 4
};

#define SEND_RSP(tag, session, req, rsp, rspField) \
    do {\
        NEW_PKG_WITH_FIELD(rsp, req, FTD_RSP_ID(tag), FTDC_CHAIN_CONTINUE, rspField);\
        (session)->SendRequestPackage(rsp);\
        (rsp)->Pop(FTDCHLEN);\
    } while (0)

#define SEND_RSP_BY_MEMORYDB_RECORD(tag, session, req, rsp, record, operType) \
    do {\
        static FTD_RSP(tag) rspField;\
        COPY_FTD_ENTITY(tag, &rspField, record);\
        rspField.OperationType = operType;\
        SEND_RSP(tag, session, req, rsp, rspField);\
    } while (0)

// 和客户端的约定，对查询请求的响应，返回的OperationType为OT_ADD，故有此宏
#define SEND_QRYRSP_BY_MEMORYDB_RECORD(tag, session, req, rsp, record, operType) \
    SEND_RSP_BY_MEMORYDB_RECORD(tag, session, req, rsp, record, OT_ADD)


/**在package中加入field，如果package已满，则发送此package，再加入field
* @param rsp 要发送的package
* @param field 要加入的field
* @param session 发送package的会话
* @param req rsp包对应的请求，在发送rsp package时需指定
* @param pkgID 当前package的ID
*/
template<typename FIELDT>
void AddRspWithField(CFTDCPackage* rsp, FIELDT* field, 
                     CFTDCSession* session, CFTDCPackage* req, int pkgID)
{
    assert(session && req && rsp && field);

    if (FTDC_ADD_FIELD(rsp, field) == -1) {
        session->SendRequestPackage(rsp);
        rsp->PrepareResponse(req, pkgID,FTDC_CHAIN_CONTINUE, FTD_VERSION);
        assert(FTDC_ADD_FIELD(rsp, field) != -1);
    }
}

#endif // __FTD_DATA_HELPER_H
