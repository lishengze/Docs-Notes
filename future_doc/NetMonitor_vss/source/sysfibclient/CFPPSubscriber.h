/////////////////////////////////////////////////////////////////////////
///@system ���׼��ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CFPPSubscriber.h
///@brief	����������fibproxy�Ự�����࣬ʵ��FTD����XTP����ת��
///@history
///20080624	����		�������ļ�
///20080624	����		�޶�ע��
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
	string	name;	//��ʾ��
	string	type;	//�й�����
	list<pair<string, string> > ipScope;						//���䷶Χ
	map<CParticipantIDType, list<userIpInfo> >	linkNumber;		//�����ڻ�Ա������ϯλ
	map<CParticipantIDType, list<userIpInfo> >	maxlinkNumber;	//�����ڻ�Ա������ϯλ
	int orderCount; //��������
	int tradeCount; //�ɽ�����
};

struct trsInfo
{
	string	time;
	vector<CFTDRspQryTradeLogField> field;
};


/// ȫ�ַ���
/// �����Ѵ���ˮ��ͳ�Ƶ��ĸ������ݣ��������л�ʱʹ��
void ClearStatInfo(void);

//
// typedef struct
// {
// 	///��Ա����
// 	CParticipantIDType	ParticipantID;
// 	///��Ա����
// 	CParticipantNameType	ParticipantName;
// 	///��Ա���
// 	CParticipantAbbrType	ParticipantAbbr;
// 	///��Ա����
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
		//@param	nType		�������ͣ� 1���µ��� 2��ȡ���� 3���ɽ��� 4����ѯ
		//@param	strTime		�µ�ʱ����߳ɽ�ʱ��
		//@param	nCnt		��������
		//@param	nPrice		�����ɽ����
		void AddOrder(int nType, string strTime, int nCnt, double nPrice = 0.0);

		typedef struct
		{
			// 1: orderinsert, 2: cancle 3: trade 4:query
			int nType;
			int nFrontID;
			int nOrderNum;
			double	nPrice;
		} SOTC_OrderInput;

		//��Ա��
		string	strPartyNo;

		//ϯλ��
		string	strUserNo;

		int nFrontID;

		//key: time
		//value: ÿ���ͳ��
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

		//��Ա��
		string	strPartiNo;

		//ϯλ����
		//key: ϯλ��
		map<string, CSeatOrderTrdCslTrace>	mpSeatTrade;
};

/////////////////////////////////////////////////////////////////////////
///CFPPSubscriber����������fibproxy�Ự�����࣬ʵ��FTD����XTP����ת��
///@author	����
///@version	1.0,20080624
/////////////////////////////////////////////////////////////////////////
class CFPPSubscriber :
	public CFTDCSubscriber
{
	/* */
	public:
		///���캯��
			///@param	wSequenceSeries	���ĵ��������к�
		CFPPSubscriber(WORD wSequenceSeries);

		///��������
		virtual ~CFPPSubscriber(void);

		///����������
			///@param	pszFlowPath	����������·��
			///@return	�޷���ֵ
		void CreateFlow(const char *pszFlowPath);

		///����ͨѶ�׶α�ź���
			///@param	wCommPhaseNo	ͨѶ�׶α��
		virtual void SetCommPhaseNo(WORD wCommPhaseNo);

		///����������к�	
			///@return	�������к�
		virtual WORD GetSequenceSeries(void);

		///�õ��ѽ��ܰ��ĸ���
			///@return	���յ����ĸ���
		virtual DWORD GetReceivedCount(void);

		///��������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		virtual void HandleMessage(CFTDCPackage *pMessage);

	/* */
	private:
		///ʱ��ͬ��������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnNtfTimeSync(CXTPPackage *pMessage);

		///���󱨵�������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnRspOrderInsert(CXTPPackage *pMessage);

		///����������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnRspOrderAction(CXTPPackage *pMessage);

		///����״̬������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnNtfOrder(CXTPPackage *pMessage);

		///�ɽ���������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnNtfTrade(CXTPPackage *pMessage);

		///��Լ���Դ�����
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnInitCurrInstrumentProperty(CXTPPackage *pMessage);

		///��Լ�������Դ����������ϰ�һͬ���ɷ��Ͱ�
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnInitInstrument(CXTPPackage *pMessage);

		///��֤���ʴ�����
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnInitCurrMarginRateDetail(CXTPPackage *pMessage);

		///�ǵ�ͣ�崦����
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnInitCurrPriceBanding(CXTPPackage *pMessage);

		///��Ա�޲ִ�����
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnInitCurrPartPosiLimitDetail(CXTPPackage *pMessage);

		///�ͻ��޲ִ�����
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnInitCurrClientPosiLimitDetail(CXTPPackage *pMessage);

		///����ͻ��޲ִ�����
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnInitCurrSpecialPosiLimitDetail(CXTPPackage *pMessage);

		///��Ա�˻���ϵ������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnInitPartRoleAccount(CXTPPackage *pMessage);

		///�˻����������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnDbAccountDeposit(CXTPPackage *pMessage);

		///�ͻ����ݱ䶯������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnClientChg(CXTPPackage *pMessage);

		///��Ա�ͻ����չ�ϵ�䶯������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnPartClientChg(CXTPPackage *pMessage);

		///��Ա�޲ֱ䶯������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnPosiLimitChg(CXTPPackage *pMessage);

		///�ͻ��޲ֱ䶯������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnClientPosiLimitChg(CXTPPackage *pMessage);

		///����ͻ��޲ֱ䶯������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnSpecPosiLimitChg(CXTPPackage *pMessage);

		///��ֵ��ȱ䶯������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnDbInsHedgeDetail(CXTPPackage *pMessage);

		///��Ա�䶯������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnDbParticipant(CXTPPackage *pMessage);

		///��֤���ʱ䶯������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnMarginRateChg(CXTPPackage *pMessage);

		///�û�IP�䶯������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnUserIpChg(CXTPPackage *pMessage);

		///USER�䶯������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnDbUser(CXTPPackage *pMessage);

		///�û���Ϣ������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnUserLogin(CXTPPackage *pMessage);

		///�û���Ϣ������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnUserLogout(CXTPPackage *pMessage);

		///�û���ǿ���˳�������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnDelUserSession(CXTPPackage *pMessage);

		///�û���Ϣ������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnInitPartPosition(CXTPPackage *pMessage);

		///�ǵ�ͣ��䶯������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnCurrPriceBandingChg(CXTPPackage *pMessage);

		///��Ա��Ϣ������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void OnInitParticipant(CXTPPackage *pMessage);

		///��������������
			///@param	pMessage	�յ���
			///@reeturn �޷���ֵ
		void ReLoad(void);
		void OnInstrumentStatusUpdate(CXTPPackage *pMessage);
		void OnInitCurrTradingSegmentAttr(CXTPPackage *pMessage);

		/// �������100������
		void BufferLast100Packages();

		/* */
	public:
		///����FTD������
		CFlow *m_pFlow;

	/* */
	private:
		///�������к�
		WORD m_wSequenceSeries;

		///�����Ҫת����XTP��
		CXTPPackage m_pkgXTP;

		///�����ת�����FTD��
		CFTDCPackage m_pkgSend;

		///��ǰʱ��
		//	CCurrentTimeField m_curTime;
		int m_nCount;

		///�������ض����
		bool m_Reload;
};

///���ڴ������ƽ̨��ʼ����Ϣ�ĺ�:
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
* ��Ա/ϯλ��¼ͳ�ơ��澯����
************************************************************************/

// ʹ��stringͳһϯλ(User)�ͻ�Ա(Participant)ID
typedef std::string UPLoginRecordID;
// ��¼����
enum LoginRecordType
{
	User,			// ϯλ
	Participant		// ��Ա
};
/////////////////////////////////////////////////////////////////////////
/// UPLoginRecord������ϯλ/��Ա��¼ͳ����Ϣ
/// �ö��������ͳ�Ƶ�½��Ϣ������ĸ澯����������������
/// @author	����
/// @version	1.0,20150513
/////////////////////////////////////////////////////////////////////////
class UPLoginRecord
{
public:
	// ��ͳ���б������һ����¼
	static UPLoginRecord* fetchRecord(const UPLoginRecordID& _id, LoginRecordType _type);
	// ��ͳ���б���ɾ��һ����¼
	static void removeRecord(const UPLoginRecordID& _id);
	// �������м�¼
	static void resetAllRecords();

public:
	// ��ȡID
	const UPLoginRecordID& getRecordID() const { return m_RecordID; }
	
	// ��ȡ����
	LoginRecordType getRecordType() const { return m_Type; }

	// ��½����+1
	void record(time_t _time, int _frontid) { m_LoginRecords.push_back(LoginInfo(_time, _frontid)); }

	// ��ȡ���еĵ�½����
	int loginTotalCount() const { return m_LoginRecords.size(); }

	// �����_endMomentʱ����ǰ_timeLength���ڵĵ�½����
	int loginCount(time_t _endMoment, int _timeLength) const;

	// ��ȡ��_endMomentʱ����ǰ_timeLength���ڵĵ�¼��ϸ
	// ��_endMomentΪ0����ʾ���е�¼��Ϣ
	// _outputLen��ʾ�������ǰN����ϸ
	string loginDetail(time_t _endMoment = 0, int _timeLength = 0, int _outputLen = 2) const;

	// ���ü�¼
	void resetRecord() { m_LoginRecords.clear(); }

#ifdef PRINT_DEBUG
	// dump��ǰϯλ�ĵ�¼�������ļ�
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
	// dump����ϯλ�ĵ�¼����
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

	// ��������ϯλ/��Ա��ͳ����Ϣ
	static map<UPLoginRecordID, UPLoginRecord*> m_AllRecords;

	/* LoginRecordID */
	UPLoginRecordID m_RecordID;

	LoginRecordType m_Type;

	/* ��¼��ϯλ/��Ա�ĵ�¼��Ϣ����ʱ��ȣ���������չ */
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
///LoginWarningCalculate������ϯλ/��Ա��¼�澯���㹦��
///@author	����
///@version	1.0,20150513
/////////////////////////////////////////////////////////////////////////
class LoginWarningCalculate
{
public:
	/* �������ļ��ж�ȡ������� */
	static bool loadCalculateObjectFromXml(const char* _fileName);

	/* �ַ�����ʽʱ��ת��Ϊtime_t����������ʱ����-1 */
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
	/* ����һ����Ա�û���¼��Ϣ */
	static void HandleUserLoginField(const CUserLoginField& _loginField, int _frontID);

	/* �������и澯���������м�״̬ */
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
	// ����ǰ�澯�����µ�����ϯλ�м�״̬
	void clearParticipantState() { m_AllRecordState.clear(); }

	// ����һ����¼��_BasisTimeΪ�ü�¼�Ļ�׼ʱ�̣�_LocalTimeΪ����ʱ��
	void HandleRecord(UPLoginRecord* _Record, time_t _BasisTime, time_t _LocalTime);

private:
	/* �澯���� */
	string m_EventName;

	/* ͳ������ */
	int m_Interval;

	/* �澯��ֵ */
	int m_Threshold;

	/* �ø澯�Ƿ����ϯλ/��Ա��Ч��Ĭ����Ч������ֵ��Դ��xml���� */
	bool m_UserEnable;
	bool m_ParticipantEnable;

	/* �澯��� */
	int m_WarningGap;

	/* ��Ըø澯������󣬱���ÿ����¼���м�״̬ */
	struct RecordState
	{
		RecordState() : LastWarningTime(0) {}
		time_t LastWarningTime;	// ���û���һ�η��͸ø澯��ʱ��
	};
	map<UPLoginRecordID, RecordState> m_AllRecordState;

	/* ��ȡ�ض���¼���м�״̬���������� */
	RecordState& getRecordState(const UPLoginRecordID& _RecordID);

	/* �������еļ������ */
	static vector<LoginWarningCalculate*> m_AllCalculate;

	/* ������ڷ������ݵİ� */
	static CFTDCPackage m_pkgSend;
	/* ������ڷ���ʱ��������� */
	static CFTDRtnSyslogEventField m_SyslogEventField;
};

//typedef map<CParticipantIDType ,map<CInstrumentIDType ,CVolumeType> > totalMap;
#endif // !defined(AFX_SYSMONITOR_SYSFIBCLIENT_CFPPSUBSCRIBER_H__20080604__INCLUDED_)
