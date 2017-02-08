#include "public.h"
#include "FileFlow.h"

#define BLOCK_SIZE	100

struct TFlowId
{
	DWORD dwSize;                       //对象长度
	void ChangeEndian()
	{
		CHANGE_ENDIAN(dwSize);
	}
};

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: makeid confilename\n");
		return -1;
	}
	string strConFileName = argv[1];
	strConFileName += ".con";
	string strIdFileName = argv[1];
	strIdFileName += ".id";
	FILE *fpCon = fopen(strConFileName.c_str(), "rb");
	if(fpCon == NULL)
	{
		printf("Can't open con file [%s]\n",  strConFileName.c_str());
		return -2;
	}
	
	FILE *fpId = fopen(strIdFileName.c_str(), "wb");
	if(fpId == NULL)
	{
		fclose(fpCon);
		printf("Can't open id file [%s]\n",  strIdFileName.c_str());
		return -2;
	}
	
	fpos_t posContentSize = 0;
	for(int i=0; ;i++)
	{
		if(i%BLOCK_SIZE ==0)
		{
			if (i == 0)
			{
				WORD wCommPhaseNo = 0;
				if (fwrite(&wCommPhaseNo, sizeof(WORD), 1, fpId)!=1)
					RAISE_RUNTIME_ERROR("Can not write id file for CFlow");
			}
			else
			{
				fpos_t posOffset = posContentSize;
				CHANGE_ENDIAN(posOffset);
				if (fwrite(&posOffset, sizeof(posOffset), 1, fpId)!=1)
					RAISE_RUNTIME_ERROR("Can not write id file for CFlow");
			}
		}
		fsetpos(fpCon, &posContentSize);
		TFlowId flowId;
		if(fread(&flowId,sizeof(flowId),1,fpCon)!=1)
		{
			break;
		}
		flowId.ChangeEndian();
		FPOS_SET(posContentSize, FPOS_GET(posContentSize)+flowId.dwSize+sizeof(flowId));
	}
	fclose(fpId);
	
	fclose(fpCon);
	
	return 0;
}