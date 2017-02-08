/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CStatusAnalysis.h
///@brief	������ҵ��״̬��������
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#ifndef REF_CSTATUSANALYSIS_H
#define REF_CSTATUSANALYSIS_H

#include "public.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "FtdData.h"
#include "CachedFileFlow.h"
#include "systools.h"
#include <iostream>
#include "EventFrontServer.h"

typedef list<int> StringList;

class CDataCenter :
	public CDataCenterManage
{
	/* */
	public:
		CDataCenter(void) :
		CDataCenterManage()
		{
		}

		///��ʼ������
		bool init(char *pszCfgPath);

		///���õ�ǰ�Ŷӻ�����״̬
			///@param	objectId	����ID
			///@param	itemId	����ID
		void setDataCenter(int objectId, int itemId);

		///ȡ��ǰ���������ĵ�����
		const char	*getDataCenter(void);

		///ȡָ�����͵Ľ�������
		list<int> &getAppIdList(const char *pAppName)
		{
			map<string, StringList>::iterator it = m_mapAppType.find(
					string(pAppName));
			if (it != m_mapAppType.end())
			{
				return it->second;
			}
			else
			{
				return m_tmpList;
			}
		}

		void print(void);

	/* */
	private:
		///����ÿ����������ͬ�����ͽ����б�
		map<string, StringList> m_mapAppType;
		map<int, string> m_mapCenterName;
		list<int> m_tmpList;
		int m_mCompositor;
		int m_mIsActiveId;
};

/////////////////////////////////////////////////////////////////////////
///CStatKey������map����ؼ��ֵ���
///@author	�ܽ���
///@version	1.0,20080701
/////////////////////////////////////////////////////////////////////////
class CStatKey
{
	/* */
	public:
		///ҵ�������
		int m_mObjectNum;

		///ҵ�����Եı��
		int m_mItemNum;

	/* */
	public:

		///���캯��
			///@param	objectNum	ҵ�����ı��
			///@param	itemNum	ҵ�����Եı��
		CStatKey(int objectNum, int itemNum)
		{
			m_mItemNum = itemNum;
			m_mObjectNum = objectNum;
		}

		CStatKey(const CStatKey &ob)
		{
			m_mItemNum = ob.m_mItemNum;
			m_mObjectNum = ob.m_mObjectNum;
		}

		void operator=(const CStatKey &ob)
		{
			m_mItemNum = ob.m_mItemNum;
			m_mObjectNum = ob.m_mObjectNum;
		}

		///����>�����
		friend bool operator>(const CStatKey &ob1, const CStatKey &ob2)
		{
			if (ob1.m_mObjectNum > ob2.m_mObjectNum)
			{
				return true;
			}
			else if (ob1.m_mObjectNum == ob2.m_mObjectNum)
			{
				if (ob1.m_mItemNum > ob2.m_mItemNum)
				{
					return true;
				}
			}

			return false;
		}

		///����<�����
		friend bool operator < (const CStatKey &ob1, const CStatKey &ob2)
		{
			if (ob1.m_mObjectNum < ob2.m_mObjectNum)
			{
				return true;
			}
			else if (ob1.m_mObjectNum == ob2.m_mObjectNum)
			{
				if (ob1.m_mItemNum < ob2.m_mItemNum)
				{
					return true;
				}
			}

			return false;
		}

		///����==�����
		friend bool operator==(const CStatKey &ob1, const CStatKey &ob2)
		{
			if ((ob1.m_mItemNum == ob2.m_mItemNum)
			&&	(ob1.m_mObjectNum == ob2.m_mObjectNum))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		///�������
		friend ostream &operator<<(ostream &output, CStatKey &ob)
		{
			output <<
				"m_mObjectNum: " <<
				ob.m_mObjectNum <<
				" m_mItemNum: " <<
				ob.m_mItemNum;
			return output;
		}
};

/////////////////////////////////////////////////////////////////////////
///CStatKey������map����ֵ����
///@author	�ܽ���
///@version	1.0,20080701
/////////////////////////////////////////////////////////////////////////
class CStatValue
{
	/* */
	public:
		///�������յ�������ָ��ֵ����
		int m_num;

		///����ָ��ļ��ʱ��
		int m_monTime;

		///�������ڵĿ�ʼʱ��
		int m_startTime;

		///�������ڵĽ���ʱ��
		int m_endTime;

		///��ָ��ֵ����������
		int m_valueType;

		///�������յ��ĵ�һ��ֵ
		double	m_fstValue;

		///�������յ������һ��ֵ
		double	m_endValue;

		///�������յ�������ֵ��ƽ��ֵ
		double	m_avgValue;

		///�������յ�����Сֵ
		double	m_minValue;

		///�������յ������ֵ
		double	m_maxValue;

		///��ʱ����ͳ�����ݱ�־
		int m_flag;

		///��ض���ID
		int m_objectId;

		///���ָ��ID
		int m_itemId;

	/* */
	public:

		///���캯��
		CStatValue(void)
		{
			m_flag = 0;
		}

		///���캯��
			///@param	monTime	���ָ��Ĳɼ�ʱ�䣬time_t����
			///@param	valueType	���ָ��ֵ�����ͣ�����Ϊ�ַ���
			///@param	pValue	���ָ���ֵ
		CStatValue(
			int monTime,
			int valueType,
			char *pValue,
			int objectId,
			int itemId);

		///�������캯��
		CStatValue(const CStatValue &ob);

		///���ء�=�������
		void operator=(const CStatValue &ob)
		{
			m_num = ob.m_num;
			m_startTime = ob.m_startTime;
			m_monTime = ob.m_monTime;
			m_endTime = ob.m_endTime;
			m_valueType = ob.m_valueType;
			m_fstValue = ob.m_fstValue;
			m_endValue = ob.m_endValue;
			m_avgValue = ob.m_avgValue;
			m_maxValue = ob.m_maxValue;
			m_minValue = ob.m_minValue;
			m_flag = ob.m_flag;
			m_objectId = ob.m_objectId;
			m_itemId = ob.m_itemId;
		}

		///����ָ��ֵ����
			///@param	monTime	���ָ��Ĳɼ�ʱ�䣬time_t����
			///@param	valueType	���ָ��ֵ�����ͣ�����Ϊ�ַ���
			///@param	pValue	���ָ���ֵ
		bool addAttrValue(
				int monTime,
				int valueType,
				char *pValue,
				int objectId,
				int itemId,
				CListHistoryObjectAttrField &cListHistoryObjectAttr);

		///����ͳ�ƺ���������һ��ʱ��û���µ�״̬�ﵽ��ͳ��ɾ����ֵ
		bool periodStatus(
				int now,
				CListHistoryObjectAttrField &cListHistoryObjectAttr);
		friend ostream &operator <<(ostream &output, CStatValue &ob);
};

/////////////////////////////////////////////////////////////////////////
///CStatusStat������ҵ��״̬�������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CStatusStat
{
	/* */
	public:
		///���캯��
			///@param	pConfigFile	SystemConfig.xml�����ļ�·��
		CStatusStat(char *pConfigFile);

		///״̬ͳ�Ʒ�������
			///@param	objectId	����ID���
			///@param	attrId	����ID���
			///@param	monTime	ָ��ɼ���ʱ��
			///@param	valueType	ָ��ֵ�����ͣ����Ϊ�ַ������;Ͳ�ͳ�Ʒ���
			///@param	pValue	ָ��ֵ�ַ���
		void addAttrStat(
		int objectId,
		int attrId,
		int monTime,
		int valueType,
		char *pValue)
		{
			if (valueType <= STRING_ATTR)
			{
				return;
			}

			m_it = m_mapStat.find(CStatKey(objectId, attrId));
			if (m_it != m_mapStat.end())	///����ָ���Ѿ����ڣ���������ָ�꺯��
			{
				m_it->second.addAttrValue(
						monTime,
						valueType,
						pValue,
						objectId,
						attrId,
						m_cListHistoryObjectAttr);
			}
			else
			{
				m_mapStat[CStatKey(objectId, attrId)] = CStatValue(
						monTime,
						valueType,
						pValue,
						objectId,
						attrId);
			}
		}

		///��ʱͳ�Ʒ�������
		void periodStats(void);

		///��ӡ�������
		void Print(void)
		{
#ifdef PRINT_DEBUG
			for (m_it = m_mapStat.begin(); m_it != m_mapStat.end(); m_it++)
			{
				cout << (CStatKey &)m_it->first << endl;
				cout << (CStatValue &)m_it->second << endl;
			}

#endif
		}

	/* */
	private:
		///����ļ�ض����ַ���
		map<CStatKey, CStatValue> m_mapStat;
		map<CStatKey, CStatValue>::iterator m_it;

	/* */
	public:
		// ��������δд�뵽������ʷ��ֵ����
		CListHistoryTradePeakField	m_cListTradePeak;

		// ��������δд�뵽������ʷK��ͳ�����ݶ���
		CListHistoryObjectAttrField m_cListHistoryObjectAttr;
		multimap<CStatKey, CFTDRtnHistoryTradePeakField> m_mapPeak;
};
#endif // REF_CSTATUSANALYSIS_H
