.SUFFIXES:  .c .cpp .o .obj .a .lib

CPP=cl -nologo 
LINK=link -nologo
PREP=cl -nologo -EP
LUA=lua
PUMP=pump
COPY=copy /y
DEL=del
MAKE=nmake
ECHO=echo

.cpp.obj:
	$(CPP) $(CPPFLAGS) $(INCLUDEDIR) -c $< >> output
	move $(@F) $(@D)



ISLIB=Y
DEFINES=-DWINDOWS -DMSVC -DISLIB
target=userapi.dll

DEBUG_DEFINE=

APPEND_CPPFLAGS=-nologo -EHsc -MT -O2 -GF -FD

PROFILE_CPPFLAGS=

WARNING_CPPFLAGS=-W3

CPPFLAGS= -DUSERAPI_IS_LIB -DLIB_USER_API_EXPORT -DDEBUG_NOT_LOG                       $(APPEND_CPPFLAGS) $(PROFILE_CPPFLAGS) $(WARNING_CPPFLAGS) $(DEBUG_DEFINE) $(DEFINES)

LIBS= kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib                       

DEBUG_LDFLAGS=

MAP_LDFLAGS=

PROFILE_LDFLAGS=

WARNING_LDFLAGS=/WARN:2

LDFLAGS=                       /FIXED:NO $(MAP_LDFLAGS) $(DEBUG_LDFLAGS) $(PROFILE_LDFLAGS) $(WARNING_LDFLAGS)

LIBARFLAGS=                         $(MAP_LDFLAGS) $(DEBUG_LDFLAGS) $(PROFILE_LDFLAGS)

DLLARFLAGS=                       /dll $(MAP_LDFLAGS) $(DEBUG_LDFLAGS) $(PROFILE_LDFLAGS)


all: makefile code

code: clearoutput $(target)

makefile: ..\..\source\platform\package.des ..\..\source\base\package.des ..\..\source\utility\package.des ..\..\source\datastruct\package.des ..\..\source\event\package.des ..\..\source\network\package.des ..\..\source\tcpnetwork\package.des ..\..\source\openssl\package.des ..\..\source\sslnetwork\package.des ..\..\source\protocol\package.des ..\..\source\channelprotocol\package.des ..\..\source\xmpprotocol\package.des ..\..\source\ftdprotocol\package.des ..\..\source\nsprotocol\package.des ..\..\source\compressprotocol\package.des ..\..\source\customDataType\package.des ..\..\source\ftdfield\package.des ..\..\source\UFCopy\package.des ..\..\source\userapi\package.des ..\..\source\probelogger\package.des  userapidll.prj
	amake userapidll.prj
	@$(ECHO) rerun nmake
	@exit /b 1

clearoutput:
	@$(ECHO) Compiling... > output

platform_obj= ..\..\source\platform\system.obj  ..\..\source\platform\platform.obj  ..\..\source\platform\mpath.obj 
platform_include= ..\..\source\platform\system.h  ..\..\source\platform\platform.h  ..\..\source\platform\mpath.h 
platform_includedir=-I..\..\source\platform\.
base_obj= ..\..\source\base\CBaseObject.obj  ..\..\source\base\DesignError.obj  ..\..\source\base\RuntimeError.obj  ..\..\source\base\CLogger.obj  ..\..\source\base\CProbeLogger.obj  ..\..\source\base\monitorIndex.obj 
base_include= ..\..\source\base\CBaseObject.h  ..\..\source\base\DesignError.h  ..\..\source\base\RuntimeError.h  ..\..\source\base\CLogger.h  ..\..\source\base\CProbeLogger.h  ..\..\source\base\monitorIndex.h  ..\..\source\base\public.h 
base_includedir=-I..\..\source\base\.
utility_obj= ..\..\source\utility\CTimeMeter.obj  ..\..\source\utility\utility.obj  ..\..\source\utility\Config.obj 
utility_include= ..\..\source\utility\CTimeMeter.h  ..\..\source\utility\utility.h  ..\..\source\utility\Config.h 
utility_includedir=-I..\..\source\utility\.
datastruct_obj= ..\..\source\datastruct\CConfig.obj  ..\..\source\datastruct\CFixMem.obj  ..\..\source\datastruct\CAVLTree.obj  ..\..\source\datastruct\CTransaction.obj  ..\..\source\datastruct\CMemory.obj  ..\..\source\datastruct\CFiniteState.obj  ..\..\source\datastruct\CacheList.obj  ..\..\source\datastruct\FieldDescribe.obj  ..\..\source\datastruct\FieldSet.obj  ..\..\source\datastruct\Index.obj  ..\..\source\datastruct\Package.obj  ..\..\source\datastruct\Flow.obj  ..\..\source\datastruct\ReadOnlyFlow.obj  ..\..\source\datastruct\FlowReader.obj  ..\..\source\datastruct\OrderingQ.obj  ..\..\source\datastruct\CachedFileFlow.obj  ..\..\source\datastruct\CachedFlow.obj  ..\..\source\datastruct\FileFlow.obj  ..\..\source\datastruct\IndexPackageFlow.obj  ..\..\source\datastruct\CSVParser.obj  ..\..\source\datastruct\CSequenceInterface.obj  ..\..\source\datastruct\CMemorySequence.obj  ..\..\source\datastruct\CErrorEngine.obj  ..\..\source\datastruct\CDate.obj  ..\..\source\datastruct\Allocator.obj  ..\..\source\datastruct\CHashIndex.obj  ..\..\source\datastruct\PtrList.obj  ..\..\source\datastruct\ObjAllocator.obj 
datastruct_include= ..\..\source\datastruct\CachedFileFlow.h  ..\..\source\datastruct\CachedFlow.h  ..\..\source\datastruct\IndexPackageFlow.h  ..\..\source\datastruct\FileFlow.h  ..\..\source\datastruct\CConfig.h  ..\..\source\datastruct\CFixMem.h  ..\..\source\datastruct\CAVLTree.h  ..\..\source\datastruct\CResource.h  ..\..\source\datastruct\CTransaction.h  ..\..\source\datastruct\CMemory.h  ..\..\source\datastruct\CFiniteState.h  ..\..\source\datastruct\CacheList.h  ..\..\source\datastruct\FieldDescribe.h  ..\..\source\datastruct\FieldSet.h  ..\..\source\datastruct\Index.h  ..\..\source\datastruct\Package.h  ..\..\source\datastruct\HashMap.h  ..\..\source\datastruct\Flow.h  ..\..\source\datastruct\ReadOnlyFlow.h  ..\..\source\datastruct\FlowReader.h  ..\..\source\datastruct\PersistentState.h  ..\..\source\datastruct\OrderingQ.h  ..\..\source\datastruct\UFDataType.h  ..\..\source\datastruct\CSVParser.h  ..\..\source\datastruct\CSequenceInterface.h  ..\..\source\datastruct\CMemorySequence.h  ..\..\source\datastruct\CErrorEngine.h  ..\..\source\datastruct\CDate.h  ..\..\source\datastruct\Allocator.h  ..\..\source\datastruct\MemoryStack.h  ..\..\source\datastruct\ThreadSafeFlow.h  ..\..\source\datastruct\CHashIndex.h  ..\..\source\datastruct\PtrList.h  ..\..\source\datastruct\ObjAllocator.h 
datastruct_includedir=-I..\..\source\datastruct\.
event_obj= ..\..\source\event\EventHandler.obj  ..\..\source\event\EventQueue.obj  ..\..\source\event\EventDispatcher.obj  ..\..\source\event\Reactor.obj  ..\..\source\event\Semaphore.obj  ..\..\source\event\Thread.obj  ..\..\source\event\SelectReactor.obj  ..\..\source\event\TimerHeap.obj  ..\..\source\event\EpollReactor.obj 
event_include= ..\..\source\event\EventHandler.h  ..\..\source\event\EventQueue.h  ..\..\source\event\Reactor.h  ..\..\source\event\Semaphore.h  ..\..\source\event\Thread.h  ..\..\source\event\Mutex.h  ..\..\source\event\SelectReactor.h  ..\..\source\event\TimerHeap.h  ..\..\source\event\TimerQueue.h  ..\..\source\event\EventDispatcher.h  ..\..\source\event\EpollReactor.h 
event_includedir=-I..\..\source\event\.
network_obj= ..\..\source\network\Channel.obj  ..\..\source\network\Client.obj  ..\..\source\network\ListenCtrl.obj  ..\..\source\network\NetworkFactory.obj  ..\..\source\network\Server.obj  ..\..\source\network\ServiceName.obj  ..\..\source\network\SocketInit.obj 
network_include= ..\..\source\network\Channel.h  ..\..\source\network\Client.h  ..\..\source\network\ListenCtrl.h  ..\..\source\network\NetworkFactory.h  ..\..\source\network\Server.h  ..\..\source\network\ServiceName.h  ..\..\source\network\SocketInit.h 
network_includedir=-I..\..\source\network\.
tcpnetwork_obj= ..\..\source\tcpnetwork\TcpChannel.obj  ..\..\source\tcpnetwork\TcpClient.obj  ..\..\source\tcpnetwork\TcpServer.obj  ..\..\source\tcpnetwork\TcpNetworkFactory.obj 
tcpnetwork_include= ..\..\source\tcpnetwork\TcpChannel.h  ..\..\source\tcpnetwork\TcpClient.h  ..\..\source\tcpnetwork\TcpServer.h  ..\..\source\tcpnetwork\TcpNetworkFactory.h 
tcpnetwork_includedir=-I..\..\source\tcpnetwork\.
openssl_obj=
openssl_lib= ..\..\source\openssl\ssleay32.lib  ..\..\source\openssl\libeay32.lib 
openssl_include=
openssl_includedir=-I..\..\source\openssl\.
sslnetwork_obj= ..\..\source\sslnetwork\SslChannel.obj  ..\..\source\sslnetwork\SslClient.obj  ..\..\source\sslnetwork\SslServer.obj  ..\..\source\sslnetwork\SslNetworkFactory.obj 
sslnetwork_include= ..\..\source\sslnetwork\SslChannel.h  ..\..\source\sslnetwork\SslClient.h  ..\..\source\sslnetwork\SslServer.h  ..\..\source\sslnetwork\SslNetworkFactory.h 
sslnetwork_includedir=-I..\..\source\sslnetwork\.
protocol_obj= ..\..\source\protocol\Protocol.obj 
protocol_include= ..\..\source\protocol\Protocol.h 
protocol_includedir=-I..\..\source\protocol\.
channelprotocol_obj= ..\..\source\channelprotocol\ChannelProtocol.obj  ..\..\source\channelprotocol\ChannelPackage.obj  ..\..\source\channelprotocol\Session.obj  ..\..\source\channelprotocol\SessionFactory.obj 
channelprotocol_include= ..\..\source\channelprotocol\ChannelProtocol.h  ..\..\source\channelprotocol\ChannelPackage.h  ..\..\source\channelprotocol\Session.h  ..\..\source\channelprotocol\SessionFactory.h 
channelprotocol_includedir=-I..\..\source\channelprotocol\.
xmpprotocol_obj= ..\..\source\xmpprotocol\XMPPackage.obj  ..\..\source\xmpprotocol\XMPSession.obj  ..\..\source\xmpprotocol\XMPProtocol.obj 
xmpprotocol_include= ..\..\source\xmpprotocol\XMPPackage.h  ..\..\source\xmpprotocol\XMPSession.h  ..\..\source\xmpprotocol\XMPProtocol.h 
xmpprotocol_includedir=-I..\..\source\xmpprotocol\.
ftdprotocol_obj= ..\..\source\ftdprotocol\FTDCPackage.obj  ..\..\source\ftdprotocol\FTDCProtocol.obj  ..\..\source\ftdprotocol\FTDCSession.obj  ..\..\source\ftdprotocol\FTDCPubEndPoint.obj  ..\..\source\ftdprotocol\FTDCSubEndPoint.obj 
ftdprotocol_include= ..\..\source\ftdprotocol\FTDCPackage.h  ..\..\source\ftdprotocol\FTDCProtocol.h  ..\..\source\ftdprotocol\FTDCSession.h  ..\..\source\ftdprotocol\FTDCPubEndPoint.h  ..\..\source\ftdprotocol\FTDCSubEndPoint.h  ..\..\source\ftdprotocol\FTDCSubscriber.h 
ftdprotocol_includedir=-I..\..\source\ftdprotocol\.
nsprotocol_obj= ..\..\source\nsprotocol\NsPackage.obj  ..\..\source\nsprotocol\NsSession.obj  ..\..\source\nsprotocol\NsProtocol.obj  ..\..\source\nsprotocol\NsSessionFactory.obj 
nsprotocol_include= ..\..\source\nsprotocol\NsPackage.h  ..\..\source\nsprotocol\NsSession.h  ..\..\source\nsprotocol\NsProtocol.h  ..\..\source\nsprotocol\NsSessionFactory.h 
nsprotocol_includedir=-I..\..\source\nsprotocol\.
compressprotocol_obj= ..\..\source\compressprotocol\CompressPackage.obj  ..\..\source\compressprotocol\CompressProtocol.obj  ..\..\source\compressprotocol\CompressUtil.obj 
compressprotocol_include= ..\..\source\compressprotocol\CompressPackage.h  ..\..\source\compressprotocol\CompressProtocol.h  ..\..\source\compressprotocol\CompressUtil.h 
compressprotocol_includedir=-I..\..\source\compressprotocol\.
customDataType_obj=
customDataType_include= ..\..\source\customDataType\customDataType.h 
customDataType_includedir=-I..\..\source\customDataType\.
ftdfield_obj= ..\..\source\ftdfield\FtdData.obj  ..\..\source\ftdfield\FtdPackageDesc.obj 
ftdfield_include= ..\..\source\ftdfield\FtdData.h  ..\..\source\ftdfield\FtdPackageDesc.h 
ftdfield_includedir=-I..\..\source\ftdfield\.
UFCopy_obj=
UFCopy_include= ..\..\source\UFCopy\UFCopy.h  ..\..\source\UFCopy\UFEntityCopy.h  ..\..\source\UFCopy\MDBCopy.h  ..\..\source\UFCopy\XTPCopy.h  ..\..\source\UFCopy\FTDCopy.h 
UFCopy_includedir=-I..\..\source\UFCopy\.
userapi_obj= ..\..\source\userapi\FtdcUserApiImpl.obj  ..\..\source\userapi\FtdcUserApiImplBase.obj 
userapi_include= ..\..\source\userapi\FtdcUserApiDataType.h  ..\..\source\userapi\FtdcUserApiStruct.h  ..\..\source\userapi\FtdcUserApi.h  ..\..\source\userapi\FtdcUserApiImpl.h  ..\..\source\userapi\FtdcUserApiImplBase.h  ..\..\source\userapi\FtdcUserApiMacro.h 
userapi_includedir=-I..\..\source\userapi\.
probelogger_obj= ..\..\source\probelogger\CSyslogService.obj  ..\..\source\probelogger\CFilelogService.obj 
probelogger_include= ..\..\source\probelogger\CSyslogService.h  ..\..\source\probelogger\CFilelogService.h 
probelogger_includedir=-I..\..\source\probelogger\.

all_objs= $(platform_obj)  $(base_obj)  $(utility_obj)  $(datastruct_obj)  $(event_obj)  $(network_obj)  $(tcpnetwork_obj)  $(openssl_obj)  $(sslnetwork_obj)  $(protocol_obj)  $(channelprotocol_obj)  $(xmpprotocol_obj)  $(ftdprotocol_obj)  $(nsprotocol_obj)  $(compressprotocol_obj)  $(customDataType_obj)  $(ftdfield_obj)  $(UFCopy_obj)  $(userapi_obj)  $(probelogger_obj) 
all_libs= $(platform_lib)  $(base_lib)  $(utility_lib)  $(datastruct_lib)  $(event_lib)  $(network_lib)  $(tcpnetwork_lib)  $(openssl_lib)  $(sslnetwork_lib)  $(protocol_lib)  $(channelprotocol_lib)  $(xmpprotocol_lib)  $(ftdprotocol_lib)  $(nsprotocol_lib)  $(compressprotocol_lib)  $(customDataType_lib)  $(ftdfield_lib)  $(UFCopy_lib)  $(userapi_lib)  $(probelogger_lib) 
INCLUDEDIR= $(platform_includedir)  $(base_includedir)  $(utility_includedir)  $(datastruct_includedir)  $(event_includedir)  $(network_includedir)  $(tcpnetwork_includedir)  $(openssl_includedir)  $(sslnetwork_includedir)  $(protocol_includedir)  $(channelprotocol_includedir)  $(xmpprotocol_includedir)  $(ftdprotocol_includedir)  $(nsprotocol_includedir)  $(compressprotocol_includedir)  $(customDataType_includedir)  $(ftdfield_includedir)  $(UFCopy_includedir)  $(userapi_includedir)  $(probelogger_includedir) 

..\..\source\platform\system.obj: ..\..\source\platform\system.cpp $(platform_include)  

..\..\source\platform\platform.obj: ..\..\source\platform\platform.cpp $(platform_include)  

..\..\source\platform\mpath.obj: ..\..\source\platform\mpath.cpp $(platform_include)  

..\..\source\base\CBaseObject.obj: ..\..\source\base\CBaseObject.cpp $(base_include)   $(platform_include)

..\..\source\base\DesignError.obj: ..\..\source\base\DesignError.cpp $(base_include)   $(platform_include)

..\..\source\base\RuntimeError.obj: ..\..\source\base\RuntimeError.cpp $(base_include)   $(platform_include)

..\..\source\base\CLogger.obj: ..\..\source\base\CLogger.cpp $(base_include)   $(platform_include)

..\..\source\base\CProbeLogger.obj: ..\..\source\base\CProbeLogger.cpp $(base_include)   $(platform_include)

..\..\source\base\monitorIndex.obj: ..\..\source\base\monitorIndex.cpp $(base_include)   $(platform_include)

..\..\source\utility\CTimeMeter.obj: ..\..\source\utility\CTimeMeter.cpp $(utility_include)   $(platform_include) $(base_include)

..\..\source\utility\utility.obj: ..\..\source\utility\utility.cpp $(utility_include)   $(platform_include) $(base_include)

..\..\source\utility\Config.obj: ..\..\source\utility\Config.cpp $(utility_include)   $(platform_include) $(base_include)

..\..\source\datastruct\CConfig.obj: ..\..\source\datastruct\CConfig.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\CFixMem.obj: ..\..\source\datastruct\CFixMem.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\CAVLTree.obj: ..\..\source\datastruct\CAVLTree.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\CTransaction.obj: ..\..\source\datastruct\CTransaction.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\CMemory.obj: ..\..\source\datastruct\CMemory.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\CFiniteState.obj: ..\..\source\datastruct\CFiniteState.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\CacheList.obj: ..\..\source\datastruct\CacheList.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\FieldDescribe.obj: ..\..\source\datastruct\FieldDescribe.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\FieldSet.obj: ..\..\source\datastruct\FieldSet.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\Index.obj: ..\..\source\datastruct\Index.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\Package.obj: ..\..\source\datastruct\Package.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\Flow.obj: ..\..\source\datastruct\Flow.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\ReadOnlyFlow.obj: ..\..\source\datastruct\ReadOnlyFlow.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\FlowReader.obj: ..\..\source\datastruct\FlowReader.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\OrderingQ.obj: ..\..\source\datastruct\OrderingQ.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\CachedFileFlow.obj: ..\..\source\datastruct\CachedFileFlow.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\CachedFlow.obj: ..\..\source\datastruct\CachedFlow.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\FileFlow.obj: ..\..\source\datastruct\FileFlow.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\IndexPackageFlow.obj: ..\..\source\datastruct\IndexPackageFlow.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\CSVParser.obj: ..\..\source\datastruct\CSVParser.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\CSequenceInterface.obj: ..\..\source\datastruct\CSequenceInterface.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\CMemorySequence.obj: ..\..\source\datastruct\CMemorySequence.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\CErrorEngine.obj: ..\..\source\datastruct\CErrorEngine.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\CDate.obj: ..\..\source\datastruct\CDate.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\Allocator.obj: ..\..\source\datastruct\Allocator.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\CHashIndex.obj: ..\..\source\datastruct\CHashIndex.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\PtrList.obj: ..\..\source\datastruct\PtrList.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\datastruct\ObjAllocator.obj: ..\..\source\datastruct\ObjAllocator.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

..\..\source\event\EventHandler.obj: ..\..\source\event\EventHandler.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

..\..\source\event\EventQueue.obj: ..\..\source\event\EventQueue.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

..\..\source\event\EventDispatcher.obj: ..\..\source\event\EventDispatcher.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

..\..\source\event\Reactor.obj: ..\..\source\event\Reactor.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

..\..\source\event\Semaphore.obj: ..\..\source\event\Semaphore.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

..\..\source\event\Thread.obj: ..\..\source\event\Thread.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

..\..\source\event\SelectReactor.obj: ..\..\source\event\SelectReactor.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

..\..\source\event\TimerHeap.obj: ..\..\source\event\TimerHeap.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

..\..\source\event\EpollReactor.obj: ..\..\source\event\EpollReactor.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

..\..\source\network\Channel.obj: ..\..\source\network\Channel.cpp $(network_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include)

..\..\source\network\Client.obj: ..\..\source\network\Client.cpp $(network_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include)

..\..\source\network\ListenCtrl.obj: ..\..\source\network\ListenCtrl.cpp $(network_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include)

..\..\source\network\NetworkFactory.obj: ..\..\source\network\NetworkFactory.cpp $(network_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include)

..\..\source\network\Server.obj: ..\..\source\network\Server.cpp $(network_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include)

..\..\source\network\ServiceName.obj: ..\..\source\network\ServiceName.cpp $(network_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include)

..\..\source\network\SocketInit.obj: ..\..\source\network\SocketInit.cpp $(network_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include)

..\..\source\tcpnetwork\TcpChannel.obj: ..\..\source\tcpnetwork\TcpChannel.cpp $(tcpnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(event_include)

..\..\source\tcpnetwork\TcpClient.obj: ..\..\source\tcpnetwork\TcpClient.cpp $(tcpnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(event_include)

..\..\source\tcpnetwork\TcpServer.obj: ..\..\source\tcpnetwork\TcpServer.cpp $(tcpnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(event_include)

..\..\source\tcpnetwork\TcpNetworkFactory.obj: ..\..\source\tcpnetwork\TcpNetworkFactory.cpp $(tcpnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(event_include)

..\..\source\sslnetwork\SslChannel.obj: ..\..\source\sslnetwork\SslChannel.cpp $(sslnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(tcpnetwork_include) $(event_include) $(openssl_include)

..\..\source\sslnetwork\SslClient.obj: ..\..\source\sslnetwork\SslClient.cpp $(sslnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(tcpnetwork_include) $(event_include) $(openssl_include)

..\..\source\sslnetwork\SslServer.obj: ..\..\source\sslnetwork\SslServer.cpp $(sslnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(tcpnetwork_include) $(event_include) $(openssl_include)

..\..\source\sslnetwork\SslNetworkFactory.obj: ..\..\source\sslnetwork\SslNetworkFactory.cpp $(sslnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(tcpnetwork_include) $(event_include) $(openssl_include)

..\..\source\protocol\Protocol.obj: ..\..\source\protocol\Protocol.cpp $(protocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include)

..\..\source\channelprotocol\ChannelProtocol.obj: ..\..\source\channelprotocol\ChannelProtocol.cpp $(channelprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(event_include)

..\..\source\channelprotocol\ChannelPackage.obj: ..\..\source\channelprotocol\ChannelPackage.cpp $(channelprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(event_include)

..\..\source\channelprotocol\Session.obj: ..\..\source\channelprotocol\Session.cpp $(channelprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(event_include)

..\..\source\channelprotocol\SessionFactory.obj: ..\..\source\channelprotocol\SessionFactory.cpp $(channelprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(event_include)

..\..\source\xmpprotocol\XMPPackage.obj: ..\..\source\xmpprotocol\XMPPackage.cpp $(xmpprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

..\..\source\xmpprotocol\XMPSession.obj: ..\..\source\xmpprotocol\XMPSession.cpp $(xmpprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

..\..\source\xmpprotocol\XMPProtocol.obj: ..\..\source\xmpprotocol\XMPProtocol.cpp $(xmpprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

..\..\source\ftdprotocol\FTDCPackage.obj: ..\..\source\ftdprotocol\FTDCPackage.cpp $(ftdprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(compressprotocol_include)

..\..\source\ftdprotocol\FTDCProtocol.obj: ..\..\source\ftdprotocol\FTDCProtocol.cpp $(ftdprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(compressprotocol_include)

..\..\source\ftdprotocol\FTDCSession.obj: ..\..\source\ftdprotocol\FTDCSession.cpp $(ftdprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(compressprotocol_include)

..\..\source\ftdprotocol\FTDCPubEndPoint.obj: ..\..\source\ftdprotocol\FTDCPubEndPoint.cpp $(ftdprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(compressprotocol_include)

..\..\source\ftdprotocol\FTDCSubEndPoint.obj: ..\..\source\ftdprotocol\FTDCSubEndPoint.cpp $(ftdprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(compressprotocol_include)

..\..\source\nsprotocol\NsPackage.obj: ..\..\source\nsprotocol\NsPackage.cpp $(nsprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

..\..\source\nsprotocol\NsSession.obj: ..\..\source\nsprotocol\NsSession.cpp $(nsprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

..\..\source\nsprotocol\NsProtocol.obj: ..\..\source\nsprotocol\NsProtocol.cpp $(nsprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

..\..\source\nsprotocol\NsSessionFactory.obj: ..\..\source\nsprotocol\NsSessionFactory.cpp $(nsprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

..\..\source\compressprotocol\CompressPackage.obj: ..\..\source\compressprotocol\CompressPackage.cpp $(compressprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

..\..\source\compressprotocol\CompressProtocol.obj: ..\..\source\compressprotocol\CompressProtocol.cpp $(compressprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

..\..\source\compressprotocol\CompressUtil.obj: ..\..\source\compressprotocol\CompressUtil.cpp $(compressprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

..\..\source\ftdfield\FtdData.obj: ..\..\source\ftdfield\FtdData.cpp $(ftdfield_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(customDataType_include)

..\..\source\ftdfield\FtdPackageDesc.obj: ..\..\source\ftdfield\FtdPackageDesc.cpp $(ftdfield_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(customDataType_include)

..\..\source\userapi\FtdcUserApiImpl.obj: ..\..\source\userapi\FtdcUserApiImpl.cpp $(userapi_include)   $(ftdprotocol_include) $(sslnetwork_include) $(UFCopy_include)

..\..\source\userapi\FtdcUserApiImplBase.obj: ..\..\source\userapi\FtdcUserApiImplBase.cpp $(userapi_include)   $(ftdprotocol_include) $(sslnetwork_include) $(UFCopy_include)

..\..\source\probelogger\CSyslogService.obj: ..\..\source\probelogger\CSyslogService.cpp $(probelogger_include)   $(platform_include) $(base_include) $(datastruct_include)

..\..\source\probelogger\CFilelogService.obj: ..\..\source\probelogger\CFilelogService.cpp $(probelogger_include)   $(platform_include) $(base_include) $(datastruct_include)


..\..\source\customDataType\customDataType.h:..\..\source\customDataType\customDataType.h.tpl ..\..\datamodel\commonEnv\UFDataType.xml
	$(PUMP) ..\..\source\customDataType\customDataType.h ..\..\source\customDataType\customDataType.h.tpl ..\..\datamodel\commonEnv\UFDataType.xml >> output

..\..\source\ftdfield\FtdPackageDesc.h:..\..\source\ftdfield\FtdPackageDesc.h.tpl ..\..\datamodel\envGenerated\FTD.xml
	$(PUMP) ..\..\source\ftdfield\FtdPackageDesc.h ..\..\source\ftdfield\FtdPackageDesc.h.tpl ..\..\datamodel\envGenerated\FTD.xml >> output

..\..\source\ftdfield\FtdPackageDesc.cpp:..\..\source\ftdfield\FtdPackageDesc.cpp.tpl ..\..\datamodel\envGenerated\FTD.xml
	$(PUMP) ..\..\source\ftdfield\FtdPackageDesc.cpp ..\..\source\ftdfield\FtdPackageDesc.cpp.tpl ..\..\datamodel\envGenerated\FTD.xml >> output

..\..\source\ftdfield\FtdData.h:..\..\source\ftdfield\FtdData.h.tpl ..\..\datamodel\envGenerated\FTD.xml
	$(PUMP) ..\..\source\ftdfield\FtdData.h ..\..\source\ftdfield\FtdData.h.tpl ..\..\datamodel\envGenerated\FTD.xml >> output

..\..\source\ftdfield\FtdData.cpp:..\..\source\ftdfield\FtdData.cpp.tpl ..\..\datamodel\envGenerated\FTD.xml
	$(PUMP) ..\..\source\ftdfield\FtdData.cpp ..\..\source\ftdfield\FtdData.cpp.tpl ..\..\datamodel\envGenerated\FTD.xml >> output

..\..\source\UFCopy\UFEntityCopy.h:..\..\source\UFCopy\UFEntityCopy.h.tpl ..\..\datamodel\commonEnv\UFEntity.xml
	$(PUMP) ..\..\source\UFCopy\UFEntityCopy.h ..\..\source\UFCopy\UFEntityCopy.h.tpl ..\..\datamodel\commonEnv\UFEntity.xml >> output

..\..\source\UFCopy\MDBCopy.h:..\..\source\UFCopy\MDBCopy.h.tpl ..\..\datamodel\envGenerated\MDB.xml
	$(PUMP) ..\..\source\UFCopy\MDBCopy.h ..\..\source\UFCopy\MDBCopy.h.tpl ..\..\datamodel\envGenerated\MDB.xml >> output

..\..\source\UFCopy\XTPCopy.h:..\..\source\UFCopy\XTPCopy.h.tpl ..\..\datamodel\envGenerated\XTP.xml
	$(PUMP) ..\..\source\UFCopy\XTPCopy.h ..\..\source\UFCopy\XTPCopy.h.tpl ..\..\datamodel\envGenerated\XTP.xml >> output

..\..\source\UFCopy\FTDCopy.h:..\..\source\UFCopy\FTDCopy.h.tpl ..\..\datamodel\envGenerated\FTD.xml
	$(PUMP) ..\..\source\UFCopy\FTDCopy.h ..\..\source\UFCopy\FTDCopy.h.tpl ..\..\datamodel\envGenerated\FTD.xml >> output

..\..\source\userapi\FtdcUserApiDataType.h:..\..\source\userapi\FtdcUserApiDataType.h.tpl ..\..\datamodel\envGenerated\FTD.xml ..\..\datamodel\commonEnv\shfeexchangeinfo.xml
	$(PUMP) ..\..\source\userapi\FtdcUserApiDataType.h ..\..\source\userapi\FtdcUserApiDataType.h.tpl ..\..\datamodel\envGenerated\FTD.xml ..\..\datamodel\commonEnv\shfeexchangeinfo.xml >> output

..\..\source\userapi\FtdcUserApiStruct.h:..\..\source\userapi\FtdcUserApiStruct.h.tpl ..\..\datamodel\envGenerated\FTD.xml ..\..\datamodel\commonEnv\shfeexchangeinfo.xml
	$(PUMP) ..\..\source\userapi\FtdcUserApiStruct.h ..\..\source\userapi\FtdcUserApiStruct.h.tpl ..\..\datamodel\envGenerated\FTD.xml ..\..\datamodel\commonEnv\shfeexchangeinfo.xml >> output

..\..\source\userapi\FtdcUserApi.h:..\..\source\userapi\FtdcUserApi.h.tpl ..\..\datamodel\envGenerated\FTD.xml ..\..\datamodel\commonEnv\shfeexchangeinfo.xml
	$(PUMP) ..\..\source\userapi\FtdcUserApi.h ..\..\source\userapi\FtdcUserApi.h.tpl ..\..\datamodel\envGenerated\FTD.xml ..\..\datamodel\commonEnv\shfeexchangeinfo.xml >> output

..\..\source\userapi\FtdcUserApiImpl.h:..\..\source\userapi\FtdcUserApiImpl.h.tpl ..\..\datamodel\envGenerated\FTD.xml ..\..\datamodel\commonEnv\shfeexchangeinfo.xml
	$(PUMP) ..\..\source\userapi\FtdcUserApiImpl.h ..\..\source\userapi\FtdcUserApiImpl.h.tpl ..\..\datamodel\envGenerated\FTD.xml ..\..\datamodel\commonEnv\shfeexchangeinfo.xml >> output

..\..\source\userapi\FtdcUserApiImpl.cpp:..\..\source\userapi\FtdcUserApiImpl.cpp.tpl ..\..\datamodel\envGenerated\FTD.xml ..\..\datamodel\commonEnv\shfeexchangeinfo.xml
	$(PUMP) ..\..\source\userapi\FtdcUserApiImpl.cpp ..\..\source\userapi\FtdcUserApiImpl.cpp.tpl ..\..\datamodel\envGenerated\FTD.xml ..\..\datamodel\commonEnv\shfeexchangeinfo.xml >> output

..\..\source\userapi\FtdcUserApiMacro.h:..\..\source\userapi\FtdcUserApiMacro.h.tpl ..\..\datamodel\envGenerated\FTD.xml ..\..\datamodel\commonEnv\shfeexchangeinfo.xml
	$(PUMP) ..\..\source\userapi\FtdcUserApiMacro.h ..\..\source\userapi\FtdcUserApiMacro.h.tpl ..\..\datamodel\envGenerated\FTD.xml ..\..\datamodel\commonEnv\shfeexchangeinfo.xml >> output


$(target): $(all_objs)
	$(LINK) $(DLLARFLAGS) -out:$@ -implib:userapi.lib $(all_objs) $(all_libs) $(LIBS) >> output


clean:
	-$(DEL) $(platform_obj)
	-$(DEL) $(base_obj)
	-$(DEL) $(utility_obj)
	-$(DEL) $(datastruct_obj)
	-$(DEL) $(event_obj)
	-$(DEL) $(network_obj)
	-$(DEL) $(tcpnetwork_obj)
	-$(DEL) $(openssl_obj)
	-$(DEL) $(sslnetwork_obj)
	-$(DEL) $(protocol_obj)
	-$(DEL) $(channelprotocol_obj)
	-$(DEL) $(xmpprotocol_obj)
	-$(DEL) $(ftdprotocol_obj)
	-$(DEL) $(nsprotocol_obj)
	-$(DEL) $(compressprotocol_obj)
	-$(DEL) $(customDataType_obj)
	-$(DEL) $(ftdfield_obj)
	-$(DEL) $(UFCopy_obj)
	-$(DEL) $(userapi_obj)
	-$(DEL) $(probelogger_obj)
	-$(DEL)   ..\..\source\customDataType\customDataType.h ..\..\source\ftdfield\FtdPackageDesc.h ..\..\source\ftdfield\FtdPackageDesc.cpp ..\..\source\ftdfield\FtdData.h ..\..\source\ftdfield\FtdData.cpp ..\..\source\UFCopy\UFEntityCopy.h ..\..\source\UFCopy\MDBCopy.h ..\..\source\UFCopy\XTPCopy.h ..\..\source\UFCopy\FTDCopy.h ..\..\source\userapi\FtdcUserApiDataType.h ..\..\source\userapi\FtdcUserApiStruct.h ..\..\source\userapi\FtdcUserApi.h ..\..\source\userapi\FtdcUserApiImpl.h ..\..\source\userapi\FtdcUserApiImpl.cpp ..\..\source\userapi\FtdcUserApiMacro.h
	-$(DEL) $(target)
	-$(DEL) userapi.lib

pump:   ..\..\source\customDataType\customDataType.h ..\..\source\ftdfield\FtdPackageDesc.h ..\..\source\ftdfield\FtdPackageDesc.cpp ..\..\source\ftdfield\FtdData.h ..\..\source\ftdfield\FtdData.cpp ..\..\source\UFCopy\UFEntityCopy.h ..\..\source\UFCopy\MDBCopy.h ..\..\source\UFCopy\XTPCopy.h ..\..\source\UFCopy\FTDCopy.h ..\..\source\userapi\FtdcUserApiDataType.h ..\..\source\userapi\FtdcUserApiStruct.h ..\..\source\userapi\FtdcUserApi.h ..\..\source\userapi\FtdcUserApiImpl.h ..\..\source\userapi\FtdcUserApiImpl.cpp ..\..\source\userapi\FtdcUserApiMacro.h

lua:  

