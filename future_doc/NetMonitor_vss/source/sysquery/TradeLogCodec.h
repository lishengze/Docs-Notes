/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file TradeLogCodec.h
///@brief TradeLog的编解码类，按系统规定的格式编解码
///@history
///20120319	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef TRADE_LOG_CODEC_H
#define TRADE_LOG_CODEC_H

#include "FtdPackageDesc.h"

/*
** 一条具体的trade log包含 数据包发生的时间、数据包的源IP、数据包所属会员的ID，数据包所属席位的ID，数据包长度信息。 
** 一条trade log的平面图如下：
**
** --------------------------------------------------------------------------------------------------------------------------------------
** | 9 Bytes   | 16 Bytes    | 11 Bytes         | 16 Bytes  | 6 Bytes | 16 Bytes   | 4 Bytes          | packet length Bytes
** --------------------------------------------------------------------------------------------------------------------------------------
** | time       | ip              | member id      | user id    | front id  | session id | packet length  | packet content
** --------------------------------------------------------------------------------------------------------------------------------------
**
** TradeLog通过TradeLogStr（一个大的字符串 3900 Bytes）返回给客户端。一个TradeLogStr可能承载多条TradeLog
**TradeLogStr的平面图如下：
**
** -------------------------------------------------------------------------------------------------------------------
** | 2 Bytes                | trade log length Bytes   | trade log length Bytes   | ...
** -------------------------------------------------------------------------------------------------------------------
** | trade log number   | trade log content          | trade log content          | ...
** -------------------------------------------------------------------------------------------------------------------
**
**
*/
class CSlogSouceKey
{
	/* */
	public:
		///数据包的时间戳
		string	m_sTime;

		///数据包来源的IP地址
		string	m_sIpAddr;

		///数据包所属会员的ID
		string	m_sMemberId;

		///数据包所属席位的ID
		string	m_sUserId;

		///数据包所属的交易前置号，为查询特定前置最后几个报文所用
		string	m_frontID;

		/// 数据包所属的会话ID号
		string	m_sessionID;

	/* */
	public:
		void print(void)
		{
			printf(
				"[%s][%s][%s][%s][%s][%s]",
				m_sTime.c_str(),
				m_sIpAddr.c_str(),
				m_sMemberId.c_str(),
				m_sUserId.c_str(),
				m_frontID.c_str(),
				m_sessionID.c_str());
		}

		CSlogSouceKey(void)
		{
			m_sTime = "";
			m_sIpAddr = "";
			m_sMemberId = "";
			m_sUserId = "";
			m_frontID = "";
			m_sessionID = "";
		}

		///构造函数
		    ///@param	pTime	时间
		    ///@param	pIpAddr	IP地址
		    ///@param	pMemberId	会员号
		    ///@param	pUserId	席位号
		    ///@param	frontID	交易前置标识
		CSlogSouceKey(
		char *pTime,
		char *pIpAddr,
		char *pMemberId,
		char *pUserId,
		int frontID,
		int sessionID)
		{
			m_sTime = pTime;
			m_sIpAddr = pIpAddr;
			m_sMemberId = pMemberId;
			m_sUserId = pUserId;

			char buf[16];
			sprintf(buf, "%d", frontID);
			m_frontID = buf;

			sprintf(buf, "%d", sessionID);
			m_sessionID = buf;
		}

		///构造函数
		    ///@param	pTime	时间
		    ///@param	pIpAddr	IP地址
		    ///@param	pMemberId	会员号
		    ///@param	pUserId	席位号
		CSlogSouceKey(
		char *pTime,
		string	&pIpAddr,
		string	&pMemberId,
		string	&pUserId,
		int frontID,
		int sessionID)
		{
			m_sTime = pTime;
			m_sIpAddr = pIpAddr;
			m_sMemberId = pMemberId;
			m_sUserId = pUserId;

			char buf[16];
			sprintf(buf, "%d", frontID);
			m_frontID = buf;

			sprintf(buf, "%d", sessionID);
			m_sessionID = buf;
		}

		CSlogSouceKey(const CSlogSouceKey &ob)
		{
			m_sTime = ob.m_sTime;
			m_sIpAddr = ob.m_sIpAddr;
			m_sMemberId = ob.m_sMemberId;
			m_sUserId = ob.m_sUserId;
			m_frontID = ob.m_frontID;
			m_sessionID = ob.m_sessionID;
		}

		void operator=(const CSlogSouceKey &ob)
		{
			m_sTime = ob.m_sTime;
			m_sIpAddr = ob.m_sIpAddr;
			m_sMemberId = ob.m_sMemberId;
			m_sUserId = ob.m_sUserId;
			m_frontID = ob.m_frontID;
			m_sessionID = ob.m_sessionID;
		}

		bool operator>(const CSlogSouceKey &ob) const
		{
			if (this->m_sTime > ob.m_sTime
			||	(
					this->m_sTime == ob.m_sTime
			&&	this->m_sIpAddr > ob.m_sIpAddr
			)
			||	(
					this->m_sTime == ob.m_sTime
			&&	this->m_sIpAddr == ob.m_sIpAddr
			&&	this->m_sMemberId > ob.m_sMemberId
			)
			||	(
					this->m_sTime == ob.m_sTime
			&&	this->m_sIpAddr == ob.m_sIpAddr
			&&	this->m_sMemberId == ob.m_sMemberId
			&&	this->m_sUserId > ob.m_sUserId
			))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool operator < (const CSlogSouceKey &ob)const
		{
			// It not be !(opertator> || operator==)
			if (this->m_sTime < ob.m_sTime
			||	(
					this->m_sTime == ob.m_sTime
			&&	this->m_sIpAddr < ob.m_sIpAddr
			)
			||	(
					this->m_sTime == ob.m_sTime
			&&	this->m_sIpAddr == ob.m_sIpAddr
			&&	this->m_sMemberId < ob.m_sMemberId
			)
			||	(
					this->m_sTime == ob.m_sTime
			&&	this->m_sIpAddr == ob.m_sIpAddr
			&&	this->m_sMemberId == ob.m_sMemberId
			&&	this->m_sUserId < ob.m_sUserId
			))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool operator==(const CSlogSouceKey &ob) const
		{
			if (this->m_sTime == ob.m_sTime
			&&	this->m_sIpAddr == ob.m_sIpAddr
			&&	this->m_sMemberId == ob.m_sMemberId
			&&	this->m_sUserId == ob.m_sUserId)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

typedef struct
{
	CSlogSouceKey meta_data;
	string	pkg_content;
} SlogData;

class TradeLogCodec
{
	/* */
	public:
		TradeLogCodec(void);

		~TradeLogCodec(void)
		{
			Clean();
		}

		void Clean(void);

		///保存slog数据，注意，需要确保能够容纳这些数据
		    ///@data	被保存的slog数据，不能为空
		void Encode(const CSlogSouceKey &header, const char *data);

		///输出经过编码的TradeLog信息
		    ///@return	将先前的slog数据以CFTDRspQryTradeLogField的形式输出
		vector<CFTDRspQryTradeLogField> OutPutEncodedSlog(void);

		///解码TradeLog内容
		    ///@param tradeLog，TradeLog信息集合，不允许有不完整的TradeLog信息。
		    ///@return	解析后的Slog 数据
		vector<SlogData> Decode(vector<CFTDRspQryTradeLogField> &tradeLog);

	/* */
	private:
		///是否有足够的空间容纳当前slog数据
		    ///@data	被保存的slog数据，不能为空
		    ///@return	true，有足够空间，false，没有足够空间
		bool hasSpace(const char *data);

		///将先前保存的slog数据消化，并将新的slog数据保存。
		    ///@data	被保存的slog数据，如果为空，则只消化先前的slog数据
		    ///@return	将先前的slog数据以CFTDRspQryTradeLogField的形式排出
		void encodeWithoutSpace(
				const CSlogSouceKey &header,
				const char	*data = NULL);

		///保存slog数据，注意，需要确保能够容纳这些数据
		    ///@data	被保存的slog数据，不能为空
		void encodeWithSpace(const CSlogSouceKey &header, const char *data);

		///处理buf中已存在的Slog
		CFTDRspQryTradeLogField outputOldSlog(void);

		///处理一个大的Slog信息
		vector<CFTDRspQryTradeLogField> outputLargeSlog(
											const CSlogSouceKey &header,
											const char	*data);

		void encodeHeader(const CSlogSouceKey &header, int dataLen);

		void encodeBody(const char *data, int dataLen);

		void encodeSlogNumber(void);

		///重置Buf
		void resetBuf(void);

		vector<SlogData> decodeTradeLog(CFTDRspQryTradeLogField tradeLog);

	/* */
	private:
		CFTDRspQryTradeLogField m_slogField;
		char *m_buf;			// m_slogField中存储Slog的buf头
		int m_buflen;			// m_slogField中存储Slog的buf的总长度
		char *m_buf_remained;	// m_slogField中存储Slog的buf可用起始地址
		int m_slog_number;		// m_slogField中存储Slog的buf中存储的Slog数量
		vector<CFTDRspQryTradeLogField> m_encodedSlogs;
};

inline void TradeLogCodec::Clean(void)
{
	resetBuf();
	m_encodedSlogs.clear();
}

inline void TradeLogCodec::Encode(const CSlogSouceKey &header, const char *data)
{
	if (hasSpace(data))
	{
		encodeWithSpace(header, data);
	}
	else
	{
		encodeWithoutSpace(header, data);
	}
}

inline void TradeLogCodec::encodeWithSpace(
	const CSlogSouceKey &header,
	const char	*data)
{
	assert(data && hasSpace(data));

	int dataLen = strlen(data);

	encodeHeader(header, dataLen);
	encodeBody(data, dataLen);
}

inline void TradeLogCodec::encodeWithoutSpace(
	const CSlogSouceKey &header,
	const char	*data)
{
	if (m_slog_number > 0)
	{
		m_encodedSlogs.push_back(outputOldSlog());
	}

	if (hasSpace(data))
	{
		encodeWithSpace(header, data);
	}
	else
	{
		vector<CFTDRspQryTradeLogField> s = outputLargeSlog(header, data);
		for (size_t i = 0; i < s.size(); i++)
		{
			m_encodedSlogs.push_back(s[i]);
		}
	}
}

inline CFTDRspQryTradeLogField TradeLogCodec::outputOldSlog(void)
{
	m_slogField.bFlag = 0;
	*m_buf_remained = '\0';
	encodeSlogNumber();

	resetBuf();

	return m_slogField;
}

inline vector<CFTDRspQryTradeLogField> TradeLogCodec::OutPutEncodedSlog(void)
{
	if (m_slog_number > 0)
	{
		m_encodedSlogs.push_back(outputOldSlog());
	}

	return m_encodedSlogs;
}

inline void TradeLogCodec::encodeBody(const char *data, int dataLen)
{
	assert(m_buf + m_buflen - m_buf_remained >= dataLen);

	memcpy(m_buf_remained, data, dataLen);
	m_buf_remained += dataLen;
	m_slog_number++;
}

inline void TradeLogCodec::encodeSlogNumber(void)
{
	char buf[6];
	sprintf(buf, "%-2d", m_slog_number);
	memcpy(m_buf, buf, 2);
}

inline void TradeLogCodec::resetBuf(void)
{
	m_slog_number = 0;
	m_buf_remained = m_buf + 2;
}

#endif // TRADE_LOG_CODEC_H
