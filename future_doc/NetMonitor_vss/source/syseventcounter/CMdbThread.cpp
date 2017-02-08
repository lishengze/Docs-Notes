

#include "CMdbThread.h"
#include "CExprAnalysis.h"
#include "EventCounterServer.h"

extern CMemoryDB * g_mExprDB;
extern CExprAnalysis *g_mExprAnalysis;
extern CStringIdMap g_mStringIdMap;
extern CDataCenter	*g_pDataCenter;

CMdbThread::CMdbThread(
	CNodeCacheBuffer *pNodeBuffer,
	CNodeCacheBuffer *pEventBuffer,
	char *pEventCfgPath) :
	m_iWork(0),
	m_mStatusStat(pEventCfgPath)
{
	m_pNodeBuffer = pNodeBuffer;
	m_pEventBuffer = pEventBuffer;
}

CMdbThread::~CMdbThread(void)
{
	ExitThread();
}

/**虚函数，子类可做一些实例化工作
* @return true:创建成功 false:创建失败
*/
bool CMdbThread::InitInstance(void)
{
	return true;
}

/**虚函数，子类清楚实例
*/
void CMdbThread::ExitInstance(void)
{
}

/**线程开始运行，纯虚函数，子类必须继承实现
*/
void CMdbThread::Run(void)
{
#ifdef LINUX
	printf("CMdbThread pid = %d tid = %d\n", getpid(), syscall(SYS_gettid));
#endif

	bool bFlag;

	CFTDRtnObjectAttrField	tmpAttr;
	CWriteableMonitorEntity tmpEntity;
	CFTDRtnSyslogEventField tmpEvent;
	CWriteableEventEntity tmpEventEntity;

	time_t	nNow = time((time_t *)NULL);
	time_t	nStart = nNow + 2;	// modify by zhou.jj 20100219, 修改为启动后就计算,是否决定计算由表达式初始化设置时间决定
	struct tm tm_time;
	LocalTime(&nStart, &tm_time);
	int nRecord = 0;
	int length = 0;
	int lastDay = tm_time.tm_yday;
	int lastFlag = (tm_time.tm_hour) / 6;

	while (1)
	{
		/// 优先进行状态数据入MDB
		for (bFlag = true, nRecord = 0; bFlag && nRecord < 1000000; nRecord++)
		{
			bFlag = m_pNodeBuffer->readNode(&tmpAttr, length);
			if (bFlag)			//从缓冲区读取到状态数据
			{
				tmpEntity.MonitorObject = g_mStringIdMap.getStringId(
						tmpAttr.ObjectID.getValue());
				tmpEntity.MonitorItem = g_mStringIdMap.getStringId(
						tmpAttr.AttrType.getValue());
				tmpEntity.MonitorTime = getTimeFromStr(
						(char *)tmpAttr.MonDate.getValue(),
						(char *)tmpAttr.MonTime.getValue());
				tmpEntity.Time = tmpAttr.MonTime;
				tmpEntity.ValueType = tmpAttr.ValueType;
				tmpEntity.AttrValue = tmpAttr.AttrValue;
				g_mExprDB->m_MonitorEntityFactory->add(&tmpEntity);

				/// 判断指标是否出现最大值,如果是字符串类型取消最大值分析和K线统计
				if (tmpAttr.ValueType != STRING_ATTR)
				{
					register multimap<CStatKey, CFTDRtnHistoryTradePeakField>::iterator
						mit = m_mStatusStat.m_mapPeak.lower_bound(
								CStatKey(
									tmpEntity.MonitorObject,
									tmpEntity.MonitorItem));

					while
					(
						mit != m_mStatusStat.m_mapPeak.upper_bound(
								CStatKey(
										tmpEntity.MonitorObject,
										tmpEntity.MonitorItem))
					)
					{
						if (mit->second.AttrValue < atof(
								tmpEntity.AttrValue.getValue()))
						{
							mit->second.AttrValue = (double)atof(
									tmpEntity.AttrValue.getValue());
							mit->second.MonDate = tmpAttr.MonDate;
							mit->second.MonTime = tmpAttr.MonTime;
							mit->second.OldAttrValue = 1.0; //作为刚出现最大值更新的标记
						}

						++mit;
					}

					m_mStatusStat.addAttrStat(
							tmpEntity.MonitorObject,
							tmpEntity.MonitorItem,
							tmpEntity.MonitorTime,
							tmpAttr.ValueType,
							(char *)tmpAttr.AttrValue.getValue());
				}

				g_pDataCenter->setDataCenter(
						tmpEntity.MonitorObject,
						tmpEntity.MonitorItem);

				/// 清除内存数据库中本对象8小时前的历史数据
				{
					CMonitorEntity	*pMonitorEntity = g_mExprDB->
						m_MonitorEntityFactory->startFindByTime(
								tmpEntity.MonitorObject,
								tmpEntity.MonitorItem,
								tmpEntity.MonitorTime - 8 * 3600);
					if (pMonitorEntity != NULL)
					{
						g_mExprDB->m_MonitorEntityFactory->remove(
								pMonitorEntity);
					}

					g_mExprDB->m_MonitorEntityFactory->endFindByTime();
				}
			}
		}

		/// 进行日志事件数据入MDB
		for (bFlag = true, nRecord = 0; bFlag && nRecord < 10000; nRecord++)
		{
			bFlag = m_pEventBuffer->readNode(&tmpEvent, length);
			if (bFlag)	//从缓冲区读取到事件数据
			{
				tmpEventEntity.MonitorObject = g_mStringIdMap.getStringId(
						tmpEvent.ObjectID.getValue());
				tmpEventEntity.MonitorTime = getTimeFromStr(
						(char *)tmpEvent.MonDate.getValue(),
						(char *)tmpEvent.MonTime.getValue());
				tmpEventEntity.Time = tmpEvent.MonTime;
				tmpEventEntity.ProcessFlag = tmpEvent.ProcessFlag;
				tmpEventEntity.EventDes = tmpEvent.EventDes;
				tmpEventEntity.WarningLevel = tmpEvent.WarningLevel.getValue();
				tmpEventEntity.EventName = g_mStringIdMap.getStringId(
						tmpEvent.EventName.getValue());
				g_mExprDB->m_EventEntityFactory->add(&tmpEventEntity);

				/// 清除内存数据库中本对象8小时前的历史数据
				{
					CEventEntity *pEventEntity;
					pEventEntity = g_mExprDB->m_EventEntityFactory->
						startFindByKey(
							tmpEventEntity.EventName,
							tmpEventEntity.MonitorTime - 8 * 3600);
					if (pEventEntity != NULL)
					{
						g_mExprDB->m_EventEntityFactory->remove(pEventEntity);
					}

					g_mExprDB->m_EventEntityFactory->endFindByKey();
				}
			}
		}

		/// 完成数据入MDB后尝试进行表达式判断
		nNow = time((time_t *)NULL);
		if (nNow >= nStart)
		{
			nStart = nNow + 1;

			// 每秒进行表达式判断
			g_mExprAnalysis->exprRun();

			// 进行指标的K线统计
			m_mStatusStat.periodStats();
		}

		/// 避免过度空载，进行小量休眠
		SleepMs(10);
	}
}

#if 0
int insertTotal = 0, deleteTotal = 0;
#endif
#if 0
CWriteableMonitorEntity theObjectEntity;
for (int i = 0; i < 10000; i++)
{
	theObjectEntity.MonitorItem = i;
	theObjectEntity.MonitorObject = i;
	theObjectEntity.MonitorTime = nNow;
	theObjectEntity.MonitorValue = i;
	g_mExprDB->m_MonitorEntityFactory->add(&theObjectEntity);
	{
		CMonitorEntity	*pMonitorEntity = g_mExprDB->m_MonitorEntityFactory->
			startFindByTime
				(
					theObjectEntity.MonitorObject, theObjectEntity.MonitorItem, theObjectEntity.MonitorTime -
					60
				);
		if (pMonitorEntity != NULL)
		{
			g_mExprDB->m_MonitorEntityFactory->remove(pMonitorEntity);
			deleteTotal++;
		}

		g_mExprDB->m_MonitorEntityFactory->endFindByTime();
	}
}

g_mExprDB->m_EventEntityFactory->clearAll();
insertTotal = insertTotal + 10000;
printf
	(
		"Time %d insertTotal %d deleteTotal %d MdbSize %d\n",
			(int)
				nNow, insertTotal, deleteTotal, g_mExprDB->
					m_MonitorEntityFactory->getCount()
	);
OSSleep(1);
continue;
#endif
