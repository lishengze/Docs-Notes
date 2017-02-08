// CSVParser.cpp: implementation of the CCSVParser class.
//
// 20070916 �Ժ�� ���ӹ��췽����Parse������ʹ֮���Խ�������ַ��� 
// 20070916 �Ժ�� �޸�GetNextToken�÷���������Ҫ�ж�CPE_HAS_NEXT 
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "CSVParser.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCSVParser::CCSVParser()
{
	m_pszData = NULL;
	m_pCurr = NULL;
	m_nErrorCode = CPE_END;
}

CCSVParser::CCSVParser(const char *pszData)
{
	Parse(pszData);
}

CCSVParser::~CCSVParser()
{

}

void CCSVParser::Parse(const char *pszData)
{
	m_pszData = pszData;
	m_pCurr = m_pszData;
	m_nErrorCode = CPE_HAS_NEXT;
	NextChar();
}

void CCSVParser::NextChar()
{
	m_chC = *m_pCurr;
	if(m_chC == '\0' || m_chC == '\r' || m_chC == '\n')
	{
		m_chC = '\0';
		m_chNC = '\0';
	}
	else{
		m_pCurr++;
		m_chNC = *m_pCurr;
	}
}

void CCSVParser::MakeWord(const char *pszEnd)
{
	int i=0;
	for (;i<TOKEN_MAX_LEN; i++)
	{
		if (m_chC == '\0')
		{
			break;
		}
		if (strchr(pszEnd, m_chC) != NULL)
		{
			if (m_chC == '"' && m_chNC == '"')
			{
				NextChar();
			}
			else
			{
				break;
			}
		}
		m_szCurrWord[i]=m_chC;
		NextChar();
	}
	m_szCurrWord[i]='\0';
}

char *CCSVParser::GetNextToken()
{
	if (m_nErrorCode != CPE_HAS_NEXT)
	{
		return NULL;
	}
	switch (m_chC)
	{
	case '"':
		NextChar();
		MakeWord("\"");
		if (m_chC != '"')
		{
			m_nErrorCode = CPE_MARK_NOT_MATCH;
			return NULL;
		}
		NextChar();
		break;
//	case '\0':
//		m_nErrorCode = CPE_END;
//		return NULL;
	default:
		MakeWord(",");
	}
	if (m_chC == ',')
	{
		m_nErrorCode = CPE_HAS_NEXT;
		NextChar();
		return m_szCurrWord;
	}
	if (m_chC == '\0')
	{
		m_nErrorCode = CPE_END;
		return m_szCurrWord;
	}

	m_nErrorCode = CPE_TOKEN_TOO_LONG;
	return NULL;
}

#if 0
int main()
{
	char *pString = ",abc111111111111111111111111,\"1,2\"\"3\",\"a\"\"a\",\"aaaaaaaa\"";
	CCSVParser parser(pString);
	do {
		char *pToken = parser.GetNextToken();
		if (pToken != NULL)
		{
			printf("%s\n", pToken);
		}
	} while(parser.GetErrorCode() == CPE_HAS_NEXT);


	char *pString2 = "\"��һ��\",\"��\"\"��\"\"��\",������";
	parser.Parse(pString2);
	for (int i=0; ;i++)
	{
		char *pToken = parser.GetNextToken();
		if (pToken == NULL)
		{
			break;
		}
		printf("%d: %s\n", i, pToken);
	}
	return 0;
}
#endif
