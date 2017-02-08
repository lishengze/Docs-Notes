#pragma once
#include "public.h"
#include "Thread.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "SyslogSpiImpl.h"
#include "DatabaseSpiImpl.h"

#ifdef WINDOWS
#include <stdio.h>
#include <windows.h>
#define BUFSIZE 4096
#endif
class CSANCaptureThread :
	public CThread
{
	/* */
	public:

		///���캯��
			///@param	pSANName	�ɼ�SAN�豸����ı���
			///@param	pCommand	�ɼ�SAN�豸��������
			///@param	pSeps	�ɼ���ʱ��ζ���
		CSANCaptureThread(
		const char	*pSANName,
		const char	*pCommand,
		const char	*pSeps)
		{
			m_pJudgeRun = NULL;
			m_mapCommand[pCommand] = pSANName;
			m_strReuslt = "";
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
			m_pJudgeRun = new CJudgeRun(pSeps);
		}

		~CSANCaptureThread(void)
		{
			if (m_pJudgeRun != NULL)
			{
				delete m_pJudgeRun;
				m_pJudgeRun = NULL;
			}

			ExitThread();
		}

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

		// ���������µ�SAN�豸�ɼ������
			///@param	pSANName	�ɼ�SAN�豸����ı���
			///@param	pCommand	�ɼ�SAN�豸��������
		void AddSANCapture(const char *pSANName, const char *pCommand)
		{
			m_lockData.Lock();
			m_mapCommand[pCommand] = pSANName;
			m_lockData.UnLock();
		}

	/* */
	private:
		CFTDRtnDBQueryField m_fieldQuery;

		///�ɼ��������С��������map
		map<string, string> m_mapCommand;

		///FTD���ݰ����ͻ�����
		CFTDCPackage m_pkgSend;

		// �����������ڱ������ݶ���
		CMutex	m_lockData;

		///�澯�¼�����
		list<CFTDRtnWarningEventField>	m_warningEvent;

		///����������������
		string	m_strReuslt;

		CJudgeRun *m_pJudgeRun;

	/* */

#ifdef WINDOWS
	private:
		HANDLE	hChildStdinRd;
		HANDLE	hChildStdinWr;
		HANDLE	hChildStdinWrDup;
		HANDLE	hChildStdoutRd;
		HANDLE	hChildStdoutWr;
		HANDLE	hChildStdoutRdDup;
		HANDLE	hInputFile;
		HANDLE	hStdout;

		BOOL CreateChildProcess(const char *pCommand);
		VOID ReadFromPipe(const char *pCommand);
		VOID ErrorExit(LPTSTR, const char *);
		VOID ErrMsg(LPTSTR, BOOL);
		VOID SANCapture(const char *pCommand);
		VOID AnalysisStr(void);

		///����object�ӽڵ㺯��
			///@param	pStart	�����ַ������׵�ַ
			///@param	nLength	��Ҫ�������ַ����ĳ���
		VOID AnalysisXml(char *pStart, int nLength);

		///���б��ж�ȡ���ݷ��ͺ���
			///@param	lsob	�б��������
			///@param	pAttr	�б����ݵ���������
		void SendDataFromList(
				list < map < string,
				string >> &lsob,
				char *pAttr);

		void xml_cabinet(char *pBuffer);
		void xml_storagecell(char *pBuffer);
		void xml_controller(char *pBuffer);
		void xml_disk(char *pBuffer);
		void xml_diskshelf(char *pBuffer);
		void xml_virtualdisk(char *pBuffer);
		void xml_virtualdiskfolder(char *pBuffer);
		void xml_virtualdiskfamilyfolder(char *pBuffer);
		void xml_hostfolder(char *pBuffer);
		void xml_diskgrouprootfolder(char *pBuffer);
		void xml_diskgroupfolder(char *pBuffer);
		void xml_drmgroupfolder(char *pBuffer);
		void xml_hardwarerootfolder(char *pBuffer);
		void xml_host(char *pBuffer);
		void xml_presentedunit(char *pBuffer);
		void xml_powersupply(char *pBuffer, map<string, string> &ob);
		list < map < string, string >> list_cabinet;
		list < map < string, string >> list_storagecell;
		list < map < string, string >> list_controller;
		list < map < string, string >> list_disk;
		list < map < string, string >> list_powersupply;	// Added by Henchi, 20100303  powersupply��diskshelf�����
		list < map < string, string >> list_diskshelf;
		list < map < string, string >> list_virtualdisk;
		list < map < string, string >> list_virtualdiskfolder;
		list < map < string, string >> list_virtualdiskfamilyfolder;
		list < map < string, string >> list_hostfolder;
		list < map < string, string >> list_diskgrouprootfolder;
		list < map < string, string >> list_diskgroupfolder;
		list < map < string, string >> list_drmgroupfolder;
		list < map < string, string >> list_hardwarerootfolder;
		list < map < string, string >> list_host;
		list < map < string, string >> list_presentedunit;
#endif
};

///ȡxmlԪ�ض�Ӧ�ĵ�һֵ����
///@param	pBuffer	����xml���ݵĻ�����
///@param	pKey	xml��ǩ����
///@param	pName	��ǩֵ
///@value	ob	�����ǩ��Ӧֵ��map
inline void getStrValue(
	char *pBuffer,
	char *pKey,
	char *pName,
	map<string, string> &ob)
{
	string	value = "";
	char *p = strstr(pBuffer, pKey);
	if (NULL != p)
	{
		p = p + strlen(pKey);

		char *q = strchr(p, '<');
		if (NULL != q)
		{
			value.assign(p, q - p);
		}
		else
		{
			value = "";
		}
	}
	else
	{
		value = "";
	}

	ob[pName] = value;
}

///ȡxmlԪ�ض�Ӧ�Ķ�ֵ����
///@param	pBuffer	����xml���ݵĻ�����
///@param	pKey	xml��ǩ����
///@param	pName	��ǩֵ
///@value	ob	�����ǩ��Ӧֵ��map
inline void getMultiStrValue(
	char *pBuffer,
	char *pKey,
	char *pName,
	map<string, string> &ob)
{
	string	value;
	char c = '0';
	char *p = strstr(pBuffer, pKey);
	while (NULL != p)
	{
		p = p + strlen(pKey);

		char *q = strchr(p, '<');
		if (NULL != q)
		{
			c++;
			value.assign(p, q - p);

			string	key = pName;
			key.append(1, c);
			ob[key] = value;
		}
		else
		{
			break;
		}

		p = q;
		p = strstr(p, pKey);
	}
}

///ȡxmlԪ�ض�Ӧ�ֽڵ�Ķ�ֵ����
///@param	pBuffer	����xml���ݵĻ�����
///@param	pStartNode	xml��ǩ����,��Controller��<hostport>�ڵ�
///@param	pEndNode	xml��ǩ����,��Controller��</hostport>
///@param	pKeyName	xml������ǩ����Ϊ�ؼ��ֵı�ǩ,��<hostport>���е�<portname>,���е�ֵ��Ϊ��䵽map�е�key
///@param	pKeyValue	xml������ǩ����Ϊֵ�ı�ǩ,��<hostport>���е�<operationalstate>,���е�ֵ��Ϊ��䵽map��value
///@value	ob	�����ǩ��Ӧֵ��map
inline void getMultiCodeStrValue(
	char *pBuffer,
	char *pStartNode,
	char *pEndNode,
	char *pKeyName,
	char *pKeyValue,
	map<string, string> &ob)
{
	string	valueKey = "";

	string	valueValue = "";
	char *pStart = strstr(pBuffer, pStartNode);
	while (NULL != pStart)
	{
		char *pEnd = strstr(pStart, pEndNode);
		if (NULL == pEnd)
		{
			break;
		}

		char *p = strstr(pStart, pKeyName);
		if (NULL != p && p < pEnd)	/// �����ӽڵ��ڲ����ڹؼ���
		{
			p = p + strlen(pKeyName);

			char *q = strchr(p, '<');
			if (NULL != q)
			{
				valueKey.assign(p, q - p);
			}
			else
			{
				valueKey = "";
			}
		}

		p = strstr(pStart, pKeyValue);
		if (NULL != p && p < pEnd)	/// �����ӽڵ��ڲ����ڹؼ���
		{
			p = p + strlen(pKeyValue);

			char *q = strchr(p, '<');
			if (NULL != q)
			{
				valueValue.assign(p, q - p);
			}
			else
			{
				valueValue = "";
			}
		}

		if (valueKey.length())
		{
			ob[valueKey] = valueValue;
		}

		pStart = pEnd + 1;
	}
}

///ȡxmlԪ�ض�Ӧ�ֽڵ�Ķ�ֵ����
///@param	pBuffer	����xml���ݵĻ�����
///@param	pStartNode	xml��ǩ����,��Controller��<hostport>�ڵ�
///@param	pEndNode	xml��ǩ����,��Controller��</hostport>
///@param	pTipName	����ֵ�ı�ǩ��,��ֵ��Ϊ��䵽map��key,��"hostportstate"
///@param	pKeyValue	xml������ǩ����Ϊֵ�ı�ǩ,��<hostport>���е�<operationalstate>,���е�ֵ��Ϊ��䵽map��value
///@value	ob	�����ǩ��Ӧֵ��map
inline void getMultiPropStrValue(
	char *pBuffer,
	char *pStartNode,
	char *pEndNode,
	char *pTipName,
	char *pKeyValue,
	map<string, string> &ob)
{
	string	valueValue = "";
	char *pStart = strstr(pBuffer, pStartNode);
	while (NULL != pStart)
	{
		char *pEnd = strstr(pStart, pEndNode);
		if (NULL == pEnd)
		{
			break;
		}

		char *p = strstr(pStart, pKeyValue);
		if (NULL != p && p < pEnd)	/// �����ӽڵ��ڲ����ڹؼ���
		{
			p = p + strlen(pKeyValue);

			char *q = strchr(p, '<');
			if (NULL != q)
			{
				valueValue.assign(p, q - p);
			}
			else
			{
				valueValue = "";
			}
		}

		if (pTipName != NULL && strlen(pTipName) > 0)
		{
			ob[pTipName] = valueValue;
		}

		pStart = pEnd + 1;
	}
}
