# Microsoft Developer Studio Project File - Name="userapi" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=userapi - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "userapi.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "userapi.mak" CFG="userapi - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "userapi - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "userapi - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "userapi - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP -DUSERAPI_IS_LIB -DLIB_USER_API_EXPORT -DDEBUG_NOT_LOG                       -nologo -EHsc -MT -O2 -GF -FD   -W3 -DWINDOWS -DMSVC -DISLIB /c
# ADD CPP -DUSERAPI_IS_LIB -DLIB_USER_API_EXPORT -DDEBUG_NOT_LOG                       -nologo -EHsc -MT -O2 -GF -FD   -W3 -DWINDOWS -DMSVC -DISLIB   -I..\..\source\platform\. -I..\..\source\base\. -I..\..\source\utility\. -I..\..\source\datastruct\. -I..\..\source\event\. -I..\..\source\network\. -I..\..\source\tcpnetwork\. -I..\..\source\openssl\. -I..\..\source\sslnetwork\. -I..\..\source\protocol\. -I..\..\source\channelprotocol\. -I..\..\source\xmpprotocol\. -I..\..\source\ftdprotocol\. -I..\..\source\nsprotocol\. -I..\..\source\compressprotocol\. -I..\..\source\customDataType\. -I..\..\source\ftdfield\. -I..\..\source\UFCopy\. -I..\..\source\userapi\. -I..\..\source\probelogger\. /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib                                               /FIXED:NO     /WARN:2



# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib                                               /FIXED:NO     /WARN:2

!ELSEIF  "$(CFG)" == "userapi - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP -DUSERAPI_IS_LIB -DLIB_USER_API_EXPORT -DDEBUG_NOT_LOG                       -nologo -EHsc -MTd -Od  -Zi -FD   -W3 -DDEBUG -DDEBUG_LOG -DWINDOWS -DMSVC -DISLIB  /c
# ADD CPP -DUSERAPI_IS_LIB -DLIB_USER_API_EXPORT -DDEBUG_NOT_LOG                       -nologo -EHsc -MTd -Od  -Zi -FD   -W3 -DDEBUG -DDEBUG_LOG -DWINDOWS -DMSVC -DISLIB   -I..\..\source\platform\. -I..\..\source\base\. -I..\..\source\utility\. -I..\..\source\datastruct\. -I..\..\source\event\. -I..\..\source\network\. -I..\..\source\tcpnetwork\. -I..\..\source\openssl\. -I..\..\source\sslnetwork\. -I..\..\source\protocol\. -I..\..\source\channelprotocol\. -I..\..\source\xmpprotocol\. -I..\..\source\ftdprotocol\. -I..\..\source\nsprotocol\. -I..\..\source\compressprotocol\. -I..\..\source\customDataType\. -I..\..\source\ftdfield\. -I..\..\source\UFCopy\. -I..\..\source\userapi\. -I..\..\source\probelogger\. /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib                                               /FIXED:NO     /DEBUG /WARN:2

# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib                                               /FIXED:NO     /DEBUG /WARN:2

!ENDIF 

# Begin Target

# Name "userapi - Win32 Release"
# Name "userapi - Win32 Debug"

# Begin Group "platform"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\platform\system.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\platform\platform.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\platform\mpath.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\platform\system.h
# End Source File

# Begin Source File
SOURCE=..\..\source\platform\platform.h
# End Source File

# Begin Source File
SOURCE=..\..\source\platform\mpath.h
# End Source File

# End Group

# Begin Group "base"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\base\CBaseObject.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\base\DesignError.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\base\RuntimeError.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\base\CLogger.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\base\CProbeLogger.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\base\monitorIndex.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\base\CBaseObject.h
# End Source File

# Begin Source File
SOURCE=..\..\source\base\DesignError.h
# End Source File

# Begin Source File
SOURCE=..\..\source\base\RuntimeError.h
# End Source File

# Begin Source File
SOURCE=..\..\source\base\CLogger.h
# End Source File

# Begin Source File
SOURCE=..\..\source\base\CProbeLogger.h
# End Source File

# Begin Source File
SOURCE=..\..\source\base\monitorIndex.h
# End Source File

# Begin Source File
SOURCE=..\..\source\base\public.h
# End Source File

# End Group

# Begin Group "utility"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\utility\CTimeMeter.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\utility\utility.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\utility\Config.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\utility\CTimeMeter.h
# End Source File

# Begin Source File
SOURCE=..\..\source\utility\utility.h
# End Source File

# Begin Source File
SOURCE=..\..\source\utility\Config.h
# End Source File

# End Group

# Begin Group "datastruct"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\datastruct\CConfig.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CFixMem.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CAVLTree.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CTransaction.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CMemory.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CFiniteState.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CacheList.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\FieldDescribe.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\FieldSet.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\Index.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\Package.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\Flow.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\ReadOnlyFlow.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\FlowReader.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\OrderingQ.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CachedFileFlow.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CachedFlow.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\FileFlow.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\IndexPackageFlow.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CSVParser.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CSequenceInterface.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CMemorySequence.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CErrorEngine.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CDate.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\Allocator.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CHashIndex.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\PtrList.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\ObjAllocator.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CachedFileFlow.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CachedFlow.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\IndexPackageFlow.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\FileFlow.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CConfig.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CFixMem.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CAVLTree.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CResource.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CTransaction.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CMemory.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CFiniteState.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CacheList.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\FieldDescribe.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\FieldSet.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\Index.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\Package.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\HashMap.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\Flow.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\ReadOnlyFlow.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\FlowReader.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\PersistentState.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\OrderingQ.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\UFDataType.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CSVParser.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CSequenceInterface.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CMemorySequence.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CErrorEngine.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CDate.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\Allocator.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\MemoryStack.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\ThreadSafeFlow.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\CHashIndex.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\PtrList.h
# End Source File

# Begin Source File
SOURCE=..\..\source\datastruct\ObjAllocator.h
# End Source File

# End Group

# Begin Group "event"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\event\EventHandler.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\event\EventQueue.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\event\EventDispatcher.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\event\Reactor.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\event\Semaphore.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\event\Thread.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\event\SelectReactor.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\event\TimerHeap.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\event\EpollReactor.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\event\EventHandler.h
# End Source File

# Begin Source File
SOURCE=..\..\source\event\EventQueue.h
# End Source File

# Begin Source File
SOURCE=..\..\source\event\Reactor.h
# End Source File

# Begin Source File
SOURCE=..\..\source\event\Semaphore.h
# End Source File

# Begin Source File
SOURCE=..\..\source\event\Thread.h
# End Source File

# Begin Source File
SOURCE=..\..\source\event\Mutex.h
# End Source File

# Begin Source File
SOURCE=..\..\source\event\SelectReactor.h
# End Source File

# Begin Source File
SOURCE=..\..\source\event\TimerHeap.h
# End Source File

# Begin Source File
SOURCE=..\..\source\event\TimerQueue.h
# End Source File

# Begin Source File
SOURCE=..\..\source\event\EventDispatcher.h
# End Source File

# Begin Source File
SOURCE=..\..\source\event\EpollReactor.h
# End Source File

# End Group

# Begin Group "network"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\network\Channel.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\network\Client.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\network\ListenCtrl.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\network\NetworkFactory.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\network\Server.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\network\ServiceName.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\network\SocketInit.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\network\Channel.h
# End Source File

# Begin Source File
SOURCE=..\..\source\network\Client.h
# End Source File

# Begin Source File
SOURCE=..\..\source\network\ListenCtrl.h
# End Source File

# Begin Source File
SOURCE=..\..\source\network\NetworkFactory.h
# End Source File

# Begin Source File
SOURCE=..\..\source\network\Server.h
# End Source File

# Begin Source File
SOURCE=..\..\source\network\ServiceName.h
# End Source File

# Begin Source File
SOURCE=..\..\source\network\SocketInit.h
# End Source File

# End Group

# Begin Group "tcpnetwork"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\tcpnetwork\TcpChannel.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\tcpnetwork\TcpClient.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\tcpnetwork\TcpServer.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\tcpnetwork\TcpNetworkFactory.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\tcpnetwork\TcpChannel.h
# End Source File

# Begin Source File
SOURCE=..\..\source\tcpnetwork\TcpClient.h
# End Source File

# Begin Source File
SOURCE=..\..\source\tcpnetwork\TcpServer.h
# End Source File

# Begin Source File
SOURCE=..\..\source\tcpnetwork\TcpNetworkFactory.h
# End Source File

# End Group

# Begin Group "openssl"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\openssl\ssleay32.lib
# End Source File

# Begin Source File
SOURCE=..\..\source\openssl\libeay32.lib
# End Source File

# End Group

# Begin Group "sslnetwork"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\sslnetwork\SslChannel.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\sslnetwork\SslClient.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\sslnetwork\SslServer.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\sslnetwork\SslNetworkFactory.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\sslnetwork\SslChannel.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sslnetwork\SslClient.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sslnetwork\SslServer.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sslnetwork\SslNetworkFactory.h
# End Source File

# End Group

# Begin Group "protocol"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\protocol\Protocol.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\protocol\Protocol.h
# End Source File

# End Group

# Begin Group "channelprotocol"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\channelprotocol\ChannelProtocol.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\channelprotocol\ChannelPackage.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\channelprotocol\Session.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\channelprotocol\SessionFactory.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\channelprotocol\ChannelProtocol.h
# End Source File

# Begin Source File
SOURCE=..\..\source\channelprotocol\ChannelPackage.h
# End Source File

# Begin Source File
SOURCE=..\..\source\channelprotocol\Session.h
# End Source File

# Begin Source File
SOURCE=..\..\source\channelprotocol\SessionFactory.h
# End Source File

# End Group

# Begin Group "xmpprotocol"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\xmpprotocol\XMPPackage.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\xmpprotocol\XMPSession.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\xmpprotocol\XMPProtocol.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\xmpprotocol\XMPPackage.h
# End Source File

# Begin Source File
SOURCE=..\..\source\xmpprotocol\XMPSession.h
# End Source File

# Begin Source File
SOURCE=..\..\source\xmpprotocol\XMPProtocol.h
# End Source File

# End Group

# Begin Group "ftdprotocol"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\ftdprotocol\FTDCPackage.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\ftdprotocol\FTDCProtocol.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\ftdprotocol\FTDCSession.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\ftdprotocol\FTDCPubEndPoint.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\ftdprotocol\FTDCSubEndPoint.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\ftdprotocol\FTDCPackage.h
# End Source File

# Begin Source File
SOURCE=..\..\source\ftdprotocol\FTDCProtocol.h
# End Source File

# Begin Source File
SOURCE=..\..\source\ftdprotocol\FTDCSession.h
# End Source File

# Begin Source File
SOURCE=..\..\source\ftdprotocol\FTDCPubEndPoint.h
# End Source File

# Begin Source File
SOURCE=..\..\source\ftdprotocol\FTDCSubEndPoint.h
# End Source File

# Begin Source File
SOURCE=..\..\source\ftdprotocol\FTDCSubscriber.h
# End Source File

# End Group

# Begin Group "nsprotocol"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\nsprotocol\NsPackage.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\nsprotocol\NsSession.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\nsprotocol\NsProtocol.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\nsprotocol\NsSessionFactory.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\nsprotocol\NsPackage.h
# End Source File

# Begin Source File
SOURCE=..\..\source\nsprotocol\NsSession.h
# End Source File

# Begin Source File
SOURCE=..\..\source\nsprotocol\NsProtocol.h
# End Source File

# Begin Source File
SOURCE=..\..\source\nsprotocol\NsSessionFactory.h
# End Source File

# End Group

# Begin Group "compressprotocol"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\compressprotocol\CompressPackage.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\compressprotocol\CompressProtocol.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\compressprotocol\CompressUtil.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\compressprotocol\CompressPackage.h
# End Source File

# Begin Source File
SOURCE=..\..\source\compressprotocol\CompressProtocol.h
# End Source File

# Begin Source File
SOURCE=..\..\source\compressprotocol\CompressUtil.h
# End Source File

# End Group

# Begin Group "customDataType"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\customDataType\customDataType.h
# End Source File

# End Group

# Begin Group "ftdfield"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\ftdfield\FtdData.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\ftdfield\FtdPackageDesc.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\ftdfield\FtdData.h
# End Source File

# Begin Source File
SOURCE=..\..\source\ftdfield\FtdPackageDesc.h
# End Source File

# End Group

# Begin Group "UFCopy"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\UFCopy\UFCopy.h
# End Source File

# Begin Source File
SOURCE=..\..\source\UFCopy\UFEntityCopy.h
# End Source File

# Begin Source File
SOURCE=..\..\source\UFCopy\MDBCopy.h
# End Source File

# Begin Source File
SOURCE=..\..\source\UFCopy\XTPCopy.h
# End Source File

# Begin Source File
SOURCE=..\..\source\UFCopy\FTDCopy.h
# End Source File

# End Group

# Begin Group "userapi"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\userapi\FtdcUserApiImpl.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\userapi\FtdcUserApiImplBase.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\userapi\FtdcUserApiDataType.h
# End Source File

# Begin Source File
SOURCE=..\..\source\userapi\FtdcUserApiStruct.h
# End Source File

# Begin Source File
SOURCE=..\..\source\userapi\FtdcUserApi.h
# End Source File

# Begin Source File
SOURCE=..\..\source\userapi\FtdcUserApiImpl.h
# End Source File

# Begin Source File
SOURCE=..\..\source\userapi\FtdcUserApiImplBase.h
# End Source File

# Begin Source File
SOURCE=..\..\source\userapi\FtdcUserApiMacro.h
# End Source File

# End Group

# Begin Group "probelogger"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\probelogger\CSyslogService.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\probelogger\CFilelogService.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\probelogger\CSyslogService.h
# End Source File

# Begin Source File
SOURCE=..\..\source\probelogger\CFilelogService.h
# End Source File

# End Group

# End Target
# End Project

