/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	FtdEngine.cpp
///@brief	移动监控会话服务器实现
///@history
///20140617	刘博		创建该文件
/////////////////////////////////////////////////////////////////////////


#ifndef RISKFRONT_FTDENGINEHPP
#define RISKFRONT_FTDENGINEHPP


#include "platform.h"
#include "Flow.h"
#include "FTDCSession.h"
#include "SessionFactory.h"
#include "IndexPackageFlow.h"
#include "customDataType.h"

struct TFrontSessionInfo
{
	DWORD nSessionID;					/**<会话号  */
	DWORD nConnectTime;					/**<连接建立时间  */
	int nDialogFlowSeqNo;				/**<对话流当前序号 */
	int nQueryFlowSeqNo;				/**<查询流当前序号 */
	bool bIsLogin;						/**<是否已经登录  */
	CUserIDType UserID;					/**<会话所属用户代码  */
	CParticipantIDType ParticipantID;	/**<会话所属会员代码  */
	int nCommFlux;						/**<单位时间的通讯流量 */
	int nMaxCommFlux;					/**<单位时间的通讯流量上限 */
	CUserTypeType UserType;				/**<用户类型 */
};

class CFtdEngine :
	public CSessionFactory,
	public CFTDCSessionCallback
{
public:
	CFtdEngine(CReactor *pReactor, const char *pszFlowPath);
	virtual ~CFtdEngine(void);
	virtual int HandlePackage(
					CFTDCPackage *pFTDCPackage,
					CFTDCSession *pSession);
protected:
	virtual CSession *CreateSession(CChannel *pChannel, DWORD);
	virtual void OnSessionConnected(CSession *pSession);
	virtual void OnSessionDisconnected(CSession *pSession, int nReason);

protected:
	CFlow *GetPublicFlow();
	CIndexPackageFlow *GetPrivateFlow(const CParticipantIDType &participantID);
	CIndexPackageFlow *GetUserFlow(const CUserIDType &userID);
	TFrontSessionInfo *GetSessionInfo(DWORD nSessionID);
	bool CFtdEngine::IsSessionLogin(DWORD nSessionID);

	void SendToDialogFlow(CFTDCSession *pSession, CFTDCPackage *pPackage);
	void SendToPrivateFlow(const CParticipantIDType &participantID, int nIndex);
	void SendToPublicFlow(CPackage *pPackage);
	void SendToQueryFlow(CFTDCSession *pSession, CFTDCPackage *pPackage);
	void SendToUserFlow(const CUserIDType &userID, int nIndex);
	int  AppendToPrivateFlow(CPackage *pPackage);
	bool PublishFlow(CFTDCSession *pSession, WORD wSequenceSeries, int nSubStartId,
		int &nPubStartId, bool bCheckDataCenter);

private:
	void SendErrorRsp(CFTDCPackage *pRequest, CFTDCSession *pSession, 
		const int nErrorCode, const char *pszErrorMsg);
	int OnReqUserLogin(CFTDCPackage *pPackage, CFTDCSession *pSession);


private:
	CFlow *m_pPublicFlow;
	CFlow *m_pPrivateFlow;

	typedef CHashMap<CParticipantIDType, CIndexPackageFlow *, HashString> CParticipantFlowMap;
	CParticipantFlowMap m_mapPrivateFlow;

	typedef CHashMap<CUserIDType, CIndexPackageFlow *, HashString> CUserFlowMap;
	CUserFlowMap m_mapUserFlow;

	typedef CHashMap<DWORD, TFrontSessionInfo, HashInt> CSessionInfoMap;
	CSessionInfoMap m_mapSessionInfo;

	CFTDCPackage m_rspPackage;
};

#endif
