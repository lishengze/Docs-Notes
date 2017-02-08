// 20120130 ����		NT-0165 slogparser��flowviewer�������ӿ��ٶ�ȡ���N���Ĺ���
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

	// ���������
	int nLastLineNumber = 0;
	int nCompSeqNo = 0;
	int nFlowID = -1;
	int c = 0;	
		
	while ((c = getopt(argc - 1, argv + 1, "l:c:i:")) != EOF)
	{
		switch (c)
		{				
			case ('l'):
				// �������
				nLastLineNumber = atoi(optarg);

				break;

			case ('c'):
				// ָ���Ŷ����
				nCompSeqNo = atoi(optarg);

				break;

			case ('i'):
				// ָ����id��
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

	// ����ͨѶ�׶α��
	WORD commPhaseNo = 0;

	// ���µ�ͨѶ�׶α��
	if (fread(&commPhaseNo, sizeof(commPhaseNo), 1, fp) != 1)
	{			
		printf("can't read CommPhaseNo\n");
		return -3;
	}

	CHANGE_ENDIAN(commPhaseNo);

	printf("CommPhaseNo=[%d]\n", commPhaseNo);

	CXTPPackage xtpPackage;
	xtpPackage.ConstructAllocate(10000, XTPHLEN);

	// �����Ӧ������������
	int nSkipLineNumber = 0;

	if (nLastLineNumber != 0)
	{
		// �ܵ�����
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

		// ����������ܳ���������
		if (nLastLineNumber > nTotalLineNumber)
			nLastLineNumber = nTotalLineNumber;

		// �������������
		nSkipLineNumber = nTotalLineNumber - nLastLineNumber;

		// �����ļ�ͷ
		fseek(fp, 0, SEEK_SET);
	}

	// �Ƿ���ʾ
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
				// ָ�����Ŷ�id
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
				// ָ������id
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
				// ʲô��û��ָ��
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
