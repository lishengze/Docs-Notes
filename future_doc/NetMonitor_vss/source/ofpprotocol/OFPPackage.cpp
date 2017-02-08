// OFPPackage.cpp: implementation of the COFPPackage class.
//
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "OFPPackage.h"

const char *OFP_COMM_OK		= "OK";
const char *OFP_COMM_ERROR	= "ERROR";

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COFPPackage::COFPPackage()
{
}

COFPPackage::~COFPPackage()
{

}

DWORD COFPPackage::GetActiveID()
{
	return OFP_ACTIVEID;
}

int COFPPackage::ValidPackage()
{
	int pklen = Length();
	if (pklen < OFPHLEN) {		//包头尚未收全
		return -1;
	}
	m_OFPHeader.FromStream(m_pHead);

	int bodylen = GetContentLength();
	if (bodylen < 0 || OFPHLEN+bodylen > OFP_PACKAGE_MAX_SIZE) {	//超过报文长度限制
		return -2;
	}

	if (pklen >= (OFPHLEN-OFPEXTHLEN+bodylen)) 
	{
		m_pTail = m_pHead+OFPHLEN-OFPEXTHLEN+bodylen;
		Pop(OFPHLEN);
		return OFPHLEN-OFPEXTHLEN+bodylen;
	}
	
	return -1;
}

int COFPPackage::MakePackage()
{
//	TRACE0("COFPPackage::MakePackage Start\n");

	m_OFPHeader.Length = Length()+OFPEXTHLEN;

	char *buf = Push(OFPHLEN);
	if(buf == NULL) 
	{
		return -1;
	} 
	else 
	{
		m_OFPHeader.ToStream(buf);
	}

//	TRACE0("COFPPackage::MakePackage End\n");
	return 0;
}

void COFPPackage::PreparePackage(const char chVersion, const WORD dwCommandID,
		const char chIsFirst,  const char chNotLast)
{
	m_OFPHeader.Head = chVersion;			// 开始标志，固定为0x01 	
	m_OFPHeader.SenderAdd = "";				// PC端填0x20，交易系统返回信息时填PC登录用户名 
	m_OFPHeader.SenderFlowType = "  ";
	m_OFPHeader.SenderFlowSeqNo = "    ";
	m_OFPHeader.ReceiverAdd = "";			// PC端发送时填本地用户名 
	m_OFPHeader.ReceiveFlowType = "  ";
	m_OFPHeader.ReceiveFlowSeqNo = "    ";
	m_OFPHeader.Start = 0x02;				// 信息开始符 
	m_OFPHeader.CommandID = dwCommandID;	// 命令类型，二进制 
	m_OFPHeader.IsFirst = chIsFirst;		// 信息状态 ‘1’第一次发送, 其他 非第一次 
	m_OFPHeader.NotLast = chNotLast;		// 信息行号 ‘0’结束,‘1’有后续行 
	m_OFPHeader.Length = 0;					// 信息正文长度 + 28 
	m_OFPHeader.Command = "";				// 命令字 
	m_OFPHeader.Echo = "";					// 处理状态 
	
	Clear();
}

char *COFPPackage::AddBody(void *pBody, int nBodySize)
{
	char *p = Push(nBodySize);
	if (p != NULL)
	{
		memcpy(p, pBody, nBodySize);
	}
	return p;
}

WORD COFPPackage::GetFlowType()
{
	WORD r;
	memcpy(&r, &m_OFPHeader.SenderFlowType, sizeof(WORD));
	return r;
}

void COFPPackage::SetFlowType(WORD wFlowType)
{
	memcpy(&m_OFPHeader.SenderFlowType, &wFlowType, sizeof(WORD));
	memcpy(&m_OFPHeader.ReceiveFlowType, &wFlowType, sizeof(WORD));
}

int COFPPackage::GetFlowSeqNo()
{
	int r;
	memcpy(&r, &m_OFPHeader.SenderFlowSeqNo, sizeof(int));
	return r;
}

void COFPPackage::SetFlowSeqNo(int nFlowSeqNo)
{
	memcpy(&m_OFPHeader.SenderFlowSeqNo, &nFlowSeqNo, sizeof(int));
	memcpy(&m_OFPHeader.ReceiveFlowSeqNo, &nFlowSeqNo, sizeof(int));
}

void COFPPackage::DebugOutput(CLogger *pLogger)
{
	char temp[20];
	char buffer[OFP_PACKAGE_MAX_SIZE+1];
	sprintf(buffer, "|%s", m_OFPHeader.Command.getValue());
	sprintf(buffer+strlen(buffer), "|%d", m_OFPHeader.Length.getValue());
	sprintf(buffer+strlen(buffer), "|%s", m_OFPHeader.Echo.getValue());
	memcpy(temp, m_OFPHeader.SenderAdd.getValue(), 16);
	temp[16] = 0;
	sprintf(buffer+strlen(buffer), "|%s", temp);
	memcpy(temp, m_OFPHeader.ReceiverAdd.getValue(), 16);
	temp[16] = 0;
	sprintf(buffer+strlen(buffer), "|%s", temp);
	
	WORD wSenderFlowType, wReceiveFlowType;
	memcpy(&wSenderFlowType, m_OFPHeader.SenderFlowType, sizeof(WORD));
	memcpy(&wReceiveFlowType, m_OFPHeader.ReceiveFlowType, sizeof(WORD));

	DWORD dwSenderFlowSeqNo,dwReceiveFlowSeqNo;
	memcpy(&dwSenderFlowSeqNo, m_OFPHeader.SenderFlowSeqNo, sizeof(DWORD));
	memcpy(&dwReceiveFlowSeqNo, m_OFPHeader.ReceiveFlowSeqNo, sizeof(DWORD));

	sprintf(buffer+strlen(buffer), "|%04x|%08x|%04x|%08x", 
		wSenderFlowType, dwSenderFlowSeqNo, wReceiveFlowType, dwReceiveFlowSeqNo);
	sprintf(buffer+strlen(buffer), "|%02x|%04x|%c|%c",
		m_OFPHeader.Start.getValue(), m_OFPHeader.CommandID,
		m_OFPHeader.IsFirst.getValue(), m_OFPHeader.NotLast.getValue());

	pLogger->output(LL_DEBUG, "\tOFP报文头:%s\n", buffer);

	if (m_OFPHeader.CommandID == 0x0701)
	{
		if (Length() < 12)
		{		
			pLogger->output(LL_DEBUG, "\tOFP报文内容：私有流报文内容长度不对\n");
			return;
		}
		memcpy(buffer, Address(), 8);
		buffer[8] = '\0';
		pLogger->output(LL_DEBUG, "\tOFP报文内容：[%s", buffer);
		DWORD x;
		memcpy(&x, Address()+8, 4);
		pLogger->output(LL_DEBUG, ":%04X:", x);
		memcpy(buffer, Address()+12, Length()-12);
		buffer[Length()-12] = '\0';
		pLogger->output(LL_DEBUG, "%s]\n", buffer);
	}
	else
	{
		memcpy(buffer, Address(), Length());
		buffer[Length()] = '\0';
		pLogger->output(LL_DEBUG, "\tOFP报文内容：[%s]\n", buffer);
	}
}

