// OFPProtocol.h: interface for the COFPProtocol class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OFPPROTOCOL_H__INCLUDED_)
#define AFX_OFPPROTOCOL_H__INCLUDED_

#include "Protocol.h"
#include "OFPPackage.h"
#include "OFPPubEndPoint.h"
#include "HashMap.h"

#define MSG_OFPERR_RECVHEARTBEAT		0xA001
#define MSG_OFPERR_SENDHEARTBEAT		0xA002
#define MSG_OFPERR_BADPACKAGE			0xA003

/**Э��ջ�����ĵڶ���Э�飬���ݾ�ϵͳ
*/
class  COFPProtocol : public CProtocol  
{
public:
	/**���캯��
	* @param pReactor ָ�����������ָ��
	* @param pBelow �²�Э���ָ��
	*/
	COFPProtocol(CReactor *pReactor, char chVersion);
	/**��������
	*/
	virtual ~COFPProtocol();

	/**����OFP��ͷ�������²�Э��
	* @param pPackage �ϲ��Э���´��İ�
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int Push(CPackage *pPackage, CProtocol *pUpper);
	
	/**��������ı��ķ��ͳ�ȥ
	*/
	void PublishSend();
	
	void Publish(CReadOnlyFlow *pFlow, WORD nSequenceSeries, int nStartId);
	void UnPublish(WORD nSequenceSeries);
protected:	
	/**��¼��ǰ�յ�����ʱ�䣬�ж��Ƿ�OFP�������ϴ�
	* @param pPackage �²�Э���ϴ��İ�
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int Pop(CPackage *pPackage);
		
	/**����ʱ��������CReactor���á�����������ʱ����֪ͨ�ϲ�Э�顣
	* ������д��ʱ�������������ġ�
	* @param nIDEvent ������Ϊ��ʱ��ʱ���ڶ�ʱ������ʱ����ʶ   
	*/
	virtual void OnTimer(int nIDEvent);
		
	/**�����������ģ�����������
	* @return >0   �ɹ�
	* @return <=0  ʧ�� 
	*/
	int SendHeartBeat();

	/**�յ�һ����������ݰ�ʱ����
	* @param pPackage ��������ݰ�
	* @return 0   �ɹ�
	* @return <>0 ʧ��
	*/
	virtual int OnRecvErrorPackage(CPackage *pPackage);

	COFPPubEndPoint *GetPubEndPoint(WORD nSequenceSeries);

protected:
	time_t m_LastWriteTime;		/**< ��󷢰�ʱ�䡡*/
	time_t m_LastReadTime;		/**< ����հ�ʱ�䡡*/
	CReactor *m_pReactor;
	char m_chVersion;
	
	typedef CHashMap<WORD, COFPPubEndPoint *, HashInt> CPubEndPointMap;
	CPubEndPointMap m_mapPubEndPoint;

	COFPPackage m_pkgHeartbeat;
};

#endif // !defined(AFX_OFPPROTOCOL_H__INCLUDED_)
