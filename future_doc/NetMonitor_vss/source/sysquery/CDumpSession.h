/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CDumpSession.h
///@brief	���������ݰ����˵���
///@auther	�Ժ��
///@history
#ifndef REF_CDUMPSESSION_H
#define REF_CDUMPSESSION_H

#include "public.h"
#include "FTDCSession.h"
#include "OFPSession.h"
#include "CLogger.h"
#include "FtdPackageDesc.h"
#include "TradeLogCodec.h"

class COFPPackageOutPut :
	public COFPPackage
{
	/* */
	public:

		///OFP���ݰ��������
			///@param	pOutHeadStr	���ݰ�ͷ���������
			///@param	nHeadStrLength	���ݰ�ͷ����
			///@param	pOutBodyStr	���ݰ����������
			///@param	nBodyStrLength	���ݰ��������������

		//void stringOutPut(char *pOutHeadStr, int & nHeadStrLength, char *pOutBodyStr, int &nBodyStrLength)
		void stringOutPut(void)
		{
			char temp[20];
			char buffer[OFP_PACKAGE_MAX_SIZE + 1];
			sprintf(buffer, "|%s", m_OFPHeader.Command.getValue());
			sprintf(
				buffer + strlen(buffer),
				"|%d",
				m_OFPHeader.Length.getValue());
			sprintf(
				buffer + strlen(buffer),
				"|%s",
				m_OFPHeader.Echo.getValue());
			memcpy(temp, m_OFPHeader.SenderAdd.getValue(), 16);
			temp[16] = 0;
			sprintf(buffer + strlen(buffer), "|%s", temp);
			memcpy(temp, m_OFPHeader.ReceiverAdd.getValue(), 16);
			temp[16] = 0;
			sprintf(buffer + strlen(buffer), "|%s", temp);

			WORD wSenderFlowType;

			WORD wReceiveFlowType;
			memcpy(&wSenderFlowType, m_OFPHeader.SenderFlowType, sizeof(WORD));
			memcpy(
				&wReceiveFlowType,
				m_OFPHeader.ReceiveFlowType,
				sizeof(WORD));

			DWORD dwSenderFlowSeqNo;

			DWORD dwReceiveFlowSeqNo;
			memcpy(
				&dwSenderFlowSeqNo,
				m_OFPHeader.SenderFlowSeqNo,
				sizeof(DWORD));
			memcpy(
				&dwReceiveFlowSeqNo,
				m_OFPHeader.ReceiveFlowSeqNo,
				sizeof(DWORD));

			sprintf(
				buffer + strlen(buffer),
				"|%04x|%08x|%04x|%08x",
				wSenderFlowType,
				dwSenderFlowSeqNo,
				wReceiveFlowType,
				dwReceiveFlowSeqNo);
			sprintf(
				buffer + strlen(buffer),
				"|%02x|%04x|%c|%c",
				m_OFPHeader.Start.getValue(),
				m_OFPHeader.CommandID,
				m_OFPHeader.IsFirst.getValue(),
				m_OFPHeader.NotLast.getValue());

			//pLogger->output(LL_DEBUG, "\tOFP����ͷ:%s\n", buffer);
			printf("\tOFP����ͷ:%s\n", buffer);

			if (m_OFPHeader.CommandID == 0x0701)
			{
				if (Length() < 12)
				{
					//pLogger->output(LL_DEBUG, "\tOFP�������ݣ�˽�����������ݳ��Ȳ���\n");
					printf("\tOFP�������ݣ�˽�����������ݳ��Ȳ���\n");
					return;
				}

				memcpy(buffer, Address(), 8);
				buffer[8] = '\0';

				//pLogger->output(LL_DEBUG, "\tOFP�������ݣ�[%s", buffer);
				printf("\tOFP�������ݣ�[%s", buffer);

				DWORD x;
				memcpy(&x, Address() + 8, 4);

				//pLogger->output(LL_DEBUG, ":%04X:", x);
				printf(":%04X:", x);
				memcpy(buffer, Address() + 12, Length() - 12);
				buffer[Length() - 12] = '\0';

				//pLogger->output(LL_DEBUG, "%s]\n", buffer);
				printf("%s]\n", buffer);
			}
			else
			{
				memcpy(buffer, Address(), Length());
				buffer[Length()] = '\0';

				//pLogger->output(LL_DEBUG, "\tOFP�������ݣ�[%s]\n", buffer);
				printf("\tOFP�������ݣ�[%s]\n", buffer);
			}
		}

	/* */
	protected:
	/* */
	private:
};

class COfpDumpSession :
	public COFPSession
{
	/* */
	public:
		COfpDumpSession(CReactor *pReactor, CChannel *pChannel);
		COfpDumpSession(
			CReactor *pReactor,
			CChannel *pChannel,
			int nFrontId,
			int nFileId,
			string	&sIpAddr,
			char cVersion,
			char *pRWFlag);
		virtual int HandlePackage(CPackage *pPackage, CProtocol *pProtocol);
		virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam)
		{
			switch (nEventID)
			{
				case MSG_OFPERR_RECVHEARTBEAT:
				case MSG_OFPERR_SENDHEARTBEAT:
				case MSG_OFPERR_BADPACKAGE:
					//Disconnect(nEventID);
					return 0;
			}

			return CSession::HandleEvent(nEventID, dwParam, pParam);
		}

		virtual void OnChannelLost(int nErrorCode)
		{
			printf("Channel lost , error code = [%x]\n", nErrorCode);
			COFPSession::OnChannelLost(nErrorCode);
		}

	/* */
	private:
		///Slog�Ự��ID
		int m_nSlogId;

		///ǰ�õ�ID
		int m_nFrontId;

		///��Ӧ�ļ���ID
		int m_nFileId;

		///�Ự��Ӧ��IP��ַ
		string	m_sIpAddr;

		///�Ự��Ӧ�Ļ�ԱID
		string	m_sMemberId;

		///�Ự��Ӧ��ϯλID
		string	m_sUserId;

		///Э��汾
		char m_cVersion;

		///��д���,READ,WRITE
		string	m_sRWFlag;
};

class CFtdcDumpSession :
	public CFTDCSession
{
	/* */
	public:
		CFtdcDumpSession(CReactor *pReactor, CChannel *pChannel);
		CFtdcDumpSession(
			CReactor *pReactor,
			CChannel *pChannel,
			int nFrontId,
			int nFileId,
			string	&sIpAddr,
			char *pRWFlag);

		virtual int HandlePackage(CPackage *pPackage, CProtocol *pProtocol);

		virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam)
		{
			switch (nEventID)
			{
				case MSG_XMPERR_RECVHEARTBEAT:
				case MSG_XMPERR_SENDHEARTBEAT:
				case MSG_XMPERR_BADPACKAGE:
				case MSG_FTDCERR_BADPACKAGE:
					// Disconnect(nEventID);
					return 0;
				case MSG_XMPWARNING_RECVHEARTBEAT:
					if (m_pSessionCallback != NULL)
					{
						m_pSessionCallback->OnSessionWarning(
								this,
								nEventID,
								(int)dwParam);
					}

					return 0;
			}

			return CSession::HandleEvent(nEventID, dwParam, pParam);
		}

		virtual void OnChannelLost(int nErrorCode)
		{
			printf("Channel lost , error code = [%x]\n", nErrorCode);
			CFTDCSession::OnChannelLost(nErrorCode);
		}

	/* */
	private:
		///Slog�Ự��ID
		int m_nSlogId;

		///ǰ�õ�ID
		int m_nFrontId;

		///��Ӧ�ļ���ID
		int m_nFileId;

		///�Ự��Ӧ��IP��ַ
		string	m_sIpAddr;

		///�Ự��Ӧ�Ļ�ԱID
		string	m_sMemberId;

		///�Ự��Ӧ��ϯλID
		string	m_sUserId;

		///Э��汾
		char m_cVersion;

		///��д���,READ,WRITE
		string	m_sRWFlag;
};

class CSlogQuery
{
	/* */
	public:

		///���캯��
		CSlogQuery(void)
		{
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
		}

		///��������
		~CSlogQuery(void)
		{
			for (SLOGSOURCEMAP::iterator it = m_mapSlog.begin();
				 it != m_mapSlog.end();
				 it++)
			{
				if ((*it).second != NULL)
				{
					free((*it).second);
				}
			}
		}

		///Slog��ѯ����
			///@param	pFTDCPackage	��ѯ�������ݰ���ַ
			///@param	pSession	��ѯ����ĻỰ
		void querySlog(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///ǰ������Ĳ�ѯ����
		    ///@param	pFTDCPackage	��ѯ�������ݰ���ַ
		    ///@param	pSession	��ѯ����ĻỰ
		void queryLatestSlog(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�������ݰ�����
			///@param	pTime	���ݰ�����ʱ��
			///@param	sIpAddr	��Ա��¼��IP��ַ
			///@param	sMemberId	��ԱID
			///@param	sUserId	ϯλ��ID
			///@param	frontID	���ݰ�������ǰ��ID
			///@param	sessionID	���ݰ��ĻỰID
			///@param	sRWFlag	��д���
			///@param	pValue	���ݰ�������ַ���
			///@param	nLength	���ݰ����ݳ���
		void savePackage(
				char *pTime,
				string	&sIpAddr,
				string	&sMemberId,
				string	&sUserId,
				int frontID,
				int sessionID,
				string	&sRWFlag,
				char *pValue,
				int nLength);

		///��ӡ�������
		void print(void)
		{
			for (SLOGSOURCEMAP::iterator it = m_mapSlog.begin();
				 it != m_mapSlog.end();)
			{
				printf(
					"[%s][%s][%s][%s][%s]\n",
					it->first.m_sTime.c_str(),
					it->first.m_sIpAddr.c_str(),
					it->first.m_sMemberId.c_str(),
					it->first.m_sUserId.c_str(),
					it->second);
				++it;
			}
		}

		///Ӧ���������
		void analysisSlog(CFTDRspQryTradeLogField *pField);

	/* */
	private:
		void notifyFrontByNewSlogPkg(
				int frondID,
				const CSlogSouceKey &pkgInfo,
				const char	*pkg);

		//ǰ�õ�������ݰ������
		struct FrontPKG
		{
			FrontPKG (const CSlogSouceKey &pkgInfo, const char *pkg)
			:
			pkg_info(pkgInfo),
			pkg_content(pkg)
			{
			}

			CSlogSouceKey pkg_info;				//���ݰ���������Ϣ�����ݰ���ʱ�����������ԱID������ϯλID��
			const char	*pkg_content;			//���ݰ����ݣ����������������ڡ�
		};

		struct Front_latest_PKG
		{
			list<FrontPKG>	latest_PKG;			//��������ݰ�����ʱ���������µ����ݰ�����ǰ�档
			Front_latest_PKG (const CSlogSouceKey &pkgInfo, const char *pkg)
			{
				insert(pkgInfo, pkg);
			}

			void insert(const CSlogSouceKey &pkgInfo, const char *pkg)
			{
				static size_t pkg_limit = 1000; // TODO: get from config
				assert(pkg);

				if (latest_PKG.size() >= pkg_limit)
				{
					latest_PKG.pop_back();
				}

				latest_PKG.push_front(FrontPKG(pkgInfo, pkg));
			}
		};

	/* */
	private:
		typedef multimap<CSlogSouceKey, char *> SLOGSOURCEMAP;

		///�������ݰ��õ�multimap
		SLOGSOURCEMAP m_mapSlog;

		/// frontID : Front_latest_PKG Map
		map<int, Front_latest_PKG>	m_front_last_pkg;

		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;
};
#endif // end REF_CDUMPSESSION_H
