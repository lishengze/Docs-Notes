#include <gtest/gtest.h>
#include "../FTDDataWrapper.h"
#include <FtdData.h>

#define DIVIDESTR		"*:*"

class CFtdDataTest:public testing::Test
{
protected:
    virtual void SetUp()
    {
        m_regularObj.WordType = 65535 ;
        m_regularObj.IntType = 2147483647 ;
        m_regularObj.FloatType = 100.100000;
        m_regularObj.StringType = "12345678";
        m_regularObj.EnumType = ET_Foo;

        m_regularObjStr = "65535" DIVIDESTR "2147483647" DIVIDESTR "100.100000" 
            DIVIDESTR "12345678" DIVIDESTR "0";

        m_upperBoundObj.WordType = 65536;
        m_upperBoundObj.IntType = 2147483648;
        m_upperBoundObj.FloatType = 1000.101000; // todo
        m_upperBoundObj.StringType = "0123456789";
        m_upperBoundObj.EnumType = ET_Foo;

        m_upperBoundObjStr = "0" DIVIDESTR "-2147483648" DIVIDESTR "1000.101000" 
            DIVIDESTR "01234567" DIVIDESTR "0";
    }
    virtual void TearDown()
    {
        
    }

    CFTDTestDummyDataField m_regularObj;
    const char * m_regularObjStr;

    CFTDTestDummyDataField m_upperBoundObj;
    const char * m_upperBoundObjStr;

    CFtdData m_obj;
};


TEST_F(CFtdDataTest, ToString)
{
    // Test fail
    // don't SetStrDelimitation
    m_obj.Init(&m_regularObj, &CFTDTestDummyDataField::m_Describe);
    EXPECT_STREQ("", m_obj.ToString().c_str());

    // Test pass
    m_obj.SetStrDelimitation(DIVIDESTR);

    m_obj.Init(&m_regularObj, &CFTDTestDummyDataField::m_Describe);
    EXPECT_STREQ(m_regularObjStr, m_obj.ToString().c_str());

    m_obj.Init(&m_upperBoundObj, &CFTDTestDummyDataField::m_Describe);
    EXPECT_STREQ(m_upperBoundObjStr, m_obj.ToString().c_str());    
}

TEST_F(CFtdDataTest, FromString)
{
    // Test fail
    // don't SetStrDelimitation
    m_obj.Init(&m_regularObj, &CFTDTestDummyDataField::m_Describe);
    EXPECT_FALSE(m_obj.FromString(m_regularObjStr));

    // Test pass
    m_obj.SetStrDelimitation(DIVIDESTR);

    m_obj.Init(&m_regularObj, &CFTDTestDummyDataField::m_Describe);
    EXPECT_TRUE(m_obj.FromString(m_regularObjStr));
    EXPECT_STREQ(m_regularObjStr, m_obj.ToString().c_str());

    m_obj.Init(&m_upperBoundObj, &CFTDTestDummyDataField::m_Describe);
    EXPECT_TRUE(m_obj.FromString(m_upperBoundObjStr));
    EXPECT_STREQ(m_upperBoundObjStr, m_obj.ToString().c_str());    


}

TEST_F(CFtdDataTest, SetAttr)
{

}

TEST_F(CFtdDataTest, GetAttr_RegularObj)
{
    m_obj.Init(&m_regularObj, &CFTDTestDummyDataField::m_Describe);
    {
        WORD v;
        EXPECT_TRUE(m_obj.GetAttr("WordType", CFtdData::AT_Short, &v, sizeof(WORD)));
        EXPECT_EQ(65535, v);
    }

    {
        int v;
        EXPECT_TRUE(m_obj.GetAttr("IntType", CFtdData::AT_Int, &v, sizeof(int)));
        EXPECT_EQ(2147483647, v);
    }

    {
        double v;
        EXPECT_TRUE(m_obj.GetAttr("FloatType", CFtdData::AT_Double, &v, sizeof(double)));
        EXPECT_EQ(100.10, v);
    }

    {
        char v[9];
        EXPECT_TRUE(m_obj.GetAttr("StringType", CFtdData::AT_String, &v, sizeof(v)));
        EXPECT_STREQ("12345678", v);
    }

    {
        char v;
        EXPECT_TRUE(m_obj.GetAttr("EnumType", CFtdData::AT_Char, &v, sizeof(char)));
        EXPECT_EQ('0', v);
    }
}