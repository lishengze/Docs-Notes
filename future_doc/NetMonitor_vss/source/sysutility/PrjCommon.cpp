

#include "PrjCommon.h"
#include <FtdPackageDesc.h>
#include "ScopedLock.h"
#include <Mutex.h>

void LogPkg
	(CFTDCPackage * pkg, CBufferLogger * bufLogger, CFileLogger * fileLogger)
{
#ifdef PACKAGE_OUTPUT
	assert(pkg && bufLogger && fileLogger);
	static CMutex mutex;
	ScopeLock<CMutex> lock(mutex);

	// 在linux上会core dump，原因待查
	//bufLogger->reset();
	//pkg->OutputHeader((CLogger*)bufLogger);
	//FTDC_DEBUG_BODY(pkg->GetTID(), pkg, (CLogger*)bufLogger);
	//int n;
	//fileLogger->output(LL_DEBUG, "%s", bufLogger->getValue(n));
	pkg->OutputHeader((CLogger *)fileLogger);
	FTDC_DEBUG_BODY(pkg->GetTID(), pkg, (CLogger *)fileLogger);
#endif
}
