/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	SyslogSpiImpl.h
///@brief	定义了日志文件读取相关的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#ifndef REF_SYSLOGSPIIMPL_H
#define REF_SYSLOGSPIIMPL_H

#include "public.h"
#include "CachedFileFlow.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#define READFILEINTERVAL	30	//文件不存在时间隔30次再尝试去读文件
	
	/////////////////////////////////////////////////////////////////////////
	///CSyslogValue定义了定期读取文件类
	///@author	周建军
	///@version	1.0,20080510
	/////////////////////////////////////////////////////////////////////////
class CSyslogValue
{
	/* */
	public:
		///探针连接地址信息
		string	m_mProbeLocation;

		///放置文件ID的字符串
		string	m_mObjectID;

		///放置文件名用的字符串,绝对路径
		string	m_mName;

		///放置文件名用的字符串,仅文件名
		string	m_mFileName;

		///放置文件类型的字符串
		string	m_mType;

		///已打开文件的描述字
		FILE *m_mFd;

		///此文件打开后已经读取的内容长度
		off_t m_mHaveRead;

		///此文件打开后已经读取的时间戳(不含年),syslog
		char m_mStrTime[20];

		///此文件打开后检查的时间
		int m_mIntTime;

		///此文件最后修改时间
		time_t	m_mTime;

		///此文件打开后已经读取的内容行数
		long m_mLines;

		///文件是否存在标记，为true表示存在，false表示不存在此文件
		int m_mValid;

		///文件是否需要继续读标记, 为true表示需要，false表示不需要
		bool m_mRdFlag;

		///保存文件读取位置标记写入指针
		CReadWriteFile	*m_pPosFiler;

		///放置FTD会话
		CFTDCSession *m_mSession;

		///放置文件名用的字符串,绝对路径
		string	m_mPosName;

		///放置连接串
		string	m_mConn;

	/* */
	public:

		///无参数的构造方法
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

		///构造方法
			///@param	pname	读取的文件名(含路径)
			///@param	pType	文件的类型(syslog,applog,keyfile,slog,dfmt文件)
			///@param	pFileName	文件名Syslog.log, 属性名dfmt.dfmtLen（dfmt文件才具备属性名，其他类型为不含路径的文件名）
			///@param	pObjectID	对象ID,如PuDian.os.AC-01.applog
			///@param	pConn	采集代理连接串信息
			///@param	pHaveRead	采集代理已经读取到的文件长度
			///@param	pReadTime	采集代理已经读取到的文件时间
			///@param	pProbeLoation	探针的地址信息
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

		///拷贝构造函数，注意：只复制文件名、有效标记、已读文件长度，读写指针和文件描述需重新分配
			///@param	ob	拷贝构造对象
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

		///析构函数，关闭文件描述符，释放文件读写标记指针空间
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

		///重载赋值操作运算符，注意：只赋值文件名、有效标记、已读文件长度，读写指针和文件描述需重新分配
			///@param	ob	赋值对象
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

		///初始化读写指针
			///@return	true表示初始化成功，false表示初始化失败
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
		///获取文件的绝对路径名
		string	m_mPath;

		///FTD会话
		CFTDCSession *m_mSession;

	/* */
	public:

		///构造函数
			///@param	objectNum	业务对象的编号
			///@param	itemNum	业务属性的编号
			///@param	pSession	FTD会话
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

		///重载>运算符
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

		///重载<运算符
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

		///重载==运算符
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

		///增加采集代理连接方法
			///@param	pProbeLocation	探针地址信息
			///@param	pSession	FTD会话
		void addProbeLocation(const char *pProbeLoation, CFTDCSession *pSession)
		{
			m_mProbeMap[pSession] = string(pProbeLoation);
			m_mStatusMap[pSession] = 0;
		}

		///取会话状态函数
			///@param	pSession	FTD会话	
			///@return	返回会话的状态
		int getStatus(CFTDCSession *pSession)
		{
			return m_mStatusMap[pSession];
		}

		///设置会话状态函数
			///@param	pSession	FTD会话
			///@param	status	状态
		void setStatus(CFTDCSession *pSession, int status)
		{
			m_mStatusMap[pSession] = status;
		}

		///删除断开的采集代理连接
			///@param	pSession	FTD会话
		void delSession(CFTDCSession *pSession)
		{
			m_mProbeMap.erase(pSession);
			m_mStatusMap.erase(pSession);
		}

		///删除文件采集对象函数
			///@param	pSession	FTD会话
			///@param	mConSyslog	文件采集对象map
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

		///取探针连接地址函数
			///@param	pSession	FTD会话
			///@return	返回地址的指针
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

		///发送FTD数据包到所有的连接
			///@param	pPackage	数据包地址
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

		///发送FTD数据包到所有的连接
			///@param	pPackage	数据包地址
			///@param	pSession	数据包发送的session会话
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

		// key:采集代理发送过来的唯一连接串 value:发送过来的会话
		map<string, CFTDCSession *> m_mConMap;

		// key:发送过来的会话 value:探针的采集地址信息
		map<CFTDCSession *, string> m_mProbeMap;

		// key:发送过来的会话 value:该会话到采集代理的连接状态
		map<CFTDCSession *, int> m_mStatusMap;

		map<string, CFTDCSession *>::iterator m_mIt;
};

/////////////////////////////////////////////////////////////////////////
///CSyslogSpiImpl定义了定期读取文件外部接口类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CSyslogSpiImpl
{
	/* */
	public:
		///构造函数
			///@param	pFlow	内存文件流指针
		CSyslogSpiImpl(CCachedFileFlow *pFlow, MapConSyslog *pFileNameMap);

		///析构函数
		~ CSyslogSpiImpl(void);

		///打印函数,打印当前所有读取文件的已读取长度
		void PrintSyslogMap(void);

		///读取文件Spi接口,外部循环调用,每调用一次就读取一次文件内容,逐行读取,读取的文件内容放入内存文件流中
			///@return	true表示成功,false表示失败
		bool GetSpi(void);

		///读取文件Spi接口,外部循环调用,每调用一次就读取一次文件内容,读取的文件内容放入内存文件流中
			///@return	true表示成功,false表示失败
		bool GetTotalSpi(void);

		///读取文件大小Spi接口,外部循环调用,每调用一次就读取一次文件内容,逐行读取,读取的文件内容放入内存文件流中
			///@return	true表示成功,false表示失败
		bool GetSizeSpi(void);

		///读取文件Spi接口,外部循环调用,每调用一次就读取一次文件内容,读取的文件内容放入内存文件流中
			///@return	true表示成功,false表示失败
		bool GetBinSpi(void);

		///读取文件Spi接口,外部循环调用,每调用一次就读取一次文件内容,逐行读取,读取的文件内容放入内存文件流中
			///@return	true表示成功,false表示失败
		bool DispatchIOsSpi(void);

		///读取文件Spi接口,外部循环调用,每调用一次就读取一次文件内容,逐行读取,读取的文件内容放入内存文件流中
			///@return	true表示成功,false表示失败
		bool DispatchIOsBinSpi(void);

		///续读文件函数,从上次读取的位置开始,逐行读取,续读指定文件到文件尾
			///@param	filename	读取的文件名
			///@param	loginfo	使用的文件读取对象名
			///@return	无返回值
		void KeepReadFile(string &filename, CSyslogValue &loginfo);

		///续读文件大小函数,从上次读取的位置开始,逐行读取,续读指定文件到文件尾
			///@param	filename	读取的文件名
			///@param	loginfo	使用的文件读取对象名
			///@return	无返回值
		void KeepReadFileSize(string &filename, CSyslogValue &loginfo);

		///续读文件函数,从上次读取的位置开始,续读指定文件到文件尾
			///@param	filename	读取的文件名
			///@param	loginfo	使用的文件读取对象名
			///@return	无返回值
		void KeepReadBinFile(string &filename, CSyslogValue &loginfo);

		///打开文件函数,检索并定位读取位置
			///@param	filename	读取的文件名
			///@param	loginfo	使用的文件读取对象名
			///@return	false 表示返回失败，true表示成功
		void KeepReadTotalFile(string &filename, CSyslogValue &loginfo);

		///打开文件函数,检索并定位读取位置
			///@param	filename	读取的文件名
			///@param	loginfo	使用的文件读取对象名
			///@return	false 表示返回失败，true表示成功
		bool OpenReadFile(string &filename, CSyslogValue &loginfo);

	/* */
	private:
		///保存当前的日期,以便重复使用
		char m_mDate[MAXTIMELEN];

		///当前的采集事件,格式为HH:MM:SS
		char m_mTime[MAXTIMELEN];

		///采集对象的ID
		char m_mObjectId[MAXOBJECTNAMELEN];

		///采集对象的名称
		char m_mObjectName[MAXOBJECTNAMELEN];

		///读取文件内容用的缓冲区,每次读写最大长度为MAXONECONTENTLEN-1
		char m_mReadBuff[MAXONECONTENTLEN];

		///每次读取文件内容的长度
		int m_mBuffSize;

		///发送文件内容用的FTD数据包
		CFTDCPackage m_pkgSend;

		///发送的日志文件内容域
		CFTDRtnSyslogInfoField	m_mLogField;

		CFTDSysFileAccessInfoField	m_mAccessField;

		///内存文件流的地址
		CCachedFileFlow *m_pFlow;

		///读取文件列表指针
		MapConSyslog *m_pFileNameMap;
};
#endif // REF_SYSLOGSPIIMPL_H
