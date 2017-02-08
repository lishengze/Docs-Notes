/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	COrderRttManager.h
///@brief	定义了数据包过滤的类
///@auther	赵鸿昊
///@history
#ifndef REF_CORDERRTTMANAGER_H
#define REF_CORDERRTTMANAGER_H

#include "public.h"
#include "FTDCSession.h"
#include "OFPSession.h"
#include "FtdPackageDesc.h"
#include "FTDCPackage.h"
#include "CSVParser.h"
#include "Storage.h"
#include "OfpData.h"
#include "FtdPackageDesc.h"
#include "CDate.h"
#include "version.h"
#include "systools.h"

///20080716 add by wu.yb
#include <SQLAPI.h>

/////////////////////////////////////////////////////////////////////////
///COrderRttKey定义了报单关键字类
///@author	周建军
///@version	1.0,20080710
/////////////////////////////////////////////////////////////////////////
class COrderRttKey
{
	/* */
	public:
		///版本号
		char Version;

		///前置的ID
		int FrontID;

		///会话的ID
		int SessionID;

		///报单的本地编号
		COrderLocalIDType OrderLocalID;

		///报单的用户ID
		CUserIDType UserID;

	/* */
	public:

		///构造函数
		COrderRttKey(void)
		{
			FrontID = 0;
			SessionID = 0;
			OrderLocalID = "";
			UserID = "";
			Version = 0;
		}

		///构造函数
			///@param	uid	用户ID
			///@param	oid	报单的本地编号
			///@param	sid	会话的ID编号
			///@param	fid	前置的ID
			///@param	vid 版本ID
		COrderRttKey(
		CUserIDType uid,
		COrderLocalIDType oid,
		int sid,
		int fid,
		char vid)
		{
			SessionID = sid;
			OrderLocalID = oid;
			UserID = uid;
			FrontID = fid;
			Version = vid;
		}

		///拷贝构造函数
		COrderRttKey(const COrderRttKey &ob)
		{
			SessionID = ob.SessionID;
			OrderLocalID = ob.OrderLocalID;
			UserID = ob.UserID;
			FrontID = ob.FrontID;
			Version = ob.Version;
		}

		///重载=运算符
		void operator=(const COrderRttKey &ob)
		{
			SessionID = ob.SessionID;
			OrderLocalID = ob.OrderLocalID;
			UserID = ob.UserID;
			FrontID = ob.FrontID;
			Version = ob.Version;
		}

		///重载>运算符
		friend bool operator>(const COrderRttKey &ob1, const COrderRttKey &ob2)
		{
			if (ob1.Version > ob2.Version)
			{
				return true;
			}
			else if (ob1.Version == ob2.Version)
			{
				if (ob1.FrontID > ob2.FrontID)
				{
					return true;
				}
				else if (ob1.FrontID == ob2.FrontID)
				{
					if (ob1.SessionID > ob2.SessionID)
					{
						return true;
					}
					else if (ob1.SessionID == ob2.SessionID)
					{
						int ret = strcmp(
								ob1.OrderLocalID.getValue(),
								ob2.OrderLocalID.getValue());
						if (ret > 0)
						{
							return true;
						}
						else if (ret == 0)
						{
							ret = strcmp(
									ob1.UserID.getValue(),
									ob2.UserID.getValue());
							if (ret > 0)
							{
								return true;
							}
						}
					}
				}
			}

			return false;
		}

		///重载<运算符
		bool operator < (const COrderRttKey &other)const
		{
			if (this->Version < other.Version)
			{
				return true;
			}
			else if (this->Version == other.Version)
			{
				if (this->FrontID < other.FrontID)
				{
					return true;
				}
				else if (this->FrontID == other.FrontID)
				{
					if (this->SessionID < other.SessionID)
					{
						return true;
					}
					else if (this->SessionID == other.SessionID)
					{
						int ret = strcmp
							(
								(char *)this->OrderLocalID.getValue(),
									(char *)other.OrderLocalID.getValue()
							);
						if (ret < 0)
						{
							return true;
						}
						else if (ret == 0)
						{
							ret = strcmp
								(
									(char *)(this->UserID.getValue()),
										(char *)other.UserID.getValue()
								);
							if (ret < 0)
							{
								return true;
							}
						}
					}
				}
			}

			return false;
		}

		///重载==运算符
		friend bool operator==(const COrderRttKey &ob1, const COrderRttKey &ob2)
		{
			if ((ob1.Version == ob2.Version)
			&&	(ob1.SessionID == ob2.SessionID)
			&&	(ob1.FrontID == ob2.FrontID)
			&&	(
					strcmp(
					ob1.OrderLocalID.getValue(),
				ob2.OrderLocalID.getValue()) == 0
			)
			&&	(strcmp(ob1.UserID.getValue(), ob2.UserID.getValue()) == 0))
			{
				return true;
			}

			return false;
		}
};
class CRttStatsKey
{
	/* */
	public:
		///版本号
		char Version;

		///前置的ID
		int FrontID;

	/* */
	public:

		///构造函数
		CRttStatsKey(void)
		{
			Version = 0;
			FrontID = 0;
		}

		///构造函数
			///@param	fid	前置的ID
			///@param	vid 版本ID
		CRttStatsKey(int fid, char vid)
		{
			FrontID = fid;
			Version = vid;
		}

		///拷贝构造函数
		CRttStatsKey(const CRttStatsKey &ob)
		{
			FrontID = ob.FrontID;
			Version = ob.Version;
		}

		///重载=运算符
		void operator=(const CRttStatsKey &ob)
		{
			FrontID = ob.FrontID;
			Version = ob.Version;
		}

		///重载>运算符
		bool operator>(const CRttStatsKey &ob2) const
		{
			if (this->Version > ob2.Version)
			{
				return true;
			}
			else if (this->Version == ob2.Version)
			{
				if (this->FrontID > ob2.FrontID)
				{
					return true;
				}
			}

			return false;
		}

		///重载<运算符
		bool operator < (const CRttStatsKey &ob2)const
		{
			if (this->Version < ob2.Version)
			{
				return true;
			}
			else if (this->Version == ob2.Version)
			{
				if (this->FrontID < ob2.FrontID)
				{
					return true;
				}
			}

			return false;
		}

		///重载==运算符
		friend bool operator==(const CRttStatsKey &ob1, const CRttStatsKey &ob2)
		{
			if ((ob1.Version == ob2.Version) && (ob1.FrontID == ob2.FrontID))
			{
				return true;
			}

			return false;
		}
};
class CRttPacketStats
{
	/* */
	public:
		CRttPacketStats(void)
		{
			m_lPacketNum[0] = m_lPacketNum[1] = m_lPacketNum[2] = m_lPacketNum[3] = m_lPacketNum[4] = 0;
		}

	/* */
	public:
		INT64 m_lPacketNum[5];
};

class CRttInSecond
{
	/* */
	public:
		QWORD nCount;	///这一刻，包的个数
		QWORD nRttSum;	///所有包的rtt和
		int nMaxRtt;	///最大的rtt
		int nMinRtt;	///最小的rtt
		
			///这一刻，报单响应时间分布
		QWORD nDistribution[8];

		CRttInSecond(void) :
		nCount(0)
		,
		nRttSum(0)
		,
		nMaxRtt(0)
		,
		nMinRtt(0)
		{
			memset(nDistribution, 0, sizeof(nDistribution));
		};
};

class CRttInSec4Front
{
	/* */
	public:
		CRttInSec4Front(void) :
		nTict(-1),
		strLastmine("")
		{
		};

		~CRttInSec4Front(void)
		{
			mapRttStatis.clear();
		}

		void addOneOrder(int nRtt, string sec);

		//int nFrontID;
		//前置能查到的最后一秒
		string	strLastmine;

		//计数, 新增一条记录时置0， 后一秒+1， 推出后置-1
		int nTict;
		map<string, CRttInSecond *> mapReady4Rtn;

		CRttInSecond allStatic;
		map<string, CRttInSecond> mapRttStatis;
};
class CRttReadyMap
{
	/* */
	public:
		map<string, CRttInSecond *> mapRttInSec;
};

typedef list<int> CIntList;

/////////////////////////////////////////////////////////////////////////
///COrderRttKey定义了报单分析类
///@author	周建军
///@version	1.0,20080710
/////////////////////////////////////////////////////////////////////////
class COrderRttAnalysis
{
	/* */
	private:
		///保存当前所有的报单请求
			///@param	key	报单请求信息
			///@param	value	相同报单的请求时间列表
		map<COrderRttKey, CIntList> m_mapOrderRtt;

		///保存数据包按照前置分类统计值
			///@param	key	前置编号0~63,最高位为数据中心编号
			///@param	value	前置的数据包响应时间分类统计总个数
		map<CRttStatsKey, CRttPacketStats>	m_mapRttPacketNum;

		///保存rtt按前置的统计
			///@param	key	前置编号0~63,最高位为数据中心编号
		map<int, CRttInSec4Front> m_mapRttStaticsFront;

	/* */
	public:
		///OFP数据包处理函数
			///@param	pOFPPackage	ofp数据包地址
			///@param	nSessionID	所属会话的ID编号
			///@param	nFrontID	所属的前置ID编号
			///@param	cVsersion	OFP协议版本
		void OnOFPPackage(
				COFPPackage *pOFPPackage,
				int nSessionID,
				int nFrontID,
				char cVersion);

		///FTD数据包处理函数
			///@param	pFTDPackage	FTD数据包地址
			///@param	nSessionID	所属会话的ID编号
			///@param	nFrontID	所属的前置ID编号
			///@param	cVsersion	FTD协议版本
		void OnFTDCPackage(
				CFTDCPackage *pPackage,
				int nSessionID,
				int nFrontID,
				char cVersion);

		///报单请求处理函数
			///@param	UserID	报单的用户ID
			///@param	OrderLocalID	报单的本地编号
			///@param	nSessionID	所属会话的ID编号
			///@param	nFrontID	所属的前置ID编号
			///@param	cVsersion	协议版本
		void HandleOrderReq(
				const CUserIDType &UserID,
				const COrderLocalIDType &OrderLocalID,
				int nSessionID,
				int nFrontID,
				char cVersion);

		///报单响应处理函数
			///@param	UserID	报单的用户ID
			///@param	OrderLocalID	报单的本地编号
			///@param	nSessionID	所属会话的ID编号
			///@param	nFrontID	所属的前置ID编号
			///@param	cVsersion	协议版本
		void HandleOrderRsp(
				const CUserIDType &UserID,
				const COrderLocalIDType &OrderLocalID,
				int nSessionID,
				int nFrontID,
				char cVersion);

		///取统计值函数
			///@return	返回当前所有前置的统计map
		map<CRttStatsKey, CRttPacketStats> &getRttAnalysis(void)
		{
			for (map<CRttStatsKey, CRttPacketStats>::iterator rttIt =
					 m_mapRttPacketNum.begin();
			 rttIt != m_mapRttPacketNum.end();)
			{
				rttIt->second.m_lPacketNum[0] = 0;
				++rttIt;
			}

			for (map<COrderRttKey, CIntList>::iterator orderIt =
					 m_mapOrderRtt.begin();
			 orderIt != m_mapOrderRtt.end();)
			{
				if (orderIt->second.size() == 0)
				{
					m_mapOrderRtt.erase(orderIt++);
				}
				else
				{
					m_mapRttPacketNum[CRttStatsKey(
							orderIt->first.FrontID,
							orderIt->first.Version)].m_lPacketNum[0]++;
					++orderIt;
				}
			}

			return m_mapRttPacketNum;
		}

		///统计结果写入物理数据库
		void putRttAnalysisToDB(void);

		///构造函数
		COrderRttAnalysis(void)
		{
		}

		///20080716 add by wu.yb
		
		
			//////////////////////////////////////////////////////////////////////////
		//20121023 feng.q
		CRttInSec4Front &GetOrderRttStatic(int nFront);

		map<int, CRttInSec4Front> &GetOrderRttMap(void);

		bool CheckRtnIsReady(map<int, CRttReadyMap> &mapRttForRtn);

		//获得所有报单和, 如果没有报单则试图查看对应前置的文件读取状态
		int GetOrderRttSum(int nFrontID, char *pcErrMsg);

	//////////////////////////////////////////////////////////////////////////
	private:
		///连接数据库，如果是连接着的，就不再进行连接
		void connectDB(void);

		///利用全局变量，生成ip:port/dbname的字符串
		string	getConnectStr(
					const string &ip,
					const string &port,
					const string &dbName) const;
		void InsertDBSysFrontInfo(
				const char	*date,
				const char	*time,
				int frontId,
				int reqCond,
				INT64 reqCount,
				double	reqRate);

	/* */
	private:
		///数据库的连接句柄 (连接使用的参数定义在sysquery.cpp)
		SAConnection m_sqlConnect;
};
#endif // end REF_CORDERRTTMANAGER_H
