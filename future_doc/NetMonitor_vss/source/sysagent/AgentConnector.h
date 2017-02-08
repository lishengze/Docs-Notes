/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	AgentConnector.h
///@brief	�����˲ɼ���������̽�벢����̽����Ϣ����
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#ifndef REF_AGENTCONNECTOR_H
#define REF_AGENTCONNECTOR_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "CEventProcess.h"
#include "CSysInternalTopology.h"
#include <map>
#include <string>
#define MAXPROBECONFIGNUM	50


using namespace std;

/////////////////////////////////////////////////////////////////////////
///CHostConfig��������������������������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CHostConfig
{
	/* */
	public:
		///���������������
		string	m_mDataCenter;

		///���������������Ҫ��������־�ļ���
		map<string, bool> m_mMapLogType;

	/* */
	public:

		///���캯��
		CHostConfig(void)
		{
			m_mDataCenter = "";
		}

		///���캯��
			///@param	mDataCenter	����������
		CHostConfig(const string &mDataCenter)
		{
			m_mDataCenter = mDataCenter;
		}

		///���캯��
			///@param	mDataCenter	����������
		CHostConfig(const char *mDataCenter)
		{
			m_mDataCenter = mDataCenter;
		}

		///�������캯��
			///@param	ob	�������Ķ�����
		CHostConfig(const CHostConfig &ob)
		{
			m_mDataCenter = ob.m_mDataCenter;
		}

		///��������
		~CHostConfig(void)
		{
		}

		///���ظ�ֵ�����
			///@param	ob	�������Ķ�����
		void operator=(const CHostConfig &ob)
		{
			m_mDataCenter = ob.m_mDataCenter;
		}
};

/////////////////////////////////////////////////////////////////////////
///CAgentSessionFactory�����˲ɼ�����̽��Ự������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CAgentSessionFactory :
	public CSessionFactory
{
	/* */
	public:

		///���캯��
		CAgentSessionFactory(CReactor *pReactor, int nMaxSession) :
		CSessionFactory(pReactor, nMaxSession)
		{
		}

		///ע�����Ӻ���
			///@param	location	���ӵĵ�ַ
		void RegisterConnecter(char *location)
		{
			CSessionFactory::RegisterConnecter(location);
			memset(m_location, 0, MAXLOCATIONLEN);
			strcpy(m_location, location);
		}

		///ȡ���ӵ�ַ����
			///@return	�������ӵ�ַ��ָ��
		char *GetLocationName(void)
		{
			return m_location;
		}

	/* */
	private:
		///����ע������ӵ�ַ
		char m_location[MAXLOCATIONLEN];
};

/////////////////////////////////////////////////////////////////////////
///CAgentConnector�����˲ɼ������̽�����Ӵ�����
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CAgentConnector :
	public CAgentSessionFactory,
	public CFTDCSessionCallback,
	public CFTDCSubscriber
{
	/* */
	public:
		///���캯��
			///@param	pReactor	CReactor����ָ��
			///@param	pSaveFile	��������λ�õ��ļ���
			///@param	location	���ӵĵ�ַ
			///@param	bProbeFlag	���ӵ�����,true:probe,false:agent
			///@param	pLinkName	���ӵı���,ZJ-Agent06
			///@param	pLinkLocation	���ӵ�IP��ַ,tcp://172.18.38.61:18806
			///@param	pEventProcess	�¼�������ָ�룬�ö�����Ԥ�ȹ���
		CAgentConnector(
			CReactor *pReactor,
			bool bProbeFlag,
			int mConnectId,
			char *pLinkName,
			char *pLinkLocation,
			CEventProcess *pEventProcess);

		///�������Ӵ�����
			///@param	pChannel	����ͨ����ָ��
			///@param	bIsListener	�Ƿ�Ϊ�����ߵ�����
			///@return	���ؽ����ĻỰID
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///�Ự����ʱ�Ĵ�����
			///@param	pSession	���ӻỰָ��
		virtual void OnSessionConnected(CSession *pSession);

		/**�Ự���ӶϿ�ʱ�Ĵ�����
	* @param	pSession	�Ͽ������ӻỰָ��
	* @param	nReasion	�Ͽ���ԭ��
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

		///����ͨѶ�׶κź���
			///@param	wCommPhaseNo	��Ҫ���õ�ͨ�Ž׶κ�
		virtual void SetCommPhaseNo(WORD wCommPhaseNo);

		///��ȡ�����кź���
			///@return	�������ĵ�ǰ���к�
		virtual WORD GetSequenceSeries(void);

		///��ȡ���а����İ���������
			///@return	���ص�ǰ�����յ��İ�����
		virtual DWORD GetReceivedCount(void);	//�յ��İ�����
		
			///�����յ��İ�������,�Ƿ���/����ģ���յ������ݰ�
			///@param	pMessage	�������յ��İ���ַ
		virtual void HandleMessage(CFTDCPackage *pMessage);

		///ȡ̽�����ӱ�־
		bool GetProbeFlag(void)
		{
			return m_bProbeFlag;
		}

		///�жϸ���־�¼����ݶ����Ƿ�������մ���
		bool ValidEvent(const char *pEventObject)
		{
			if (pEventObject != NULL && strlen(pEventObject) > 20)
			{
				if (m_EventCount.find(pEventObject) != m_EventCount.end())
				{
					/// ����Ϊ10������
					return m_EventCount[pEventObject]++ < 10;
				}
				else
				{
					m_EventCount[pEventObject] = 1;
				}
				return true;
			}
			return false;
		}
	/* */
	private:
		///FTD����Ӧ���յ��İ�������,������Ӧ��ģ���лỰ�����յ������ݰ�
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pSession	���ݰ������ĻỰID
			///@return	���ش���Ľ��
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///̽���������ô�����
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pSession	���ݰ������ĻỰID
		void OnReqQryHostConfig(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�û���¼Ӧ������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pSession	���ݰ������ĻỰID
		void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///�û��˳���������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pSession	���ݰ������ĻỰID
		void OnReqUserLogout(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///ϵͳ��־������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pSession	���ݰ������ĻỰID
		void OnRtnSyslogInfoTopic(CFTDCPackage *pFTDCPackage);

		///Ӧ����־������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pDataCenter	���ݰ���������������
		void OnRtnSyslogInfoApplog(
				CFTDCPackage *pFTDCPackage,
				char *pDataCenter);

		///������־������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pDataCenter	���ݰ���������������
		void OnRtnSyslogInfoSyslog(
				CFTDCPackage *pFTDCPackage,
				char *pDataCenter);

		///�ؼ��ļ���־������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pDataCenter	���ݰ���������������
		void OnRtnSyslogInfoKeyfile(
				CFTDCPackage *pFTDCPackage,
				char *pDataCenter);

		///��������־������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pDataCenter	���ݰ���������������
		void OnRtnSyslogInfoSlog(CFTDCPackage *pFTDCPackage, char *pDataCenter);

		///���������������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
		void OnRtnUpdateSysConfig(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		/**�����û���¼������
	* @param	pFTDCPackage	��Ҫ�����FTDC���ݰ���ַ
	* @param	pSession	���ݰ�������FTD�Ựָ��
	*/
		void OnReqUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///����̽�뷢�ͳ����ĸ澯������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnWarningEventTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

	/* */
	public:
		///�����ӵı������� "ZJ-Agent06"
		string	m_sLinkName;

		///�����ӵ����Ӵ����� "tcp://172.18.38.61:18806"
		string	m_sLinkLocation;

	/* */
	private:
		//����̽���� true:probe,false:agent
		bool m_bProbeFlag;

		///����ConnectID
		int m_mConnectId;

		///�������յ������ݰ�����
		long m_mPacketRecvNum;

		///���ݰ�����ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///����ʹ�õ���־��Ϣ��
		CFTDRtnSyslogInfoField	m_mSyslogInfo;

		///������ʹ�õ���־���ݻ�����
		char m_mContentBuf[MAXONECONTENTLEN];

		///���¼�����ʹ�ö���ָ��
		CEventProcess *m_pEventProcess;

		///���ڻ�����־�¼���Ŀ��������Ϣ
		map <string, int> m_EventCount;
};

class CFileDescript
{
	/* */
	public:
		///�汾��
		string	m_location;

		///ǰ�õ�ID
		string	m_appname;

	/* */
	public:

		///���캯��
		CFileDescript(void)
		{
			m_location = "";
			m_appname = "";
		}

		///���캯��
			///@param	location	��ַ��Ϣ
			///@param	appname Ӧ����
		CFileDescript(string location, string appname)
		{
			m_location = location;
			m_appname = appname;
		}

		///�������캯��
		CFileDescript(const CFileDescript &ob)
		{
			m_location = ob.m_location;
			m_appname = ob.m_appname;
		}

		///����=�����
		void operator=(const CFileDescript &ob)
		{
			m_location = ob.m_location;
			m_appname = ob.m_appname;
		}

		///����>�����
		bool operator>(const CFileDescript &ob2) const
		{
			if (this->m_location > ob2.m_location)
			{
				return true;
			}
			else if (this->m_location == ob2.m_location)
			{
				if (this->m_appname > ob2.m_appname)
				{
					return true;
				}
			}

			return false;
		}

		///����<�����
		bool operator < (const CFileDescript &ob2)const
		{
			if (this->m_location < ob2.m_location)
			{
				return true;
			}
			else if (this->m_location == ob2.m_location)
			{
				if (this->m_appname < ob2.m_appname)
				{
					return true;
				}
			}

			return false;
		}

		///����==�����
		friend bool operator==(
		const CFileDescript &ob1,
		const CFileDescript &ob2)
		{
			if ((ob1.m_location == ob2.m_location)
			&&	(ob1.m_appname == ob2.m_appname))
			{
				return true;
			}

			return false;
		}
};

class CFileInfo
{
	/* */
	public:
		///ƫ����
		string	m_pos;

		///����ȡʱ��
		string	m_time;

	/* */
	public:

		///���캯��
		CFileInfo(void)
		{
			m_pos = "";
			m_time = "";
		}

		///���캯��
			///@param	location	ƫ����
			///@param	stime ʱ��
		CFileInfo(string pos, string stime)
		{
			m_pos = pos;
			m_time = stime;
		}

		///�������캯��
		CFileInfo(const CFileInfo &ob)
		{
			m_pos = ob.m_pos;
			m_time = ob.m_time;
		}

		///����=�����
		void operator=(const CFileInfo &ob)
		{
			m_pos = ob.m_pos;
			m_time = ob.m_time;
		}

		///����>�����
		bool operator>(const CFileInfo &ob2) const
		{
			if (this->m_pos > ob2.m_pos)
			{
				return true;
			}
			else if (this->m_pos == ob2.m_pos)
			{
				if (this->m_time > ob2.m_time)
				{
					return true;
				}
			}

			return false;
		}

		///����<�����
		bool operator < (const CFileInfo &ob2)const
		{
			if (this->m_pos < ob2.m_pos)
			{
				return true;
			}
			else if (this->m_pos == ob2.m_pos)
			{
				if (this->m_time < ob2.m_time)
				{
					return true;
				}
			}

			return false;
		}

		///����==�����
		friend bool operator==(const CFileInfo &ob1, const CFileInfo &ob2)
		{
			if ((ob1.m_pos == ob2.m_pos) && (ob1.m_time == ob2.m_time))
			{
				return true;
			}

			return false;
		}
};
#endif // REF_AGENTCONNECTOR_H END
