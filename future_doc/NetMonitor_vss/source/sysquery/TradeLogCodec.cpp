/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file TradeLogCodec.cpp
///@brief TradeLog的编解码类，按系统规定的格式编解码
///@history
///20120319	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#include "TradeLogCodec.h"

// time, ip, memberID, userID, frontID, sessionID, pkgLen
static int	slog_data_header_len = 9 + 16 + 11 + 16 + 6 + 16 + 4;
static const char *slog_data_head_str = "%-9s%-16s%-11s%-16s%-6s%-16s%-4d";

TradeLogCodec::TradeLogCodec(void)
{
	m_buf = (char *)m_slogField.TradeLogStr.getValue();
	m_buf_remained = m_buf + 2;						// 2 offset kept for m_slog_number "%-2d"
	m_buflen = sizeof(m_slogField.TradeLogStr) - 1; // The last is reversed for '\0'
	*(m_buf + m_buflen) = '\0';

	m_slog_number = 0;
}

bool TradeLogCodec::hasSpace(const char *data)
{
	assert(data);

	int space = m_buf + m_buflen - m_buf_remained - slog_data_header_len;
	int dataLen = strlen(data);

	return (dataLen > space ? false : true);
}

vector<CFTDRspQryTradeLogField> TradeLogCodec::outputLargeSlog(
	const CSlogSouceKey &header,
	const char	*data)
{
	vector<CFTDRspQryTradeLogField> fields;

	int dataLen = strlen(data);

	// 系统中一个报文最多用2个CFTDRspQryTradeLogField就可以来承载
	if (dataLen + 2 * slog_data_header_len > 2 * m_buflen)
	{
		printf(
			"Error: trade log is large, cann't be stored by two CFTDRspQryTradeLogField!!\n");
		return fields;
	}

	int data_part_len = m_buflen - 2 - slog_data_header_len;

	m_slogField.bFlag = 1;
	encodeHeader(header, data_part_len);
	encodeBody(data, data_part_len);
	encodeSlogNumber();

	fields.push_back(m_slogField);

	resetBuf();

	data += data_part_len;
	data_part_len = dataLen - data_part_len;

	m_slogField.bFlag = 0;
	encodeHeader(header, data_part_len);
	encodeBody(data, data_part_len);
	encodeSlogNumber();

	fields.push_back(m_slogField);

	resetBuf();

	return fields;
}

void TradeLogCodec::encodeHeader(const CSlogSouceKey &header, int dataLen)
{
	assert(m_buf + m_buflen - m_buf_remained >= slog_data_header_len);

	sprintf(
		m_buf_remained,
		slog_data_head_str,
		header.m_sTime.c_str(),
		header.m_sIpAddr.c_str(),
		header.m_sMemberId.c_str(),
		header.m_sUserId.c_str(),
		header.m_frontID.c_str(),
		header.m_sessionID.c_str(),
		dataLen);

	m_buf_remained += slog_data_header_len;
}

vector<SlogData> TradeLogCodec::Decode(
	vector<CFTDRspQryTradeLogField> &tradeLog)
{
	vector<SlogData> decoded_slog;

	int n = tradeLog.size();
	if (tradeLog[n - 1].bFlag)
	{
		// 有不完整的tradelog记录，直接返回
		return decoded_slog;
	}

	for (int i = 0; i < n; i++)
	{
		if (tradeLog[i].bFlag == 0)
		{	//单一完整包
			vector<SlogData> tmp = decodeTradeLog(tradeLog[i]);
			for (int i = 0; i < tmp.size(); i++)
			{
				decoded_slog.push_back(tmp[i]);
			}
		}
		else
		{	// 2个组合包
			vector<SlogData> tmp1 = decodeTradeLog(tradeLog[i]);
			i++;

			vector<SlogData> tmp2 = decodeTradeLog(tradeLog[i]);
			tmp1[0].pkg_content += tmp2[0].pkg_content;

			decoded_slog.push_back(tmp1[0]);
		}
	}

	return decoded_slog;
}

vector<SlogData> TradeLogCodec::decodeTradeLog(CFTDRspQryTradeLogField tradeLog)
{
	const char	*curr = tradeLog.TradeLogStr.getValue();
	vector<SlogData> slogDataSet;

	char str_slog_number[3] = { 0 };
	strncpy(str_slog_number, curr, 2);
	curr += 2;

	int slog_number = atoi(str_slog_number);

	for (int i = 0; i < slog_number; i++)
	{
		char str_time[10] = { 0 };
		char str_ip[17] = { 0 };
		char str_member[12] = { 0 };
		char str_user[17] = { 0 };
		char str_front[7] = { 0 };
		char str_session[17] = { 0 };
		char str_pkg_len[5] = { 0 };
		char str_pkg_content[4000] = { 0 };

		strncpy(str_time, curr, 9);
		curr += 9;

		strncpy(str_ip, curr, 16);
		curr += 16;

		strncpy(str_member, curr, 11);
		curr += 11;

		strncpy(str_user, curr, 16);
		curr += 16;

		strncpy(str_front, curr, 6);
		curr += 6;

		strncpy(str_session, curr, 16);
		curr += 16;

		strncpy(str_pkg_len, curr, 4);
		curr += 4;

		int pkg_len = atoi(str_pkg_len);
		strncpy(str_pkg_content, curr, pkg_len);
		curr += pkg_len;

		SlogData slog;
		slog.meta_data.m_sTime = str_time;
		slog.meta_data.m_sIpAddr = str_ip;
		slog.meta_data.m_sMemberId = str_member;
		slog.meta_data.m_sUserId = str_user;
		slog.meta_data.m_frontID = str_front;
		slog.meta_data.m_sessionID = str_session;
		slog.pkg_content = str_pkg_content;

		slogDataSet.push_back(slog);
	}

	return slogDataSet;
}
