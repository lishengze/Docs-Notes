/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	FileRecordFinder.cpp
///@brief	����һ��ʱ���ַ�����λ���ļ��еļ�¼λ��
///@history
///20080527	����		�������ļ�
///20120410	�̺״�		������־���괦����ƣ�ԭ���ϲ�֧�ֶ�ο���������
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
	/// ����ļ������ɱ�����򿪣����ڴ˴��ͷ��ļ����
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
			/// ��ǰΪ�׿��ִ�
			pos = getCompKey(szBuf, szTime, iTimeLen, POS_HEAD);
			bHead = false;
		}
		else
		{
			/// ��ǰΪ�������ִ�
			pos = getCompKey(szBuf, szTime, iTimeLen, POS_FIRST);
		}

		if (pos >= 0)
		{
			/// �õ���Ч��¼����λ��
			pos_offset += pos;
			pos_dest = pos_offset;
			return true;
		}
		else
		{
			/// �����α�����ƶ�
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
				/// �ҵ�Ŀ��ʱ�����¼,��ǰpos_dest��Ϊ�׸�Ŀ��ʱ���λ��
				return true;
			}
		}

		pos_offset += strlen(szBuf);
	}

	/// δ�ҵ�Ŀ��ʱ�����¼,��ǰpos_destΪ���������һ����Чʱ���λ��(����pos_low)
	return false;
}

// add by cao.ning
// ������ԭ�㷨�У������ֿ��꣬�����ķ��ص�һ����¼�����
// ���㷨��ʹ����ʱ���Ƚϣ������������жϼ�¼ʱ���Ƿ����Ŀ��ʱ��
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
		// ����ȡ�����ļ����ݰ��д洢
		// pair: offset, ������
		vector<pair<int, string> > LinesBuffer;

		size_t	pos_offset = pos_low;

		char* p = strtok(szBuff, "\n");
		LinesBuffer.push_back(make_pair(pos_offset, p));
		pos_offset += (strlen(p) + 1);	// \nռ��һ���ַ�

		while ((p = strtok(NULL, "\n")) != NULL)
		{
			LinesBuffer.push_back(make_pair(pos_offset, p));
			pos_offset += (strlen(p) + 1);
		}

		// ���ȡ��������ֻ��һ�У��ͷ�����һ�е�ƫ����
		if (LinesBuffer.size() <= 1)
		{
			pos_dest = pos_low;
			return true;
		}
		else
		{
			long lStartLineTime = DateStringToLong(LinesBuffer[0].second.c_str());
			long lEndLineTime = DateStringToLong(LinesBuffer[LinesBuffer.size() - 1].second.c_str());
			if (l_Time > lEndLineTime)	// buff�����м�¼��ʱ���С��Ŀ��ʱ��
			{
				// ƫ��������Ϊbuffβ��
				pos_dest = pos_high;
				return true;
			}
			else if (l_Time < lStartLineTime)	// buff�����м�¼��ʱ�������Ŀ��ʱ��
			{
				// ƫ��������Ϊbuff�ײ�
				pos_dest = pos_low;
				return true;
			}

			// �Ӻ���ǰ�Աȣ�����Ŀ��ʱ������˫��ʱ��Ĳ�ֵ������ǰһ�еĲ�ֵ���ں�һ��ʱ�����غ�һ�е�ƫ����
			// ��ֵʹ��unsigned������ֵ���ָ�ֵ��ͬ������
			vector<pair<int, string> >::iterator itBackLine = LinesBuffer.end() - 1, itFrontLine = itBackLine - 1;
			for (;itFrontLine >= LinesBuffer.begin(); --itBackLine, --itFrontLine)
			{
				// ���һ�е�ʱ���
				unsigned BackTimeOffset = DateStringToLong(itBackLine->second.c_str()) - l_Time;
				unsigned FrontTimeOffset = DateStringToLong(itFrontLine->second.c_str()) - l_Time;

				if (FrontTimeOffset > BackTimeOffset)
				{
					pos_dest = itBackLine->first;
					return true;
				}
			}
			// �����ʱ��δ�ҵ����ʵ�ʱ�䣬˵��buff�е�����ʱ�����Ŀ��ʱ����򷵻�buff�еĵ�һ��
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
			/// �õ���Ч��¼����λ��
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
	/// �޶�pos_offsetȡֵ����[pos_low, pos_high]
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
	/// �޶�pos_offsetȡֵ����[pos_low, pos_high]
	pos_offset = pos_offset < pos_low ? pos_low : (pos_offset > pos_high ? pos_high : pos_offset);

	/// pos_offset ǰ��
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

	/// �����ҵ����׵�һ�����������Ļ��з����û��з���ļ�¼��������ʱ�䴮�Ļ���Ҫ��
	while ((pPos = strchr(pCursor, '\n')) != NULL)
	{
		pPos++;
		if (IsValidDateTime(pPos))
		{
			pos = pPos - szBuf;
			memset(szTime, 0x00, iTimeLen);
			strncpy(szTime, pPos, iTimeLen - 1);
			if (POS_LAST != posType)
			{	// ������Ҫ�ҵ��׸�λ��ʱ�˳�
				break;
			}
		}

		pCursor = pPos;
	}

	return pos;
}

/// ����һ���ַ���
///@return -1 û���ҵ�
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
	return findNew(key, 2048, isSysLog);	// isSysLog��ʾ�������Ƿ�ΪSysLog�ļ�
}

///��ʼ���ļ��ߴ�Ͷ�λ�ļ�ָ�뵽��ʼλ��
///@return -1 ��ȡ�ļ��ߴ���Ϣʧ��
int CFileRecordFinder::init(void)
{
	if (m_fd == NULL)
	{
		/// Mod by Henchi, 20120407
				/// �ļ���ģʽ"r+"����Ϊ"r"
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
			/// ����ͨ��������ĩ����¼�ж���־�Ƿ���ڿ�������
						/// ��������¼���ڱ�ĩ����¼��־��2�����ϼ���Ϊ����
			char recFirst[LEN_DATATIME_STAMP];
			char recLast[LEN_DATATIME_STAMP];
			int recBufLen = LEN_DATATIME_STAMP;

			size_t	low = 0;
			size_t	high = m_size;
			size_t	offset;

			/// ��ȡ���䷶Χ���׸���Чʱ�����λ��
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

/// �ƶ��ļ�ָ�뵽�ض�λ��
void CFileRecordFinder::moveFilePoint(size_t pos)
{
	fseek(m_fd, pos, SEEK_SET);
}

long CFileRecordFinder::getDateCode(long lDatetime)
{
	return lDatetime >> 18;
}

/// Mod by Henchi, 20120410
/// �ع��˲��Ҽ�¼λ�õķ���������Կ��������֧��
/// �ҵ��ļ��е�Ŀ��λ��
size_t CFileRecordFinder::find(
	long l_key,
	size_t	blockSize,
	size_t	pos_low,		// ǰ����¼���ļ��ڵ�ƫ����
	size_t	pos_high,		// β����¼���ļ��ڵ�ƫ����
	long l_low,				// ǰ����¼��ʱ��ֵ
	long l_high)			// β����¼��ʱ��ֵ
{
	///������ȡ��¼�е�ʱ�䲿�ֵ�����
	char rec[LEN_DATATIME_STAMP];
	int recBufLen = sizeof(rec);

	size_t	pos_offset = 0; /// ����Ŀ��λ�õ�ƫ����
	size_t	pos_mid = 0;
	long l_mid = 0;

	/// ȷ��pos_lowʼ�ճɹ����ʱ���
	while ((pos_high - pos_low) > LEN_DATATIME_STAMP)	/// ��������ռ�
	{
		if ((pos_high - pos_low) < REC_BUF_SIZE)
		{
			/// �ѽ���С���鷶Χ��ֱ�����ж�ȡ����Ч
						/// �����Ƿ��ҵ�������pos_low��ʶĿ��λ��
			//getRecordPos(pos_low, pos_high, pos_offset, rec, recBufLen, l_key);
			getRecordPosNew(pos_low, pos_high, pos_offset, rec, recBufLen, l_key);
			pos_low = pos_offset;
			break;
		}

		pos_mid = pos_low + (pos_high - pos_low) / 2;	/// ��ȡ�м�λ��
						
				/// Ѱ�Ҵ˺��׸�ʱ���
		if (!getRecordPosL(
				pos_mid,
			pos_high,
			pos_offset,
			rec,
			recBufLen,
			false))
		{
			/// pos_offset ��Ч
						/// ��ǰpos_mid֮������ʱ�����Ϣ�����Խ�ƥ������ǰ��
			pos_high = pos_mid;
		}
		else
		{
			/// pos_offset ��Ч
						/// ��֪pos_mid֮����ʱ���
			l_mid = DateStringToLong(rec);
			if (l_mid > l_high)				// ˵���˴���Ϊȥ�����Ϣ�����Խ�ƥ���������
			{
				pos_low = pos_offset;
			}
			else if (l_mid == l_high)		// ��Ϊ�˴��ѽӽ�β��
			{
				if (l_key > l_mid)			// l_key > l_high
				{
					pos_low = pos_high;		// �������Ҳ���ƥ��ļ�¼��ƥ�����
					break;
				}
				else						// l_key <= l_mid
				{
					pos_high = pos_offset;	// ���Խ�ƥ������ǰ�ƣ������ڶ����������ʱ������ǰ�ƿ���ǰ�����Ǳ���ļ�¼�Σ�
				}
			}
			else	// l_mid < l_high	// ��Ϊ�˴��ѽӽ�Ŀ��λ��
			{
				if (l_key > l_mid)
				{
					pos_low = pos_offset;	// ���Խ�ƥ���������
				}
				else						// l_key <= l_mid
				{
					pos_high = pos_offset;	// ���Խ�ƥ������ǰ��
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

	///���ڴ�ż�¼�е�ʱ������
	char rec[LEN_DATATIME_STAMP];
	int recBufLen = sizeof(rec);

	size_t	low = 0;
	size_t	mid = 0;
	int pos = 0;

	/// ������̼�Ҫ˵����
		/// �����ļ���ʼ��ʱ�õ��ļ�������¼��ĩ����¼ʱ��ֵ
		/// �����ĩʱ�估Ŀ��ʱ����Ϣ��������ǰ��־���ݵĻ������
		/// ����:�Ƿ����? ��ȫƥ�䡢ȫ��ƥ�䣬���ǲ���ƥ��?
		/// ���ڲ���ƥ����������������
	if (m_lFirst == 0 || m_lLast == 0)
	{
		/// δ�ɹ���ȡ��ֹʱ�����Ϣ��������־��ʽ��������		
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
				/// ˵����־�ļ������еļ�¼����ȥ���
				low = m_size;
				str_msg = "All Records are last year's";
			}
			else
			{
				/// ˵����־�ļ��׸�ʱ����ѷ���Ҫ��
				low = m_posFirst;
				str_msg = "All Records are new";
			}
		}
		else if (m_lKey <= m_lLast)
		{
			/// �������Σ�Ҫ���ļ�β����ǰ�ҳ�����ķ���������λ��
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
			/// ��־�����м�¼ʱ������ڣ�Ҫ�ҵ�λ�����ļ�β��
			low = m_size;
			str_msg = "All Records are too old";
		}
	}
	else	/// ������Ϊ�����п��������
	{
		if (m_lKey <= m_lLast)
		{
			/// �����νϸ��ӣ�Ҫ���ļ�β����ǰ�ҳ�����ķ���������λ��
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
			/// ��־�����м�¼ʱ������ڣ�Ҫ�ҵ�λ�����ļ�β��
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

///�ж�һ��ʱ�����ڴ��ĸ�ʽ�Ƿ�Ϸ�
///�ִ�����[Jun 03 13:38:56]��Ϊ�Ϸ�
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

///��һ������[Jun 03 13:38:56]��ʱ�䴮ת��Ϊһ������
///month|day|hour|minute|second
///4bits|5bits|5bits|6bits|6bits = 26bits
///bits: 6|6|6|6|6 = 30bits final design
///@return 0 ˵��û���ܹ���ȷ�Ľ�����ʱ��
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
			printf("�������ʱ�䴮����ȷ\n");
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

// isSysLogָ���˸��ļ��Ƿ�ΪSysLog�ļ�
// ��ΪSysLog�ļ�����key��ʾ���ǽ������ʼʱ��
// �����ļ���������������ļ�¼
long CFileRecordFinder::findNew( long key, size_t blockSize, bool isSysLog )
{
	m_lKey = key;

	long cur;
	int bufSize = 2048;
	char buf[2048];
	string	str_msg;

	///���ڴ�ż�¼�е�ʱ������
	char rec[LEN_DATATIME_STAMP];
	int recBufLen = sizeof(rec);

	size_t	low = 0;
	size_t	mid = 0;
	int pos = 0;

	/// ������̼�Ҫ˵����
	/// �����ļ���ʼ��ʱ�õ��ļ�������¼��ĩ����¼ʱ��ֵ
	/// �����ĩʱ�估Ŀ��ʱ����Ϣ��������ǰ��־���ݵĻ������
	/// ����:�Ƿ����? ��ȫƥ�䡢ȫ��ƥ�䣬���ǲ���ƥ��?
	/// ���ڲ���ƥ����������������
	if (m_lFirst == 0 || m_lLast == 0)
	{
		/// δ�ɹ���ȡ��ֹʱ�����Ϣ��������־��ʽ��������		
		printf(
			"\n====FileRecordFinder====\n  LogFile[%s]\n  Message[%s]\n",
			m_filename,
			"No Records found");
		return -1;
	}

	// ˵����
	// SysLog�ļ��У����µļ�¼ֻ���ǽ���ġ������ܷ�������д������ļ�¼
	// ��˿���ͨ��SysLog����һ�ص�򵥵��ж��ļ������Ƿ�¾�
	// Ҳ����˵�����SysLogβ���ļ�¼������ǽ���ģ���ô����Ϊ�ļ��ǳ¾ɵ�
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
				/// ˵����־�ļ������еļ�¼����ȥ���
				low = m_size;
				str_msg = "All Records are last year's";
			}
			else
			{
				/// ˵����־�ļ��׸�ʱ����ѷ���Ҫ��
				low = m_posFirst;
				str_msg = "All Records are new";
			}
		}
		else if (m_lKey <= m_lLast)
		{
			/// �������Σ�Ҫ���ļ�β����ǰ�ҳ�����ķ���������λ��
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
			/// ��־�����м�¼ʱ������ڣ�Ҫ�ҵ�λ�����ļ�β��
			low = m_size;
			str_msg = "All Records are too old";
		}
	}
	else	/// ������Ϊ�����п��������
	{
		if (m_lKey <= m_lLast)
		{
			/// �����νϸ��ӣ�Ҫ���ļ�β����ǰ�ҳ�����ķ���������λ��
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
			/// ��־�����м�¼ʱ������ڣ�Ҫ�ҵ�λ�����ļ�β��
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
