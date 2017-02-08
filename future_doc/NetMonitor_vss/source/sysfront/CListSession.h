/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CListSession.h
///@brief	定义了会话列表的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#ifndef REF_CLISTSESSION_H
#define REF_CLISTSESSION_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"

/////////////////////////////////////////////////////////////////////////
///CListSession定义了会话连接列表类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CListSession
{
	/* */
	private:
		///保存了一个订阅对象的所有会话连接
		list<CFTDCSession *> m_mSessionList;

		///会话连接列表的迭代器
		list<CFTDCSession *>::iterator	m_mListIt;

	/* */
	public:
		///构造函数
		CListSession(void);

		///析构函数
		~ CListSession(void);

		///增加会话函数,向列表中新增一个会话,若该会话已存在则不增加
			///@param	pSession	需要增加的FTDC会话指针
		void AddFlow(CFTDCSession *pSession);

		///删除会话函数,删除列表中的一个会话,若该会话不存在就直接返回
			///@param	pSession	需要删除的FTDC会话指针
		void DelFlow(CFTDCSession *pSession);

		///发送数据包函数,发送FTDC数据包到当前保存的所有会话连接上
			///@param	pFTDCPackage	指向发送数据包的指针
			///@param	pHashKey	数据包包含的订阅对象ID
		void SendPackage(CFTDCPackage *pFTDCPackage, const char *pHashKey);
};

class CMapSession
{
	/* */
	private:
		///保存了一个订阅对象的所有会话连接
		map<CFTDCSession *, bool> m_mSessionMap;

		///会话连接map使用的迭代器
		map<CFTDCSession *, bool>::iterator m_mMapIt;

	/* */
	public:

		///构造函数
		CMapSession(void)
		{
		}

		///析构函数
		~CMapSession(void)
		{
		}

		///增加会话函数,向列表中新增一个会话,若该会话已存在则不增加
			///@param	pSession	需要增加的FTDC会话指针
		void AddFlow(CFTDCSession *pSession)
		{
			m_mSessionMap[pSession] = true;
		}

		///删除会话函数,删除列表中的一个会话,若该会话不存在就直接返回
			///@param	pSession	需要删除的FTDC会话指针
		void DelFlow(CFTDCSession *pSession)
		{
			m_mSessionMap.erase(pSession);
		}

		///发送数据包函数,发送FTDC数据包到当前保存的所有会话连接上
			///@param	pFTDCPackage	指向发送数据包的指针
			///@param	pHashKey	数据包包含的订阅对象ID
		void SendPackage(CFTDCPackage *pFTDCPackage, const char *pHashKey)
		{
			int i = 1;
			for (m_mMapIt = m_mSessionMap.begin();
				 m_mMapIt != m_mSessionMap.end();
				 ++m_mMapIt)
			{
				CFTDCSession *pSession = m_mMapIt->first;

				//			printf("CMapSession::SendPackage:包长度 %d 订阅个数 %d ObjectId %s\n",pFTDCPackage->Length(),i, (char *)pHashKey);
				pSession->SendRequestPackage(pFTDCPackage);
				pFTDCPackage->Pop(FTDCHLEN);
				i++;
			}
		}
};

/////////////////////////////////////////////////////////////////////////
///CListSessionArray定义了会话连接类的列表数组类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CListSessionArray
{
	/* */
	private:
		///散列数组筒的大小
		int m_mHashSize;

		///会话连接类的指针
		CMapSession *m_pList;

		///对象ID
		CStringIdMap m_mStringIdMap;

		CIntMonitorIndex *m_pObjectAttrCountIndex;

	/* */
	public:
		///构造函数,构造时申请数组的大小为m_mHashSize
		CListSessionArray(void);

		///构造函数,构造时申请数组的大小为m_mHashSize = iSize
		CListSessionArray(int iSize);

		///析构函数,析构时释放申请的数组空间
		~ CListSessionArray(void);

		///增加订阅对象函数,一个会话增加订阅一个对象
			///@param	pSession	增加订阅对象的会话地址
			///@param	pHashKey	订阅对象的ID
		void AddSubcriberObject(CFTDCSession *pSession, char *pHashKey);	// 增加订阅一个对象
		
			///取消订阅对象函数,一个会话取消订阅一个对象
			///@param	pSession	增加订阅对象的会话地址
			///@param	pHashKey	订阅对象的ID
		void DelSubcriberObject(CFTDCSession *pSession, char *pHashKey);	// 取消订阅一个对象
		
			///发送数据包函数,发送FTDC数据包订阅该数据的会话
			///@param	pFTDCPackage	指向发送数据包的指针
			///@param	pHashKey	数据包包含的订阅对象ID
		void SendPackage(CFTDCPackage *pFTDCPackage, const char *pHashKey); // 发送一个数据包
		
			///删除会话函数,遍历数组,删除等于该会话的会话,客户端连接断开时需要删除该客户端订阅的所有对象
			///@param	pSession	需要删除的会话指针
		void DelFTDSession(CFTDCSession *pSession);

		void SetListSize(int iListSize);
};
#endif // REF_CLISTSESSION_H END
