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

		///构造函数
			///@param	pSANName	采集SAN设备定义的别名
			///@param	pCommand	采集SAN设备的命令行
			///@param	pSeps	采集的时间段定义
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

		/**虚函数，子类可做一些实例化工作
	* @return true:创建成功 false:创建失败
	*/
		virtual bool InitInstance(void);

		/**虚函数，子类清楚实例
	*/
		virtual void ExitInstance(void);

		/**线程开始运行，纯虚函数，子类必须继承实现
	*/
		virtual void Run(void);

	/* */
	public:
		// 用于让主程序把线程生成的数据发送出去
		void GetSpi(void);

		// 用于增加新的SAN设备采集命令函数
			///@param	pSANName	采集SAN设备定义的别名
			///@param	pCommand	采集SAN设备的命令行
		void AddSANCapture(const char *pSANName, const char *pCommand)
		{
			m_lockData.Lock();
			m_mapCommand[pCommand] = pSANName;
			m_lockData.UnLock();
		}

	/* */
	private:
		CFTDRtnDBQueryField m_fieldQuery;

		///采集的命令行、对象别名map
		map<string, string> m_mapCommand;

		///FTD数据包发送缓冲区
		CFTDCPackage m_pkgSend;

		// 数据锁，用于保护数据队列
		CMutex	m_lockData;

		///告警事件队列
		list<CFTDRtnWarningEventField>	m_warningEvent;

		///保存命令行输出结果
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

		///分析object子节点函数
			///@param	pStart	分析字符串的首地址
			///@param	nLength	需要分析的字符串的长度
		VOID AnalysisXml(char *pStart, int nLength);

		///从列表中读取数据发送函数
			///@param	lsob	列表对象引用
			///@param	pAttr	列表数据的属性类型
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
		list < map < string, string >> list_powersupply;	// Added by Henchi, 20100303  powersupply与diskshelf相分离
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

///取xml元素对应的单一值函数
///@param	pBuffer	保存xml内容的缓冲区
///@param	pKey	xml标签类型
///@param	pName	标签值
///@value	ob	保存标签对应值的map
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

///取xml元素对应的多值函数
///@param	pBuffer	保存xml内容的缓冲区
///@param	pKey	xml标签类型
///@param	pName	标签值
///@value	ob	保存标签对应值的map
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

///取xml元素对应分节点的多值函数
///@param	pBuffer	保存xml内容的缓冲区
///@param	pStartNode	xml标签类型,如Controller的<hostport>节点
///@param	pEndNode	xml标签类型,如Controller的</hostport>
///@param	pKeyName	xml二级标签中作为关键字的标签,如<hostport>节中的<portname>,此列的值作为填充到map中的key
///@param	pKeyValue	xml二级标签中作为值的标签,如<hostport>节中的<operationalstate>,此列的值作为填充到map的value
///@value	ob	保存标签对应值的map
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
		if (NULL != p && p < pEnd)	/// 满足子节点内部存在关键字
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
		if (NULL != p && p < pEnd)	/// 满足子节点内部存在关键字
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

///取xml元素对应分节点的多值函数
///@param	pBuffer	保存xml内容的缓冲区
///@param	pStartNode	xml标签类型,如Controller的<hostport>节点
///@param	pEndNode	xml标签类型,如Controller的</hostport>
///@param	pTipName	用于值的标签名,此值作为填充到map的key,如"hostportstate"
///@param	pKeyValue	xml二级标签中作为值的标签,如<hostport>节中的<operationalstate>,此列的值作为填充到map的value
///@value	ob	保存标签对应值的map
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
		if (NULL != p && p < pEnd)	/// 满足子节点内部存在关键字
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
