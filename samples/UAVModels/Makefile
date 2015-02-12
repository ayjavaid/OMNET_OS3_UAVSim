#
# OMNeT++/OMNEST Makefile for libUAVModels
#
# This file was generated with the command:
#  opp_makemake -f --deep --make-so -O out -L../GPSApp/out/$$\(CONFIGNAME\)/src -L../CNI_OS3/out/$$\(CONFIGNAME\)/src -L../CNI_OS3/out/$$\(CONFIGNAME\) -L../inet/out/$$\(CONFIGNAME\)/src -L../GPSAttackApp/out/$$\(CONFIGNAME\)/src -lGPSApp -lCNI_OS3 -lCNI_OS3 -linet -lGPSAttackApp -DINET_IMPORT -KGPSAPP_PROJ=../GPSApp -KCNI_OS3_PROJ=../CNI_OS3 -KINET_PROJ=../inet -KGPSATTACKAPP_PROJ=../GPSAttackApp
#

# Name of target to be created (-o option)
TARGET = libUAVModels$(SHARED_LIB_SUFFIX)

# C++ include paths (with -I)
INCLUDE_PATH = -I. -IDebug -IDebug/src -Igcc-debug -Igcc-debug/src

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../GPSApp/out/$(CONFIGNAME)/src -L../CNI_OS3/out/$(CONFIGNAME)/src -L../CNI_OS3/out/$(CONFIGNAME) -L../inet/out/$(CONFIGNAME)/src -L../GPSAttackApp/out/$(CONFIGNAME)/src  -lGPSApp -lCNI_OS3 -lCNI_OS3 -linet -lGPSAttackApp
LIBS += -Wl,-rpath,`abspath ../GPSApp/out/$(CONFIGNAME)/src` -Wl,-rpath,`abspath ../CNI_OS3/out/$(CONFIGNAME)/src` -Wl,-rpath,`abspath ../CNI_OS3/out/$(CONFIGNAME)` -Wl,-rpath,`abspath ../inet/out/$(CONFIGNAME)/src` -Wl,-rpath,`abspath ../GPSAttackApp/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/NAV.o \
    $O/AdvUAVHost.o \
    $O/Telemetry.o \
    $O/DataLog.o \
    $O/DataAcq.o \
    $O/AltHeadRefSys.o \
    $O/UAVControl.o

# Message files
MSGFILES =

# Other makefile variables (-K)
GPSAPP_PROJ=../GPSApp
CNI_OS3_PROJ=../CNI_OS3
INET_PROJ=../inet
GPSATTACKAPP_PROJ=../GPSAttackApp

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
	$(Q)-rm -f UAVModels UAVModels.exe libUAVModels.so libUAVModels.a libUAVModels.dll libUAVModels.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f Debug/*_m.cc Debug/*_m.h
	$(Q)-rm -f Debug/src/*_m.cc Debug/src/*_m.h
	$(Q)-rm -f gcc-debug/*_m.cc gcc-debug/*_m.h
	$(Q)-rm -f gcc-debug/src/*_m.cc gcc-debug/src/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc Debug/*.cc Debug/src/*.cc gcc-debug/*.cc gcc-debug/src/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/AdvUAVHost.o: AdvUAVHost.cc
$O/AltHeadRefSys.o: AltHeadRefSys.cc
$O/DataAcq.o: DataAcq.cc
$O/DataLog.o: DataLog.cc
$O/NAV.o: NAV.cc
$O/Telemetry.o: Telemetry.cc
$O/UAVControl.o: UAVControl.cc

