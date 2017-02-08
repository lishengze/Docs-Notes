/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CDumpSession.h
///@brief	定义了数据包过滤的类
///@auther	赵鸿昊
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

		///OFP数据包输出函数
			///@param	pOutHeadStr	数据包头输出缓冲区
			///@param	nHeadStrLength	数据包头长度
			///@param	pOutBodyStr	数据包输出缓冲区
			///@param	nBodyStrLength	数据包输出缓冲区长度

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

			//pLogger->output(LL_DEBUG, "\tOFP报文头:%s\n", buffer);
			printf("\tOFP报文头:%s\n", buffer);

			if (m_OFPHeader.CommandID == 0x0701)
			{
				if (Length() < 12)
				{
					//pLogger->output(LL_DEBUG, "\tOFP报文内容：私有流报文内容长度不对\n");
					printf("\tOFP报文内容：私有流报文内容长度不对\n");
					return;
				}

				memcpy(buffer, Address(), 8);
				buffer[8] = '\0';

				//pLogger->output(LL_DEBUG, "\tOFP报文内容：[%s", buffer);
				printf("\tOFP报文内容：[%s", buffer);

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

				//pLogger->output(LL_DEBUG, "\tOFP报文内容：[%s]\n", buffer);
				printf("\tOFP报文内容：[%s]\n", buffer);
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
		///Slog会话的ID
		int m_nSlogId;

		///前置的ID
		int m_nFrontId;

		///对应文件的ID
		int m_nFileId;

		///会话对应的IP地址
		string	m_sIpAddr;

		///会话对应的会员ID
		string	m_sMemberId;

		///会话对应的席位ID
		string	m_sUserId;

		///协议版本
		char m_cVersion;

		///读写标记,READ,WRITE
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
		///Slog会话的ID
		int m_nSlogId;

		///前置的ID
		int m_nFrontId;

		///对应文件的ID
		int m_nFileId;

		///会话对应的IP地址
		string	m_sIpAddr;

		///会话对应的会员ID
		string	m_sMemberId;

		///会话对应的席位ID
		string	m_sUserId;

		///协议版本
		char m_cVersion;

		///读写标记,READ,WRITE
		string	m_sRWFlag;
};

class CSlogQuery
{
	/* */
	public:

		///构造函数
		CSlogQuery(void)
		{
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
		}

		///析构函数
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

		///Slog查询函数
			///@param	pFTDCPackage	查询请求数据包地址
			///@param	pSession	查询请求的会话
		void querySlog(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///前置最后报文查询函数
		    ///@param	pFTDCPackage	查询请求数据包地址
		    ///@param	pSession	查询请求的会话
		void queryLatestSlog(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///保存数据包函数
			///@param	pTime	数据包处理时间
			///@param	sIpAddr	会员登录的IP地址
			///@param	sMemberId	会员ID
			///@param	sUserId	席位的ID
			///@param	frontID	数据包所属的前置ID
			///@param	sessionID	数据包的会话ID
			///@param	sRWFlag	读写标记
			///@param	pValue	数据包输出的字符串
			///@param	nLength	数据包内容长度
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

		///打印输出函数
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

		///应答解析函数
		void analysisSlog(CFTDRspQryTradeLogField *pField);

	/* */
	private:
		void notifyFrontByNewSlogPkg(
				int frondID,
				const CSlogSouceKey &pkgInfo,
				const char	*pkg);

		//前置的最近数据包缓冲池
		struct FrontPKG
		{
			FrontPKG (const CSlogSouceKey &pkgInfo, const char *pkg)
			:
			pkg_info(pkgInfo),
			pkg_content(pkg)
			{
			}

			CSlogSouceKey pkg_info;				//数据包的属性信息：数据包的时间戳、所属会员ID、所属席位ID。
			const char	*pkg_content;			//数据包内容，不管理其生命周期。
		};

		struct Front_latest_PKG
		{
			list<FrontPKG>	latest_PKG;			//最近的数据包，按时间排序，最新的数据包在最前面。
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

		///保存数据包用的multimap
		SLOGSOURCEMAP m_mapSlog;

		/// frontID : Front_latest_PKG Map
		map<int, Front_latest_PKG>	m_front_last_pkg;

		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;
};
#endif // end REF_CDUMPSESSION_H
