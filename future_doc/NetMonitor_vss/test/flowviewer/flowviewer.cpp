#include "public.h"
#include "XtpPackageDesc.h"
#include "XTPPackage.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: flowviewer flowfilename\n");
		return -1;
	}

	FILE *fp = fopen(argv[1], "rb");
	if (fp == NULL)
	{
		printf("can't open flow file [%s]\n", argv[1]);
		return -2;
	}

	CXTPPackage xtpPackage;
	xtpPackage.ConstructAllocate(10000, XTPHLEN);
	for (int i=0;;i++)
	{
		xtpPackage.AllocateMax();
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
		XTP_PACKAGE_DEBUG(&xtpPackage);

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
