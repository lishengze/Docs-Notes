#include <gtest/gtest.h>
#include <string>
#include <FtdData.h>
#include "../FTDDataWrapper.h"
#include "../DBOperator.h"

//using namespace std;


string g_strDbIp;			// 数据库连接IP
string g_strDbPort;			// 数据库连接PORT
string g_strDbName;			// 数据库名
string g_strDbUser;			// 数据库登陆用户
string g_strDbPwd;			// 数据库登陆密码


static const char * table = "t_SysNetCommunity";
CFTDSysNetCommunityField field;
CFtdData obj(&field, &CFTDSysNetCommunityField::m_Describe);

static const char * delim = "::";
static string objStr;

void InitGlobal()
{
    g_strDbIp = "172.16.94.65";
    g_strDbPort = "1521";
    g_strDbName = "monitor";
    g_strDbUser = "netmonitor";
    g_strDbPwd = "netmonitor";

    field.ID = 100;
    field.IPADDR = "192.168.0.1";
    field.COMMUNITY = "COMMUNITY";

    obj.SetStrDelimitation(delim);
    objStr = obj.ToString();
}




class DBOperatorTest:public testing::Test
{
protected:
    virtual void SetUp()
    {
        InitGlobal();
    }

    virtual void TearDown()
    {

    }

    DBOperator m_dbOper;
    SqlGenerator m_sql;
};


TEST_F(DBOperatorTest, SqlGenerator)
{
    //Test fail
    EXPECT_STREQ("", m_sql.InsertCmd(NULL, NULL).c_str());
    EXPECT_STREQ("", m_sql.InsertCmd("abc", NULL).c_str());
    EXPECT_STREQ("", m_sql.InsertCmd(NULL, &obj).c_str());

    EXPECT_STREQ("", m_sql.DeleteCmd(NULL).c_str());

    EXPECT_STREQ("", m_sql.UpdateCmd(NULL, NULL, NULL).c_str());
    EXPECT_STREQ("", m_sql.UpdateCmd(NULL, &obj, "abc").c_str());
    EXPECT_STREQ("", m_sql.UpdateCmd("ABC", NULL, "abc").c_str());
    EXPECT_STREQ("", m_sql.UpdateCmd("ABC", &obj, NULL).c_str());
    EXPECT_STREQ("", m_sql.UpdateCmd("ABC", &obj, "abc").c_str());

    EXPECT_STREQ("", m_sql.SearchAllCmd(NULL).c_str());

    EXPECT_STREQ("", m_sql.SearchMaxCmd(NULL, NULL).c_str());
    EXPECT_STREQ("", m_sql.SearchMaxCmd("abc", NULL).c_str());
    EXPECT_STREQ("", m_sql.SearchMaxCmd(NULL, "abc").c_str());
}


void dummySearchHandler(SACommand & records, void * data)
{
    ASSERT_TRUE(false && "You shouldn't search any result!");
}

void checkValueSearchHandler(SACommand & records, void * data)
{
    obj.FromDBRecord(records);
    EXPECT_STREQ(((string *)data)->c_str(), obj.ToString().c_str());
}

TEST_F(DBOperatorTest, InsertRecord)
{
    // Test pass
    EXPECT_TRUE(m_dbOper.InsertRecord(m_sql.InsertCmd(table, &obj).c_str(), &obj));
    EXPECT_TRUE(m_dbOper.SearchRecord(m_sql.SearchAllCmd(table).c_str(), checkValueSearchHandler, &objStr));

    // Test fail
    EXPECT_FALSE(m_dbOper.InsertRecord(m_sql.InsertCmd(table, &obj).c_str(), NULL));    
    EXPECT_FALSE(m_dbOper.InsertRecord("", NULL));   

    EXPECT_TRUE(m_dbOper.DeleteRecord(m_sql.DeleteCmd(table,  "ID").c_str(), &obj, "ID"));
}

TEST_F(DBOperatorTest, DeleteRecord)
{
    // Test pass
    EXPECT_TRUE(m_dbOper.InsertRecord(m_sql.InsertCmd(table, &obj).c_str(), &obj));
    EXPECT_TRUE(m_dbOper.DeleteRecord(m_sql.DeleteCmd(table,  "ID"), &obj, "ID"));

    EXPECT_TRUE(m_dbOper.InsertRecord(m_sql.InsertCmd(table, &obj).c_str(), &obj));
    EXPECT_TRUE(m_dbOper.DeleteRecord(m_sql.DeleteCmd(table)));

    EXPECT_TRUE(m_dbOper.SearchRecord(m_sql.SearchAllCmd(table).c_str(), dummySearchHandler, NULL));
}

TEST_F(DBOperatorTest, UpdateRecord)
{
    // Test pass
    {
        CFTDSysNetCommunityField field;
        CFtdData obj(&field, &CFTDSysNetCommunityField::m_Describe);

        field.ID = 100;
        field.IPADDR = "192.168.0.1";
        field.COMMUNITY = "COMMUNITY";               

        EXPECT_TRUE(m_dbOper.InsertRecord(m_sql.InsertCmd(table, &obj).c_str(), &obj));

        field.IPADDR = "127.0.0.1";
        field.COMMUNITY = "COMMUNITY of 127.0.0.1";

        obj.SetStrDelimitation(delim);
        string objStr = obj.ToString();

        EXPECT_TRUE(m_dbOper.UpdateRecord(m_sql.UpdateCmd(table, &obj, "ID").c_str(), &obj, "ID"));
        EXPECT_TRUE(m_dbOper.SearchRecord(m_sql.SearchAllCmd(table).c_str(), 
            checkValueSearchHandler, &objStr));

        EXPECT_TRUE(m_dbOper.DeleteRecord(m_sql.DeleteCmd(table,  "ID").c_str(), &obj, "ID"));
    }
    
}
