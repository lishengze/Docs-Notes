/////////////////////////////////////////////////////////////////////////
///@system 交易监控系统
///@company 上海期货信息技术有限公司
///@file CFPPSubscriber.h
///@brief	定义了面向fibproxy会话订阅类，实现FTD包向XTP包的转化
///@history
///20080624	郭鹏		创建该文件
///20080624	郭鹏		修订注释
#ifndef SYS_FPPSUBSCRIBER_H
#define SYS_FPPSUBSCRIBER_H
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "public.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FTDCSubscriber.h"
#include "XTPPackage.h"
#include "FibProxyData.h"
#include "FileFlow.h"
#include "CConfig.h"
#include "CachedFileFlow.h"
#include "XtpPackageDesc.h"
#include "FtdPackageDesc.h"
#include "UFCopy.h"
#include "EventConnect.h"
#include <PrjCommon.h>

#ifdef WIN32
#include <direct.h>
#define MKDIR(path, mode)	mkdir(path)
#else
#define MKDIR(path, mode)	mkdir(path, mode)
#endif
struct userIpInfo
{
	CUserIDType id;
	CIPAddressType	ip;
};

struct ipLinkInfo
{
	string	name;	//显示名
	string	type;	//托管类型
	list<pair<string, string> > ipScope;						//区间范围
	map<CParticipantIDType, list<userIpInfo> >	linkNumber;		//区间内会员及下属席位
	map<CParticipantIDType, list<userIpInfo> >	maxlinkNumber;	//区间内会员及下属席位
	int orderCount; //报单笔数
	int tradeCount; //成交笔数
};

struct trsInfo
{
	string	time;
	vector<CFTDRspQryTradeLogField> field;
};


/// 全局方法
/// 清理已从流水中统计到的各类数据，交易日切换时使用
void ClearStatInfo(void);

//
// typedef struct
// {
// 	///会员代码
// 	CParticipantIDType	ParticipantID;
// 	///会员名称
// 	CParticipantNameType	ParticipantName;
// 	///会员简称
// 	CParticipantAbbrType	ParticipantAbbr;
// 	///会员类型
// 	CMemberTypeType	MemberType;
//
// };
class CMemberTradeOrderRecTrace;

class CSeatOrderTrdCslTrace
{
	/* */
	public:
		CSeatOrderTrdCslTrace(void)
		{
		}

		~CSeatOrderTrdCslTrace(void)
		{
		};

		//////////////////////////////////////////////////////////////////////////
		//@param	nType		报单类型， 1：新单， 2：取消， 3：成交， 4：查询
		//@param	strTime		下单时间或者成交时间
		//@param	nCnt		报单数量
		//@param	nPrice		报单成交金额
		void AddOrder(int nType, string strTime, int nCnt, double nPrice = 0.0);

		typedef struct
		{
			// 1: orderinsert, 2: cancle 3: trade 4:query
			int nType;
			int nFrontID;
			int nOrderNum;
			double	nPrice;
		} SOTC_OrderInput;

		//会员号
		string	strPartyNo;

		//席位号
		string	strUserNo;

		int nFrontID;

		//key: time
		//value: 每秒的统计
		map<string, CFTDRtnParticTradeOrderStatesField> mpTraceOrdInput;
};

class CMemberTradeOrderRecTrace
{
	/* */
	public:
		CMemberTradeOrderRecTrace(void)
		{
		};
		~CMemberTradeOrderRecTrace(void)
		{
		};

		void HasPacksNeedSend(
				list<CFTDRtnParticTradeOrderStatesField> &lstPktRdy);

		CSeatOrderTrdCslTrace &RecordNewOrderInput(
		string	strUser,
		int nUserFrtID = 0)
		{
			if (mpSeatTrade.find(strUser) == mpSeatTrade.end())
			{
				mpSeatTrade[strUser].strUserNo = strUser;
				mpSeatTrade[strUser].strPartyNo = strPartiNo;
				mpSeatTrade[strUser].nFrontID = nUserFrtID;
			}

			return mpSeatTrade[strUser];
		}

		//会员号
		string	strPartiNo;

		//席位交易
		//key: 席位号
		map<string, CSeatOrderTrdCslTrace>	mpSeatTrade;
};

/////////////////////////////////////////////////////////////////////////
///CFPPSubscriber定义了面向fibproxy会话订阅类，实现FTD包向XTP包的转化
///@author	郭鹏
///@version	1.0,20080624
/////////////////////////////////////////////////////////////////////////
class CFPPSubscriber :
	public CFTDCSubscriber
{
	/* */
	public:
		///构造函数
			///@param	wSequenceSeries	订阅的主题序列号
		CFPPSubscriber(WORD wSequenceSeries);

		///析构函数
		virtual ~CFPPSubscriber(void);

		///流创建函数
			///@param	pszFlowPath	流创建磁盘路径
			///@return	无返回值
		void CreateFlow(const char *pszFlowPath);

		///设置通讯阶段编号函数
			///@param	wCommPhaseNo	通讯阶段编号
		virtual void SetCommPhaseNo(WORD wCommPhaseNo);

		///获得主题序列号	
			///@return	主题序列号
		virtual WORD GetSequenceSeries(void);

		///得到已接受包的个数
			///@return	已收到包的个数
		virtual DWORD GetReceivedCount(void);

		///包处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		virtual void HandleMessage(CFTDCPackage *pMessage);

	/* */
	private:
		///时钟同步处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnNtfTimeSync(CXTPPackage *pMessage);

		///错误报单处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnRspOrderInsert(CXTPPackage *pMessage);

		///报单处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnRspOrderAction(CXTPPackage *pMessage);

		///报单状态处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnNtfOrder(CXTPPackage *pMessage);

		///成交单处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnNtfTrade(CXTPPackage *pMessage);

		///合约属性处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnInitCurrInstrumentProperty(CXTPPackage *pMessage);

		///合约基本属性处理函数，与上包一同构成发送包
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnInitInstrument(CXTPPackage *pMessage);

		///保证金率处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnInitCurrMarginRateDetail(CXTPPackage *pMessage);

		///涨跌停板处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnInitCurrPriceBanding(CXTPPackage *pMessage);

		///会员限仓处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnInitCurrPartPosiLimitDetail(CXTPPackage *pMessage);

		///客户限仓处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnInitCurrClientPosiLimitDetail(CXTPPackage *pMessage);

		///特殊客户限仓处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnInitCurrSpecialPosiLimitDetail(CXTPPackage *pMessage);

		///会员账户关系处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnInitPartRoleAccount(CXTPPackage *pMessage);

		///账户出入金处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnDbAccountDeposit(CXTPPackage *pMessage);

		///客户数据变动处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnClientChg(CXTPPackage *pMessage);

		///会员客户对照关系变动处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnPartClientChg(CXTPPackage *pMessage);

		///会员限仓变动处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnPosiLimitChg(CXTPPackage *pMessage);

		///客户限仓变动处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnClientPosiLimitChg(CXTPPackage *pMessage);

		///特殊客户限仓变动处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnSpecPosiLimitChg(CXTPPackage *pMessage);

		///保值额度变动处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnDbInsHedgeDetail(CXTPPackage *pMessage);

		///会员变动处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnDbParticipant(CXTPPackage *pMessage);

		///保证金率变动处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnMarginRateChg(CXTPPackage *pMessage);

		///用户IP变动处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnUserIpChg(CXTPPackage *pMessage);

		///USER变动处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnDbUser(CXTPPackage *pMessage);

		///用户信息处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnUserLogin(CXTPPackage *pMessage);

		///用户信息处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnUserLogout(CXTPPackage *pMessage);

		///用户被强制退出处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnDelUserSession(CXTPPackage *pMessage);

		///用户信息处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnInitPartPosition(CXTPPackage *pMessage);

		///涨跌停板变动处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnCurrPriceBandingChg(CXTPPackage *pMessage);

		///会员信息处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void OnInitParticipant(CXTPPackage *pMessage);

		///死机重启处理函数
			///@param	pMessage	收到包
			///@reeturn 无返回值
		void ReLoad(void);
		void OnInstrumentStatusUpdate(CXTPPackage *pMessage);
		void OnInitCurrTradingSegmentAttr(CXTPPackage *pMessage);

		/// 缓冲最后100个报文
		void BufferLast100Packages();

		/* */
	public:
		///保存FTD包的流
		CFlow *m_pFlow;

	/* */
	private:
		///主题序列号
		WORD m_wSequenceSeries;

		///存放需要转化的XTP包
		CXTPPackage m_pkgXTP;

		///存放已转化后的FTD包
		CFTDCPackage m_pkgSend;

		///当前时间
		//	CCurrentTimeField m_curTime;
		int m_nCount;

		///重启流回读标记
		bool m_Reload;
};

///用于处理管理平台初始化信息的宏:
#define MANAGERINIT(x)												   \
	{																   \
		C##x##Field sfield;											   \
		CNamedFieldIterator itor = m_pkgXTP.GetNamedFieldIterator(	   \
				&C##x##Field::m_Describe);							   \
		while (!itor.IsEnd())										   \
		{															   \
			itor.Retrieve(&sfield);									   \
			m_pkgSend.PreparePackage(								   \
					FTD_TID_Rtn##x##InitTopic,						   \
					FTDC_CHAIN_LAST,								   \
					FTD_VERSION);									   \
			CFTDRtn##x##InitField tfield;							   \
			tfield.OperationType = 0;								   \
			Copy##x##Entity(&tfield, &sfield);						   \
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);					   \
			m_pkgSend.MakePackage();								   \
			m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length()); \
			itor.Next();											   \
		}															   \
	}

/************************************************************************
* 会员/席位登录统计、告警功能
************************************************************************/

// 使用string统一席位(User)和会员(Participant)ID
typedef std::string UPLoginRecordID;
// 登录类型
enum LoginRecordType
{
	User,			// 席位
	Participant		// 会员
};
/////////////////////////////////////////////////////////////////////////
/// UPLoginRecord定义了席位/会员登录统计信息
/// 该对象仅负责统计登陆信息，具体的告警计算由其他对象负责
/// @author	曹宁
/// @version	1.0,20150513
/////////////////////////////////////////////////////////////////////////
class UPLoginRecord
{
public:
	// 向统计列表中添加一个记录
	static UPLoginRecord* fetchRecord(const UPLoginRecordID& _id, LoginRecordType _type);
	// 从统计列表中删除一个记录
	static void removeRecord(const UPLoginRecordID& _id);
	// 重置所有记录
	static void resetAllRecords();

public:
	// 获取ID
	const UPLoginRecordID& getRecordID() const { return m_RecordID; }
	
	// 获取类型
	LoginRecordType getRecordType() const { return m_Type; }

	// 登陆次数+1
	void record(time_t _time, int _frontid) { m_LoginRecords.push_back(LoginInfo(_time, _frontid)); }

	// 获取所有的登陆次数
	int loginTotalCount() const { return m_LoginRecords.size(); }

	// 计算从_endMoment时刻向前_timeLength秒内的登陆次数
	int loginCount(time_t _endMoment, int _timeLength) const;

	// 获取从_endMoment时刻向前_timeLength秒内的登录明细
	// 若_endMoment为0，表示所有登录信息
	// _outputLen表示按序输出前N个明细
	string loginDetail(time_t _endMoment = 0, int _timeLength = 0, int _outputLen = 2) const;

	// 重置记录
	void resetRecord() { m_LoginRecords.clear(); }

#ifdef PRINT_DEBUG
	// dump当前席位的登录数据至文件
	void dump(FILE* _pFile) const
	{
		fprintf(_pFile, "%s : ", m_RecordID.c_str());
		char timeBuffer[32];
		for (vector<LoginInfo>::const_iterator itRecord = m_LoginRecords.begin();
			itRecord != m_LoginRecords.end(); ++itRecord)
		{
			memset(timeBuffer, 0, 32);
			struct tm tm_Now;
			LocalTime(&itRecord->LoginTime, &tm_Now);
			strftime(timeBuffer, 32, "[%Y%m%d %H:%M:%S]", &tm_Now);
			fprintf(_pFile, "%s ", timeBuffer);
		}
		fprintf(_pFile, "\n");
	}
	// dump所有席位的登录数据
	static void dump()
	{
		printf("%s ParticipantRecord Count[%d]\n", __FUNCTION__, m_AllRecords.size());
		FILE* pDumpFile = fopen("RecordsDumpFile.txt", "a");
		if (pDumpFile)
		{
			fprintf(pDumpFile, "[ParticipantLoginRecord::dump]\n");
			for (map<UPLoginRecordID, UPLoginRecord*>::iterator
				it = m_AllRecords.begin(); it != m_AllRecords.end(); ++it)
			{
				it->second->dump(pDumpFile);
			}
			fprintf(pDumpFile, "\n");
			fclose(pDumpFile);
		}
		else
		{
			printf("Open RecordsDumpFile.txt Error!\n");
		}
	}
#endif // PRINT_DEBUG

private:
	UPLoginRecord(const UPLoginRecordID& _RecordID, LoginRecordType _type)
		: m_RecordID(_RecordID), m_Type(_type)
	{ }

	~UPLoginRecord() {}

	// 保存所有席位/会员的统计信息
	static map<UPLoginRecordID, UPLoginRecord*> m_AllRecords;

	/* LoginRecordID */
	UPLoginRecordID m_RecordID;

	LoginRecordType m_Type;

	/* 记录该席位/会员的登录信息，如时间等，后续可扩展 */
	struct LoginInfo
	{
		LoginInfo(time_t _time, int _frontid)
			: LoginTime(_time), FrontID(_frontid) { }
		time_t LoginTime;
		int FrontID;
	};
	vector<LoginInfo> m_LoginRecords;
};

/////////////////////////////////////////////////////////////////////////
///LoginWarningCalculate定义了席位/会员登录告警计算功能
///@author	曹宁
///@version	1.0,20150513
/////////////////////////////////////////////////////////////////////////
class LoginWarningCalculate
{
public:
	/* 从配置文件中读取计算对象 */
	static bool loadCalculateObjectFromXml(const char* _fileName);

	/* 字符串格式时间转化为time_t，发生错误时返回-1 */
	static inline time_t convertToTime(const CDateType& _date, const CTimeType& _time)
	{
		struct tm sTM;
		sscanf(_date.getValue(), "%4d%2d%2d",
			&sTM.tm_year, &sTM.tm_mon, &sTM.tm_mday);
		sscanf(_time.getValue(), "%2d:%2d:%2d",
			&sTM.tm_hour, &sTM.tm_min, &sTM.tm_sec);
		sTM.tm_year -= 1900;
		sTM.tm_mon--;
		sTM.tm_isdst = -1;
		return mktime(&sTM);
	}

private:
	LoginWarningCalculate(
		const char* _EventName,
		int _Interval,
		int _Threshold,
		int _WarningGap,
		bool _userEnable = true,
		bool _participantEnable = true)
		: m_EventName(_EventName), m_Interval(_Interval), 
		m_Threshold(_Threshold), m_WarningGap(_WarningGap),
		m_UserEnable(_userEnable), m_ParticipantEnable(_participantEnable)
	{
	}
	~LoginWarningCalculate() {}

public:
	/* 处理一个会员用户登录信息 */
	static void HandleUserLoginField(const CUserLoginField& _loginField, int _frontID);

	/* 清理所有告警计算对象的中间状态 */
	static void reset()
	{
		for (vector<LoginWarningCalculate*>::iterator
			itObject = m_AllCalculate.begin();
			itObject != m_AllCalculate.end();
			++itObject)
		{
			(*itObject)->clearParticipantState();
		}
	}

private:
	// 清理当前告警对象下的所有席位中间状态
	void clearParticipantState() { m_AllRecordState.clear(); }

	// 处理一条记录，_BasisTime为该记录的基准时刻，_LocalTime为本地时间
	void HandleRecord(UPLoginRecord* _Record, time_t _BasisTime, time_t _LocalTime);

private:
	/* 告警名称 */
	string m_EventName;

	/* 统计周期 */
	int m_Interval;

	/* 告警阈值 */
	int m_Threshold;

	/* 该告警是否针对席位/会员有效，默认有效，具体值来源于xml配置 */
	bool m_UserEnable;
	bool m_ParticipantEnable;

	/* 告警间隔 */
	int m_WarningGap;

	/* 针对该告警计算对象，保存每个记录的中间状态 */
	struct RecordState
	{
		RecordState() : LastWarningTime(0) {}
		time_t LastWarningTime;	// 该用户上一次发送该告警的时间
	};
	map<UPLoginRecordID, RecordState> m_AllRecordState;

	/* 获取特定记录的中间状态，返回引用 */
	RecordState& getRecordState(const UPLoginRecordID& _RecordID);

	/* 保存所有的计算对象 */
	static vector<LoginWarningCalculate*> m_AllCalculate;

	/* 存放用于发送数据的包 */
	static CFTDCPackage m_pkgSend;
	/* 存放用于发送时间的数据域 */
	static CFTDRtnSyslogEventField m_SyslogEventField;
};

//typedef map<CParticipantIDType ,map<CInstrumentIDType ,CVolumeType> > totalMap;
#endif // !defined(AFX_SYSMONITOR_SYSFIBCLIENT_CFPPSUBSCRIBER_H__20080604__INCLUDED_)
