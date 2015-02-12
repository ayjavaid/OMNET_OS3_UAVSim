#
# OMNeT++/OMNEST Makefile for libGPSApp
#
# This file was generated with the command:
#  opp_makemake -f --deep --make-so -O out -I../../inet/src/networklayer/common -I../../inet/src -I../../inet/src/networklayer/icmpv6 -I../../inet/src/world/obstacles -I../../inet/src/networklayer/xmipv6 -I../../inet/src/networklayer/contract -I../../inet/src/networklayer/autorouting/ipv4 -I../../inet/src/util -I../../inet/src/transport/contract -I../../inet/src/status -I../../inet/src/mobility/static -I../../CNI_OS3/src/base -I../../inet/src/linklayer/radio/propagation -I../../CNI_OS3/src/libnorad -I../../inet/src/linklayer/radio -I../../inet/src/util/headerserializers/tcp -I../../inet/src/networklayer/ipv4 -I../../inet/src/mobility/contract -I../../inet/src/util/headerserializers/ipv4 -I../../inet/src/applications/common -I../../inet/src/base -I../../inet/src/mobility/single -I../../inet/src/util/headerserializers -I../../inet/src/world/radio -I../../inet/src/networklayer/ipv6 -I../../inet/src/transport/sctp -I../../inet/src/util/headerserializers/udp -I../../CNI_OS3/src/mobility -I../../inet/src/networklayer/ipv6tunneling -I../../inet/src/applications/pingapp -I../../inet/src/battery/models -I../../inet/src/util/headerserializers/ipv6 -I../../inet/src/util/headerserializers/sctp -I../../inet/src/linklayer/contract -I../../inet/src/transport/tcp_common -I../../inet/src/networklayer/arp -I../../inet/src/mobility/common -I../../inet/src/transport/udp -L../../CNI_OS3/out/$$\(CONFIGNAME\)/src -L../../CNI_OS3/out/$$\(CONFIGNAME\) -L../../inet/out/$$\(CONFIGNAME\)/src -lCNI_OS3 -lCNI_OS3 -linet -DINET_IMPORT -KCNI_OS3_PROJ=../../CNI_OS3 -KINET_PROJ=../../inet
#

# Name of target to be created (-o option)
TARGET = libGPSApp$(SHARED_LIB_SUFFIX)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../../inet/src/networklayer/common \
    -I../../inet/src \
    -I../../inet/src/networklayer/icmpv6 \
    -I../../inet/src/world/obstacles \
    -I../../inet/src/networklayer/xmipv6 \
    -I../../inet/src/networklayer/contract \
    -I../../inet/src/networklayer/autorouting/ipv4 \
    -I../../inet/src/util \
    -I../../inet/src/transport/contract \
    -I../../inet/src/status \
    -I../../inet/src/mobility/static \
    -I../../CNI_OS3/src/base \
    -I../../inet/src/linklayer/radio/propagation \
    -I../../CNI_OS3/src/libnorad \
    -I../../inet/src/linklayer/radio \
    -I../../inet/src/util/headerserializers/tcp \
    -I../../inet/src/networklayer/ipv4 \
    -I../../inet/src/mobility/contract \
    -I../../inet/src/util/headerserializers/ipv4 \
    -I../../inet/src/applications/common \
    -I../../inet/src/base \
    -I../../inet/src/mobility/single \
    -I../../inet/src/util/headerserializers \
    -I../../inet/src/world/radio \
    -I../../inet/src/networklayer/ipv6 \
    -I../../inet/src/transport/sctp \
    -I../../inet/src/util/headerserializers/udp \
    -I../../CNI_OS3/src/mobility \
    -I../../inet/src/networklayer/ipv6tunneling \
    -I../../inet/src/applications/pingapp \
    -I../../inet/src/battery/models \
    -I../../inet/src/util/headerserializers/ipv6 \
    -I../../inet/src/util/headerserializers/sctp \
    -I../../inet/src/linklayer/contract \
    -I../../inet/src/transport/tcp_common \
    -I../../inet/src/networklayer/arp \
    -I../../inet/src/mobility/common \
    -I../../inet/src/transport/udp \
    -I.

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../../CNI_OS3/out/$(CONFIGNAME)/src -L../../CNI_OS3/out/$(CONFIGNAME) -L../../inet/out/$(CONFIGNAME)/src  -lCNI_OS3 -lCNI_OS3 -linet
LIBS += -Wl,-rpath,`abspath ../../CNI_OS3/out/$(CONFIGNAME)/src` -Wl,-rpath,`abspath ../../CNI_OS3/out/$(CONFIGNAME)` -Wl,-rpath,`abspath ../../inet/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = $O/GPSApp.o $O/GPSPacket_m.o

# Message files
MSGFILES = \
    GPSPacket.msg

# Other makefile variables (-K)
CNI_OS3_PROJ=../../CNI_OS3
INET_PROJ=../../inet

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppenvir$D $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS) -DINET_IMPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating shared library: $@
	$(Q)$(SHLIB_LD) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS) $(LDFLAGS)
	$(Q)$(SHLIB_POSTPROCESS) $O/$(TARGET)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f GPSApp GPSApp.exe libGPSApp.so libGPSApp.a libGPSApp.dll libGPSApp.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/GPSApp.o: GPSApp.cc \
	$(CNI_OS3_PROJ)/src/base/Norad.h \
	$(CNI_OS3_PROJ)/src/base/WebServiceControl.h \
	$(CNI_OS3_PROJ)/src/libnorad/cEci.h \
	$(CNI_OS3_PROJ)/src/libnorad/cJulian.h \
	$(CNI_OS3_PROJ)/src/libnorad/cNoradBase.h \
	$(CNI_OS3_PROJ)/src/libnorad/cNoradSDP4.h \
	$(CNI_OS3_PROJ)/src/libnorad/cNoradSGP4.h \
	$(CNI_OS3_PROJ)/src/libnorad/cOrbit.h \
	$(CNI_OS3_PROJ)/src/libnorad/cSite.h \
	$(CNI_OS3_PROJ)/src/libnorad/cTLE.h \
	$(CNI_OS3_PROJ)/src/libnorad/cVector.h \
	$(CNI_OS3_PROJ)/src/libnorad/ccoord.h \
	$(CNI_OS3_PROJ)/src/libnorad/globals.h \
	$(CNI_OS3_PROJ)/src/libnorad/libnorad.h \
	$(CNI_OS3_PROJ)/src/mobility/SatSGP4FisheyeMobility.h \
	$(CNI_OS3_PROJ)/src/mobility/SatSGP4Mobility.h \
	GPSApp.h \
	GPSPacket_m.h \
	$(INET_PROJ)/src/applications/common/ApplicationBase.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/ILifecycle.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/LifecycleOperation.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/base/NodeOperations.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	$(INET_PROJ)/src/base/OperationalBase.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/mobility/common/LineSegmentsMobilityBase.h \
	$(INET_PROJ)/src/mobility/common/MobilityBase.h \
	$(INET_PROJ)/src/mobility/common/MovingMobilityBase.h \
	$(INET_PROJ)/src/mobility/contract/IMobility.h \
	$(INET_PROJ)/src/mobility/single/CircleMobility.h \
	$(INET_PROJ)/src/mobility/single/LinearMobility.h \
	$(INET_PROJ)/src/mobility/single/RectangleMobility.h \
	$(INET_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddressResolver.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET_PROJ)/src/transport/contract/UDPSocket.h \
	$(INET_PROJ)/src/util/FWMath.h
$O/GPSPacket_m.o: GPSPacket_m.cc \
	GPSPacket_m.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/INETDefs.h

