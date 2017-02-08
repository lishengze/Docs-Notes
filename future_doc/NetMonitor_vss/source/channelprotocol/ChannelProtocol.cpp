// ChannelProtocol.cpp: implementation of the CChannelProtocol class.
//
// 20080620 �Ժ�� ���Ӽ���Ƿ�д��æ�Ľӿ�IsWriteBusy
///20120409 ����   NT-0139 �ӿ���Ӧʱ�䣺�����˳��Զ�ȡ��д��Ĵ���
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "ChannelProtocol.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChannelProtocol::CChannelProtocol(CReactor *pReactor,CChannel *pChannel,int nPackageMaxSize)
:CProtocol(pReactor, 0, NULL, NULL),
m_ChannelPackage(nPackageMaxSize),
m_CacheList(20000)
{
	m_pChannel=pChannel;
	if (pChannel->GetType() == CT_STREAM)
	{
		SetTimer(1, 1000);			//�򿪶�ʱǿ��ˢ�¶�ʱ��
	}
}

CChannelProtocol::~CChannelProtocol()
{

}

int CChannelProtocol::Push(CPackage *pPackage, CProtocol *pUpper)
{
//	TRACE2("CChannelProtocol::Push [%p][%d]\n",pPackage->Address(),pPackage->Length());
	if (m_pChannel->GetType() == CT_STREAM)
	{
		m_CacheList.PushBack(pPackage->Address(),pPackage->Length());
		return 0;
	}
	else
	{
		int len=m_pChannel->Write(pPackage->Length(),pPackage->Address());
		if (len != pPackage->Length())
		{
			return -1;
		}
	}
	return 0;
}

void CChannelProtocol::GetIds(int *pReadId, int *pWriteId)
{
	if (!m_pChannel->Available())
	{
		*pReadId = 0;
		*pWriteId = 0;
		return;
	}
	if(m_pChannel!=NULL){
		*pReadId=m_pChannel->GetId();
	}
	else{
		*pReadId=0;
	}

	////////////////////////////
//	*pWriteId = m_pChannel->GetId();
	if(!m_CacheList.IsEmpty()){
		*pWriteId=m_pChannel->GetId();
	}
	else{
		*pWriteId=0;
	}

}

int CChannelProtocol::HandleInput()
{
	int ret = 0;
	for (int i=0; i<80; i++)
	{
		int nReadLen=m_ChannelPackage.ReadFromChannel(m_pChannel);
		if(nReadLen<0){
			//����
			NotifyError(MSG_CHNLERR_READ, 0, this);
			return -1;
		}
		if (nReadLen == 0)
		{
			break;
		}
		ret = Pop(&m_ChannelPackage);
		if (ret != 0)
		{
			return ret;
		} 
	}
	return ret;
}

int CChannelProtocol::HandleOutput()
{
 	return Flush();
}

void CChannelProtocol::OnTimer(int nIDEvent)
{
	//��ֹselect��write�ļ��ʧЧ
	Flush();
}

int CChannelProtocol::Flush()
{
	if (!m_pChannel->CheckConnection())
	{
		return 0;
	}

	for(int i=0; i<80; i++)
	{
		int nDataLen = 8192;		//--������Ҫ����
		
		char *pData=(char *)m_CacheList.GetData(nDataLen);		
		if(pData==NULL)
		{
			break;
		}
//		TRACE1("GetData [%d]\n", DataLen);
		int len = m_pChannel->Write(nDataLen, pData);
		if(len < 0){
			NotifyError(MSG_CHNLERR_WRITE, 0, this);
			return len;
		}

/*
		for(int i=0; i<len; i++){
			printf("%02x  ", pData[i]&0xFF);
		}
		printf("\n");
*/
		m_CacheList.PopFront(len);
				
		if(len != nDataLen)
		{
			break;
		}
	}
	return 0;
}

bool CChannelProtocol::IsWriteBusy()
{
	return !m_CacheList.IsEmpty();
}
