/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	DatabaseSpiImpl.h
///@brief	定义了数据库读取探针的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
///20090515 武玉波		把对数据库的访问做成一个线程，该类中仅仅负责，去掉所有和通讯有关的成员和操作
///20100204	周建军		增加注释说明m_DatabaseInfoMap，m_dbConnections的用途
#ifndef REF_DATABASESPIIMPL_H
#define REF_DATABASESPIIMPL_H

#include "public.h"
#include "CachedFileFlow.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"

#include "SQLAPI.h"

class CSPQuery
{
	/* */
	public:
		~CSPQuery(void)
		{
		}

		CSPQuery(void)
		{
			objectId = "";
			attrType = "";
			requestId = 0;
			session = NULL;
		}

		CSPQuery(
		const char	*pObjectId,
		const char	*pAttrType,
		DWORD nRequestId,
		const CFTDCSession	*pSession)
		{
			objectId = pObjectId;
			attrType = pAttrType;
			requestId = nRequestId;
			session = (CFTDCSession *)pSession;
		}

		CSPQuery(const CSPQuery &ob)
		{
			objectId = ob.objectId;
			attrType = ob.attrType;
			requestId = ob.requestId;
			session = ob.session;
		}

		void operator=(const CSPQuery &ob)
		{
			objectId = ob.objectId;
			attrType = ob.attrType;
			requestId = ob.requestId;
			session = ob.session;
		}

	/* */
	public:
		string	objectId;
		string	attrType;
		DWORD requestId;
		CFTDCSession *session;
};

/////////////////////////////////////////////////////////////////////////
///CDataBaseAttr定义了时间段处理类
///@author	周建军
///@version	1.0,20090625
/////////////////////////////////////////////////////////////////////////
class CDataBaseAttr
{
	/* */
	public:

		///缺省构造函数
		CDataBaseAttr(void)
		{
			sDNSName = "";
			sInstanceName = "";
			sReturnType = "";
			m_nLastRunSec = 0;
			m_nLogId = 0;
			m_sOpTime = "00:00:00";

			time_t	timep;
			time(&timep);

			struct tm tm_time;
			LocalTime(&timep, &tm_time);
			char tmp[9];
			sprintf(
				tmp,
				"%04d%02d%02d",
				tm_time.tm_year + 1900,
				tm_time.tm_mon + 1,
				tm_time.tm_mday);
			m_sOpDate = tmp;
		}

		///构造函数
			///@param	pDNSName	数据库别名
			///@param	pInstanceName	数据库实例名或存储过程类型
			///@param	pSeps	该操作对应的所有时间段
		CDataBaseAttr(
		const char	*pDNSName,
		const char	*pInstanceName,
		const char	*pSeps)
		{
			char *p = strchr((char *)pInstanceName, ':');
			if (p != NULL)
			{
				*p = '\0';
				p++;
			}
			else
			{
				p = DATACENTERDB;
			}

			sDNSName = pDNSName;
			sInstanceName = pInstanceName;
			sReturnType = p;
			m_nLastRunSec = 0;
			m_nLogId = 0;
			m_sOpTime = "00:00:00";
			p = (char *)pSeps;
			while (p != NULL)
			{
				if (isValid(p))
				{
					m_vSep.push_back(CSeps(p));
				}

				p = strchr(p, ',');
				if (p != NULL)
				{
					p++;
				}
			}

			time_t	timep;
			time(&timep);

			struct tm *pGm = localtime(&timep);
			char tmp[9];
			sprintf(
				tmp,
				"%04d%02d%02d",
				pGm->tm_year + 1900,
				pGm->tm_mon + 1,
				pGm->tm_mday);
			m_sOpDate = tmp;
		}

		///拷贝构造函数
		CDataBaseAttr(const CDataBaseAttr &ob)
		{
			sDNSName = ob.sDNSName;
			sInstanceName = ob.sInstanceName;
			sReturnType = ob.sReturnType;
			m_nLastRunSec = ob.m_nLastRunSec;
			m_vSep.clear();
			for (unsigned int i = 0; i < ob.m_vSep.size(); i++)
			{
				m_vSep.push_back(ob.m_vSep[i]);
			}

			if (m_sOpDate == "")
			{
				m_sOpDate = ob.m_sOpDate;
				m_sOpTime = ob.m_sOpTime;
				m_nLogId = ob.m_nLogId;
			}
		}

		CDataBaseAttr &operator=(const CDataBaseAttr &ob)
		{
			sDNSName = ob.sDNSName;
			sInstanceName = ob.sInstanceName;
			sReturnType = ob.sReturnType;
			m_nLastRunSec = ob.m_nLastRunSec;
			m_vSep.clear();
			for (unsigned int i = 0; i < ob.m_vSep.size(); i++)
			{
				m_vSep.push_back(ob.m_vSep[i]);
			}

			if (m_sOpDate == "")
			{
				m_sOpDate = ob.m_sOpDate;
				m_sOpTime = ob.m_sOpTime;
				m_nLogId = ob.m_nLogId;
			}

			return *this;
		}

		///判断字符串是否符合时间段频率定义格式
		bool isValid(char *p)
		{
			return
				(
					*(p + 2) == ':'
				&&	*(p + 5) == ':'
				&&	*(p + 8) == '-'
				&&	*(p + 11) == ':'
				&&	*(p + 14) == ':'
				&&	*(p + 17) == '.'
				);
		}

		///判断是否需要取该指标
			///@param	nNowSec	从系统中取得的秒数（已经补充了时差）
			///@return	true需要执行,false不需要执行
		bool needExcute(const int nNowSec)
		{
			if (nNowSec < m_nLastRunSec)
			{
				return false;
			}
			else
			{
				int nTemp = nNowSec % 86400;
				for (unsigned int i = 0; i < m_vSep.size(); i++)
				{
					if (nTemp < m_vSep[i].m_nStart)
					{
						m_nLastRunSec = nNowSec - nTemp + m_vSep[i].m_nStart;
						return false;
					}
					else if (nTemp >= m_vSep[i].m_nStart
						 &&	 nTemp < m_vSep[i].m_nEnd)	// 取该时间段的采样频率
					{
						m_nLastRunSec = nNowSec -
							(
								nNowSec %
								m_vSep[i].m_nInterval
							) +
									m_vSep[i].m_nInterval;
						return true;
					}
				}

				if (m_vSep.size() == 0)
				{
					m_nLastRunSec = nNowSec + 86400;
					return false;
				}
				else
				{
					m_nLastRunSec = nNowSec -
						nTemp +
						86400 +
						m_vSep[0].m_nStart;
					return false;
				}
			}
		}

	/* */
	protected:
	/* */
	public:
		///数据库别名
		string	sDNSName;

		///操作数据库的SP返回类型,CURSOR,NOCURSOR..
		string	sInstanceName;

		///SP返回的属性列表是数据库类还是应用类db,app
		string	sReturnType;

		///操作时段数组
		vector<CSeps> m_vSep;

		///上次操作数据库时间,从当日零点开始的秒数
		int m_nLastRunSec;

		///上次读取到的数据库日志表Logid的值
		unsigned long m_nLogId;

		///上次读取到的数据库日志表OpDate的值
		string	m_sOpDate;

		///上次读取到的数据库日志表OpTime的值
		string	m_sOpTime;
};

class CDBQueryField
{
	/* */
	public:
		///查询对象ID
		string	m_objectID;

		///查询的SP名称
		string	m_attrType;

		///请求的RequestID
		DWORD m_requestID;

		///请求的FTD会话
		CFTDCSession *m_session;

		///该请求是否处理完成标记
		bool m_reqFlag;

		///请求处理的结果返回值
		int m_rtnCode;

		///请求处理的结果字符串应答
		string	m_rtnMsg;

		///请求查询获得的结果
		list<CFTDRspQryDBQueryField> m_dbQuery;
};

/////////////////////////////////////////////////////////////////////////
///CDatabaseSpiImpl定义了数据库的指标采集类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CDatabaseSpiImpl
{
	/* */
	public:
		CDatabaseSpiImpl(void);
		~ CDatabaseSpiImpl(void);

	/* */
	public:
		///数据库类采集函数
			///@param	nNowTimeSec	当前的时间，未增加时区秒数
			///@return	
		void GetDatabaseSpi(time_t nNowTimeSec);

		///用于更新数据库连接map对象函数
			///@param	sConfigName	数据库配置别名
			///@param	sConnectString	数据库连接用的信息
		void UpdateDatabaseInfoMap(
				string	&sConfigName,
				CDBConnectString &sConnectString);

		///用于更新指标采集map对象函数，本函数用来统计表大小
			///@param	pAttrName	数据库指标名称
			///@param	pSeps	指标采样时间段频率
			///@param	pDNSName	数据库的别名
			///@param	pTableName	数据库的表名称
		void UpdateDBAttrMap(
				const char	*pAttrName,
				const char	*pSeps,
				const char	*pDNSName,
				const char	*pTableName);

		///用于更新数据库调用存储过程对象
			///@param	pSPName	SP名称
			///@param	pSeps	读取SP的时间及频率信息
			///@param	pDNSName	数据库别名信息
			///@param	pSPType	SP的返回值类型
		void UpdateSPInfoMap(
				const char	*pSPName,
				const char	*pSeps,
				const char	*pDNSName,
				const char	*pSPType);

		///用于更新数据库读取日志表对象
			///@param	pTableName	日志表名称
			///@param	pSeps	读取日志表的时间及频率信息
			///@param	pDNSName	数据库别名信息
			///@param	pPosition	数据库表读取的偏移量信息
		void UpdateDBLogMap(
				const char	*pTableName,
				const char	*pSeps,
				const char	*pDNSName,
				const char	*pPosition);

		///用于更新数据库临时查询请求对象函数
			///@param	pObjectId	请求数据库对象的ID
			///@param	pAttrType	请求数据库查询的SP名称
			///@param	dRequestId	请求的RequestId编号
			///@param	pSession	该请求所属的ftd Session
		void UpdateSPQuery(
				const char	*pObjectId,
				const char	*pAttrType,
				const DWORD dRequestId,
				const CFTDCSession	*pSession);

		void UpdateConfig(CFTDRspQryHostConfigField *hostConfig);

	///20080717 add by wu.yb
	private:
		///连接数据库函数，如果是连接着的，就不再进行连接
			///@param	strIp	数据库服务器的IP地址
			///@param	port	数据库服务器的端口号
			///@param	strDbName	数据库实例名
			///@param	strUser	数据库用户名
			///@param	strPwd	数据库用户对应的密码
			///@return	返回数据库的SAConnection连接指针
		SAConnection *connectDB(
						const string &strIp,
						int port,
						const string &strDbName,
						const string &strUser,
						const string &strPwd);

		///the database server connection status
			///我们使用的SQLAPI版本没有这个函数，新的版本有
			///判断数据库是否真的活跃函数
			///@param	conn	数据库连接指针
			///@return	true表示连接活跃，false表示连接不可用
		bool isAlive(SAConnection *conn);

		///读取单个表的记录数函数
			///@param	conn	数据库连接指针
			///@param	tableName	数据库表名称
			///@return	返回该表大小，即记录总数
		long getRecordNum(SAConnection *conn, const string &tableName);

		string	getCmdText(const string &tableName) const;
		string	getConnectStr(
					const string &ip,
					int port,
					const string &dbName) const;

		//2008.10.15 add and change by wu.yb
		//因为需要增加新的指标； 并且这些指标不是数据库表尺寸这样的形式；
		//其中OrderSize  TradeSize 是计算表的尺寸，延用原来的方式，使用select count(1) from table计算表的尺寸，
		//但 TotalVolume 指标却需要使用 select sum(Volume) from  table进行计算
		//TotalAmount select a.Volume * a.Price * b.VolumeMultiple from currsgoperation.t_trade a , sync.t_Instrument b
		// 基于这样的情况，对现有GetSpi进行调整，
		// 1 网络相关的部分独立出来；
		// 2 对 tableSize TotalVolume TotalAmount 这3类指标分别定义不同的函数
		int getVolume(SAConnection *conn, const string &tableName);
		double	getAmount(SAConnection *conn);

		///执行存储过程函数	20090624 add by zhou.jj
			///@param	conn	数据库连接指针
			///@param	spName	存储过程名称
			///@param	dataBaseAttr	存储过程对应的数据库别名、时段、存储过程类型
			///@return	
		bool getSP(
				SAConnection *conn,
				const string &spName,
				CDataBaseAttr &dataBaseAttr);

		///执行数据库临时监控请求处理函数
			///@param	cDBQueryField	数据库临时请求对象
			///@return	
		bool getReqSP(CDBQueryField &cDBQueryField);

		///执行取数据库日志表
			///@param	conn	数据库连接指针
			///@param	tableName	数据库日志表名称
			///@param	dataBaseAttr	数据库日志表信息
			///@return	
		bool getDBLog(
				SAConnection *conn,
				const string &tableName,
				CDataBaseAttr &dataBaseAttr);

		///发送指标数据
		// @param attrName 指标的名称
		// @param attrValue 指标的数值
		// @param valueType
		void sendData(
				const char	*attrName,
				const char	*attrValue,
				int valueType);

		///查找数据库的连接参数，并进行连接，同时对连接对象进行缓存
			///@param	dbName 需要查找的数据库的别名
			///@param	returnType	使用该数据库连接的应用是sp类型还是db类型,用于区分是数据库监控调用的sp还是业务系统取指标的sp
			///@return 返回数据库连接指针，NULL 不能取得数据库连接对象
		SAConnection *getConnectionObj(
						const string &dbName,
						const string &returnType);

		/// 判断一个属性的最后字符串(以[.]进行分割)是否特定的字符串
		//orignal="xxx.yyy.[DbTotalVolume|DbTotalAmount]
		// 采用的是大小写不敏感的方式
		bool isXProp(const char *orignal, const char *propKey) const;

		///产生告警事件，并打包发送到所有的连接
			///@param	pEventName	告警事件名
			///@param	pObjectName	告警对象名
			///@param	pEventDes	告警描述信息
			///@param	pDBName		告警产生的数据库别名
		void GenerateProbeEvent(
				char *pEventName,
				char *pObjectName,
				char *pEventDes,
				char *pDBName);

	/* */
	private:
		// Added by Henchi 20080721
			///保存当天的日期
		char m_mDate[10];

		///保存的当前采集时间
		char m_mTime[10];

		///保存的采集对象ID
		char m_mObjectId[64];

		///采集对象属性信息的FTD域
		CFTDRtnObjectAttrField	m_ObjAttrInfo;

		///告警产生的时间间隔
		int m_nInterval;

		///告警事件序列号，递增
		int m_nEventId;

		///告警事件名编号，相同对象的相同告警每次均相同
		int m_nEventNum;

		///@key	告警事件名称
			///@value	告警最近发生的时间
		map<string, int> m_mapEventDesc;

		///@key	数据库别名
			///@value	数据库别名对应的连接信息
		map<string, CDBConnectString> m_DatabaseInfoMap;	// 数据库连接信息
		
			///@key	数据库的ObjectID
			///@value	数据库别名
		map<string, string> m_ObjectIdDBNameMap;			//保存数据库的对象ID及对应别名信息
		
			///用于缓存各个不同的数据库的连接

		//QQQQ 需要考虑赋值的问题
			///这里采用指针进行存储，避免赋值操作的不完整；
			///@key	数据库别名
			///@value	用该别名建立的数据库连接指针, 这个map同m_DatabaseInfoMap一同使用
		map<string, SAConnection *> m_dbConnections;

		///用于缓存各个不同的数据库的连接是否真正活跃，一个spi调用周期只是真正的执行SQL一次
			///@key	用该别名建立的数据库连接指针,
			///@value	连接是否真正活跃
		map<SAConnection *, bool> m_connActive;

		///@key	监控指标名称,如tinit.DBSeriesLen
			///@value	监控指标需要采集的表名、数据库别名结构列表
		map<string, listTDB> m_DBAttrMap;					// 数据库监控指标信息
			///@key	监控指标名称,如tinit.DBSeriesLen
			///@value	监控指标对应的时段，此时数据库别名无效
		map<string, CDataBaseAttr>	m_DBAttrSepsMap;		// 数据库监控指标信息
		
			///@key	存储过程名,如dbmonitorpkg.getinstancenameproc
			///@value	存储过程对应的数据库别名、时段、存储过程类型
		map<string, CDataBaseAttr>	m_SPmap;				//所有需要采集的SP信息
		
			///@key	数据库日志表名称,如monitor.t_syslog
			///@value	日志表对应的数据库别名、时段
		map<string, CDataBaseAttr>	m_DBLogmap;				//所有需要采集的数据库日志表信息

	/* */
	public:
		//20090515 By Solomon Wu
		deque<CFTDRtnObjectAttrField> m_attrInfo;
		deque<CFTDRtnWarningEventField> m_eventInfo;
		deque<CFTDRtnSyslogEventField>	m_syslogInfo;
		deque<CFTDRtnDBQueryField>	m_dbqueryInfo;

		///保存当前所有未处理的和已经处理的查询请求
		list<CDBQueryField> m_reqDbQuery;

		///保存当前所有未发送的对象ID主机ID变更消息
		list<CFTDRtnUpdateSysConfigField> m_updateConfigInfo;

		CMutex	m_dataLock;
		CMutex	m_cmdLock;
		list<CFTDRspQryHostConfigField> m_configList;
		list<CSPQuery>	m_spQueryList;
};
#endif // !defined(REF_DATABASESPIIMPL_H)
