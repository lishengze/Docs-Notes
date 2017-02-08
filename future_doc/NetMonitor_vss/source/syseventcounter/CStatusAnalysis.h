/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CStatusAnalysis.h
///@brief	定义了业务状态分析的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
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

		///初始化函数
		bool init(char *pszCfgPath);

		///设置当前排队机工作状态
			///@param	objectId	对象ID
			///@param	itemId	属性ID
		void setDataCenter(int objectId, int itemId);

		///取当前主数据中心的名称
		const char	*getDataCenter(void);

		///取指定类型的进程名称
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
		///保存每个数据中心同种类型进程列表
		map<string, StringList> m_mapAppType;
		map<int, string> m_mapCenterName;
		list<int> m_tmpList;
		int m_mCompositor;
		int m_mIsActiveId;
};

/////////////////////////////////////////////////////////////////////////
///CStatKey定义了map对象关键字的类
///@author	周建军
///@version	1.0,20080701
/////////////////////////////////////////////////////////////////////////
class CStatKey
{
	/* */
	public:
		///业务对象编号
		int m_mObjectNum;

		///业务属性的编号
		int m_mItemNum;

	/* */
	public:

		///构造函数
			///@param	objectNum	业务对象的编号
			///@param	itemNum	业务属性的编号
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

		///重载>运算符
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

		///重载<运算符
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

		///重载==运算符
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

		///重载输出
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
///CStatKey定义了map对象值的类
///@author	周建军
///@version	1.0,20080701
/////////////////////////////////////////////////////////////////////////
class CStatValue
{
	/* */
	public:
		///本周期收到的属性指标值个数
		int m_num;

		///最新指标的监控时间
		int m_monTime;

		///本次周期的开始时间
		int m_startTime;

		///本次周期的结束时间
		int m_endTime;

		///本指标值的数据类型
		int m_valueType;

		///本周期收到的第一个值
		double	m_fstValue;

		///本周起收到的最后一个值
		double	m_endValue;

		///本周期收到的所有值得平均值
		double	m_avgValue;

		///本周期收到的最小值
		double	m_minValue;

		///本周期收到的最大值
		double	m_maxValue;

		///定时产生统计数据标志
		int m_flag;

		///监控对象ID
		int m_objectId;

		///监控指标ID
		int m_itemId;

	/* */
	public:

		///构造函数
		CStatValue(void)
		{
			m_flag = 0;
		}

		///构造函数
			///@param	monTime	监控指标的采集时间，time_t类型
			///@param	valueType	监控指标值的类型，不能为字符串
			///@param	pValue	监控指标的值
		CStatValue(
			int monTime,
			int valueType,
			char *pValue,
			int objectId,
			int itemId);

		///拷贝构造函数
		CStatValue(const CStatValue &ob);

		///重载“=”运算符
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

		///增加指标值函数
			///@param	monTime	监控指标的采集时间，time_t类型
			///@param	valueType	监控指标值的类型，不能为字符串
			///@param	pValue	监控指标的值
		bool addAttrValue(
				int monTime,
				int valueType,
				char *pValue,
				int objectId,
				int itemId,
				CListHistoryObjectAttrField &cListHistoryObjectAttr);

		///周期统计函数，超过一定时间没有新的状态达到就统计删除该值
		bool periodStatus(
				int now,
				CListHistoryObjectAttrField &cListHistoryObjectAttr);
		friend ostream &operator <<(ostream &output, CStatValue &ob);
};

/////////////////////////////////////////////////////////////////////////
///CStatusStat定义了业务状态处理的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CStatusStat
{
	/* */
	public:
		///构造函数
			///@param	pConfigFile	SystemConfig.xml配置文件路径
		CStatusStat(char *pConfigFile);

		///状态统计分析函数
			///@param	objectId	对象ID编号
			///@param	attrId	属性ID编号
			///@param	monTime	指标采集的时间
			///@param	valueType	指标值的类型，如果为字符串类型就不统计分析
			///@param	pValue	指标值字符串
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
			if (m_it != m_mapStat.end())	///对象指标已经存在，调用增加指标函数
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

		///定时统计分析函数
		void periodStats(void);

		///打印输出函数
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
		///保存的监控对象字符串
		map<CStatKey, CStatValue> m_mapStat;
		map<CStatKey, CStatValue>::iterator m_it;

	/* */
	public:
		// 保存所有未写入到流的历史峰值对象
		CListHistoryTradePeakField	m_cListTradePeak;

		// 保存所有未写入到流的历史K线统计数据对象
		CListHistoryObjectAttrField m_cListHistoryObjectAttr;
		multimap<CStatKey, CFTDRtnHistoryTradePeakField> m_mapPeak;
};
#endif // REF_CSTATUSANALYSIS_H
