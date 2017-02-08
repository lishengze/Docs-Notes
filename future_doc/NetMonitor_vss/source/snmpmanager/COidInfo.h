/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	COidInfo.h
///@brief	������OID��ز�������
///@history
///20110517	κ�� �������ļ�
#ifndef REF_COIDINFO_H
#define REF_COIDINFO_H

class COidInfo
{
	/* */
	public:
		COidInfo(void) :
		oidlen(0)
		{
		}

		//��ֵ������
		COidInfo &operator=(const COidInfo &info)
		{
			if (info.oidlen <= MAX_OID_LEN)
			{
				memcpy(
					(char *)oidvalue,
					(char *)info.oidvalue,
					info.oidlen * sizeof(oid));
				oidlen = info.oidlen;
			}
			else
			{
				oidlen = 0;
			}

			return *this;
		}

		//�Ƚϲ�����
		bool operator < (const COidInfo &info)const
		{
			return (memcmp(oidvalue, info.oidvalue, oidlen * sizeof(oid)) < 0);
		}

		//��ֵ����
		void assign(const oid *value, size_t len)
		{
			if (len <= MAX_OID_LEN)
			{
				memcpy((char *)oidvalue, (char *)value, len * sizeof(oid));
				oidlen = len;
			}
			else
			{
				oidlen = 0;
			}
		}

	/* */
	public:
		oid oidvalue[MAX_OID_LEN];
		size_t	oidlen;
};

//OIDINFO����
typedef std::map<long, COidInfo> ENDOIDMAP;

//OIDINFO������
typedef ENDOIDMAP::iterator ENDOIDITERATOR;
#endif
