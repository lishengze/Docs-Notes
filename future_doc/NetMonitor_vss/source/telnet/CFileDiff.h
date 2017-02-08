#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define PRINT_DEBUG
#undef PRINT_DEBUG
#define MAX_BUF_SIZE	10240	// 行缓冲区大小
#define CHAR_SPACE		0x20	// 空格键
#define CHAR_TAB		0X09	// 制表符

//#define ASSERT_VALID_PSZ(x) assert(x != NULL && strlen(x) >0)
#define ASSERT_VALID_PSZ(x)		assert(x != NULL)
#define ASSERT_LESS_THAN(x, y)	assert(x < y)
#define RELEASE_POINTER(x) \
	if (x != NULL)		   \
	{					   \
		delete x;		   \
		x = NULL;		   \
	}

typedef vector<string>	vec_str;
typedef vector<string>::iterator vec_str_it;
typedef vector<long> vec_long;
typedef vector<long>::iterator	vec_long_it;
typedef map<string, int> map_str_int;
typedef map<string, int>::iterator	map_str_int_it;
typedef enum
{
	Normal	= 0,
	Ignored,
	Changed,
	Added,
	Deleted
} LineMode;
typedef enum
{
	Valide	= 0,
	Invalide
} CaseMode;
typedef enum
{
	None	= 0,
	Head,
	Tail,
	Both,
	All,
	NullLine		// 是否忽略空行
} SpaceMode;

inline bool IsBlankChar(char c)
{
	return c == CHAR_SPACE || c == CHAR_TAB;
}

inline char toLower(char c)
{
	return (c >= 65 && c <= 90) ? c + 32 : c;
}

class CCompareMode;
class CCompareEngine;
class CFileDiff;
class CFileLine;
class CFilePartition;

#define ASSERT_VALID_PFL(x) assert(x != NULL)
#define ASSERT_VALID_PFP(x) \
	assert(					\
		x != NULL && x->m_lLineCount == x->m_vLines.size())
typedef vector<CFileLine *> vec_line;
typedef vector<CFileLine *>::iterator vec_line_it;

// CCompareMode类定义了文件比较的模式
class CCompareMode
{
	/* */
	public:
		CCompareMode(void)
		{
			UseDefault();
		}

		~CCompareMode(void)
		{
		}

		void SetCaseMode(CaseMode cm)
		{
			casemode = cm;
		}

		void SetSpaceMode(SpaceMode sm)
		{
			spacemode = sm;
		}

		CaseMode GetCaseMode(void)
		{
			return casemode;
		}

		SpaceMode GetSpaceMode(void)
		{
			return spacemode;
		}

		void UseDefault(void)
		{
			casemode = Invalide;
			spacemode = All;
			regexp.clear();
		}

		void AddRegExp(string exp)
		{
			// 转换表达式中的'*'号为'%s'
			string	strTmp = "";
			int iCount = 0;
			for (string::iterator it = exp.begin(); it != exp.end(); it++)
			{
				if ((*it) != '*')
				{
					strTmp.append(1, (char) *it);
				}
				else
				{
					strTmp.append("%s");
					iCount++;
				}
			}

			regexp[strTmp] = iCount;
		}

		map_str_int &GetRegExp(void)
		{
			return regexp;
		}

	/* */
	private:
		CaseMode casemode;
		SpaceMode spacemode;
		map_str_int regexp;
};

// CFileLine定义了文件行的数据结构体
class CFileLine
{
	/* */
	protected:
		long m_lRawLineNo;		// 保存记录位于原文本文件中的行号
		long m_lCmpLineNo;		// 保存记录用于对比打印输出时的实际行距
		string	m_strRawLine;	// 保存原文本行记录
		string	m_strCmpLine;	// 保存经过加工后用于对比的行记录
		long m_lToken;			// 对比串经过算法获取的Token值,用于初查快速对比
		LineMode m_LineMode;	// 保存此文件行的对比结束状态
		void Init(void)
		{
			m_lRawLineNo = 0;
			m_lCmpLineNo = 0;
			m_strRawLine = "";
			m_strCmpLine = "";
			m_lToken = 0;
			m_LineMode = Normal;
		}

	/* */
	public:
		CFileLine(void)
		{
			Init();
		}

		~CFileLine(void)
		{
		}

		CFileLine(char *pszLine, CCompareMode &CompMode);

		void SetRawString(char *p)
		{
			ASSERT_VALID_PSZ(p);
			m_strRawLine = p;
		}

		string GetRawString(void)
		{
			return m_strRawLine;
		}

		void SetCmpString(char *p)
		{
			ASSERT_VALID_PSZ(p);
			m_strCmpLine = p;
		}

		string GetCmpString(void)
		{
			return m_strCmpLine;
		}

		void SetLineMode(LineMode mode)
		{
			m_LineMode = mode;
		}

		LineMode GetLineMode(void)
		{
			return m_LineMode;
		}

		long GetToken(void)
		{
			return m_lToken;
		}

		void SetRawLineNo(long no)
		{
			m_lRawLineNo = no;
		}

		long GetRawLineNo(void)
		{
			return m_lRawLineNo;
		}

		void SetCmpLineNo(long no)
		{
			m_lCmpLineNo = no;
		}

		long GetCmpLineNo(void)
		{
			return m_lCmpLineNo;
		}

		void SetStatus(LineMode mode, long offset)
		{
			if (m_LineMode != Ignored)
			{
				m_LineMode = mode;
			}

			m_lCmpLineNo = m_lRawLineNo + offset;
		}

		bool MatchRegExp(string line, map_str_int &regexp);
};

// CFilePartition保存了文件对比增长过程中的文件数据段

// 其负责加载文本文件,并结合比较模式对行记录进行转化,得到转化后的文本行
class CFilePartition
{
	/* */
	public:
		string	m_strFileName;	// 保存文件路径名
		long m_lLineCount;		// 保存文件行数
		vec_line m_vLines;		// 保存文件行记录
		vec_long m_vTokens;		// 保存每一行的token值,用于快速检索

	/* */
	protected:
		void Init(void)
		{
			m_strFileName = "";
			m_lLineCount = 0;
		}

		void Release(void)
		{
			for (vec_line_it it = m_vLines.begin(); it != m_vLines.end(); it++)
			{
				delete *it;
			}

			m_vLines.clear();
			m_vTokens.clear();
		}

		void AddString(char *pszLine, CCompareMode &CompMode);

	/* */
	public:
		CFilePartition(void)
		{
			Init();
		}

		~CFilePartition(void)
		{
			Release();
		}

		void Reset(void)
		{
			Release();
			Init();
		}

		LineMode GetLineMode(long lLineNo)
		{
			ASSERT_LESS_THAN(lLineNo, m_lLineCount);
			return m_vLines[lLineNo]->GetLineMode();
		}

		bool LoadFile(const char *pszFileName, CCompareMode &CompMode);
		bool MatchLine(long lLineNo1, CFilePartition *pFile2, long &lLineNo2);
		void SetLineStatus(long lLineNo, LineMode mode, long offset);
};

// add by cao.ning
// 原始的文件存储方式不适合LD算法，此处定义新的文件存储方式
// 在文件匹配完成后，会将新的存储方式映射到原来的存储方式上
typedef struct LDMatrixValue
{
	LDMatrixValue(): m_Value(0), m_Equal(false){}
	int m_Value;
	bool m_Equal;
} LDMatrixValue;

// 回溯方向
#define BACKTO_LEFT_TOP 1	// 左上
#define BACKTO_LEFT 2		// 左
#define BACKTO_TOP 3		// 上
// CCompareEngine类完成文本比较的实际功能

// 包括文本转化,对比检索,得到对比结果...
class CCompareEngine
{
	/* */
	public:
		CFilePartition	*m_pFile1;
		CFilePartition	*m_pFile2;
		int m_iStatus;	// 保存当前比较结果
		int m_iAdded;
		int m_iDeleted;
		int m_iChanged;
		int m_iAddedIgnore;
		int m_iDeletedIgnore;
		int m_iChangedIgnore;

	/* */
	protected:
		void Reset(void)
		{
			m_iStatus = -2; // 未进行文件比较
			m_iAdded = 0;
			m_iDeleted = 0;
			m_iChanged = 0;
			m_iAddedIgnore = 0;
			m_iDeletedIgnore = 0;
			m_iChangedIgnore = 0;
		}

	/* */
	public:
		CCompareEngine(void)
		{
			Reset();
			m_pFile1 = new CFilePartition();
			m_pFile2 = new CFilePartition();
		}

		~CCompareEngine(void)
		{
			RELEASE_POINTER(m_pFile1);
			RELEASE_POINTER(m_pFile2);
		}

		bool InitTask(
		string	&FileName1,
		string	&FileName2,
		CCompareMode &CompMode)
		{
			Reset();
			m_pFile1->Reset();
			m_pFile2->Reset();

			return m_pFile1->LoadFile(FileName1.c_str(), CompMode)
			&&	m_pFile2->LoadFile(FileName2.c_str(), CompMode);
		}

		int DoCompare(void);
		void Dump(void);

		// add by cao.ning
		// 新的基于行的文本比较算法，Levenshtein distance算法
		// 参考：http://en.wikipedia.org/wiki/Levenshtein_distance
		// 具体实现方式请查看文档
		int DoLDCompare(void);

private:
	/* Levenshtein distance算法 */

	// 文本内容预处理
	void PreProcessFile(int &StartPoint);

	// 对两个文件进行LD计算，参数指明了计算位置
	// 计算完成后会更新下次计算位置
	void DoLevenshteinDistance(int &nStartPoint);

	// 文件行对比
	bool CompareLines(int nLineNo_file1, int nLineNo_file2);
};

// CFileDiff类是基于文本文件比较的工具类

// 输入:文件名 对比选项 过滤正则表达式 等...

// 输出:比较结果
class CFileDiff
{
	/* */
	public:
		CFileDiff(void)
		{
			m_iStatus = -2; // 未进行文件比较
		}

		~CFileDiff(void)
		{
		}

		// 设置需要进行对比的文件
		void SetFiles(const char *pszFile1, const char *pszFile2);

		void SetCaseMode(CaseMode cm)
		{
			m_CompMode.SetCaseMode(cm);
		}

		void SetSpaceMode(SpaceMode sm)
		{
			m_CompMode.SetSpaceMode(sm);
		}

		void AddRegExp(string exp)
		{
			m_CompMode.AddRegExp(exp);
		}

		// 文件比较,返回值: -1 比较过程发生异常; 0 两个文件相同; N 文件中存在有N行差异
		int Compare(void);

		// 打印比较结果序列
		void Show(void);

	/* */
	public:
		CCompareMode m_CompMode;
		CCompareEngine	m_CompEngine;
		string	m_strFile1; // 保存比较文件名1
		string	m_strFile2; // 保存比较文件名2
		int m_iStatus;		// 保存当前比较结果
};
