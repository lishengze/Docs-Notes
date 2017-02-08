/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	COrderRttManager.h
///@brief	���������ݰ����˵���
///@auther	�Ժ��
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
///COrderRttKey�����˱����ؼ�����
///@author	�ܽ���
///@version	1.0,20080710
/////////////////////////////////////////////////////////////////////////
class COrderRttKey
{
	/* */
	public:
		///�汾��
		char Version;

		///ǰ�õ�ID
		int FrontID;

		///�Ự��ID
		int SessionID;

		///�����ı��ر��
		COrderLocalIDType OrderLocalID;

		///�������û�ID
		CUserIDType UserID;

	/* */
	public:

		///���캯��
		COrderRttKey(void)
		{
			FrontID = 0;
			SessionID = 0;
			OrderLocalID = "";
			UserID = "";
			Version = 0;
		}

		///���캯��
			///@param	uid	�û�ID
			///@param	oid	�����ı��ر��
			///@param	sid	�Ự��ID���
			///@param	fid	ǰ�õ�ID
			///@param	vid �汾ID
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

		///�������캯��
		COrderRttKey(const COrderRttKey &ob)
		{
			SessionID = ob.SessionID;
			OrderLocalID = ob.OrderLocalID;
			UserID = ob.UserID;
			FrontID = ob.FrontID;
			Version = ob.Version;
		}

		///����=�����
		void operator=(const COrderRttKey &ob)
		{
			SessionID = ob.SessionID;
			OrderLocalID = ob.OrderLocalID;
			UserID = ob.UserID;
			FrontID = ob.FrontID;
			Version = ob.Version;
		}

		///����>�����
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

		///����<�����
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

		///����==�����
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
		///�汾��
		char Version;

		///ǰ�õ�ID
		int FrontID;

	/* */
	public:

		///���캯��
		CRttStatsKey(void)
		{
			Version = 0;
			FrontID = 0;
		}

		///���캯��
			///@param	fid	ǰ�õ�ID
			///@param	vid �汾ID
		CRttStatsKey(int fid, char vid)
		{
			FrontID = fid;
			Version = vid;
		}

		///�������캯��
		CRttStatsKey(const CRttStatsKey &ob)
		{
			FrontID = ob.FrontID;
			Version = ob.Version;
		}

		///����=�����
		void operator=(const CRttStatsKey &ob)
		{
			FrontID = ob.FrontID;
			Version = ob.Version;
		}

		///����>�����
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

		///����<�����
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

		///����==�����
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
		QWORD nCount;	///��һ�̣����ĸ���
		QWORD nRttSum;	///���а���rtt��
		int nMaxRtt;	///����rtt
		int nMinRtt;	///��С��rtt
		
			///��һ�̣�������Ӧʱ��ֲ�
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
		//ǰ���ܲ鵽�����һ��
		string	strLastmine;

		//����, ����һ����¼ʱ��0�� ��һ��+1�� �Ƴ�����-1
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
///COrderRttKey�����˱���������
///@author	�ܽ���
///@version	1.0,20080710
/////////////////////////////////////////////////////////////////////////
class COrderRttAnalysis
{
	/* */
	private:
		///���浱ǰ���еı�������
			///@param	key	����������Ϣ
			///@param	value	��ͬ����������ʱ���б�
		map<COrderRttKey, CIntList> m_mapOrderRtt;

		///�������ݰ�����ǰ�÷���ͳ��ֵ
			///@param	key	ǰ�ñ��0~63,���λΪ�������ı��
			///@param	value	ǰ�õ����ݰ���Ӧʱ�����ͳ���ܸ���
		map<CRttStatsKey, CRttPacketStats>	m_mapRttPacketNum;

		///����rtt��ǰ�õ�ͳ��
			///@param	key	ǰ�ñ��0~63,���λΪ�������ı��
		map<int, CRttInSec4Front> m_mapRttStaticsFront;

	/* */
	public:
		///OFP���ݰ�������
			///@param	pOFPPackage	ofp���ݰ���ַ
			///@param	nSessionID	�����Ự��ID���
			///@param	nFrontID	������ǰ��ID���
			///@param	cVsersion	OFPЭ��汾
		void OnOFPPackage(
				COFPPackage *pOFPPackage,
				int nSessionID,
				int nFrontID,
				char cVersion);

		///FTD���ݰ�������
			///@param	pFTDPackage	FTD���ݰ���ַ
			///@param	nSessionID	�����Ự��ID���
			///@param	nFrontID	������ǰ��ID���
			///@param	cVsersion	FTDЭ��汾
		void OnFTDCPackage(
				CFTDCPackage *pPackage,
				int nSessionID,
				int nFrontID,
				char cVersion);

		///������������
			///@param	UserID	�������û�ID
			///@param	OrderLocalID	�����ı��ر��
			///@param	nSessionID	�����Ự��ID���
			///@param	nFrontID	������ǰ��ID���
			///@param	cVsersion	Э��汾
		void HandleOrderReq(
				const CUserIDType &UserID,
				const COrderLocalIDType &OrderLocalID,
				int nSessionID,
				int nFrontID,
				char cVersion);

		///������Ӧ������
			///@param	UserID	�������û�ID
			///@param	OrderLocalID	�����ı��ر��
			///@param	nSessionID	�����Ự��ID���
			///@param	nFrontID	������ǰ��ID���
			///@param	cVsersion	Э��汾
		void HandleOrderRsp(
				const CUserIDType &UserID,
				const COrderLocalIDType &OrderLocalID,
				int nSessionID,
				int nFrontID,
				char cVersion);

		///ȡͳ��ֵ����
			///@return	���ص�ǰ����ǰ�õ�ͳ��map
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

		///ͳ�ƽ��д���������ݿ�
		void putRttAnalysisToDB(void);

		///���캯��
		COrderRttAnalysis(void)
		{
		}

		///20080716 add by wu.yb
		
		
			//////////////////////////////////////////////////////////////////////////
		//20121023 feng.q
		CRttInSec4Front &GetOrderRttStatic(int nFront);

		map<int, CRttInSec4Front> &GetOrderRttMap(void);

		bool CheckRtnIsReady(map<int, CRttReadyMap> &mapRttForRtn);

		//������б�����, ���û�б�������ͼ�鿴��Ӧǰ�õ��ļ���ȡ״̬
		int GetOrderRttSum(int nFrontID, char *pcErrMsg);

	//////////////////////////////////////////////////////////////////////////
	private:
		///�������ݿ⣬����������ŵģ��Ͳ��ٽ�������
		void connectDB(void);

		///����ȫ�ֱ���������ip:port/dbname���ַ���
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
		///���ݿ�����Ӿ�� (����ʹ�õĲ���������sysquery.cpp)
		SAConnection m_sqlConnect;
};
#endif // end REF_CORDERRTTMANAGER_H
