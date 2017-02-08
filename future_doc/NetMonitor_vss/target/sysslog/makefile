.SUFFIXES:  .c .cpp .o .obj .a .lib

CPP=g++ -fpic -fpermissive
LINK=g++
PREP=g++ -E -P
PUMP=pump
LUA=lua
COPY=cp
DEL=rm -f
MAKE=make
ECHO=echo
AR=ar

.cpp.o:
	$(CPP) $(CPPFLAGS) $(INCLUDEDIR) -c $< -o $@ 2>> output



ISLIB=N
DEFINES=-DLINUX -DGCC
target=sysslog

DEBUG_DEFINE=-DDEBUG -DDEBUG_LOG

APPEND_CPPFLAGS=-g -O0

PROFILE_CPPFLAGS=

WARNING_CPPFLAGS=-Wall -Wno-sign-compare

CPPFLAGS=                               $(APPEND_CPPFLAGS) $(PROFILE_CPPFLAGS) $(WARNING_CPPFLAGS) $(DEBUG_DEFINE) $(DEFINES)

LIBS= -lpthread -lrt -ldl                              

DEBUG_LDFLAGS=-g

MAP_LDFLAGS=

PROFILE_LDFLAGS=

WARNING_LDFLAGS=-Wall -Wno-sign-compare

LDFLAGS=                               $(MAP_LDFLAGS) $(DEBUG_LDFLAGS) $(PROFILE_LDFLAGS) $(WARNING_LDFLAGS)

LIBARFLAGS=                              -static $(MAP_LDFLAGS) $(DEBUG_LDFLAGS) $(PROFILE_LDFLAGS)

DLLARFLAGS=                              -shared $(MAP_LDFLAGS) $(DEBUG_LDFLAGS) $(PROFILE_LDFLAGS)


all: makefile code

code: clearoutput $(target)

makefile: ../../source/platform/package.des ../../source/base/package.des ../../source/utility/package.des ../../source/datastruct/package.des ../../source/event/package.des ../../source/network/package.des ../../source/tcpnetwork/package.des ../../source/udpnetwork/package.des ../../source/protocol/package.des ../../source/channelprotocol/package.des ../../source/scpprotocol/package.des ../../source/xmpprotocol/package.des ../../source/compressprotocol/package.des ../../source/ofpprotocol/package.des ../../source/ftdprotocol/package.des ../../source/xml/package.des ../../source/probelogger/package.des ../../source/version/package.des ../../source/refobject/package.des ../../source/sqlapi/package.des ../../source/ofpfield/package.des ../../source/UFCopy/package.des ../../source/customDataType/package.des ../../source/ftdfield/package.des ../../source/sysutility/package.des ../../source/sysdbutility/package.des ../../source/sysslog/package.des  sysslog.prj
	amake sysslog.prj
	@$(ECHO) rerun nmake
	@exit 1

clearoutput:
	@$(ECHO) Compiling... > output

platform_obj= ../../source/platform/system.o  ../../source/platform/platform.o  ../../source/platform/mpath.o 
platform_include= ../../source/platform/system.h  ../../source/platform/platform.h  ../../source/platform/mpath.h 
platform_includedir=-I../../source/platform/.
base_obj= ../../source/base/CBaseObject.o  ../../source/base/DesignError.o  ../../source/base/RuntimeError.o  ../../source/base/CLogger.o  ../../source/base/CProbeLogger.o  ../../source/base/monitorIndex.o 
base_include= ../../source/base/CBaseObject.h  ../../source/base/DesignError.h  ../../source/base/RuntimeError.h  ../../source/base/CLogger.h  ../../source/base/CProbeLogger.h  ../../source/base/monitorIndex.h  ../../source/base/public.h 
base_includedir=-I../../source/base/.
utility_obj= ../../source/utility/CTimeMeter.o  ../../source/utility/utility.o  ../../source/utility/Config.o 
utility_include= ../../source/utility/CTimeMeter.h  ../../source/utility/utility.h  ../../source/utility/Config.h 
utility_includedir=-I../../source/utility/.
datastruct_obj= ../../source/datastruct/CConfig.o  ../../source/datastruct/CFixMem.o  ../../source/datastruct/CAVLTree.o  ../../source/datastruct/CTransaction.o  ../../source/datastruct/CMemory.o  ../../source/datastruct/CFiniteState.o  ../../source/datastruct/CacheList.o  ../../source/datastruct/FieldDescribe.o  ../../source/datastruct/FieldSet.o  ../../source/datastruct/Index.o  ../../source/datastruct/Package.o  ../../source/datastruct/Flow.o  ../../source/datastruct/ReadOnlyFlow.o  ../../source/datastruct/FlowReader.o  ../../source/datastruct/OrderingQ.o  ../../source/datastruct/CachedFileFlow.o  ../../source/datastruct/CachedFlow.o  ../../source/datastruct/FileFlow.o  ../../source/datastruct/IndexPackageFlow.o  ../../source/datastruct/CSVParser.o  ../../source/datastruct/CSequenceInterface.o  ../../source/datastruct/CMemorySequence.o  ../../source/datastruct/CErrorEngine.o  ../../source/datastruct/CDate.o  ../../source/datastruct/Allocator.o  ../../source/datastruct/CHashIndex.o  ../../source/datastruct/PtrList.o  ../../source/datastruct/ObjAllocator.o 
datastruct_include= ../../source/datastruct/CachedFileFlow.h  ../../source/datastruct/CachedFlow.h  ../../source/datastruct/IndexPackageFlow.h  ../../source/datastruct/FileFlow.h  ../../source/datastruct/CConfig.h  ../../source/datastruct/CFixMem.h  ../../source/datastruct/CAVLTree.h  ../../source/datastruct/CResource.h  ../../source/datastruct/CTransaction.h  ../../source/datastruct/CMemory.h  ../../source/datastruct/CFiniteState.h  ../../source/datastruct/CacheList.h  ../../source/datastruct/FieldDescribe.h  ../../source/datastruct/FieldSet.h  ../../source/datastruct/Index.h  ../../source/datastruct/Package.h  ../../source/datastruct/HashMap.h  ../../source/datastruct/Flow.h  ../../source/datastruct/ReadOnlyFlow.h  ../../source/datastruct/FlowReader.h  ../../source/datastruct/PersistentState.h  ../../source/datastruct/OrderingQ.h  ../../source/datastruct/UFDataType.h  ../../source/datastruct/CSVParser.h  ../../source/datastruct/CSequenceInterface.h  ../../source/datastruct/CMemorySequence.h  ../../source/datastruct/CErrorEngine.h  ../../source/datastruct/CDate.h  ../../source/datastruct/Allocator.h  ../../source/datastruct/MemoryStack.h  ../../source/datastruct/ThreadSafeFlow.h  ../../source/datastruct/CHashIndex.h  ../../source/datastruct/PtrList.h  ../../source/datastruct/ObjAllocator.h 
datastruct_includedir=-I../../source/datastruct/.
event_obj= ../../source/event/EventHandler.o  ../../source/event/EventQueue.o  ../../source/event/EventDispatcher.o  ../../source/event/Reactor.o  ../../source/event/Semaphore.o  ../../source/event/Thread.o  ../../source/event/SelectReactor.o  ../../source/event/TimerHeap.o  ../../source/event/EpollReactor.o 
event_include= ../../source/event/EventHandler.h  ../../source/event/EventQueue.h  ../../source/event/Reactor.h  ../../source/event/Semaphore.h  ../../source/event/Thread.h  ../../source/event/Mutex.h  ../../source/event/SelectReactor.h  ../../source/event/TimerHeap.h  ../../source/event/TimerQueue.h  ../../source/event/EventDispatcher.h  ../../source/event/EpollReactor.h 
event_includedir=-I../../source/event/.
network_obj= ../../source/network/Channel.o  ../../source/network/Client.o  ../../source/network/ListenCtrl.o  ../../source/network/NetworkFactory.o  ../../source/network/Server.o  ../../source/network/ServiceName.o  ../../source/network/SocketInit.o 
network_include= ../../source/network/Channel.h  ../../source/network/Client.h  ../../source/network/ListenCtrl.h  ../../source/network/NetworkFactory.h  ../../source/network/Server.h  ../../source/network/ServiceName.h  ../../source/network/SocketInit.h 
network_includedir=-I../../source/network/.
tcpnetwork_obj= ../../source/tcpnetwork/TcpChannel.o  ../../source/tcpnetwork/TcpClient.o  ../../source/tcpnetwork/TcpServer.o  ../../source/tcpnetwork/TcpNetworkFactory.o 
tcpnetwork_include= ../../source/tcpnetwork/TcpChannel.h  ../../source/tcpnetwork/TcpClient.h  ../../source/tcpnetwork/TcpServer.h  ../../source/tcpnetwork/TcpNetworkFactory.h 
tcpnetwork_includedir=-I../../source/tcpnetwork/.
udpnetwork_obj= ../../source/udpnetwork/UdpChannel.o  ../../source/udpnetwork/UdpClient.o  ../../source/udpnetwork/UdpServer.o  ../../source/udpnetwork/UdpNetworkFactory.o 
udpnetwork_include= ../../source/udpnetwork/UdpChannel.h  ../../source/udpnetwork/UdpClient.h  ../../source/udpnetwork/UdpServer.h  ../../source/udpnetwork/UdpNetworkFactory.h 
udpnetwork_includedir=-I../../source/udpnetwork/.
protocol_obj= ../../source/protocol/Protocol.o 
protocol_include= ../../source/protocol/Protocol.h 
protocol_includedir=-I../../source/protocol/.
channelprotocol_obj= ../../source/channelprotocol/ChannelProtocol.o  ../../source/channelprotocol/ChannelPackage.o  ../../source/channelprotocol/Session.o  ../../source/channelprotocol/SessionFactory.o 
channelprotocol_include= ../../source/channelprotocol/ChannelProtocol.h  ../../source/channelprotocol/ChannelPackage.h  ../../source/channelprotocol/Session.h  ../../source/channelprotocol/SessionFactory.h 
channelprotocol_includedir=-I../../source/channelprotocol/.
scpprotocol_obj= ../../source/scpprotocol/SCPPackage.o  ../../source/scpprotocol/SCPPackageDesc.o  ../../source/scpprotocol/SCPProtocol.o 
scpprotocol_include= ../../source/scpprotocol/SCPPackage.h  ../../source/scpprotocol/SCPPackageDesc.h  ../../source/scpprotocol/SCPProtocol.h 
scpprotocol_includedir=-I../../source/scpprotocol/.
xmpprotocol_obj= ../../source/xmpprotocol/XMPPackage.o  ../../source/xmpprotocol/XMPSession.o  ../../source/xmpprotocol/XMPProtocol.o 
xmpprotocol_include= ../../source/xmpprotocol/XMPPackage.h  ../../source/xmpprotocol/XMPSession.h  ../../source/xmpprotocol/XMPProtocol.h 
xmpprotocol_includedir=-I../../source/xmpprotocol/.
compressprotocol_obj= ../../source/compressprotocol/CompressPackage.o  ../../source/compressprotocol/CompressProtocol.o  ../../source/compressprotocol/CompressUtil.o 
compressprotocol_include= ../../source/compressprotocol/CompressPackage.h  ../../source/compressprotocol/CompressProtocol.h  ../../source/compressprotocol/CompressUtil.h 
compressprotocol_includedir=-I../../source/compressprotocol/.
ofpprotocol_obj= ../../source/ofpprotocol/OFPPackage.o  ../../source/ofpprotocol/OFPProtocol.o  ../../source/ofpprotocol/OFPSession.o  ../../source/ofpprotocol/OFPPubEndPoint.o 
ofpprotocol_include= ../../source/ofpprotocol/OFPDataType.h  ../../source/ofpprotocol/OFPPackage.h  ../../source/ofpprotocol/OFPProtocol.h  ../../source/ofpprotocol/OFPSession.h  ../../source/ofpprotocol/OFPPubEndPoint.h 
ofpprotocol_includedir=-I../../source/ofpprotocol/.
ftdprotocol_obj= ../../source/ftdprotocol/FTDCPackage.o  ../../source/ftdprotocol/FTDCProtocol.o  ../../source/ftdprotocol/FTDCSession.o  ../../source/ftdprotocol/FTDCPubEndPoint.o  ../../source/ftdprotocol/FTDCSubEndPoint.o 
ftdprotocol_include= ../../source/ftdprotocol/FTDCPackage.h  ../../source/ftdprotocol/FTDCProtocol.h  ../../source/ftdprotocol/FTDCSession.h  ../../source/ftdprotocol/FTDCPubEndPoint.h  ../../source/ftdprotocol/FTDCSubEndPoint.h  ../../source/ftdprotocol/FTDCSubscriber.h 
ftdprotocol_includedir=-I../../source/ftdprotocol/.
xml_obj= ../../source/xml/CXML.o  ../../source/xml/XMLAction.o 
xml_include= ../../source/xml/CXML.h  ../../source/xml/XMLAction.h 
xml_includedir=-I../../source/xml/.
probelogger_obj= ../../source/probelogger/CSyslogService.o  ../../source/probelogger/CFilelogService.o 
probelogger_include= ../../source/probelogger/CSyslogService.h  ../../source/probelogger/CFilelogService.h 
probelogger_includedir=-I../../source/probelogger/.
version_obj= ../../source/version/version.o 
version_include= ../../source/version/version.h  ../../source/version/versionValue.h 
version_includedir=-I../../source/version/.
refobject_obj= ../../source/refobject/RefString.o 
refobject_include= ../../source/refobject/RefObject.h  ../../source/refobject/RefString.h 
refobject_includedir=-I../../source/refobject/.
sqlapi_obj=
sqlapi_lib= ../../source/sqlapi/sqlapi.a 
sqlapi_include= ../../source/sqlapi/SQLAPI.h 
sqlapi_includedir=-I../../source/sqlapi/.
ofpfield_obj= ../../source/ofpfield/OfpData.o 
ofpfield_include= ../../source/ofpfield/OfpData.h 
ofpfield_includedir=-I../../source/ofpfield/.
UFCopy_obj=
UFCopy_include= ../../source/UFCopy/UFCopy.h  ../../source/UFCopy/UFEntityCopy.h  ../../source/UFCopy/MDBCopy.h  ../../source/UFCopy/XTPCopy.h  ../../source/UFCopy/FTDCopy.h 
UFCopy_includedir=-I../../source/UFCopy/.
customDataType_obj=
customDataType_include= ../../source/customDataType/customDataType.h 
customDataType_includedir=-I../../source/customDataType/.
ftdfield_obj= ../../source/ftdfield/FtdData.o  ../../source/ftdfield/FtdPackageDesc.o 
ftdfield_include= ../../source/ftdfield/FtdData.h  ../../source/ftdfield/FtdPackageDesc.h 
ftdfield_includedir=-I../../source/ftdfield/.
sysutility_obj= ../../source/sysutility/systools.o  ../../source/sysutility/xmlcfg.o  ../../source/sysutility/FileRecordFinder.o  ../../source/sysutility/md5Handler.o  ../../source/sysutility/CTimePolicy.o  ../../source/sysutility/ThreadPool.o  ../../source/sysutility/StringUtil.o  ../../source/sysutility/CDeployConfig.o  ../../source/sysutility/PrjCommon.o  ../../source/sysutility/CCalendar.o  ../../source/sysutility/CSysInternalTopology.o 
sysutility_include= ../../source/sysutility/systools.h  ../../source/sysutility/xmlcfg.h  ../../source/sysutility/FileRecordFinder.h  ../../source/sysutility/md5Handler.h  ../../source/sysutility/CTimePolicy.h  ../../source/sysutility/FTDDataHelper.h  ../../source/sysutility/ThreadPool.h  ../../source/sysutility/SyncEvent.h  ../../source/sysutility/SyncEvent_Platform.h  ../../source/sysutility/ScopedLock.h  ../../source/sysutility/PrjCommon.h  ../../source/sysutility/StringUtil.h  ../../source/sysutility/CDeployConfig.h  ../../source/sysutility/CCalendar.h  ../../source/sysutility/CSysInternalTopology.h 
sysutility_includedir=-I../../source/sysutility/.
sysdbutility_obj= ../../source/sysdbutility/FTDDataWrapper.o  ../../source/sysdbutility/DBOperator.o 
sysdbutility_include= ../../source/sysdbutility/FTDDataWrapper.h  ../../source/sysdbutility/DBOperator.h 
sysdbutility_includedir=-I../../source/sysdbutility/.
sysslog_obj= ../../source/sysslog/sysslog.o  ../../source/sysslog/CounterConnector.o  ../../source/sysslog/CStatusSubscriber.o  ../../source/sysslog/CSlogServer.o  ../../source/sysslog/CPackageFilter.o  ../../source/sysslog/CDumpSession.o  ../../source/sysslog/CSlogConnection.o  ../../source/sysslog/COrderRttManager.o  ../../source/sysslog/slogparser.o  ../../source/sysslog/SessionProxy.o  ../../source/sysslog/TradeLogCodec.o 
sysslog_include= ../../source/sysslog/CounterConnector.h  ../../source/sysslog/CStatusSubscriber.h  ../../source/sysslog/CSlogServer.h  ../../source/sysslog/CPackageFilter.h  ../../source/sysslog/CDumpSession.h  ../../source/sysslog/CSlogConnection.h  ../../source/sysslog/COrderRttManager.h  ../../source/sysslog/slogparser.h  ../../source/sysslog/SessionProxy.h  ../../source/sysslog/TradeLogCodec.h 
sysslog_includedir=-I../../source/sysslog/.

all_objs= $(platform_obj)  $(base_obj)  $(utility_obj)  $(datastruct_obj)  $(event_obj)  $(network_obj)  $(tcpnetwork_obj)  $(udpnetwork_obj)  $(protocol_obj)  $(channelprotocol_obj)  $(scpprotocol_obj)  $(xmpprotocol_obj)  $(compressprotocol_obj)  $(ofpprotocol_obj)  $(ftdprotocol_obj)  $(xml_obj)  $(probelogger_obj)  $(version_obj)  $(refobject_obj)  $(sqlapi_obj)  $(ofpfield_obj)  $(UFCopy_obj)  $(customDataType_obj)  $(ftdfield_obj)  $(sysutility_obj)  $(sysdbutility_obj)  $(sysslog_obj) 
all_libs= $(platform_lib)  $(base_lib)  $(utility_lib)  $(datastruct_lib)  $(event_lib)  $(network_lib)  $(tcpnetwork_lib)  $(udpnetwork_lib)  $(protocol_lib)  $(channelprotocol_lib)  $(scpprotocol_lib)  $(xmpprotocol_lib)  $(compressprotocol_lib)  $(ofpprotocol_lib)  $(ftdprotocol_lib)  $(xml_lib)  $(probelogger_lib)  $(version_lib)  $(refobject_lib)  $(sqlapi_lib)  $(ofpfield_lib)  $(UFCopy_lib)  $(customDataType_lib)  $(ftdfield_lib)  $(sysutility_lib)  $(sysdbutility_lib)  $(sysslog_lib) 
INCLUDEDIR= $(platform_includedir)  $(base_includedir)  $(utility_includedir)  $(datastruct_includedir)  $(event_includedir)  $(network_includedir)  $(tcpnetwork_includedir)  $(udpnetwork_includedir)  $(protocol_includedir)  $(channelprotocol_includedir)  $(scpprotocol_includedir)  $(xmpprotocol_includedir)  $(compressprotocol_includedir)  $(ofpprotocol_includedir)  $(ftdprotocol_includedir)  $(xml_includedir)  $(probelogger_includedir)  $(version_includedir)  $(refobject_includedir)  $(sqlapi_includedir)  $(ofpfield_includedir)  $(UFCopy_includedir)  $(customDataType_includedir)  $(ftdfield_includedir)  $(sysutility_includedir)  $(sysdbutility_includedir)  $(sysslog_includedir) 

../../source/platform/system.o: ../../source/platform/system.cpp $(platform_include)  

../../source/platform/platform.o: ../../source/platform/platform.cpp $(platform_include)  

../../source/platform/mpath.o: ../../source/platform/mpath.cpp $(platform_include)  

../../source/base/CBaseObject.o: ../../source/base/CBaseObject.cpp $(base_include)   $(platform_include)

../../source/base/DesignError.o: ../../source/base/DesignError.cpp $(base_include)   $(platform_include)

../../source/base/RuntimeError.o: ../../source/base/RuntimeError.cpp $(base_include)   $(platform_include)

../../source/base/CLogger.o: ../../source/base/CLogger.cpp $(base_include)   $(platform_include)

../../source/base/CProbeLogger.o: ../../source/base/CProbeLogger.cpp $(base_include)   $(platform_include)

../../source/base/monitorIndex.o: ../../source/base/monitorIndex.cpp $(base_include)   $(platform_include)

../../source/utility/CTimeMeter.o: ../../source/utility/CTimeMeter.cpp $(utility_include)   $(platform_include) $(base_include)

../../source/utility/utility.o: ../../source/utility/utility.cpp $(utility_include)   $(platform_include) $(base_include)

../../source/utility/Config.o: ../../source/utility/Config.cpp $(utility_include)   $(platform_include) $(base_include)

../../source/datastruct/CConfig.o: ../../source/datastruct/CConfig.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/CFixMem.o: ../../source/datastruct/CFixMem.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/CAVLTree.o: ../../source/datastruct/CAVLTree.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/CTransaction.o: ../../source/datastruct/CTransaction.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/CMemory.o: ../../source/datastruct/CMemory.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/CFiniteState.o: ../../source/datastruct/CFiniteState.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/CacheList.o: ../../source/datastruct/CacheList.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/FieldDescribe.o: ../../source/datastruct/FieldDescribe.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/FieldSet.o: ../../source/datastruct/FieldSet.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/Index.o: ../../source/datastruct/Index.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/Package.o: ../../source/datastruct/Package.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/Flow.o: ../../source/datastruct/Flow.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/ReadOnlyFlow.o: ../../source/datastruct/ReadOnlyFlow.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/FlowReader.o: ../../source/datastruct/FlowReader.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/OrderingQ.o: ../../source/datastruct/OrderingQ.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/CachedFileFlow.o: ../../source/datastruct/CachedFileFlow.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/CachedFlow.o: ../../source/datastruct/CachedFlow.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/FileFlow.o: ../../source/datastruct/FileFlow.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/IndexPackageFlow.o: ../../source/datastruct/IndexPackageFlow.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/CSVParser.o: ../../source/datastruct/CSVParser.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/CSequenceInterface.o: ../../source/datastruct/CSequenceInterface.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/CMemorySequence.o: ../../source/datastruct/CMemorySequence.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/CErrorEngine.o: ../../source/datastruct/CErrorEngine.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/CDate.o: ../../source/datastruct/CDate.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/Allocator.o: ../../source/datastruct/Allocator.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/CHashIndex.o: ../../source/datastruct/CHashIndex.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/PtrList.o: ../../source/datastruct/PtrList.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/datastruct/ObjAllocator.o: ../../source/datastruct/ObjAllocator.cpp $(datastruct_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include)

../../source/event/EventHandler.o: ../../source/event/EventHandler.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

../../source/event/EventQueue.o: ../../source/event/EventQueue.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

../../source/event/EventDispatcher.o: ../../source/event/EventDispatcher.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

../../source/event/Reactor.o: ../../source/event/Reactor.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

../../source/event/Semaphore.o: ../../source/event/Semaphore.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

../../source/event/Thread.o: ../../source/event/Thread.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

../../source/event/SelectReactor.o: ../../source/event/SelectReactor.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

../../source/event/TimerHeap.o: ../../source/event/TimerHeap.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

../../source/event/EpollReactor.o: ../../source/event/EpollReactor.cpp $(event_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include)

../../source/network/Channel.o: ../../source/network/Channel.cpp $(network_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include)

../../source/network/Client.o: ../../source/network/Client.cpp $(network_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include)

../../source/network/ListenCtrl.o: ../../source/network/ListenCtrl.cpp $(network_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include)

../../source/network/NetworkFactory.o: ../../source/network/NetworkFactory.cpp $(network_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include)

../../source/network/Server.o: ../../source/network/Server.cpp $(network_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include)

../../source/network/ServiceName.o: ../../source/network/ServiceName.cpp $(network_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include)

../../source/network/SocketInit.o: ../../source/network/SocketInit.cpp $(network_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include)

../../source/tcpnetwork/TcpChannel.o: ../../source/tcpnetwork/TcpChannel.cpp $(tcpnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(event_include)

../../source/tcpnetwork/TcpClient.o: ../../source/tcpnetwork/TcpClient.cpp $(tcpnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(event_include)

../../source/tcpnetwork/TcpServer.o: ../../source/tcpnetwork/TcpServer.cpp $(tcpnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(event_include)

../../source/tcpnetwork/TcpNetworkFactory.o: ../../source/tcpnetwork/TcpNetworkFactory.cpp $(tcpnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(event_include)

../../source/udpnetwork/UdpChannel.o: ../../source/udpnetwork/UdpChannel.cpp $(udpnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(event_include)

../../source/udpnetwork/UdpClient.o: ../../source/udpnetwork/UdpClient.cpp $(udpnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(event_include)

../../source/udpnetwork/UdpServer.o: ../../source/udpnetwork/UdpServer.cpp $(udpnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(event_include)

../../source/udpnetwork/UdpNetworkFactory.o: ../../source/udpnetwork/UdpNetworkFactory.cpp $(udpnetwork_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(event_include)

../../source/protocol/Protocol.o: ../../source/protocol/Protocol.cpp $(protocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include)

../../source/channelprotocol/ChannelProtocol.o: ../../source/channelprotocol/ChannelProtocol.cpp $(channelprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(event_include)

../../source/channelprotocol/ChannelPackage.o: ../../source/channelprotocol/ChannelPackage.cpp $(channelprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(event_include)

../../source/channelprotocol/Session.o: ../../source/channelprotocol/Session.cpp $(channelprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(event_include)

../../source/channelprotocol/SessionFactory.o: ../../source/channelprotocol/SessionFactory.cpp $(channelprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(event_include)

../../source/scpprotocol/SCPPackage.o: ../../source/scpprotocol/SCPPackage.cpp $(scpprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(event_include)

../../source/scpprotocol/SCPPackageDesc.o: ../../source/scpprotocol/SCPPackageDesc.cpp $(scpprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(event_include)

../../source/scpprotocol/SCPProtocol.o: ../../source/scpprotocol/SCPProtocol.cpp $(scpprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(event_include)

../../source/xmpprotocol/XMPPackage.o: ../../source/xmpprotocol/XMPPackage.cpp $(xmpprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

../../source/xmpprotocol/XMPSession.o: ../../source/xmpprotocol/XMPSession.cpp $(xmpprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

../../source/xmpprotocol/XMPProtocol.o: ../../source/xmpprotocol/XMPProtocol.cpp $(xmpprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

../../source/compressprotocol/CompressPackage.o: ../../source/compressprotocol/CompressPackage.cpp $(compressprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

../../source/compressprotocol/CompressProtocol.o: ../../source/compressprotocol/CompressProtocol.cpp $(compressprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

../../source/compressprotocol/CompressUtil.o: ../../source/compressprotocol/CompressUtil.cpp $(compressprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(event_include)

../../source/ofpprotocol/OFPPackage.o: ../../source/ofpprotocol/OFPPackage.cpp $(ofpprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(event_include) $(channelprotocol_include)

../../source/ofpprotocol/OFPProtocol.o: ../../source/ofpprotocol/OFPProtocol.cpp $(ofpprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(event_include) $(channelprotocol_include)

../../source/ofpprotocol/OFPSession.o: ../../source/ofpprotocol/OFPSession.cpp $(ofpprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(event_include) $(channelprotocol_include)

../../source/ofpprotocol/OFPPubEndPoint.o: ../../source/ofpprotocol/OFPPubEndPoint.cpp $(ofpprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(network_include) $(protocol_include) $(event_include) $(channelprotocol_include)

../../source/ftdprotocol/FTDCPackage.o: ../../source/ftdprotocol/FTDCPackage.cpp $(ftdprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(compressprotocol_include)

../../source/ftdprotocol/FTDCProtocol.o: ../../source/ftdprotocol/FTDCProtocol.cpp $(ftdprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(compressprotocol_include)

../../source/ftdprotocol/FTDCSession.o: ../../source/ftdprotocol/FTDCSession.cpp $(ftdprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(compressprotocol_include)

../../source/ftdprotocol/FTDCPubEndPoint.o: ../../source/ftdprotocol/FTDCPubEndPoint.cpp $(ftdprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(compressprotocol_include)

../../source/ftdprotocol/FTDCSubEndPoint.o: ../../source/ftdprotocol/FTDCSubEndPoint.cpp $(ftdprotocol_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(compressprotocol_include)

../../source/xml/CXML.o: ../../source/xml/CXML.cpp $(xml_include)   $(platform_include) $(base_include) $(probelogger_include) $(datastruct_include) $(utility_include)

../../source/xml/XMLAction.o: ../../source/xml/XMLAction.cpp $(xml_include)   $(platform_include) $(base_include) $(probelogger_include) $(datastruct_include) $(utility_include)

../../source/probelogger/CSyslogService.o: ../../source/probelogger/CSyslogService.cpp $(probelogger_include)   $(platform_include) $(base_include) $(datastruct_include)

../../source/probelogger/CFilelogService.o: ../../source/probelogger/CFilelogService.cpp $(probelogger_include)   $(platform_include) $(base_include) $(datastruct_include)

../../source/version/version.o: ../../source/version/version.cpp $(version_include)   $(platform_include) $(base_include) $(probelogger_include)

../../source/refobject/RefString.o: ../../source/refobject/RefString.cpp $(refobject_include)   $(platform_include)

../../source/ofpfield/OfpData.o: ../../source/ofpfield/OfpData.cpp $(ofpfield_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(customDataType_include) $(ofpprotocol_include) $(network_include) $(protocol_include) $(event_include) $(channelprotocol_include)

../../source/ftdfield/FtdData.o: ../../source/ftdfield/FtdData.cpp $(ftdfield_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(customDataType_include)

../../source/ftdfield/FtdPackageDesc.o: ../../source/ftdfield/FtdPackageDesc.cpp $(ftdfield_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(customDataType_include)

../../source/sysutility/systools.o: ../../source/sysutility/systools.cpp $(sysutility_include)   $(platform_include) $(base_include) $(utility_include) $(probelogger_include) $(datastruct_include) $(network_include) $(event_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(scpprotocol_include) $(customDataType_include) $(ftdfield_include) $(ftdprotocol_include) $(refobject_include)

../../source/sysutility/xmlcfg.o: ../../source/sysutility/xmlcfg.cpp $(sysutility_include)   $(platform_include) $(base_include) $(utility_include) $(probelogger_include) $(datastruct_include) $(network_include) $(event_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(scpprotocol_include) $(customDataType_include) $(ftdfield_include) $(ftdprotocol_include) $(refobject_include)

../../source/sysutility/FileRecordFinder.o: ../../source/sysutility/FileRecordFinder.cpp $(sysutility_include)   $(platform_include) $(base_include) $(utility_include) $(probelogger_include) $(datastruct_include) $(network_include) $(event_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(scpprotocol_include) $(customDataType_include) $(ftdfield_include) $(ftdprotocol_include) $(refobject_include)

../../source/sysutility/md5Handler.o: ../../source/sysutility/md5Handler.cpp $(sysutility_include)   $(platform_include) $(base_include) $(utility_include) $(probelogger_include) $(datastruct_include) $(network_include) $(event_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(scpprotocol_include) $(customDataType_include) $(ftdfield_include) $(ftdprotocol_include) $(refobject_include)

../../source/sysutility/CTimePolicy.o: ../../source/sysutility/CTimePolicy.cpp $(sysutility_include)   $(platform_include) $(base_include) $(utility_include) $(probelogger_include) $(datastruct_include) $(network_include) $(event_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(scpprotocol_include) $(customDataType_include) $(ftdfield_include) $(ftdprotocol_include) $(refobject_include)

../../source/sysutility/ThreadPool.o: ../../source/sysutility/ThreadPool.cpp $(sysutility_include)   $(platform_include) $(base_include) $(utility_include) $(probelogger_include) $(datastruct_include) $(network_include) $(event_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(scpprotocol_include) $(customDataType_include) $(ftdfield_include) $(ftdprotocol_include) $(refobject_include)

../../source/sysutility/StringUtil.o: ../../source/sysutility/StringUtil.cpp $(sysutility_include)   $(platform_include) $(base_include) $(utility_include) $(probelogger_include) $(datastruct_include) $(network_include) $(event_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(scpprotocol_include) $(customDataType_include) $(ftdfield_include) $(ftdprotocol_include) $(refobject_include)

../../source/sysutility/CDeployConfig.o: ../../source/sysutility/CDeployConfig.cpp $(sysutility_include)   $(platform_include) $(base_include) $(utility_include) $(probelogger_include) $(datastruct_include) $(network_include) $(event_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(scpprotocol_include) $(customDataType_include) $(ftdfield_include) $(ftdprotocol_include) $(refobject_include)

../../source/sysutility/PrjCommon.o: ../../source/sysutility/PrjCommon.cpp $(sysutility_include)   $(platform_include) $(base_include) $(utility_include) $(probelogger_include) $(datastruct_include) $(network_include) $(event_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(scpprotocol_include) $(customDataType_include) $(ftdfield_include) $(ftdprotocol_include) $(refobject_include)

../../source/sysutility/CCalendar.o: ../../source/sysutility/CCalendar.cpp $(sysutility_include)   $(platform_include) $(base_include) $(utility_include) $(probelogger_include) $(datastruct_include) $(network_include) $(event_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(scpprotocol_include) $(customDataType_include) $(ftdfield_include) $(ftdprotocol_include) $(refobject_include)

../../source/sysutility/CSysInternalTopology.o: ../../source/sysutility/CSysInternalTopology.cpp $(sysutility_include)   $(platform_include) $(base_include) $(utility_include) $(probelogger_include) $(datastruct_include) $(network_include) $(event_include) $(protocol_include) $(channelprotocol_include) $(xmpprotocol_include) $(scpprotocol_include) $(customDataType_include) $(ftdfield_include) $(ftdprotocol_include) $(refobject_include)

../../source/sysdbutility/FTDDataWrapper.o: ../../source/sysdbutility/FTDDataWrapper.cpp $(sysdbutility_include)   $(platform_include) $(base_include) $(utility_include) $(datastruct_include) $(customDataType_include) $(ftdfield_include)

../../source/sysdbutility/DBOperator.o: ../../source/sysdbutility/DBOperator.cpp $(sysdbutility_include)   $(platform_include) $(base_include) $(utility_include) $(datastruct_include) $(customDataType_include) $(ftdfield_include)

../../source/sysslog/sysslog.o: ../../source/sysslog/sysslog.cpp $(sysslog_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(tcpnetwork_include) $(protocol_include) $(channelprotocol_include) $(scpprotocol_include) $(xmpprotocol_include) $(ftdprotocol_include) $(ftdfield_include) $(xml_include) $(sysdbutility_include)

../../source/sysslog/CounterConnector.o: ../../source/sysslog/CounterConnector.cpp $(sysslog_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(tcpnetwork_include) $(protocol_include) $(channelprotocol_include) $(scpprotocol_include) $(xmpprotocol_include) $(ftdprotocol_include) $(ftdfield_include) $(xml_include) $(sysdbutility_include)

../../source/sysslog/CStatusSubscriber.o: ../../source/sysslog/CStatusSubscriber.cpp $(sysslog_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(tcpnetwork_include) $(protocol_include) $(channelprotocol_include) $(scpprotocol_include) $(xmpprotocol_include) $(ftdprotocol_include) $(ftdfield_include) $(xml_include) $(sysdbutility_include)

../../source/sysslog/CSlogServer.o: ../../source/sysslog/CSlogServer.cpp $(sysslog_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(tcpnetwork_include) $(protocol_include) $(channelprotocol_include) $(scpprotocol_include) $(xmpprotocol_include) $(ftdprotocol_include) $(ftdfield_include) $(xml_include) $(sysdbutility_include)

../../source/sysslog/CPackageFilter.o: ../../source/sysslog/CPackageFilter.cpp $(sysslog_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(tcpnetwork_include) $(protocol_include) $(channelprotocol_include) $(scpprotocol_include) $(xmpprotocol_include) $(ftdprotocol_include) $(ftdfield_include) $(xml_include) $(sysdbutility_include)

../../source/sysslog/CDumpSession.o: ../../source/sysslog/CDumpSession.cpp $(sysslog_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(tcpnetwork_include) $(protocol_include) $(channelprotocol_include) $(scpprotocol_include) $(xmpprotocol_include) $(ftdprotocol_include) $(ftdfield_include) $(xml_include) $(sysdbutility_include)

../../source/sysslog/CSlogConnection.o: ../../source/sysslog/CSlogConnection.cpp $(sysslog_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(tcpnetwork_include) $(protocol_include) $(channelprotocol_include) $(scpprotocol_include) $(xmpprotocol_include) $(ftdprotocol_include) $(ftdfield_include) $(xml_include) $(sysdbutility_include)

../../source/sysslog/COrderRttManager.o: ../../source/sysslog/COrderRttManager.cpp $(sysslog_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(tcpnetwork_include) $(protocol_include) $(channelprotocol_include) $(scpprotocol_include) $(xmpprotocol_include) $(ftdprotocol_include) $(ftdfield_include) $(xml_include) $(sysdbutility_include)

../../source/sysslog/slogparser.o: ../../source/sysslog/slogparser.cpp $(sysslog_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(tcpnetwork_include) $(protocol_include) $(channelprotocol_include) $(scpprotocol_include) $(xmpprotocol_include) $(ftdprotocol_include) $(ftdfield_include) $(xml_include) $(sysdbutility_include)

../../source/sysslog/SessionProxy.o: ../../source/sysslog/SessionProxy.cpp $(sysslog_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(tcpnetwork_include) $(protocol_include) $(channelprotocol_include) $(scpprotocol_include) $(xmpprotocol_include) $(ftdprotocol_include) $(ftdfield_include) $(xml_include) $(sysdbutility_include)

../../source/sysslog/TradeLogCodec.o: ../../source/sysslog/TradeLogCodec.cpp $(sysslog_include)   $(platform_include) $(base_include) $(probelogger_include) $(utility_include) $(datastruct_include) $(event_include) $(network_include) $(tcpnetwork_include) $(protocol_include) $(channelprotocol_include) $(scpprotocol_include) $(xmpprotocol_include) $(ftdprotocol_include) $(ftdfield_include) $(xml_include) $(sysdbutility_include)


../../source/ofpfield/OfpData.h:../../source/ofpfield/OfpData.h.tpl ../../datamodel/env/OFPMisc.xml
	$(PUMP) ../../source/ofpfield/OfpData.h ../../source/ofpfield/OfpData.h.tpl ../../datamodel/env/OFPMisc.xml >> output

../../source/ofpfield/OfpData.cpp:../../source/ofpfield/OfpData.cpp.tpl ../../datamodel/env/OFPMisc.xml
	$(PUMP) ../../source/ofpfield/OfpData.cpp ../../source/ofpfield/OfpData.cpp.tpl ../../datamodel/env/OFPMisc.xml >> output

../../source/UFCopy/UFEntityCopy.h:../../source/UFCopy/UFEntityCopy.h.tpl ../../datamodel/commonEnv/UFEntity.xml
	$(PUMP) ../../source/UFCopy/UFEntityCopy.h ../../source/UFCopy/UFEntityCopy.h.tpl ../../datamodel/commonEnv/UFEntity.xml >> output

../../source/UFCopy/MDBCopy.h:../../source/UFCopy/MDBCopy.h.tpl ../../datamodel/envGenerated/MDB.xml
	$(PUMP) ../../source/UFCopy/MDBCopy.h ../../source/UFCopy/MDBCopy.h.tpl ../../datamodel/envGenerated/MDB.xml >> output

../../source/UFCopy/XTPCopy.h:../../source/UFCopy/XTPCopy.h.tpl ../../datamodel/envGenerated/XTP.xml
	$(PUMP) ../../source/UFCopy/XTPCopy.h ../../source/UFCopy/XTPCopy.h.tpl ../../datamodel/envGenerated/XTP.xml >> output

../../source/UFCopy/FTDCopy.h:../../source/UFCopy/FTDCopy.h.tpl ../../datamodel/envGenerated/FTD.xml
	$(PUMP) ../../source/UFCopy/FTDCopy.h ../../source/UFCopy/FTDCopy.h.tpl ../../datamodel/envGenerated/FTD.xml >> output

../../source/customDataType/customDataType.h:../../source/customDataType/customDataType.h.tpl ../../datamodel/commonEnv/UFDataType.xml
	$(PUMP) ../../source/customDataType/customDataType.h ../../source/customDataType/customDataType.h.tpl ../../datamodel/commonEnv/UFDataType.xml >> output

../../source/ftdfield/FtdPackageDesc.h:../../source/ftdfield/FtdPackageDesc.h.tpl ../../datamodel/envGenerated/FTD.xml
	$(PUMP) ../../source/ftdfield/FtdPackageDesc.h ../../source/ftdfield/FtdPackageDesc.h.tpl ../../datamodel/envGenerated/FTD.xml >> output

../../source/ftdfield/FtdPackageDesc.cpp:../../source/ftdfield/FtdPackageDesc.cpp.tpl ../../datamodel/envGenerated/FTD.xml
	$(PUMP) ../../source/ftdfield/FtdPackageDesc.cpp ../../source/ftdfield/FtdPackageDesc.cpp.tpl ../../datamodel/envGenerated/FTD.xml >> output

../../source/ftdfield/FtdData.h:../../source/ftdfield/FtdData.h.tpl ../../datamodel/envGenerated/FTD.xml
	$(PUMP) ../../source/ftdfield/FtdData.h ../../source/ftdfield/FtdData.h.tpl ../../datamodel/envGenerated/FTD.xml >> output

../../source/ftdfield/FtdData.cpp:../../source/ftdfield/FtdData.cpp.tpl ../../datamodel/envGenerated/FTD.xml
	$(PUMP) ../../source/ftdfield/FtdData.cpp ../../source/ftdfield/FtdData.cpp.tpl ../../datamodel/envGenerated/FTD.xml >> output


$(target): $(all_objs)
	$(LINK) $(LDFLAGS) -o $@ $(all_objs) $(all_libs) $(LIBS) >> output


clean:
	-$(DEL) $(platform_obj)
	-$(DEL) $(base_obj)
	-$(DEL) $(utility_obj)
	-$(DEL) $(datastruct_obj)
	-$(DEL) $(event_obj)
	-$(DEL) $(network_obj)
	-$(DEL) $(tcpnetwork_obj)
	-$(DEL) $(udpnetwork_obj)
	-$(DEL) $(protocol_obj)
	-$(DEL) $(channelprotocol_obj)
	-$(DEL) $(scpprotocol_obj)
	-$(DEL) $(xmpprotocol_obj)
	-$(DEL) $(compressprotocol_obj)
	-$(DEL) $(ofpprotocol_obj)
	-$(DEL) $(ftdprotocol_obj)
	-$(DEL) $(xml_obj)
	-$(DEL) $(probelogger_obj)
	-$(DEL) $(version_obj)
	-$(DEL) $(refobject_obj)
	-$(DEL) $(sqlapi_obj)
	-$(DEL) $(ofpfield_obj)
	-$(DEL) $(UFCopy_obj)
	-$(DEL) $(customDataType_obj)
	-$(DEL) $(ftdfield_obj)
	-$(DEL) $(sysutility_obj)
	-$(DEL) $(sysdbutility_obj)
	-$(DEL) $(sysslog_obj)
	-$(DEL)   ../../source/ofpfield/OfpData.h ../../source/ofpfield/OfpData.cpp ../../source/UFCopy/UFEntityCopy.h ../../source/UFCopy/MDBCopy.h ../../source/UFCopy/XTPCopy.h ../../source/UFCopy/FTDCopy.h ../../source/customDataType/customDataType.h ../../source/ftdfield/FtdPackageDesc.h ../../source/ftdfield/FtdPackageDesc.cpp ../../source/ftdfield/FtdData.h ../../source/ftdfield/FtdData.cpp
	-$(DEL) $(target)

pump:   ../../source/ofpfield/OfpData.h ../../source/ofpfield/OfpData.cpp ../../source/UFCopy/UFEntityCopy.h ../../source/UFCopy/MDBCopy.h ../../source/UFCopy/XTPCopy.h ../../source/UFCopy/FTDCopy.h ../../source/customDataType/customDataType.h ../../source/ftdfield/FtdPackageDesc.h ../../source/ftdfield/FtdPackageDesc.cpp ../../source/ftdfield/FtdData.h ../../source/ftdfield/FtdData.cpp
lua:  

