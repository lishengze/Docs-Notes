#ifndef RISKFRONT_FTDENGINEHPP
#define RISKFRONT_FTDENGINEHPP

#include <map>
#include <string>
#include <vector>
using namespace std;

#include "FrontEngine.h"
#include "FTDCSession.h"
#include "FtdData.h"
#include "tools.h"

const int FTDE_MAX_SEQUENCE_SERIES = 10;

typedef char TForwardID[128 + 8];	//session+requestid
struct TFTDReq
{
	CFTDCPackage *pFtdPackage;
	DWORD nSessionID;
};

class CReqFtdPackageList :
	public CMPMC
{
	/* */
	public:
		CReqFtdPackageList(DWORD size = 1000000) :
		CMPMC(1000000)
		{
		};

		~CReqFtdPackageList(void)
		{
			int cnt = m_list.size();
			for (int i = 0; i < cnt; ++i)
			{
				struct TFTDReq	req;
				req = m_list.front();
				m_list.erase(m_list.begin());
			}
		};

	/* */
	protected:
		void OnGetOut(void *data)
		{
			*((struct TFTDReq *)data) = m_list.front();
			m_list.erase(m_list.begin());
			return;
		};

		void OnAddIn(void *data)
		{
			m_list.push_back(*(struct TFTDReq *)data);
			return;
		};

	/* */
	private:
		typedef std::list<struct TFTDReq> CList_CFTDCPackage;
		CList_CFTDCPackage m_list;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*class CRsqFtdPackageList : public CMPMC
{
public:
	CRsqFtdPackageList(DWORD size = 1000000) : CMPMC(1000000) {};
	
	~CRsqFtdPackageList() {
		int cnt = m_list.size();
		for (int i = 0; i < cnt; ++i) {
			struct TFTDReq req;
			req = m_list.front();
			m_list.erase(m_list.begin());
		}
	};

protected:
	void OnGetOut(void *data) {
		*((struct TFTDReq *) data) = m_list.front();
		m_list.erase(m_list.begin());
		return;
	};

	void OnAddIn(void *data) {
		m_list.push_back(*(struct TFTDReq *)data);
		return;
	};

private:
	typedef std::list<struct TFTDReq>	CList_CFTDCPackage;
	CList_CFTDCPackage		m_list;
};*/

/*class CRspPackageList
{
public:
	CRspPackageList()
	{
		count =0;
	}

	CFTDCPackage read(int )


private:
	CMutex m_Mutex;
	int count;
	int reader;
	int writer;
	std::list<CFTDCPackage> m_list;
}*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct TFTDRsp
{
	std::list<CFTDCPackage *> rsplist;
	DWORD nSessionID;
};
typedef std::list<CFTDCPackage *> CList_CFTDCPackages;
typedef std::list<struct TFTDRsp *> CList_CFTDCRspPackages;
struct TFtdeDisseminationInfo
{
	DWORD nSessionID;
	CDateType TradingDay;
	int nFieldCount;
	CFTDDisseminationField Fields[FTDE_MAX_SEQUENCE_SERIES];
};

class CFtdEngine :
	public CFrontEngine,
	public CFTDCSessionCallback
{
	/* */
	public:
		CFtdEngine(CReactor *pReactor, const char *pszFlowPath);
		virtual ~CFtdEngine(void);
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		void PutFtdReq(struct TFTDReq *pPackage);

		void GetFtdReq(struct TFTDReq *pPackage);

		void PutFtdRsp(struct TFTDRsp *pRsp, bool bPutToFront = false);

		void PutFtdRspToSessionFront(struct TFTDRsp *pRsp);

		struct TFTDRsp	*GetFtdRsp(void);

		virtual void OnTimer(int nIDEvent);

		void ForwardAgent(CFTDCPackage *pFTDCPackage);

		void SendQueryRspByAgent(void);

	/* */
	protected:
		virtual CSession *CreateSession(CChannel *pChannel, bool bIsListener);
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		void SendErrorRsp(
				CFTDCSession *pSession,
				const int nErrorCode,
				const char *pszErrorMsg);

	/* */
	private:
		typedef std::map<std::string, struct TFTDReq> CMap_ForwardQry;

		CFTDCPackage m_rspPackage;
		CReqFtdPackageList m_UserRequest;
		CList_CFTDCRspPackages m_UserRsp;

		CMutex m_rspProtect;
		CMap_ForwardQry m_mapForwardQry;
		CList_CFTDCPackages m_AgentResponse;
};
#endif
