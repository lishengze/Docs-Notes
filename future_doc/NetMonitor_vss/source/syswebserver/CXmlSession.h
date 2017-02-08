/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CXmlSession.h
///@brief	定义了XML协议类
///@history 
///20080810	周建军		创建该文件

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

/**是一个存放协议栈的容器，是基于IO处理的EventHandler类，一般是由ListenCtrl
*创建，它必须注册到一个Reactor。容器的底部捆绑在一个TcpChannel上，容器内的
*协议只有通过容器的才能得到读写操作 */
class CXmlSession : public CProtocolCallback, public CSession
{
public:
	/**构造函数，完成协议栈的构造
	* @param pReactor   运行引擎
	* @param pChannel   一个TcpChannel
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
	
	/**析构函数，释放可控资源
	*/
	virtual ~CXmlSession()
	{
		delete m_pXmlProtocol;
	}
	
	/**处理一条消息
	* @param nEventID 消息ID
	* @param dwParam 第一个参数
	* @param pParam 第二个参数
	* @return 处理结果
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

	/**获取读、写socket，供select使用
	* @param pReadId   输出参数，返回读所使用的socket，为0表示不需要读
	* @param pWriteId  输出参数，返回写所使用的socket，为0表示不需要写
	* @remark 在这里将发布的主题的数据包传递到最下层协议
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

	/**设置本会话的版本
	*@param	version	版本号
	*/
	void SetVersion(BYTE version)
	{
		m_version = version;
	}
	
	/**获取本会话的版本
	*@return	本会话的版本
	*/
	BYTE GetVersion(void)
	{
		return m_version;
	}
	
protected:
	CXmlProtocol *m_pXmlProtocol;		/**< FTDC协议对象*/
	CXmlSessionCallback *m_pPackageHandler;
	///-----
	///	王肇东，20060223：增加了对FTD协议的版本设置
	///-----
	BYTE m_version;
};

#endif

