--[[
生成处理通用操作表的代码
--]]
require("LuaXml")

-- lua $(path)\GeneralOperationTables_internal.h.lua $(path)\MemoryDBInitFunc.xml $(path)\GeneralOperationTables_internal.h
local xmlEnvFile = arg[1] -- "MemoryDBInitFunc.xml"

local targetFile = arg[2] -- "GeneralOperationTables_internal.h"

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
			else
				map[node.name] = node.name
			end
		end
	end
end

local document = xml.load(xmlEnvFile)
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
///@file GeneralOperationTables_internal.h
///@brief 定义了生产通用操作的代码，由脚本生产而成，勿直接修改本文件
///@history
///20110701	李志伟		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef __GENERAL_OPERATION_TABLES_INTERNAL_H
#define __GENERAL_OPERATION_TABLES_INTERNAL_H


#include "FTDDataHelper.h"


]]

tail = [[

#endif // __GENERAL_OPERATION_TABLES_INTERNAL_H
]]


-- generate output file
local output = io.open(targetFile, "w");

output:write(header)

-- generate FTD obj copier
output:write("// define ftd obj copier\n")
for k, _ in pairs(tables) do
	output:write("DEFINE_FTD_OBJ_COPIER(" .. string.sub(k, 4) .. ")\n") -- string.sub(k, 4) to filte prefix sys
	--output:write(..tbrtns[k]..)
end

for k, _ in pairs(tablesapps) do
		output:write("typedef void (* FTD_OBJ_COPIER_W2F_T(")
		output:write(string.sub(k, 4))
		output:write("))(FTD_FIELD(")
		output:write(string.sub(k, 4))
		output:write(")*pTarget,  FTD_WRITABLE(")
		output:write(string.sub(k, 4))
		output:write(") * pSource); \\\n")
		output:write("static void FTD_OBJ_COPIER_W2F(")
		output:write(string.sub(k, 4))
		output:write(")(FTD_FIELD(")
		output:write(string.sub(k, 4))
		output:write(")*pTarget,  FTD_WRITABLE(")
		output:write(string.sub(k, 4))
		output:write(") * pSource) \n")
		output:write("{ COPY_FTD_ENTITY(" ..string.sub(k, 4).. ", pTarget, pSource); }\n\n")

		output:write("typedef void (* FTD_OBJ_COPIER_F2W_T(")
		output:write(string.sub(k, 4))
		output:write("))(FTD_WRITABLE(")
		output:write(string.sub(k, 4))
		output:write(")*pTarget,  FTD_FIELD(")
		output:write(string.sub(k, 4))
		output:write(") * pSource); \\\n")
		output:write("static void FTD_OBJ_COPIER_F2W(")
		output:write(string.sub(k, 4))
		output:write(")(FTD_WRITABLE(")
		output:write(string.sub(k, 4))
		output:write(")*pTarget,  FTD_FIELD(")
		output:write(string.sub(k, 4))
		output:write(") * pSource) \n")
		output:write("{ COPY_FTD_ENTITY(" ..string.sub(k, 4).. ", pTarget, pSource); }\n\n")

		output:write("typedef void (* FTD_OBJ_COPIER_F2RTN_T(")
		output:write(string.sub(k, 4))
		output:write("))(FTD_RTN(")
		output:write(tbrtns[k])
		output:write(")*pTarget,  FTD_FIELD(")
		output:write(string.sub(k, 4))
		output:write(") * pSource); \\\n")
		output:write("static void FTD_OBJ_COPIER_F2RTN(")
		output:write(string.sub(k, 4))
		output:write(")(FTD_RTN(")
		output:write(tbrtns[k])
		output:write(")*pTarget,  FTD_FIELD(")
		output:write(string.sub(k, 4))
		output:write(") * pSource) \n")
		output:write("{ COPY_FTD_ENTITY(" ..string.sub(k, 4).. ", pTarget, pSource); }\n\n")

		output:write("typedef void (* FTD_OBJ_COPIER_RSP2RTN_T(")
		output:write(string.sub(k, 4))
		output:write("))(FTD_RTN(")
		output:write(tbrtns[k])
		output:write(")*pTarget,  FTD_RSP(")
		output:write(tbrsps[k])
		output:write(") * pSource); \\\n")
		output:write("static void FTD_OBJ_COPIER_RSP2RTN(")
		output:write(string.sub(k, 4))
		output:write(")(FTD_RTN(")
		output:write(tbrtns[k])
		output:write(")*pTarget,  FTD_RSP(")
		output:write(tbrsps[k])
		output:write(") * pSource) \n")
		output:write("{ COPY_FTD_ENTITY(" ..string.sub(k, 4).. ", pTarget, pSource); }\n\n\n")

end


-- generate operation handler

output:write("\n\n#define DO_OPERATION(table, reqField, handle, operData, defaultHandler)\\\n")
output:write("do {\\\n")

for k, _ in pairs(tables) do
	output:write("\tif(table == \"" .. k .. "\") {\\\n")
	output:write("\t\thandle(" .. string.sub(k, 4) .. ", reqField, operData, " ..string.sub(k, 4)..");\\\n")
	output:write("\t\tbreak;\\\n")
	output:write("\t}\\\n")
end

for k, _ in pairs(tablesapps) do
	output:write("\tif(table == \"" .. k .. "\") {\\\n")
	output:write("\t\thandle(" .. string.sub(k, 4) .. ", reqField, operData, " ..tbrtns[k]..");\\\n")
	output:write("\t\tbreak;\\\n")
	output:write("\t}\\\n")
end


output:write("\tdefaultHandler(operData);\\\n")

output:write("} while(0)\n")

output:write(tail)

output:close()
