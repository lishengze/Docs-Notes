/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CExprAnalysis.cpp
///@brief	 实现了事件计算的类
///@history
///20080610	周建军		创建该文件
///20080623	周建军		修订注释
///20080908 郭鹏		添加MDB对配置文件的参数载入
///20091214	周建军		变更号:MS-0001 （使表达式支持工作日判断函数，增加了IsWorkingDay函数）
///20091218	周建军		增加延迟计算告警设置，可以解决每次系统重新启动时发出HostNotActive告警
#include "inputStream.h"
#include "inputToken.h"
#include "CExprParser.h"
#include "databaseData.h"
#include "CExprAnalysis.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "FtdData.h"
#include "CachedFileFlow.h"
#include "EventCounterServer.h"
#include "CStatusAnalysis.h"
#include "BaseDataStruct.h"
#include "PrjCommon.h"
#include "CCalendar.h"

#define EVENT_TOKEN_FLAGS " \t,;=<>()[]{}\'\""

class CCalendar;

//#pragma warning(once:4244)
// 必须的外部全局变量，这些是只读的，不需要加锁 20090612

extern int g_iTimeZoneOffset;				// 当前系统时区与标准时区偏移秒数（东8区为28800）
extern int g_mMonitorTime;						// Active间隔次数
extern const char *INI_FILE_NAME;
extern CConfig	*currentConfig;					//用于内存数据库相关INI内容载入
extern CDataCenter	*g_pDataCenter;
extern CListWarningEventField *g_pListEvent;	// 保存所有未写入到流的告警事件
extern CEventProcess g_cEventProcess;			///全局告警更新处理对象
extern map<string, string>	g_DevIPList;
extern int	g_mConfigControlEvent;
extern CWarningEventManager g_warningEventManager;
extern int	g_warningeventdelaytime;
extern map<string, int> g_mNoNightTradingDays;  //没有夜盘的交易日 

//本地一次性构造该map，构造完之后给外部使用，如只是在一个线程内使用不需要加锁 20090612
///@key	事件名称
///@value	事件的级别
map<string, string> g_mapEventLevel;

/// Added by Henchi, 20120228
//本地一次性构造该map，构造完之后给外部使用，如只是在一个线程内使用不需要加锁
///@key	事件英文名称,如:HostNotActive
///@value	事件的全名,如:主机不活跃
map<string, string> g_mapEventFullName;

//本地一次性构造该map，构造完之后给外部使用，如只是在一个线程内使用不需要加锁
///@key	事件英文名称,如:HostNotActive
///@value	事件的描述,如:未接收到主机的活跃信息
map<string, string> g_mapEventDesc;

//本地定义的全局变量，外部也需要使用，该对象仅在CMdbThread线程使用，不需要加锁 20090612
CMemoryDB *g_mExprDB = NULL;
CStringIdMap g_mStringIdMap;

extern CCalendar g_calender;

///保存分析表达式的列表
TOperatorLine g_mOperators[] =
{
	{ BI_OPERATOR_LEFT, "&& & || |" },
	{ BI_OPERATOR_LEFT, "== >= > < <= !=" },
	{ BI_OPERATOR_LEFT, "+ -" },
	{ BI_OPERATOR_LEFT, "* /" },
	{ BI_OPERATOR_RIGHT, "**" },
	{ UNI_OPERATOR_LEFT, "! - @ # $ ^@ ^# ^$" }
};
#define OPERATOR_LINE_COUNT (sizeof(g_mOperators) / sizeof(TOperatorLine))

CExprParser<CValue> g_mEventParser(g_mOperators, OPERATOR_LINE_COUNT);

///保存每次计算一个告警需要的所有值字符串列表
list<string> g_warningInfoList;

CContext *g_pContext = NULL;

//仅本地需要的全局变量 20090612
bool g_bValueExist = true;
int g_mAlert = 120; // 计算最近时间之内的监控指标
int g_mEventId = 1; // 当日事件发生的ID编号，递增不重复
const char	*g_mFuncSeperator[] = { "()", "[]", "{}" };

const char	*g_mKeywords[] = { "now", "today", "date", "time", NULL };
CCharSetForLetterDigitDotUnderLineColonPtr	g_mCharSetIden = new
	CCharSetForLetterDigitDotUnderLineColon();

///getItemValue函数,取监控指标的值
///@param	result	保存函数计算结果值
///@param	monitorObject	监控对象的ID
///@param	monitorItem	监控指标的ID
///@param	monitorTime	监控的时间
///@return	返回监控指标是否取得成功，true表示成功，false表示失败
double CContext::getItemValue(
	int monitorObject,
	int monitorItem,
	int monitorTime)
{
	CMonitorEntity	*pMonitorEntity;
	pMonitorEntity = g_mExprDB->m_MonitorEntityFactory->findByKey(
			monitorObject,
			monitorItem,
			monitorTime);

	if (pMonitorEntity != NULL)
	{
		return atof(pMonitorEntity->AttrValue.getValue());
	}
	else
	{
		g_bValueExist = false;
		return -1.0;
	}
}

///getItemValue函数,取监控指标的值
///@param	result	保存函数计算结果值
///@param	monitorObject	监控对象的ID
///@param	monitorItem	监控指标的ID
///@param	monitorTime	监控的时间
///@return	返回监控指标是否取得成功，true表示成功，false表示失败
bool CContext::getItemValue(
	CValue	&result,
	int monitorObject,
	int monitorItem,
	int monitorNow)
{
	CMonitorEntity	*pMonitorEntity;
	pMonitorEntity = g_mExprDB->m_MonitorEntityFactory->findByKey(
			monitorObject,
			monitorItem,
			monitorNow);

	if (pMonitorEntity != NULL)
	{
		result.setValue(
				pMonitorEntity->MonitorTime,
				pMonitorEntity->AttrValue.getValue(),
				pMonitorEntity->ValueType);
		RECORDWARNINGINFO_ATTR;
		return true;
	}
	else
	{
		RECORDWARNINGINFO_NOATTR;
		return false;
	}
}

///getLastedItemValue函数,取监控指标最新的值(@)
///@param	result	保存函数计算结果值
///@param	monitorObject	监控对象的ID
///@param	monitorItem	监控指标的ID
///@param	monitorTime	返回监控的时间
///@return	返回监控指标是否取得成功，true表示成功，false表示失败
bool CContext::getLastedItemValue(
	CValue	&result,
	int monitorObject,
	int monitorItem,
	int monitorNow,
	int &monitorTime)
{
	CMonitorEntity	*pMonitorEntity;

	pMonitorEntity = g_mExprDB->m_MonitorEntityFactory->startFindByTime(
			monitorObject,
			monitorItem,
			monitorNow);
	if (pMonitorEntity)
	{
		monitorTime = pMonitorEntity->MonitorTime;
		g_mExprDB->m_MonitorEntityFactory->endFindByTime();
		result.setValue(
				pMonitorEntity->MonitorTime,
				pMonitorEntity->AttrValue.getValue(),
				pMonitorEntity->ValueType);
		RECORDWARNINGINFO_ATTR;
		return true;

		//return  pMonitorEntity->MonitorValue;
	}

	g_mExprDB->m_MonitorEntityFactory->endFindByTime();
	monitorTime = -1;
	RECORDWARNINGINFO_NOATTR;
	return false;
}

///getLastedItemTime函数,取监控指标最新的值对应的时间
///@param	result	保存函数计算结果值
///@param	monitorObject	监控对象的ID
///@param	monitorItem	监控指标的ID
///@param	monitorTime	返回监控的时间
///@return	返回监控指标是否取得成功，true表示成功，false表示失败
bool CContext::getLastedItemTime(
	CValue	&result,
	int monitorObject,
	int monitorItem,
	int monitorNow,
	int &monitorTime)
{
	CMonitorEntity	*pMonitorEntity;

	pMonitorEntity = g_mExprDB->m_MonitorEntityFactory->startFindByTime(
			monitorObject,
			monitorItem,
			monitorNow);
	if (pMonitorEntity)
	{
		monitorTime = pMonitorEntity->MonitorTime;
		g_mExprDB->m_MonitorEntityFactory->endFindByTime();
		result.setDIntConstant(
				pMonitorEntity->MonitorTime,
				pMonitorEntity->MonitorTime);
		RECORDWARNINGINFO_ATTR;
		return true;

		//return  pMonitorEntity->MonitorValue;
	}

	g_mExprDB->m_MonitorEntityFactory->endFindByTime();
	monitorTime = -1;
	RECORDWARNINGINFO_NOATTR;
	return false;
}

///getNextItemValue函数,取监控指标上一次的值(#)
///@param	result	保存函数计算结果值
///@param	monitorObject	监控对象的ID
///@param	monitorItem	监控指标的ID
///@param	monitorTime	返回监控的时间
///@return	返回监控指标是否取得成功，true表示成功，false表示失败
bool CContext::getNextItemValue(
	CValue	&result,
	int monitorObject,
	int monitorItem,
	int monitorNow,
	int &monitorTime)
{
	CMonitorEntity	*pMonitorEntity;

	pMonitorEntity = g_mExprDB->m_MonitorEntityFactory->startFindByTime(
			monitorObject,
			monitorItem,
			monitorNow);
	if (pMonitorEntity)
	{
		pMonitorEntity = g_mExprDB->m_MonitorEntityFactory->findNextByTime();
		if (pMonitorEntity)
		{
			monitorTime = pMonitorEntity->MonitorTime;
			g_mExprDB->m_MonitorEntityFactory->endFindByTime();
			result.setValue(
					pMonitorEntity->MonitorTime,
					pMonitorEntity->AttrValue.getValue(),
					pMonitorEntity->ValueType);
			RECORDWARNINGINFO_ATTR;
			return true;

			//return  pMonitorEntity->MonitorValue;
		}
	}

	g_mExprDB->m_MonitorEntityFactory->endFindByTime();
	monitorTime = -1;
	RECORDWARNINGINFO_NOATTR;
	return false;
}

///getNextItemTime函数,取监控指标上一次的值对应的时间
///@param	result	保存函数计算结果值
///@param	monitorObject	监控对象的ID
///@param	monitorItem	监控指标的ID
///@param	monitorTime	返回监控的时间
///@return	返回监控指标是否取得成功，true表示成功，false表示失败
bool CContext::getNextItemTime(
	CValue	&result,
	int monitorObject,
	int monitorItem,
	int monitorNow,
	int &monitorTime)
{
	CMonitorEntity	*pMonitorEntity;

	pMonitorEntity = g_mExprDB->m_MonitorEntityFactory->startFindByTime(
			monitorObject,
			monitorItem,
			monitorNow);
	if (pMonitorEntity)
	{
		pMonitorEntity = g_mExprDB->m_MonitorEntityFactory->findNextByTime();
		if (pMonitorEntity)
		{
			monitorTime = pMonitorEntity->MonitorTime;
			g_mExprDB->m_MonitorEntityFactory->endFindByTime();
			result.setDIntConstant(
					pMonitorEntity->MonitorTime,
					pMonitorEntity->MonitorTime);
			RECORDWARNINGINFO_ATTR;
			return true;

			//return  pMonitorEntity->MonitorValue;
		}
	}

	g_mExprDB->m_MonitorEntityFactory->endFindByTime();
	monitorTime = -1;
	RECORDWARNINGINFO_NOATTR;
	return false;
}

///getCurrentItemValue函数,取监控指标指定时间以前的值($)
///@param	result	保存函数计算结果值
///@param	monitorObject	监控对象的ID
///@param	monitorItem	监控指标的ID
///@param	monitorTime	返回监控的时间
///@return	返回监控指标是否取得成功，true表示成功，false表示失败
bool CContext::getCurrentItemValue(
	CValue	&result,
	int monitorObject,
	int monitorItem,
	int &monitorNow,
	int timeVal)
{
	CMonitorEntity	*pMonitorEntity;

	pMonitorEntity = g_mExprDB->m_MonitorEntityFactory->startFindByTime(
			monitorObject,
			monitorItem,
			monitorNow - timeVal);
	if (pMonitorEntity)
	{
		g_mExprDB->m_MonitorEntityFactory->endFindByTime();
		result.setValue(
				pMonitorEntity->MonitorTime,
				pMonitorEntity->AttrValue.getValue(),
				pMonitorEntity->ValueType);
		RECORDWARNINGINFO_ATTR;
		return true;

		//return  pMonitorEntity->MonitorValue;
	}

	g_mExprDB->m_MonitorEntityFactory->endFindByTime();
	monitorNow = -1;
	RECORDWARNINGINFO_NOATTR;
	return false;
}

class CEventNodePaser
{
	/* */
	private:
		///保存产生事件的名称
		string	m_mEventName;

		///保存产生事件的完整名称
		string	m_mFullName;

		///保存产生事件的级别
		string	m_mEventLevel;

		///保存事件的描述信息
		string	m_mDescription;

		///供客户端统计使用的事件序列号
		int m_mEventSeries;

		///放弃计算时间
		int m_mGiveupTime;

		///事件计算周期
		int m_mInterval;

		///最后一次事件产生时间
		int m_mBirthTime;

		///最后一次用状态计算事件的时间
		int m_mCountNow;

		///最后一次获取到计算结果的时间,不区分是否产生事件
		int m_mResultNow;

		///最后从内存数据库中取出的计算时产生的最大时间
		int m_mDbTime;

		///计算对象的ID
		int m_mMonitorObject;

		///对象指标的ID
		int m_mMonitorItem;

		///保存计算公式产生的计算节点指针
		CExprNode<CValue> *m_pExpr;

		///保存输入流
		CInputStreamPtr m_pStream;

	/* */
	public:
		///保存需要分析的字符串表达式
		string	m_mExprString;

		///指标的类型，如app、os
		string	m_mItemType;

	/* */
	public:
		///构造函数
			///@param	pEventName	满足条件时产生的事件名称
			///@param	pFullName	满足条件时产生的完整事件名称
			///@param	pEventLevel	产生的事件所属的告警级别
			///@param	pControl	使用的控制公式
			///@param	mGiveupTime	放弃计算时间,为0表示始终计算
			///@param	mInterval	计算的周期
			///@param	pUsing	计算使用的公式
			///@param	theParser	公式使用的解析器
			///@param	pObjectId	告警对象的ID
			///@param	pObjectItem	告警对象的指标
		CEventNodePaser(
			char *pEventName,
			char *pFullName,
			char *pEventLevel,
			char *pDesc,
			char *pControl,
			int mGiveupTime,
			int mInterval,
			char *pUsing,
			CExprParser<CValue> &theParser,
			char *pObjectId,
			char *pObjectItem,
			char *pItemType);

		///析构函数
		~CEventNodePaser(void)
		{
		}

		///表达式求值函数
			///@param	eventField	保存新事件的域
			///@return	返回事件计算结果,true表示已经产生新的事件,false不产生
		bool Evaluation(CFTDRtnWarningEventField &eventField);

		///表达式测试函数
			///@return	返回事件测试结果,true表示测试通过,false表示测试未通过
		bool TestExpr(void);
};

list<CEventNodePaser *> g_pPaserList;	///保存所有的表示分析器指针
list<CEventNodePaser *> g_pCfgPaserList;					///保存来自文件的分析器指针
CMutex	g_cParseListMutex;

#ifdef PRINT_DEBUG
list<string> g_mBiaodashiList;								///保存所有的计算表达式,对应g_pPaserList
#endif
CExprAnalysis::CExprAnalysis(char *pEventCfgFile)
{
	g_pContext = new CContext((char *)INI_FILE_NAME);

	m_sXmlFile = pEventCfgFile;
	m_bExprAvailable = false;

	//for test
	/*
	map<int, map<string, int> > expr_device_list;
	std::map<int, CFTDRspQryNetEventExprField> exprs;

	generateObjectExpr(expr_device_list, exprs);
*/
	/*	map<string ,int> objid;
	objid["TRADE.Beijing.app.sysprobe"] = 1;

	map<string, map<string, int> > attr_devs;
	attr_devs["Active"] = objid;

	CFTDRspQryNetEventExprField expfield;

	expfield.ENAME = "HostNotActive";
	expfield.CONTROL = "nowbetween(\"08:10:00\",\"23:00:00\")";
	expfield.EXPR = "((^@Active < (now-300))&&(getSystemName(@)==\"TRADE\"))";
	expfield.GIVEUPTIME = 3;
	expfield.WarningLEVEL = "error";

	vector<CFTDRspQryNetEventExprField> exprs;
	exprs.push_back(expfield);

	generateObjectExpr(attr_devs, exprs);
*/
	//生成配置文件中的表达式
	list<string> mObjectIdList;
	g_pCfgPaserList.clear();

	//	g_pContext = new CContext((char *)INI_FILE_NAME);
	m_pXMLDoc = NULL;
	m_pXMLRoot = NULL;

	XMLNodeType NodeType = XMLTag;
	if (m_pXMLDoc == NULL)
	{
		m_pXMLDoc = new CXMLDoc();
		try
		{
			m_pXMLDoc->read(pEventCfgFile);
			m_pXMLRoot = m_pXMLDoc->getRootNode();

			// To be written on exit
			m_sXmlFile = pEventCfgFile;

			CXMLNode *pServiceNode = m_pXMLRoot->findNode(
					NodeType,
					"Events",
					NULL,
					NULL);
			CXMLNodeList *pNodeList = pServiceNode->getNodeList();
			if (pNodeList != NULL)
			{
				CXMLNode *pNode = (*pNodeList)[0];
				map<string, CObjectIdStatus>::iterator	mapIt;
				map<string, CObjectIdStatus> &appIdNameMap = g_pDataCenter->
					getAppIdNameMap();

				for (int i = 0; i < (int)pNodeList->size(); i++)
				{
					CXMLNode *pNodeCur = (*pNodeList)[i];
					printf("\nThe next expr %d:\n", i + 1);

					//printf("%s\n",__FUNCTION__);
#ifdef PRINT_DEBUG
					printf("\t%s \n", pNodeCur->findProperty(XML_EVENT_NAME));
					printf("\t%s \n", pNodeCur->findProperty(XML_EVENT_TYPE));
					printf(
						"\t%s \n",
						pNodeCur->findProperty(XML_EVENT_FULLNAME));
					printf("\t%s \n", pNodeCur->findProperty(XML_EVENT_LEVEL));
					printf(
						"\t%s \n",
						pNodeCur->findProperty(XML_EVENT_GIVEUPTIME));
					printf(
						"\t%s \n",
						pNodeCur->findProperty(XML_EVENT_CONTROL));
					printf("\t%s \n", pNodeCur->findProperty(XML_EVENT_EXPR));
					printf(
						"\t%s \n\n",
						pNodeCur->findProperty(XML_EVENT_COMMENT));
#endif

					string	mAttrStr;						///保存读取到的第一个指标名
					string	mObject;						///保存读取到的第一个监控对象名
					string	mExpr;							///保存完成的表达式字符串
					string	objectType =
						(
							pNodeCur->findProperty(
									XML_EVENT_TYPE) ? pNodeCur->findProperty(XML_EVENT_TYPE) : ""
						);
					string	objectId =
						(
							pNodeCur->findProperty(
									XML_EVENT_OBJECTID) ? pNodeCur->findProperty(
									XML_EVENT_OBJECTID) : ""
						);
					string	objectAttr =
						(
							pNodeCur->findProperty(
									XML_EVENT_OBJECTATTR) ? pNodeCur->findProperty(
									XML_EVENT_OBJECTATTR) : ""
						);
					g_mapEventLevel[string(
							pNodeCur->findProperty(XML_EVENT_NAME))] = string(pNodeCur->findProperty(XML_EVENT_LEVEL));
					g_mapEventFullName[string(
							pNodeCur->findProperty(XML_EVENT_NAME))] = string(pNodeCur->findProperty(XML_EVENT_FULLNAME));
					g_mapEventDesc[string(
							pNodeCur->findProperty(XML_EVENT_NAME))] = string(pNodeCur->findProperty(XML_EVENT_COMMENT));

					if (pNodeCur->findProperty(XML_EVENT_EXPR) == NULL)
					{
						continue;
					}

					if (getAttrFromExpr(
							mAttrStr,
						mObject,
						pNodeCur->findProperty(XML_EVENT_EXPR)))
					{
						mObjectIdList.clear();
						if (objectType == DATACENTERHOST)	// 操作系统类告警条件设置
						{
							for (mapIt = appIdNameMap.begin();
								 mapIt != appIdNameMap.end();
								 mapIt++)
							{
								if (strstr(mapIt->first.c_str(), ".os."))
								{
									char sOsId[80];

									char dOsId[80];
									strcpy(dOsId, mapIt->first.c_str());

									int m = 0;
									int n = strlen(dOsId);

									for (int j = 0; j < n; j++)
									{
										if (dOsId[j] == '-')
										{
											sOsId[m] = '\\';
											m += 1;
										}

										sOsId[m] = dOsId[j];
										m += 1;
									}

									sOsId[m] = '\0';

									// Mod by Henchi, 20090813
									string	OsId = sOsId;
									addObjectIdtoExpr(
										mExpr,
										OsId,
										pNodeCur->findProperty(
												XML_EVENT_EXPR));
									if (pNodeCur->findProperty(
											XML_EVENT_CONTROL)
								&&	(
											strcmp(
											pNodeCur->findProperty(
											XML_EVENT_CONTROL),
										"")
								))
									{
										mExpr.append(" && (");
										mExpr.append(
												pNodeCur->findProperty(
														XML_EVENT_CONTROL));
										mExpr.append(")");
									}

									CEventNodePaser *pPaser = new
										CEventNodePaser(
											pNodeCur->findProperty(
													XML_EVENT_NAME),
											pNodeCur->findProperty(
													XML_EVENT_FULLNAME),
											pNodeCur->findProperty(
													XML_EVENT_LEVEL),
											pNodeCur->findProperty(
													XML_EVENT_COMMENT),
											pNodeCur->findProperty(
													XML_EVENT_CONTROL),
											(
												pNodeCur->findProperty(
														XML_EVENT_GIVEUPTIME) ? atoi(
														pNodeCur->
															findProperty(
																	XML_EVENT_GIVEUPTIME)) : 0
											),
											(
												pNodeCur->findProperty(
														XML_EVENT_INTERVAL) ? atoi(
														pNodeCur->
															findProperty(
																	XML_EVENT_INTERVAL)) : 0
											),
											(char *)mExpr.c_str(),
											g_mEventParser,
											(
												(char *)pNodeCur->findProperty(
														XML_EVENT_OBJECTID)
											) ?
												(
													(char *)pNodeCur->findProperty(
															XML_EVENT_OBJECTID)
												) :
													(char *)
														mapIt->first.c_str(),
											(
												(char *)pNodeCur->findProperty(
														XML_EVENT_OBJECTATTR)
											) ?
												(
													(char *)pNodeCur->findProperty(
															XML_EVENT_OBJECTATTR)
												) : (char *)mAttrStr.c_str(),
											DATACENTERAPP);
									g_pCfgPaserList.push_back(pPaser);
#ifdef PRINT_DEBUG
									g_mBiaodashiList.push_back(mExpr);
#endif
									printf(
										"Whole OS Expr explained by xml item [%d] [%s] \n",
										i,
										mExpr.c_str());
								}
							}
						}
						else
						{	// 应用进程类告警条件设置
							g_pDataCenter->getAppIdFromAttr(
									mObjectIdList,
									mAttrStr);

							list<string>::iterator	it;
							for (it = mObjectIdList.begin();
								 it != mObjectIdList.end();
								 it++)
							{
								addObjectIdtoExpr(
									mExpr,
									*it,
									pNodeCur->findProperty(XML_EVENT_EXPR));
								if (pNodeCur->findProperty(
										XML_EVENT_CONTROL)
							&&	(
										strcmp(
										pNodeCur->findProperty(
										XML_EVENT_CONTROL),
									"")
							))
								{
									mExpr.append(" && (");
									mExpr.append(
											pNodeCur->findProperty(
													XML_EVENT_CONTROL));
									mExpr.append(")");
								}

								CEventNodePaser *pPaser = new CEventNodePaser(
										pNodeCur->findProperty(XML_EVENT_NAME),
										pNodeCur->findProperty(
												XML_EVENT_FULLNAME),
										pNodeCur->findProperty(XML_EVENT_LEVEL),
										pNodeCur->findProperty(
												XML_EVENT_COMMENT),
										pNodeCur->findProperty(
												XML_EVENT_CONTROL),
										(
											pNodeCur->findProperty(
													XML_EVENT_GIVEUPTIME) ? atoi(
													pNodeCur->findProperty(
															XML_EVENT_GIVEUPTIME)) : 0
										),
										(
											pNodeCur->findProperty(
													XML_EVENT_INTERVAL) ? atoi(
													pNodeCur->findProperty(
															XML_EVENT_INTERVAL)) : 0
										),
										(char *)mExpr.c_str(),
										g_mEventParser,
										(
											(char *)pNodeCur->findProperty(
													XML_EVENT_OBJECTID)
										) ?
											(
												(char *)pNodeCur->findProperty(
														XML_EVENT_OBJECTID)
											) : (char *)(it->c_str()),
										(
											(char *)pNodeCur->findProperty(
													XML_EVENT_OBJECTATTR)
										) ?
											(
												(char *)pNodeCur->findProperty(
														XML_EVENT_OBJECTATTR)
											) : (char *)mAttrStr.c_str(),
										DATACENTERAPP);
								g_pCfgPaserList.push_back(pPaser);
#ifdef PRINT_DEBUG
								g_mBiaodashiList.push_back(mExpr);
#endif
								printf(
									"Whole App Expr explained by xml item [%d] [%s] \n",
									i,
									mExpr.c_str());
							}
						}
					}
					else	// 指定监控对象的单一告警条件设置
					{
						if (objectType != DATACENTERHOST)
						{
							objectType = DATACENTERAPP;
						}

						mExpr = "(";
						mExpr.append(pNodeCur->findProperty(XML_EVENT_EXPR));
						mExpr.append(")");
						if (pNodeCur->findProperty(XML_EVENT_CONTROL)
						&&	(
								strcmp(
								pNodeCur->findProperty(
								XML_EVENT_CONTROL),
							"")
					))
						{
							mExpr.append(" && (");
							mExpr.append(
									pNodeCur->findProperty(XML_EVENT_CONTROL));
							mExpr.append(")");
						}

#ifdef PRINT_DEBUG
						printf("expr:[%s]\n", mExpr.c_str());
#endif

						CEventNodePaser *pPaser = new CEventNodePaser(
								pNodeCur->findProperty(XML_EVENT_NAME),
								pNodeCur->findProperty(XML_EVENT_FULLNAME),
								pNodeCur->findProperty(XML_EVENT_LEVEL),
								pNodeCur->findProperty(XML_EVENT_COMMENT),
								pNodeCur->findProperty(XML_EVENT_CONTROL),
								(
									pNodeCur->findProperty(
											XML_EVENT_GIVEUPTIME) ? atoi(
											pNodeCur->findProperty(
													XML_EVENT_GIVEUPTIME)) : 0
								),
								(
									pNodeCur->findProperty(
											XML_EVENT_INTERVAL) ? atoi(
											pNodeCur->findProperty(
													XML_EVENT_INTERVAL)) : 0
								),
								(char *)mExpr.c_str(),
								g_mEventParser,
								(
									(char *)pNodeCur->findProperty(
											XML_EVENT_OBJECTID)
								) ?
									(
										(char *)pNodeCur->findProperty(
												XML_EVENT_OBJECTID)
									) : (char *)(mObject.c_str()),
								(
									(char *)pNodeCur->findProperty(
											XML_EVENT_OBJECTATTR)
								) ?
									(
										(char *)pNodeCur->findProperty(
												XML_EVENT_OBJECTATTR)
									) : (char *)mAttrStr.c_str(),
								(char *)objectType.c_str());
						g_pCfgPaserList.push_back(pPaser);
#ifdef PRINT_DEBUG
						g_mBiaodashiList.push_back(mExpr);
#endif
					}

					printf(
						"Whole One Expr explained by xml item [%s] \n",
						mExpr.c_str());
					if (mExpr.length() == 0)
					{
						printf(
							"Error: while explain[%s]\n",
							pNodeCur->findProperty(XML_EVENT_EXPR));
					}

					fflush(stdout);
				}
			}

			fflush(stdout);
		}
		catch(CParseError * e)
		{
			delete e;
			delete m_pXMLDoc;
			m_pXMLDoc = NULL;
			printf("\t XML Event File %s explain failed\n", pEventCfgFile);
			fflush(stdout);
			exit(0);
		}
	}

	exprTest();
}

bool CExprAnalysis::generateObjectExpr(
	map<int, map<string, int> > &expr_device_list,
	map<string, map<string, int> >	&attr_device_list,
	std::map<int, CFTDRspQryNetEventExprField>	&exprs)
{
	//test code
	//expr_device_list.clear();
	/*	expr_device_list[1]["zhangjiang.test1.fun1.T-JY3560-B2_1-DO_shfe_com_cn"] = 1;
	//expr_device_list[1]["zhangjiang.test.fun.abc"] = 1;
	CFTDRspQryNetEventExprField testfield;
	testfield.CONTROL = "";
	testfield.EXPR="@cpmCPUTotal1minRev > 5";
	testfield.GIVEUPTIME = 2;
	testfield.WarningLEVEL = "error";

	exprs[1] = testfield;
*/
	//ParseList读写锁
	g_cParseListMutex.Lock();

	g_pPaserList.clear();

	std::map<int, CFTDRspQryNetEventExprField>::iterator e_i = exprs.begin();
	for (; e_i != exprs.end(); ++e_i)
	{
		map<int, map<string, int> >::iterator e_d_i = expr_device_list.find(
				e_i->first);

		//更新事件级别
		g_mapEventLevel[e_i->second.ENAME.getValue()] = e_i->second.WarningLEVEL.getValue();
		g_mapEventFullName[e_i->second.ENAME.getValue()] = e_i->second.CNAME.getValue();
		g_mapEventDesc[e_i->second.ENAME.getValue()] = e_i->second.DISCRIPTION.getValue();

		string mAttrStr;	///保存读取到的第一个指标名
		string mObject;		///保存读取到的第一个监控对象名
		string mExpr;		///保存完成的表达式字符串
		if (getAttrFromExpr(
				mAttrStr,
			mObject,
			(char *)e_i->second.EXPR.getValue()))
		{
			//key:原始id，value:转以后的id
			map<string, string> objectidlist;

			if (e_d_i == expr_device_list.end())
			{
				//任务设备组中没有关联该表达式，从属性表中提取
				map<string, map<string, int> >::iterator a_i = attr_device_list.
					find(mAttrStr);
				if (a_i == attr_device_list.end())
				{
					continue;
				}

				//拥有该attr的所有objectid
				map<string, int>::iterator	d_i = a_i->second.begin();
				for (; d_i != a_i->second.end(); ++d_i)
				{
					string resultstr = transformStr(d_i->first);
					objectidlist[d_i->first] = resultstr;
				}
			}
			else
			{
				//关联该表达式的所有objectid
				map<string, int>::iterator	d_i = e_d_i->second.begin();
				for (; d_i != e_d_i->second.end(); ++d_i)
				{
					string resultstr = transformStr(d_i->first);
					if (resultstr.length() > 0)
					{
						objectidlist[d_i->first] = resultstr;
					}
				}
			}

			map<string, string>::iterator m_i = objectidlist.begin();
			for (; m_i != objectidlist.end(); ++m_i)
			{
				addObjectIdtoExpr(
					mExpr,
					m_i->second,
					(char *)e_i->second.EXPR.getValue());
				if (strcmp(e_i->second.CONTROL.getValue(), ""))
				{
					mExpr.append(" && (");
					mExpr.append(e_i->second.CONTROL.getValue());
					mExpr.append(")");
				}

				CEventNodePaser *pPaser = new CEventNodePaser(
						(char *)e_i->second.ENAME.getValue(),
						(char *)e_i->second.CNAME.getValue(),
						(char *)e_i->second.WarningLEVEL.getValue(),
						(char *)e_i->second.DISCRIPTION.getValue(),
						(char *)e_i->second.CONTROL.getValue(),
						e_i->second.GIVEUPTIME.getValue(),
						0,
						(char *)mExpr.c_str(),
						g_mEventParser,
						(char *)m_i->first.c_str(),
						(char *)mAttrStr.c_str(),
						"");

				g_pPaserList.push_back(pPaser);

				printf(
					"Whole App Expr explained by xml item [%s] \n",
					mExpr.c_str());
			}
		}

		fflush(stdout);
	}

	m_bExprAvailable = true;

	g_cParseListMutex.UnLock();

	return true;
}

bool CExprAnalysis::addObjectIdtoExpr(
	string	&strExpr,
	string	&objectid,
	char *pExpr)
{
	strExpr = "(";

	char *pStart;

	char *pEnd;

	char *pOral;
	char buff[64];
	memset(buff, 0, 64);
	pStart = pExpr;
	pEnd = pExpr;

	/// Mod by Henchi, 20120914
		/// 调整表达式解析方法，使其支持所有位置插入对象名
	while (*pStart != '\0' && *pEnd != '\0')
	{
		if (*pStart != '@' && *pStart != '#' && *pStart != '$')
		{
			pStart++;
			continue;
		}

		pStart++;

		//此时pStart > pEnd,将这一段字符入串
		strExpr.append(pEnd, pStart - pEnd);
		pEnd = pStart;
		while (*pEnd != '\0')
		{
			pEnd++;
			if ((isalnum(*pEnd) != 0) || (*pEnd == '.') || (*pEnd == '_'))
			{
				continue;
			}
			else if (*pEnd == ':')
			{
				strExpr.append(pStart, pEnd - pStart);
				pStart = pEnd + 1;
				break;
			}
			else			//已经找到第一个含有单目运算符不指定监控对象的指标
			{
				strExpr.append(objectid);
				if (*pStart != ':')
				{
					strExpr.append(":");
				}

				strExpr.append(pStart, pEnd - pStart);
				pStart = pEnd;
				break;
			}
		}
	}

	if (pStart > pEnd)
	{
		strExpr.append(pEnd, pStart - pEnd);
	}
	else
	{
		strExpr.append(pStart, pEnd - pStart);
	}

	strExpr.append(")");
	return false;
}

bool CExprAnalysis::getAttrFromExpr(string &attr, string &object, char *expr)
{
	char *pStart;

	char *pEnd;
	char buff[128];
	memset(buff, 0, 128);
	pStart = expr;

	bool firstFound = false;
	while (*pStart != '\0')
	{
		if (*pStart != '@' && *pStart != '#' && *pStart != '$')
		{
			pStart++;
			continue;
		}

		pStart++;
		pEnd = pStart;
		while (*pEnd != '\0')
		{
			if ((isalnum(*pEnd) != 0) || (*pEnd == '.') || (*pEnd == '_'))	// Mod by Henchi, 20120813. 恢复 ||(*pEnd=='_')
			{
				pEnd++;
				continue;
			}
			else if (*pEnd == ':')
			{
				if (firstFound)
				{
					pStart = pEnd + 1;
					break;
				}
				else
				{
					memcpy(buff, pStart, pEnd - pStart);
					object = buff;
					memset(buff, 0, 128);
					pEnd++;
					pStart = pEnd;
					while (*pEnd != '\0')
					{
						if ((isalnum(*pEnd) != 0)
						||	(*pEnd == '.')
						||	(*pEnd == '_')) // Mod by Henchi, 20120813. 恢复 ||(*pEnd=='_')
						{
							pEnd++;
							continue;
						}

						memcpy(buff, pStart, pEnd - pStart);
						attr = buff;

						// Added by Henchi, 20100406
						// 清理buff域，避免再次解析到object时复用此buff可能导致的对象ID异常
						memset(buff, 0, 128);
						break;
					}

					break;
				}
			}

			// next add by zhou.jj 20090427 增加对转义字符'\'的解释，遇到该字符直接向后跳过两个字符
			else if (*pEnd == '\\')
			{
				pEnd++;
				pEnd++;
			}

			// before add by zhou.jj 20090427
			else						//已经找到第一个含有单目运算符不指定监控对象的指标
			{
				memcpy(buff, pStart, pEnd - pStart);
				attr = buff;
				return true;
			}
		}
	}

	return false;
}

CExprAnalysis::~CExprAnalysis(void)
{
	if (m_pXMLDoc)
	{
		delete m_pXMLDoc;
		m_pXMLDoc = NULL;
	}

	list<CEventNodePaser *>::iterator it;
	for (it = g_pPaserList.begin(); it != g_pPaserList.end(); it++)
	{
		if (*it)
		{
			delete(*it);
		}
	}
}

void CExprAnalysis::addExpr(void)
{
	for (int i = 0; i < 20; i++)
	{
		if (i % 2 == 0)
		{
			addMonitorEntity(1, 1, i, i);
		}
	}

	CMonitorEntity	*pMonitorEntity;
	int monitorTime;

	pMonitorEntity = g_mExprDB->m_MonitorEntityFactory->startFindByTime(
			1,
			1,
			5);
	while (pMonitorEntity)
	{
		monitorTime = pMonitorEntity->MonitorTime;
		pMonitorEntity = g_mExprDB->m_MonitorEntityFactory->findNextByTime();
	}

	g_mExprDB->m_MonitorEntityFactory->endFindByTime();
	pMonitorEntity = g_mExprDB->m_MonitorEntityFactory->findByKey(1, 1, 5);
	if (pMonitorEntity != NULL)
	{
		monitorTime = pMonitorEntity->MonitorTime;
	}

	monitorTime = 0;

	//pMonitorEntity = g_mExprDB->m_MonitorEntityFactory->findByKey1(monitorObject,monitorItem);
}

void CExprAnalysis::exprTest(void)
{
	try
	{
		list<CEventNodePaser *>::iterator it;
		int iExprNo = 0;
		for (it = g_pCfgPaserList.begin(); it != g_pCfgPaserList.end();)
		{
			if (*it)
			{
				if (!(*it)->TestExpr()) ///已产生新的事件,保存在eventField中
				{
					g_pCfgPaserList.erase(it++);
				}
				else
				{
					++iExprNo;
					printf(
						"==ExprNo[%04d]: %s\n",
						iExprNo,
						(*it)->m_mExprString.c_str());
					it++;
				}
			}
		}
	}

	catch(CExprException * e)
	{
		printf("Unknown expression, find exception\n");
		fflush(stdout);
		e->display();
	}
}

void CExprAnalysis::exprRun(void)
{
	//ParseList读写锁
	g_cParseListMutex.Lock();

	//执行数据库中的表达式
	RunExprs(g_pPaserList);

	g_cParseListMutex.UnLock();

	//执行配置文件中的表达式
	RunExprs(g_pCfgPaserList);
}

void CExprAnalysis::addMonitorEntity(
	const char	*monitorObject,
	const char	*monitorItem,
	int monitorTime,
	int monitorValue)
{
	CWriteableMonitorEntity theMonitorEntity;
	theMonitorEntity.MonitorObject = g_mStringIdMap.getStringId(monitorObject);
	theMonitorEntity.MonitorItem = g_mStringIdMap.getStringId(monitorItem);
	theMonitorEntity.MonitorTime = monitorTime;
	theMonitorEntity.ValueType = DINT_VALUE;
	sprintf((char *)theMonitorEntity.AttrValue.getValue(), "%d", monitorValue);

	//theMonitorEntity.MonitorValue=(double) monitorValue;
	g_mExprDB->m_MonitorEntityFactory->add(&theMonitorEntity);
	return;
}

void CExprAnalysis::addMonitorEntity(
	int monitorObject,
	int monitorItem,
	int monitorTime,
	int monitorValue)
{
	CWriteableMonitorEntity theMonitorEntity;
	theMonitorEntity.MonitorObject = monitorObject;
	theMonitorEntity.MonitorItem = monitorItem;
	theMonitorEntity.MonitorTime = monitorTime;
	theMonitorEntity.ValueType = DINT_VALUE;
	sprintf((char *)theMonitorEntity.AttrValue.getValue(), "%d", monitorValue);

	//theMonitorEntity.MonitorValue=(double)monitorValue;
	g_mExprDB->m_MonitorEntityFactory->add(&theMonitorEntity);
	return;
}

void CExprAnalysis::RunExprs(list<CEventNodePaser *> &parser_list)
{
	CFTDRtnWarningEventField eventField;
	memset(&eventField, 0, sizeof(CFTDRtnWarningEventField));

	try
	{
		//bool mHave=false;
		//g_mPkgSend.PreparePackage(FTD_TID_RtnWarningEventTopic, FTDC_CHAIN_LAST, FTD_VERSION);
		list<CEventNodePaser *>::iterator it;
#ifdef PRINT_DEBUG
		list<string>::iterator	strit = g_mBiaodashiList.begin();
		int i = 0;
#endif
		for (it = parser_list.begin(); it != parser_list.end(); it++)
		{
#ifdef PRINT_DEBUG
			PRINTF;
			printf("=====表达式: %s\n", strit->c_str());
			printf("================Event 事件编号 : %d\n", i);
			i++;
			strit++;
#endif

			//printf("=====表达式: %s\n",(*it)->m_mExprString.c_str());
			if (*it && (*it)->Evaluation(eventField))					///已产生新的事件,保存在eventField中
			{
				time_t timep = time((time_t *)NULL);
				struct tm tm_time;				
				LocalTime(&timep, &tm_time);

				sprintf(
					(char *)eventField.MonDate.getValue(), 
					"%04d%02d%02d",
					tm_time.tm_year + 1900,
					tm_time.tm_mon + 1,
					tm_time.tm_mday);	

				sprintf(
					(char *)eventField.MonTime.getValue(),
					"%02d:%02d:%02d",
					tm_time.tm_hour,
					tm_time.tm_min,
					tm_time.tm_sec);

				eventField.OccurTime = eventField.MonTime;
				eventField.OccurDate = eventField.MonDate;

				CFTDRtnWarningQueryField warningInfo;
				memset(&warningInfo, 0, sizeof(CFTDRtnWarningQueryField));
				warningInfo.MonDate = eventField.MonDate;
				warningInfo.MonTime = eventField.MonTime;


				/// Mod by Henchi, 20130531
				/// 修改事件信息格式，以避免表达式超长及指标明细重复现象
				//string outInfo = (*it)->m_mExprString;
				string outInfo = "";
				outInfo.append(DBSEPARATORRECORD);

				list<string>::iterator	infoIt = g_warningInfoList.begin();
				while (infoIt != g_warningInfoList.end())
				{
					outInfo.append(*infoIt);
					infoIt++;
				}
				int iLen = (*it)->m_mExprString.length() + outInfo.length();
				if ( iLen < sizeof(warningInfo.DBQueryResult))
				{
					sprintf((char *)warningInfo.DBQueryResult.getValue(), "%s%s", 
						(char *)(*it)->m_mExprString.c_str(), (char *)outInfo.c_str()
						);
				}
				else if (outInfo.length() < sizeof(warningInfo.DBQueryResult)) ///仅省略表达式
				{
					sprintf((char *)warningInfo.DBQueryResult.getValue(), "%s", 
						(char *)outInfo.c_str()
						);				
				}
				else	/// 表达式及尾部详情信息省略
				{
					/// Mod by Henchi, 20131211
					/// 原有赋值方式可能因outInfo超长导致内存溢出
					//warningInfo.DBQueryResult = (*it)->m_mExprString.c_str();
					//char *pPos = (char *)warningInfo.DBQueryResult.getValue();
					//pPos += max(0, (int)(sizeof(warningInfo.DBQueryResult) -5 -(outInfo.length())));
					//sprintf(pPos, "... %s", outInfo.c_str());
					SNPRINTF((char *)warningInfo.DBQueryResult.getValue(), sizeof(warningInfo.DBQueryResult) -6, "%s", outInfo.c_str());
					strcat((char *)warningInfo.DBQueryResult.getValue(), "...");
				}

				warningInfo.EvendID = eventField.EvendID.getValue();

				string exprkey = eventField.ObjectID.getValue();
				exprkey += "_";
				exprkey += eventField.EventName.getValue();
				exprkey += "_";
				exprkey += eventField.MonDate.getValue();
				exprkey += "_";
				exprkey += eventField.MonTime.getValue();

				if (g_pDataCenter->IsObjectEventOff(
						(char *)eventField.ObjectID.getValue()))
				{
					printf(
						"--- Notice: ObjectID [%s] Warnning Event [%s] drop!\n",
						eventField.ObjectID.getValue(),
						eventField.EventName.getValue());
					continue;
				}

				if (g_mConfigControlEvent)
				{
					//缓存事件的对应的表达式信息
					m_mapWarningEventExpr.add(exprkey, (*it)->m_mExprString);

					m_mapWarningInfo.add(exprkey, string(warningInfo.DBQueryResult.getValue()));

					//发送给config
					AddWarningEvent(eventField);
				}
				else
				{
					g_pListEvent->WriteValue(eventField, warningInfo);
				}

				/// Added by Henchi, 20130531
				/// 用于告警事件明细追踪
				printf(
					"\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\nGen Event:[%s] [%s] %s[%s]\n%s\n%s\n\n",
					(const char *)eventField.OccurTime,
					(const char *)eventField.ObjectID,
					(const char *)eventField.EventName,
					(const char *)eventField.WarningLevel,
					(const char *)eventField.EventDes,
					(const char *)warningInfo.DBQueryResult.getValue()
					);
			}
		}
	}

	catch(CExprException * e)
	{
		printf("Unknown expression, find exception\n");
		fflush(stdout);
		e->display();
	}
}

CEventNodePaser::CEventNodePaser(
	char *pEventName,
	char *pFullName,
	char *pEventLevel,
	char *pDesc,
	char *pControl,
	int mGiveupTime,
	int mInterval,
	char *pUsing,
	CExprParser<CValue> &theParser,
	char *pObjectId,
	char *pObjectItem,
	char *pItemType)
{
	g_cEventProcess.getEventDesc(pObjectId, pEventName, m_mEventSeries);
	m_mEventName = pEventName;
	m_mFullName = pFullName;
	m_mDescription = pDesc;
	m_mEventLevel = pEventLevel;
	m_mGiveupTime = mGiveupTime;
	m_mInterval = mInterval;
	m_mMonitorItem = g_mStringIdMap.getStringId(pObjectItem);
	m_mMonitorObject = g_mStringIdMap.getStringId(pObjectId);
	m_mItemType = pItemType;

	m_mBirthTime = 0;
	m_mDbTime = -2;
	m_mCountNow = (int)time((time_t *)NULL);
	m_mResultNow = (int)time((time_t *)NULL) + g_warningeventdelaytime; /// 加大告警计算起步延迟
	m_pStream = new CStringInputStream(pUsing);
	m_mExprString = pUsing;
	m_pExpr = theParser.parse(m_pStream);

	printf(
		"CEventNodePaser::CEventNodePaser [%s] %d\n",
		pObjectId,
		m_mMonitorObject);

#ifdef PRINT_DEBUG
	printf("CEventNodePaser::CEventNodePaser:exprValue :%s:\n", pUsing);
	m_pExpr->display();
#endif
}

bool CEventNodePaser::TestExpr(void)
{
	CValue	&result = m_pExpr->eval(*g_pContext);
	if (result.getConstantFlag() && result.getDIntValue() <= 0)
	{
		return false;					//	表达式测试未通过
	}
	else
	{
		return true;
	}
}

bool CEventNodePaser::Evaluation(CFTDRtnWarningEventField &eventField)
{
	if (m_mGiveupTime && (m_mCountNow <= (m_mGiveupTime + m_mBirthTime)))
	{
#ifdef PRINT_DEBUG
		PRINTF;
		printf(
			"\t Eval:GiveupTime m_mCountNow:%d m_mGiveupTime:%d m_mBirthTime:%d\n",
			m_mCountNow,
			m_mGiveupTime,
			m_mBirthTime);
#endif
		m_mCountNow = time((time_t *)NULL);
		m_mResultNow = m_mCountNow;		// by zhou.jj 20100816 放弃时间之内不再根据该时间段内的状态值产生告警
		return false;
	}

	time_t iNow = time((time_t *)NULL);
	int mResult = m_mResultNow;
	for (m_mCountNow = iNow; m_mCountNow > m_mResultNow; m_mCountNow--)
	{
		g_pContext->setNow(m_mCountNow);
		g_bValueExist = true;

		CValue	&result = m_pExpr->eval(*g_pContext);

		if (result.getDIntValue() > 0)	//存在监控指标值并且计算结果为真才能产生新事件
		{
#ifdef PRINT_DEBUG
			printf(
				"运行文件 ： %s 行数：%d m_mCountNow %d\n",
				__FILE__,
				__LINE__,
				m_mCountNow);
			result.display();
#endif
			if ((iNow <= (m_mBirthTime + m_mGiveupTime))
			||	(m_mDbTime >= result.getDTimeValue() && m_mDbTime != -1))
			{
				m_mResultNow = m_mCountNow;
				return false;
			}

			m_mBirthTime = iNow;		// 产生告警时间
			m_mResultNow = iNow;		// 具备计算结果的时间(不论结果为true或false)
			m_mDbTime = result.getDTimeValue();

			eventField.EvendID = g_mEventId++;
			eventField.EventName = m_mEventName.c_str();
			eventField.FullEventName = m_mFullName.c_str();
			eventField.WarningLevel = m_mEventLevel.c_str();
			eventField.EventNum = m_mEventSeries;
			eventField.ObjectID = g_mStringIdMap.getString(m_mMonitorObject);

			/// Mod by Henchi, 20120301
						/// 事件描述信息在产生是填充完整
						/// 回填信息不再是指标名称，是否有其它影响，待查
			//eventField.EventDes = g_mStringIdMap.getString(m_mMonitorItem);
			eventField.EventDes = m_mDescription.c_str();
			eventField.ProcessFlag = "N";

			map<string, string>::iterator g_i = g_DevIPList.find(
					eventField.ObjectID.getValue());
			if (g_i != g_DevIPList.end())
			{
				eventField.IPAddress = g_i->second.c_str();
			}
			else
			{
				/// 尝试从配置文件信息中获取其IP信息
				eventField.IPAddress = g_pDataCenter->getAddressByObjectID(
						(char *)eventField.ObjectID.getValue()).c_str();
			}

			time_t timep = m_mBirthTime;
			struct tm tm_time;
			if (LocalTime((time_t *) &timep, &tm_time) != NULL)
			{
				sprintf(
					(char *)eventField.OccurTime.getValue(),
					"%02d:%02d:%02d",
					tm_time.tm_hour,
					tm_time.tm_min,
					tm_time.tm_sec);
				sprintf(
					(char *)eventField.OccurDate.getValue(),
					"%04d%02d%02d",
					1900 + tm_time.tm_year,
					1 + tm_time.tm_mon,
					tm_time.tm_mday);
			}
			else
			{
				printf(
					"运行文件 ： %s 行数：%d 指针 p 为空！ \n",
					__FILE__,
					__LINE__);
				fflush(stdout);
				exit(0);
			}
			return true;
		}
		else
		{
			mResult = max(mResult, result.getDTimeValue());
			if (mResult <= m_mResultNow)
			{
				break;
			}

			// 20080829 20:22 at home
			m_mCountNow = min(m_mCountNow, result.getDTimeValue());
		}
	}	// for end

	m_mResultNow = mResult;
	if (m_mResultNow < iNow - g_mAlert)
	{
		m_mResultNow = iNow - g_mAlert;
	}

	return false;
}

CContext::CContext(char *pConfigFile)
{
	///注意下面的表达式分析器设置
	g_mEventParser.setIdentifierCharSet(NULL, g_mCharSetIden);
	g_mEventParser.setKeywords(g_mKeywords);
	g_mEventParser.setNumberSupport(false, true);

	if (g_mExprDB == NULL)
	{
		CConfig *pConfig = new CConfig(pConfigFile);

		///MDB对INI导入处:
		currentConfig = pConfig;
		g_mExprDB = new CMemoryDB();
		g_mExprDB->init(pConfig);
	}

	m_now = 0;

	// 测试程序
#if 0
	CWriteableEventEntity theEvent;
	theEvent.EventName = g_mStringIdMap.getStringId("Connect");
	theEvent.MonitorTime = time((time_t *)NULL);
	theEvent.MonitorObject = 2;
	for (int i = 0; i < 20; i++)
	{
		theEvent.MonitorTime = theEvent.MonitorTime + 1;
		printf("%d %d\n", theEvent.EventName, theEvent.MonitorTime);
		g_mExprDB->m_EventEntityFactory->add(&theEvent);
		g_mExprDB->m_EventEntityFactory->add(&theEvent);
	}

#endif
}

CContext::~CContext(void)
{
	delete g_mExprDB;
	g_mExprDB = NULL;
}

void CContext::setNow(int newNow)
{
	m_now = newNow;
	g_warningInfoList.clear();
}

int CContext::getNow(void)
{
	return m_now;
}

bool CContext::getKeywordValue(CValue &result, const char *keyword)
{
	time_t now;
	time(&now);

	struct tm tm_time;
	LocalTime(&now, &tm_time);

	char szDate[10], szTime[10];

	if (!strcmp(keyword, "now"))
	{
		result.setIntegerConstant(m_now);
	}
	else if (!strcmp(keyword, "today"))
	{
		result.setIntegerConstant(m_now - (m_now % 86400));
	}
	else if (!strcmp(keyword, "date"))
	{
		sprintf(
			szDate,
			"%d%02d%02d",
			1900 + tm_time.tm_year,
			tm_time.tm_mon + 1,
			tm_time.tm_mday);
		result.setStringConstant(szDate, m_now);
	}
	else if (!strcmp(keyword, "time"))
	{
		sprintf(
			szTime,
			"%02d:%02d:%02d",
			tm_time.tm_hour,
			tm_time.tm_min,
			tm_time.tm_sec);
		result.setStringConstant(szTime, m_now);
	}

	return true;
}

bool CContext::getUniOperatorResult(
	CValue	&result,
	CValue	&value,
	const char	*thisOperator)
{
	if (!strcmp(thisOperator, "-"))
	{
		result.setConstantFlag(value.getConstantFlag());
		if (value.getValueType() == INT_VALUE)
		{
			result.setIntegerConstant(-value.getIntValue());
		}
		else if (value.getValueType() == DOUBLE_VALUE)
		{
			result.setFltConstant(-value.getFltValue(), value.getDTimeValue());
		}
		else if (value.getValueType() == DINT_VALUE)
		{
			result.setDIntConstant(
					-value.getDIntValue(),
					value.getDTimeValue());
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, "@"))	//指定监控对象监控指标的当前值
	{
		if (value.getValueType() == OBJECT_VALUE)
		{
			int objectid, subobjectid,
						itemid,
						monitorTime;
			objectid = g_mStringIdMap.getStringSubId(
					subobjectid,
					itemid,
					g_mStringIdMap.getString(value.getObjectValue()));
			if (objectid < 0)
			{
				value.display(stdout);
				g_mStringIdMap.print();
				printf(
					" @ getStringSubId wrong [%s]\n",
					(
						NULL == g_mStringIdMap.getString(
								value.getObjectValue())
					) ? "NULL" : g_mStringIdMap.getString(
							value.getObjectValue()));
				return false;
			}

			if (itemid == g_mStringIdMap.getStringId(""))
			{	///处理类似@BECK.PuDian.app.CsConsole.1:字串，返回字符串类型，值为BECK.PuDian.app.CsConsole.1
				result.setStringConstant(g_mStringIdMap.getString(subobjectid));

				///此类标识为静态数据,于表达式内不发生变化
				result.setConstantFlag(true);
			}
			else
			{
				getLastedItemValue(
					result,
					subobjectid,
					itemid,
					m_now,
					monitorTime);
			}
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, "#"))	//指定监控对象监控指标的上一秒的值
	{
		if (value.getValueType() == OBJECT_VALUE)
		{
			int objectid, subobjectid,
						itemid,
						monitorTime;
			objectid = g_mStringIdMap.getStringSubId(
					subobjectid,
					itemid,
					g_mStringIdMap.getString(value.getObjectValue()));
			if (objectid < 0)
			{
				value.display(stdout);
				printf(
					" # getStringSubId wrong [%s]\n",
					(
						NULL == g_mStringIdMap.getString(
								value.getObjectValue())
					) ? "NULL" : g_mStringIdMap.getString(
							value.getObjectValue()));
				return false;
			}

			getNextItemValue(result, subobjectid, itemid, m_now, monitorTime);
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, "$"))	//指定监控对象监控指标的指定时间以前的值，Time是一个整数，以秒计
	{
		if (value.getValueType() == LIST_VALUE)
		{
			int subobjectid, itemid,
							monitorNow,
							monitorTime,
							timeTemp;
			list<int> *p = value.getListValue();
			list<int>::iterator it;
			it = p->begin();
			subobjectid = *it;
			p->pop_front();
			it = p->begin();
			itemid = *it;
			p->pop_front();
			it = p->begin();
			monitorNow = *it;
			p->pop_front();
			getLastedItemValue(result, subobjectid, itemid, m_now, timeTemp);
			getLastedItemValue(
				result,
				subobjectid,
				itemid,
				monitorNow,
				monitorTime);
			if (timeTemp == monitorTime && monitorNow != m_now)
			{
				timeTemp = timeTemp - (m_now - monitorNow);
				getLastedItemValue(
					result,
					subobjectid,
					itemid,
					timeTemp,
					monitorTime);
			}
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, "^@"))	//指定监控对象监控指标的最新采样时间
	{
		if (value.getValueType() == OBJECT_VALUE)
		{
			int objectid, subobjectid,
						itemid,
						monitorTime;
			objectid = g_mStringIdMap.getStringSubId(
					subobjectid,
					itemid,
					g_mStringIdMap.getString(value.getObjectValue()));
			if (objectid < 0)
			{
				value.display(stdout);
				printf(
					" ^@ getStringSubId wrong [%s]\n",
					(
						NULL == g_mStringIdMap.getString(
								value.getObjectValue())
					) ? "NULL" : g_mStringIdMap.getString(
							value.getObjectValue()));
				return false;
			}

			getLastedItemTime(result, subobjectid, itemid, m_now, monitorTime);
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, "^#"))	//指定监控对象监控指标的上一次对应的采样时间
	{
		if (value.getValueType() == OBJECT_VALUE)
		{
			int objectid, subobjectid,
						itemid,
						monitorTime;
			objectid = g_mStringIdMap.getStringSubId(
					subobjectid,
					itemid,
					g_mStringIdMap.getString(value.getObjectValue()));
			if (objectid < 0)
			{
				value.display(stdout);
				printf(
					" ^# getStringSubId wrong [%s]\n",
					(
						NULL == g_mStringIdMap.getString(
								value.getObjectValue())
					) ? "NULL" : g_mStringIdMap.getString(
							value.getObjectValue()));
				return false;
			}

			getNextItemTime(result, subobjectid, itemid, m_now, monitorTime);
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, "^$"))	//指定监控对象监控指标的指定时间以前的采样时间，Time是一个整数，以秒计
	{
		if (value.getValueType() == LIST_VALUE)
		{
			int subobjectid, itemid,
							monitorNow,
							monitorTime,
							timeTemp;
			list<int> *p = value.getListValue();
			list<int>::iterator it;
			it = p->begin();
			subobjectid = *it;
			p->pop_front();
			it = p->begin();
			itemid = *it;
			p->pop_front();
			it = p->begin();
			monitorNow = *it;
			p->pop_front();
			getLastedItemTime(result, subobjectid, itemid, m_now, timeTemp);
			getLastedItemTime(
				result,
				subobjectid,
				itemid,
				monitorNow,
				monitorTime);
			if (timeTemp == monitorTime && monitorNow != m_now)
			{
				timeTemp = timeTemp - (m_now - monitorNow);
				getLastedItemTime(
					result,
					subobjectid,
					itemid,
					timeTemp,
					monitorTime);
			}
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, "!"))
	{
		result.setConstantFlag(value.getConstantFlag());
		if (value.getValueType() == INT_VALUE)
		{
			result.setIntegerConstant(!value.getIntValue());
		}
		else if (value.getValueType() == DINT_VALUE)
		{
			result.setDIntConstant(
					!value.getDIntValue(),
					value.getDTimeValue());
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	return true;
}

#define GETDTIMEVALUE	int monitorTime;							  \
	if (value1.getDTimeValue() < 0 || value2.getDTimeValue() < 0)	  \
	{																  \
		monitorTime = -1;											  \
	}																  \
	else															  \
	{																  \
		monitorTime =												  \
			(														  \
				value1.getDTimeValue() > value2.getDTimeValue()		  \
					? value1.getDTimeValue() : value2.getDTimeValue() \
			);														  \
	}

bool CContext::getBiOperatorResult(
	CValue	&result,
	CValue	&value1,
	const char	*thisOperator,
	CValue	&value2)
{
	GETDTIMEVALUE;
	if (!strcmp(thisOperator, "+"))
	{
		result.setConstantFlag(
				value1.getConstantFlag() && value2.getConstantFlag());
		if (value2.getDTimeValue() == -1 && value2.getIntValue() == -1)
		{
			if (value1.getValueType() == INT_VALUE)
			{
				result.setIntegerConstant(value1.getIntValue());
			}
			else if (value1.getValueType() == DOUBLE_VALUE)
			{
				result.setFltConstant(
						value1.getFltValue(),
						value1.getDTimeValue());
			}
			else if (value1.getValueType() == DINT_VALUE)
			{
				result.setDIntConstant(
						value1.getDIntValue(),
						value1.getDTimeValue());
			}
			else if (value1.getValueType() == STRING_VALUE)
			{
				result.setStringConstant(
						new CRefString(value1.getStringValue()),
						monitorTime);
			}
		}
		else if (value1.getDTimeValue() == -1 && value1.getIntValue() == -1)
		{
			if (value2.getValueType() == INT_VALUE)
			{
				result.setIntegerConstant(value2.getIntValue());
			}
			else if (value2.getValueType() == DOUBLE_VALUE)
			{
				result.setFltConstant(
						value2.getFltValue(),
						value2.getDTimeValue());
			}
			else if (value2.getValueType() == DINT_VALUE)
			{
				result.setDIntConstant(
						value2.getDIntValue(),
						value2.getDTimeValue());
			}
			else if (value2.getValueType() == STRING_VALUE)
			{
				result.setStringConstant(
						new CRefString(value2.getStringValue()),
						monitorTime);
			}
		}
		else if ((
					 (value1.getValueType() == DINT_VALUE)
			 ||	 (value1.getValueType() == INT_VALUE)
			 ||	 (value1.getValueType() == DOUBLE_VALUE)
			 )
			 &&	 (
					 (value2.getValueType() == DINT_VALUE)
			 ||	 (value2.getValueType() == INT_VALUE)
			 ||	 (value2.getValueType() == DOUBLE_VALUE)
			 ))
		{
			result.setFltConstant(
					value1.getFltValue() + value2.getFltValue(),
					monitorTime);
		}
		else if ((value1.getValueType() == STRING_VALUE)
			 &&	 (value2.getValueType() == STRING_VALUE))
		{
			char *buffer = new char[(value1.getStringValue())->getLen() +
				(value2.getStringValue())->getLen() + 1];
			strcpy(buffer, value1.getStringValue());
			strcat(buffer, value2.getStringValue());
			result.setStringConstant(new CRefString(buffer), monitorTime);
			delete buffer;
		}
		else if ((value1.getValueType() == STRING_VALUE)
			 &&	 (value2.getValueType() != STRING_VALUE))
		{
			result.setStringConstant(
					new CRefString(value1.getStringValue()),
					monitorTime);
		}
		else if ((value1.getValueType() != STRING_VALUE)
			 &&	 (value2.getValueType() == STRING_VALUE))
		{
			result.setStringConstant(
					new CRefString(value2.getStringValue()),
					monitorTime);
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, "=="))
	{
		result.setConstantFlag(
				value1.getConstantFlag() && value2.getConstantFlag());
		if ((
				(value1.getValueType() == DINT_VALUE)
		||	(value1.getValueType() == INT_VALUE)
		||	(value1.getValueType() == DOUBLE_VALUE)
		)
		&&	(
				(value2.getValueType() == DINT_VALUE)
		||	(value2.getValueType() == INT_VALUE)
		||	(value2.getValueType() == DOUBLE_VALUE)
		))
		{
			result.setDIntConstant(
					value1.getFltValue() == value2.getFltValue(),
					monitorTime);
		}
		else if ((value1.getValueType() == STRING_VALUE)
			 &&	 (value2.getValueType() == STRING_VALUE))
		{
			result.setDIntConstant(
					value1.getStringValue()->equal(value2.getStringValue()),
					monitorTime);
		}
		else if ((value1.getValueType() == STRING_VALUE)
			 ||	 (value2.getValueType() == STRING_VALUE))
		{
			result.setDIntConstant(false, monitorTime);
		}
		else if (true)
		{
			result.setDIntConstant(false, monitorTime);
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, ">="))
	{
		result.setConstantFlag(
				value1.getConstantFlag() && value2.getConstantFlag());
		if ((
				(value1.getValueType() == DINT_VALUE)
		||	(value1.getValueType() == INT_VALUE)
		||	(value1.getValueType() == DOUBLE_VALUE)
		)
		&&	(
				(value2.getValueType() == DINT_VALUE)
		||	(value2.getValueType() == INT_VALUE)
		||	(value2.getValueType() == DOUBLE_VALUE)
		))
		{
			result.setDIntConstant(
					value1.getFltValue() >= value2.getFltValue(),
					monitorTime);
		}
		else if ((value1.getValueType() == STRING_VALUE)
			 &&	 (value2.getValueType() == STRING_VALUE))
		{
			result.setDIntConstant(
					value1.getStringValue()->ge(value2.getStringValue()),
					monitorTime);
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, ">"))
	{
		result.setConstantFlag(
				value1.getConstantFlag() && value2.getConstantFlag());
		if ((
				(value1.getValueType() == DINT_VALUE)
		||	(value1.getValueType() == INT_VALUE)
		||	(value1.getValueType() == DOUBLE_VALUE)
		)
		&&	(
				(value2.getValueType() == DINT_VALUE)
		||	(value2.getValueType() == INT_VALUE)
		||	(value2.getValueType() == DOUBLE_VALUE)
		))
		{
			result.setDIntConstant(
					value1.getFltValue() > value2.getFltValue(),
					monitorTime);
		}
		else if ((value1.getValueType() == STRING_VALUE)
			 &&	 (value2.getValueType() == STRING_VALUE))
		{
			result.setDIntConstant(
					value1.getStringValue()->gt(value2.getStringValue()),
					monitorTime);
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, "<="))
	{
		result.setConstantFlag(
				value1.getConstantFlag() && value2.getConstantFlag());
		if ((
				(value1.getValueType() == DINT_VALUE)
		||	(value1.getValueType() == INT_VALUE)
		||	(value1.getValueType() == DOUBLE_VALUE)
		)
		&&	(
				(value2.getValueType() == DINT_VALUE)
		||	(value2.getValueType() == INT_VALUE)
		||	(value2.getValueType() == DOUBLE_VALUE)
		))
		{
			result.setDIntConstant(
					value1.getFltValue() <= value2.getFltValue(),
					monitorTime);
		}
		else if ((value1.getValueType() == STRING_VALUE)
			 &&	 (value2.getValueType() == STRING_VALUE))
		{
			result.setDIntConstant(
					value1.getStringValue()->le(value2.getStringValue()),
					monitorTime);
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, "<"))
	{
		result.setConstantFlag(
				value1.getConstantFlag() && value2.getConstantFlag());
		if ((
				(value1.getValueType() == DINT_VALUE)
		||	(value1.getValueType() == INT_VALUE)
		||	(value1.getValueType() == DOUBLE_VALUE)
		)
		&&	(
				(value2.getValueType() == DINT_VALUE)
		||	(value2.getValueType() == INT_VALUE)
		||	(value2.getValueType() == DOUBLE_VALUE)
		))
		{
			result.setDIntConstant(
					value1.getFltValue() < value2.getFltValue(),
					monitorTime);
		}
		else if ((value1.getValueType() == STRING_VALUE)
			 &&	 (value2.getValueType() == STRING_VALUE))
		{
			result.setDIntConstant(
					value1.getStringValue()->lt(value2.getStringValue()),
					monitorTime);
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, "!="))
	{
		result.setConstantFlag(
				value1.getConstantFlag() && value2.getConstantFlag());
		if ((
				(value1.getValueType() == DINT_VALUE)
		||	(value1.getValueType() == INT_VALUE)
		||	(value1.getValueType() == DOUBLE_VALUE)
		)
		&&	(
				(value2.getValueType() == DINT_VALUE)
		||	(value2.getValueType() == INT_VALUE)
		||	(value2.getValueType() == DOUBLE_VALUE)
		))
		{
			result.setDIntConstant(
					value1.getFltValue() != value2.getFltValue(),
					monitorTime);
		}
		else if ((value1.getValueType() == STRING_VALUE)
			 &&	 (value2.getValueType() == STRING_VALUE))
		{
			if (strcmp((const char *)value1.getStringValue(), (const char *)value2.getStringValue()) != 0)
				result.setDIntConstant(1, monitorTime);
			else
				result.setDIntConstant(0, monitorTime);
		}
		else if ((value1.getValueType() == STRING_VALUE)
			 ||	 (value2.getValueType() == STRING_VALUE))
		{
			result.setDIntConstant(true, monitorTime);
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, "-"))
	{
		result.setConstantFlag(
				value1.getConstantFlag() && value2.getConstantFlag());
		if (value2.getDTimeValue() == -1 && value2.getIntValue() == -1)
		{
			if (value1.getValueType() == INT_VALUE)
			{
				result.setIntegerConstant(value1.getIntValue());
			}
			else if (value1.getValueType() == DOUBLE_VALUE)
			{
				result.setFltConstant(
						value1.getFltValue(),
						value1.getDTimeValue());
			}
			else if (value1.getValueType() == DINT_VALUE)
			{
				result.setDIntConstant(
						value1.getDIntValue(),
						value1.getDTimeValue());
			}
		}
		else if (value1.getDTimeValue() == -1 && value1.getIntValue() == -1)
		{
			if (value2.getValueType() == INT_VALUE)
			{
				result.setIntegerConstant(-value2.getIntValue());
			}
			else if (value2.getValueType() == DOUBLE_VALUE)
			{
				result.setFltConstant(
						-value2.getFltValue(),
						value2.getDTimeValue());
			}
			else if (value2.getValueType() == DINT_VALUE)
			{
				result.setDIntConstant(
						-value2.getDIntValue(),
						value2.getDTimeValue());
			}
		}
		else if ((
					 (value1.getValueType() == DINT_VALUE)
			 ||	 (value1.getValueType() == INT_VALUE)
			 ||	 (value1.getValueType() == DOUBLE_VALUE)
			 )
			 &&	 (
					 (value2.getValueType() == DINT_VALUE)
			 ||	 (value2.getValueType() == INT_VALUE)
			 ||	 (value2.getValueType() == DOUBLE_VALUE)
			 ))
		{
			result.setFltConstant(
					value1.getFltValue() - value2.getFltValue(),
					monitorTime);
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, "*"))
	{
		result.setConstantFlag(
				value1.getConstantFlag() && value2.getConstantFlag());
		if ((
				(value1.getValueType() == DINT_VALUE)
		||	(value1.getValueType() == INT_VALUE)
		||	(value1.getValueType() == DOUBLE_VALUE)
		)
		&&	(
				(value2.getValueType() == DINT_VALUE)
		||	(value2.getValueType() == INT_VALUE)
		||	(value2.getValueType() == DOUBLE_VALUE)
		))
		{
			result.setFltConstant(
					value1.getFltValue() * value2.getFltValue(),
					monitorTime);
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, "/"))
	{
		result.setConstantFlag(
				value1.getConstantFlag() && value2.getConstantFlag());
		if ((
				(value1.getValueType() == DINT_VALUE)
		||	(value1.getValueType() == INT_VALUE)
		||	(value1.getValueType() == DOUBLE_VALUE)
		)
		&&	(
				(value2.getValueType() == DINT_VALUE)
		||	(value2.getValueType() == INT_VALUE)
		||	(value2.getValueType() == DOUBLE_VALUE)
		))
		{
			result.setFltConstant(
					value1.getFltValue() / value2.getFltValue(),
					monitorTime);
		}
		else
		{
			return false;
		}
	}
	else if (!strcmp(thisOperator, "**"))
	{
		result.setConstantFlag(
				value1.getConstantFlag() && value2.getConstantFlag());
		if ((
				(value1.getValueType() == DINT_VALUE)
		||	(value1.getValueType() == INT_VALUE)
		||	(value1.getValueType() == DOUBLE_VALUE)
		)
		&&	(
				(value2.getValueType() == DINT_VALUE)
		||	(value2.getValueType() == INT_VALUE)
		||	(value2.getValueType() == DOUBLE_VALUE)
		))
		{
			result.setFltConstant(
					pow(value1.getFltValue(), value2.getFltValue()),
					monitorTime);
		}
		else
		{
			return false;
		}
	}
	else if ((!strcmp(thisOperator, "&&")) || (!strcmp(thisOperator, "&")))
	{
		if ((value1.getConstantFlag() && value1.getIntValue() <= 0)
		||	(value2.getConstantFlag() && value2.getIntValue() <= 0)
		||	(value1.getConstantFlag() && value2.getConstantFlag()))
		{
			result.setConstantFlag(true);
		}

		if ((
				(value1.getValueType() == DINT_VALUE)
		||	(value1.getValueType() == INT_VALUE)
		||	(value1.getValueType() == DOUBLE_VALUE)
		)
		&&	(
				(value2.getValueType() == DINT_VALUE)
		||	(value2.getValueType() == INT_VALUE)
		||	(value2.getValueType() == DOUBLE_VALUE)
		))
		{
			result.setDIntConstant(
					value1.getIntValue() && value2.getIntValue(),
					monitorTime);
		}
		else
		{
			return false;
		}
	}
	else if ((!strcmp(thisOperator, "||")) || (!strcmp(thisOperator, "|")))
	{
		if ((value1.getConstantFlag() && value1.getIntValue() > 0)
		||	(value2.getConstantFlag() && value2.getIntValue() > 0)
		||	(value1.getConstantFlag() && value2.getConstantFlag()))
		{
			result.setConstantFlag(true);
		}

		if ((
				(value1.getValueType() == DINT_VALUE)
		||	(value1.getValueType() == INT_VALUE)
		||	(value1.getValueType() == DOUBLE_VALUE)
		)
		&&	(
				(value2.getValueType() == DINT_VALUE)
		||	(value2.getValueType() == INT_VALUE)
		||	(value2.getValueType() == DOUBLE_VALUE)
		))
		{
			result.setDIntConstant(
					value1.getIntValue() || value2.getIntValue(),
					monitorTime);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	return true;
}

bool CContext::evalFunction(
	CValue	&result,
	const CRefStringPtr &identifier,
	char funcSeperator,
	int paraCount,
	CValue **paraList)
{
	if (identifier->equal("atof"))
	{
		if (paraCount != 1)
		{
			return false;
		}

		return myAtof(result, paraList);
	}
	else if (identifier->equal("itoa"))
	{
		if (paraCount != 2)
		{
			return false;
		}

		return myItoa(result, paraList);
	}
	else if (identifier->equal("atoi"))
	{
		if (paraCount != 1)
		{
			return false;
		}

		return myAtoi(result, paraList);
	}
	else if (identifier->equal("getValue"))
	{
		if (paraCount != 3)
		{
			return false;
		}

		return getValue(result, paraList);
	}
	else if (identifier->equal("if"))
	{
		if (paraCount != 3)
		{
			return false;
		}

		return ifFunc(result, paraList);
	}
	else if (identifier->equal("Ttoi"))
	{
		if (paraCount != 1)
		{
			return false;
		}

		return Ttoi(result, paraList);
	}
	else if (identifier->equal("Itot"))
	{
		if (paraCount != 1)
		{
			return false;
		}

		return Itot(result, paraList);
	}
	else if (identifier->equal("nowbetween"))
	{
		if (paraCount != 2)
		{
			return false;
		}

		return nowbetween(result, paraList);
	}
	else if (identifier->equal("valbetween"))
	{
		if (paraCount != 3)
		{
			return false;
		}

		return valbetween(result, paraList);
	}
	else if (identifier->equal("ObjectIn"))
	{
		if (paraCount < 2)
		{
			return false;
		}

		return ObjectIn(result, paraCount, paraList);
	}
	else if (identifier->equal("ObjectContain"))
	{
		if (paraCount < 2)
		{
			return false;
		}

		return ObjectContain(result, paraCount, paraList);
	}
	else if (identifier->equal("getdatediff"))
	{
		if (paraCount != 2)
		{
			return false;
		}

		return getdatediff(result, paraList);
	}
	else if (identifier->equal("gettimediff"))
	{
		if (paraCount != 2)
		{
			return false;
		}

		return gettimediff(result, paraList);
	}
	else if (identifier->equal("getTimeGap"))
	{
		if (paraCount != 2)
		{
			return false;
		}

		return getTimeGap(result, paraList);
	}
	else if (identifier->equal("getperiod"))
	{
		if (paraCount != 1)
		{
			return false;
		}

		return getperiod(result, paraList);
	}
	else if (identifier->equal("Summary"))
	{
		if (paraCount != 2)
		{
			return false;
		}

		return Summary(result, paraList);
	}
	else if (identifier->equal("ObjectEventSummary"))
	{
		if (paraCount != 3)
		{
			return false;
		}

		return ObjectEventSummary(result, paraList);
	}
	else if (identifier->equal("Exist"))
	{
		if (paraCount != 2)
		{
			return false;
		}

		return Exist(result, paraList);
	}
	else if (identifier->equal("ObjectEventExist"))
	{
		if (paraCount != 3)
		{
			return false;
		}

		return ObjectEventExist(result, paraList);
	}
	else if (identifier->equal("CheckEventOccur"))
	{
		if (paraCount != 5)
		{
			return false;
		}

		return CheckEventOccur(result, paraList);
	}
	else if (identifier->equal("IsWorkingDay"))
	{
		return IsWorkingDay(result, paraList);
	}
	else if (identifier->equal("CheckEventDesc"))
	{
		if (paraCount != 5)
		{
			return false;
		}

		return CheckEventDesc(result, paraList);
	}
	else if (identifier->equal("CheckEventValid"))
	{
		if (paraCount != 5)
		{
			return false;
		}

		return CheckEventValid(result, paraList);
	}
	else if (identifier->equal("CheckEventDescExist"))
	{
		if (paraCount != 5)
		{
			return false;
		}

		return CheckEventDescExist(result, paraList);
	}
	else if (identifier->equal("CheckEventDescValue"))
	{
		return CheckEventDescValue(result, paraCount, paraList);
	}
	else if (identifier->equal("CheckEventDescValueOR"))
	{
		return CheckEventDescValueOR(result, paraCount, paraList);
	}
	else if (identifier->equal("GetEventTimeByDescValue"))
	{
		return GetEventTimeByDescValue(result, paraCount, paraList);
	}
	else if (identifier->equal("GetEventTimeByDescValueOR"))
	{
		return GetEventTimeByDescValueOR(result, paraCount, paraList);
	}
	else if (identifier->equal("getEventDesc"))
	{
		if (paraCount != 4)
		{
			return false;
		}

		return getEventDesc(result, paraList);
	}
	else if (identifier->equal("getStringId"))
	{
		if (paraCount != 1)
		{
			return false;
		}

		return getStringId(result, paraList);
	}
	else if (identifier->equal("getmaincentername"))
	{
		return getmaincentername(result, paraList);
	}
	else if (identifier->equal("getSystemName"))
	{
		result.setConstantFlag(true);
		return getSystemName(result, paraList);
	}
	else if (identifier->equal("getDomainName"))
	{
		result.setConstantFlag(true);
		if (paraCount != 3)
		{
			return false;
		}

		return getDomainName(result, paraList);
	}
	else if (identifier->equal("getactiveapp"))
	{
		return getactiveapp(result, paraList);
	}
	else if (identifier->equal("IsTradingDay"))
	{
		return IsTradingDay(result, paraCount, paraList);
	}
	else if (identifier->equal("IsContinuousTradingDay"))
	{
		return IsContinuousTradingDay(result, paraCount, paraList);
	}
	else if (identifier->equal("IsDayTradingPeriod"))
	{
		return IsDayTradingPeriod(result, paraCount, paraList);
	}
	else if (identifier->equal("IsNightTradingPeriod"))
	{
		return IsNightTradingPeriod(result, paraCount, paraList);
	}
	else if (identifier->equal("IsTradingPeriod"))
	{
		return IsTradingPeriod(result, paraCount, paraList);
	}	
	else if(identifier->equal("HasNightTradingPeriod"))
	{
		return HasNightTradingPeriod(result, paraCount, paraList);
	}
	else
	{
#ifdef PRINT_DEBUG
		printf(
			"运行文件 ： %s 行数：%d paraCount %d %s\n",
			__FILE__,
			__LINE__,
			paraCount,
			identifier->getValue());
		paraList[0]->display();
#endif
		if (paraCount != 1
		||	(
				paraList[0]->getValueType() != INT_VALUE
		&&	paraList[0]->getValueType() != DINT_VALUE
		&&	paraList[0]->getValueType() != DOUBLE_VALUE
		))
		{
			return false;
		}

		int subObId, itemId;
		if (g_mStringIdMap.getStringSubId(
				subObId,
			itemId,
			identifier->getValue()) >= 0)
		{
			result.setListValue(subObId);
			result.setListValue(itemId);
			result.setListValue(paraList[0]->getIntValue());
			return true;
		}
	}

	return false;
}

bool CContext::ifFunc(CValue &result, CValue **paraList)
{
	if (paraList[0]->getValueType() != INT_VALUE
	&&	paraList[0]->getValueType() != DINT_VALUE
	&&	paraList[0]->getValueType() != DOUBLE_VALUE)
	{
		return false;
	}

	if (paraList[0]->getIntValue())
	{
		result = *(paraList[1]);
	}
	else
	{
		result = *(paraList[2]);
	}

	return true;
}

bool CContext::getValue(CValue &result, CValue **paraList)
{
	if ((paraList[0]->getValueType() != OBJECT_VALUE)
	||	(paraList[1]->getValueType() != OBJECT_VALUE)
	||	(paraList[2]->getValueType() != INT_VALUE))
	{
		return false;
	}

	getItemValue(
		result,
		paraList[0]->getObjectValue(),
		paraList[1]->getObjectValue(),
		paraList[2]->getIntValue());
	return true;
}

bool CContext::myAtof(CValue &result, CValue **paraList)
{
	if (paraList[0]->getValueType() == INT_VALUE
	||	paraList[0]->getValueType() == DINT_VALUE
	||	paraList[0]->getValueType() == DOUBLE_VALUE)
	{
		result = *(paraList[0]);
		return true;
	}

	if (paraList[0]->getValueType() != STRING_VALUE)
	{
		return false;
	}

	result.setFltConstant(atof(paraList[0]->getStringValue()->getValue()), 0);
	return true;
}

bool CContext::myItoa(CValue &result, CValue **paraList)
{
	char buffer[1024];
	if ((paraList[0]->getValueType() != INT_VALUE)
	||	(paraList[1]->getValueType() != INT_VALUE))
	{
		return false;
	}

	int len = paraList[1]->getIntValue();
	if (len != 0)
	{
		sprintf(buffer, "%0*d", len, paraList[0]->getIntValue());
	}
	else
	{
		sprintf(buffer, "%d", paraList[0]->getIntValue());
	}

	char *p = new char[strlen(buffer) + 1];
	strcpy(p, buffer);
	result.setStringConstant(new CRefString(p), paraList[0]->getDTimeValue());
	delete p;
	return true;
}

bool CContext::myAtoi(CValue &result, CValue **paraList)
{
	if (paraList[0]->getValueType() == INT_VALUE)
	{
		result = *(paraList[0]);
		return true;
	}
	else if (paraList[0]->getValueType() == DINT_VALUE)
	{
		result = *(paraList[0]);
		return true;
	}

	if (paraList[0]->getValueType() != STRING_VALUE)
	{
		return false;
	}

	result.setIntegerConstant(atoi(paraList[0]->getStringValue()->getValue()));
	return true;
}

bool CContext::Ttoi(CValue &result, CValue **paraList)
{
	if (paraList[0]->getValueType() != STRING_VALUE)
	{
		return false;
	}

	char *p = (char *)paraList[0]->getStringValue()->getValue();
	result.setIntegerConstant(3600 * atoi(p) + 60 * atoi(p + 3) + atoi(p + 6));
	return true;
}

bool CContext::Itot(CValue &result, CValue **paraList)
{
	if (paraList[0]->getValueType() != INT_VALUE
	&&	paraList[0]->getValueType() != DINT_VALUE)
	{
		return false;
	}

	char buffer[20];
	sprintf(
		buffer,
		"%02d:%02d:%02d",
		paraList[0]->getIntValue() / 3600,
		(paraList[0]->getIntValue() % 3600) / 60,
		paraList[0]->getIntValue() % 60);

	char *p = new char[strlen(buffer) + 1];
	strcpy(p, buffer);
	result.setStringConstant(new CRefString(p), paraList[0]->getDTimeValue());
	delete p;

	//	result.setStringConstant(buffer);
	return true;
}

bool CContext::nowbetween(CValue &result, CValue **paraList)
{
	time_t nowTime = m_now;
	struct tm tm_time;
	LocalTime(&nowTime, &tm_time);
	int seconds = tm_time.tm_sec + tm_time.tm_hour * 3600 + tm_time.tm_min * 60;
	if (paraList[0]->getValueType() != STRING_VALUE
	||	paraList[1]->getValueType() != STRING_VALUE)
	{
		return false;
	}

	char *p = (char *)paraList[0]->getStringValue()->getValue();
	if (seconds < 3600 * atoi(p) + 60 * atoi(p + 3) + atoi(p + 6))
	{
		result.setIntegerConstant(0);
		return true;
	}

	p = (char *)paraList[1]->getStringValue()->getValue();
	if (seconds > 3600 * atoi(p) + 60 * atoi(p + 3) + atoi(p + 6))
	{
		result.setIntegerConstant(0);
		return true;
	}

	result.setIntegerConstant(1);
	return true;
}

bool CContext::valbetween(CValue &result, CValue **paraList)
{
	result.setIntegerConstant(0);
	if (paraList[0]->getValueType() == STRING_VALUE)
	{
		if (strcmp(
				paraList[0]->getStringValue()->getValue(),
			paraList[1]->getStringValue()->getValue()) >= 0
		&&	strcmp(
				paraList[0]->getStringValue()->getValue(),
			paraList[2]->getStringValue()->getValue()) < 0)
		{
			result.setIntegerConstant(1);
		}
		else
		{
			result.setIntegerConstant(0);
		}
	}
	else if (paraList[0]->getValueType() == INT_VALUE)
	{
		if (paraList[0]->getIntValue() >= paraList[1]->getIntValue()
		&&	paraList[0]->getIntValue() < paraList[2]->getIntValue())
		{
			result.setIntegerConstant(1);
		}
		else
		{
			result.setIntegerConstant(0);
		}
	}
	else if (paraList[0]->getValueType() == DOUBLE_VALUE
		 ||	 paraList[0]->getValueType() == PERCENT_VALUE)
	{
		if (paraList[0]->getFltValue() >=
				(paraList[1]->getFltValue() + paraList[1]->getIntValue())
		&&	paraList[0]->getFltValue() <
				(paraList[2]->getIntValue() + paraList[2]->getIntValue()))
		{
			result.setIntegerConstant(1);
		}
		else
		{
			result.setIntegerConstant(0);
		}
	}

	return true;
}

bool CContext::ObjectIn(CValue &result, int paraCount, CValue **paraList)
{
	char *pObject = (char *)paraList[0]->getStringValue()->getValue();
	char *pValue = NULL;

	/// 暂时认为需要对比的对象及值集均为字串常量,仅计算一次
	result.setConstantFlag(true);
	for (int i = 1; i < paraCount; i++)
	{
		pValue = (char *)paraList[i]->getStringValue()->getValue();
		if (strcmp(pObject, pValue) == 0)
		{
			result.setIntegerConstant(1);
			return true;
		}
	}

	result.setIntegerConstant(0);
	return true;
}

bool CContext::ObjectContain(CValue &result, int paraCount, CValue **paraList)
{
	char *pObject = (char *)paraList[0]->getStringValue()->getValue();
	char *pValue = NULL;

	/// 暂时认为需要对比的对象及值集均为字串常量,仅计算一次
	result.setConstantFlag(true);
	for (int i = 1; i < paraCount; i++)
	{
		pValue = (char *)paraList[i]->getStringValue()->getValue();
		if (strstr(pObject, pValue) != NULL)
		{
			result.setIntegerConstant(1);
			return true;
		}
	}

	result.setIntegerConstant(0);
	return true;
}

bool CContext::gettimediff(CValue &result, CValue **paraList)
{
	if (paraList[0]->getValueType() != STRING_VALUE
	||	paraList[1]->getValueType() != STRING_VALUE)
	{
		return false;
	}

	char *p = NULL;
	p = (char *)paraList[0]->getStringValue()->getValue();

	int time1 = 3600 * atoi(p) + 60 * atoi(p + 3) + atoi(p + 6);
	p = (char *)paraList[1]->getStringValue()->getValue();

	int time2 = 3600 * atoi(p) + 60 * atoi(p + 3) + atoi(p + 6);
	result.setIntegerConstant(time2 - time1);
	return true;
}

int CContext::getTimeSec(CValue * pTimeValue)
{
	int iTime = 0;

	if (pTimeValue->getValueType() == INT_VALUE)
	{
		iTime = pTimeValue->getIntValue();
	}
	else if(pTimeValue->getValueType() == DINT_VALUE)
	{
		iTime = pTimeValue->getDIntValue();
	}
	else if(pTimeValue->getValueType() == STRING_VALUE)
	{
		char *q = (char *)pTimeValue->getStringValue()->getValue();
		char szTmp[32];
		SNPRINTF(szTmp, 30, q);
		char *p = szTmp;
		int iLen = strlen(q);
		if (iLen >= 17 || iLen == 8)	
		{
			if (iLen >= 17)		// "20151123 08:10:01"
			{
				struct tm sDate;
				memset(&sDate, 0x00, sizeof(sDate));
				sDate.tm_mday = atoi(p + 6);
				*(p + 6) = 0x00;
				sDate.tm_mon = atoi(p + 4) - 1;
				*(p + 4) = 0x00;
				sDate.tm_year = atoi(p) - 1900;		
				iTime = mktime(&sDate);
				p += 9;
			}				
			// "08:10:01"
			iTime += 3600 * atoi(p) + 60 * atoi(p + 3) + atoi(p + 6);
		}
		//printf("getTimeSec:[%s] [%d]\n", q, iTime);
	}
	
	return iTime;
}

bool CContext::getTimeGap(CValue &result, CValue **paraList)
{
	int time1 = getTimeSec(paraList[0]);
	int time2 = getTimeSec(paraList[1]);
	int iTime = 0;

	if (time1 <= 86400 || time2 <= 86400)
	{
		/// 不包含日期的时间值比较,排除时区差异
		time1 = time1 > 86400 ? (time1 - g_iTimeZoneOffset) % 86400 : time1;
		time2 = time2 > 86400 ? (time2 - g_iTimeZoneOffset) % 86400 : time2;

		/// 保证TimeGap取出来为正值
		if (time1 > time2)
		{
			iTime = time1 - time2;
		}
		else
		{
			iTime = time2 - time1;
		}

		/// 认为正常情况下差距不应如此巨大，考虑可能是因为跨天时偏移造成，尝试修正。
		if (iTime > 80000)
			iTime = 86400 - iTime;
	}
	else
	{
		/// 包含日期的时间值比较
		/// 保证TimeGap取出来为正值
		if (time1 > time2)
		{
			iTime = time1 - time2;
		}
		else
		{
			iTime = time2 - time1;
		}
	}
	//printf("Time1[%d]\nTime2[%d]\ngap[%d]\n\n\n", time1, time2, iTime);

	result.setIntegerConstant(iTime);

	return true;
}

bool CContext::getdatediff(CValue &result, CValue **paraList)
{
	if (paraList[0]->getValueType() != STRING_VALUE
	||	paraList[1]->getValueType() != STRING_VALUE)
	{
		return false;
	}

	char szDate1[10], szDate2[10];
	struct tm date1, date2;

	strncpy(szDate1, (char *)paraList[0]->getStringValue()->getValue(), 9);
	strncpy(szDate2, (char *)paraList[1]->getStringValue()->getValue(), 9);

	char *p = NULL;
	p = szDate1;
	memset(&date1, 0x00, sizeof(date1));
	memset(&date2, 0x00, sizeof(date2));
	date1.tm_mday = atoi(p + 6);
	*(p + 6) = 0x00;
	date1.tm_mon = atoi(p + 4) - 1;
	*(p + 4) = 0x00;
	date1.tm_year = atoi(p) - 1900;
	p = szDate2;
	date2.tm_mday = atoi(p + 6);
	*(p + 6) = 0x00;
	date2.tm_mon = atoi(p + 4) - 1;
	*(p + 4) = 0x00;
	date2.tm_year = atoi(p) - 1900;
	result.setIntegerConstant((mktime(&date2) - mktime(&date1)) / 86400);
	return true;
}

bool CContext::getperiod(CValue &result, CValue **paraList)
{
	result.setIntegerConstant(
			g_pDataCenter->getAttrInterval(
					paraList[0]->getStringValue()->getValue()));
	return true;
}

bool CContext::Summary(CValue &result, CValue **paraList)
{
	CEventEntity *pEventEntity;
	int iNum = 0, iCount = 0;
	int iEventId = g_mStringIdMap.getStringId(
			paraList[0]->getStringValue()->getValue());
	pEventEntity = g_mExprDB->m_EventEntityFactory->startFindByKey(
			iEventId,
			m_now);

	while (pEventEntity)
	{
		iCount++;

		/// Mod by Henchi, 20130130
				/// 不再限制记录时间，而通过条数控制遍历范围和强度
		if (iCount > 1000
		||	(pEventEntity->MonitorTime < m_now - paraList[1]->getIntValue()))
		{
			break;
		}

		if (strcmp(pEventEntity->ProcessFlag.getValue(), "L") == 0)
		{
			iNum++;
		}

		/// Add by Henchi, 20131211
		/// 无需记录过多历史内容
		if (iNum <= 3)
		{
			RECORDWARNINGINFO_EVENT;
		}
		pEventEntity = g_mExprDB->m_EventEntityFactory->findNextByKey();
	}

	g_mExprDB->m_EventEntityFactory->endFindByKey();

	result.setDIntConstant(iNum, m_now);
	return true;
}

bool CContext::ObjectEventSummary(CValue &result, CValue **paraList)
{
	CEventEntity *pEventEntity;
	int iNum = 0, iCount = 0;
	int iObjectId = g_mStringIdMap.getStringId(
			paraList[0]->getStringValue()->getValue());
	int iEventId = g_mStringIdMap.getStringId(
			paraList[1]->getStringValue()->getValue());
	pEventEntity = g_mExprDB->m_EventEntityFactory->startFindByObject(
			iObjectId,
			iEventId,
			m_now);

	while (pEventEntity)
	{
		/// Mod by Henchi, 20130130
				/// 不再限制记录时间，而通过条数控制遍历范围和强度
		iCount++;		/// 通过iCount记录遍历的强度，以避免ProcessFlag不为L/C的事件影响。

		//if ((pEventEntity->MonitorTime  < m_now - 300 )
		if (iCount > 1000
		||	(pEventEntity->MonitorTime < m_now - paraList[2]->getIntValue()))
		{
			break;
		}

		/// 注意：当不以“L/C”标识事件时，可能需要添加相应判断处理。
		if (strcmp(pEventEntity->ProcessFlag.getValue(), "L") == 0)
		{
			iNum++;
		}

		/// Add by Henchi, 20131211
		/// 无需记录过多历史内容
		if (iNum <= 3)
		{
			RECORDWARNINGINFO_EVENT;
		}
		pEventEntity = g_mExprDB->m_EventEntityFactory->findNextByObject();
	}

	g_mExprDB->m_EventEntityFactory->endFindByObject();

	result.setDIntConstant(iNum, m_now);
	return true;
}

bool CContext::Exist(CValue &result, CValue **paraList)
{
	CEventEntity *pEventEntity;
	int iNum = 0;		// 默认为没找到
	int iEventId = g_mStringIdMap.getStringId(
			paraList[0]->getStringValue()->getValue());
	pEventEntity = g_mExprDB->m_EventEntityFactory->startFindByKey(
			iEventId,
			m_now);
	if (pEventEntity != NULL
	&&	(pEventEntity->MonitorTime >= m_now - paraList[1]->getDIntValue()))
	{
		RECORDWARNINGINFO_EVENT;
		iNum = 1;
	}

	g_mExprDB->m_EventEntityFactory->endFindByKey();

	result.setDIntConstant(iNum, m_now);
	return true;
}

bool CContext::ObjectEventExist(CValue &result, CValue **paraList)
{
	CEventEntity *pEventEntity;
	int iNum = 0;
	int iObjectId = g_mStringIdMap.getStringId(
			paraList[0]->getStringValue()->getValue());
	int iEventId = g_mStringIdMap.getStringId(
			paraList[1]->getStringValue()->getValue());
	pEventEntity = g_mExprDB->m_EventEntityFactory->startFindByObject(
			iObjectId,
			iEventId,
			m_now);
	if (pEventEntity != NULL
	&&	(pEventEntity->MonitorTime >= m_now - paraList[2]->getDIntValue()))
	{
		RECORDWARNINGINFO_EVENT;
		iNum = 1;
	}

	g_mExprDB->m_EventEntityFactory->endFindByObject();

	result.setDIntConstant(iNum, m_now);
	return true;
}

bool IntCheckValue(int iLeft, const char *pOpr, int iRight)
{
	if (strncmp("eq", pOpr, 2) == 0)
	{
		return iLeft == iRight;
	}
	else if (strncmp("ne", pOpr, 2) == 0)
	{
		return iLeft != iRight;
	}
	else if (strncmp("le", pOpr, 2) == 0)
	{
		return iLeft <= iRight;
	}
	else if (strncmp("ge", pOpr, 2) == 0)
	{
		return iLeft >= iRight;
	}
	else if (strncmp("lt", pOpr, 2) == 0)
	{
		return iLeft < iRight;
	}
	else if (strncmp("gt", pOpr, 2) == 0)
	{
		return iLeft > iRight;
	}
	else
	{
		return false;
	}
}

bool strCheckValue(const char *pSource, const char *pOpr, int iValue)
{
	int iSource = 0;
	if (strncmp(pSource, "0x", 2) == 0 && strlen(pSource) == 6)
	{
		sscanf(pSource, "%x", &iSource);
	}
	else
	{
		iSource = atoi(pSource);
	}

	return IntCheckValue(iSource, pOpr, iValue);
}

bool strCheckValue(const char *pSource, const char *pOpr, const char *pValue)
{
	int iValue = strcmp(pSource, pValue);
	return IntCheckValue(iValue, pOpr, 0);
}

bool CheckStrValue(const char *pSource, const char *pOpr, CValue *pValue)
{
	if (pOpr[2] == 's') // like "eqs"
	{
		/// String mode
		return strCheckValue(
				pSource,
				pOpr,
				pValue->getStringValue()->getValue());
	}
	else				// like "eq"
	{
		/// Int mode
		return strCheckValue(pSource, pOpr, pValue->getIntValue());
	}
}

///检查pSource字符中是否包含pKey='pValue'的字串函数
bool strCheckOccur(const char *pSource, const char *pKey, const char *pValue)
{
	char *q;

	char *p = (char *)pSource;
	q = strstr(p, pKey);
	while (NULL != q)
	{
		p = q + strlen(pKey);
		if (*p == '=')
		{
			p++;
			if (NULL != p && (*p == '\'' || *p == '\"'))
			{
				p++;
				if (memcmp(p, pValue, strlen(pValue)) == 0)
				{
					p = p + strlen(pValue);
					if (NULL == p
					||	*p == ' '
					||	*p == '\''
					||	*p == '\"'
					||	*p == ','
					||	*p == ';')
					{
						return true;
					}
				}
			}
		}

		if (NULL == p)
		{
			return false;
		}

		q = strstr(p, pKey);
	}

	return false;
}

bool strCheckValid_U(
	const char	*pSource,
	const char	*pKey,
	const char	*pValue,
	bool bDefault = false)
{
	char *q;

	char *p = (char *)pSource;
	char cSep;
	char szKey[32];
	char szValue[1024];
	if (pKey != NULL && strlen(pKey) < sizeof(szKey) - 2)
	{
		sprintf(szKey, "%s=", pKey);
	}
	else
	{
		return bDefault;
	}

	q = strstr(p, szKey);
	while (NULL != q)
	{
		p = q + strlen(pKey);
		while (p != NULL && *p != '=')
		{
			p++;
		}

		while (p != NULL && *p != '\'' && *p != '\"')
		{
			p++;
		}

		if (p == NULL)
		{
			return bDefault;
		}

		cSep = *p++;
		q = strchr(p, cSep);
		if (q != NULL)
		{
			strncpy(
				szValue,
				p,
				(q - p >= sizeof(szValue) ? sizeof(szValue) - 1 : q - p));
			return memcmp(szValue, pValue, strlen(pValue)) == 0;
		}

		q = strstr(p, szKey);
	}

	return bDefault;
}

bool CContext::IsWorkingDay(CValue &result, CValue **paraList)
{
	time_t timep = m_now;
	struct tm tm_time;
	if (LocalTime(&timep, &tm_time) != NULL)
	{
		if (tm_time.tm_wday > 0 && tm_time.tm_wday < 6)
		{
			result.setDIntConstant(1, m_now);
		}
		else
		{
			result.setDIntConstant(0, m_now);
		}
	}
	else
	{
		result.setDIntConstant(0, m_now);
	}

	return true;
}

bool CContext::IsDayTradingPeriod(CValue &result, int paraCount, CValue **paraList)
{
	char datevalue[10] = {0};
	char timevalue[10] = {0};
	
	if(paraCount == 0)
	{
		//查当前时间
		time_t timep = m_now;
		struct tm tm_time;
		LocalTime((time_t *) &timep, &tm_time);
		SNPRINTF(datevalue, 10, "%04d%02d%02d", tm_time.tm_year+1900,tm_time.tm_mon+1,tm_time.tm_mday);
		SNPRINTF(timevalue,10, "%02d:%02d:%02d",tm_time.tm_hour,tm_time.tm_min,tm_time.tm_sec);
	}
	else if(paraCount == 1)
	{
		//YYYYMMDD HH:MM::SS
		if (paraList[0]->getValueType() == STRING_VALUE)
		{
			if(strlen((char *)paraList[0]->getStringValue()->getValue()) != 17)
			{
				printf("time str %s invalid,should be YYYYMMDD HH:MM:SS in %s\n"
					, (char *)paraList[0]->getStringValue()->getValue()
					, __FUNCTION__);
				return false;
			}

			strncpy(datevalue, (char *)paraList[0]->getStringValue()->getValue(), 8);
			strncpy(timevalue, (char *)(paraList[0]->getStringValue()->getValue() + 9), 8);		
		}
		else if(paraList[0]->getValueType() == INT_VALUE)
		{
			//传int时刻
			time_t inputtime = paraList[0]->getDIntValue();
			struct tm tm_time;
			LocalTime(&inputtime, &tm_time);
			SNPRINTF(datevalue, 10, "%04d%02d%02d",
				tm_time.tm_year + 1900,
				tm_time.tm_mon + 1,
				tm_time.tm_mday);	

			
			SNPRINTF(timevalue, 10, "%02d:%02d:%02d",
				tm_time.tm_hour,
				tm_time.tm_min,
				tm_time.tm_sec);
		}
		else
		{
			printf("input para type:%d invalid in %s\n", paraList[0]->getValueType(), __FUNCTION__);		
			return false;
		}
	}
	else
	{
		printf("input para count:%d invalid in %s\n", paraCount, __FUNCTION__);
		return false;
	}	

	if(((strcmp(timevalue, "08:55:00")>=0 && strcmp(timevalue, "10:15:00")<0)
		||(strcmp(timevalue, "10:30:00")>=0 && strcmp(timevalue, "11:30:00")<0)
		||(strcmp(timevalue, "13:30:00")>=0 && strcmp(timevalue, "15:00:00")<0))	
	  && g_calender.isTradingDay((string)datevalue)
	)
	{
		result.setIntegerConstant(1);	
	}
	else
	{
		result.setIntegerConstant(0);		
	}
	return true;
}

bool CContext::IsNightTradingPeriod(CValue &result, int paraCount, CValue **paraList)
{
	char datevalue[10] = {0};
	char timevalue[10] = {0};
	
	if(paraCount == 0)
	{
		//查当前时间
		time_t timep = m_now;
		struct tm tm_time;
		LocalTime((time_t *) &timep, &tm_time);
		SNPRINTF(datevalue, 10, "%04d%02d%02d", tm_time.tm_year+1900,tm_time.tm_mon+1,tm_time.tm_mday);
		SNPRINTF(timevalue,10, "%02d:%02d:%02d",tm_time.tm_hour,tm_time.tm_min,tm_time.tm_sec);
	}
	else if(paraCount == 1)
	{
		//YYYYMMDD HH:MM::SS
		if (paraList[0]->getValueType() == STRING_VALUE)
		{
			if(strlen((char *)paraList[0]->getStringValue()->getValue()) != 17)
			{
				printf("time str %s invalid,should be YYYYMMDD HH:MM:SS in %s\n"
					, (char *)paraList[0]->getStringValue()->getValue()
					, __FUNCTION__);
				return false;
			}

			strncpy(datevalue, (char *)paraList[0]->getStringValue()->getValue(), 8);
			strncpy(timevalue, (char *)(paraList[0]->getStringValue()->getValue() + 9), 8);		
		}
		else if(paraList[0]->getValueType() == INT_VALUE)
		{
			//传int时刻
			time_t inputtime = paraList[0]->getDIntValue();
			struct tm tm_time;
			LocalTime(&inputtime, &tm_time);			SNPRINTF(datevalue, 10, "%04d%02d%02d",
				tm_time.tm_year + 1900,
				tm_time.tm_mon + 1,
				tm_time.tm_mday);	

			SNPRINTF(timevalue, 10, "%02d:%02d:%02d",
				tm_time.tm_hour,
				tm_time.tm_min,
				tm_time.tm_sec);
		}
		else
		{
			printf("input para type:%d invalid in %s\n", paraList[0]->getValueType(), __FUNCTION__);
			return false;
		}
	}
	else
	{
		printf("input para count:%d invalid in %s\n", paraCount, __FUNCTION__);
		return false;
	}

	if((strcmp(timevalue, "20:55:00")>=0 && strcmp(timevalue, "23:59:59")<=0 && g_calender.isContinuousDay(stDate((const char *)datevalue))) 
		||(strcmp(timevalue, "00:00:00")>=0 && strcmp(timevalue, "02:30:00")<0) && g_calender.AfterContinuousDay(stDate((const char *)datevalue))
		)
	{
		result.setIntegerConstant(1);	
	}
	else
	{
		result.setIntegerConstant(0);		
	}
	return true;
}

bool CContext::IsContinuousTradingDay(CValue &result, int paraCount, CValue **paraList)
{
	//是否在非交易日列表中
	char datevalue[10] = {0};
	
	if(paraCount == 0)
	{
		//查当前时间
		time_t timep = m_now;
		struct tm tm_time;
		LocalTime((time_t *) &timep, &tm_time);
		SNPRINTF(datevalue, 10, "%04d%02d%02d", tm_time.tm_year+1900,tm_time.tm_mon+1,tm_time.tm_mday);
	}
	else if(paraCount == 1)
	{
		//YYYYMMDD
		if (paraList[0]->getValueType() == STRING_VALUE)
		{
			strncpy(datevalue, (char *)paraList[0]->getStringValue()->getValue(), 10);
		}
		else if(paraList[0]->getValueType() == INT_VALUE)
		{
			//传int时刻
			time_t inputtime = paraList[0]->getDIntValue();
			struct tm tm_time;
			LocalTime(&inputtime, &tm_time);			SNPRINTF(datevalue, 10, "%04d%02d%02d",
				tm_time.tm_year + 1900,
				tm_time.tm_mon + 1,
				tm_time.tm_mday);	
		}
		else
		{
			printf("input para type:%d invalid in %s\n", paraList[0]->getValueType(), __FUNCTION__);
			return false;
		}		
	}
	else if(paraCount == 3)
	{
		//YYYY MM DD
		if(paraList[0]->getValueType() == INT_VALUE&&
		   paraList[1]->getValueType() == INT_VALUE&&
		   paraList[2]->getValueType() == INT_VALUE)
		{
			SNPRINTF(datevalue, 10, "%04d%02d%02d", 
				paraList[0]->getDIntValue(),
				paraList[1]->getDIntValue(),
				paraList[2]->getDIntValue());
		}
		else
		{
			printf("param form:YYYY,MM,DD(int type), please check in %s!\n", __FUNCTION__);
			return false;
		}	
	}
	else
	{
		printf("invalid paraCount:%d in %s\n", paraCount, __FUNCTION__);
		return false;
	}

	if(g_calender.isContinuousDay((const char *)datevalue))
	{
		result.setIntegerConstant(1);
	}
	else
	{
		result.setIntegerConstant(0);
	}
	return true;
}

bool CContext::IsTradingPeriod(CValue &result, int paraCount, CValue **paraList)
{	
	if (IsDayTradingPeriod(result, paraCount, paraList))
	{
		if (result.getDIntValue() == 0)
			return IsNightTradingPeriod(result, paraCount, paraList);
	}
	else
	{
		result.setIntegerConstant(0);
		return false;
	}
}

bool CContext::IsTradingDay(CValue &result, int paraCount, CValue **paraList)
{
	char datevalue[10] = {0};
	
	if(paraCount == 0)
	{
		//查当前时间
		time_t timep = m_now;
		struct tm tm_time;
		LocalTime((time_t *) &timep, &tm_time);
		SNPRINTF(datevalue, 10, "%04d%02d%02d", tm_time.tm_year+1900,tm_time.tm_mon+1,tm_time.tm_mday);
	}
	else if(paraCount == 1)
	{
		//YYYYMMDD
		if (paraList[0]->getValueType() == STRING_VALUE)
		{
			strncpy(datevalue, (char *)paraList[0]->getStringValue()->getValue(), 10);
		}
		else if(paraList[0]->getValueType() == INT_VALUE)
		{
			//传int时刻
			time_t inputtime = paraList[0]->getDIntValue();
			struct tm tm_time;
			LocalTime(&inputtime, &tm_time);			SNPRINTF(datevalue, 10, "%04d%02d%02d",
				tm_time.tm_year + 1900,
				tm_time.tm_mon + 1,
				tm_time.tm_mday);	
		}
		else
		{
			printf("input para type:%d invalid in %s\n", paraList[0]->getValueType(), __FUNCTION__);
			return false;
		}		
	}
	else if(paraCount == 3)
	{
		//YYYY MM DD
		if(paraList[0]->getValueType() == INT_VALUE&&
		   paraList[1]->getValueType() == INT_VALUE&&
		   paraList[2]->getValueType() == INT_VALUE)
		{
			SNPRINTF(datevalue, 10, "%04d%02d%02d", 
				paraList[0]->getDIntValue(),
				paraList[1]->getDIntValue(),
				paraList[2]->getDIntValue());
		}
		else
		{
			printf("param form:YYYY,MM,DD(int type), please check in %s!\n", __FUNCTION__);
			return false;
		}	
	}
	else
	{
		printf("invalid paraCount:%d in %s\n", paraCount, __FUNCTION__);
		return false;
	}

	if(g_calender.isTradingDay((string)datevalue))
	{
		result.setIntegerConstant(1);
	}
	else
	{
		result.setIntegerConstant(0);
	}
	return true;
}

///HasNightTradingPeriod函数,判断给定的日期是否有夜盘
///@param	result	保存函数计算结果值
///@param	paraCount	保存参数个数			
///@param	paraList	getDomainName函数的参数列表
///@return	返回结果,为true表示成功,false表示失败
bool CContext::HasNightTradingPeriod(CValue &result, int paraCount, CValue **paraList)
{
	char datevalue[10] = {0};
	
	if(paraCount == 0)
	{
		//查当前时间
		time_t timep = m_now;
		struct tm tm_time;
		LocalTime((time_t *) &timep, &tm_time);
		SNPRINTF(datevalue, 10, "%04d%02d%02d", tm_time.tm_year+1900,tm_time.tm_mon+1,tm_time.tm_mday);
	}
	else if(paraCount == 1)
	{
		//YYYYMMDD
		if (paraList[0]->getValueType() == STRING_VALUE)
		{
			strncpy(datevalue, (char *)paraList[0]->getStringValue()->getValue(), 10);
		}
		else if(paraList[0]->getValueType() == INT_VALUE)
		{
			//传int时刻
			time_t inputtime = paraList[0]->getDIntValue();
			struct tm tm_time;
			LocalTime(&inputtime, &tm_time);			SNPRINTF(datevalue, 10, "%04d%02d%02d",
				tm_time.tm_year + 1900,
				tm_time.tm_mon + 1,
				tm_time.tm_mday);	
		}
		else
		{
			printf("input para type:%d invalid in %s\n", paraList[0]->getValueType(), __FUNCTION__);
			return false;
		}		
	}
	else if(paraCount == 3)
	{
		//YYYY MM DD
		if(paraList[0]->getValueType() == INT_VALUE&&
		   paraList[1]->getValueType() == INT_VALUE&&
		   paraList[2]->getValueType() == INT_VALUE)
		{
			SNPRINTF(datevalue, 10, "%04d%02d%02d", 
				paraList[0]->getDIntValue(),
				paraList[1]->getDIntValue(),
				paraList[2]->getDIntValue());
		}
		else
		{
			printf("param form:YYYY,MM,DD(int type), please check in %s!\n", __FUNCTION__);
			return false;
		}	
	}
	else
	{
		printf("invalid paraCount:%d in %s\n", paraCount, __FUNCTION__);
		return false;
	}

	//非交易日或无夜盘交易日
	if(!g_calender.isTradingDay((const char *)datevalue) || g_calender.isNoNightTradingDay((const char *)datevalue))
	{
		result.setIntegerConstant(0);
	}
	else
	{
		result.setIntegerConstant(1);	
	}
	return true;
}

bool CContext::CheckEventOccur(CValue &result, CValue **paraList)
{
	CEventEntity *pEventEntity;
	int iNum = 0;
	int iObjectId = g_mStringIdMap.getStringId(
			paraList[0]->getStringValue()->getValue());
	int iEventId = g_mStringIdMap.getStringId(
			paraList[1]->getStringValue()->getValue());
	pEventEntity = g_mExprDB->m_EventEntityFactory->startFindByObject(
			iObjectId,
			iEventId,
			m_now);
	while (pEventEntity)
	{
		if ((pEventEntity->MonitorTime < m_now - paraList[2]->getDIntValue()))
		{
			iNum = 0;
			break;

			//result.setDIntConstant(0, pEventEntity->MonitorTime);
			//return true;
		}
		else
		{
			if (strCheckOccur(
					(const char *)pEventEntity->EventDes,
				paraList[3]->getStringValue()->getValue(),
				paraList[4]->getStringValue()->getValue()))
			{
				RECORDWARNINGINFO_EVENT;
				iNum = 1;
				break;
			}
		}

		pEventEntity = g_mExprDB->m_EventEntityFactory->findNextByObject();
	}

	g_mExprDB->m_EventEntityFactory->endFindByObject();

	result.setDIntConstant(iNum, m_now);
	return true;
}

bool CContext::CheckEventDesc(CValue &result, CValue **paraList)
{
	CEventEntity *pEventEntity;
	int iNum = 1;
	int iObjectId = g_mStringIdMap.getStringId(
			paraList[0]->getStringValue()->getValue());
	int iEventId = g_mStringIdMap.getStringId(
			paraList[1]->getStringValue()->getValue());
	pEventEntity = g_mExprDB->m_EventEntityFactory->startFindByObject(
			iObjectId,
			iEventId,
			m_now);
	while (pEventEntity)
	{
		if ((pEventEntity->MonitorTime < m_now - paraList[2]->getDIntValue()))
		{
			break;

			//result.setDIntConstant(0, pEventEntity->MonitorTime);
			//return true;
		}
		else
		{
			if (!strCheckOccur(
					(const char *)pEventEntity->EventDes,
				paraList[3]->getStringValue()->getValue(),
				paraList[4]->getStringValue()->getValue()))
			{
				RECORDWARNINGINFO_EVENT;
				iNum = 0;
				break;
			}
		}

		pEventEntity = g_mExprDB->m_EventEntityFactory->findNextByObject();
	}

	g_mExprDB->m_EventEntityFactory->endFindByObject();

	result.setDIntConstant(iNum, m_now);
	return true;
}

bool CContext::CheckEventValid(CValue &result, CValue **paraList)
{
	CEventEntity *pEventEntity;
	int iNum = 1;	/// 默认为合法
	int iObjectId = g_mStringIdMap.getStringId(
			paraList[0]->getStringValue()->getValue());
	int iEventId = g_mStringIdMap.getStringId(
			paraList[1]->getStringValue()->getValue());
	pEventEntity = g_mExprDB->m_EventEntityFactory->startFindByObject(
			iObjectId,
			iEventId,
			m_now);
	while (pEventEntity)
	{
		if ((pEventEntity->MonitorTime < m_now - paraList[2]->getDIntValue()))
		{
			break;
		}
		else
		{
			if (!strCheckValid_U(
					(const char *)pEventEntity->EventDes,
				paraList[3]->getStringValue()->getValue(),
				paraList[4]->getStringValue()->getValue(),
				true))
			{
				RECORDWARNINGINFO_EVENT;
				iNum = 0;
				break;
			}
		}

		pEventEntity = g_mExprDB->m_EventEntityFactory->findNextByObject();
	}

	g_mExprDB->m_EventEntityFactory->endFindByObject();

	result.setDIntConstant(iNum, m_now);
	return true;
}

bool CContext::CheckEventDescExist(CValue &result, CValue **paraList)
{
	CEventEntity *pEventEntity;
	int iNum = 0;	/// 默认为找不到
	int iObjectId = g_mStringIdMap.getStringId(
			paraList[0]->getStringValue()->getValue());
	int iEventId = g_mStringIdMap.getStringId(
			paraList[1]->getStringValue()->getValue());
	pEventEntity = g_mExprDB->m_EventEntityFactory->startFindByObject(
			iObjectId,
			iEventId,
			m_now);
	while (pEventEntity)
	{
		if ((pEventEntity->MonitorTime < m_now - paraList[2]->getDIntValue()))
		{
			break;
		}
		else
		{
			if (strCheckValid_U(
					(const char *)pEventEntity->EventDes,
				paraList[3]->getStringValue()->getValue(),
				paraList[4]->getStringValue()->getValue()))
			{
				RECORDWARNINGINFO_EVENT;
				iNum = 1;
				break;
			}
		}

		pEventEntity = g_mExprDB->m_EventEntityFactory->findNextByObject();
	}

	g_mExprDB->m_EventEntityFactory->endFindByObject();

	result.setDIntConstant(iNum, m_now);
	return true;
}

/// Added by Henchi,20120620
/// CheckEventDescValue 基于"AND"运算的事件描述多值校验
bool CContext::CheckEventDescValue(
	CValue	&result,
	int paraCount,
	CValue **paraList)
{
	if (paraCount < 6 || paraCount % 3 != 0)
	{
		return false;
	}

	CEventEntity *pEventEntity;
	char szTmp[MAXONECONTENTLEN];

	/// Common Info
	int iObjectId = g_mStringIdMap.getStringId(
			paraList[0]->getStringValue()->getValue());
	int iEventId = g_mStringIdMap.getStringId(
			paraList[1]->getStringValue()->getValue());
	int iTimeOffset = paraList[2]->getDIntValue();

	int iNum = 0;
	pEventEntity = g_mExprDB->m_EventEntityFactory->startFindByObject(
			iObjectId,
			iEventId,
			m_now);

	while (pEventEntity)
	{
		if ((pEventEntity->MonitorTime < m_now - paraList[2]->getDIntValue()))
		{
			iNum = 0;
			break;
		}
		else
		{
			bool bResult = true;

			/// 当前记录符合时间要求，尝试获取目标域
			map<int, string> map_tokens;
			map<int, string>::iterator map_it;
			strcpy(szTmp, (const char *)pEventEntity->EventDes);

			char *p = strtok(szTmp, EVENT_TOKEN_FLAGS);
			for (int iCount = 1; p != NULL; iCount++)
			{
				map_tokens[iCount] = p;
				p = strtok(NULL, EVENT_TOKEN_FLAGS);
			}

			for (int iPos = 3; iPos < paraCount; iPos = iPos + 3)
			{
				int iFieldNum = paraList[iPos]->getDIntValue();
				map_it = map_tokens.find(iFieldNum);
				if (map_it == map_tokens.end())
				{
					bResult = false;
					break;
				}
				else
				{
					/// 多条件项采用"AND"运算
					bResult &= CheckStrValue(
							map_it->second.c_str(),
							paraList[iPos + 1]->getStringValue()->getValue(),
							paraList[iPos + 2]);

					// 可重复匹配
					// map_tokens.erase(map_it);
				}
			}

			if (bResult)	// All matched
			{
				RECORDWARNINGINFO_EVENT;
				iNum = 1;
				break;		// break 'while' circle, only get the first matched record.
			}
		}

		pEventEntity = g_mExprDB->m_EventEntityFactory->findNextByObject();
	}

	g_mExprDB->m_EventEntityFactory->endFindByObject();
	result.setDIntConstant(iNum, m_now);
	return true;
}

/// CheckEventDescValue 基于"OR"运算的事件描述多值校验
bool CContext::CheckEventDescValueOR(
	CValue	&result,
	int paraCount,
	CValue **paraList)
{
	if (paraCount < 6 || paraCount % 3 != 0)
	{
		return false;
	}

	CEventEntity *pEventEntity;
	char szTmp[MAXONECONTENTLEN];

	/// Common Info
	int iObjectId = g_mStringIdMap.getStringId(
			paraList[0]->getStringValue()->getValue());
	int iEventId = g_mStringIdMap.getStringId(
			paraList[1]->getStringValue()->getValue());
	int iTimeOffset = paraList[2]->getDIntValue();

	int iNum = 0;
	pEventEntity = g_mExprDB->m_EventEntityFactory->startFindByObject(
			iObjectId,
			iEventId,
			m_now);

	while (pEventEntity)
	{
		if ((pEventEntity->MonitorTime < m_now - paraList[2]->getDIntValue()))
		{
			iNum = 0;
			break;
		}
		else
		{
			bool bResult = false;

			/// 当前记录符合时间要求，尝试获取目标域
			map<int, string> map_tokens;
			map<int, string>::iterator map_it;
			strcpy(szTmp, (const char *)pEventEntity->EventDes);

			char *p = strtok(szTmp, EVENT_TOKEN_FLAGS);
			for (int iCount = 1; p != NULL; iCount++)
			{
				map_tokens[iCount] = p;
				p = strtok(NULL, EVENT_TOKEN_FLAGS);
			}

			for (int iPos = 3; iPos < paraCount; iPos = iPos + 3)
			{
				int iFieldNum = paraList[iPos]->getDIntValue();
				map_it = map_tokens.find(iFieldNum);
				if (map_it == map_tokens.end())
				{
					continue;
				}
				else
				{
					/// 多条件项采用"OR"运算
					bResult |= CheckStrValue(
							map_it->second.c_str(),
							paraList[iPos + 1]->getStringValue()->getValue(),
							paraList[iPos + 2]);
					if (bResult)
					{
						break;	// break 'for' circle.
					}
				}
			}

			if (bResult)		// someone matched
			{
				RECORDWARNINGINFO_EVENT;
				iNum = 1;
				break;			// break 'while' circle, only get the first matched record.
			}
		}

		pEventEntity = g_mExprDB->m_EventEntityFactory->findNextByObject();
	}

	g_mExprDB->m_EventEntityFactory->endFindByObject();
	result.setDIntConstant(iNum, m_now);
	return true;
}

/// GetEventTimeByDescValue 基于"AND"运算的事件描述多值校验
bool CContext::GetEventTimeByDescValue(
	CValue	&result,
	int paraCount,
	CValue **paraList)
{
	if (paraCount < 6 || paraCount % 3 != 0)
	{
		return false;
	}

	CEventEntity *pEventEntity;
	char szTmp[MAXONECONTENTLEN];

	/// Common Info
	int iObjectId = g_mStringIdMap.getStringId(
			paraList[0]->getStringValue()->getValue());
	int iEventId = g_mStringIdMap.getStringId(
			paraList[1]->getStringValue()->getValue());
	int iTimeOffset = paraList[2]->getDIntValue();

	int iNum = 0;
	pEventEntity = g_mExprDB->m_EventEntityFactory->startFindByObject(
			iObjectId,
			iEventId,
			m_now);

	while (pEventEntity)
	{
		if ((pEventEntity->MonitorTime < m_now - paraList[2]->getDIntValue()))
		{
			iNum = 0;
			break;
		}
		else
		{
			bool bResult = true;

			/// 当前记录符合时间要求，尝试获取目标域
			map<int, string> map_tokens;
			map<int, string>::iterator map_it;
			strcpy(szTmp, (const char *)pEventEntity->EventDes);

			char *p = strtok(szTmp, EVENT_TOKEN_FLAGS);
			for (int iCount = 1; p != NULL; iCount++)
			{
				map_tokens[iCount] = p;
				p = strtok(NULL, EVENT_TOKEN_FLAGS);
			}

			for (int iPos = 3; iPos < paraCount; iPos = iPos + 3)
			{
				int iFieldNum = paraList[iPos]->getDIntValue();
				map_it = map_tokens.find(iFieldNum);
				if (map_it == map_tokens.end())
				{
					bResult = false;
					break;
				}
				else
				{
					/// 多条件项采用"AND"运算
					bResult &= CheckStrValue(
							map_it->second.c_str(),
							paraList[iPos + 1]->getStringValue()->getValue(),
							paraList[iPos + 2]);

					// 可重复匹配
					// map_tokens.erase(map_it);
				}
			}

			if (bResult)	// All matched
			{
				RECORDWARNINGINFO_EVENT;
				iNum = pEventEntity->MonitorTime;	/// GetEventTime (DateTime info)
				break;		// break 'while' circle, only get the first matched record.
			}
		}

		pEventEntity = g_mExprDB->m_EventEntityFactory->findNextByObject();
	}

	g_mExprDB->m_EventEntityFactory->endFindByObject();
	result.setDIntConstant(iNum, iNum);
	return true;
}

/// GetEventTimeByDescValueOR 基于"OR"运算的事件描述多值校验
bool CContext::GetEventTimeByDescValueOR(
	CValue	&result,
	int paraCount,
	CValue **paraList)
{
	if (paraCount < 6 || paraCount % 3 != 0)
	{
		return false;
	}

	CEventEntity *pEventEntity;
	char szTmp[MAXONECONTENTLEN];

	/// Common Info
	int iObjectId = g_mStringIdMap.getStringId(
			paraList[0]->getStringValue()->getValue());
	int iEventId = g_mStringIdMap.getStringId(
			paraList[1]->getStringValue()->getValue());
	int iTimeOffset = paraList[2]->getDIntValue();

	int iNum = 0;
	pEventEntity = g_mExprDB->m_EventEntityFactory->startFindByObject(
			iObjectId,
			iEventId,
			m_now);

	while (pEventEntity)
	{
		if ((pEventEntity->MonitorTime < m_now - paraList[2]->getDIntValue()))
		{
			iNum = 0;
			break;
		}
		else
		{
			bool bResult = false;

			/// 当前记录符合时间要求，尝试获取目标域
			map<int, string> map_tokens;
			map<int, string>::iterator map_it;
			strcpy(szTmp, (const char *)pEventEntity->EventDes);

			char *p = strtok(szTmp, EVENT_TOKEN_FLAGS);
			for (int iCount = 1; p != NULL; iCount++)
			{
				map_tokens[iCount] = p;
				p = strtok(NULL, EVENT_TOKEN_FLAGS);
			}

			for (int iPos = 3; iPos < paraCount; iPos = iPos + 3)
			{
				int iFieldNum = paraList[iPos]->getDIntValue();
				map_it = map_tokens.find(iFieldNum);
				if (map_it == map_tokens.end())
				{
					continue;
				}
				else
				{
					/// 多条件项采用"OR"运算
					bResult |= CheckStrValue(
							map_it->second.c_str(),
							paraList[iPos + 1]->getStringValue()->getValue(),
							paraList[iPos + 2]);
					if (bResult)
					{
						break;	// break 'for' circle.
					}
				}
			}

			if (bResult)		// someone matched
			{
				RECORDWARNINGINFO_EVENT;
				iNum = pEventEntity->MonitorTime;	/// GetEventTime (DateTime info)
				break;			// break 'while' circle, only get the first matched record.
			}
		}

		pEventEntity = g_mExprDB->m_EventEntityFactory->findNextByObject();
	}

	g_mExprDB->m_EventEntityFactory->endFindByObject();
	result.setDIntConstant(iNum, iNum);
	return true;
}

bool CContext::getEventDesc(CValue &result, CValue **paraList)
{
	CEventEntity *pEventEntity;
	char szTmp[MAXONECONTENTLEN];
	int iObjectId = g_mStringIdMap.getStringId(
			paraList[0]->getStringValue()->getValue());
	int iEventId = g_mStringIdMap.getStringId(
			paraList[1]->getStringValue()->getValue());
	int iTimeOffset = paraList[2]->getDIntValue();
	int iFieldNum = paraList[3]->getDIntValue();
	pEventEntity = g_mExprDB->m_EventEntityFactory->startFindByObject(
			iObjectId,
			iEventId,
			m_now);

	/// 仅找到首条记录
	if (pEventEntity == NULL)
	{
		result.setStringConstant(new CRefString("-1"));
	}
	else
	{
		if ((pEventEntity->MonitorTime < m_now - iTimeOffset))
		{
			result.setStringConstant(new CRefString("-1"));
		}
		else
		{
			/// 找到首条符合时间要求记录
			strcpy(szTmp, (const char *)pEventEntity->EventDes);
			if (iFieldNum <= 0)
			{
				result.setStringConstant(new CRefString(szTmp));
			}
			else
			{
				char *p = strtok(szTmp, " ,;=\'\"");
				for (int iCount = 1;; iCount++)
				{
					if (NULL == p)
					{
						result.setStringConstant(new CRefString("-1"));
						break;
					}

					if (iCount == iFieldNum)
					{
						result.setStringConstant(new CRefString(p));
						break;
					}

					p = strtok(NULL, " ,;=\'\"");
				}
			}
		}
	}

	g_mExprDB->m_EventEntityFactory->endFindByObject();
	return true;
}

bool CContext::getStringId(CValue &result, CValue **paraList)
{
	result.setIntegerConstant(
			g_mStringIdMap.getStringId(
					paraList[0]->getStringValue()->getValue()));
	return true;
}

bool CContext::getmaincentername(CValue &result, CValue **paraList)
{
	char *p = new char[65];
	strcpy(p, g_pDataCenter->getDataCenter());
	result.setStringConstant(new CRefString(p));
	delete p;
	return true;
}

bool CContext::getactiveapp(CValue &result, CValue **paraList)
{
	list<int> &idList = g_pDataCenter->getAppIdList(
			paraList[0]->getStringValue()->getValue());
	list<int>::const_iterator it = idList.begin();
	int nNum = 0, monitorTime,
				maxTime = 0;
	int itemid = g_mStringIdMap.getStringId(APPATTRISACTIVE);
	while (it != idList.end())
	{
		getLastedItemValue(result, *it, itemid, m_now, monitorTime);
		maxTime = max(maxTime, monitorTime);

		int temp = g_pDataCenter->getAttrInterval(APPATTRISACTIVE);
		if ((
				monitorTime + g_mMonitorTime * g_pDataCenter->getAttrInterval(
				APPATTRISACTIVE)
	) > m_now)
		{
			nNum++;
		}

		it++;
	}

	result.setDIntConstant(nNum, maxTime);
	return true;
}

bool CContext::getSystemName(CValue &result, CValue **paraList)
{
	char temp[MAXOBJECTNAMELEN];
	strcpy(temp, paraList[0]->getStringValue()->getValue());

	char *p = strchr(temp, '.');
	*p = '\0';
	p = new char[strlen(temp) + 1];
	strcpy(p, temp);
	result.setStringConstant(new CRefString(p), paraList[0]->getDTimeValue());
	delete p;
	return true;
}

/// Added by Henchi, 20120412
/// 获取指定域字段的值
/// getDomainName(“TRADE.PuDian.app.tkernel.1”, 1, 3) == "TRADE.PuDian.app";
/// getDomainName(“TRADE.PuDian.app.tkernel.1”, 4, 2) == "tkernel.1";
bool CContext::getDomainName(CValue &result, CValue **paraList)
{
	int iPos, iDomains;
	char temp[MAXOBJECTNAMELEN];
	strcpy(temp, paraList[0]->getStringValue()->getValue());
	iPos = paraList[1]->getDIntValue();
	iPos = iPos > 1 ? iPos : 1;
	iDomains = paraList[2]->getDIntValue();
	iDomains = iDomains > 0 ? iDomains : 0;

	char *p = temp;

	char *q = temp;
	int iCount = iPos + iDomains;
	int iDomain = 1;
	while ((q = strchr(q, '.')) != NULL)
	{
		iDomain++;
		q++;
		if (iDomain == iPos)
		{
			p = q;
		}

		if (iDomain == iCount)
		{
			break;
		}
	}

	if (q == NULL)
	{
		/// 当前p为字段左端 其后字段全部满足
		result.setStringConstant(new CRefString(p));
	}
	else
	{
		/// 当前p为字段左端 q为字段尾
		if (--q > p)
		{
			*(q) = 0x00;
			result.setStringConstant(new CRefString(p));
		}
		else
		{
			result.setStringConstant(new CRefString(""));
		}
	}

	return true;
}

bool CValue::setIdentifierConstant(const CRefStringPtr &value)
{
	m_valueType = OBJECT_VALUE;
	m_intValue = g_mStringIdMap.getStringId(value);
	return true;
}

void CValue::display(FILE *output)
{
	switch (getValueType())
	{
		case NO_VALUE:
			fprintf(output, "No value\n");
			break;
		case INT_VALUE:
			fprintf(output, "Int value:%d\n", m_intValue);
			break;
		case STRING_VALUE:
			fprintf(output, "String value:%s\n", m_stringValue->getValue());
			break;
		case OBJECT_VALUE:
			fprintf(
				output,
				"Object value:%s\n",
				g_mStringIdMap.getString(m_intValue));
			break;
		case LIST_VALUE:
			{
				list<int>::iterator it = m_listValue.begin();
				fprintf(output, "List Value:");
				while (it != m_listValue.end())
				{
					fprintf(output, "%d ", *it);
					it++;
				}

				fprintf(output, "\n");
			}

			break;
		case DINT_VALUE:
			fprintf(output, "DInt value %d %d\n", m_intValue, m_intTime);
			break;
		case DOUBLE_VALUE:
			fprintf(output, "DOUBLE value %f %d\n", m_fltValue, m_intTime);
			break;
		default:
			fprintf(output, "Unknown value\n");
			break;
	}
}

time_t g_mTradeTime;
char g_day[9] = { 0 };

/*
* pdate 日期: 20081101
* ptime 时间: 15:20:30
* return 整数时间
*/
int getTimeFromStr(char *pdate, char *ptime)
{
	int i = strcmp(pdate, g_day);
	if (i != 0)
	{
		struct tm m_mTime;
		m_mTime.tm_mday = atoi(pdate) % 100;
		m_mTime.tm_mon = (atoi(pdate) % 10000) / 100 - 1;
		m_mTime.tm_year = (atoi(pdate)) / 10000 - 1900;

		m_mTime.tm_sec = 0;
		m_mTime.tm_min = 0;
		m_mTime.tm_hour = 0;
		g_mTradeTime = mktime(&m_mTime);
		if (g_mTradeTime == (time_t) (-1))
		{
			//printf("错误的时间和日期格式 %s %s\n",pdate,ptime);
			g_day[0] = '\0';
			return 0;
		}

		strcpy(g_day, pdate);
		return (int)
			(
				g_mTradeTime + ((ptime[0] - '0') * 10 + (ptime[1] - '0')) * 3600 +
					((ptime[3] - '0') * 10 + (ptime[4] - '0')) * 60 +
						((ptime[6] - '0') * 10 + (ptime[7] - '0'))
			);
	}
	else
	{
		return (int)
			(
				g_mTradeTime + ((ptime[0] - '0') * 10 + (ptime[1] - '0')) * 3600 +
					((ptime[3] - '0') * 10 + (ptime[4] - '0')) * 60 +
						((ptime[6] - '0') * 10 + (ptime[7] - '0'))
			);
	}
}

/// 取指定监控对象的指定指标在某个时间的值
/// @param	mObjectId	监控对象的ID
/// @param	mAttrId	监控指标的ID
/// @param	pDate	日期
/// @param	pTime	时间
/// @return double	返回该指标的值
double getItemValue(int mObjectId, int mAttrId, char *pDate, char *pTime)
{
	if (g_pContext != NULL)
	{
		return g_pContext->getItemValue(
				mObjectId,
				mAttrId,
				getTimeFromStr(pDate, pTime));
	}

	return -1.0;
}

string transformStr(string oristr)
{
	char sOsId[1024], dOsId[1024];
	strncpy(dOsId, oristr.c_str(), 1024);

	int m = 0;
	int n = strlen(dOsId);

	for (int j = 0; j < n; j++)
	{
		if (dOsId[j] == '+'
		||	dOsId[j] == '-'
		||	dOsId[j] == '*'
		||	dOsId[j] == '/'
		||	dOsId[j] == ':')
		{
			sOsId[m] = '\\';
			m += 1;
		}

		sOsId[m] = dOsId[j];
		m += 1;
	}

	sOsId[m] = '\0';

	string resultstr = sOsId;
	return resultstr;
}
