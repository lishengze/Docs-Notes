/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CListSession.h
///@brief	�����˻Ự�б����
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
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
///CListSession�����˻Ự�����б���
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CListSession
{
	/* */
	private:
		///������һ�����Ķ�������лỰ����
		list<CFTDCSession *> m_mSessionList;

		///�Ự�����б�ĵ�����
		list<CFTDCSession *>::iterator	m_mListIt;

	/* */
	public:
		///���캯��
		CListSession(void);

		///��������
		~ CListSession(void);

		///���ӻỰ����,���б�������һ���Ự,���ûỰ�Ѵ���������
			///@param	pSession	��Ҫ���ӵ�FTDC�Ựָ��
		void AddFlow(CFTDCSession *pSession);

		///ɾ���Ự����,ɾ���б��е�һ���Ự,���ûỰ�����ھ�ֱ�ӷ���
			///@param	pSession	��Ҫɾ����FTDC�Ựָ��
		void DelFlow(CFTDCSession *pSession);

		///�������ݰ�����,����FTDC���ݰ�����ǰ��������лỰ������
			///@param	pFTDCPackage	ָ�������ݰ���ָ��
			///@param	pHashKey	���ݰ������Ķ��Ķ���ID
		void SendPackage(CFTDCPackage *pFTDCPackage, const char *pHashKey);
};

class CMapSession
{
	/* */
	private:
		///������һ�����Ķ�������лỰ����
		map<CFTDCSession *, bool> m_mSessionMap;

		///�Ự����mapʹ�õĵ�����
		map<CFTDCSession *, bool>::iterator m_mMapIt;

	/* */
	public:

		///���캯��
		CMapSession(void)
		{
		}

		///��������
		~CMapSession(void)
		{
		}

		///���ӻỰ����,���б�������һ���Ự,���ûỰ�Ѵ���������
			///@param	pSession	��Ҫ���ӵ�FTDC�Ựָ��
		void AddFlow(CFTDCSession *pSession)
		{
			m_mSessionMap[pSession] = true;
		}

		///ɾ���Ự����,ɾ���б��е�һ���Ự,���ûỰ�����ھ�ֱ�ӷ���
			///@param	pSession	��Ҫɾ����FTDC�Ựָ��
		void DelFlow(CFTDCSession *pSession)
		{
			m_mSessionMap.erase(pSession);
		}

		///�������ݰ�����,����FTDC���ݰ�����ǰ��������лỰ������
			///@param	pFTDCPackage	ָ�������ݰ���ָ��
			///@param	pHashKey	���ݰ������Ķ��Ķ���ID
		void SendPackage(CFTDCPackage *pFTDCPackage, const char *pHashKey)
		{
			int i = 1;
			for (m_mMapIt = m_mSessionMap.begin();
				 m_mMapIt != m_mSessionMap.end();
				 ++m_mMapIt)
			{
				CFTDCSession *pSession = m_mMapIt->first;

				//			printf("CMapSession::SendPackage:������ %d ���ĸ��� %d ObjectId %s\n",pFTDCPackage->Length(),i, (char *)pHashKey);
				pSession->SendRequestPackage(pFTDCPackage);
				pFTDCPackage->Pop(FTDCHLEN);
				i++;
			}
		}
};

/////////////////////////////////////////////////////////////////////////
///CListSessionArray�����˻Ự��������б�������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CListSessionArray
{
	/* */
	private:
		///ɢ������Ͳ�Ĵ�С
		int m_mHashSize;

		///�Ự�������ָ��
		CMapSession *m_pList;

		///����ID
		CStringIdMap m_mStringIdMap;

		CIntMonitorIndex *m_pObjectAttrCountIndex;

	/* */
	public:
		///���캯��,����ʱ��������Ĵ�СΪm_mHashSize
		CListSessionArray(void);

		///���캯��,����ʱ��������Ĵ�СΪm_mHashSize = iSize
		CListSessionArray(int iSize);

		///��������,����ʱ�ͷ����������ռ�
		~ CListSessionArray(void);

		///���Ӷ��Ķ�����,һ���Ự���Ӷ���һ������
			///@param	pSession	���Ӷ��Ķ���ĻỰ��ַ
			///@param	pHashKey	���Ķ����ID
		void AddSubcriberObject(CFTDCSession *pSession, char *pHashKey);	// ���Ӷ���һ������
		
			///ȡ�����Ķ�����,һ���Ựȡ������һ������
			///@param	pSession	���Ӷ��Ķ���ĻỰ��ַ
			///@param	pHashKey	���Ķ����ID
		void DelSubcriberObject(CFTDCSession *pSession, char *pHashKey);	// ȡ������һ������
		
			///�������ݰ�����,����FTDC���ݰ����ĸ����ݵĻỰ
			///@param	pFTDCPackage	ָ�������ݰ���ָ��
			///@param	pHashKey	���ݰ������Ķ��Ķ���ID
		void SendPackage(CFTDCPackage *pFTDCPackage, const char *pHashKey); // ����һ�����ݰ�
		
			///ɾ���Ự����,��������,ɾ�����ڸûỰ�ĻỰ,�ͻ������ӶϿ�ʱ��Ҫɾ���ÿͻ��˶��ĵ����ж���
			///@param	pSession	��Ҫɾ���ĻỰָ��
		void DelFTDSession(CFTDCSession *pSession);

		void SetListSize(int iListSize);
};
#endif // REF_CLISTSESSION_H END
