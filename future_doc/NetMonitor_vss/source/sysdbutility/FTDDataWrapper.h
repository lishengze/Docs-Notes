/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file FTDDataWrapper.h
///@brief 提供了操作FTD协议数据（CFTDXXXField对象）的包装类
///@history 
///20110531	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef __CFTDDATA_WRAPPER_H
#define __CFTDDATA_WRAPPER_H

#include <platform.h>
#include <string>
#include <FieldDescribe.h>
#include <PrjCommon.h>

class CFieldDescribe;
class SACommand;

using namespace std;

// CFtdData是一个包装类，它包装了通过Datamodel规则生成的数据类（形如CFTDXXXField，位于文件FtdData.h中）
// CFtdData给这些数据类提供一些便利的读写数据类属性的方法，序列化/反序列化方法。
class CFtdData {
public:
	/**默认构造函数，需要继续调用Init函数来初始化对象
	*/
    CFtdData() : m_obj(NULL), m_descr(NULL) {}

	/**带参构造函数
	* @param obj CFTDXXXField对象
    * @param descr CFTDXXXField对象的静态描述类m_Describe
	*/
    CFtdData(void * obj, CFieldDescribe* descr) : m_obj(obj), m_descr(descr)
    {
        assert(m_obj && m_descr);
    }

    ~CFtdData() 
    { //empty! 
    }
        
	/**初始化CFtdData对象，如果不是以带参构造函数创建对象，一定要初始化对象。
	* @param obj CFTDXXXField对象
    * @param descr CFTDXXXField对象的静态描述对象m_Describe
	*/
    void SetInner(void * obj, CFieldDescribe* descr)
    {
        m_obj = obj;
        m_descr = descr;

        assert(m_obj && m_descr);
    }

	/**
    * @return 包装的CFTDXXXField对象
	*/
    void * Obj() const
    {
        return m_obj;
    }

	/**
    * @return 包装的CFTDXXXField对象的静态描述对象m_Describe
	*/
    CFieldDescribe * Descr() const
    {
        return m_descr;
    }

	/**废弃的方法
	*/
    bool SetIntAttr(const char * attr, DWORD value);

	/**废弃的方法
	*/
    bool GetIntAttr(const char * attr, DWORD * value) const;

    enum Attribute_Type {
        AT_Char = FT_BYTE,
        AT_Short = FT_WORD,
        AT_Int = FT_DWORD,
        AT_String = FT_BYTE,
        AT_Float = FT_REAL8,  // It should be FT_REAL4, but our CUFBaseFloatType is double actually.
        AT_Double = FT_REAL8
    };

	/**设置CFTDXXXField对象特定属性的值
	* @param attr 属性名
    * @param type 属性的类型
    * @param value 要设置成的值
    * @return 成功设置返回true。如果attr为空或者无效；value为空；返回false
	*/
    bool SetAttr(const char * attr, Attribute_Type type, const void * value);

	/**获取CFTDXXXField对象特定属性的值
	* @param attr 属性名
    * @param type 属性的类型
    * @param value 接收属性值的对象
    * @param size 接收属性值的对象的长度，
    *                    如果属性值为字符串，接收value的长度容纳不下所有内容，则会做截断处理。
    * @return 成功获取返回true，如果attr为空或者无效；value为空；size为无效值（<=0）；返回false
	*/
    bool GetAttr(const char * attr, Attribute_Type type, void * value, int size) const;

	/**将一条数据库记录反序列化成CFTDXXXField对象，
    *   参数类型本应该为 const SACommand&，由于SACommand没有提供const方法，所以用SACommand&
	* @param cmd 数据库记录
	*/
    void FromDBRecord(SACommand& cmd);

	/**将CFTDXXXField对象序列化成一条数据库记录
	* @param cmd 数据库记录
	*/
    void ToDBRecord(SACommand& cmd) const;

	/**通过指定的分隔符，以及相应形式的字符串，反序列化CFTDXXXField对象。
    *   反序列化前，必须确保通过SetStrDelimitation设置过分隔符
	* @param serializedStr 能反序列化为CFTDXXXField对象的字符串
    * @param attrDelimit 分隔符，不能为空
    * @return 当成功反序列化时返回true，反之返回false
	*/
    bool FromString(const string& serializedStr, const char * attrDelimit);

	/**序列化CFTDXXXField对象，通过指定的分隔符分隔各属性。
    *   序列化成字符串前，必须确保通过SetStrDelimitation设置过分隔符
    * @param attrDelimit 分隔符，不能为空
    * @return 序列化的字符串，各属性用分隔符分隔。如果没有设置分隔符，返回空串
	*/
    string& ToString(const char * attrDelimit);

    enum Compare_Result {
        CR_EQ,  // =
        CR_GT,  // >
        CR_LT,   // <
        CR_INVALID
    };

	/**比较特定属性的值。
    * @param name 要比较的属性名字
    * @param value 要比较的属性的值，以字符串形式表示。
    * @return 对象属性的值等于value，返回CR_EQ，大于value，返回CR_GT，小于value，返回CR_LT
    *             如果没有attr属性或为空，或者value为空，返回CR_INVALID
	*/
    Compare_Result CompareAttrValue(const char * attr, const char * value);

private:
    void * m_obj; //Just a reference.
    CFieldDescribe * m_descr; //Just a reference.

    string m_serializedStr;
    string m_delimit;
};

#endif // __CFTDDATA_WRAPPER_H
