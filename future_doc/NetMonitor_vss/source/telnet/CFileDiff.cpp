#include "CFileDiff.h"

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

// CFileLine ---
CFileLine::CFileLine(char *pszLine, CCompareMode &CompMode)
{
	// ��ɵļ�¼�е����ݼ��ؼ�ת��...
	// ת����ʽ ���������ձȽϽ��
	Init();
	if (strlen(pszLine) == 0)
	{
		if (CompMode.GetSpaceMode() == NullLine)
			throw 0;
		return;
	}

	m_strRawLine = pszLine;			// ����ԭʼ��¼
	char szBuf[MAX_BUF_SIZE] = "";
	char *p = pszLine;
	int iLength = strlen(pszLine);
	int iPos = 0;
	bool bIsIndentation = true;
	m_lToken = 0;

	// ���������β�հ�,���ִ�β���հ�����ȥ��
	if (CompMode.GetSpaceMode() >= Tail)
	{
		for (int i = iLength; i > 0; i--)
		{
			if (!IsBlankChar(*p + i - 1))
			{
				break;
			}
			else
			{
				// ��β�Ŀհ��ַ�ȫ���ÿ�,�������ִ����ȷ����仯
				*(p + i - 1) = 0x00;
			}
		}
	}

	// �ִ����ȿ��ܷ����仯
	iLength = strlen(pszLine);

	for (int i = 0; i < iLength; i++, p++)
	{
		// �������հ��ַ�
		if (IsBlankChar(*p))
		{
			if (CompMode.GetSpaceMode() == All)
			{
				// �������еĿհ��ַ�
				continue;
			}

			if (bIsIndentation
			&&	CompMode.GetSpaceMode() != None
			&&	CompMode.GetSpaceMode() != Tail)
			{
				// ������Щ�����ַ�
				continue;
			}
		}
		else
		{
			bIsIndentation = false; // �������������
		}

		// ���ַ�����Ƚ�Ԫ����,ͬʱ����Tokenֵ...
		if (CompMode.GetCaseMode() == Invalide)
		{					// �����ִ�Сд
			szBuf[iPos] = toLower(*p);
		}
		else
		{
			szBuf[iPos] = *p;
		}

		m_lToken += 2 * m_lToken +*p;
		iPos++;
	}

	if (CompMode.GetSpaceMode() == NullLine && strlen(szBuf) == 0)
	{
		throw 0;
		return;
	}

	szBuf[iPos] = 0x00;		// ��ӽ�����
	m_strCmpLine = szBuf;	// ���ת������ִ�����

	// ���� �ִ��Ƿ�ƥ�����������ʽ
	// ��ƥ��: �ִ�ԭ������,״̬���ΪIgnored;
	if (MatchRegExp(m_strRawLine, CompMode.GetRegExp()))
	{
		m_LineMode = Ignored;
	}
}

bool CFileLine::MatchRegExp(string line, map_str_int &regexp)
{
	int i = 1;

	int iMatch;
	char szTmp[256];
	for (map_str_int_it it = regexp.begin(); it != regexp.end(); it++, i++)
	{
		if (it->second <= 0)
		{
			// ��ͨ���,�����ִ�ȫƥ��
			if (line.compare(it->first) == 0)
			{
				return true;
			}
		}
		else
		{
			// ����ͨ���ƥ��,���֧��10��ͨ���
			if ((
					iMatch = sscanf(
					line.c_str(),
				it->first.c_str(),
				szTmp,
				szTmp,
				szTmp,
				szTmp,
				szTmp,
				szTmp,
				szTmp,
				szTmp,
				szTmp,
				szTmp)
		) == it->second)
			{
				return true;
			}
		}
	}

	return false;
}

// --- CFileLine

// CFilePartition ---
bool CFilePartition::LoadFile(const char *pszFileName, CCompareMode &CompMode)
{
	ASSERT_VALID_PSZ(pszFileName);

	FILE *fpFile = fopen(pszFileName, "r");
	if (fpFile == NULL)
	{
		return false;
	}

	m_strFileName = pszFileName;

	char szBuf[MAX_BUF_SIZE] = "";
	while (fgets(szBuf, MAX_BUF_SIZE, fpFile))
	{
		if (szBuf[strlen(szBuf) - 1] == '\n')
		{
			szBuf[strlen(szBuf) - 1] = 0x00;	// ɾ����β���з�
		}

		if (szBuf[strlen(szBuf) - 1] == '\r')
		{
			szBuf[strlen(szBuf) - 1] = 0x00;	// ɾ����β���з�
		}

		AddString(szBuf, CompMode);
	}

	fclose(fpFile);
	return m_vLines.size() == m_vTokens.size() ? true : false;
}

void CFilePartition::SetLineStatus(long lLineNo, LineMode mode, long offset)
{
	ASSERT_LESS_THAN(lLineNo, m_lLineCount);
	m_vLines[lLineNo]->SetStatus(mode, offset);
}

void CFilePartition::AddString(char *pszLine, CCompareMode &CompMode)
{
	ASSERT_VALID_PSZ(pszLine);

	CFileLine *pFileLine;
	try
	{
		pFileLine = new CFileLine(pszLine, CompMode);
	}
	catch (...)
	{
		pFileLine = NULL;
		return;
	}

	ASSERT_VALID_PFL(pFileLine);
	pFileLine->SetRawLineNo(m_lLineCount++);

	m_vLines.push_back(pFileLine);
	m_vTokens.push_back(pFileLine->GetToken());

#ifdef PRINT_DEBUG
	//	printf("[Line%03d]:%s\n", m_lLineCount, pFileLine->GetRawString().c_str());
	//	printf("[Convert]:%s\n", pFileLine->GetCmpString().c_str());
	//	printf("Token:%ld\n\n", pFileLine->GetToken());
#endif
}

bool CFilePartition::MatchLine(
	long lLineNo1,
	CFilePartition	*pFile2,
	long &lLineNo2)
{
	ASSERT_VALID_PFP(pFile2);
	if (lLineNo1 >= m_lLineCount || lLineNo2 >= pFile2->m_lLineCount)
	{
		return false;
	}

	for (long lLineNo = lLineNo2; lLineNo < pFile2->m_lLineCount; lLineNo++)
	{
		//		if (pFile2->GetLineMode(lLineNo) == Ignored)
		//			continue;
		if (pFile2->m_vTokens[lLineNo] == m_vTokens[lLineNo1])
		{
			string	strLine = m_vLines[lLineNo1]->GetCmpString();
			if (strLine.compare(pFile2->m_vLines[lLineNo]->GetCmpString()) == 0)
			{
				lLineNo2 = lLineNo;
				return true;
			}
		}
	}

	return false;
}

// --- CFilePartition

// CCompareEngine ---
int CCompareEngine::DoCompare(void)
{
	// �ı��ļ��Ƚϵĺ����㷨
	// �ڲ����õ�Token��ת���ִ����ѵõ�...
	long nFileLines1 = m_pFile1->m_lLineCount;
	long nFileLines2 = m_pFile2->m_lLineCount;
	long nCurrLineNo1 = 0;
	long nCurrLineNo2 = 0;

	// ���ļ�1Ϊ��ʱ,���ļ�2�Ƿ�Ϊ��,2�ǿ�ʱ,��������ȫΪAdded״̬
	if (nFileLines1 == 0)
	{
		for (nCurrLineNo2 = 0; nCurrLineNo2 < nFileLines2; nCurrLineNo2++)
		{
			m_pFile2->SetLineStatus(nCurrLineNo2, Added, m_iDeleted);
			m_iAdded++;
			if (m_pFile2->GetLineMode(nCurrLineNo2) == Ignored)
			{
				m_iAddedIgnore++;
			}
		}
	}
	else
	{
		// ���ļ�1Ϊ��׼���Ա������ļ�
		for (nCurrLineNo1 = 0;
			 nCurrLineNo1 < nFileLines1;
			 nCurrLineNo1++, nCurrLineNo2++)
		{
			// �ļ�2�е����α�
			long nLineNo2 = nCurrLineNo2;

			// ���ļ�2Ϊ�� ��
			// �ļ�2�Ѿ�ɨ����ɣ��ļ�1��û�����ƥ�䣬�ļ�1��ʣ���ֶ�ȫ�����ΪDeleted.
			if (nLineNo2 >= nFileLines2)
			{
				for (; nCurrLineNo1 < nFileLines1; nCurrLineNo1++)
				{
					m_pFile1->SetLineStatus(nCurrLineNo1, Deleted, m_iAdded);
					m_iDeleted++;
					if (m_pFile1->GetLineMode(nCurrLineNo1) == Ignored)
					{
						m_iDeletedIgnore++;
					}
				}

				break;
			}

			// �ļ�1�ĵ�ǰ���Ƿ������ļ�2���ҵ�ƥ��
			// ���ҵ������ļ�2�и����кż�¼��nLineNo2�з���
			// ��δ�ҵ������ļ�2�е�ǰ�����ļ�1�Ա�Ѱ��ƥ����
			if (m_pFile1->MatchLine(nCurrLineNo1, m_pFile2, nLineNo2))
			{
				// �ļ�2�з���ƫ��,֮ǰ��ƫ����ȫ��Ϊ��������...
				for (; nCurrLineNo2 < nLineNo2; nCurrLineNo2++)
				{
					m_pFile2->SetLineStatus(nCurrLineNo2, Added, m_iDeleted);
					m_iAdded++;
					if (m_pFile2->GetLineMode(nCurrLineNo2) == Ignored)
					{
						m_iAddedIgnore++;
					}
				}

				m_pFile2->SetLineStatus(nCurrLineNo2, Normal, m_iDeleted);
				m_pFile1->SetLineStatus(nCurrLineNo1, Normal, m_iAdded);
			}
			else
			{
				// ����¼���ļ�2��û���ҵ�ƥ����
				// ���������ļ�1�����ļ�2�еĵ�ǰ����..
				// ����ҵ�,˵���ļ�1�������б�ɾ����
				// ���û���ҵ�,˵���ļ������˱仯,˫������¼ΪChanged ...
				long nLineNo1 = nCurrLineNo1;
				if (m_pFile2->MatchLine(nCurrLineNo2, m_pFile1, nLineNo1))
				{
					for (; nCurrLineNo1 < nLineNo1; nCurrLineNo1++)
					{
						m_pFile1->SetLineStatus(
								nCurrLineNo1,
								Deleted,
								m_iAdded);
						m_iDeleted++;
						if (m_pFile1->GetLineMode(nCurrLineNo1) == Ignored)
						{
							m_iDeletedIgnore++;
						}
					}

					m_pFile2->SetLineStatus(nCurrLineNo2, Normal, m_iDeleted);
					m_pFile1->SetLineStatus(nCurrLineNo1, Normal, m_iAdded);
				}
				else
				{
					m_pFile2->SetLineStatus(nCurrLineNo2, Changed, m_iDeleted);
					m_pFile1->SetLineStatus(nCurrLineNo1, Changed, m_iAdded);
					m_iChanged++;

					// ����˫����ΪIgnoredʱ,�˸ı佫������
					if (m_pFile1->GetLineMode(nCurrLineNo1) == Ignored
					&&	m_pFile2->GetLineMode(nCurrLineNo2) == Ignored)
					{
						m_iChangedIgnore++;
					}
				}
			}
		}

		// ���ļ��������ɨ�裬���ļ�2û��ɣ����ļ�2��ʣ���ֶ�ȫ�����ΪAdded״̬
		for (; nCurrLineNo2 < nFileLines2; nCurrLineNo2++)
		{
			m_pFile2->SetLineStatus(nCurrLineNo2, Added, m_iDeleted);
			m_iAdded++;
			if (m_pFile2->GetLineMode(nCurrLineNo2) == Ignored)
			{
				m_iAddedIgnore++;
			}
		}
	}

	m_iAdded -= m_iAddedIgnore;
	m_iChanged -= m_iChangedIgnore;
	m_iDeleted -= m_iDeletedIgnore;
	m_iStatus = m_iAdded + m_iDeleted + m_iChanged;
	return m_iStatus;
}

void CCompareEngine::Dump(void)
{
	printf(
		"There are total %d diffs: %d added, %d deleted, %d changed\n",
		m_iStatus,
		m_iAdded,
		m_iDeleted,
		m_iChanged);

#ifdef PRINT_DEBUG
	printf("\n\n===============================================\n\n");

	long lTotalLines = m_pFile1->m_lLineCount + m_iDeleted;
	long lLineNo1;
	long lLineNo2;
	for (int i = 0, j = 0, k = 0; i < lTotalLines; i++)
	{
		if (j < m_pFile1->m_lLineCount)
		{
			lLineNo1 = m_pFile1->m_vLines[j]->GetCmpLineNo();
		}

		if (k < m_pFile2->m_lLineCount)
		{
			lLineNo2 = m_pFile2->m_vLines[k]->GetCmpLineNo();
		}

		if (lLineNo1 == i && lLineNo2 == i)
		{
			// ͬʱ������ļ�
			CFileLine *pFileLine1 = m_pFile1->m_vLines[j];
			CFileLine *pFileLine2 = m_pFile2->m_vLines[k];
			printf(
				"[++%04ld]%04ld  %02d  %-90s | %04ld  %02d  %-90s\n",
				i,
				pFileLine1->GetRawLineNo(),
				pFileLine1->GetLineMode(),
				pFileLine1->GetRawString().c_str(),
				pFileLine2->GetRawLineNo(),
				pFileLine2->GetLineMode(),
				pFileLine2->GetRawString().c_str());
			j++;
			k++;
		}
		else if (lLineNo1 == i && lLineNo2 != i)
		{
			// ������ļ�1����,�ļ�2����
			CFileLine *pFileLine1 = m_pFile1->m_vLines[j];
			printf(
				"[+-%04ld]%04ld  %02d  %-90s |  --\n",
				i,
				pFileLine1->GetRawLineNo(),
				pFileLine1->GetLineMode(),
				pFileLine1->GetRawString().c_str());
			j++;
		}
		else if (lLineNo1 != i && lLineNo2 == i)
		{
			// ������ļ�2����,�ļ�1����
			CFileLine *pFileLine2 = m_pFile2->m_vLines[k];
			printf(
				"[-+%04ld] --                                                                                                  | %04ld  %02d  %-90s\n",
				i,
				pFileLine2->GetRawLineNo(),
				pFileLine2->GetLineMode(),
				pFileLine2->GetRawString().c_str());
			k++;
		}
	}

#endif
}

// add by cao.ning
// �µĻ����е��ı��Ƚ��㷨��Levenshtein distance�㷨
int CCompareEngine::DoLDCompare( void )
{


	// ������ļ��У��κ�һ���ļ�������С��1����ִ��ԭ�����㷨
	if (m_pFile1->m_lLineCount <= 1 || m_pFile2->m_lLineCount <= 1)
	{
		return DoCompare();
	}

	// ����λ��
	int nStartPoint = 0;
	
	// ���ļ�����Ԥ����
	PreProcessFile(nStartPoint);

//	while (nStartPoint < LineCount_file1 
//		&& nStartPoint < LineCount_file2)
	{
		DoLevenshteinDistance(nStartPoint);
	}
/*
	// ���ļ�1�����������ļ�2��β����Ӷ�Ӧ�����Ŀ���
	int nFileEnd = nStartPoint + 1;
	for (; nFileEnd < m_vFile1Lines.size(); nFileEnd++)
	{
		CLdLine* NullLine = NULL;
		m_vFile2Lines.insert(m_vFile2Lines.end() - 1, NullLine);
	}

	// ���ļ�2�����������ļ�1��β����Ӷ�Ӧ�����Ŀ���
	for (; nFileEnd < m_vFile2Lines.size(); ++nFileEnd)
	{
		CLdLine* NullLine = NULL;
		m_vFile1Lines.insert(m_vFile1Lines.end() - 1, NullLine);
	}
	*/

	vec_line &m_vFile1Lines = m_pFile1->m_vLines;
	vec_line &m_vFile2Lines = m_pFile2->m_vLines;
	// ���ݵõ����ļ�����Ϣ���任Ϊԭʼ������Ϣ
	// ��ʱ���ļ�1���ļ�2�������Ѿ���ͬ
	for (int i = 0; i < m_vFile1Lines.size(); ++i)
	{
		// ���ļ�1Ϊԭʼ�汾
		// ���ļ�1����˿��У���ʾ��Ӧ���Ǳ���ӵ�
		// ���ļ�2����˿��У���ʾ��Ӧ���Ǳ�ɾ����
		// ����
		// �ļ�1�� A A [] B C  D E
		// �ļ�2�� A A C  B [] D E
		// C��ӵ����ļ���A��B֮���λ�ã�ͬ��B֮���C��ɾ����
		if (m_vFile1Lines[i] == NULL)
		{
			CFileLine* LineFile2 = m_vFile2Lines[i];
			LineFile2->SetStatus(Added, m_iDeleted);
			m_iAdded++;
			if (LineFile2->GetLineMode() == Ignored)
			{
				m_iAddedIgnore++;
			}
		}
		else if (m_vFile2Lines[i] == NULL)
		{
			CFileLine* LineFile1 = m_vFile1Lines[i];
			LineFile1->SetStatus(Deleted, m_iAdded);
			m_iDeleted++;
			if (LineFile1->GetLineMode() == Ignored)
			{
				m_iDeletedIgnore++;
			}
		}
		else
		{
			CFileLine* LineFile1 = m_vFile1Lines[i];
			CFileLine* LineFile2 = m_vFile2Lines[i];
			if (!CompareLines(i, i))
			{
				LineFile1->SetStatus(Changed, m_iAdded);
				LineFile2->SetStatus(Changed, m_iDeleted);
				m_iChanged++;

				if (LineFile1->GetLineMode() == Ignored && LineFile2->GetLineMode() == Ignored)
				{
					m_iChangedIgnore++;
				}
			}
			else
			{
				LineFile1->SetStatus(Normal, m_iAdded);
				LineFile2->SetStatus(Normal, m_iDeleted);
			}
		}
	}

	// ɾ������
	for (vec_line::iterator itLine = m_vFile1Lines.begin();itLine != m_vFile1Lines.end();)
	{
		if ((*itLine) == NULL)
			itLine = m_vFile1Lines.erase(itLine);
		else
			++itLine;
	}
	for (vec_line::iterator itLine = m_vFile2Lines.begin();itLine != m_vFile2Lines.end();)
	{
		if ((*itLine) == NULL)
			itLine = m_vFile2Lines.erase(itLine);
		else
			++itLine;
	}

	m_iAdded -= m_iAddedIgnore;
	m_iChanged -= m_iChangedIgnore;
	m_iDeleted -= m_iDeletedIgnore;
	m_iStatus = m_iAdded + m_iDeleted + m_iChanged;
	return m_iStatus;
}


// --- CCompareEngine

// CFileDiff ---
void CFileDiff::SetFiles(const char *pszFile1, const char *pszFile2)
{
	ASSERT_VALID_PSZ(pszFile1);
	ASSERT_VALID_PSZ(pszFile2);
	m_strFile1 = pszFile1;
	m_strFile2 = pszFile2;
}

int CFileDiff::Compare(void)
{
	if (m_CompEngine.InitTask(m_strFile1, m_strFile2, m_CompMode))
	{
		return m_CompEngine.DoCompare();
	}
	else
	{
		return -1;
	}
}

void CFileDiff::Show(void)
{
	m_CompEngine.Dump();
}

// --- CFileDiff


/* Levenshtein distance�㷨ʹ�ú��� */

// �ı�����Ԥ����
// StartPoint���������ļ��е�һ����ƥ�����
void CCompareEngine::PreProcessFile( int &StartPoint )
{
	int nRowIndex = 0;
	for (;nRowIndex < m_pFile1->m_lLineCount && nRowIndex < m_pFile2->m_lLineCount;
		++nRowIndex)
	{
		bool bSameRow = false;
		// �ж��������Ƿ���ͬ
		if (m_pFile1->m_vTokens[nRowIndex] != m_pFile2->m_vTokens[nRowIndex])
		{
			return;
		}
		else
		{
			string strLine1 = m_pFile1->m_vLines[nRowIndex]->GetCmpString();
			string strLine2 = m_pFile2->m_vLines[nRowIndex]->GetCmpString();
			if (strLine1.compare(strLine2) == 0)
				StartPoint = nRowIndex;
			else
				return;
		}

	}

}

void CCompareEngine::DoLevenshteinDistance( 
	int &nStartPoint)
{
	vec_line &m_vFile1Lines = m_pFile1->m_vLines;
	vec_line &m_vFile2Lines = m_pFile2->m_vLines;

	// ������󳤶�
	// ������Ϊ�ļ�1��С��������Ϊ�ļ�2��С
	int nMatrixColumnLength = m_vFile1Lines.size() - nStartPoint;

	int nMatrixRowLength = m_vFile2Lines.size() - nStartPoint;

	// ��������к��������ڳ�ʼ������˳�����Ҫ��1
	++nMatrixColumnLength;
	++nMatrixRowLength;

	// ����LD����
	LDMatrixValue **LDMatrix = new LDMatrixValue*[nMatrixRowLength];
	for (int i = 0; i < nMatrixRowLength; ++i)
		LDMatrix[i] = new LDMatrixValue[nMatrixColumnLength];

	// LD�����һ��
	for (int i = 0; i < nMatrixColumnLength; ++i)
		LDMatrix[0][i].m_Value = i;

	// LD�����һ��
	for (int i = 0; i < nMatrixRowLength; ++i)
		LDMatrix[i][0].m_Value = i;

	// ����������Ԫ
	for (int i = 1; i < nMatrixRowLength; ++i)
	{
		for (int j = 1; j < nMatrixColumnLength; ++j)
		{
			if (CompareLines(nStartPoint + j - 1, nStartPoint + i - 1))
			{
				LDMatrix[i][j].m_Value = LDMatrix[i - 1][j - 1].m_Value;
				LDMatrix[i][j].m_Equal = true;
			}
			else
			{
				int minValue = min((LDMatrix[i - 1][j - 1]).m_Value, (LDMatrix[i - 1][j]).m_Value);
				LDMatrix[i][j].m_Value = min(minValue, LDMatrix[i][j - 1].m_Value) + 1;
				LDMatrix[i][j].m_Equal = false;
			}
		}

	}

	// ���ݷ���
	int nBackDirection;
	// ���ݴ��������ݺ�ĳ���Ϊ���ݴ�����1
	int nBackCount = 0;
	// ���о������
	for (int i = nMatrixRowLength - 1, j = nMatrixColumnLength - 1;
		i > 0 || j > 0;)
	{
		// �Ѿ����ݵ������ϱ�Ե���������
		if (i == 0)
		{
			nBackDirection = BACKTO_LEFT;
		}
		// �Ѿ����ݵ��������Ե�����ϻ���
		else if (j == 0)
		{
			nBackDirection = BACKTO_TOP;
		}
		else
		{
			// ����������Ͻǻ���
			if (LDMatrix[i][j].m_Equal)
			{
				nBackDirection = BACKTO_LEFT_TOP;
			}
			else
			{
				// �������ȡ���ϣ��ϣ���������С��
				int nValueMin;
				
				if (LDMatrix[i - 1][j].m_Value <= LDMatrix[i][j - 1].m_Value)
				{
					nValueMin = LDMatrix[i - 1][j].m_Value;
					nBackDirection = BACKTO_TOP;
				}
				else
				{
					nValueMin = LDMatrix[i][j - 1].m_Value;
					nBackDirection = BACKTO_LEFT;
				}
				
				nBackDirection = (LDMatrix[i - 1][j - 1].m_Value <= nValueMin) ? BACKTO_LEFT_TOP : nBackDirection;

			}
		}

		// ���ݻ��ݷ���ȷ���ı�λ����Ϣ
		switch (nBackDirection)
		{
		case BACKTO_LEFT_TOP:	// �����ϻ��ݣ���λ�ò���
			--i;
			--j;
			break;
		case BACKTO_LEFT:	// ������ݣ�������ӵ��ļ�2��
			{
				CFileLine* NullLine = NULL;
				vec_line::iterator itInsertPoint = 
					(nStartPoint + i >= m_vFile2Lines.size()) ? m_vFile2Lines.end() : 
					m_vFile2Lines.begin() + nStartPoint + i;
				vec_long::iterator itInsertToken = 
					(nStartPoint + i >= m_pFile2->m_vTokens.size()) ? m_pFile2->m_vTokens.end() : 
					m_pFile2->m_vTokens.begin() + nStartPoint + i;

				m_vFile2Lines.insert(itInsertPoint, NullLine);
				m_pFile2->m_vTokens.insert(itInsertToken, -1);
				--j;
				break;
			}
		case BACKTO_TOP:	// ���ϻ��ݣ�������ӵ��ļ�1��
			{
				CFileLine* NullLine = NULL;
				vec_line::iterator itInsertPoint = 
					(nStartPoint + j >= m_vFile1Lines.size()) ? m_vFile1Lines.end() : 
					m_vFile1Lines.begin() + nStartPoint + j;
				vec_long::iterator itInsertToken = 
					(nStartPoint + j >= m_pFile1->m_vTokens.size()) ? m_pFile1->m_vTokens.end() : 
					m_pFile1->m_vTokens.begin() + nStartPoint + j;
				m_vFile1Lines.insert(itInsertPoint, NullLine);
				m_pFile1->m_vTokens.insert(itInsertToken, -1);
				--i;
				break;
			}
		default:
			break;
		}
		nBackCount++;
	}

	// ɾ������
	for (int i = 0; i < nMatrixRowLength; ++i)
	{
		delete LDMatrix[i];
	}
	delete []LDMatrix;
}

bool CCompareEngine::CompareLines( int nLineNo_file1, int nLineNo_file2 )
{
	if (m_pFile1->m_vTokens[nLineNo_file1] != m_pFile2->m_vTokens[nLineNo_file2])
	{
		return false;
	}
	else
	{
		string strLine1 = m_pFile1->m_vLines[nLineNo_file1]->GetCmpString();
		string strLine2 = m_pFile2->m_vLines[nLineNo_file2]->GetCmpString();
		if (strLine1.compare(strLine2) == 0)
			return true;
		else
			return false;
	}
}