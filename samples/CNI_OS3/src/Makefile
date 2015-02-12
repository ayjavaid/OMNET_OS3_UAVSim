#
# OMNeT++/OMNEST Makefile for libCNI_OS3
#
# This file was generated with the command:
#  opp_makemake -f --deep --make-so -O out -I../../inet/src/networklayer/common -I../../inet/src/networklayer/icmpv6 -I../../inet/src -I../../inet/src/world/obstacles -I../../inet/src/networklayer/xmipv6 -I../../inet/src/networklayer/contract -I../../inet/src/networklayer/autorouting/ipv4 -I../../inet/src/util -I../../inet/src/transport/contract -I../../inet/src/status -I../../inet/src/linklayer/radio/propagation -I../../inet/src/linklayer/radio -I../../inet/src/util/headerserializers/tcp -I../../inet/src/networklayer/ipv4 -I../../inet/src/mobility/contract -I../../inet/src/util/headerserializers/ipv4 -I../../inet/src/base -I../../inet/src/util/headerserializers -I../../inet/src/world/radio -I../../inet/src/networklayer/ipv6 -I../../inet/src/transport/sctp -I../../inet/src/util/headerserializers/udp -I../../inet/src/networklayer/ipv6tunneling -I../../inet/src/applications/pingapp -I../../inet/src/battery/models -I../../inet/src/util/headerserializers/ipv6 -I../../inet/src/util/headerserializers/sctp -I../../inet/src/linklayer/contract -I../../inet/src/networklayer/arp -I../../inet/src/transport/tcp_common -I../../inet/src/transport/udp -I../../inet/src/mobility/common -L../../inet/out/$$\(CONFIGNAME\)/src -L../out/$$\(CONFIGNAME\) -lcurl -linet -DINET_IMPORT -KINET_PROJ=../../inet
#

# Name of target to be created (-o option)
TARGET = libCNI_OS3$(SHARED_LIB_SUFFIX)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../../inet/src/networklayer/common \
    -I../../inet/src/networklayer/icmpv6 \
    -I../../inet/src \
    -I../../inet/src/world/obstacles \
    -I../../inet/src/networklayer/xmipv6 \
    -I../../inet/src/networklayer/contract \
    -I../../inet/src/networklayer/autorouting/ipv4 \
    -I../../inet/src/util \
    -I../../inet/src/transport/contract \
    -I../../inet/src/status \
    -I../../inet/src/linklayer/radio/propagation \
    -I../../inet/src/linklayer/radio \
    -I../../inet/src/util/headerserializers/tcp \
    -I../../inet/src/networklayer/ipv4 \
    -I../../inet/src/mobility/contract \
    -I../../inet/src/util/headerserializers/ipv4 \
    -I../../inet/src/base \
    -I../../inet/src/util/headerserializers \
    -I../../inet/src/world/radio \
    -I../../inet/src/networklayer/ipv6 \
    -I../../inet/src/transport/sctp \
    -I../../inet/src/util/headerserializers/udp \
    -I../../inet/src/networklayer/ipv6tunneling \
    -I../../inet/src/applications/pingapp \
    -I../../inet/src/battery/models \
    -I../../inet/src/util/headerserializers/ipv6 \
    -I../../inet/src/util/headerserializers/sctp \
    -I../../inet/src/linklayer/contract \
    -I../../inet/src/networklayer/arp \
    -I../../inet/src/transport/tcp_common \
    -I../../inet/src/transport/udp \
    -I../../inet/src/mobility/common \
    -I. \
    -Ibase \
    -Ilibnorad \
    -Imobility \
    -Isimulations \
    -Isimulations/SatSGP4 \
    -Isimulations/SatSGP4/images \
    -Isimulations/SatSGP4/images/weatherIcons \
    -Isimulations/SatSGP4/results \
    -Isimulations/TestFarha \
    -Isimulations/Validation

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../../inet/out/$(CONFIGNAME)/src -L../out/$(CONFIGNAME)  -lcurl -linet
LIBS += -Wl,-rpath,`abspath ../../inet/out/$(CONFIGNAME)/src` -Wl,-rpath,`abspath ../out/$(CONFIGNAME)`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/base/WebServiceControl.o \
    $O/base/observer.o \
    $O/base/UserConfig.o \
    $O/base/Norad.o \
    $O/base/WeatherControl.o \
    $O/base/Calculation.o \
    $O/libnorad/cTLE.o \
    $O/libnorad/cNoradSGP4.o \
    $O/libnorad/cEci.o \
    $O/libnorad/ccoord.o \
    $O/libnorad/cNoradBase.o \
    $O/libnorad/cNoradSDP4.o \
    $O/libnorad/cSite.o \
    $O/libnorad/cJulian.o \
    $O/libnorad/cOrbit.o \
    $O/libnorad/globals.o \
    $O/libnorad/cVector.o \
    $O/mobility/SatSGP4FisheyeMobility.o \
    $O/mobility/LUTMotionMobility.o \
    $O/mobility/SatSGP4Mobility.o

# Message files
MSGFILES =

# Other makefile variables (-K)
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
	$(Q)-rm -f CNI_OS3 CNI_OS3.exe libCNI_OS3.so libCNI_OS3.a libCNI_OS3.dll libCNI_OS3.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f base/*_m.cc base/*_m.h
	$(Q)-rm -f libnorad/*_m.cc libnorad/*_m.h
	$(Q)-rm -f mobility/*_m.cc mobility/*_m.h
	$(Q)-rm -f simulations/*_m.cc simulations/*_m.h
	$(Q)-rm -f simulations/SatSGP4/*_m.cc simulations/SatSGP4/*_m.h
	$(Q)-rm -f simulations/SatSGP4/images/*_m.cc simulations/SatSGP4/images/*_m.h
	$(Q)-rm -f simulations/SatSGP4/images/weatherIcons/*_m.cc simulations/SatSGP4/images/weatherIcons/*_m.h
	$(Q)-rm -f simulations/SatSGP4/results/*_m.cc simulations/SatSGP4/results/*_m.h
	$(Q)-rm -f simulations/TestFarha/*_m.cc simulations/TestFarha/*_m.h
	$(Q)-rm -f simulations/Validation/*_m.cc simulations/Validation/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc base/*.cc libnorad/*.cc mobility/*.cc simulations/*.cc simulations/SatSGP4/*.cc simulations/SatSGP4/images/*.cc simulations/SatSGP4/images/weatherIcons/*.cc simulations/SatSGP4/results/*.cc simulations/TestFarha/*.cc simulations/Validation/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/base/Calculation.o: base/Calculation.cc \
	base/Calculation.h \
	base/Norad.h \
	base/UserConfig.h \
	base/WeatherControl.h \
	base/WebServiceControl.h \
	libnorad/cEci.h \
	libnorad/cJulian.h \
	libnorad/cNoradBase.h \
	libnorad/cNoradSDP4.h \
	libnorad/cNoradSGP4.h \
	libnorad/cOrbit.h \
	libnorad/cSite.h \
	libnorad/cTLE.h \
	libnorad/cVector.h \
	libnorad/ccoord.h \
	libnorad/globals.h \
	libnorad/libnorad.h \
	mobility/SatSGP4FisheyeMobility.h \
	mobility/SatSGP4Mobility.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/mobility/common/LineSegmentsMobilityBase.h \
	$(INET_PROJ)/src/mobility/common/MobilityBase.h \
	$(INET_PROJ)/src/mobility/common/MovingMobilityBase.h \
	$(INET_PROJ)/src/mobility/contract/IMobility.h \
	$(INET_PROJ)/src/util/FWMath.h \
	$(INET_PROJ)/src/world/radio/ChannelControl.h \
	$(INET_PROJ)/src/world/radio/IChannelControl.h
$O/base/Norad.o: base/Norad.cc \
	base/Norad.h \
	base/WebServiceControl.h \
	libnorad/cEci.h \
	libnorad/cJulian.h \
	libnorad/cNoradBase.h \
	libnorad/cNoradSDP4.h \
	libnorad/cNoradSGP4.h \
	libnorad/cOrbit.h \
	libnorad/cSite.h \
	libnorad/cTLE.h \
	libnorad/cVector.h \
	libnorad/ccoord.h \
	libnorad/globals.h \
	libnorad/libnorad.h
$O/base/UserConfig.o: base/UserConfig.cc \
	base/Norad.h \
	base/UserConfig.h \
	base/WebServiceControl.h \
	libnorad/cEci.h \
	libnorad/cJulian.h \
	libnorad/cNoradBase.h \
	libnorad/cNoradSDP4.h \
	libnorad/cNoradSGP4.h \
	libnorad/cOrbit.h \
	libnorad/cSite.h \
	libnorad/cTLE.h \
	libnorad/cVector.h \
	libnorad/ccoord.h \
	libnorad/globals.h \
	libnorad/libnorad.h \
	mobility/SatSGP4FisheyeMobility.h \
	mobility/SatSGP4Mobility.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/mobility/common/LineSegmentsMobilityBase.h \
	$(INET_PROJ)/src/mobility/common/MobilityBase.h \
	$(INET_PROJ)/src/mobility/common/MovingMobilityBase.h \
	$(INET_PROJ)/src/mobility/contract/IMobility.h \
	$(INET_PROJ)/src/util/FWMath.h \
	$(INET_PROJ)/src/world/radio/ChannelControl.h \
	$(INET_PROJ)/src/world/radio/IChannelControl.h
$O/base/WeatherControl.o: base/WeatherControl.cc \
	base/WeatherControl.h \
	base/WebServiceControl.h
$O/base/WebServiceControl.o: base/WebServiceControl.cc \
	base/WebServiceControl.h
$O/base/observer.o: base/observer.cc \
	base/Calculation.h \
	base/Norad.h \
	base/UserConfig.h \
	base/WeatherControl.h \
	base/WebServiceControl.h \
	base/observer.h \
	libnorad/cEci.h \
	libnorad/cJulian.h \
	libnorad/cNoradBase.h \
	libnorad/cNoradSDP4.h \
	libnorad/cNoradSGP4.h \
	libnorad/cOrbit.h \
	libnorad/cSite.h \
	libnorad/cTLE.h \
	libnorad/cVector.h \
	libnorad/ccoord.h \
	libnorad/globals.h \
	libnorad/libnorad.h \
	mobility/SatSGP4FisheyeMobility.h \
	mobility/SatSGP4Mobility.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/mobility/common/LineSegmentsMobilityBase.h \
	$(INET_PROJ)/src/mobility/common/MobilityBase.h \
	$(INET_PROJ)/src/mobility/common/MovingMobilityBase.h \
	$(INET_PROJ)/src/mobility/contract/IMobility.h \
	$(INET_PROJ)/src/util/FWMath.h \
	$(INET_PROJ)/src/world/radio/ChannelControl.h \
	$(INET_PROJ)/src/world/radio/IChannelControl.h
$O/libnorad/cEci.o: libnorad/cEci.cc \
	libnorad/cEci.h \
	libnorad/cJulian.h \
	libnorad/cVector.h \
	libnorad/ccoord.h \
	libnorad/globals.h
$O/libnorad/cJulian.o: libnorad/cJulian.cc \
	libnorad/cJulian.h \
	libnorad/globals.h
$O/libnorad/cNoradBase.o: libnorad/cNoradBase.cc \
	libnorad/cEci.h \
	libnorad/cJulian.h \
	libnorad/cNoradBase.h \
	libnorad/cOrbit.h \
	libnorad/cTLE.h \
	libnorad/cVector.h \
	libnorad/ccoord.h \
	libnorad/globals.h
$O/libnorad/cNoradSDP4.o: libnorad/cNoradSDP4.cc \
	libnorad/cJulian.h \
	libnorad/cNoradBase.h \
	libnorad/cNoradSDP4.h \
	libnorad/cOrbit.h \
	libnorad/cTLE.h \
	libnorad/cVector.h \
	libnorad/ccoord.h \
	libnorad/globals.h
$O/libnorad/cNoradSGP4.o: libnorad/cNoradSGP4.cc \
	libnorad/cJulian.h \
	libnorad/cNoradBase.h \
	libnorad/cNoradSGP4.h \
	libnorad/cOrbit.h \
	libnorad/cTLE.h \
	libnorad/cVector.h \
	libnorad/ccoord.h \
	libnorad/globals.h
$O/libnorad/cOrbit.o: libnorad/cOrbit.cc \
	libnorad/cEci.h \
	libnorad/cJulian.h \
	libnorad/cNoradBase.h \
	libnorad/cNoradSDP4.h \
	libnorad/cNoradSGP4.h \
	libnorad/cOrbit.h \
	libnorad/cTLE.h \
	libnorad/cVector.h \
	libnorad/ccoord.h \
	libnorad/globals.h
$O/libnorad/cSite.o: libnorad/cSite.cc \
	libnorad/cEci.h \
	libnorad/cJulian.h \
	libnorad/cSite.h \
	libnorad/cVector.h \
	libnorad/ccoord.h \
	libnorad/globals.h
$O/libnorad/cTLE.o: libnorad/cTLE.cc \
	libnorad/cTLE.h \
	libnorad/globals.h
$O/libnorad/cVector.o: libnorad/cVector.cc \
	libnorad/cVector.h
$O/libnorad/ccoord.o: libnorad/ccoord.cc \
	libnorad/ccoord.h \
	libnorad/globals.h
$O/libnorad/globals.o: libnorad/globals.cc \
	libnorad/globals.h
$O/mobility/LUTMotionMobility.o: mobility/LUTMotionMobility.cc \
	mobility/LUTMotionMobility.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/mobility/common/MobilityBase.h \
	$(INET_PROJ)/src/mobility/common/MovingMobilityBase.h \
	$(INET_PROJ)/src/mobility/contract/IMobility.h \
	$(INET_PROJ)/src/util/FWMath.h
$O/mobility/SatSGP4FisheyeMobility.o: mobility/SatSGP4FisheyeMobility.cc \
	base/Norad.h \
	base/WebServiceControl.h \
	libnorad/cEci.h \
	libnorad/cJulian.h \
	libnorad/cNoradBase.h \
	libnorad/cNoradSDP4.h \
	libnorad/cNoradSGP4.h \
	libnorad/cOrbit.h \
	libnorad/cSite.h \
	libnorad/cTLE.h \
	libnorad/cVector.h \
	libnorad/ccoord.h \
	libnorad/globals.h \
	libnorad/libnorad.h \
	mobility/SatSGP4FisheyeMobility.h \
	mobility/SatSGP4Mobility.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/mobility/common/LineSegmentsMobilityBase.h \
	$(INET_PROJ)/src/mobility/common/MobilityBase.h \
	$(INET_PROJ)/src/mobility/common/MovingMobilityBase.h \
	$(INET_PROJ)/src/mobility/contract/IMobility.h \
	$(INET_PROJ)/src/util/FWMath.h
$O/mobility/SatSGP4Mobility.o: mobility/SatSGP4Mobility.cc \
	base/Norad.h \
	base/WebServiceControl.h \
	libnorad/cEci.h \
	libnorad/cJulian.h \
	libnorad/cNoradBase.h \
	libnorad/cNoradSDP4.h \
	libnorad/cNoradSGP4.h \
	libnorad/cOrbit.h \
	libnorad/cSite.h \
	libnorad/cTLE.h \
	libnorad/cVector.h \
	libnorad/ccoord.h \
	libnorad/globals.h \
	libnorad/libnorad.h \
	mobility/SatSGP4Mobility.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/mobility/common/LineSegmentsMobilityBase.h \
	$(INET_PROJ)/src/mobility/common/MobilityBase.h \
	$(INET_PROJ)/src/mobility/common/MovingMobilityBase.h \
	$(INET_PROJ)/src/mobility/contract/IMobility.h \
	$(INET_PROJ)/src/util/FWMath.h

