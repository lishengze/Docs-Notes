--[[
生成处理同步配置服务的代码
--]]
require("LuaXml")

-- lua $(path)\GeneralOperationTables_internal.h.lua $(path)\MemoryDBInitFunc.xml $(path)\GeneralOperationTables_internal.h
local xmlEnvFile = arg[1] -- "MemoryDBInitFunc.xml"

local targetFile = arg[2] -- "CSyncServer_internal.h"

--local xmlEnvFile = "MemoryDBInitFunc.xml"
--local targetFile = "CSyncServer_internal.h"


-- a table for storing table name
local tables = {}

local tablesapps = {}
local tbrtns = {}
local tbrsps = {}

function parseEntityName(document, map)
	for _, node in pairs(document) do
		if node[0] == "Entity" then
			if node.rtnfield and node.rspfield then
				tablesapps[node.name] = node.name
				tbrtns[node.name] = node.rtnfield
				tbrsps[node.name] = node.rspfield
			end

			map[node.name] = node.name

		end
	end
end


local document = xml.load(xmlEnvFile)

-- parse <Entity> under <MemoryDBInitFunc>
parseEntityName(document, tables)

for _, node in pairs(document) do
	if node[0] == "GeneralOperation" then
		-- parse <Entity> under <GeneralOperation>
		parseEntityName(node, tables)
		break;
	end
end


header = [[
/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file CSyncServer_internal.h
///@brief 定义了处理同步配置服务的代码，由脚本生产而成，勿直接修改本文件
///@history
///20110928	李志伟		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef __CSYNC_SERVER_INTERNAL_H
#define __CSYNC_SERVER_INTERNAL_H

#include <FTDDataHelper.h>
#include <PrjCommon.h>

#ifdef PACKAGE_OUTPUT
extern CFileLogger* g_recvPkgLogger;		// 数据包输出到文件
extern CBufferLogger* g_bufferLogger;
#endif


#define HANDLE_RTN_TOPIC(tag) \
    do {\
        if (isMaster()) {\
            LOG_ERROR("Only slavery will get notify info, Check you master and slavery!");\
        }\
        FTD_RTN(tag) field;\
        FOREACH_FIELD(pFTDCPackage, FTD_RTN(tag), field)\
        {\
            bool result = true;\
            switch (field.OperationType)\
            {\
                case 2:\
                {\
                    INSERT_OBJ_TO_DB(tag, field, m_dbHandler, result);\
                    break;\
                }\
                case 3:\
                {\
                    DELETE_OBJ_FROM_DB(tag, field, "ID", m_dbHandler, result);\
                    break;\
                }\
                case 4:\
                {\
                    UPDATE_OBJ_TO_DB(tag, field, "ID", m_dbHandler, result);\
                    break;\
                }\
                default:\
               {\
                    LOG_WARNING("Invalid operation type");\
                    break;\
               }\
            }\
        }\
    } while(0)


#define HANDLE_RTN_TOPIC2(tag, tag2) \
    do {\
        if (isMaster()) {\
            LOG_ERROR("Only slavery will get notify info, Check you master and slavery!");\
        }\
        FTD_RTN(tag) field;\
        FOREACH_FIELD(pFTDCPackage, FTD_RTN(tag), field)\
        {\
            bool result = true;\
            switch (field.OperationType)\
            {\
                case 2:\
                {\
                    INSERT_OBJ_TO_DB(tag2, field, m_dbHandler, result);\
                    break;\
                }\
                case 3:\
                {\
                    DELETE_OBJ_FROM_DB(tag2, field, "ID", m_dbHandler, result);\
                    break;\
                }\
                case 4:\
                {\
                    UPDATE_OBJ_TO_DB(tag2, field, "ID", m_dbHandler, result);\
                    break;\
                }\
                default:\
               {\
                    LOG_WARNING("Invalid operation type");\
                    break;\
               }\
            }\
        }\
    } while(0)

]]

tail = [[

#endif // __CSYNC_SERVER_INTERNAL_H
]]


function signatureName(name)
	return "OnRtn" .. name .. "Topic"
end

function generateSignature(output, name)
	output:write("\nvoid CSyncServer::" .. signatureName(name) .. "(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)")
end


HandlePackage_Begin = [[

int CSyncServer::HandlePackage(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
    LogPkg(pFTDCPackage, g_bufferLogger, g_recvPkgLogger);
#endif

	switch(pFTDCPackage->GetTID())
	{
]]

HandlePackage_End = [[
	}

	m_flowSync->addToFlow(pFTDCPackage);

    return 0;
}
]]


function generateFuncBody(output, name)
	generateSignature(output, name)
	output:write("\n{\n")
	output:write("\tHANDLE_RTN_TOPIC(" .. name .. ");")
	output:write("\n}\n")
end

function generateFuncBody2(output, name, name2)
	generateSignature(output, name)
	output:write("\n{\n")
	output:write("\tHANDLE_RTN_TOPIC2(" .. name .. "," ..name2.. ");")
	output:write("\n}\n")
end

function generateFlowSyncHander(output)
	output:write("\t\tcase FTD_TID_ReqSubscribeTopic:\n")
	output:write("\t\t\tm_flowSync->OnReqFlowSyncTopic(pFTDCPackage, pSession);\n")
	output:write("\t\t\tbreak;\n")
end

function generateHandlePackage(output)
	output:write(HandlePackage_Begin);

	for k, _ in pairs(tables) do
		local name = string.sub(k, 4)

		if tbrtns[k] then
			output:write("\t\tcase FTD_TID_Rtn" .. tbrtns[k] .. "Topic:\n")
			output:write("\t\t\t" .. signatureName(tbrtns[k]) .. "(pFTDCPackage, pSession);\n")
		else
			output:write("\t\tcase FTD_TID_Rtn" .. name .. "Topic:\n")
			output:write("\t\t\t" .. signatureName(name) .. "(pFTDCPackage, pSession);\n")
		end

		output:write("\t\t\tbreak;\n")
	end

	generateFlowSyncHander(output)

	output:write("\t\tdefault:\n")
	output:write("\t\t\tbreak;\n")

	output:write(HandlePackage_End);
end

-- generate output file
local output = io.open(targetFile, "w");

output:write(header)

-- generate comoment method declaration
output:write("\n/* \t Please copy me to declaration of CSyncServer")
for k, _ in pairs(tables) do
	if tbrtns[k] then
		output:write("\nvoid " .. signatureName(tbrtns[k]) .. "(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)")

	else
		output:write("\nvoid " .. signatureName(string.sub(k, 4)) .. "(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)")
	end

	output:write(";\n")
end
output:write("*/\n")

-- generate function definition
for k, _ in pairs(tables) do
	if tbrtns[k] then
		generateFuncBody2(output, tbrtns[k], string.sub(k, 4))
	else
		generateFuncBody(output, string.sub(k, 4))
	end
end

-- generate HandlePackage function
generateHandlePackage(output)

output:write(tail)

output:close()
