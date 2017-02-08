# Microsoft Developer Studio Project File - Name="syseventcounter" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=syseventcounter - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "syseventcounter.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "syseventcounter.mak" CFG="syseventcounter - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "syseventcounter - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "syseventcounter - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "syseventcounter - Win32 Release"

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
# ADD BASE CPP                                -nologo -EHsc -MT -O2 -GF -FD   -W3 -DWINDOWS -DMSVC /c
# ADD CPP                                -nologo -EHsc -MT -O2 -GF -FD   -W3 -DWINDOWS -DMSVC   -I..\..\source\platform\. -I..\..\source\base\. -I..\..\source\utility\. -I..\..\source\datastruct\. -I..\..\source\event\. -I..\..\source\network\. -I..\..\source\tcpnetwork\. -I..\..\source\udpnetwork\. -I..\..\source\protocol\. -I..\..\source\channelprotocol\. -I..\..\source\scpprotocol\. -I..\..\source\xmpprotocol\. -I..\..\source\compressprotocol\. -I..\..\source\ftdprotocol\. -I..\..\source\xml\. -I..\..\source\boostregex\. -I..\..\source\probelogger\. -I..\..\source\version\. -I..\..\source\MDB_EVENT\. -I..\..\source\customDataType\. -I..\..\source\ftdfield\. -I..\..\source\refobject\. -I..\..\source\expr\. -I..\..\source\sysutility\. -I..\..\source\syseventcounter\. -I..\..\source\telnet\. -I..\..\source\sshapi\ -I..\..\source\UFCopy\. /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib -lncurses -lcrypto                                /FORCE:MULTIPLE                                /FIXED:NO     /WARN:2



# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib -lncurses -lcrypto                               /nodefaultlib:"libcmt.lib"  /FORCE:MULTIPLE                                /FIXED:NO     /WARN:2

!ELSEIF  "$(CFG)" == "syseventcounter - Win32 Debug"

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
# ADD BASE CPP                                -nologo -EHsc -MTd -Od  -Zi -FD   -W3 -DDEBUG -DDEBUG_LOG -DWINDOWS -DMSVC  /c
# ADD CPP                                -nologo -EHsc -MTd -Od  -Zi -FD   -W3 -DDEBUG -DDEBUG_LOG -DWINDOWS -DMSVC   -I..\..\source\platform\. -I..\..\source\base\. -I..\..\source\utility\. -I..\..\source\datastruct\. -I..\..\source\event\. -I..\..\source\network\. -I..\..\source\tcpnetwork\. -I..\..\source\udpnetwork\. -I..\..\source\protocol\. -I..\..\source\channelprotocol\. -I..\..\source\scpprotocol\. -I..\..\source\xmpprotocol\. -I..\..\source\compressprotocol\. -I..\..\source\ftdprotocol\. -I..\..\source\xml\. -I..\..\source\boostregex\. -I..\..\source\probelogger\. -I..\..\source\version\. -I..\..\source\MDB_EVENT\. -I..\..\source\customDataType\. -I..\..\source\ftdfield\. -I..\..\source\refobject\. -I..\..\source\expr\. -I..\..\source\sysutility\. -I..\..\source\syseventcounter\. -I..\..\source\telnet\. -I..\..\source\sshapi\ -I..\..\source\UFCopy\. /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib -lncurses -lcrypto                                /FORCE:MULTIPLE                                /FIXED:NO     /DEBUG /WARN:2

# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib -lncurses -lcrypto                               msvcrtd.lib  /nodefaultlib:"libcmtd.lib;msvcrt.lib"  /FORCE:MULTIPLE                                /FIXED:NO     /DEBUG /WARN:2

!ENDIF 

# Begin Target

# Name "syseventcounter - Win32 Release"
# Name "syseventcounter - Win32 Debug"

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

# Begin Group "udpnetwork"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\udpnetwork\UdpChannel.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\udpnetwork\UdpClient.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\udpnetwork\UdpServer.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\udpnetwork\UdpNetworkFactory.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\udpnetwork\UdpChannel.h
# End Source File

# Begin Source File
SOURCE=..\..\source\udpnetwork\UdpClient.h
# End Source File

# Begin Source File
SOURCE=..\..\source\udpnetwork\UdpServer.h
# End Source File

# Begin Source File
SOURCE=..\..\source\udpnetwork\UdpNetworkFactory.h
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

# Begin Group "scpprotocol"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\scpprotocol\SCPPackage.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\scpprotocol\SCPPackageDesc.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\scpprotocol\SCPProtocol.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\scpprotocol\SCPPackage.h
# End Source File

# Begin Source File
SOURCE=..\..\source\scpprotocol\SCPPackageDesc.h
# End Source File

# Begin Source File
SOURCE=..\..\source\scpprotocol\SCPProtocol.h
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

# Begin Group "xml"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\xml\CXML.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\xml\XMLAction.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\xml\CXML.h
# End Source File

# Begin Source File
SOURCE=..\..\source\xml\XMLAction.h
# End Source File

# End Group

# Begin Group "boostregex"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\boostregex\libboost_regex.lib
# End Source File

# Begin Source File
SOURCE=..\..\source\boostregex\libboost_regex-vc100-mt-gd-1_53.lib
# End Source File

# Begin Source File
SOURCE=..\..\source\boostregex\libboost_regex-vc100-mt-sgd-1_53.lib
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

# Begin Group "version"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\version\version.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\version\version.h
# End Source File

# Begin Source File
SOURCE=..\..\source\version\versionValue.h
# End Source File

# End Group

# Begin Group "MDB_EVENT"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\MDB_EVENT\CDatabaseDataFactory.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\CDatabaseResource.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\BaseDataStruct.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\databaseResources.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\databaseFactories.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\databaseFactorySearchs.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\databaseIterators.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\CMemoryDB.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\CDumpLog.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\databaseGroupActions.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\databaseIteratorRepository.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\CDatabaseDataFactory.h
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\CDatabaseResource.h
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\BaseDataStruct.h
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\databaseResources.h
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\databaseFactories.h
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\databaseIterators.h
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\CMemoryDB.h
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\CDumpLog.h
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\databaseGroupActions.h
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\databaseIteratorRepository.h
# End Source File

# Begin Source File
SOURCE=..\..\source\MDB_EVENT\databaseData.h
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

# Begin Group "refobject"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\refobject\RefString.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\refobject\RefObject.h
# End Source File

# Begin Source File
SOURCE=..\..\source\refobject\RefString.h
# End Source File

# End Group

# Begin Group "expr"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\expr\inputStream.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\expr\inputToken.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\expr\CExprException.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\expr\charSet.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\expr\inputStream.h
# End Source File

# Begin Source File
SOURCE=..\..\source\expr\inputToken.h
# End Source File

# Begin Source File
SOURCE=..\..\source\expr\CExprException.h
# End Source File

# Begin Source File
SOURCE=..\..\source\expr\charSet.h
# End Source File

# Begin Source File
SOURCE=..\..\source\expr\CBaseValue.h
# End Source File

# Begin Source File
SOURCE=..\..\source\expr\CBaseContext.h
# End Source File

# Begin Source File
SOURCE=..\..\source\expr\CExprNode.h
# End Source File

# Begin Source File
SOURCE=..\..\source\expr\CExprParser.h
# End Source File

# End Group

# Begin Group "sysutility"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\sysutility\systools.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\xmlcfg.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\FileRecordFinder.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\md5Handler.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\CTimePolicy.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\ThreadPool.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\StringUtil.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\CDeployConfig.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\PrjCommon.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\CCalendar.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\CSysInternalTopology.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\systools.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\xmlcfg.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\FileRecordFinder.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\md5Handler.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\CTimePolicy.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\FTDDataHelper.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\ThreadPool.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\SyncEvent.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\SyncEvent_Platform.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\ScopedLock.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\PrjCommon.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\StringUtil.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\CDeployConfig.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\CCalendar.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sysutility\CSysInternalTopology.h
# End Source File

# End Group

# Begin Group "syseventcounter"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\syseventcounter\CExprAnalysis.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\syseventcounter.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\SnmpSubcriber.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\EventCounterServer.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\EventFrontServer.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\CStatusAnalysis.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\CSavePosThread.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\CMdbThread.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\ProbeServer.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\EventConfigConnector.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\CRegexConfig.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\CMsgGenerator.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\test_event.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\CExprAnalysis.h
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\SnmpSubcriber.h
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\EventCounterServer.h
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\EventFrontServer.h
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\CStatusAnalysis.h
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\CSavePosThread.h
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\CMdbThread.h
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\ProbeServer.h
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\EventConfigConnector.h
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\CRegexConfig.h
# End Source File

# Begin Source File
SOURCE=..\..\source\syseventcounter\CMsgGenerator.h
# End Source File

# End Group

# Begin Group "telnet"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\telnet\CTelnet.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\telnet\CTelnetClient.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\telnet\CTelnetConnThread.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\telnet\CFileDiff.cpp
# End Source File

# Begin Source File
SOURCE=..\..\source\telnet\CTelnet.h
# End Source File

# Begin Source File
SOURCE=..\..\source\telnet\CTelnetClient.h
# End Source File

# Begin Source File
SOURCE=..\..\source\telnet\CTelnetConnThread.h
# End Source File

# Begin Source File
SOURCE=..\..\source\telnet\CFileDiff.h
# End Source File

# End Group

# Begin Group "sshapi"

# PROP Default_Filter ""
# Begin Source File
SOURCE=..\..\source\sshapi\libssh.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sshapi\ssh_threads.h
# End Source File

# Begin Source File
SOURCE=..\..\source\sshapi\libssh.lib
# End Source File

# Begin Source File
SOURCE=..\..\source\sshapi\libssl.lib
# End Source File

# Begin Source File
SOURCE=..\..\source\sshapi\libz.lib
# End Source File

# Begin Source File
SOURCE=..\..\source\sshapi\libssh_threads.lib
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

# End Target
# End Project

