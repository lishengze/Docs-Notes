/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	FileRecordFinder.cpp
///@brief	利用一个时间字符串定位在文件中的记录位置
///@history
///20080527	武玉波		创建该文件
///20120410	晏鹤春		加入日志跨年处理机制（原理上不支持多次跨年的情况）
/////////////////////////////////////////////////////////////////////////
#include "FileRecordFinder.h"

#define REC_BUF_SIZE	4096

//static map<string,int> m_month;
CFileRecordFinder::CFileRecordFinder(const char *filename) :
	m_fd(NULL)
{
	m_lKey = 0;
	m_lFirst = 0;
	m_lLast = 0;
	m_posFirst = 0;
	m_posLast = 0;
	strcpy(&m_filename[0], filename);
}

CFileRecordFinder::CFileRecordFinder(FILE *file) :
	m_fd(file)
{
	m_lKey = 0;
	m_lFirst = 0;
	m_lLast = 0;
	m_posFirst = 0;
	m_posLast = 0;
	m_filename[0] = 0;
}

CFileRecordFinder::~CFileRecordFinder(void)
{
	/// 如果文件并非由本对象打开，则不在此处释放文件句柄
	if (strlen(m_filename))
	{
		fclose(m_fd);
	}

	m_fd = NULL;
}

bool CFileRecordFinder::getRecordPosL(
	size_t	pos_low,
	size_t	pos_high,
	size_t	&pos_dest,
	char *szTime,
	int iTimeLen,
	bool bHead)
{
	char szBuf[REC_BUF_SIZE];
	long pos = -1;
	long lBytes = 0;
	size_t	pos_offset = 0;

	while (pos == -1 && pos_low < pos_high && pos_offset < pos_high)
	{
		memset(szBuf, 0x00, sizeof(szBuf));
		lBytes = readBufL(pos_low, pos_high, pos_offset, szBuf, sizeof(szBuf));
		if (lBytes <= 0)
		{
			/// read nothing, should break;
			break;
		}

		if (bHead == true)
		{
			/// 当前为首块字串
			pos = getCompKey(szBuf, szTime, iTimeLen, POS_HEAD);
			bHead = false;
		}
		else
		{
			/// 当前为后续块字串
			pos = getCompKey(szBuf, szTime, iTimeLen, POS_FIRST);
		}

		if (pos >= 0)
		{
			/// 得到有效记录日期位置
			pos_offset += pos;
			pos_dest = pos_offset;
			return true;
		}
		else
		{
			/// 检索游标继续移动
			pos_offset += lBytes;
		}
	}

	return false;
}

bool CFileRecordFinder::getRecordPos(
	size_t	pos_low,
	size_t	pos_high,
	size_t	&pos_dest,
	char *szTime,
	int iTimeLen,
	long l_Time)
{
	char szBuf[REC_BUF_SIZE];
	long pos = -1;
	long lBytes = 0;
	long lRecTime = 0;
	size_t	pos_offset = pos_low;
	pos_dest = pos_low;

	moveFilePoint(pos_low);
	while
	(
		!feof(m_fd)
	&&	fgets(szBuf, sizeof(szBuf) - 1, m_fd)
	&&	pos_offset <= pos_high
	)
	{
		if (IsValidDateTime(szBuf))
		{
			pos_dest = pos_offset;
			lRecTime = DateStringToLong(szBuf);
			if (lRecTime >= l_Time)
			{
				/// 找到目标时间戳记录,当前pos_dest即为首个目标时间戳位置
				return true;
			}
		}

		pos_offset += strlen(szBuf);
	}

	/// 未找到目标时间戳记录,当前pos_dest为区间内最后一个有效时间戳位置(或者pos_low)
	return false;
}

// add by cao.ning
// 修正了原算法中，若出现跨年，会错误的返回第一条记录的情况
// 本算法中使用了时间差比较，而不仅仅是判断记录时间是否大于目标时间
bool CFileRecordFinder::getRecordPosNew( 
	size_t pos_low, 
	size_t pos_high, 
	size_t &pos_dest, 
	char *szTime, 
	int iTimeLen, 
	long l_Time )
{
	moveFilePoint(pos_low);

	char szBuff[REC_BUF_SIZE] = {0};
	size_t	pos_offset = pos_low;

	int Readlen = fread(szBuff, 1, pos_high - pos_low, m_fd);
	if (Readlen > 0)
	{
		// 将读取到的文件内容按行存储
		// pair: offset, 行内容
		vector<pair<int, string> > LinesBuffer;

		size_t	pos_offset = pos_low;

		char* p = strtok(szBuff, "\n");
		LinesBuffer.push_back(make_pair(pos_offset, p));
		pos_offset += (strlen(p) + 1);	// \n占了一个字符

		while ((p = strtok(NULL, "\n")) != NULL)
		{
			LinesBuffer.push_back(make_pair(pos_offset, p));
			pos_offset += (strlen(p) + 1);
		}

		// 如果取出的内容只有一行，就返回这一行的偏移量
		if (LinesBuffer.size() <= 1)
		{
			pos_dest = pos_low;
			return true;
		}
		else
		{
			long lStartLineTime = DateStringToLong(LinesBuffer[0].second.c_str());
			long lEndLineTime = DateStringToLong(LinesBuffer[LinesBuffer.size() - 1].second.c_str());
			if (l_Time > lEndLineTime)	// buff中所有记录的时间均小于目标时间
			{
				// 偏移量设置为buff尾部
				pos_dest = pos_high;
				return true;
			}
			else if (l_Time < lStartLineTime)	// buff中所有记录的时间均大于目标时间
			{
				// 偏移量设置为buff首部
				pos_dest = pos_low;
				return true;
			}

			// 从后向前对比，计算目标时间与这双行时间的差值，当与前一行的差值大于后一行时，返回后一行的偏移量
			// 差值使用unsigned，若差值出现负值，同样适用
			vector<pair<int, string> >::iterator itBackLine = LinesBuffer.end() - 1, itFrontLine = itBackLine - 1;
			for (;itFrontLine >= LinesBuffer.begin(); --itBackLine, --itFrontLine)
			{
				// 与后一行的时间差
				unsigned BackTimeOffset = DateStringToLong(itBackLine->second.c_str()) - l_Time;
				unsigned FrontTimeOffset = DateStringToLong(itFrontLine->second.c_str()) - l_Time;

				if (FrontTimeOffset > BackTimeOffset)
				{
					pos_dest = itBackLine->first;
					return true;
				}
			}
			// 如果此时还未找到合适的时间，说明buff中的所有时间均比目标时间大，则返回buff中的第一行
			pos_dest = pos_low;
			return true;
		}
	}

	pos_dest = pos_low;
	return false;
}


bool CFileRecordFinder::getRecordPosR(
	size_t	pos_low,
	size_t	pos_high,
	size_t	&pos_dest,
	char *szTime,
	int iTimeLen)
{
	char szBuf[REC_BUF_SIZE];
	long pos = -1;
	long lBytes = 0;
	size_t	pos_offset = m_size;

	while (pos == -1 && pos_low < pos_high && pos_low < pos_offset)
	{
		memset(szBuf, 0x00, sizeof(szBuf));
		lBytes = readBufR(pos_low, pos_high, pos_offset, szBuf, sizeof(szBuf));
		if (lBytes <= 0)
		{
			/// read nothing, should break;
			break;
		}

		pos_offset -= lBytes;
		pos = getCompKey(szBuf, szTime, iTimeLen, POS_LAST);

		if (pos >= 0)
		{
			/// 得到有效记录日期位置
			pos_offset += pos;
			pos_dest = pos_offset;
			return true;
		}
	}

	return false;
}

int CFileRecordFinder::readBufL(
	size_t	pos_low,
	size_t	pos_high,
	size_t	&pos_offset,
	char *szBuf,
	int iBufSize)
{
	/// 限定pos_offset取值区间[pos_low, pos_high]
	pos_offset = pos_offset < pos_low ? pos_low : (pos_offset > pos_high ? pos_high : pos_offset);

	long lBytes = (pos_high - pos_offset) > (iBufSize - 1) ? (iBufSize - 1) :
		(pos_high - pos_offset);
	fseek(m_fd, pos_offset, SEEK_SET);
	return fread(szBuf, 1, lBytes, m_fd);
}

int CFileRecordFinder::readBufR(
	size_t	pos_low,
	size_t	pos_high,
	size_t	pos_offset,
	char *szBuf,
	int iBufSize)
{
	/// 限定pos_offset取值区间[pos_low, pos_high]
	pos_offset = pos_offset < pos_low ? pos_low : (pos_offset > pos_high ? pos_high : pos_offset);

	/// pos_offset 前移
	long lBytes = (pos_offset - pos_low) > (iBufSize - 1) ? (iBufSize - 1) :
		(pos_offset - pos_low);
	pos_offset -= lBytes;
	fseek(m_fd, pos_offset, SEEK_SET);
	return fread(szBuf, 1, lBytes, m_fd);
}

int CFileRecordFinder::getCompKey(
	char *szBuf,
	char *szTime,
	int iTimeLen,
	POS_TYPE posType)
{
	char *pCursor = szBuf;
	char *pPos = pCursor;
	long pos = -1;

	if (POS_HEAD == posType && IsValidDateTime(pPos))
	{
		memset(szTime, 0x00, iTimeLen);
		strncpy(szTime, pPos, iTimeLen - 1);
		return 0;
	}

	/// 尝试找到最首的一个满足条件的换行符（该换行符后的记录内容满足时间串的基本要求）
	while ((pPos = strchr(pCursor, '\n')) != NULL)
	{
		pPos++;
		if (IsValidDateTime(pPos))
		{
			pos = pPos - szBuf;
			memset(szTime, 0x00, iTimeLen);
			strncpy(szTime, pPos, iTimeLen - 1);
			if (POS_LAST != posType)
			{	// 仅当需要找到首个位置时退出
				break;
			}
		}

		pCursor = pPos;
	}

	return pos;
}

/// 搜索一个字符串
///@return -1 没有找到
long CFileRecordFinder::Search(const char *keyStr)
{
	long key = DateStringToLong(keyStr);
	return Search(key);
}

long CFileRecordFinder::Search(long key)
{
	init();
	return find(key, 2048);
}

long CFileRecordFinder::SearchNew( long key, bool isSysLog )
{
	init();
	return findNew(key, 2048, isSysLog);	// isSysLog表示搜索的是否为SysLog文件
}

///初始化文件尺寸和定位文件指针到开始位置
///@return -1 获取文件尺寸信息失败
int CFileRecordFinder::init(void)
{
	if (m_fd == NULL)
	{
		/// Mod by Henchi, 20120407
				/// 文件打开模式"r+"调整为"r"
		m_fd = fopen((const char *) &m_filename[0], "r");
		if (m_fd == NULL)
		{
			printf("Open File [%s] failure\n", m_filename);
			fflush(stdout);
			return -1;
		}
	}

	/// get file size
	int result;
#ifdef WIN32
	struct _stat buf;
	result = _fstat(fileno(m_fd), &buf);
#else
	struct stat buf;
	result = fstat(fileno(m_fd), &buf);
#endif
	if (result != 0)
	{
		if (errno == EBADF)
		{
			printf("Bad file descriptor.\n");
		}
		else if (errno == EINVAL)
		{
			printf("Invalid argument to fstat.\n");
		}

		fflush(stdout);
		return -1;
	}
	else
	{
		m_size = buf.st_size;
		m_modtime = buf.st_mtime;

		/// Added by Henchi, 20120407
		if (m_size <= 0)
		{
			printf("Empty file [%s].\n", m_filename);
		}
		else
		{
			/// 尝试通过首条及末条记录判断日志是否存在跨年现象
						/// 当首条记录日期比末条记录日志大2天以上即认为跨年
			char recFirst[LEN_DATATIME_STAMP];
			char recLast[LEN_DATATIME_STAMP];
			int recBufLen = LEN_DATATIME_STAMP;

			size_t	low = 0;
			size_t	high = m_size;
			size_t	offset;

			/// 获取区间范围内首个有效时间戳的位置
			if (getRecordPosL(low, high, offset, recFirst, recBufLen))
			{
				m_lFirst = DateStringToLong(recFirst);
				m_posFirst = offset;

				if (getRecordPosR(low, high, offset, recLast, recBufLen))
				{
					m_lLast = DateStringToLong(recLast);
					m_posLast = offset;
				}
				else
				{
					m_lLast = m_lFirst;
					m_posLast = m_posFirst;
				}
			}
		}
	}

	moveFilePoint(0);
	return 0;
}

/// 移动文件指针到特定位置
void CFileRecordFinder::moveFilePoint(size_t pos)
{
	fseek(m_fd, pos, SEEK_SET);
}

long CFileRecordFinder::getDateCode(long lDatetime)
{
	return lDatetime >> 18;
}

/// Mod by Henchi, 20120410
/// 重构了查找记录位置的方法，加入对跨年现象的支持
/// 找到文件中的目标位置
size_t CFileRecordFinder::find(
	long l_key,
	size_t	blockSize,
	size_t	pos_low,		// 前部记录在文件内的偏移量
	size_t	pos_high,		// 尾部记录在文件内的偏移量
	long l_low,				// 前部记录的时间值
	long l_high)			// 尾部记录的时间值
{
	///用于提取记录中的时间部分的数据
	char rec[LEN_DATATIME_STAMP];
	int recBufLen = sizeof(rec);

	size_t	pos_offset = 0; /// 保存目标位置的偏移量
	size_t	pos_mid = 0;
	long l_mid = 0;

	/// 确保pos_low始终成功标记时间戳
	while ((pos_high - pos_low) > LEN_DATATIME_STAMP)	/// 保障区块空间
	{
		if ((pos_high - pos_low) < REC_BUF_SIZE)
		{
			/// 已进入小区块范围，直接逐行读取更高效
						/// 不论是否找到，均以pos_low标识目标位置
			//getRecordPos(pos_low, pos_high, pos_offset, rec, recBufLen, l_key);
			getRecordPosNew(pos_low, pos_high, pos_offset, rec, recBufLen, l_key);
			pos_low = pos_offset;
			break;
		}

		pos_mid = pos_low + (pos_high - pos_low) / 2;	/// 粗取中间位置
						
				/// 寻找此后首个时间戳
		if (!getRecordPosL(
				pos_mid,
			pos_high,
			pos_offset,
			rec,
			recBufLen,
			false))
		{
			/// pos_offset 无效
						/// 当前pos_mid之后已无时间戳信息，尝试将匹配区间前移
			pos_high = pos_mid;
		}
		else
		{
			/// pos_offset 有效
						/// 已知pos_mid之后有时间戳
			l_mid = DateStringToLong(rec);
			if (l_mid > l_high)				// 说明此处仍为去年的信息，尝试将匹配区间后移
			{
				pos_low = pos_offset;
			}
			else if (l_mid == l_high)		// 认为此处已接近尾部
			{
				if (l_key > l_mid)			// l_key > l_high
				{
					pos_low = pos_high;		// 区间内找不到匹配的记录，匹配结束
					break;
				}
				else						// l_key <= l_mid
				{
					pos_high = pos_offset;	// 尝试将匹配区间前移（当存在多个跨年现象时，区间前移可能前进到非本年的记录段）
				}
			}
			else	// l_mid < l_high	// 认为此处已接近目标位置
			{
				if (l_key > l_mid)
				{
					pos_low = pos_offset;	// 尝试将匹配区间后移
				}
				else						// l_key <= l_mid
				{
					pos_high = pos_offset;	// 尝试将匹配区间前移
					l_high = l_mid;
				}
			}
		}
	}

	return pos_low;
}

///@return -1 not found
long CFileRecordFinder::find(long key, size_t blockSize)
{
	m_lKey = key;

	long cur;
	int bufSize = 2048;
	char buf[2048];
	string	str_msg;

	///用于存放记录中的时间数据
	char rec[LEN_DATATIME_STAMP];
	int recBufLen = sizeof(rec);

	size_t	low = 0;
	size_t	mid = 0;
	int pos = 0;

	/// 处理过程简要说明：
		/// 首先文件初始化时得到文件首条记录及末条记录时间值
		/// 结合首末时间及目标时间信息，分析当前日志内容的基本情况
		/// 包括:是否跨年? 是全匹配、全不匹配，还是部分匹配?
		/// 对于部分匹配情况进行深入分析
	if (m_lFirst == 0 || m_lLast == 0)
	{
		/// 未成功获取起止时间戳信息，表明日志格式可能有误		
		printf(
			"\n====FileRecordFinder====\n  LogFile[%s]\n  Message[%s]\n",
			m_filename,
			"No Records found");
		return -1;
	}

	if (getDateCode(m_lFirst) <= getDateCode(m_lLast))
	{
		if (m_lKey <= m_lFirst)
		{
			if (getDateCode(m_lKey) < getDateCode(m_lFirst) - 2)
			{
				/// 说明日志文件中所有的记录都是去年的
				low = m_size;
				str_msg = "All Records are last year's";
			}
			else
			{
				/// 说明日志文件首个时间戳已符合要求
				low = m_posFirst;
				str_msg = "All Records are new";
			}
		}
		else if (m_lKey <= m_lLast)
		{
			/// 常见情形，要在文件尾部向前找出最早的符合条件的位置
			low = find(
					m_lKey,
					blockSize,
					m_posFirst,
					m_posLast,
					m_lFirst,
					m_lLast);
			str_msg = "Caudal Records are new";
		}
		else
		{
			/// 日志中现有记录时间均过期，要找的位置于文件尾部
			low = m_size;
			str_msg = "All Records are too old";
		}
	}
	else	/// 可以认为存在有跨年的现象
	{
		if (m_lKey <= m_lLast)
		{
			/// 此情形较复杂，要在文件尾部向前找出最早的符合条件的位置
			low = find(
					m_lKey,
					blockSize,
					m_posFirst,
					m_posLast,
					m_lFirst,
					m_lLast);
			str_msg = "There are multi-year records, Caudal Records are new";
		}
		else
		{
			/// 日志中现有记录时间均过期，要找的位置于文件尾部
			low = m_size;
			str_msg = "There are multi-year records, All Records are too old";
		}
	}

	printf(
		"\n====FileRecordFinder====\n  LogFile[%s]\n  IntTime[%ld]\n  StrTime[%s]\n  SeekPos[%ld]\n  Message[%s]\n\n",
		m_filename,
		m_lKey,
		LongToDateString(m_lKey),
		low,
		str_msg.c_str());
	fflush(stdout);
	return low;
}

///判断一个时间日期串的格式是否合法
///字串形如[Jun 03 13:38:56]的为合法
bool CFileRecordFinder::IsValidDateTime(char *buf)
{
	char *p = buf;
	return (p != NULL) && (strlen(p) >= LEN_DATATIME_STAMP - 1)
&&	(
			(
				*(p + 3) == ' '
			&&	*(p + 6) == ' '
			&&	*(p + 9) == ':'
			&&	*(p + 12) == ':'
			)
		||	(
					*(p + 3) == ' ' && *(p + 5) == ' ' && *(p + 8) == ':' && *
						(p + 11) == ':'
				)
		);
}

///把一个形如[Jun 03 13:38:56]的时间串转换为一个整数
///month|day|hour|minute|second
///4bits|5bits|5bits|6bits|6bits = 26bits
///bits: 6|6|6|6|6 = 30bits final design
///@return 0 说明没有能够正确的解析出时间
long CFileRecordFinder::DateStringToLong(const char *str)
{
	static int	initflag = 0;
	static map<string, int> month;
	if (initflag == 0)
	{
		month.insert(std::make_pair(string("Jan"), 1));
		month.insert(std::make_pair(string("Feb"), 2));
		month.insert(std::make_pair(string("Mar"), 3));
		month.insert(std::make_pair(string("Apr"), 4));
		month.insert(std::make_pair(string("May"), 5));
		month.insert(std::make_pair(string("Jun"), 6));
		month.insert(std::make_pair(string("Jul"), 7));
		month.insert(std::make_pair(string("Aug"), 8));
		month.insert(std::make_pair(string("Sep"), 9));
		month.insert(std::make_pair(string("Oct"), 10));
		month.insert(std::make_pair(string("Nov"), 11));
		month.insert(std::make_pair(string("Dec"), 12));
		initflag = 1;
	}

	if (!IsValidDateTime((char *)str))
	{
		return 0;
	}

	long ret = 0;
	long field;

	int fieldCnt = 0;
	int bits = 30;

	char *tmp = (char *)str;

	while (tmp && (*tmp) == ' ')
	{
		tmp++;
	}

	char *buf = (char *)malloc(strlen(tmp) + 1);
	strcpy(buf, tmp);
	tmp = buf;

	char *p = NULL;
	p = strtok(tmp, " :");
	if (p)
	{
		fieldCnt++;

		map<string, int>::iterator	it;
		it = month.find(p);
		if (it != month.end())
		{
			field = month[p];
		}
		else
		{
			printf("Record==%s	%s\n", p, str);
			printf("需分析的时间串不正确\n");
			fflush(stdout);
			free(buf);
			return 0;
		}

		bits -= 6;
		ret |= field << bits;
	}

	while ((p = strtok(NULL, " :")) != NULL)
	{
		field = atoi(p);
		bits -= 6;
		ret |= field << bits;

		fieldCnt++;
		if (fieldCnt == 5)
		{
			break;
		}
	}

	free(buf);

	if (fieldCnt != 5)
	{
		return 0;
	}

	return ret;
}

char *CFileRecordFinder::LongToDateString(long lDatetime)
{
	static int	initflag = 0;
	static map<int, string> month_int;
	if (initflag == 0)
	{
		month_int.insert(std::make_pair(1, string("Jan")));
		month_int.insert(std::make_pair(2, string("Feb")));
		month_int.insert(std::make_pair(3, string("Mar")));
		month_int.insert(std::make_pair(4, string("Apr")));
		month_int.insert(std::make_pair(5, string("May")));
		month_int.insert(std::make_pair(6, string("Jun")));
		month_int.insert(std::make_pair(7, string("Jul")));
		month_int.insert(std::make_pair(8, string("Aug")));
		month_int.insert(std::make_pair(9, string("Sep")));
		month_int.insert(std::make_pair(10, string("Oct")));
		month_int.insert(std::make_pair(11, string("Nov")));
		month_int.insert(std::make_pair(12, string("Dec")));

		initflag = 1;
	}

	static char DateTime[LEN_DATATIME_STAMP];
	memset(DateTime, 0x00, sizeof(DateTime));

	int iMon = (lDatetime & MASK_MON) >> 24;
	int iDay = (lDatetime & MASK_DAY) >> 18;
	int iHour = (lDatetime & MASK_HOUR) >> 12;
	int iMin = (lDatetime & MASK_MIN) >> 6;
	int iSec = (lDatetime & MASK_SEC);
	if (iMon > 0
	&&	iMon <= 12
	&&	iDay > 0
	&&	iDay <= 31
	&&	iHour >= 0
	&&	iHour < 60
	&&	iMin >= 0
	&&	iMin < 60
	&&	iSec >= 0
	&&	iSec < 60)
	{
		sprintf(
			DateTime,
			"%s %02d %02d:%02d:%02d",
			month_int[iMon].c_str(),
			iDay,
			iHour,
			iMin,
			iSec);
	}

	return DateTime;
}

// isSysLog指明了该文件是否为SysLog文件
// 若为SysLog文件，则key表示的是今天的起始时间
// 即，文件搜索仅搜索今天的记录
long CFileRecordFinder::findNew( long key, size_t blockSize, bool isSysLog )
{
	m_lKey = key;

	long cur;
	int bufSize = 2048;
	char buf[2048];
	string	str_msg;

	///用于存放记录中的时间数据
	char rec[LEN_DATATIME_STAMP];
	int recBufLen = sizeof(rec);

	size_t	low = 0;
	size_t	mid = 0;
	int pos = 0;

	/// 处理过程简要说明：
	/// 首先文件初始化时得到文件首条记录及末条记录时间值
	/// 结合首末时间及目标时间信息，分析当前日志内容的基本情况
	/// 包括:是否跨年? 是全匹配、全不匹配，还是部分匹配?
	/// 对于部分匹配情况进行深入分析
	if (m_lFirst == 0 || m_lLast == 0)
	{
		/// 未成功获取起止时间戳信息，表明日志格式可能有误		
		printf(
			"\n====FileRecordFinder====\n  LogFile[%s]\n  Message[%s]\n",
			m_filename,
			"No Records found");
		return -1;
	}

	// 说明：
	// SysLog文件中，最新的记录只能是今天的。不可能发生今天写入明天的记录
	// 因此可以通过SysLog的这一特点简单的判断文件内容是否陈旧
	// 也就是说，如果SysLog尾部的记录如果不是今天的，那么就认为文件是陈旧的
	if (isSysLog)
	{
		long lTailTime = m_lLast, lTodayTime = key;
		lTailTime = lTailTime >> 18;
		lTodayTime = lTodayTime >> 18;
		if (lTodayTime != lTailTime)
		{
			low = m_size;
			str_msg = "All Records are old.";
		}
		else
		{
			low = find(
				m_lKey,
				blockSize,
				m_posFirst,
				m_posLast,
				m_lFirst,
				m_lLast);
			str_msg = "Caudal Records are new";
		}

		return low;
	}

	if (getDateCode(m_lFirst) <= getDateCode(m_lLast))
	{
		if (m_lKey <= m_lFirst)
		{
			if (getDateCode(m_lKey) < getDateCode(m_lFirst) - 2)
			{
				/// 说明日志文件中所有的记录都是去年的
				low = m_size;
				str_msg = "All Records are last year's";
			}
			else
			{
				/// 说明日志文件首个时间戳已符合要求
				low = m_posFirst;
				str_msg = "All Records are new";
			}
		}
		else if (m_lKey <= m_lLast)
		{
			/// 常见情形，要在文件尾部向前找出最早的符合条件的位置
			low = find(
				m_lKey,
				blockSize,
				m_posFirst,
				m_posLast,
				m_lFirst,
				m_lLast);
			str_msg = "Caudal Records are new";
		}
		else
		{
			/// 日志中现有记录时间均过期，要找的位置于文件尾部
			low = m_size;
			str_msg = "All Records are too old";
		}
	}
	else	/// 可以认为存在有跨年的现象
	{
		if (m_lKey <= m_lLast)
		{
			/// 此情形较复杂，要在文件尾部向前找出最早的符合条件的位置
			low = find(
				m_lKey,
				blockSize,
				m_posFirst,
				m_posLast,
				m_lFirst,
				m_lLast);
			str_msg = "There are multi-year records, Caudal Records are new";
		}
		else
		{
			/// 日志中现有记录时间均过期，要找的位置于文件尾部
			low = m_size;
			str_msg = "There are multi-year records, All Records are too old";
		}
	}

	printf(
		"\n====FileRecordFinder====\n  LogFile[%s]\n  IntTime[%ld]\n  StrTime[%s]\n  SeekPos[%ld]\n  Message[%s]\n\n",
		m_filename,
		m_lKey,
		LongToDateString(m_lKey),
		low,
		str_msg.c_str());
	fflush(stdout);
	return low;
}
