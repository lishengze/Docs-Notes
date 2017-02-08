/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	COidInfo.h
///@brief	定义了OID相关操作的类
///@history
///20110517	魏诚 创建该文件
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

		//赋值操作符
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

		//比较操作符
		bool operator < (const COidInfo &info)const
		{
			return (memcmp(oidvalue, info.oidvalue, oidlen * sizeof(oid)) < 0);
		}

		//赋值函数
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

//OIDINFO容器
typedef std::map<long, COidInfo> ENDOIDMAP;

//OIDINFO迭代器
typedef ENDOIDMAP::iterator ENDOIDITERATOR;
#endif
