#pragma once
#include "public.h"
#include "Thread.h"
#include "DatabaseSpiImpl.h"
#include "SyslogSpiImpl.h"

///����URL����
///@param	pUrl	URL��ַ,��http://www.shfe.com.cn:80/testweblogic.jsp
///@param	sDomainName	�����������������:www.shfe.com.cn
///@param	nPort	������������������˿ں�:80
///@param	sHtmlUrl	�������������url:testweblogic.jsp
bool explainUrl(
		const char	*pUrl,
		string	&sDomainName,
		int &nPort,
		string	&sHtmlUrl);

#ifdef LINUX
#include <ftw.h>
class CFileCheckValue
{
	/* */
	public:
		~CFileCheckValue(void)
		{
		}

		CFileCheckValue(void)
		{
			st_size = 0;
			st_time = 0;
			mResult = 0;
			md5file = "";
		}

		CFileCheckValue(off_t size, time_t mtime, const char *file)
		{
			st_size = size;
			st_time = mtime;
			md5file = file;
			mResult = 0;
		}

		CFileCheckValue(const CFileCheckValue &ob)
		{
			st_size = ob.st_size;
			st_time = ob.st_time;
			md5file = ob.md5file;
			mResult = ob.mResult;
		}

		void operator=(const CFileCheckValue &ob)
		{
			st_size = ob.st_size;
			st_time = ob.st_time;
			md5file = ob.md5file;
			mResult = ob.mResult;
		}

	/* */
	public:
		off_t st_size;
		time_t	st_time;
		int mResult;
		string	md5file;
};
#endif
class CHtmlTestValue
{
	/* */
	public:
		CHtmlTestValue(void)
		{
			m_sDomain = "";
			m_nPort = 80;
			m_sHtmlUrl = "";
			m_sHtmlValue = "";
		}

		///���캯��
			///@param	nPort	�˿ں�
			///@param	sHtmlUrl	������ҳ��Url
			///@param	pHtmlValue	������ҳ��ֵ
		CHtmlTestValue(
		string	&sDomain,
		int nPort,
		string	&sHtmlUrl,
		const char	*pHtmlValue)
		{
			m_sDomain = sDomain;
			m_nPort = nPort;
			m_sHtmlUrl = sHtmlUrl;
			m_sHtmlValue = pHtmlValue;
		}

		CHtmlTestValue(const CHtmlTestValue &ob)
		{
			m_sDomain = ob.m_sDomain;
			m_nPort = ob.m_nPort;
			m_sHtmlUrl = ob.m_sHtmlUrl;
			m_sHtmlValue = ob.m_sHtmlValue;
		}

		void operator=(const CHtmlTestValue &ob)
		{
			m_sDomain = ob.m_sDomain;
			m_nPort = ob.m_nPort;
			m_sHtmlUrl = ob.m_sHtmlUrl;
			m_sHtmlValue = ob.m_sHtmlValue;
		}

		~CHtmlTestValue(void)
		{
		}

	/* */
	public:
		///web������������ҳ������ַ
		string	m_sDomain;

		///web�������˿ں�
		int m_nPort;

		///web�������Ĳ���Url
		string	m_sHtmlUrl;

		///web������������ҳ��ֵ
		string	m_sHtmlValue;
};

class CFileCheckThread :
	public CThread
{
	/* */
	public:
		CFileCheckThread(void);
		~ CFileCheckThread(void);

		/**�麯�����������һЩʵ��������
	* @return true:�����ɹ� false:����ʧ��
	*/
		virtual bool InitInstance(void);

		/**�麯�����������ʵ��
	*/
		virtual void ExitInstance(void);

		/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
		virtual void Run(void);

	/* */
	public:
		// ��������������߳����ɵ����ݷ��ͳ�ȥ
		void GetSpi(void);

		///���ڸ���У���������
			///@param	pCheckPath	����У���Դ�ļ�·��
			///@param	pMD5Path	����У���md5�����ļ�·��
			///@param	pSeps	У��ʱ��μ�Ƶ��
		void UpdateCheckConfig(
				const char	*pCheckPath,
				const char	*pMD5Path,
				const char	*pSeps);

		///���ڸ�����ҳУ���������
			///@param	sDomainName	����
			///@param	nPort	�˿�
			///@param	sHtmlUrl	���Ե�url
			///@param	pHtmlValue	��ҳ��ֵ
			///@param	pSeps	У��ʱ��μ�Ƶ��
		void UpdateCheckHtml(
		string	sObjectName,
		string	&sDomainName,
		int nPort,
		string	&sHtmlUrl,
		const char	*pHtmlValue,
		const char	*pSeps)
		{
			m_lockMap.Lock();
			m_mapCheckHtml[sObjectName] = CHtmlTestValue(
					sDomainName,
					nPort,
					sHtmlUrl,
					pHtmlValue);
			if (NULL == m_pHtmlRun)
			{
				m_pHtmlRun = new CJudgeRun(pSeps);
			}

			m_lockMap.UnLock();
		}

	/* */
	private:
		///���ڼ��web������������ҳ�Ƿ�����������
			///@param	pObjectName	web��������������,�磺"apache.1"
			///@param	pServerIp	web������ip��ַ
			///@param	nPort		web�������Ķ˿ں�
			///@param	pServerName	web����������
			///@param	pHtmlUrl	web��������Url
			///@param	pHtmlValue	web������У���Ŀ��ֵ
		int htmlTest(
				const char	*pObjectName,
				const char	*pServerIp,
				int nPort,
				const char	*pServerName,
				const char	*pHtmlUrl,
				const char	*pHtmlValue);
		void htmlTestPage(
				const char	*pObjectName,
				const char	*pServerName,
				int nPort,
				const char	*pHtmlUrl,
				const char	*pHtmlValue);

		///���ڷ���Token���а���ָ����¼���Ϣ�ķ���
			///@param	pObjectName	web��������������,�磺"apache.1"
			///@param	pToken	У��ҳ�淵�ص���Ϣ�ִ�
			///@param	pHtmlValue	web������У���Ŀ��ֵ
		void Analizer(
				const char	*pObjectName,
				char *pToken,
				const char	*pHtmlValue);

#ifdef LINUX
		static int	fn(const char *file, const struct stat *sb, int flag);
#endif

	/* */
	private:
		// �����������ڱ���У��map
		CMutex	m_lockMap;

		///FTD���ݰ����ͻ�����
		CFTDCPackage m_pkgSend;

		///@key	У���Դ�ļ�·��
			///@value	У��������ļ�·��
		map<string, string> m_mapCheckFile;

		///@key	��ҳ������
			///@value	��ҳУ���ֵ
		map<string, CHtmlTestValue> m_mapCheckHtml;

		CJudgeRun *m_pJudgeRun;
		CJudgeRun *m_pHtmlRun;

		/// ����У��ļ�����
		int m_iAttrCount;		/// ָ����������
		int m_iSuccessCount;	/// �ɹ����������
		int m_iFailedCount;		/// ʧ�ܶ��������
		
			///�����������ڱ������ݶ���
		static CMutex s_lockData;

		//����ָ�����
		list<CFTDRtnObjectAttrField> s_objectAttr;

		///�澯�¼�����
		static list<CFTDRtnWarningEventField> s_warningEvent;

		///��־�¼�����
		static list<CFTDRtnSyslogEventField> s_syslogEvent;
};
