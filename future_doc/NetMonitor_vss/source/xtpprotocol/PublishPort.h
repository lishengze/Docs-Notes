// PublishPort.h: interface for the CPublishPort class.
//
// 20120409  ����   NT-0139 �ӿ���Ӧʱ�䣺xtpЭ���޸�Ϊ΢�뼶����
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUBLISHPORT_H__88F9C025_0AE8_4FBE_AAFD_56BAE65FECFD__INCLUDED_)
#define AFX_PUBLISHPORT_H__88F9C025_0AE8_4FBE_AAFD_56BAE65FECFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FlowReader.h"
#include "Protocol.h"
#include "XTPPackage.h"

/**��¼һ�������ߵ���Ϣ
*/
struct TSubscirberInfo
{
	DWORD dwSubscriberID;				/**< �����ߴ��� */
	DWORD dwLastActiveTime;				/**< �ϴη���ACKʱ�� */
};

/**CPublishCompactPackage�ǿ������ɶ�����İ������ڷ�����Ϣʱ���������
*  ��װ��һ���������������Ϸ���
*/
class CPublishCompactPackage : public CPackage
{
public:
	/**���캯��
	*@param nMaxLength ����������С�������˿������ɵİ����ۼƳ���
	*@remark ���캯���и��������������Ļ���������Ҫ�����������ҽӡ�
	*/
	CPublishCompactPackage(int nMaxLength);

	/**��������һ������������
	*@param pPackage Ҫ��ӵİ�
	*@return true ��ӳɹ���false ���ʧ�ܣ����ڵĿ��пռ䲻��
	*@remark
	*/
	bool AppendPackage(CPackage *pPackage);

	/**��հ��е�����
	*/
	void Reset();
private:
	char *m_pBufferEnd;			/**< ���л�����ָ�� */
};

/**CPublishPort����Ϣ���еķ����˿ڡ�һ��CPublishPort��������һ�鶩����
*  ������Ϣ��
*/
class CPublishPort  
{
public:
	/**���캯��
	*@param pSendProtocol ������Ϣʹ�õ�Э�����
	*@param pSendPackage ������Ϣʹ�õİ�
	*@param nSubjectID ������Ϣ������
	*/
	CPublishPort(CProtocol *pSendProtocol, CXTPPackage *pSendPackage, DWORD nSubjectID);

	/**��������
	*/
	virtual ~CPublishPort();

	/**�ҽ�һ������׼�������еİ����ͳ�ȥ
	*@param pFlow Ҫ��������
	*@param nStartId ��ǰҪ���͵���Ϣ�����
	*@return 0 �ҽӳɹ��� ���� �ҽ�ʧ��
	*/
	int AttachFlow(CReadOnlyFlow *pFlow, int nStartId);

	/**�ı䵱ǰ������Ϣ�����
	*@param nOffset ��Ϣ��ŵ�ƫ����
	*@param nSeekFlag ��ʼλ�ã�
	*       FROM_HEAD ����ͷ�����㣻FROM_HERE �ӵ�ǰλ�ü��㣻FROM_END ��β������
	*@remark �����ŷ����˻��ˣ��������ʻ��½�
	*/
	void MoveTo(int nOffset, CFlowReader::SeekFlag nSeekFlag = CFlowReader::FROM_HEAD);

	/**��ȡ��һ��Ҫ���͵İ�
	*@return NULL δȡ��Ҫ���͵İ���!=NULL ȡ����Ҫ���͵İ�
	*/
	CPackage *GetNextDataPackage();
	
	/**����һ����Ϣ
	*@param nClockLapse ʱ��Ƭ���ȣ�΢��
	*@return ʵ�ʷ��͵���Ϣ�ĸ���
	*@remark ����ʱ��Ƭ�ĳ��Ⱥͷ������ʣ��ӵ�ǰ��ſ�ʼ�������е���Ϣ���ͳ�ȥ
	*/
	int Publish(QWORD nClockLapse);

	/**�ӹ���һ�������˿�������Ķ�����
	*@param pPublishPort ���ӹܵķ����˿�
	*/
	void Merge(CPublishPort *pPublishPort);

	/**���һ���������Ƿ��ɱ�CPublishPort�����ṩ���ͷ���
	*@param dwSubscriberID ������ID
	*@return true �ṩ��false ���ṩ
	*/
	inline bool IsServeFor(DWORD dwSubscriberID);

	/**��ȡ��ǰ������Ϣ�����
	*@return ��ǰ������Ϣ�����
	*/
	inline int GetNextId();

	/**��ȡ�ṩ����Ķ����ߵĸ���
	*@return �����ߵĸ���
	*/
	inline int GetSubscirberCount();

	/**���Ӷ�һ�������ߵķ�������
	*@param dwSubscriberID ������ID
	*@param dwLastActiveTime �ṩ�������ʼʱ��
	*/
	inline void AddSubscriber(DWORD dwSubscriberID, DWORD dwLastActiveTime);

	/**ȡ����һ�������ߵķ�������
	*@param dwSubscriberID ������ID
	*@param dwLastActiveTime �ṩ�������ʼʱ��
	*/
	inline void DelSubscriber(DWORD dwSubscriberID);

	/**����һ�������ߵ�ACKʱ��
	*@param dwSubscriberID ������ID
	*@param dwLastActiveTime �յ�ACK��ʱ��
	*@return
	*@remark
	*/
	inline void UpdSubscriber(DWORD dwSubscriberID, DWORD dwLastActiveTime);

	/**����ʱ�Ķ����ߴӷ����б���ɾ��
	*@param dwCurrTime����ǰʱ��
	*@return true �ж����߳�ʱ��false û�ж����߳�ʱ
	*@remark ����ʱ��δ�յ�ĳ�������ߵ�ACKʱ�����ö����ߴӷ����б���ɾ��
	*/
	bool RemoveTimeoutSubscriber(DWORD dwCurrTime);

	/**�ı䷢������
	*@param nDeltaTransRate �������ʵı仯����>0���٣�<0����
	*/
	inline void ChangeTransRate(int nDeltaTransRate);

	/**��ȡ��ǰ��������
	*@return ��ǰ��������
	*/
	inline int GetTransRate();

private:
	/**�������ж������ϲ��İ����͵�������
	*@return true ���ͳɹ���false ����ʧ��
	*/
	bool Flush();

private:
	DWORD m_nSubjectID;							/**< ��������ID */
	CFlowReader m_flowReader;					/**< ��ȡҪ����������Reader */
	CXTPPackage *m_pSendPackage;				/**< ��ȡҪ���������İ� */
	
	CPublishCompactPackage *m_pCompactPackage;	/**< �ϲ����İ����������� */

	int m_nTransRate;							/**< ��������(byte/ms) */
	int m_nBandWidth;							/**< ���ʹ���(���ʡ�ʱ��Ƭ) */
	CProtocol *m_pSendProtocol;					/**< ������Ϣʹ�õ�Э����� */
	int m_nTransRateIncrease;					/**< ���������ٶ� */
	int m_nDesiredTransRate;					/**< ����������뷢������ */

	vector<TSubscirberInfo> m_SubscirberInfos;	/**< �ṩ����Ķ������б� */
	DWORD m_dwGroupID;							/**< PublishPort�ı�ʶ */
};

inline int CPublishPort::GetNextId()
{
	return m_flowReader.GetId();
}

inline bool CPublishPort::IsServeFor(DWORD dwSubscriberID)
{
	for (int i=0; i<m_SubscirberInfos.size(); i++)
	{
		if (m_SubscirberInfos[i].dwSubscriberID == dwSubscriberID)
		{
			return true;
		}
	}
	return false;
}

inline int CPublishPort::GetSubscirberCount()
{
	return m_SubscirberInfos.size();
}

inline void CPublishPort::AddSubscriber(DWORD dwSubscriberID, DWORD dwLastActiveTime)
{
	TSubscirberInfo SubscirberInfo;
	SubscirberInfo.dwSubscriberID = dwSubscriberID;
	SubscirberInfo.dwLastActiveTime = dwLastActiveTime;
	m_SubscirberInfos.push_back(SubscirberInfo);
}

inline void CPublishPort::UpdSubscriber(DWORD dwSubscriberID, DWORD dwLastActiveTime)
{
	vector<TSubscirberInfo>::iterator i= m_SubscirberInfos.begin();
	for (; i != m_SubscirberInfos.end(); i++)
	{
		if ((*i).dwSubscriberID == dwSubscriberID)
		{
			(*i).dwLastActiveTime = dwLastActiveTime;
			break;
		}
	}
}

inline void CPublishPort::DelSubscriber(DWORD dwSubscriberID)
{
	vector<TSubscirberInfo>::iterator i= m_SubscirberInfos.begin();
	for (; i != m_SubscirberInfos.end(); i++)
	{
		if ((*i).dwSubscriberID == dwSubscriberID)
		{
			m_SubscirberInfos.erase(i);
			break;
		}
	}
}

inline void CPublishPort::ChangeTransRate(int nDeltaTransRate)
{
	m_nTransRate += nDeltaTransRate;
}

inline int CPublishPort::GetTransRate()
{
	return m_nTransRate;
}

#endif // !defined(AFX_PUBLISHPORT_H__88F9C025_0AE8_4FBE_AAFD_56BAE65FECFD__INCLUDED_)
