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
#define MAX_BUF_SIZE	10240	// �л�������С
#define CHAR_SPACE		0x20	// �ո��
#define CHAR_TAB		0X09	// �Ʊ��

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
	NullLine		// �Ƿ���Կ���
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

// CCompareMode�ඨ�����ļ��Ƚϵ�ģʽ
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
			// ת�����ʽ�е�'*'��Ϊ'%s'
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

// CFileLine�������ļ��е����ݽṹ��
class CFileLine
{
	/* */
	protected:
		long m_lRawLineNo;		// �����¼λ��ԭ�ı��ļ��е��к�
		long m_lCmpLineNo;		// �����¼���ڶԱȴ�ӡ���ʱ��ʵ���о�
		string	m_strRawLine;	// ����ԭ�ı��м�¼
		string	m_strCmpLine;	// ���澭���ӹ������ڶԱȵ��м�¼
		long m_lToken;			// �Աȴ������㷨��ȡ��Tokenֵ,���ڳ�����ٶԱ�
		LineMode m_LineMode;	// ������ļ��еĶԱȽ���״̬
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

// CFilePartition�������ļ��Ա����������е��ļ����ݶ�

// �为������ı��ļ�,����ϱȽ�ģʽ���м�¼����ת��,�õ�ת������ı���
class CFilePartition
{
	/* */
	public:
		string	m_strFileName;	// �����ļ�·����
		long m_lLineCount;		// �����ļ�����
		vec_line m_vLines;		// �����ļ��м�¼
		vec_long m_vTokens;		// ����ÿһ�е�tokenֵ,���ڿ��ټ���

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
// ԭʼ���ļ��洢��ʽ���ʺ�LD�㷨���˴������µ��ļ��洢��ʽ
// ���ļ�ƥ����ɺ󣬻Ὣ�µĴ洢��ʽӳ�䵽ԭ���Ĵ洢��ʽ��
typedef struct LDMatrixValue
{
	LDMatrixValue(): m_Value(0), m_Equal(false){}
	int m_Value;
	bool m_Equal;
} LDMatrixValue;

// ���ݷ���
#define BACKTO_LEFT_TOP 1	// ����
#define BACKTO_LEFT 2		// ��
#define BACKTO_TOP 3		// ��
// CCompareEngine������ı��Ƚϵ�ʵ�ʹ���

// �����ı�ת��,�Աȼ���,�õ��ԱȽ��...
class CCompareEngine
{
	/* */
	public:
		CFilePartition	*m_pFile1;
		CFilePartition	*m_pFile2;
		int m_iStatus;	// ���浱ǰ�ȽϽ��
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
			m_iStatus = -2; // δ�����ļ��Ƚ�
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
		// �µĻ����е��ı��Ƚ��㷨��Levenshtein distance�㷨
		// �ο���http://en.wikipedia.org/wiki/Levenshtein_distance
		// ����ʵ�ַ�ʽ��鿴�ĵ�
		int DoLDCompare(void);

private:
	/* Levenshtein distance�㷨 */

	// �ı�����Ԥ����
	void PreProcessFile(int &StartPoint);

	// �������ļ�����LD���㣬����ָ���˼���λ��
	// ������ɺ������´μ���λ��
	void DoLevenshteinDistance(int &nStartPoint);

	// �ļ��жԱ�
	bool CompareLines(int nLineNo_file1, int nLineNo_file2);
};

// CFileDiff���ǻ����ı��ļ��ȽϵĹ�����

// ����:�ļ��� �Ա�ѡ�� ����������ʽ ��...

// ���:�ȽϽ��
class CFileDiff
{
	/* */
	public:
		CFileDiff(void)
		{
			m_iStatus = -2; // δ�����ļ��Ƚ�
		}

		~CFileDiff(void)
		{
		}

		// ������Ҫ���жԱȵ��ļ�
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

		// �ļ��Ƚ�,����ֵ: -1 �ȽϹ��̷����쳣; 0 �����ļ���ͬ; N �ļ��д�����N�в���
		int Compare(void);

		// ��ӡ�ȽϽ������
		void Show(void);

	/* */
	public:
		CCompareMode m_CompMode;
		CCompareEngine	m_CompEngine;
		string	m_strFile1; // ����Ƚ��ļ���1
		string	m_strFile2; // ����Ƚ��ļ���2
		int m_iStatus;		// ���浱ǰ�ȽϽ��
};
