// FileFlow.cpp: implementation of the CFileFlow class.
//
// 20070828 �Ժ�� �޸��쳣�˳��ķ�ʽ
// 20100423 ����   NT-0100��id�ļ���дʱfpos_t�����޸�ΪQWORD����
// 20100428 ����   NT-0101������������У�鹦��
// 20110624 ����   NT-0139 �ӿ���Ӧʱ�䣺����֪ͨ����
///20120626 ����   NT-0139 �ӿ���Ӧʱ�䣺�����Զ�֪ͨ���ֶ�֪ͨ�Ŀ��ƹ���
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "FileFlow.h"

#define BLOCK_SIZE	100

struct TFlowId
{
	DWORD dwSize;                       //���󳤶�
	void ChangeEndian()
	{
		CHANGE_ENDIAN(dwSize);
	}
};
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CFileFlow::CFileFlow(const char *pszFlowName, const char *pszPath, bool bReuse)
{
	m_nCount= 0;
	FPOS_SET(m_nContentSize,0);
	m_fpIdFile=NULL;
	m_fpContentFile=NULL;
	m_nCommPhaseNo = 0;
	OpenFile(pszFlowName, pszPath, bReuse);
	
	m_nReadId = -1;
	FPOS_SET(m_nReadOffset,0);

	INIT_CRITICAL_VAR(m_criticalVar);

}
CFileFlow::CFileFlow(int nFlowID, const char *pszPath, bool bReuse)
{
	char szFlowName[20];
	sprintf(szFlowName, "%08x", nFlowID);
	new (this) CFileFlow(szFlowName, pszPath, bReuse);
}

CFileFlow::~CFileFlow()
{
	DELETE_CRITICAL_VAR(m_criticalVar);
	CloseFile();
}

int CFileFlow::GetCount(void)
{
	return m_nCount;
}

const int *CFileFlow::GetCountPtr(void)
{
	return &m_nCount;
}

fpos_t CFileFlow::GetContentSize(void)
{
	return m_nContentSize;
}

int CFileFlow::Append(void *pObject, int length)
{
	ENTER_CRITICAL(m_criticalVar);
	fsetpos(m_fpContentFile, &m_nContentSize);
	TFlowId flowId;
	flowId.dwSize=length;
	
	flowId.ChangeEndian();
	if (fwrite(&flowId,sizeof(flowId),1,m_fpContentFile)!=1)
		EMERGENCY_EXIT("Can not write content file for CFlow");

	if (fwrite(pObject,1,length,m_fpContentFile) != (size_t)length)
		EMERGENCY_EXIT("Can not write content file for CFlow");
	fflush(m_fpContentFile);

	FPOS_SET(m_nContentSize,FPOS_GET(m_nContentSize)+length+sizeof(flowId));
	m_nCount++;

	if(m_nCount%BLOCK_SIZE==0){
		m_BlockOffset.push_back(m_nContentSize);
		fseek(m_fpIdFile,0,SEEK_END);
		fpos_t dwOffset = m_nContentSize;
		CHANGE_ENDIAN(dwOffset);
		QWORD offset = FPOS_GET(dwOffset);

		if (fwrite(&offset,sizeof(offset),1,m_fpIdFile)!=1)
			EMERGENCY_EXIT("Can not write id file for CFlow");
		
		fflush(m_fpIdFile);
	}
	LEAVE_CRITICAL(m_criticalVar);

	// �����Զ�֪ͨʱ������
	if (m_bAutoNotify)
	{
		// ֪ͨ
		CFlow::Notify();
	}

	return m_nCount-1;
}

fpos_t CFileFlow::GetOffset(int id)
{
	fpos_t offset;
	FPOS_SET(offset, 0);
	if (m_nReadId+1 == id)
	{
		offset = m_nReadOffset;
	}
	else
	{
		TFlowId flowId;
		int i=id/BLOCK_SIZE;
		offset=m_BlockOffset[i];
		for(i*=BLOCK_SIZE;i<id;i++){
			fsetpos(m_fpContentFile, &offset);
			if(fread(&flowId,sizeof(flowId),1,m_fpContentFile)!=1)
				EMERGENCY_EXIT("Can not read content file for CFlow");
			flowId.ChangeEndian();
			FPOS_SET(offset,FPOS_GET(offset)+flowId.dwSize+sizeof(flowId));
		}
	}
	return offset;
}

int CFileFlow::Get(int id, void *pObject, int length)
{
	ENTER_CRITICAL(m_criticalVar);
	fpos_t offset = GetOffset(id); 
	TFlowId flowId;
	fsetpos(m_fpContentFile, &offset);
	if(fread(&flowId,sizeof(flowId),1,m_fpContentFile)!=1)
		EMERGENCY_EXIT("Can not read content file for CFlow");
	flowId.ChangeEndian();

	if (flowId.dwSize>length)
		EMERGENCY_EXIT("Insufficient buffer length while reading CFlow");

	if (fread(pObject,1,flowId.dwSize,m_fpContentFile)!=(size_t)flowId.dwSize)
		EMERGENCY_EXIT("Can not read content file for CFlow");

	m_nReadId = id;
	FPOS_SET(m_nReadOffset,FPOS_GET(offset) + flowId.dwSize + sizeof(flowId));
	LEAVE_CRITICAL(m_criticalVar);
	
	return flowId.dwSize;
}

void CFileFlow::GetLength(FILE* file, QWORD& length)
{
#ifdef WIN32
	struct _stati64 statbuf;

	if (_fstati64(fileno(file), &statbuf) == 0)
		length = statbuf.st_size;
#else
	struct stat statbuf;
	
	if (fstat(fileno(file), &statbuf) == 0)
		length = statbuf.st_size;
#endif
}

void CFileFlow::SetLength(FILE* file, QWORD length)
{
#ifdef WIN32
	fpos_t pos = length;
	fsetpos(file, &pos);
	HANDLE handle = (HANDLE) _get_osfhandle(fileno(file));
	SetEndOfFile(handle);
#else
	ftruncate(fileno(file), length);
#endif
}

void CFileFlow::Valid(const char * pszIdFileName, const char * pszConFileName)
{
	// ���ļ�
	FILE* idFile = mfopen(pszIdFileName, "r+b");
	FILE* conFile = mfopen(pszConFileName, "r+b");

	if (idFile == NULL || conFile == NULL)
	{
		if (idFile != NULL)
			fclose(idFile);

		if (conFile != NULL)
			fclose(conFile);
		
		return;
	}

	// �õ��ļ�����
	QWORD idFileLength = 0;
	QWORD conFileLength = 0;

	GetLength(idFile, idFileLength);
	GetLength(conFile, conFileLength);

	// id�ļ�Ӧ�ð���ͨѶ�׶α��
	if (idFileLength < sizeof(WORD))
	{
		fclose(idFile);
		fclose(conFile);

		EMERGENCY_EXIT("CFlow id file is not valid");
	}

	// �����ļ�ͷ
	if (fseek(conFile, 0, SEEK_SET) != 0)
		EMERGENCY_EXIT("CFlow con file is not valid");

	// ����id�ļ���con�ļ�Ӧ�ñ������ļ�����
	// ��con�ļ�Ϊ׼
	DWORD flowLen = 0;
	QWORD conPos = 0;
	QWORD idCount = 0;

	while (conFileLength - conPos >= sizeof(DWORD))
	{
		// ��������
		fread(&flowLen, sizeof(flowLen), 1, conFile);
		CHANGE_ENDIAN(flowLen);
		conPos += sizeof(DWORD);

		// �鿴�Ƿ������ݳ���
		if (conFileLength - conPos < flowLen)
		{
			conPos -= sizeof(DWORD);
			
			break;
		}

		// id��������
		idCount ++;

		// �鿴�Ƿ񳬹�id�ļ�����
		if (idFileLength < sizeof(WORD) + (idCount / BLOCK_SIZE) * sizeof(QWORD))
		{
			conPos -= sizeof(DWORD);
			idCount --;

			break;
		}

		// ���������ݳ���
		fseek(conFile, flowLen, SEEK_CUR);
		conPos += flowLen;
	}

	// ���úϷ���id��con�ļ�����
	idFileLength = sizeof(WORD) + (idCount / BLOCK_SIZE) * sizeof(QWORD);
	conFileLength = conPos;

	// ����id�ļ���con�ļ�����
	SetLength(idFile, idFileLength);
	SetLength(conFile, conFileLength);

	// �ر��ļ�
	fclose(idFile);
	fclose(conFile);
}

void CFileFlow::OpenFile(const char *pszFlowName, const char *pszPath, bool bReuse)
{
	ASSERT(pszPath != NULL);
	
	CloseFile();
	
	char szIdFilename[512];
	char szContentFilename[512];
	sprintf(szIdFilename, "%s%s.id",pszPath, pszFlowName);
	sprintf(szContentFilename, "%s%s.con", pszPath, pszFlowName);

	// ��������ʱ�����ļ�
	if (bReuse)
		Valid(szIdFilename, szContentFilename);

	m_nCount=0;
	FPOS_SET(m_nContentSize,0);

	m_BlockOffset.clear();

	fpos_t firstOffset;
	FPOS_SET(firstOffset, 0);
	m_BlockOffset.push_back(firstOffset);

	m_fpIdFile=mfopen(szIdFilename,"a+b");
	m_fpContentFile=mfopen(szContentFilename,"a+b");
	if ((m_fpIdFile==NULL)||(m_fpContentFile==NULL))
	{
		CloseFile();
		EMERGENCY_EXIT("can not open CFlow file");
	}
	
	if (!bReuse)
	{
		if (!InitFile())
		{
			CloseFile();
			EMERGENCY_EXIT("can not init CFlow file");
		}
		return ;
	}

#ifdef WIN32	
	struct _stati64 statbuf;
	int result = _stati64( szContentFilename, &statbuf );
#else
	struct stat statbuf;
	int result = stat( szContentFilename, &statbuf );
#endif
	if( result != 0 )
		EMERGENCY_EXIT( "Problem getting file information" );

	FPOS_SET(m_nContentSize,statbuf.st_size);
		
	fpos_t size;
	FPOS_SET(size,0);
	fseek(m_fpIdFile,0,SEEK_SET);
	if(fread(&m_nCommPhaseNo, sizeof(m_nCommPhaseNo), 1, m_fpIdFile) != 1)
	{
		if (!InitFile())
		{
			CloseFile();
			EMERGENCY_EXIT("can not init CFlow file");
		}
		return ;
	}
	CHANGE_ENDIAN(m_nCommPhaseNo);
	for(;;){
		QWORD offset;

		if (fread(&offset,sizeof(offset),1,m_fpIdFile)!=1)
			break;

		fpos_t dwOffset;
		FPOS_SET(dwOffset, offset);
		CHANGE_ENDIAN(dwOffset);
		m_BlockOffset.push_back(dwOffset);
		size=dwOffset;
		m_nCount+=BLOCK_SIZE;
	}
	TFlowId flowId;
	int i;
	for(i=0;;i++){
		if(fsetpos(m_fpContentFile, &size)!=0)
		{
			EMERGENCY_EXIT("fsetpos failed");
		}
		if(fread(&flowId,sizeof(flowId),1,m_fpContentFile)!=1)
			break;
		flowId.ChangeEndian();
		FPOS_SET(size,FPOS_GET(size)+flowId.dwSize+sizeof(flowId));
	}
	if(FPOS_GET(size)!=FPOS_GET(m_nContentSize) || i>=BLOCK_SIZE )
		EMERGENCY_EXIT("size!=m_nContentSize || i>=BLOCK_SIZE");

	m_nCount+=i;
}

bool CFileFlow::InitFile()
{
	m_nContentSize = GetOffset(m_nCount);
	int nIdCount = m_nCount/BLOCK_SIZE;
	m_BlockOffset.resize(nIdCount+1);

#ifdef WIN32
	if(chsize(fileno(m_fpIdFile), nIdCount) != 0)
	{
		return false;
	}
	if(chsize(fileno(m_fpContentFile), m_nContentSize) != 0)
	{
		return false;
	}
#else
	ftruncate(fileno(m_fpIdFile), nIdCount);
	ftruncate(fileno(m_fpContentFile), FPOS_GET(m_nContentSize));
#endif
	if (fseek(m_fpIdFile, 0, SEEK_SET) != 0)
	{
		return false;
	}
	WORD nCommPhaseNo = m_nCommPhaseNo;
	CHANGE_ENDIAN(nCommPhaseNo);
	if(fwrite(&nCommPhaseNo, sizeof(nCommPhaseNo), 1, m_fpIdFile) != 1)
	{
		return false;
	}
	fflush(m_fpIdFile);
	return true;
}

void CFileFlow::CloseFile()
{
	if(m_fpIdFile != NULL){
		fclose(m_fpIdFile);
		m_fpIdFile = NULL;
	}
	if(m_fpContentFile != NULL){
		fclose(m_fpContentFile);
		m_fpContentFile = NULL;
	}
}

WORD CFileFlow::GetCommPhaseNo()
{
	return m_nCommPhaseNo;
}

void CFileFlow::SetCommPhaseNo(WORD nCommPhaseNo)
{
	if (nCommPhaseNo != m_nCommPhaseNo)
	{
		m_nCommPhaseNo = nCommPhaseNo;
		m_nCount= 0;
		InitFile();
	}
}

bool CFileFlow::Truncate(int nCount)
{
	if (m_nCount <= nCount)
	{
		return true;
	}
	m_nCount= nCount;
	return InitFile();
}
