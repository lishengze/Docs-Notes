/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CExprAnalysis.h
///@brief	�������¼��������
///@history
///20080610	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
///20091218	�ܽ���		�����ӳټ���澯ʱ��궨��
#ifndef REF_CEXPRANALYSIS_H
#define REF_CEXPRANALYSIS_H

#include "public.h"
#include "systools.h"
#include "CBaseValue.h"
#include "CXML.h"
#include "FtdPackageDesc.h"
#include "CBaseValue.h"
#include "CBaseContext.h"

//#define  UNKNOWN_ATTR		0				///δ֪���͵���������
//#define	 STRING_ATTR		1				///�ַ�����������
//#define	 INT_ATTR			2				///������������
//#define	 FLOAT_ATTR			3				///����������
//#define	 PERCENT_ATTR		4				///�ٷֱ���������
#define UNKNOWN_VALUE	UNKNOWN_ATTR
#define STRING_VALUE	STRING_ATTR
#define DINT_VALUE		INT_ATTR
#define DOUBLE_VALUE	FLOAT_ATTR
#define PERCENT_VALUE	PERCENT_ATTR
#define INT_VALUE		10
#define LIST_VALUE		11
#define OBJECT_VALUE	12

#define EXPR_DELAYTIME	300 ///�澯�ӳټ���ʱ��
#define outpos			printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);

/////////////////////////////////////////////////////////////////////////
///CValue�����˱��ʽ���ֵ����
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CValue :
	public CBaseValue
{
	/* */
	protected:
		///����ֵ����Ϊ�������ʶ����ӦID��ֵ
		int m_intValue;

		///����ֵ����Ϊ��������ֵ
		double	m_fltValue;

		///����ֵ����Ϊ����ʱ��Ӧ��ʱ��
		int m_intTime;

		///����ֵ����Ϊ�ַ�����ֵ
		CRefStringPtr m_stringValue;

		///���溯������ֵ�б�,��������ֵΪ����
		list<int> m_listValue;

	/* */
	public:

		///���캯��
		CValue(void)
		{
			m_intTime = 0;
			m_fltValue = 0.0;
			m_intTime = 0;
			m_bConstant = false;
		}

		///�������캯��
		CValue(const CValue &s)
		{
			m_valueType = s.m_valueType;
			m_intValue = s.m_intValue;
			m_stringValue = s.m_stringValue;
			m_fltValue = s.m_fltValue;
			m_bConstant = s.m_bConstant;
		}

		///��������
		virtual~CValue(void)
		{
		}

		///��������������,���ö�������Ϊ�������Ͷ���,ֵΪvalue
			///@param	value	���������ֵ
			///@return	�������ý��,trueΪ�ɹ�,falseΪʧ��
		virtual bool setIntegerConstant(int value)
		{
			m_valueType = INT_VALUE;
			m_intValue = value;
			m_fltValue = (double)value;
			return true;
		}

		///ȡ���������ֵ����
			///@return	�������������ֵ
		int getIntValue(void)
		{
			return m_intValue;
		}

		///����ֵ����
			///@param	value	���õ�ֵ
			///@param	valueType	ֵ������
		virtual bool setValue(
		int valueTime,
		const char	*valueString,
		int valueType)
		{
			m_valueType = valueType;
			if (valueType == STRING_VALUE)
			{
				m_stringValue = new CRefString(valueString);
			}
			else if (valueType == DINT_VALUE)
			{
				m_intValue = (int)atoi(valueString);
				m_intTime = valueTime;
				m_fltValue = (double)atof(valueString);
			}
			else if (valueType == FLOAT_ATTR)
			{
				m_intTime = valueTime;
				m_fltValue = (double)atof(valueString);
			}
			else if (valueType == PERCENT_ATTR)
			{
				m_intTime = valueTime;
				m_valueType = DOUBLE_VALUE;
				m_fltValue = (double)atof(valueString);
			}
			else if (valueType == UNKNOWN_VALUE)
			{
				m_valueType = valueType;
				m_intTime = valueTime;
			}
			else
			{
				printf(
					"UnKnown value type %d valueTime %d valueString %s\n",
					valueType,
					valueTime,
					valueString);
			}

			return true;
		}

		///�����ַ���������,���ö�������Ϊ�ַ������Ͷ���,ֵΪvalue
			///@param	value	������ַ���ֵ
			///@return	�������ý��,trueΪ�ɹ�,falseΪʧ��
		virtual bool setStringConstant(const CRefStringPtr &value)
		{
			m_valueType = STRING_VALUE;
			m_stringValue = value;
			return true;
		}

		///�����ַ���������,���ö�������Ϊ�ַ������Ͷ���,ֵΪvalue
			///@param	value	������ַ���ֵ
			///@return	�������ý��,trueΪ�ɹ�,falseΪʧ��
		bool setStringConstant(const CRefStringPtr &value, int timeValue)
		{
			m_valueType = STRING_VALUE;
			m_stringValue = value;
			m_intTime = timeValue;
			return true;
		}

		///ȡ�ַ��������ֵ����
			///@return	�����ַ������������
		CRefStringPtr &getStringValue(void)
		{
			return m_stringValue;
		}

		///���ñ�ʶ��������,���ö�������Ϊ��ʶ�����Ͷ���,ֵΪvalue
			///@param	value	����ı�ʶ��ֵ
			///@return	�������ý��,trueΪ�ɹ�,falseΪʧ��
		virtual bool setIdentifierConstant(const CRefStringPtr &value);

		///���ñ�ʶ��������,���ö�������Ϊ��ʶ�����Ͷ���,ֵΪvalue
			///@param	value	��ʶ��ֵ�����ID
		void setObjectValue(int value)
		{
			m_valueType = OBJECT_VALUE;
			m_intValue = value;
		}

		///ȡ��ʶ������ID�ĺ���
			///@return	���ر�ʶ�������ID
		int getObjectValue(void)
		{
			return m_intValue;
		}

		///����list������,���ö�������Ϊlist���Ͷ���,ֵΪvalue
			///@param	value	listֵ
		void setListValue(int value)
		{
			m_valueType = LIST_VALUE;
			m_listValue.push_back(value);
		}

		///ȡ��ʶ������ID�ĺ���
			///@return	���ر�ʶ�������ID
		list<int> *getListValue(void)
		{
			return &m_listValue;
		}

		///��������������,���ö�������Ϊ�������Ͷ���,ֵΪvalue
			///@param	value	���������ֵ
			///@param	timeValue	���ָ��ֵ��Ӧ��ʱ��
			///@return	�������ý��,trueΪ�ɹ�,falseΪʧ��
		bool setDIntConstant(int value, int timeValue)
		{
			m_valueType = DINT_VALUE;
			m_intValue = value;
			m_intTime = timeValue;
			m_fltValue = (double)value;
			return true;
		}

		///���ø�����������,���ö�������Ϊ�������Ͷ���,ֵΪvalue
			///@param	value	����ĸ���ֵ
			///@return	�������ý��,trueΪ�ɹ�,falseΪʧ��
		virtual bool setFloatConstant(double value)
		{
			m_valueType = DOUBLE_VALUE;
			m_fltValue = value;
			m_intValue = (int)value;
			return true;
		}

		///���ø�����������,���ö�������Ϊ�������Ͷ���,ֵΪvalue
			///@param	value	����ĸ���ֵ
			///@param	timeValue	���ָ��ֵ��Ӧ��ʱ��
			///@return	�������ý��,trueΪ�ɹ�,falseΪʧ��
		bool setFltConstant(double value, int timeValue)
		{
			m_valueType = DOUBLE_VALUE;
			m_fltValue = value;
			m_intTime = timeValue;
			m_intValue = (int)value;
			return true;
		}

		///ȡ���������ֵ����
			///@return	������������ֵ
		int getDIntValue(void)
		{
			return m_intValue;
		}

		///ȡ��������ֵ����
			///@return	������������ֵ
		double getFltValue(void)
		{
			return m_fltValue;
		}

		///ȡ�����ʱ��ֵ����
		///@return	�������������ʱ��ֵ
		int getDTimeValue(void)
		{
			return m_intTime;
		}

		///�����������
		virtual void display(FILE *output = stdout);
};


/// Mod by Henchi, 20130531
/// ���ݸ�ʽ�������ֶξ���
#define RECORDWARNINGINFO_ATTR		char szBuf[4096];		\
	sprintf(szBuf,"[%s] %s:%s Value[%s] MTime[%d] Now[%d] Delay(%d)sec\r\n",	\
		(const char *)pMonitorEntity->Time,													\
		g_mStringIdMap.getString(pMonitorEntity->MonitorObject),	\
		g_mStringIdMap.getString(pMonitorEntity->MonitorItem),		\
		(const char *)pMonitorEntity->AttrValue,									\
		(int)(pMonitorEntity->MonitorTime),												\
		(int)m_now,	(int)m_now - (int)(pMonitorEntity->MonitorTime) 		\
	);	\
	if (std::find(g_warningInfoList.begin(), g_warningInfoList.end(), szBuf) == g_warningInfoList.end())	\
		g_warningInfoList.push_back(szBuf);


#define RECORDWARNINGINFO_NOATTR		char szBuf[4096];		\
	char clockBuffer[20];															  \
	time_t	timeClock = monitorNow;													  \
	struct tm tm_time;										  \
	if (LocalTime(&timeClock, &tm_time) != NULL)															  \
	{																				  \
		sprintf(																	  \
			clockBuffer,															  \
			"%04d%02d%02d %02d:%02d:%02d",											  \
			1900 + tm_time.tm_year,												  \
			1 + tm_time.tm_mon,													  \
			tm_time.tm_mday,														  \
			tm_time.tm_hour,														  \
			tm_time.tm_min,														  \
			tm_time.tm_sec);														  \
	}																				  \
	sprintf(szBuf,"[%s] %s:%s Value[(null)]\r\n",	\
		(const char *)clockBuffer,																\
		g_mStringIdMap.getString(monitorObject),	\
		g_mStringIdMap.getString(monitorItem));	\
	g_bValueExist = false;															  \
	result.setDIntConstant(-1, -1);												\
	if (std::find(g_warningInfoList.begin(), g_warningInfoList.end(), szBuf) == g_warningInfoList.end())	\
		g_warningInfoList.push_back(szBuf);


#define RECORDWARNINGINFO_EVENT		char szBuf[4096];		\
	sprintf(szBuf,"[%s] %s %s[%s][%s] Des[%s] MTime[%d] Now[%d] Delay(%d)sec\r\n",	\
		(const char *)pEventEntity->Time,													\
		g_mStringIdMap.getString(pEventEntity->MonitorObject),	\
		g_mStringIdMap.getString(pEventEntity->EventName),		\
		(const char *)pEventEntity->WarningLevel,							\
		(const char *)pEventEntity->ProcessFlag,							\
		(const char *)pEventEntity->EventDes,									\
		(int)(pEventEntity->MonitorTime),												\
		(int)m_now,	(int)m_now - (int)(pEventEntity->MonitorTime) 		\
	);	\
	if (std::find(g_warningInfoList.begin(), g_warningInfoList.end(), szBuf) == g_warningInfoList.end())	\
		g_warningInfoList.push_back(szBuf);


/////////////////////////////////////////////////////////////////////////
///CContext������һ�����������ĵ��࣬ʹ�õ�ģ�����CValueֵ��
///@author	�ܽ���
///@version	1.0,20080623
/////////////////////////////////////////////////////////////////////////
class CContext :
	public CBaseContext<CValue>
{
	/* */
	private:
		///����ĵ�ǰʱ��ؼ��ֵ�ֵ
		int m_now;

	/* */
	public:
		///���캯��
			///@param	pConfigFile	�ڴ����ݿ�ʹ�õ������ļ���
		CContext(char *pConfigFile);

		///��������
		~ CContext(void);

		///���õ�ǰʱ��ؼ���ֵ����
			///@param	newNow	�µĵ�ǰʱ��ֵ
		void setNow(int newNow);

		///��ȡ��ǰʱ��ؼ���ֵ����
			///@return	���ص�ǰʱ��now�ؼ��ֵ�����ֵ
		int getNow(void);

		///���µ�ǰʱ��ؼ���ֵ����
			///@param	newNow	�µĵ�ǰʱ��ֵ
		void updateNow(int newNow)
		{
			m_now = newNow;
		}

		///ȡ�ؼ���ֵ����
			///@param	result	����ؼ���ȡ�õĽ��ֵ
			///@param	keyword	�ؼ��ֵ�����
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		virtual bool getKeywordValue(CValue &result, const char *keyword);

		///��Ŀ��������㺯��,���㵥Ŀ������Ľ��ֵ
			///@param	result	������ż�����ֵ
			///@param	value	��Ŀ�������������
			///@param	thisOperator	��Ŀ�������
			///@return	���ؽ��,true��ʾ�ɹ�,false��ʾʧ��
		virtual bool getUniOperatorResult(
						CValue	&result,
						CValue	&value,
						const char	*thisOperator);

		///˫Ŀ��������㺯��,����˫Ŀ������Ľ��ֵ
			///@param	result	������ż�����ֵ
			///@param	value1	˫Ŀ�������������
			///@param	thisOperator	˫Ŀ�������
			///@param	value2	˫Ŀ�������������
			///@return	���ؽ��,true��ʾ�ɹ�,false��ʾʧ��
		virtual bool getBiOperatorResult(
						CValue	&result,
						CValue	&value1,
						const char	*thisOperator,
						CValue	&value2);

		///���㺯����ֵ������ʹ�ñ�ʶ����ע�⣬Ҳ����������������
			///@param	result	���ý����ֵ
			///@param	identifier	���������Ʊ�ʶ��
			///@param	funcSeperator	���������ķָ����ĵ�һ����һ����'('��'['�����
			///@param	paraCount	�����ĸ���
			///@param	paraList	�����嵥��
			///@return	���ؽ��,true��ʾ�ɹ�,false��ʾʧ��
		virtual bool evalFunction(
						CValue	&result,
						const CRefStringPtr &identifier,
						char funcSeperator,
						int paraCount,
						CValue	**paraList);

		///if������ʵ�ֺ���
			///@param	result	���ý����ֵ
			///@param	paraList	�����嵥��
			///@return	���ؽ��,true��ʾ�ɹ�,false��ʾʧ��
		bool ifFunc(CValue &result, CValue **paraList);

		///myItoa������ʵ�ֺ���,������Ϊ�ַ�������
			///@param	result	���ý����ֵ
			///@param	paraList	�����嵥,
			///		paraList[0]Ϊ��Ҫ�任������,paraList[1]Ϊ�ַ�������
			///@return	���ؽ��,true��ʾ�ɹ�,false��ʾʧ��
		bool myItoa(CValue &result, CValue **paraList);

		///myAtoi������ʵ�ֺ���,�ַ����任Ϊ����
			///@param	result	���ý����ֵ
			///@param	paraList	�����嵥
			///@return	���ؽ��,true��ʾ�ɹ�,false��ʾʧ��
		bool myAtoi(CValue &result, CValue **paraList);

		///myAtof������ʵ�ֺ���,�ַ����任Ϊ������
			///@param	result	���ý����ֵ
			///@param	paraList	�����嵥
			///@return	���ؽ��,true��ʾ�ɹ�,false��ʾʧ��
		bool myAtof(CValue &result, CValue **paraList);

		///Ttoi������ʵ�ֺ���,�ַ���ʱ��任Ϊ����
			///@param	result	���ý����ֵ
			///@param	paraList	�����嵥
			///@return	���ؽ��,true��ʾ�ɹ�,false��ʾʧ��
		bool Ttoi(CValue &result, CValue **paraList);

		///Itot������ʵ�ֺ���,����ʱ��任Ϊ�ַ���
			///@param	result	���ý����ֵ
			///@param	paraList	�����嵥
			///@return	���ؽ��,true��ʾ�ɹ�,false��ʾʧ��
		bool Itot(CValue &result, CValue **paraList);

		///nowbetween����,�жϵ�ǰʱ���Ƿ���ʱ�䷶Χ��
			///@param	result	���溯��������ֵ
			///@param	paraList	nowbetween�����Ĳ����б�
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool nowbetween(CValue &result, CValue **paraList);

		///valbetween����,�жϵ�ǰ���������Ƿ���ֵ��Χ[value1, value2)��(����ҿ�)
			///@param	result	���溯��������ֵ
			///@param	paraList	valbetween�����Ĳ����б�
		//object�� Ŀ�����ֵ
		//value1���Աȼ�������ֵ
		//value2���Աȼ�������ֵ
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool valbetween(CValue &result, CValue **paraList);

		///ObjectIn����,���Ŀ��ؼ����Ƿ����ڶԱȼ�����
			///@param	result	���溯��������ֵ
			///@param	paraCount	�����������ֵ
			///@param	paraList	ObjectIn�����Ĳ����б�
			///@paraList
		//object�� Ŀ��ؼ���
		//valueList���Աȼ�������Ϣ�б�����ö�ٸ���
		//����ֵ������������д�������object�ؼ�����ֵͬ�򷵻�true,����Ϊfalse
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool ObjectIn(CValue &result, int paraCount, CValue **paraList);

		///ObjectContain����,���Ŀ��ؼ����Ƿ����ڶԱȼ�����
			///@param	result	���溯��������ֵ
			///@param	paraCount	�����������ֵ
			///@param	paraList	ObjectContain�����Ĳ����б�
			///@paraList
		//object�� Ŀ��ؼ���
		//valueList���Աȼ�������Ϣ�б�����ö�ٸ���
		//����ֵ������������д�����[����]object�ؼ��ֵĴ�ֵ�򷵻�true,����Ϊfalse
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool ObjectContain(CValue &result, int paraCount, CValue **paraList);

		///getdatediff����,�����������ڴ�֮���������
			///@param	result	���溯��������ֵ
			///@param	paraList	getdatediff�����Ĳ����б�
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool getdatediff(CValue &result, CValue **paraList);

		///gettimediff����,��������ʱ�䴮֮���������
			///@param	result	���溯��������ֵ
			///@param	paraList	gettimediff�����Ĳ����б�
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool gettimediff(CValue &result, CValue **paraList);

		///getTimeSec����,������ֵ���񱣴������ֵ
		///@param	result	���溯��������ֵ
		///@param	pTimeValue	����ʱ�����ݵ�Value�ṹ����Ϊ��ֵ���ִ���(֧��8������17�ֽ�ʱ���ʽ)
		///@return	���ؾ������������
		int getTimeSec(CValue * pTimeValue);
		
		///getTimeGap����,��������ʱ�䣨���ݻ�����ǰ��Ҳ֧�֣�֮����������ľ���ֵ
		///@param	result	���溯��������ֵ
		///@param	paraCount	getTimeGap�����Ĳ�������
		///@param	paraList	getTimeGap�����Ĳ����б�
		///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool getTimeGap(CValue &result, CValue **paraList);

		///getperiod����,ȡָ��Ĳɼ�ʱ����
			///@param	result	���溯��������ֵ
			///@param	paraList	getperiod�����Ĳ����б�
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool getperiod(CValue &result, CValue **paraList);

		///getStringId����,ȡ�ַ�����Ӧ��IDֵ
			///@param	result	���溯��������ֵ
			///@param	paraList	getValue�����Ĳ����б�
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool getStringId(CValue &result, CValue **paraList);

		///getmaincentername����,ȡ��ǰ���������ĵ�����
			///@param	result	���溯��������ֵ
			///@param	paraList	getperiod�����Ĳ����б�
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool getmaincentername(CValue &result, CValue **paraList);

		///getactiveapp����,ȡ��ǰָ�����͵Ļҵ����̵ĸ���
			///@param	result	���溯��������ֵ
			///@param	paraList	getperiod�����Ĳ����б�
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool getactiveapp(CValue &result, CValue **paraList);

		///getSystemName����,ȡ��ǰ����������ҵ��ϵͳ��
			///@param	result	���溯��������ֵ
			///@param	paraList	getSystemName�����Ĳ����б�
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool getSystemName(CValue &result, CValue **paraList);

		///getDomainName����,ȡ����ID��ָ���򲿷ֵ��ִ�
			///@param	result	���溯��������ֵ
			///@param	paraList	getDomainName�����Ĳ����б�
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool getDomainName(CValue &result, CValue **paraList);

		///getValue����,���ݼ�ض���ID,ָ��ID,ʱ��ȡ���ָ���ֵ
			///@param	result	���溯��������ֵ
			///@param	paraList	getValue�����Ĳ����б�
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool getValue(CValue &result, CValue **paraList);

		///===�����¼��ڴ�����ĺ�������===
			///Summary����,ͳ�����һ��ʱ�����¼���������
			///@param	result	���溯��������ֵ
			///@param	paraList	Summary�����Ĳ����б�
			///@paraList	������һ������: EventName	�¼���
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool Summary(CValue &result, CValue **paraList);

		///ObjectEventSummary����,ͳ��ָ���������һ��ʱ�����¼���������
			///@param	result	���溯��������ֵ
			///@param	paraList	ObjectEventSummary�����Ĳ����б�
			///@paraList	��������������: ObjectId����ID,EventName�¼���
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool ObjectEventSummary(CValue &result, CValue **paraList);

		///Exist����,���һ��ʱ�����Ƿ���ĳ�¼�
			///@param	result	���溯��������ֵ
			///@param	paraList	Summary�����Ĳ����б�
			///@paraList	������һ������: EventName	�¼���
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool Exist(CValue &result, CValue **paraList);

		///ObjectEventExist����,ͳ��ָ���������һ��ʱ�����Ƿ���ĳ�¼�
			///@param	result	���溯��������ֵ
			///@param	paraList	ObjectEventSummary�����Ĳ����б�
			///@paraList	��������������: ObjectId����ID,EventName�¼���
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool ObjectEventExist(CValue &result, CValue **paraList);

		///IsWorkingDay����,����¼������Ƿ��ǹ����պ���
			///@param	result	���溯��������ֵ������ǹ����գ�resultΪ1������Ϊ0
			///@param	paraList	IsWorkingDay�����Ĳ����б�
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool IsWorkingDay(CValue &result, CValue **paraList);

		///IsDayTradingPeriod����,�жϸ�����ʱ���Ƿ������̽���ʱ��
			///@param	result	���溯��������ֵ
			///@param	paraCount	�����������			
			///@param	paraList	getDomainName�����Ĳ����б�
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool IsDayTradingPeriod(CValue &result, int paraCount, CValue **paraList);

		///IsNightTradingPeriod����,�жϸ�����ʱ���Ƿ���ҹ�̽���ʱ��
			///@param	result	���溯��������ֵ
			///@param	paraCount	�����������			
			///@param	paraList	getDomainName�����Ĳ����б�
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool IsNightTradingPeriod(CValue &result, int paraCount, CValue **paraList);

		///IsTradingPeriod����,�жϸ�����ʱ���Ƿ��ǽ���ʱ��
		///@param	result	���溯��������ֵ
		///@param	paraCount	�����������			
		///@param	paraList	getDomainName�����Ĳ����б�
		///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool IsTradingPeriod(CValue &result, int paraCount, CValue **paraList);

		///IsTradingDay����,�жϸ����������Ƿ��ǽ�����
		///@param	result	���溯��������ֵ
		///@param	paraCount	�����������			
		///@param	paraList	getDomainName�����Ĳ����б�
		///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool IsTradingDay(CValue &result, int paraCount, CValue **paraList);

		///IsContinuousTradingDay����,�жϸ����������Ƿ�������������
		///@param	result	���溯��������ֵ
		///@param	paraCount	�����������			
		///@param	paraList	getDomainName�����Ĳ����б�
		///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool IsContinuousTradingDay(CValue &result, int paraCount, CValue **paraList);

		///HasNightTradingPeriod����,�жϸ����������Ƿ���ҹ��
		///@param	result	���溯��������ֵ
		///@param	paraCount	�����������			
		///@param	paraList	getDomainName�����Ĳ����б�
		///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool HasNightTradingPeriod(CValue &result, int paraCount, CValue **paraList);

		///CheckEventOccur����,����¼��Ƿ�������
			///@param	result	���溯��������ֵ
			///@param	paraList	CheckEventOccur�����Ĳ����б�
			///@paraList	ObjectId����ID,EventName�¼���,Interval�¼������������ڵ������,KeyType���Ĺؼ�����,KeyValue���Ĺؼ���ֵ
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool CheckEventOccur(CValue &result, CValue **paraList);

		///CheckEventDesc����,��鷢���¼������еĹؼ��ֶ�Ӧ��ֵ�Ƿ���ͬ�ĺ���
			///@param	result	���溯��������ֵ
			///@param	paraList	CheckEventOccur�����Ĳ����б�
			///@paraList	ObjectId����ID,EventName�¼���,Interval�¼������������ڵ������,KeyType���Ĺؼ�����,KeyValue���Ĺؼ���ֵ
		//objectid�� ����ID
		//eventname�� �¼���
		//timeval��ֻ������ʱ�����ڵ��¼�
		//key���¼���������Ҫ���Ĺؼ���
		//value���¼���������Ҫ���ؼ��ֵ�ֵ
		//����ֵ����������д��� key='value'����ú�������Ϊtrue
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool CheckEventDesc(CValue &result, CValue **paraList);

		///CheckEventValid����,���ʱ���ڷ����¼������е��Ƿ���ڲ����ϼ�ֵ��Ҫ��Ķ���
			///@param	result	���溯��������ֵ
			///@param	paraList	CheckEventOccur�����Ĳ����б�
			///@paraList	ObjectId����ID,EventName�¼���,Interval�¼������������ڵ������,KeyType���Ĺؼ�����,KeyValue���Ĺؼ���ֵ
		//objectid�� ����ID
		//eventname�� �¼���
		//timeval��ֻ������ʱ�����ڵ��¼�
		//key���¼���������Ҫ���Ĺؼ���
		//value���¼���������Ҫ���ؼ��ֵ�ֵ
		//����ֵ����������д��� key!='value'����ú�������Ϊfalse�����򷵻�true
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool CheckEventValid(CValue &result, CValue **paraList);

		///CheckEventDescExist����,���ʱ���ڷ����¼������е��Ƿ���ڷ��ϼ�ֵ��Ҫ��Ķ���
			///@param	result	���溯��������ֵ
			///@param	paraList	CheckEventOccur�����Ĳ����б�
			///@paraList	ObjectId����ID,EventName�¼���,Interval�¼������������ڵ������,KeyType���Ĺؼ�����,KeyValue���Ĺؼ���ֵ
		//objectid�� ����ID
		//eventname�� �¼���
		//timeval��ֻ������ʱ�����ڵ��¼�
		//key���¼���������Ҫ���Ĺؼ���
		//value���¼���������Ҫ���ؼ��ֵ�ֵ
		//����ֵ����������д��� key='value'����ú�������Ϊtrue
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool CheckEventDescExist(CValue &result, CValue **paraList);

		//++++++++++ Added by Henchi, 20120620 ++++++++++
		
		///CheckEventDescValue������Ѱ��ָ��ʱ�����Ƿ���ڷ����������¼�������"AND"������¼�������ֵУ�飩
		///@param	result	���溯��������ֵ
		///@param	paraCount	CheckEventDescValue�����Ĳ�������
		///@param	paraList	CheckEventDescValue�����Ĳ����б�
		///@paraList	ObjectId����ID,EventName�¼���,Interval�¼������������ڵ������,KeyType���Ĺؼ�����,KeyValue���Ĺؼ���ֵ
		//[1]objectid�� ����ID
		//[2]eventname�� �¼���
		//[3]timeval��ֻ������ʱ�����ڵ��¼�
		//[4]fieldno��ָ������ţ��Կո�ָ��ģ�
		//[5]operator����ϵ������ִ������αȽ�:eq,ge,le,gt,lt,ne;�ִ��Ƚ�:eqs,ges,les,gts,lts,nes��
		//[6]value��ָ��ƥ���ֵ
		//[...]��������������ɶ�γ��֣�����ָ��������У��
		//����ֵ��true��ʾ�ҵ���,false��ʾû���ҵ�
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool CheckEventDescValue(
				CValue	&result,
				int paraCount,
				CValue	**paraList);

		///CheckEventDescValueOR������Ѱ��ָ��ʱ�����Ƿ���ڷ����������¼�������"OR"������¼�������ֵУ�飩
		///@param	result	���溯��������ֵ
		///@param	paraCount	CheckEventDescValue�����Ĳ�������
		///@param	paraList	CheckEventDescValue�����Ĳ����б�
		///@paraList	ObjectId����ID,EventName�¼���,Interval�¼������������ڵ������,KeyType���Ĺؼ�����,KeyValue���Ĺؼ���ֵ
		//[1]objectid�� ����ID
		//[2]eventname�� �¼���
		//[3]timeval��ֻ������ʱ�����ڵ��¼�
		//[4]fieldno��ָ������ţ��Կո�ָ��ģ�
		//[5]operator����ϵ������ִ������αȽ�:eq,ge,le,gt,lt,ne;�ִ��Ƚ�:eqs,ges,les,gts,lts,nes��
		//[6]value��ָ��ƥ���ֵ
		//[...]��������������ɶ�γ��֣�����ָ��������У��
		//����ֵ��true��ʾ�ҵ���,false��ʾû���ҵ�
		///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool CheckEventDescValueOR(
				CValue	&result,
				int paraCount,
				CValue	**paraList);

		///GetEventTimeByDescValue������Ѱ��ָ��ʱ�����Ƿ���ڷ����������¼�������"AND"������¼�������ֵУ�飩,�������¼�ʱ��(����)
		///@param	result	���溯��������ֵ
		///@param	paraCount	CheckEventDescValue�����Ĳ�������
		///@param	paraList	CheckEventDescValue�����Ĳ����б�
		///@paraList	ObjectId����ID,EventName�¼���,Interval�¼������������ڵ������,KeyType���Ĺؼ�����,KeyValue���Ĺؼ���ֵ
		//[1]objectid�� ����ID
		//[2]eventname�� �¼���
		//[3]timeval��ֻ������ʱ�����ڵ��¼�
		//[4]fieldno��ָ������ţ��Կո�ָ��ģ�
		//[5]operator����ϵ������ִ������αȽ�:eq,ge,le,gt,lt,ne;�ִ��Ƚ�:eqs,ges,les,gts,lts,nes��
		//[6]value��ָ��ƥ���ֵ
		//[...]��������������ɶ�γ��֣�����ָ��������У��
		//����ֵ��true��ʾ�ҵ���,false��ʾû���ҵ�
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool GetEventTimeByDescValue(
				CValue	&result,
				int paraCount,
				CValue	**paraList);

		///GetEventTimeByDescValueOR������Ѱ��ָ��ʱ�����Ƿ���ڷ����������¼�������"OR"������¼�������ֵУ�飩,�������¼�ʱ��(����)
		///@param	result	���溯��������ֵ
		///@param	paraCount	CheckEventDescValue�����Ĳ�������
		///@param	paraList	CheckEventDescValue�����Ĳ����б�
		///@paraList	ObjectId����ID,EventName�¼���,Interval�¼������������ڵ������,KeyType���Ĺؼ�����,KeyValue���Ĺؼ���ֵ
		//[1]objectid�� ����ID
		//[2]eventname�� �¼���
		//[3]timeval��ֻ������ʱ�����ڵ��¼�
		//[4]fieldno��ָ������ţ��Կո�ָ��ģ�
		//[5]operator����ϵ������ִ������αȽ�:eq,ge,le,gt,lt,ne;�ִ��Ƚ�:eqs,ges,les,gts,lts,nes��
		//[6]value��ָ��ƥ���ֵ
		//[...]��������������ɶ�γ��֣�����ָ��������У��
		//����ֵ��true��ʾ�ҵ���,false��ʾû���ҵ�
		///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool GetEventTimeByDescValueOR(
				CValue	&result,
				int paraCount,
				CValue	**paraList);

		///getEventDesc����,��ȡָ��ʱ�������һ��ָ���¼��������������н�ȡĿ���ֶ�
		///@param	result	���溯��������ֵ
		///@param	paraList	getEventDesc�����Ĳ����б�
		///@paraList	ObjectId����ID,EventName�¼���,Interval�¼������������ڵ������,KeyType���Ĺؼ�����,KeyValue���Ĺؼ���ֵ
		//objectid�� ����ID
		//eventname�� �¼���
		//timeval��ֻ������ʱ�����ڵ��¼�
		//fieldno��ָ������ţ��Կո�ָ��ģ�
		//����ֵ������Ŀ������ִ���Ϣ����1��ʼ��ʶ��ţ�0��ʾȫ��������Ϣ��
			///@return	���ؽ��,Ϊtrue��ʾ�ɹ�,false��ʾʧ��
		bool getEventDesc(CValue &result, CValue **paraList);

		//++++++++++ Added End ++++++++++
		
		///+++�����¼��ڴ�����ĺ�������+++
		
		///getItemValue����,ȡ���ָ���ֵ
		///@param	result	���溯��������ֵ
		///@param	monitorObject	��ض����ID
		///@param	monitorItem	���ָ���ID
		///@param	monitorTime	��ص�ʱ��
		///@return	���ؼ��ָ���Ƿ�ȡ�óɹ���true��ʾ�ɹ���false��ʾʧ��
		double	getItemValue(
					int monitorObject,
					int monitorItem,
					int monitorTime);

		///getItemValue����,ȡ���ָ���ֵ
		///@param	result	���溯��������ֵ
		///@param	monitorObject	��ض����ID
		///@param	monitorItem	���ָ���ID
		///@param	monitorTime	��ص�ʱ��
		///@return	���ؼ��ָ���Ƿ�ȡ�óɹ���true��ʾ�ɹ���false��ʾʧ��
		bool getItemValue(
				CValue	&result,
				int monitorObject,
				int monitorItem,
				int monitorNow);

		///getLastedItemValue����,ȡ���ָ�����µ�ֵ(@)
		///@param	result	���溯��������ֵ
		///@param	monitorObject	��ض����ID
		///@param	monitorItem	���ָ���ID
		///@param	monitorTime	���ؼ�ص�ʱ��
		///@return	���ؼ��ָ���Ƿ�ȡ�óɹ���true��ʾ�ɹ���false��ʾʧ��
		bool getLastedItemValue(
				CValue	&result,
				int monitorObject,
				int monitorItem,
				int monitorNow,
				int &monitorTime);

		///getLastedItemTime����,ȡ���ָ�����µ�ֵ��Ӧ��ʱ��
		///@param	result	���溯��������ֵ
		///@param	monitorObject	��ض����ID
		///@param	monitorItem	���ָ���ID
		///@param	monitorTime	���ؼ�ص�ʱ��
		///@return	���ؼ��ָ���Ƿ�ȡ�óɹ���true��ʾ�ɹ���false��ʾʧ��
		bool getLastedItemTime(
				CValue	&result,
				int monitorObject,
				int monitorItem,
				int monitorNow,
				int &monitorTime);

		///getNextItemValue����,ȡ���ָ����һ�ε�ֵ(#)
			///@param	result	���溯��������ֵ
			///@param	monitorObject	��ض����ID
			///@param	monitorItem	���ָ���ID
			///@param	monitorTime	���ؼ�ص�ʱ��
			///@return	���ؼ��ָ���Ƿ�ȡ�óɹ���true��ʾ�ɹ���false��ʾʧ��
		bool getNextItemValue(
				CValue	&result,
				int monitorObject,
				int monitorItem,
				int monitorNow,
				int &monitorTime);

		///getNextItemTime����,ȡ���ָ����һ�ε�ֵ��Ӧ��ʱ��
			///@param	result	���溯��������ֵ
			///@param	monitorObject	��ض����ID
			///@param	monitorItem	���ָ���ID
			///@param	monitorTime	���ؼ�ص�ʱ��
			///@return	���ؼ��ָ���Ƿ�ȡ�óɹ���true��ʾ�ɹ���false��ʾʧ��
		bool getNextItemTime(
				CValue	&result,
				int monitorObject,
				int monitorItem,
				int monitorNow,
				int &monitorTime);

		///getCurrentItemValue����,ȡ���ָ��ָ��ʱ����ǰ��ֵ($)
			///@param	result	���溯��������ֵ
			///@param	monitorObject	��ض����ID
			///@param	monitorItem	���ָ���ID
			///@param	monitorTime	���ؼ�ص�ʱ��
			///@return	���ؼ��ָ���Ƿ�ȡ�óɹ���true��ʾ�ɹ���false��ʾʧ��
		bool getCurrentItemValue(
				CValue	&result,
				int monitorObject,
				int monitorItem,
				int &monitorNow,
				int timeVal);		
};

class CEventNodePaser;

/////////////////////////////////////////////////////////////////////////
///CExprAnalysis�����˽���XML�¼�������ʽ�������������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CExprAnalysis
{
	/* */
	public:
		///���캯��
			///@param	pEventCfgFile	�����¼���XML�ļ���
		CExprAnalysis(char *pEventCfgFile);

		///��������
		~ CExprAnalysis(void);

		///���Ӽ��״ֵ̬����
			///@param	monitorObject	��ض�����
			///@param	monitorItem	���ָ����
			///@param	monitorTime	���ָ�������ʱ��
			///@param	monitorValue	���ָ���ֵ(����)
		void addMonitorEntity(
				const char	*monitorObject,
				const char	*monitorItem,
				int monitorTime,
				int monitorValue);

		///���Ӽ��״ֵ̬����
			///@param	monitorObject	��ض�����
			///@param	monitorItem	���ָ����
			///@param	monitorTime	���ָ�������ʱ��
			///@param	monitorValue	���ָ���ֵ(����)
		void addMonitorEntity(
				int monitorObject,
				int monitorItem,
				int monitorTime,
				int monitorValue);

		///��ȡָ�꺯��,�ӱ��ʽ����ȡ����һ��û��ָ����ض����ָ��
			///@param	attr	��ȡ���ļ��ָ��
			///@param	object	��ȡ���ļ�ض���
			///@param	expr	���ʽ��ָ��
		bool getAttrFromExpr(string &attr, string &object, char *expr);

		///���Ӽ�ض���ָ�꺯��,û��ָ����ض����ָ����Ҫ���Ӽ�ض���
			///@param	strExpr	����ļ��㹫ʽ	
			///@param	objectid	��Ҫ���ӵĶ���ID
			///@param	expr	���ʽ��ָ��
		bool addObjectIdtoExpr(string &strExpr, string &objectid, char *pExpr);

		///���ӱ��ʽ����
		void addExpr(void);

		void exprTest(void);
		void exprRun(void);

		//����������ݿ�ı��ʽ
		bool generateObjectExpr(
				map<int, map<string, int> > &expr_device_list,
				map<string, map<string, int> > &,
				map<int, CFTDRspQryNetEventExprField> &exprs);

		bool isExprAvailable(void)
		{
			return m_bExprAvailable;
		}

		void AddWarningEvent(CFTDRtnWarningEventField &warningevent)
		{
			m_listWarningEvent.add(warningevent);
		}

		bool GetWarningEvent(CFTDRtnWarningEventField &warningevent)
		{
			return m_listWarningEvent.get(warningevent);
		}

	/* */
	private:
		//����������ʽ
		void RunExprs(list<CEventNodePaser *> &parser_list);

	/* */
	private:
		///XML�ĵ���ָ��
		CXMLDoc *m_pXMLDoc;

		///XML���ڵ�ָ��
		CXMLNode *m_pXMLRoot;

		///����XML�ļ���ָ��
		string	m_sXmlFile;

		///���ʽ�Ƿ�����
		bool m_bExprAvailable;

		///���͸�config�ĸ澯�¼�����
		TemplateMutexCatch<CFTDRtnWarningEventField> m_listWarningEvent;

	/* */
	public:
		TemplateMutexMap<string, string> m_mapWarningEventExpr;

		///�澯�¼���Ӧ�ĵĸ澯��ϸ��Ϣ
		TemplateMutexMap<string, string> m_mapWarningInfo;
};

int getTimeFromStr(char *pdate, char *ptime);

string	transformStr(string oristr);
#endif // REF_CEXPRANALYSIS_H
