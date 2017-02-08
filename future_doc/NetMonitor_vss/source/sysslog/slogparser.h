///////////////////////////////////////////////////////////////////////////////////////
//slogparser.h
//
//20071226 赵鸿昊	增加使用-a参数，输出OFP报单的请求/应答时间
//20080109 赵鸿昊	1.增加-e参数，指定错误输出文件
//					2.修改-a参数，可以指定输出RTT不合要求的报单请求/应答
//					3.报单请求应答匹配改为四个字段，增加了LocalID序号和会话号，以避免
//					  LocalID重复及基于会员的MBack
//					4.修改Reactor读操作的驱动模式，不再遍历IOList，改由CSlogConnection
//					  直接驱动，速度可以提高几十倍
//20080110 赵鸿昊	1.增加对FTD协议的支持
//					2.RTT分析支持-f模式
#ifndef REF_SLOGPARSER_H
#define REF_SLOGPARSER_H

#include "public.h"
#include "FTDCSession.h"
#include "OFPSession.h"
#include "FtdPackageDesc.h"
#include "FTDCPackage.h"
#include "CSVParser.h"
#include "Storage.h"
#include "OfpData.h"
#include "FtdPackageDesc.h"
#include "CDate.h"
#include "version.h"
#include "SelectReactor.h"

#include "CPackageFilter.h"
#include "CSlogConnection.h"
#include "CDumpSession.h"
#include "COrderRttManager.h"

#define MAX_SLOG_REC_LEN	20480

#define COUNT_NEW_SLOG_FLAG 60

typedef CHashMap<int, CSlogConnection *, HashInt> CSlogConnectionMap;

#define DEFAULT_FOLLOW	true

///=== 20110907 by zhou.jj

/**Channel事件在日志中的头
*/
struct TNewChannelLogHeader
{
	DWORD dwId;		/**< Channel的句柄*/
	DWORD dwTime;	/**< 事件发生时间 */
	WORD wType;		/**< 事件类型 */
	WORD wLength;	/**< 事件内容长度 */

	/**改变字节序
	*/
	void ChangeEndian(void)
	{
		CHANGE_ENDIAN(dwId);
		CHANGE_ENDIAN(dwTime);
		CHANGE_ENDIAN(wType);
		CHANGE_ENDIAN(wLength);
	}
};

///20110907 by zhou.jj


/////////////////////////////////////////////////////////////////////////
///CSlogDescript定义了单个slog文件读取管理类
///@author	周建军
///@version	1.0,20080711
/////////////////////////////////////////////////////////////////////////
class CSlogDescript
{
	/* */
	public:
		CSlogDescript(void);

		///构造函数
			///@param	pszSlogFileName	SLog文件名字
			///@param	nSlogFileNameId	文件名的唯一ID编号
		CSlogDescript(const char *pszSlogFileName, const int nSlogFileNameId);

		///构造函数
			///@param	nDataCenterId	Slog文件归属数据中心ID编号
			///@param	pszSlogFileName	SLog文件名字
			///@param	nSlogFileNameId	文件名的唯一ID编号
		CSlogDescript(
			const int nDataCenterId,
			const char	*pszSlogFileName,
			const int nSlogFileNameId);

		///构造函数
			///@param	nDataCenterId	Slog文件归属数据中心ID编号
			///@param	pszSlogFileName	SLog文件名字
			///@param	nSlogFileNameId	文件名的唯一ID编号
			///@param	pszDesiredIpAddress	过滤的ip地址
		CSlogDescript(
			const int nDataCenterId,
			const char	*pszSlogFileName,
			const int nSlogFileNameId,
			const char	*pszDesiredIpAddress);

		///构造函数
			///@param	nDataCenterId	Slog文件归属数据中心ID编号
			///@param	pszSlogFileName	SLog文件名字
			///@param	nSlogFileNameId	文件名的唯一ID编号
			///@param	pszDesiredIpAddress	过滤的ip地址
			///@param	bFollow	持续读取文件标记
		CSlogDescript(
			const int nDataCenterId,
			const char	*pszSlogFileName,
			const int nSlogFileNameId,
			const char	*pszDesiredIpAddress,
			bool bFollow);

		///拷贝构造函数
		CSlogDescript(const CSlogDescript &ob)
		{
			m_fpSlog = ob.m_fpSlog;
			m_strSlogFileName = ob.m_strSlogFileName;
			m_strDesiredIpAddress = ob.m_strDesiredIpAddress;
			memcpy(&m_header, &(ob.m_header), sizeof(m_header));
			m_nReadLen = ob.m_nReadLen;
			m_bFollow = ob.m_bFollow;

			INT64 mFposlong = FPOS_GET(ob.m_fposLog);
			FPOS_SET(m_fposLog, mFposlong);
			m_tLastTime = ob.m_tLastTime;
			m_nFrontID = ob.m_nFrontID;
			m_nFileID = ob.m_nFileID;
			m_cVersion = ob.m_cVersion;
			m_cWrongFlag = ob.m_cWrongFlag;
			newFileFlag = ob.newFileFlag;
		}

		///重载“=”运算符
		void operator=(const CSlogDescript &ob)
		{
			m_fpSlog = ob.m_fpSlog;
			m_strSlogFileName = ob.m_strSlogFileName;
			m_strDesiredIpAddress = ob.m_strDesiredIpAddress;
			memcpy(&m_header, &(ob.m_header), sizeof(m_header));
			m_nReadLen = ob.m_nReadLen;
			m_bFollow = ob.m_bFollow;

			INT64 mFposlong = FPOS_GET(ob.m_fposLog);
			FPOS_SET(m_fposLog, mFposlong);
			m_tLastTime = ob.m_tLastTime;
			m_nFrontID = ob.m_nFrontID;
			m_nFileID = ob.m_nFileID;
			m_cVersion = ob.m_cVersion;
			m_cWrongFlag = ob.m_cWrongFlag;
			newFileFlag = ob.newFileFlag;
		}
		int getIDFrontMap(string str_slog_file_name);
	/* */
	public:
		///保存打开的文件描述符
		FILE *m_fpSlog;

		///SLog数据包头
		TChannelLogHeader m_header;
		TNewChannelLogHeader m_newHeader;

		///文件读写缓冲区
		char m_buffer[MAX_SLOG_REC_LEN];

		///文件已读取长度
		int m_nReadLen;

		///文件读取标记,true表示循环读取,false表示读取结束即停止
		bool m_bFollow;

		///保存文件路径名
		string	m_strSlogFileName;

		///保存过滤的IP地址
		string	m_strDesiredIpAddress;

		///文件读写位置
		fpos_t	m_fposLog;

		///保存Slog连接对象
		CSlogConnectionMap	m_mapSlogConnection;

		///最后读的时间
		time_t	m_tLastTime;

		///前置的编号
		int m_nFrontID;

		///读取文件的编号
		int m_nFileID;

		///协议版本号,0为ftd，1为ofp，2为ofp2
		char m_cVersion;

		///文件出错标记，一旦文件读出错，就暂停读取该文件
		char m_cWrongFlag;

		///=== 20110907 by zhou.jj
			///SLog新格式数据包头
		int newFileFlag;

		/// 20110907 by zhou.jj
};

class CSlogReactor :
	public CReactor
{
	/* */
	public:
		~ CSlogReactor(void);

		void Clear(void)
		{
			for (m_mapIt = m_mapSlogDescript.begin();
				 m_mapIt != m_mapSlogDescript.end();
				 m_mapIt++)
			{
				CSlogConnectionMap::iterator itor = m_mapIt->second.
					m_mapSlogConnection.Begin();
				while (!itor.IsEnd())
				{
					delete(*itor);
					itor++;
				}

				m_mapIt->second.m_mapSlogConnection.Clear();

				if (m_mapIt->second.m_fpSlog != NULL)
				{
					fclose(m_mapIt->second.m_fpSlog);
					m_mapIt->second.m_fpSlog = NULL;
				}
			}

			m_mapSlogDescript.clear();
		}

		void GetSlogFileStatus(int nFrontID, char *pLogBuf);

	/* */
	protected:
		CSlogConnection *CreateSlogConnection(
							int nID,
							const char	*pszIPAddress,
							int nFrontID,
							int nFileID,
							char cVersion);
		CSlogConnection *GetSlogConnection(int nID);
		bool DelSlogConnection(int nID);

		bool ReadOne(void);
		virtual void DispatchIOs(void);

	/* */
	private:
		void PrepareIds(fd_set &readfds, fd_set &writefds, int &MaxID);
		void DispatchIO(fd_set &readfds, fd_set &writefds, int &MaxID);

	/* */
	private:
		map<string, CSlogDescript>	m_mapSlogDescript;
		map<string, CSlogDescript>::iterator m_mapIt;
};
#endif //end REF_SLOGPARSER_H
