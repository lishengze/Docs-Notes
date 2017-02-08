// 20120130 江鹏		NT-0165 slogparser和flowviewer工具增加快速读取最后N条的功能
#include "public.h"
#include "XtpPackageDesc.h"
#include "XTPPackage.h"

void Usage()
{
	printf("Usage: flowviewer flowfilename [-l line] [-c CompSeqNo] [-i FlowID]\n");
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		Usage();
		return -1;
	}

	CLogger* logger = CLogger::GetInstance();

	// 读最后行数
	int nLastLineNumber = 0;
	int nCompSeqNo = 0;
	int nFlowID = -1;
	int c = 0;	
		
	while ((c = getopt(argc - 1, argv + 1, "l:c:i:")) != EOF)
	{
		switch (c)
		{				
			case ('l'):
				// 最后行数
				nLastLineNumber = atoi(optarg);

				break;

			case ('c'):
				// 指定排队序号
				nCompSeqNo = atoi(optarg);

				break;

			case ('i'):
				// 指定流id号
				nFlowID = atoi(optarg);

				break;

			default:
				Usage();
				return -1;
		}
	}		

	FILE *fp = fopen(argv[1], "rb");

	if (fp == NULL)
	{
		printf("can't open flow file [%s]\n", argv[1]);
		return -2;	
	}

	// 读入通讯阶段编号
	WORD commPhaseNo = 0;

	// 读新的通讯阶段编号
	if (fread(&commPhaseNo, sizeof(commPhaseNo), 1, fp) != 1)
	{			
		printf("can't read CommPhaseNo\n");
		return -3;
	}

	CHANGE_ENDIAN(commPhaseNo);

	printf("CommPhaseNo=[%d]\n", commPhaseNo);

	CXTPPackage xtpPackage;
	xtpPackage.ConstructAllocate(10000, XTPHLEN);

	// 计算出应该跳过的条数
	int nSkipLineNumber = 0;

	if (nLastLineNumber != 0)
	{
		// 总的行数
		int nTotalLineNumber = 0;

		for (int i = 0; ;i ++)
		{
			xtpPackage.AllocateMax();
			DWORD size = 0;

			if (fread(&size, sizeof(DWORD), 1, fp) != 1)
			{
				break;
			}

			CHANGE_ENDIAN(size);

			if (size > 10000)
			{
				break;
			}
			
			if (fread(xtpPackage.Address(), 1, size, fp) != size)
			{
				break;
			}

			xtpPackage.Truncate(size);
			
			if (!xtpPackage.ValidPackage())
			{
				break;
			}

			nTotalLineNumber ++;
		}

		// 最后行数不能超过总行数
		if (nLastLineNumber > nTotalLineNumber)
			nLastLineNumber = nTotalLineNumber;

		// 计算出跳过行数
		nSkipLineNumber = nTotalLineNumber - nLastLineNumber;

		// 跳回文件头
		fseek(fp, 0, SEEK_SET);
	}

	// 是否显示
	bool bIsShow = true;
	DWORD size = 0;

	for (int i=0;;i++)
	{
		xtpPackage.AllocateMax();
		
		if (fread(&size, sizeof(DWORD), 1, fp) != 1)
		{
			printf("read package size error\n");
			break;
		}

		CHANGE_ENDIAN(size);
		
		if (size > 10000)
		{
			printf("too large package\n");
			break;
		}

		if (i >= nSkipLineNumber)
		{
			if (fread(xtpPackage.Address(), 1, size, fp) != size)
			{
				printf("read package content error\n");
				break;
			}

			xtpPackage.Truncate(size);

			if (!xtpPackage.ValidPackage())
			{
				printf("invalid package\n");
				break;
			}

			if (nCompSeqNo != 0)
			{
				// 指定了排队id
				if (xtpPackage.GetXTPHeader()->CompSeqNo < nCompSeqNo)
				{
					bIsShow = false;
				}
				else if (xtpPackage.GetXTPHeader()->CompSeqNo > nCompSeqNo)
				{
					break;
				}
				else
				{
					bIsShow = true;
				}
			}
			else if (nFlowID != -1)
			{
				// 指定了流id
				if (i < nFlowID)
				{
					bIsShow = false;
				}
				else if (i > nFlowID)
				{
					break;
				}
				else
				{
					bIsShow = true;
				}
			}
			else
			{
				// 什么都没有指定
				bIsShow = true;
			}

			if (bIsShow)
			{
				printf("FLOW ID=[%d], SIZE=[%d]\n", i, size);
				xtpPackage.OutputHeader(logger);                         
				XTP_DEBUG_BODY(xtpPackage.GetTid(), &xtpPackage, logger);
			}
		}
		else
		{
			fseek(fp, size, SEEK_CUR);
		}
	}

	fclose(fp);
	return 0;
}
