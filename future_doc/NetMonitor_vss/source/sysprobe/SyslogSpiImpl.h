/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	SyslogSpiImpl.h
///@brief	��������־�ļ���ȡ��ص���
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#ifndef REF_SYSLOGSPIIMPL_H
#define REF_SYSLOGSPIIMPL_H

#include "public.h"
#include "CachedFileFlow.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#define READFILEINTERVAL	30	//�ļ�������ʱ���30���ٳ���ȥ���ļ�
	
	/////////////////////////////////////////////////////////////////////////
	///CSyslogValue�����˶��ڶ�ȡ�ļ���
	///@author	�ܽ���
	///@version	1.0,20080510
	/////////////////////////////////////////////////////////////////////////
class CSyslogValue
{
	/* */
	public:
		///̽�����ӵ�ַ��Ϣ
		string	m_mProbeLocation;

		///�����ļ�ID���ַ���
		string	m_mObjectID;

		///�����ļ����õ��ַ���,����·��
		string	m_mName;

		///�����ļ����õ��ַ���,���ļ���
		string	m_mFileName;

		///�����ļ����͵��ַ���
		string	m_mType;

		///�Ѵ��ļ���������
		FILE *m_mFd;

		///���ļ��򿪺��Ѿ���ȡ�����ݳ���
		off_t m_mHaveRead;

		///���ļ��򿪺��Ѿ���ȡ��ʱ���(������),syslog
		char m_mStrTime[20];

		///���ļ��򿪺����ʱ��
		int m_mIntTime;

		///���ļ�����޸�ʱ��
		time_t	m_mTime;

		///���ļ��򿪺��Ѿ���ȡ����������
		long m_mLines;

		///�ļ��Ƿ���ڱ�ǣ�Ϊtrue��ʾ���ڣ�false��ʾ�����ڴ��ļ�
		int m_mValid;

		///�ļ��Ƿ���Ҫ���������, Ϊtrue��ʾ��Ҫ��false��ʾ����Ҫ
		bool m_mRdFlag;

		///�����ļ���ȡλ�ñ��д��ָ��
		CReadWriteFile	*m_pPosFiler;

		///����FTD�Ự
		CFTDCSession *m_mSession;

		///�����ļ����õ��ַ���,����·��
		string	m_mPosName;

		///�������Ӵ�
		string	m_mConn;

	/* */
	public:

		///�޲����Ĺ��췽��
		CSyslogValue(void)
		{
			m_mSession = NULL;
			m_mConn = "";
			m_pPosFiler = NULL;
			m_mObjectID = "";
			m_mName = "";
			m_mType = "";
			m_mFileName = "";
			m_mFd = NULL;
			m_mHaveRead = 0;
			m_mIntTime = 0;
			memset(m_mStrTime, 0, 20);
			m_mLines = 0;
			m_mValid = 0;
			m_mValid = READFILEINTERVAL;
			m_mRdFlag = false;
			m_mPosName = "";
			m_mProbeLocation = "";
			m_mTime = 0;
			getFileName();
		}

		///���췽��
			///@param	pname	��ȡ���ļ���(��·��)
			///@param	pType	�ļ�������(syslog,applog,keyfile,slog,dfmt�ļ�)
			///@param	pFileName	�ļ���Syslog.log, ������dfmt.dfmtLen��dfmt�ļ��ž߱�����������������Ϊ����·�����ļ�����
			///@param	pObjectID	����ID,��PuDian.os.AC-01.applog
			///@param	pConn	�ɼ��������Ӵ���Ϣ
			///@param	pHaveRead	�ɼ������Ѿ���ȡ�����ļ�����
			///@param	pReadTime	�ɼ������Ѿ���ȡ�����ļ�ʱ��
			///@param	pProbeLoation	̽��ĵ�ַ��Ϣ
		CSyslogValue(
		const char	*pName,
		char *pType,
		char *pFileName,
		char *pObjectID,
		char *pConn,
		char *pHaveRead,
		char *pReadTime,
		const char	*pProbeLocation)
		{
			m_mSession = NULL;
			m_mConn = pConn;
			m_pPosFiler = NULL;
			m_mObjectID = pObjectID;
			m_mName = pName;
			m_mType = pType;
			m_mFileName = pFileName;
			m_mFd = NULL;
			m_mHaveRead = atol(pHaveRead);
			m_mIntTime = atol(pReadTime);
			memset(m_mStrTime, 0, 20);
			m_mLines = 0;
			m_mValid = READFILEINTERVAL;
			m_mRdFlag = false;
			m_mProbeLocation = pProbeLocation;
			m_mTime = 0;
			getFileName();
		}

		///�������캯����ע�⣺ֻ�����ļ�������Ч��ǡ��Ѷ��ļ����ȣ���дָ����ļ����������·���
			///@param	ob	�����������
		CSyslogValue(const CSyslogValue &ob)
		{
			m_mSession = ob.m_mSession;
			m_pPosFiler = NULL;
			m_mObjectID = ob.m_mObjectID;
			m_mName = ob.m_mName;
			m_mType = ob.m_mType;
			m_mFileName = ob.m_mFileName;
			m_mFd = NULL;
			m_mHaveRead = ob.m_mHaveRead;
			m_mIntTime = ob.m_mIntTime;
			strcpy(m_mStrTime, ob.m_mStrTime);
			m_mLines = ob.m_mLines;
			m_mValid = ob.m_mValid;
			m_mRdFlag = ob.m_mRdFlag;
			m_mConn = ob.m_mConn;
			m_mProbeLocation = ob.m_mProbeLocation;
			m_mTime = ob.m_mTime;
			getFileName();
		}

		///�����������ر��ļ����������ͷ��ļ���д���ָ��ռ�
		~CSyslogValue(void)
		{
			if (m_mFd != NULL)
			{
				SAFE_FCLOSE(m_mFd);
			}

			if (m_pPosFiler != NULL)
			{
				delete m_pPosFiler;
			}
		}

		///���ظ�ֵ�����������ע�⣺ֻ��ֵ�ļ�������Ч��ǡ��Ѷ��ļ����ȣ���дָ����ļ����������·���
			///@param	ob	��ֵ����
		void operator=(const CSyslogValue &ob)
		{
			m_mSession = ob.m_mSession;
			m_pPosFiler = NULL;
			m_mObjectID = ob.m_mObjectID;
			m_mName = ob.m_mName;
			m_mType = ob.m_mType;
			m_mFileName = ob.m_mFileName;
			m_mFd = NULL;
			m_mHaveRead = ob.m_mHaveRead;
			m_mIntTime = ob.m_mIntTime;
			strcpy(m_mStrTime, ob.m_mStrTime);
			m_mLines = ob.m_mLines;
			m_mValid = ob.m_mValid;
			m_mRdFlag = ob.m_mRdFlag;
			m_mConn = ob.m_mConn;
			m_mProbeLocation = ob.m_mProbeLocation;
			m_mTime = ob.m_mTime;
			getFileName();
		}

		///��ʼ����дָ��
			///@return	true��ʾ��ʼ���ɹ���false��ʾ��ʼ��ʧ��
		bool InitFilelog(void);
		bool InitBinFilelog(void);
		void getFileName(void);

	/* */
	protected:
	/* */
	private:
};

class CConStringKey
{
	/* */
	public:
		///��ȡ�ļ��ľ���·����
		string	m_mPath;

		///FTD�Ự
		CFTDCSession *m_mSession;

	/* */
	public:

		///���캯��
			///@param	objectNum	ҵ�����ı��
			///@param	itemNum	ҵ�����Եı��
			///@param	pSession	FTD�Ự
		CConStringKey(string mPath, CFTDCSession *mSession)
		{
			m_mSession = mSession;
			m_mPath = mPath;
		}

		CConStringKey(const CConStringKey &ob)
		{
			m_mPath = ob.m_mPath;
			m_mSession = ob.m_mSession;
		}

		void operator=(const CConStringKey &ob)
		{
			m_mPath = ob.m_mPath;
			m_mSession = ob.m_mSession;
		}

		///����>�����
		friend bool operator>(
		const CConStringKey &ob1,
		const CConStringKey &ob2)
		{
			if (ob1.m_mPath > ob2.m_mPath)
			{
				return true;
			}
			else if (ob1.m_mPath == ob2.m_mPath)
			{
				if (ob1.m_mSession > ob2.m_mSession)
				{
					return true;
				}
			}

			return false;
		}

		///����<�����
		friend bool operator < (const CConStringKey &ob1, const CConStringKey &ob2)
		{
			if (ob1.m_mPath < ob2.m_mPath)
			{
				return true;
			}
			else if (ob1.m_mPath == ob2.m_mPath)
			{
				if (ob1.m_mSession < ob2.m_mSession)
				{
					return true;
				}
			}

			return false;
		}

		///����==�����
		friend bool operator==(
		const CConStringKey &ob1,
		const CConStringKey &ob2)
		{
			if ((ob1.m_mPath == ob2.m_mPath)
			&&	(ob1.m_mSession == ob2.m_mSession))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

typedef map<CConStringKey, CSyslogValue> MapConSyslog;

class CManageConSession
{
	/* */
	public:
		CManageConSession(void)
		{
			m_mResult = "";
		}

		///���Ӳɼ��������ӷ���
			///@param	pProbeLocation	̽���ַ��Ϣ
			///@param	pSession	FTD�Ự
		void addProbeLocation(const char *pProbeLoation, CFTDCSession *pSession)
		{
			m_mProbeMap[pSession] = string(pProbeLoation);
			m_mStatusMap[pSession] = 0;
		}

		///ȡ�Ự״̬����
			///@param	pSession	FTD�Ự	
			///@return	���ػỰ��״̬
		int getStatus(CFTDCSession *pSession)
		{
			return m_mStatusMap[pSession];
		}

		///���ûỰ״̬����
			///@param	pSession	FTD�Ự
			///@param	status	״̬
		void setStatus(CFTDCSession *pSession, int status)
		{
			m_mStatusMap[pSession] = status;
		}

		///ɾ���Ͽ��Ĳɼ���������
			///@param	pSession	FTD�Ự
		void delSession(CFTDCSession *pSession)
		{
			m_mProbeMap.erase(pSession);
			m_mStatusMap.erase(pSession);
		}

		///ɾ���ļ��ɼ�������
			///@param	pSession	FTD�Ự
			///@param	mConSyslog	�ļ��ɼ�����map
		void delSyslog(CFTDCSession *pSession, MapConSyslog &mConSyslog)
		{
			for (MapConSyslog::iterator iter = mConSyslog.begin();
				 iter != mConSyslog.end();)
			{
				if (iter->first.m_mSession == pSession)
				{
					mConSyslog.erase(iter++);
				}
				else
				{
					++iter;
				}
			}
		}

		///ȡ̽�����ӵ�ַ����
			///@param	pSession	FTD�Ự
			///@return	���ص�ַ��ָ��
		const char *getProbeLocation(CFTDCSession *pSession)
		{
			map<CFTDCSession *, string>::iterator it = m_mProbeMap.find(
					pSession);
			if (it == m_mProbeMap.end())
			{
				return NULL;
			}
			else
			{
				return it->second.c_str();
			}
		}

		///����FTD���ݰ������е�����
			///@param	pPackage	���ݰ���ַ
		void sendFTDCPackage(CFTDCPackage *pPackage)
		{
			map<CFTDCSession *, int>::iterator	it;
			for (it = m_mStatusMap.begin(); it != m_mStatusMap.end(); it++)
			{
				if (it->second > 0)
				{
					it->first->SendRequestPackage(pPackage);
					pPackage->Pop(FTDCHLEN);
				}
			}
		}

		///����FTD���ݰ������е�����
			///@param	pPackage	���ݰ���ַ
			///@param	pSession	���ݰ����͵�session�Ự
		void sendFTDCPackage(CFTDCPackage *pPackage, CFTDCSession *pSession)
		{
			map<CFTDCSession *, int>::iterator	it = m_mStatusMap.find(
					pSession);
			if (it != m_mStatusMap.end())
			{
				if (it->second > 0)
				{
					pSession->SendRequestPackage(pPackage);
				}
			}
		}

		bool isValidFtdcSession(void)
		{
			bool bFlag = false;
			map<CFTDCSession *, int>::iterator	it;
			for (it = m_mStatusMap.begin(); it != m_mStatusMap.end(); it++)
			{
				if (it->second > 0)
				{
					bFlag = true;
				}
				else
				{
					bFlag = bFlag || false;
				}
			}

			return bFlag;
		}

	/* */
	protected:
	/* */
	private:
		string	m_mResult;

		// key:�ɼ������͹�����Ψһ���Ӵ� value:���͹����ĻỰ
		map<string, CFTDCSession *> m_mConMap;

		// key:���͹����ĻỰ value:̽��Ĳɼ���ַ��Ϣ
		map<CFTDCSession *, string> m_mProbeMap;

		// key:���͹����ĻỰ value:�ûỰ���ɼ����������״̬
		map<CFTDCSession *, int> m_mStatusMap;

		map<string, CFTDCSession *>::iterator m_mIt;
};

/////////////////////////////////////////////////////////////////////////
///CSyslogSpiImpl�����˶��ڶ�ȡ�ļ��ⲿ�ӿ���
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CSyslogSpiImpl
{
	/* */
	public:
		///���캯��
			///@param	pFlow	�ڴ��ļ���ָ��
		CSyslogSpiImpl(CCachedFileFlow *pFlow, MapConSyslog *pFileNameMap);

		///��������
		~ CSyslogSpiImpl(void);

		///��ӡ����,��ӡ��ǰ���ж�ȡ�ļ����Ѷ�ȡ����
		void PrintSyslogMap(void);

		///��ȡ�ļ�Spi�ӿ�,�ⲿѭ������,ÿ����һ�ξͶ�ȡһ���ļ�����,���ж�ȡ,��ȡ���ļ����ݷ����ڴ��ļ�����
			///@return	true��ʾ�ɹ�,false��ʾʧ��
		bool GetSpi(void);

		///��ȡ�ļ�Spi�ӿ�,�ⲿѭ������,ÿ����һ�ξͶ�ȡһ���ļ�����,��ȡ���ļ����ݷ����ڴ��ļ�����
			///@return	true��ʾ�ɹ�,false��ʾʧ��
		bool GetTotalSpi(void);

		///��ȡ�ļ���СSpi�ӿ�,�ⲿѭ������,ÿ����һ�ξͶ�ȡһ���ļ�����,���ж�ȡ,��ȡ���ļ����ݷ����ڴ��ļ�����
			///@return	true��ʾ�ɹ�,false��ʾʧ��
		bool GetSizeSpi(void);

		///��ȡ�ļ�Spi�ӿ�,�ⲿѭ������,ÿ����һ�ξͶ�ȡһ���ļ�����,��ȡ���ļ����ݷ����ڴ��ļ�����
			///@return	true��ʾ�ɹ�,false��ʾʧ��
		bool GetBinSpi(void);

		///��ȡ�ļ�Spi�ӿ�,�ⲿѭ������,ÿ����һ�ξͶ�ȡһ���ļ�����,���ж�ȡ,��ȡ���ļ����ݷ����ڴ��ļ�����
			///@return	true��ʾ�ɹ�,false��ʾʧ��
		bool DispatchIOsSpi(void);

		///��ȡ�ļ�Spi�ӿ�,�ⲿѭ������,ÿ����һ�ξͶ�ȡһ���ļ�����,���ж�ȡ,��ȡ���ļ����ݷ����ڴ��ļ�����
			///@return	true��ʾ�ɹ�,false��ʾʧ��
		bool DispatchIOsBinSpi(void);

		///�����ļ�����,���ϴζ�ȡ��λ�ÿ�ʼ,���ж�ȡ,����ָ���ļ����ļ�β
			///@param	filename	��ȡ���ļ���
			///@param	loginfo	ʹ�õ��ļ���ȡ������
			///@return	�޷���ֵ
		void KeepReadFile(string &filename, CSyslogValue &loginfo);

		///�����ļ���С����,���ϴζ�ȡ��λ�ÿ�ʼ,���ж�ȡ,����ָ���ļ����ļ�β
			///@param	filename	��ȡ���ļ���
			///@param	loginfo	ʹ�õ��ļ���ȡ������
			///@return	�޷���ֵ
		void KeepReadFileSize(string &filename, CSyslogValue &loginfo);

		///�����ļ�����,���ϴζ�ȡ��λ�ÿ�ʼ,����ָ���ļ����ļ�β
			///@param	filename	��ȡ���ļ���
			///@param	loginfo	ʹ�õ��ļ���ȡ������
			///@return	�޷���ֵ
		void KeepReadBinFile(string &filename, CSyslogValue &loginfo);

		///���ļ�����,��������λ��ȡλ��
			///@param	filename	��ȡ���ļ���
			///@param	loginfo	ʹ�õ��ļ���ȡ������
			///@return	false ��ʾ����ʧ�ܣ�true��ʾ�ɹ�
		void KeepReadTotalFile(string &filename, CSyslogValue &loginfo);

		///���ļ�����,��������λ��ȡλ��
			///@param	filename	��ȡ���ļ���
			///@param	loginfo	ʹ�õ��ļ���ȡ������
			///@return	false ��ʾ����ʧ�ܣ�true��ʾ�ɹ�
		bool OpenReadFile(string &filename, CSyslogValue &loginfo);

	/* */
	private:
		///���浱ǰ������,�Ա��ظ�ʹ��
		char m_mDate[MAXTIMELEN];

		///��ǰ�Ĳɼ��¼�,��ʽΪHH:MM:SS
		char m_mTime[MAXTIMELEN];

		///�ɼ������ID
		char m_mObjectId[MAXOBJECTNAMELEN];

		///�ɼ����������
		char m_mObjectName[MAXOBJECTNAMELEN];

		///��ȡ�ļ������õĻ�����,ÿ�ζ�д��󳤶�ΪMAXONECONTENTLEN-1
		char m_mReadBuff[MAXONECONTENTLEN];

		///ÿ�ζ�ȡ�ļ����ݵĳ���
		int m_mBuffSize;

		///�����ļ������õ�FTD���ݰ�
		CFTDCPackage m_pkgSend;

		///���͵���־�ļ�������
		CFTDRtnSyslogInfoField	m_mLogField;

		CFTDSysFileAccessInfoField	m_mAccessField;

		///�ڴ��ļ����ĵ�ַ
		CCachedFileFlow *m_pFlow;

		///��ȡ�ļ��б�ָ��
		MapConSyslog *m_pFileNameMap;
};
#endif // REF_SYSLOGSPIIMPL_H
