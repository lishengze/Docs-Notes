/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file TradeLogCodec.h
///@brief TradeLog�ı�����࣬��ϵͳ�涨�ĸ�ʽ�����
///@history
///20120319	��־ΰ   �������ļ�
/////////////////////////////////////////////////////////////////////////
#ifndef TRADE_LOG_CODEC_H
#define TRADE_LOG_CODEC_H

#include "FtdPackageDesc.h"

/*
** һ�������trade log���� ���ݰ�������ʱ�䡢���ݰ���ԴIP�����ݰ�������Ա��ID�����ݰ�����ϯλ��ID�����ݰ�������Ϣ�� 
** һ��trade log��ƽ��ͼ���£�
**
** --------------------------------------------------------------------------------------------------------------------------------------
** | 9 Bytes   | 16 Bytes    | 11 Bytes         | 16 Bytes  | 6 Bytes | 16 Bytes   | 4 Bytes          | packet length Bytes
** --------------------------------------------------------------------------------------------------------------------------------------
** | time       | ip              | member id      | user id    | front id  | session id | packet length  | packet content
** --------------------------------------------------------------------------------------------------------------------------------------
**
** TradeLogͨ��TradeLogStr��һ������ַ��� 3900 Bytes�����ظ��ͻ��ˡ�һ��TradeLogStr���ܳ��ض���TradeLog
**TradeLogStr��ƽ��ͼ���£�
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
		///���ݰ���ʱ���
		string	m_sTime;

		///���ݰ���Դ��IP��ַ
		string	m_sIpAddr;

		///���ݰ�������Ա��ID
		string	m_sMemberId;

		///���ݰ�����ϯλ��ID
		string	m_sUserId;

		///���ݰ������Ľ���ǰ�úţ�Ϊ��ѯ�ض�ǰ����󼸸���������
		string	m_frontID;

		/// ���ݰ������ĻỰID��
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

		///���캯��
		    ///@param	pTime	ʱ��
		    ///@param	pIpAddr	IP��ַ
		    ///@param	pMemberId	��Ա��
		    ///@param	pUserId	ϯλ��
		    ///@param	frontID	����ǰ�ñ�ʶ
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

		///���캯��
		    ///@param	pTime	ʱ��
		    ///@param	pIpAddr	IP��ַ
		    ///@param	pMemberId	��Ա��
		    ///@param	pUserId	ϯλ��
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

		///����slog���ݣ�ע�⣬��Ҫȷ���ܹ�������Щ����
		    ///@data	�������slog���ݣ�����Ϊ��
		void Encode(const CSlogSouceKey &header, const char *data);

		///������������TradeLog��Ϣ
		    ///@return	����ǰ��slog������CFTDRspQryTradeLogField����ʽ���
		vector<CFTDRspQryTradeLogField> OutPutEncodedSlog(void);

		///����TradeLog����
		    ///@param tradeLog��TradeLog��Ϣ���ϣ��������в�������TradeLog��Ϣ��
		    ///@return	�������Slog ����
		vector<SlogData> Decode(vector<CFTDRspQryTradeLogField> &tradeLog);

	/* */
	private:
		///�Ƿ����㹻�Ŀռ����ɵ�ǰslog����
		    ///@data	�������slog���ݣ�����Ϊ��
		    ///@return	true�����㹻�ռ䣬false��û���㹻�ռ�
		bool hasSpace(const char *data);

		///����ǰ�����slog���������������µ�slog���ݱ��档
		    ///@data	�������slog���ݣ����Ϊ�գ���ֻ������ǰ��slog����
		    ///@return	����ǰ��slog������CFTDRspQryTradeLogField����ʽ�ų�
		void encodeWithoutSpace(
				const CSlogSouceKey &header,
				const char	*data = NULL);

		///����slog���ݣ�ע�⣬��Ҫȷ���ܹ�������Щ����
		    ///@data	�������slog���ݣ�����Ϊ��
		void encodeWithSpace(const CSlogSouceKey &header, const char *data);

		///����buf���Ѵ��ڵ�Slog
		CFTDRspQryTradeLogField outputOldSlog(void);

		///����һ�����Slog��Ϣ
		vector<CFTDRspQryTradeLogField> outputLargeSlog(
											const CSlogSouceKey &header,
											const char	*data);

		void encodeHeader(const CSlogSouceKey &header, int dataLen);

		void encodeBody(const char *data, int dataLen);

		void encodeSlogNumber(void);

		///����Buf
		void resetBuf(void);

		vector<SlogData> decodeTradeLog(CFTDRspQryTradeLogField tradeLog);

	/* */
	private:
		CFTDRspQryTradeLogField m_slogField;
		char *m_buf;			// m_slogField�д洢Slog��bufͷ
		int m_buflen;			// m_slogField�д洢Slog��buf���ܳ���
		char *m_buf_remained;	// m_slogField�д洢Slog��buf������ʼ��ַ
		int m_slog_number;		// m_slogField�д洢Slog��buf�д洢��Slog����
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
