/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CStatusAnalysis.cpp
///@brief	实现了业务状态分析的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#include "CStatusAnalysis.h"
#include "EventCounterServer.h"
#include "databaseData.h"
#include "CMsgGenerator.h"

extern CStringIdMap g_mStringIdMap;
extern int	g_mKLineStatPeriod;
extern CMsgGenerator g_MsgGenerator;

bool CDataCenter::init(char *pszCfgPath)
{
	XMLInit(pszCfgPath);
	for (map<string, string>::iterator it = m_mapAppIdType.begin();
		 it != m_mapAppIdType.end();
		 it++)
	{
		// it->first : PuDian.app.tkernel.1
		// string a=Pudian.app.tkernel,b=PuDian.app.tkernel.1 ;
		char temp[64];
		strcpy(temp, it->first.c_str());

		char *p = strchr(temp, '.');
		if (p)
		{
			p++;
		}
		else
		{
			continue;
		}

		p = strchr(p, '.');
		if (p)
		{
			p++;
		}
		else
		{
			continue;
		}

		if (*p == 'o')
		{
			continue;
		}

		p = strchr(p, '.');
		if (p)
		{
			p++;
		}
		else
		{
			continue;
		}

		p = strchr(p, '.');
		if (p)
		{
			*p = '\0';
		}

		map<string, StringList>::iterator mit;
		mit = m_mapAppType.find(temp);
		if (mit != m_mapAppType.end())	// 应用类进程已存在,只需要增加指标
		{
			mit->second.push_back(
					g_mStringIdMap.getStringId(it->first.c_str()));
		}
		else
		{
			list<int> lp;
			lp.push_back(g_mStringIdMap.getStringId(it->first.c_str()));
			m_mapAppType[string(temp)] = lp;
		}

		if ((p = strstr(temp, APP_COMPOSITOT)) != NULL)
		{
			p--;
			*p = '\0';
			m_mapCenterName[g_mStringIdMap.getStringId(
					it->first.c_str())] = string(temp);
		}
	}

	m_mIsActiveId = g_mStringIdMap.getStringId(APPATTRISACTIVE);
	return true;
}

void CDataCenter::setDataCenter(int objectId, int itemId)
{
	if (itemId != m_mIsActiveId)
	{
		return;
	}

	map<int, string>::iterator	it = m_mapCenterName.find(objectId);
	if (it == m_mapCenterName.end())
	{
		return;
	}

	m_mCompositor = objectId;
}

const char *CDataCenter::getDataCenter(void)
{
	return m_mapCenterName[m_mCompositor].c_str();
}

void CDataCenter::print(void)
{
	map<string, StringList>::const_iterator it = m_mapAppType.begin();
	while (it != m_mapAppType.end())
	{
		StringList::const_iterator	listIt = it->second.begin();
		while (listIt != it->second.end())
		{
			printf(
				"[%s][%d][%s]\n",
				it->first.c_str(),
				*listIt,
				g_mStringIdMap.getString(*listIt));
			listIt++;
		}

		it++;
	}

	map<int, string>::const_iterator cit = m_mapCenterName.begin();
	while (cit != m_mapCenterName.end())
	{
		printf(
			"compositor id [%d] value [%s]\n",
			cit->first,
			cit->second.c_str());
		cit++;
	}
}

ostream &operator<<(ostream &output, CStatValue &ob)
{
	output <<
		" m_num:" <<
		ob.m_num <<
		" m_valueType:" <<
		ob.m_valueType <<
		" m_startTime:" <<
		ob.m_startTime <<
		" m_endTime:" <<
		ob.m_endTime <<
		" m_monTime:" <<
		ob.m_monTime <<
		" m_fstValue:" <<
		ob.m_fstValue <<
		" m_avgValue:" <<
		ob.m_avgValue <<
		" m_minValue:" <<
		ob.m_minValue <<
		" m_maxValue:" <<
		ob.m_maxValue <<
		" m_endValue:" <<
		ob.m_endValue <<
		" m_objectId:" <<
		ob.m_objectId <<
		" m_itemId:" <<
		ob.m_itemId <<
		" m_flag:" <<
		ob.m_flag;
	return output;
}

CStatValue::CStatValue(
	int monTime,
	int valueType,
	char *pValue,
	int objectId,
	int itemId)
{
	m_num = 1;
	m_valueType = valueType;
	m_monTime = monTime;
	m_startTime = monTime - monTime % g_mKLineStatPeriod;
	m_endTime = monTime - monTime % g_mKLineStatPeriod + g_mKLineStatPeriod;
	m_fstValue = atof(pValue);
	m_endValue = m_fstValue;
	m_avgValue = m_fstValue;
	m_minValue = m_fstValue;
	m_maxValue = m_fstValue;
	m_flag = 0;
	m_objectId = objectId;
	m_itemId = itemId;
}

///拷贝构造函数
CStatValue::CStatValue(const CStatValue &ob)
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

bool CStatValue::addAttrValue(
	int monTime,
	int valueType,
	char *pValue,
	int objectId,
	int itemId,
	CListHistoryObjectAttrField &cListHistoryObjectAttr)
{
	/// 为及时产生成交汇总信息,将指标统计区段由[00-59)调整为[01-60)
	if (monTime < m_startTime)
	{
		return false;
	}
	else if (monTime > m_endTime)	///产生一个新的k线数据
	{
		///输出K线数据
		m_avgValue = m_avgValue / (double)m_num;

		CFTDRtnHistoryObjectAttrField fieldInfo;
		fieldInfo.ObjectID = g_mStringIdMap.getString(objectId);
		fieldInfo.AttrType = g_mStringIdMap.getString(itemId);
		fieldInfo.ValueCount = m_num;
		fieldInfo.ValueType = m_valueType;
		fieldInfo.MonDate = getStrFromDate(m_startTime);
		fieldInfo.BeginTime = getStrFromTime(m_startTime);
		fieldInfo.EndTime = getStrFromTime(m_endTime);
		fieldInfo.FirstValue = m_fstValue;
		fieldInfo.AvgValue = m_avgValue;
		fieldInfo.MinValue = m_minValue;
		fieldInfo.MaxValue = m_maxValue;
		fieldInfo.EndValue = m_endValue;

		cListHistoryObjectAttr.WriteValue(fieldInfo);
		g_MsgGenerator.AddObjectAttr(fieldInfo);

		m_num = 1;
		m_valueType = valueType;
		m_monTime = monTime;
		m_startTime = monTime - monTime % g_mKLineStatPeriod + 1;	//统计区段由[00-59)调整为[01-60)
		m_endTime = monTime - monTime % g_mKLineStatPeriod + g_mKLineStatPeriod;
		m_fstValue = atof(pValue);
		m_endValue = m_fstValue;
		m_avgValue = m_fstValue;
		m_minValue = m_fstValue;
		m_maxValue = m_fstValue;
		if (m_flag)
		{
			m_flag = 0;
		}
	}

	/// Mod by Henchi, 20121211
		/// 修正源码中的逻辑错误
	else	// m_startTime < monTime <= m_endTime
	{
		m_monTime = monTime;
		m_num++;

		double	tmp = atof(pValue);

		m_avgValue = m_avgValue + tmp;
		m_minValue = m_minValue > tmp ? tmp : m_minValue;
		m_maxValue = m_maxValue > tmp ? m_maxValue : tmp;
		m_endValue = tmp;
	}

	return true;
}

bool CStatValue::periodStatus(
	int now,
	CListHistoryObjectAttrField &cListHistoryObjectAttr)
{
	if (m_endTime >= (now - g_mKLineStatPeriod))
	{
		return false;
	}

	m_flag++;
	if (m_flag >= 2)
	{
		if (m_num == 0)
		{
			//魏诚add, 20120202
			//周期内无任何数据产生，不输出K线
			return false;
		}

		///输出K线数据
		m_avgValue = m_avgValue / (double)m_num;

		CFTDRtnHistoryObjectAttrField fieldInfo;
		fieldInfo.ObjectID = g_mStringIdMap.getString(m_objectId);
		fieldInfo.AttrType = g_mStringIdMap.getString(m_itemId);
		fieldInfo.ValueCount = m_num;
		fieldInfo.ValueType = m_valueType;
		fieldInfo.MonDate = getStrFromDate(m_startTime);
		fieldInfo.BeginTime = getStrFromTime(m_startTime);
		fieldInfo.EndTime = getStrFromTime(m_endTime);
		fieldInfo.FirstValue = m_fstValue;
		fieldInfo.AvgValue = m_avgValue;
		fieldInfo.MinValue = m_minValue;
		fieldInfo.MaxValue = m_maxValue;
		fieldInfo.EndValue = m_endValue;

		cListHistoryObjectAttr.WriteValue(fieldInfo);

		m_num = 0;
		m_startTime = m_startTime + g_mKLineStatPeriod;
		m_endTime = m_endTime + g_mKLineStatPeriod;
		m_fstValue = 0.0;
		m_endValue = 0.0;
		m_avgValue = 0.0;
		m_minValue = 0.0;
		m_maxValue = 0.0;
		return true;
	}

	return false;
}

CStatusStat::CStatusStat(char *pConfigFile)
{
	CXMLDoc *pXMLDoc = NULL;
	CXMLNode *pXMLRoot = NULL;
	XMLNodeType NodeType = XMLTag;
	pXMLDoc = new CXMLDoc();
	pXMLDoc->read(pConfigFile);
	pXMLRoot = pXMLDoc->getRootNode();

	CFTDRtnHistoryTradePeakField peakField;

	memset(&peakField, 0, sizeof(peakField));

	CXMLNode *pServiceNode = pXMLRoot->findNode(NodeType, "Peaks", NULL, NULL);
	CXMLNodeList *pNodeList = pServiceNode->getNodeList();
	CXMLNode *pNode = (*pNodeList)[0];
	for (int i = 0; i < pNodeList->size(); i++)
	{
		CXMLNode *pNodeCur = (*pNodeList)[i];
		printf("\t%s \n", pNodeCur->findProperty("app"));
		printf("\t%s \n", pNodeCur->findProperty("Attr"));
		printf("\t%s \n", pNodeCur->findProperty("RltAttr"));
		peakField.ObjectID = pNodeCur->findProperty("app");
		peakField.AttrType = pNodeCur->findProperty("Attr");
		peakField.RltAttrType = pNodeCur->findProperty("RltAttr");
		peakField.MaxAttrValue = g_mStringIdMap.getStringId(
				pNodeCur->findProperty("Attr"));	///历史最大值保存监控对象的指标ID
		peakField.MaxRltAttrValue = g_mStringIdMap.getStringId(
				pNodeCur->findProperty("RltAttr")); ///历史最大值对应的相关指标值保存监控对象的相关指标ID
		peakField.OldRltAttrValue = g_mStringIdMap.getStringId(
				pNodeCur->findProperty("app"));		///次新值的相关属性值保存app对象的ID
		m_mapPeak.insert(
				make_pair(
					CStatKey(
							g_mStringIdMap.getStringId(
									pNodeCur->findProperty("app")),
							g_mStringIdMap.getStringId(
									pNodeCur->findProperty("Attr"))),
					peakField));
	}

	fflush(stdout);
}

extern double getItemValue(
				int mObjectId,
				int mAttrId,
				char *pDate,
				char *pTime);

///定时统计分析函数
void CStatusStat::periodStats(void)
{
	int now = time((time_t *)NULL);
	for (m_it = m_mapStat.begin(); m_it != m_mapStat.end();)
	{
		if (m_it->second.periodStatus(now, m_cListHistoryObjectAttr))
		{
			m_mapStat.erase(m_it++);
		}
		else
		{
			m_it++;
		}
	}

	for (multimap<CStatKey, CFTDRtnHistoryTradePeakField>::iterator mit =
			 m_mapPeak.begin();
	 mit != m_mapPeak.end();
		 mit++)
	{
		if (mit->second.OldAttrValue.getValue() == 1.0)
		{
			mit->second.RltAttrValue = getItemValue(
					(int)mit->second.OldRltAttrValue.getValue(),
					(int)mit->second.MaxRltAttrValue.getValue(),
					(char *)(mit->second.MonDate.getValue()),
					(char *)(mit->second.MonTime.getValue()));

			m_cListTradePeak.WriteValue(
					(CFTDRtnHistoryTradePeakField &) (mit->second));
			if (mit->second.RltAttrValue >= 0.0)
			{
				mit->second.OldAttrValue = 0.0;
			}
			else
			{
				printf("没有找到相关指标对应的指标值\n");
				fflush(stdout);
			}
		}
	}
}
