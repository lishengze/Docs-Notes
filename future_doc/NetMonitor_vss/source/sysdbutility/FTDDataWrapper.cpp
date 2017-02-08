#include "FTDDataWrapper.h"
#include <FieldDescribe.h>
#include <SQLAPI.h>
#include <vector>
#include <StringUtil.h>
#include <PrjCommon.h>

bool CFtdData::SetIntAttr(const char *attr, DWORD value)
{
	if (!attr)
	{
		return false;
	}

	bool rtn = false;
	int n = m_descr->GetMemberCount();

	for (int i = 0; i < n; i++)
	{
		if (strcmp(m_descr->GetMemberDesc(i)->szName, attr) == 0)
		{
			assert(m_descr->GetMemberDesc(i)->nType == FT_DWORD);

			char *pMem = (char *)m_obj +
				m_descr->GetMemberDesc(i)->nStreamOffset;

			*((DWORD *)pMem) = value;
			rtn = true;
			break;
		}
	}

	return rtn;
}

bool CFtdData::GetIntAttr(const char *attr, DWORD *value) const
{
	if (!attr || !value)
	{
		return false;
	}

	bool rtn = false;
	int n = m_descr->GetMemberCount();

	for (int i = 0; i < n; i++)
	{
		if (strcmp(m_descr->GetMemberDesc(i)->szName, attr) == 0)
		{
			assert(m_descr->GetMemberDesc(i)->nType == FT_DWORD);

			char *pMem = (char *)m_obj +
				m_descr->GetMemberDesc(i)->nStreamOffset;

			*value = *((DWORD *)pMem);
			rtn = true;
			break;
		}
	}

	return rtn;
}

bool CFtdData::SetAttr(const char *attr, Attribute_Type type, const void *value)
{
	if (!attr || !value)
	{
		return false;
	}

	bool rtn = false;
	int n = m_descr->GetMemberCount();

	for (int i = 0; i < n; i++)
	{
		if (strcmp(m_descr->GetMemberDesc(i)->szName, attr) == 0)
		{
			assert(
				m_descr->GetMemberDesc(i)->nType == type
				&&	"Name or Type is wrong, check it!");

			char *pMem = (char *)m_obj +
				m_descr->GetMemberDesc(i)->nStructOffset;

			switch (m_descr->GetMemberDesc(i)->nType)
			{
				case FT_BYTE:
					{
						int size = m_descr->GetMemberDesc(i)->nSize;
						if (size == 1)
						{
							*pMem = *((char *)value);
						}
						else
						{
							strncpy(pMem, (const char *)value, size - 1);
							*(pMem + size - 1) = 0;
						}

						break;
					}

				case FT_WORD:
					{
						*((WORD *)pMem) = *((WORD *)value);
						break;
					}

				case FT_DWORD:
					{
						*((DWORD *)pMem) = *((DWORD *)value);
						break;
					}

				case FT_REAL4:
					{
						*((float *)pMem) = *((float *)value);
						break;
					}

				case FT_REAL8:
					{
						*((double *)pMem) = *((double *)value);
						break;
					}

				default:
					assert(false && "Invaild data type!");
			}

			rtn = true;
			break;
		}
	}

	return rtn;
}

bool CFtdData::GetAttr(
	const char	*attr,
	Attribute_Type	type,
	void *value,
	int size) const
{
	if (!attr || !value || size <= 0)
	{
		return false;
	}

	bool rtn = false;
	int n = m_descr->GetMemberCount();

	for (int i = 0; i < n; i++)
	{
		if (strcmp(m_descr->GetMemberDesc(i)->szName, attr) == 0)
		{
			assert(
				m_descr->GetMemberDesc(i)->nType == type
				&&	"Name or Type is wrong, check it!");

			char *pMem = (char *)m_obj +
				m_descr->GetMemberDesc(i)->nStructOffset;

			switch (m_descr->GetMemberDesc(i)->nType)
			{
				case FT_BYTE:
					{
						int memSize = m_descr->GetMemberDesc(i)->nSize;
						if (memSize == 1)
						{
							*((char *)value) = *pMem;
						}
						else
						{
							strncpy((char *)value, pMem, size - 1);
							*((char *)value + size - 1) = 0;
						}

						break;
					}

				case FT_WORD:
					{
						*((WORD *)value) = *((WORD *)pMem);
						break;
					}

				case FT_DWORD:
					{
						*((DWORD *)value) = *((DWORD *)pMem);
						break;
					}

				case FT_REAL4:
					{
						*((float *)value) = *((float *)pMem);
						break;
					}

				case FT_REAL8:
					{
						*((double *)value) = *((double *)pMem);
						break;
					}

				default:
					assert(false && "Invaild data type!");
			}

			rtn = true;
			break;
		}
	}

	return rtn;
}

void CFtdData::FromDBRecord(SACommand &cmd)
{
	int n = m_descr->GetMemberCount();

	for (int i = 0; i < n; i++)
	{
		char *pMem = (char *)m_obj + m_descr->GetMemberDesc(i)->nStructOffset;
		const char	*pName = m_descr->GetMemberDesc(i)->szName;
		int size = m_descr->GetMemberDesc(i)->nSize;

		try
		{
			switch (m_descr->GetMemberDesc(i)->nType)
			{
				case FT_BYTE:
					{
						// SAString重载了operator const SAChar *()方法，但SAChar为UNICODE字符，需要注意！
						SAString str = cmd.Field(pName).asString();
						if (size == 1)
						{
							*(pMem) = *((const char *)str);
						}
						else
						{
							str.TrimRight();
							strncpy(pMem, (const char *)str, size - 1);
							*(pMem + size - 1) = 0;
						}

						break;
					}

				case FT_WORD:
					{
						WORD tmp = cmd.Field(pName).asShort();
						*((WORD *)pMem) = tmp;
						break;
					}

				case FT_DWORD:
					{
						DWORD tmp = cmd.Field(pName).asLong();
						*((DWORD *)pMem) = tmp;
						break;
					}

				case FT_QWORD:
					{
	#ifdef WINDOWS
						QWORD tmp = (unsigned long long int)cmd.Field(
								pName).asNumeric();

						//unsigned char *p = cmd.Field(pName).asNumeric().val;
						//memcpy(pMem, p, sizeof(QWORD));
						*((QWORD *)pMem) = tmp;

						//*((QWORD *)pMem) = cmd.Field(pName).asNumeric().val;
	#else
						QWORD tmp = (unsigned long long int)cmd.Field(pName).asLong();
						*((QWORD *)pMem) = tmp;
	#endif
						break;
					}

				case FT_REAL4:
					{
						float tmp = (float)cmd.Field(pName).asDouble();
						*((float *)pMem) = tmp;
						break;
					}

				case FT_REAL8:
					{
						double	tmp = cmd.Field(pName).asDouble();
						*((double *)pMem) = tmp;
						break;
					}

				default:
					assert(false && "Invaild data type!");
			}
		}

		catch(SAException & ex)
		{
			LOG_ERROR(
				"CFtdData::FromDBRecord catch exception: (%s) when get (%s %s)\n",
				(const char *)ex.ErrText(),
				"attribute",
				pName);
		}
	}
}

void CFtdData::ToDBRecord(SACommand &cmd) const
{
	int n = m_descr->GetMemberCount();

	for (int i = 0; i < n; i++)
	{
		char *pMem = (char *)m_obj + m_descr->GetMemberDesc(i)->nStructOffset;
		const char	*pName = m_descr->GetMemberDesc(i)->szName;
		int size = m_descr->GetMemberDesc(i)->nSize;

		try
		{
			switch (m_descr->GetMemberDesc(i)->nType)
			{
				case FT_BYTE:
					{
						if (size == 1)
						{
							cmd.Param(pName).setAsString() = *pMem;
						}
						else
						{
							cmd.Param(pName).setAsString() = (const char *)pMem;
						}

						break;
					}

				case FT_WORD:
					{
						cmd.Param(pName).setAsShort() = *((WORD *)pMem);
						break;
					}

				case FT_DWORD:
					{
						cmd.Param(pName).setAsLong() = *((DWORD *)pMem);
						break;
					}

				case FT_REAL4:
					{
						cmd.Param(pName).setAsDouble() = *((float *)pMem);
						break;
					}

				case FT_QWORD:
					{
	#ifdef WINDOWS
						cmd.Param(pName).setAsNumeric() = *((unsigned long long int *)pMem);
	#else
						cmd.Param(pName).setAsLong() = *((QWORD *)pMem);
	#endif
						break;
					}

				case FT_REAL8:
					{
						cmd.Param(pName).setAsDouble() = *((double *)pMem);
						break;
					}

				default:
					assert(false && "Invaild data type!");
			}
		}

		catch(SAException & ex)
		{
			LOG_ERROR(
				"CFtdData::ToDBRecord catch exception: (%s) when set (%s %s)\n",
				(const char *)ex.ErrText(),
				"attribute",
				pName);
		}
	}
}

bool CFtdData::FromString(const string &serializedStr, const char *attrDelimit)
{
	vector<string>	attrArray;

	m_delimit = attrDelimit;

	assert(!m_delimit.empty());

	if (!SplitStr(serializedStr, m_delimit, attrArray))
	{
		LOG_WARNING(
			"CFtdData::FromString: parse serialized string failed! serializedStr(%s) delimitation is (%s) \n",
			(const char *)serializedStr.c_str(),
			m_delimit.c_str());
		return false;
	}

	int n = m_descr->GetMemberCount();
	if (attrArray.size() != n)
	{
		LOG_WARNING(
			"(%s) is not a vaild serialized string of %s\n",
			(const char *)serializedStr.c_str(),
			m_descr->GetFieldName());
		return false;
	}

	bool invalid = false;
	int i;
	for (i = 0; i < n; i++)
	{
		char *pMem = (char *)m_obj + m_descr->GetMemberDesc(i)->nStructOffset;

		switch (m_descr->GetMemberDesc(i)->nType)
		{
			case FT_BYTE:
				{
					int size = m_descr->GetMemberDesc(i)->nSize;
					if (size == 1)
					{
						*pMem = attrArray[i][0];
					}
					else
					{
						strncpy(pMem, attrArray[i].c_str(), size - 1);
						*(pMem + size - 1) = 0;
					}

					break;
				}

			case FT_WORD:
				{
					if (isdigit(attrArray[i].c_str()))
					{
						WORD tmp = atoi(attrArray[i].c_str());
						*((WORD *)pMem) = tmp;
					}
					else
					{
						invalid = true;
					}

					break;
				}

			case FT_DWORD:
				{
					if (isdigit(attrArray[i].c_str()))
					{
						DWORD tmp = atol(attrArray[i].c_str());
						*((DWORD *)pMem) = tmp;
					}
					else
					{
						invalid = true;
					}

					break;
				}

			case FT_REAL4:
				{
					if (isfloat(attrArray[i].c_str()))
					{
						float tmp = (float)atof(attrArray[i].c_str());
						*((float *)pMem) = tmp;
					}
					else
					{
						invalid = true;
					}

					break;
				}

			case FT_REAL8:
				{
					if (isfloat(attrArray[i].c_str()))
					{
						double	tmp = atof(attrArray[i].c_str());
						*((double *)pMem) = tmp;
					}
					else
					{
						invalid = true;
					}

					break;
				}

			default:
				assert(false && "Invaild data type!");
		}

		if (invalid)
		{
			LOG_WARNING(
				"(%s) is not a vaild serialized string of %s, field of (%s) is invalid!\n",
				(const char *)serializedStr.c_str(),
				m_descr->GetFieldName(),
				m_descr->GetMemberDesc(i)->szName);
			break;
		}
	}

	return !invalid;
}

string &CFtdData::ToString(const char *attrDelimit)
{
	m_delimit = attrDelimit;

	assert(!m_delimit.empty());

	m_serializedStr = "";

	int n = m_descr->GetMemberCount();

	for (int i = 0; i < n; i++)
	{
		char *pMem = (char *)m_obj + m_descr->GetMemberDesc(i)->nStructOffset;
		const char	*pName = m_descr->GetMemberDesc(i)->szName;
		int size = m_descr->GetMemberDesc(i)->nSize;

		switch (m_descr->GetMemberDesc(i)->nType)
		{
			case FT_BYTE:
				{
					if (size == 1)
					{
						m_serializedStr += *pMem;
					}
					else
					{
						m_serializedStr += (const char *)pMem;
					}

					break;
				}

			case FT_WORD:
				{
					WORD tmp = *((WORD *)pMem);
					char str[6];
					sprintf(str, "%d", tmp);

					m_serializedStr += str;
					break;
				}

			case FT_DWORD:
				{
					DWORD tmp = *((DWORD *)pMem);
					char str[12];
					sprintf(str, "%ld", tmp);

					m_serializedStr += str;
					break;
				}

			case FT_REAL4:
				{
					float tmp = *((float *)pMem);
					char str[12];
					sprintf(str, "%f", tmp);

					m_serializedStr += str;
					break;
				}

			case FT_REAL8:
				{
					double	tmp = *((double *)pMem);
					char str[24];
					sprintf(str, "%Lf", tmp);

					m_serializedStr += str;
					break;
				}

			default:
				assert(false && "Invaild data type!");
		}

		if (i != n - 1)
		{
			m_serializedStr += m_delimit;
		}
	}

	return m_serializedStr;
}

// 比较2个简单类型
#define COMPARE(v1, v2) ((v1) > (v2) ? CR_GT : ((v1) < (v2) ? CR_LT : CR_EQ))

// 比较浮点类型
#define COMPARE_FLOAT(v1, v2, precision)					\
		(													\
			(v1) > ((v2) + precision) ? CR_GT :				\
				((v1) < ((v2) - precision) ? CR_LT : CR_EQ) \
		)

// 浮点数误差值，用于浮点数比较
#define SMALL_DOUBLE	0.000000001

CFtdData::Compare_Result CFtdData::CompareAttrValue(
	const char	*attr,
	const char	*value)
{
	if (!attr || !value)
	{
		return CR_INVALID;
	}

	Compare_Result	rtn = CR_INVALID;

	int n = m_descr->GetMemberCount();
	for (int i = 0; i < n; i++)
	{
		if (strcmp(m_descr->GetMemberDesc(i)->szName, attr) == 0)
		{
			char *pMem = (char *)m_obj +
				m_descr->GetMemberDesc(i)->nStructOffset;

			switch (m_descr->GetMemberDesc(i)->nType)
			{
				case FT_BYTE:
					{
						int size = m_descr->GetMemberDesc(i)->nSize;
						if (size == 1)
						{
							rtn = COMPARE(*pMem, *value);
						}
						else
						{
							int strComp = strcmp(pMem, value);
							rtn = COMPARE(strComp, 0);
						}

						break;
					}

				case FT_WORD:
					{
						WORD tmp = atoi(value);
						rtn = COMPARE(*((WORD *)pMem), tmp);
						break;
					}

				case FT_DWORD:
					{
						DWORD tmp = atol(value);
						rtn = COMPARE(*((DWORD *)pMem), tmp);
						break;
					}

				case FT_REAL4:
					{
						float tmp = (float)atof(value);
						rtn = COMPARE_FLOAT(*((float *)pMem), tmp, SMALL_DOUBLE);
						break;
					}

				case FT_REAL8:
					{
						double	tmp = atof(value);
						rtn = COMPARE_FLOAT(*((double *)pMem), tmp, SMALL_DOUBLE);
						break;
					}

				default:
					assert(false && "Invaild data type!");
			}

			break;
		}
	}

	return rtn;
}
