/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CXmlSession.h
///@brief	������XMLЭ����
///@history 
///20080810	�ܽ���		�������ļ�

#ifndef REF_CXMLSESSION_H
#define REF_CXMLSESSION_H

#include "EventHandler.h"
#include "CXmlProtocol.h"
#include "CXmlPackage.h"

#include "XMPSession.h"
#include "XMPProtocol.h"

class CXmlSession;
class CXmlSessionCallback
{
public:
	virtual int HandlePackage(CXmlPackage *pXmlPackage, CXmlSession *pSession) = 0;
};

/**��һ�����Э��ջ���������ǻ���IO�����EventHandler�࣬һ������ListenCtrl
*������������ע�ᵽһ��Reactor�������ĵײ�������һ��TcpChannel�ϣ������ڵ�
*Э��ֻ��ͨ�������Ĳ��ܵõ���д���� */
class CXmlSession : public CProtocolCallback, public CSession
{
public:
	/**���캯�������Э��ջ�Ĺ���
	* @param pReactor   ��������
	* @param pChannel   һ��TcpChannel
	*/ 	
	CXmlSession(CReactor *pReactor,CChannel *pChannel)
		:CSession(pReactor, pChannel,10000)
	{
		m_pXmlProtocol = new CXmlProtocol(m_pReactor);
		m_pXmlProtocol->AttachLower(m_pChannelProtocol, 0);
		m_pXmlProtocol->RegisterErrorHandler(this);
		m_pXmlProtocol->RegisterUpperHandler(this);
		m_pPackageHandler = NULL;
	}
	
	/**�����������ͷſɿ���Դ
	*/
	virtual ~CXmlSession()
	{
		delete m_pXmlProtocol;
	}
	
	/**����һ����Ϣ
	* @param nEventID ��ϢID
	* @param dwParam ��һ������
	* @param pParam �ڶ�������
	* @return ������
	*/
	virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam)
	{
		return CSession::HandleEvent(nEventID,dwParam,pParam);
	}

	virtual int HandlePackage(CPackage *pPackage,CProtocol *pProtocol)
	{
		if (pProtocol == m_pXmlProtocol)
		{
			CXmlPackage *pXmlPacakge = (CXmlPackage *)pPackage;
			if (m_pPackageHandler == NULL)
			{
				printf("CXmlSession::HandlePackage handler wrong\n");
				return 0;
			}
			return m_pPackageHandler->HandlePackage(pXmlPacakge, this);
		}
		printf("CXmlSession::HandlePackage protocol wrong\n");
		return 0;
	}

	/**��ȡ����дsocket����selectʹ��
	* @param pReadId   ������������ض���ʹ�õ�socket��Ϊ0��ʾ����Ҫ��
	* @param pWriteId  �������������д��ʹ�õ�socket��Ϊ0��ʾ����Ҫд
	* @remark �����ｫ��������������ݰ����ݵ����²�Э��
	*/
	virtual void GetIds(int *pReadId, int *pWriteId)
	{
		CSession::GetIds(pReadId, pWriteId);
	}
	
	void RegisterPackageHandler(CXmlSessionCallback *pPackageHandler)
	{
		m_pPackageHandler = pPackageHandler;
	}
	
	CXmlPackage *CreatePackage()
	{
		CXmlPackage *pPackage = new CXmlPackage;
		pPackage->ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 64);
		return pPackage;
	}
	
	void SendRequestPackage(CXmlPackage *pPackage)
	{
		m_pXmlProtocol->Send(pPackage);
	}
	
	virtual void Disconnect(int nErrorCode)
	{
		CSession::Disconnect(nErrorCode);
	}

	/**���ñ��Ự�İ汾
	*@param	version	�汾��
	*/
	void SetVersion(BYTE version)
	{
		m_version = version;
	}
	
	/**��ȡ���Ự�İ汾
	*@return	���Ự�İ汾
	*/
	BYTE GetVersion(void)
	{
		return m_version;
	}
	
protected:
	CXmlProtocol *m_pXmlProtocol;		/**< FTDCЭ�����*/
	CXmlSessionCallback *m_pPackageHandler;
	///-----
	///	���ض���20060223�������˶�FTDЭ��İ汾����
	///-----
	BYTE m_version;
};

#endif

