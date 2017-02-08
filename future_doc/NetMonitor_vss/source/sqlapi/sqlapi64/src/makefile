# Makefile for SQLAPI++
# Linux/Unix version

.SUFFIXES:
.SUFFIXES: .cpp .obj .o

CFG=release

SA_DEFINE=SA_TRIAL

CPP = g++ 
AR = ar
RUNLIB = ranlib
LIBS = -ldld -lpthread

SQLAPI_INC = -I../include -I../include/ora_linux
SQLAPI_CLIENT_DEFS=-DSQLAPI_oraClient

CPPFLAGS = -Wall -pthread -mlp64 
CPPDEFS = -D$(SA_DEFINE) -DLINUX -DNDEBUG $(SQLAPI_CLIENT_DEFS) -D_XOPEN_SOURCE_EXTENDED -DSA_USE_PTHREAD -D_POSIX_C_SOURCE=199506L -DSS_64BIT_SERVER -DHPUX_IA64
LDFLAGS = -s

.cpp.o:
	$(CPP) $(CPPFLAGS) -c -g       $(CPPDEFS) $(SQLAPI_INC) $< -o $@

SOBJS =	SQLAPI.o ISAClient.o samisc.o \
	ora7API_linux.o ora8API_linux.o oraClient.o \

ALL:  libsqlapi.a

libsqlapi.a: $(SOBJS)
	${AR} r $@ $(SOBJS)
	$(RUNLIB) $@
	$(CPP) $(CPPFLAGS) -shared $(SOBJS) -o libsqlapi.so 
step1:step1.o
	$(CPP) -o $@ step1.o -L$(HOME)/sqlapi/src -lsqlapi -ldld -mlp64	

all: ALL

clean:
	-@rm -f *.obj
	-@rm -f *.o

safe_clean: clean
	-@rm -f *.so
	-@rm -f *.a
	-@rm -f test
	-@rm -f tests
	-@rm -f testd
	-@rm -f testds
