--[[
生成初始化内存数据库的内部头文件
--]]
require("LuaXml")

-- lua $(path)\MemoryDBInitFunc_internal.h.lua $(path)\MemoryDBInitFunc.xml $(path)\MemoryDBInitFunc_internal.h
local xmlEnvFile = arg[1]

local targetFile = arg[2]

print(xmlEnvFile, targetFile)


function parseEntityName(document, map)
	for _, node in pairs(document) do
		if node[0] == "Entity" then
			map[node.name] = node.name
		end
	end
end

-- a table for storing entity which will be init in memory db.   For example {SysNetInterface = SysNetInterface}
local memdbEntity = {}

-- custom type config path, it's usually under datamodel/commonEnv/UFDataType.xml
local customTypeConfigPath = ""

-- UFEntity Config Path, it's usually under datamodel/commonEnv/UFEntity.xml
local UFEntityConfigPath = ""

local UFMdbEntityPath = ""

local document = xml.load(xmlEnvFile)

-- parse <Entity> under <MemoryDBInitFunc>
parseEntityName(document, memdbEntity)

for _, node in pairs(document) do
	if node[0] == "CustomType" then
		customTypeConfigPath = node.path
	elseif node[0] == "UFEntity" then
		UFEntityConfigPath = node.path
	elseif node[0] == "MemDBType" then
		UFMdbEntityPath = node.path
	elseif node[0] == "GeneralOperation" then
		-- parse <Entity> under <GeneralOperation>
		parseEntityName(node, memdbEntity)
	end
end

-- a table for storing all custom data types. For example {TypeObjectID = String}
local dataTypeMap = {}

document = xml.load(customTypeConfigPath)

-- parse custom data type
for _, customType in pairs(document) do
	if type(customType) == "table" then
		for attr, value in pairs(customType) do
			if attr == "typename" then
				dataTypeMap[value] = customType[0]   -- customType[0] is the name of element
			end
		end
	end
end

-- a table for storing all entity. For example {SysNetInterface = {MAC = TypeObjectID} }
local UFEntity = {}

document = xml.load(UFMdbEntityPath)

local entii = {};
-- parse UFEntity
for _, node in pairs(document) do
	if node[0] == "tables" then
		for _, tables in pairs(node) do
			if tables[0] == "table" then
				print(tables.name)

				for _, fields in pairs(tables) do
					if fields[0] == "fields" then
						for _, fld in pairs(fields) do
							if (fld.name) then
								entii[fld.name] = string.sub(fld.type, 2, -5)
								if tables.name == "SysNetMonitorDeviceTask" then
									print(string.format("%s : %s" ,fld.name, entii[fld.name]))
								end

							end
						end
					end
				end
				UFEntity[tables.name] = entii
				entii = {}
			end
		end
	end

end


-- generate SAValueRead expression according custom type
function generateType(output, memObj, attribute, attributeType, partyLinkInfo_spec)
	local type = dataTypeMap[attributeType];

	if partyLinkInfo_spec and attribute == "Interface" then
		output:write("\n\tSAString str = records.Field(\"".. attribute .. "\").asString();")
		output:write("\n\tstr.TrimRight();")
		output:write("\n\tstr.TrimLeft();")
		output:write("\n\tstr.Replace(\".\", \"_\");")
		output:write("\n\t"..memObj.."." .. attribute .." = (const char*)str;\n")
		return
	end

	output:write("\n\t"..memObj.."." .. attribute .. " = records.Field(\"" .. attribute .. "\").")

	if type == "Int" or type == "RangeInt" then
		output:write("asLong();\n")
	elseif type == "String" or type == "VString" or type == "Array" then
		output:write("asString();\n")
		output:write("\t" .. memObj .. "." .. attribute .. ".trim();\n")
	elseif type == "Char" or type == "EnumChar" or type == "Word" then
		output:write("asShort();\n")
	elseif type == "Float" or type == "FixNumber" then
		output:write("asDouble();\n")
	end
end

function generateSignature(output, name)
	output:write("\nvoid FUNC_NAME(" .. name .. ")(SACommand & records, void * data)")
end

-- output is the opend file for writting
-- entityName is name of entity, check attribute of entity from memdbEntity
-- entityTable is a table which contains pairs of attribute and type
function generateMemDBInitFunc(output, entityName, entityTable)
	-- generate function signature
	generateSignature(output, entityName)
	output:write("\n")

	-- generate function body
	output:write("{\n")

	local partyLinkInfo_spec = false
	if entityName == "SysNetPartyLinkInfo" then
		partyLinkInfo_spec = true
	end

	output:write("\tCWriteable" .. entityName .. " mdbfield;\n")
	for attrName, attrType in pairs(entityTable) do
		generateType(output, "mdbfield", attrName, attrType, partyLinkInfo_spec);

	end

	output:write("\n\tpMemoryDB->m_" .. entityName .. "Factory->add(&mdbfield, NULL);\n")

	output:write("}\n")
end


header = [[
/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file MemoryDBInitFunc_internal.h
///@brief 定义了初始化内存数据库的函数，由脚本生产而成，勿直接修改本文件
///@history
///20110620	李志伟		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef __MEMORY_DB_INIT_FUNC_INTERNAL_H
#define __MEMORY_DB_INIT_FUNC_INTERNAL_H

#include <SQLAPI.h>
#include <CMemoryDB.h>

#define FUNC_NAME(tag) InitMem##tag

]]

tail = [[

#endif // __MEMORY_DB_INIT_FUNC_INTERNAL_H
]]


memDBInitSet = [[


// 定义初始化内存数据库的回调结构
typedef struct {
    const char * table;
    DBOperator::searchHander_t initCB;
    DBOperator::searchHander_t setIDCB;
} memoryInitData_t;


extern map<string, int> g_idMaker;

extern CMemoryDB *pMemoryDB;

// 初始化内存数据库中表的起始索引值
void InitIDMaker(SACommand & records, void * data)
{
    assert(data);

    //TODO modify table
    static int prefix = 2; // strlen("t_");

    int id = records.Field(1).asLong() +1;
    const char * table = (const char *)data + prefix;
    g_idMaker[table] = id;
}

#define MEM_DB_INIT_ITEM(tag) {"t_"#tag, FUNC_NAME(tag), InitIDMaker}

]]

function generateMemDBInitSet(output)
	output:write(memDBInitSet)

	output:write("static memoryInitData_t memInitData[] = {\n")

	for name in pairs(memdbEntity) do
		output:write("\tMEM_DB_INIT_ITEM(" .. name .. "),\n")
	end

	output:write("};\n")
end


-- generate output file
local output = io.open(targetFile, "w");

output:write(header)

--generate init function declaration
for name, _ in pairs(memdbEntity) do
	generateSignature(output, name)
	output:write(";\n")
end

generateMemDBInitSet(output)


-- generate init function body
for name, content in pairs(UFEntity) do
	if memdbEntity[name] then
		generateMemDBInitFunc(output, name, content)
	end
end


output:write(tail)

output:close()







