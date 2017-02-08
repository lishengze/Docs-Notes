#include "public.h"
#include "FtdPackageDesc.h"
#include "FTDCPackage.h"


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: ftdflowviewer ftdflowfilename\n");
		return -1;
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

	CFTDCPackage ftdPackage;
	ftdPackage.ConstructAllocate(10000, FTDCHLEN);
	for (int i=0;;i++)
	{
		ftdPackage.AllocateMax();
		DWORD size = 0;
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
		printf("FLOW ID=[%d], SIZE=[%d]\n", i, size);
		if (fread(ftdPackage.Address(), 1, size, fp) != size)
		{
			printf("read package content error\n");
			break;
		}
		ftdPackage.Truncate(size);
		if (!ftdPackage.ValidPackage())
		{
			printf("invalid package\n");
			break;
		}
		FTDC_PACKAGE_DEBUG((&ftdPackage));

//		if (xtpPackage.GetXTPHeader()->Tid == TID_InitCurrPartPosiLimitDetail)
//		{
//			printf("---------------------------\n");
//			char buf[10000];
//			CNamedFieldIterator itor = xtpPackage.GetNamedFieldIterator(&CCurrPartPosiLimitDetailField::m_Describe);
//			while (!itor.IsEnd())
//			{
//				itor.Retrieve(buf);
//				XTP_FIELD_DEBUG(stdout, buf, &CCurrPartPosiLimitDetailField::m_Describe);
//				itor.Next();
//			}
//			printf("---------------------------\n");
//		}
	}

	fclose(fp);
	return 0;
}
