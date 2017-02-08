/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	FtdEngine.cpp
///@brief	�ƶ���ػỰ������ʵ��
///@history
///20140617	����		�������ļ�
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
	DWORD nSessionID;					/**<�Ự��  */
	DWORD nConnectTime;					/**<���ӽ���ʱ��  */
	int nDialogFlowSeqNo;				/**<�Ի�����ǰ��� */
	int nQueryFlowSeqNo;				/**<��ѯ����ǰ��� */
	bool bIsLogin;						/**<�Ƿ��Ѿ���¼  */
	CUserIDType UserID;					/**<�Ự�����û�����  */
	CParticipantIDType ParticipantID;	/**<�Ự������Ա����  */
	int nCommFlux;						/**<��λʱ���ͨѶ���� */
	int nMaxCommFlux;					/**<��λʱ���ͨѶ�������� */
	CUserTypeType UserType;				/**<�û����� */
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
