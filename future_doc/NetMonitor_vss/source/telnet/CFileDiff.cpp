#include "CFileDiff.h"

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

// CFileLine ---
CFileLine::CFileLine(char *pszLine, CCompareMode &CompMode)
{
	// 完成的记录行的数据加载及转换...
	// 转换方式 将决定最终比较结果
	Init();
	if (strlen(pszLine) == 0)
	{
		if (CompMode.GetSpaceMode() == NullLine)
			throw 0;
		return;
	}

	m_strRawLine = pszLine;			// 保存原始记录
	char szBuf[MAX_BUF_SIZE] = "";
	char *p = pszLine;
	int iLength = strlen(pszLine);
	int iPos = 0;
	bool bIsIndentation = true;
	m_lToken = 0;

	// 如果忽略行尾空白,则将字串尾部空白先行去除
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
				// 行尾的空白字符全部置空,将导致字串长度发生变化
				*(p + i - 1) = 0x00;
			}
		}
	}

	// 字串长度可能发生变化
	iLength = strlen(pszLine);

	for (int i = 0; i < iLength; i++, p++)
	{
		// 检索到空白字符
		if (IsBlankChar(*p))
		{
			if (CompMode.GetSpaceMode() == All)
			{
				// 忽略所有的空白字符
				continue;
			}

			if (bIsIndentation
			&&	CompMode.GetSpaceMode() != None
			&&	CompMode.GetSpaceMode() != Tail)
			{
				// 忽略这些缩进字符
				continue;
			}
		}
		else
		{
			bIsIndentation = false; // 进入非缩进区段
		}

		// 此字符加入比较元素中,同时计算Token值...
		if (CompMode.GetCaseMode() == Invalide)
		{					// 不区分大小写
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

	szBuf[iPos] = 0x00;		// 添加结束符
	m_strCmpLine = szBuf;	// 完成转化后的字串拷贝

	// 首先 字串是否匹配过滤正则表达式
	// 如匹配: 字串原样存入,状态变更为Ignored;
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
			// 无通配符,进行字串全匹配
			if (line.compare(it->first) == 0)
			{
				return true;
			}
		}
		else
		{
			// 进行通配等匹配,最多支持10个通配符
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
			szBuf[strlen(szBuf) - 1] = 0x00;	// 删除行尾换行符
		}

		if (szBuf[strlen(szBuf) - 1] == '\r')
		{
			szBuf[strlen(szBuf) - 1] = 0x00;	// 删除行尾换行符
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
	// 文本文件比较的核心算法
	// 内部采用的Token及转化字串均已得到...
	long nFileLines1 = m_pFile1->m_lLineCount;
	long nFileLines2 = m_pFile2->m_lLineCount;
	long nCurrLineNo1 = 0;
	long nCurrLineNo2 = 0;

	// 当文件1为空时,看文件2是否为空,2非空时,其内数据全为Added状态
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
		// 以文件1为基准，对比两个文件
		for (nCurrLineNo1 = 0;
			 nCurrLineNo1 < nFileLines1;
			 nCurrLineNo1++, nCurrLineNo2++)
		{
			// 文件2中的行游标
			long nLineNo2 = nCurrLineNo2;

			// 当文件2为空 或
			// 文件2已经扫描完成，文件1还没有完成匹配，文件1中剩余字段全部标记为Deleted.
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

			// 文件1的当前行是否能在文件2中找到匹配
			// 若找到，将文件2中该行行号记录到nLineNo2中返回
			// 若未找到，将文件2中当前行与文件1对比寻找匹配行
			if (m_pFile1->MatchLine(nCurrLineNo1, m_pFile2, nLineNo2))
			{
				// 文件2中发生偏移,之前的偏移行全部为新增数据...
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
				// 本记录在文件2中没有找到匹配项
				// 反过来在文件1中找文件2中的当前行项..
				// 如果找到,说明文件1中若干行被删除了
				// 如果没有找到,说明文件发生了变化,双方均记录为Changed ...
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

					// 仅当双方均为Ignored时,此改变将被忽略
					if (m_pFile1->GetLineMode(nCurrLineNo1) == Ignored
					&&	m_pFile2->GetLineMode(nCurrLineNo2) == Ignored)
					{
						m_iChangedIgnore++;
					}
				}
			}
		}

		// 当文件１已完成扫描，而文件2没完成，则文件2中剩余字段全部标记为Added状态
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
			// 同时输出两文件
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
			// 仅输出文件1内容,文件2留空
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
			// 仅输出文件2内容,文件1留空
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
// 新的基于行的文本比较算法，Levenshtein distance算法
int CCompareEngine::DoLDCompare( void )
{


	// 如果两文件中，任何一个文件的行数小于1，则执行原来的算法
	if (m_pFile1->m_lLineCount <= 1 || m_pFile2->m_lLineCount <= 1)
	{
		return DoCompare();
	}

	// 计算位置
	int nStartPoint = 0;
	
	// 对文件进行预处理
	PreProcessFile(nStartPoint);

//	while (nStartPoint < LineCount_file1 
//		&& nStartPoint < LineCount_file2)
	{
		DoLevenshteinDistance(nStartPoint);
	}
/*
	// 若文件1超长，则在文件2中尾部添加对应数量的空行
	int nFileEnd = nStartPoint + 1;
	for (; nFileEnd < m_vFile1Lines.size(); nFileEnd++)
	{
		CLdLine* NullLine = NULL;
		m_vFile2Lines.insert(m_vFile2Lines.end() - 1, NullLine);
	}

	// 若文件2超长，则在文件1中尾部添加对应数量的空行
	for (; nFileEnd < m_vFile2Lines.size(); ++nFileEnd)
	{
		CLdLine* NullLine = NULL;
		m_vFile1Lines.insert(m_vFile1Lines.end() - 1, NullLine);
	}
	*/

	vec_line &m_vFile1Lines = m_pFile1->m_vLines;
	vec_line &m_vFile2Lines = m_pFile2->m_vLines;
	// 根据得到的文件行信息，变换为原始的行信息
	// 此时，文件1和文件2的行数已经相同
	for (int i = 0; i < m_vFile1Lines.size(); ++i)
	{
		// 以文件1为原始版本
		// 若文件1添加了空行，表示对应行是被添加的
		// 若文件2添加了空行，表示对应行是被删除的
		// 例：
		// 文件1： A A [] B C  D E
		// 文件2： A A C  B [] D E
		// C添加到了文件中A和B之间的位置，同理，B之后的C被删除了
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

	// 删除空行
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


/* Levenshtein distance算法使用函数 */

// 文本内容预处理
// StartPoint返回两个文件中第一个不匹配的行
void CCompareEngine::PreProcessFile( int &StartPoint )
{
	int nRowIndex = 0;
	for (;nRowIndex < m_pFile1->m_lLineCount && nRowIndex < m_pFile2->m_lLineCount;
		++nRowIndex)
	{
		bool bSameRow = false;
		// 判断行内容是否相同
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

	// 计算矩阵长度
	// 列数量为文件1大小，行数量为文件2大小
	int nMatrixColumnLength = m_vFile1Lines.size() - nStartPoint;

	int nMatrixRowLength = m_vFile2Lines.size() - nStartPoint;

	// 矩阵的首行和首列用于初始化，因此长度需要加1
	++nMatrixColumnLength;
	++nMatrixRowLength;

	// 构造LD矩阵
	LDMatrixValue **LDMatrix = new LDMatrixValue*[nMatrixRowLength];
	for (int i = 0; i < nMatrixRowLength; ++i)
		LDMatrix[i] = new LDMatrixValue[nMatrixColumnLength];

	// LD矩阵第一行
	for (int i = 0; i < nMatrixColumnLength; ++i)
		LDMatrix[0][i].m_Value = i;

	// LD矩阵第一列
	for (int i = 0; i < nMatrixRowLength; ++i)
		LDMatrix[i][0].m_Value = i;

	// 计算其他单元
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

	// 回溯方向
	int nBackDirection;
	// 回溯次数，回溯后的长度为回溯次数减1
	int nBackCount = 0;
	// 进行矩阵回溯
	for (int i = nMatrixRowLength - 1, j = nMatrixColumnLength - 1;
		i > 0 || j > 0;)
	{
		// 已经回溯到矩阵上边缘，向左回溯
		if (i == 0)
		{
			nBackDirection = BACKTO_LEFT;
		}
		// 已经回溯到矩阵左边缘，向上回溯
		else if (j == 0)
		{
			nBackDirection = BACKTO_TOP;
		}
		else
		{
			// 相等则向左上角回溯
			if (LDMatrix[i][j].m_Equal)
			{
				nBackDirection = BACKTO_LEFT_TOP;
			}
			else
			{
				// 不相等则取左上，上，左三个最小的
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

		// 根据回溯方向，确定文本位置信息
		switch (nBackDirection)
		{
		case BACKTO_LEFT_TOP:	// 向右上回溯，行位置不变
			--i;
			--j;
			break;
		case BACKTO_LEFT:	// 向左回溯，空行添加到文件2中
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
		case BACKTO_TOP:	// 向上回溯，空行添加到文件1中
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

	// 删除矩阵
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