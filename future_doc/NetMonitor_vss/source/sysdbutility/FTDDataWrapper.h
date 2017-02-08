/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file FTDDataWrapper.h
///@brief �ṩ�˲���FTDЭ�����ݣ�CFTDXXXField���󣩵İ�װ��
///@history 
///20110531	��־ΰ   �������ļ�
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

// CFtdData��һ����װ�࣬����װ��ͨ��Datamodel�������ɵ������ࣨ����CFTDXXXField��λ���ļ�FtdData.h�У�
// CFtdData����Щ�������ṩһЩ�����Ķ�д���������Եķ��������л�/�����л�������
class CFtdData {
public:
	/**Ĭ�Ϲ��캯������Ҫ��������Init��������ʼ������
	*/
    CFtdData() : m_obj(NULL), m_descr(NULL) {}

	/**���ι��캯��
	* @param obj CFTDXXXField����
    * @param descr CFTDXXXField����ľ�̬������m_Describe
	*/
    CFtdData(void * obj, CFieldDescribe* descr) : m_obj(obj), m_descr(descr)
    {
        assert(m_obj && m_descr);
    }

    ~CFtdData() 
    { //empty! 
    }
        
	/**��ʼ��CFtdData������������Դ��ι��캯����������һ��Ҫ��ʼ������
	* @param obj CFTDXXXField����
    * @param descr CFTDXXXField����ľ�̬��������m_Describe
	*/
    void SetInner(void * obj, CFieldDescribe* descr)
    {
        m_obj = obj;
        m_descr = descr;

        assert(m_obj && m_descr);
    }

	/**
    * @return ��װ��CFTDXXXField����
	*/
    void * Obj() const
    {
        return m_obj;
    }

	/**
    * @return ��װ��CFTDXXXField����ľ�̬��������m_Describe
	*/
    CFieldDescribe * Descr() const
    {
        return m_descr;
    }

	/**�����ķ���
	*/
    bool SetIntAttr(const char * attr, DWORD value);

	/**�����ķ���
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

	/**����CFTDXXXField�����ض����Ե�ֵ
	* @param attr ������
    * @param type ���Ե�����
    * @param value Ҫ���óɵ�ֵ
    * @return �ɹ����÷���true�����attrΪ�ջ�����Ч��valueΪ�գ�����false
	*/
    bool SetAttr(const char * attr, Attribute_Type type, const void * value);

	/**��ȡCFTDXXXField�����ض����Ե�ֵ
	* @param attr ������
    * @param type ���Ե�����
    * @param value ��������ֵ�Ķ���
    * @param size ��������ֵ�Ķ���ĳ��ȣ�
    *                    �������ֵΪ�ַ���������value�ĳ������ɲ����������ݣ�������ضϴ���
    * @return �ɹ���ȡ����true�����attrΪ�ջ�����Ч��valueΪ�գ�sizeΪ��Чֵ��<=0��������false
	*/
    bool GetAttr(const char * attr, Attribute_Type type, void * value, int size) const;

	/**��һ�����ݿ��¼�����л���CFTDXXXField����
    *   �������ͱ�Ӧ��Ϊ const SACommand&������SACommandû���ṩconst������������SACommand&
	* @param cmd ���ݿ��¼
	*/
    void FromDBRecord(SACommand& cmd);

	/**��CFTDXXXField�������л���һ�����ݿ��¼
	* @param cmd ���ݿ��¼
	*/
    void ToDBRecord(SACommand& cmd) const;

	/**ͨ��ָ���ķָ������Լ���Ӧ��ʽ���ַ����������л�CFTDXXXField����
    *   �����л�ǰ������ȷ��ͨ��SetStrDelimitation���ù��ָ���
	* @param serializedStr �ܷ����л�ΪCFTDXXXField������ַ���
    * @param attrDelimit �ָ���������Ϊ��
    * @return ���ɹ������л�ʱ����true����֮����false
	*/
    bool FromString(const string& serializedStr, const char * attrDelimit);

	/**���л�CFTDXXXField����ͨ��ָ���ķָ����ָ������ԡ�
    *   ���л����ַ���ǰ������ȷ��ͨ��SetStrDelimitation���ù��ָ���
    * @param attrDelimit �ָ���������Ϊ��
    * @return ���л����ַ������������÷ָ����ָ������û�����÷ָ��������ؿմ�
	*/
    string& ToString(const char * attrDelimit);

    enum Compare_Result {
        CR_EQ,  // =
        CR_GT,  // >
        CR_LT,   // <
        CR_INVALID
    };

	/**�Ƚ��ض����Ե�ֵ��
    * @param name Ҫ�Ƚϵ���������
    * @param value Ҫ�Ƚϵ����Ե�ֵ�����ַ�����ʽ��ʾ��
    * @return �������Ե�ֵ����value������CR_EQ������value������CR_GT��С��value������CR_LT
    *             ���û��attr���Ի�Ϊ�գ�����valueΪ�գ�����CR_INVALID
	*/
    Compare_Result CompareAttrValue(const char * attr, const char * value);

private:
    void * m_obj; //Just a reference.
    CFieldDescribe * m_descr; //Just a reference.

    string m_serializedStr;
    string m_delimit;
};

#endif // __CFTDDATA_WRAPPER_H
