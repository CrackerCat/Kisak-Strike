#Generated by VPC

NAME=localize
TARGET_PLATFORM=linux64
TARGET_PLATFORM_EXT=_client
VPC_HOST=linux

SRCROOT=..
LINUX_MAKEFILE=1
USE_VALVE_BINDIR=0
# If no configuration is specified, "release" will be used.
CFG ?= release




















################################################################################
#
# CFG=debug
#
################################################################################

ifeq "$(CFG)" "debug"

GCC_ExtraCompilerFlags=
GCC_ExtraCxxCompilerFlags=
GCC_ExtraLinkerFlags=
DisableLinkerDeadCodeElimination=
SymbolVisibility=hidden
TreatWarningsAsErrors=false
OptimizerLevel=-gdwarf-4 -g2 $(OptimizerLevel_CompilerSpecific)
PrecompiledHeaderInclude=
SystemLibraries=
DLL_EXT=_client.so
SYM_EXT=.dbg
DEVTOOLS := ../devtools
MAKEFILE_BASE := $(DEVTOOLS)/makefile_base_posix.mak
COMPILE_DEPENDANT_MAKEFILES := localize_linux64.mak $(MAKEFILE_BASE)
FORCEINCLUDES= 
DEFINES += -DVPC -DCSTRIKE_REL_BUILD=1 -DRAD_TELEMETRY_DISABLED -DDEBUG -D_DEBUG -DGNUC -DPOSIX -DCOMPILER_GCC -DMEMOVERRIDE_MODULE=localize -D_DLL_EXT=_client.so -D_LINUX -DLINUX -DPOSIX -D_POSIX -DDLLNAME=localize -DGL_GLEXT_PROTOTYPES -DDX_TO_GL_ABSTRACTION -DUSE_SDL -DCSTRIKE15 -D_DLL_EXT=_client.so -D_DLL_PREFIX=lib -D_EXTERNAL_DLL_EXT=.so -D_LINUX=1 -D_LINUXSTEAMRT64=1 -D_POSIX=1 -DLINUX=1 -DLINUX64=1 -DLINUXSTEAMRT64=1 -DPOSIX=1 -DPROJECTDIR=/home/lwss/Documents/cstrike15_src/localize -DVPCGAME=csgo -DVPCGAMECAPS=CSGO 
INCLUDEDIRS += ../common ../public ../public/tier0 ../public/tier1 ../thirdparty/SDL2 
CONFTYPE=dll
IMPORTLIBRARY=
OUTPUTFILE=$(OBJ_DIR)/localize_client.so
GAMEOUTPUTFILE=../../game/bin/linux64/localize_client.so

CPPFILES= \
    ../public/tier0/memoverride.cpp \
    localize.cpp \
    ../public/registry.cpp \
    ../public/UnicodeFileHelpers.cpp

unexport CPPFILES

LIBFILES = \
    ../lib/public/linux64/tier1_client.a \
    ../lib/public/linux64/interfaces_client.a \
    ../lib/public/linux64/tier2_client.a \
    -L../lib/public/linux64 -ltier0_client \
    -L../lib/public/linux64 -lvstdlib_client \
    -L../lib/public/linux64 -lsteam_api

unexport LIBFILES

LIBFILENAMES = \
    ../lib/public/linux64/libtier0_client.so \
    ../lib/public/linux64/tier1_client.a \
    ../lib/public/linux64/interfaces_client.a \
    ../lib/public/linux64/libvstdlib_client.so \
    ../lib/public/linux64/tier2_client.a \
    ../lib/public/linux64/libsteam_api.so

unexport LIBFILENAMES

ALL_CUSTOM_BUILD_TOOLS =

unexport ALL_CUSTOM_BUILD_TOOLS

ALL_CUSTOM_BUILD_TOOL_DEPENDENCIES =

unexport ALL_CUSTOM_BUILD_TOOL_DEPENDENCIES

ALL_CUSTOM_BUILD_TOOL_SCRIPTS =

unexport ALL_CUSTOM_BUILD_TOOL_SCRIPTS

ALL_CUSTOM_BUILD_TOOL_OUTPUTS =

unexport ALL_CUSTOM_BUILD_TOOL_OUTPUTS

ALL_DEPGEN_FILES = \
    $(OBJ_DIR)/memoverride.P \
    $(OBJ_DIR)/localize.P \
    $(OBJ_DIR)/registry.P \
    $(OBJ_DIR)/UnicodeFileHelpers.P

unexport ALL_DEPGEN_FILES


#
# Include the base makefile now.
#
include $(MAKEFILE_BASE)


#
# Create sentinel directories
#
$(OBJ_DIR)/_vpc_generated_scripts/custom_build_tools/_vpc_create_dirs: localize_linux64.mak | $(OBJ_DIR)/_create_dir
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) create custom build tools dir start
	$(QUIET_PREFIX) $(MKDIR) -p $(OBJ_DIR)/_vpc_generated_scripts/custom_build_tools/locks $(QUIET_ECHO_POSTFIX)
	$(QUIET_PREFIX) $(MKDIR) -p $(OBJ_DIR)/_vpc_generated_scripts/custom_build_tools/ranthisbuild $(QUIET_ECHO_POSTFIX)
	$(QUIET_PREFIX) $(MKDIR) -p $(OBJ_DIR)/_vpc_generated_scripts/custom_build_tools/sentinels $(QUIET_ECHO_POSTFIX)
	$(QUIET_PREFIX) $(TOUCH) $(OBJ_DIR)/_vpc_generated_scripts/custom_build_tools/_vpc_create_dirs


#
# include all the depgen .P files which will include dependency information.
#
include $(wildcard $(OBJ_DIR)/memoverride.P)
include $(wildcard $(OBJ_DIR)/localize.P)
include $(wildcard $(OBJ_DIR)/registry.P)
include $(wildcard $(OBJ_DIR)/UnicodeFileHelpers.P)


#
# Compare/cache a string of compile settings to see if we need to recompile .o's
#
$(eval $(call DETECT_STRING_CHANGE_BETWEEN_BUILDS,COMPILE_O_GLOBAL_SETTINGS,$$(call COMPILE_O_SETTINGS,$$(CFG_CPPFLAGS))))


#
# Compile rules
#
$(OBJ_DIR)/memoverride.o: ../public/tier0/memoverride.cpp $(call DETECT_STRING_CHANGE_BETWEEN_BUILDS_TIMESTAMP_FILE,COMPILE_O_GLOBAL_SETTINGS) | _precompile_steps
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile start for file $(OBJ_DIR)/memoverride.o
	$(QUIET_PREFIX) $(call SPEW_UPDATED_DEPENDENCIES)
	$(QUIET_PREFIX) $(call RUN_PREBUILD_EVENT_ONCE)
	$(PRE_COMPILE_FILE)
	$(QUIET_PREFIX) $(MKDIR) -p "$(dir $@)"
	$(call COMPILE_FILE, $(CFG_CPPFLAGS)) $(POST_COMPILE_FILE)
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile end for file $(OBJ_DIR)/memoverride.o

$(OBJ_DIR)/localize.o: localize.cpp $(call DETECT_STRING_CHANGE_BETWEEN_BUILDS_TIMESTAMP_FILE,COMPILE_O_GLOBAL_SETTINGS) | _precompile_steps
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile start for file $(OBJ_DIR)/localize.o
	$(QUIET_PREFIX) $(call SPEW_UPDATED_DEPENDENCIES)
	$(QUIET_PREFIX) $(call RUN_PREBUILD_EVENT_ONCE)
	$(PRE_COMPILE_FILE)
	$(QUIET_PREFIX) $(MKDIR) -p "$(dir $@)"
	$(call COMPILE_FILE, $(CFG_CPPFLAGS)) $(POST_COMPILE_FILE)
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile end for file $(OBJ_DIR)/localize.o

$(OBJ_DIR)/registry.o: ../public/registry.cpp $(call DETECT_STRING_CHANGE_BETWEEN_BUILDS_TIMESTAMP_FILE,COMPILE_O_GLOBAL_SETTINGS) | _precompile_steps
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile start for file $(OBJ_DIR)/registry.o
	$(QUIET_PREFIX) $(call SPEW_UPDATED_DEPENDENCIES)
	$(QUIET_PREFIX) $(call RUN_PREBUILD_EVENT_ONCE)
	$(PRE_COMPILE_FILE)
	$(QUIET_PREFIX) $(MKDIR) -p "$(dir $@)"
	$(call COMPILE_FILE, $(CFG_CPPFLAGS)) $(POST_COMPILE_FILE)
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile end for file $(OBJ_DIR)/registry.o

$(OBJ_DIR)/UnicodeFileHelpers.o: ../public/UnicodeFileHelpers.cpp $(call DETECT_STRING_CHANGE_BETWEEN_BUILDS_TIMESTAMP_FILE,COMPILE_O_GLOBAL_SETTINGS) | _precompile_steps
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile start for file $(OBJ_DIR)/UnicodeFileHelpers.o
	$(QUIET_PREFIX) $(call SPEW_UPDATED_DEPENDENCIES)
	$(QUIET_PREFIX) $(call RUN_PREBUILD_EVENT_ONCE)
	$(PRE_COMPILE_FILE)
	$(QUIET_PREFIX) $(MKDIR) -p "$(dir $@)"
	$(call COMPILE_FILE, $(CFG_CPPFLAGS)) $(POST_COMPILE_FILE)
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile end for file $(OBJ_DIR)/UnicodeFileHelpers.o

endif # (CFG=debug)




















################################################################################
#
# CFG=release
#
################################################################################

ifeq "$(CFG)" "release"

GCC_ExtraCompilerFlags=
GCC_ExtraCxxCompilerFlags=
GCC_ExtraLinkerFlags=
DisableLinkerDeadCodeElimination=
SymbolVisibility=hidden
TreatWarningsAsErrors=false
OptimizerLevel=-gdwarf-4 -g2 $(OptimizerLevel_CompilerSpecific)
PrecompiledHeaderInclude=
SystemLibraries=
DLL_EXT=_client.so
SYM_EXT=.dbg
DEVTOOLS := ../devtools
MAKEFILE_BASE := $(DEVTOOLS)/makefile_base_posix.mak
COMPILE_DEPENDANT_MAKEFILES := localize_linux64.mak $(MAKEFILE_BASE)
FORCEINCLUDES= 
DEFINES += -DVPC -DCSTRIKE_REL_BUILD=1 -DRAD_TELEMETRY_DISABLED -DNDEBUG -D_GLIBCXX_USE_CXX11_ABI=0 -DGNUC -DPOSIX -DCOMPILER_GCC -DMEMOVERRIDE_MODULE=localize -D_DLL_EXT=_client.so -D_LINUX -DLINUX -DPOSIX -D_POSIX -DDLLNAME=localize -DGL_GLEXT_PROTOTYPES -DDX_TO_GL_ABSTRACTION -DUSE_SDL -DCSTRIKE15 -D_DLL_EXT=_client.so -D_DLL_PREFIX=lib -D_EXTERNAL_DLL_EXT=.so -D_LINUX=1 -D_LINUXSTEAMRT64=1 -D_POSIX=1 -DLINUX=1 -DLINUX64=1 -DLINUXSTEAMRT64=1 -DPOSIX=1 -DPROJECTDIR=/home/lwss/Documents/cstrike15_src/localize -DVPCGAME=csgo -DVPCGAMECAPS=CSGO 
INCLUDEDIRS += ../common ../public ../public/tier0 ../public/tier1 ../thirdparty/SDL2 
CONFTYPE=dll
IMPORTLIBRARY=
OUTPUTFILE=$(OBJ_DIR)/localize_client.so
GAMEOUTPUTFILE=../../game/bin/linux64/localize_client.so

CPPFILES= \
    ../public/tier0/memoverride.cpp \
    localize.cpp \
    ../public/registry.cpp \
    ../public/UnicodeFileHelpers.cpp

unexport CPPFILES

LIBFILES = \
    ../lib/public/linux64/tier1_client.a \
    ../lib/public/linux64/interfaces_client.a \
    ../lib/public/linux64/tier2_client.a \
    -L../lib/public/linux64 -ltier0_client \
    -L../lib/public/linux64 -lvstdlib_client \
    -L../lib/public/linux64 -lsteam_api

unexport LIBFILES

LIBFILENAMES = \
    ../lib/public/linux64/libtier0_client.so \
    ../lib/public/linux64/tier1_client.a \
    ../lib/public/linux64/interfaces_client.a \
    ../lib/public/linux64/libvstdlib_client.so \
    ../lib/public/linux64/tier2_client.a \
    ../lib/public/linux64/libsteam_api.so

unexport LIBFILENAMES

ALL_CUSTOM_BUILD_TOOLS =

unexport ALL_CUSTOM_BUILD_TOOLS

ALL_CUSTOM_BUILD_TOOL_DEPENDENCIES =

unexport ALL_CUSTOM_BUILD_TOOL_DEPENDENCIES

ALL_CUSTOM_BUILD_TOOL_SCRIPTS =

unexport ALL_CUSTOM_BUILD_TOOL_SCRIPTS

ALL_CUSTOM_BUILD_TOOL_OUTPUTS =

unexport ALL_CUSTOM_BUILD_TOOL_OUTPUTS

ALL_DEPGEN_FILES = \
    $(OBJ_DIR)/memoverride.P \
    $(OBJ_DIR)/localize.P \
    $(OBJ_DIR)/registry.P \
    $(OBJ_DIR)/UnicodeFileHelpers.P

unexport ALL_DEPGEN_FILES


#
# Include the base makefile now.
#
include $(MAKEFILE_BASE)


#
# Create sentinel directories
#
$(OBJ_DIR)/_vpc_generated_scripts/custom_build_tools/_vpc_create_dirs: localize_linux64.mak | $(OBJ_DIR)/_create_dir
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) create custom build tools dir start
	$(QUIET_PREFIX) $(MKDIR) -p $(OBJ_DIR)/_vpc_generated_scripts/custom_build_tools/locks $(QUIET_ECHO_POSTFIX)
	$(QUIET_PREFIX) $(MKDIR) -p $(OBJ_DIR)/_vpc_generated_scripts/custom_build_tools/ranthisbuild $(QUIET_ECHO_POSTFIX)
	$(QUIET_PREFIX) $(MKDIR) -p $(OBJ_DIR)/_vpc_generated_scripts/custom_build_tools/sentinels $(QUIET_ECHO_POSTFIX)
	$(QUIET_PREFIX) $(TOUCH) $(OBJ_DIR)/_vpc_generated_scripts/custom_build_tools/_vpc_create_dirs


#
# include all the depgen .P files which will include dependency information.
#
include $(wildcard $(OBJ_DIR)/memoverride.P)
include $(wildcard $(OBJ_DIR)/localize.P)
include $(wildcard $(OBJ_DIR)/registry.P)
include $(wildcard $(OBJ_DIR)/UnicodeFileHelpers.P)


#
# Compare/cache a string of compile settings to see if we need to recompile .o's
#
$(eval $(call DETECT_STRING_CHANGE_BETWEEN_BUILDS,COMPILE_O_GLOBAL_SETTINGS,$$(call COMPILE_O_SETTINGS,$$(CFG_CPPFLAGS))))


#
# Compile rules
#
$(OBJ_DIR)/memoverride.o: ../public/tier0/memoverride.cpp $(call DETECT_STRING_CHANGE_BETWEEN_BUILDS_TIMESTAMP_FILE,COMPILE_O_GLOBAL_SETTINGS) | _precompile_steps
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile start for file $(OBJ_DIR)/memoverride.o
	$(QUIET_PREFIX) $(call SPEW_UPDATED_DEPENDENCIES)
	$(QUIET_PREFIX) $(call RUN_PREBUILD_EVENT_ONCE)
	$(PRE_COMPILE_FILE)
	$(QUIET_PREFIX) $(MKDIR) -p "$(dir $@)"
	$(call COMPILE_FILE, $(CFG_CPPFLAGS)) $(POST_COMPILE_FILE)
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile end for file $(OBJ_DIR)/memoverride.o

$(OBJ_DIR)/localize.o: localize.cpp $(call DETECT_STRING_CHANGE_BETWEEN_BUILDS_TIMESTAMP_FILE,COMPILE_O_GLOBAL_SETTINGS) | _precompile_steps
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile start for file $(OBJ_DIR)/localize.o
	$(QUIET_PREFIX) $(call SPEW_UPDATED_DEPENDENCIES)
	$(QUIET_PREFIX) $(call RUN_PREBUILD_EVENT_ONCE)
	$(PRE_COMPILE_FILE)
	$(QUIET_PREFIX) $(MKDIR) -p "$(dir $@)"
	$(call COMPILE_FILE, $(CFG_CPPFLAGS)) $(POST_COMPILE_FILE)
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile end for file $(OBJ_DIR)/localize.o

$(OBJ_DIR)/registry.o: ../public/registry.cpp $(call DETECT_STRING_CHANGE_BETWEEN_BUILDS_TIMESTAMP_FILE,COMPILE_O_GLOBAL_SETTINGS) | _precompile_steps
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile start for file $(OBJ_DIR)/registry.o
	$(QUIET_PREFIX) $(call SPEW_UPDATED_DEPENDENCIES)
	$(QUIET_PREFIX) $(call RUN_PREBUILD_EVENT_ONCE)
	$(PRE_COMPILE_FILE)
	$(QUIET_PREFIX) $(MKDIR) -p "$(dir $@)"
	$(call COMPILE_FILE, $(CFG_CPPFLAGS)) $(POST_COMPILE_FILE)
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile end for file $(OBJ_DIR)/registry.o

$(OBJ_DIR)/UnicodeFileHelpers.o: ../public/UnicodeFileHelpers.cpp $(call DETECT_STRING_CHANGE_BETWEEN_BUILDS_TIMESTAMP_FILE,COMPILE_O_GLOBAL_SETTINGS) | _precompile_steps
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile start for file $(OBJ_DIR)/UnicodeFileHelpers.o
	$(QUIET_PREFIX) $(call SPEW_UPDATED_DEPENDENCIES)
	$(QUIET_PREFIX) $(call RUN_PREBUILD_EVENT_ONCE)
	$(PRE_COMPILE_FILE)
	$(QUIET_PREFIX) $(MKDIR) -p "$(dir $@)"
	$(call COMPILE_FILE, $(CFG_CPPFLAGS)) $(POST_COMPILE_FILE)
	$(QUIET_PREFIX) $(BUILD_DEBUG_ECHO) COMPILE_FILE compile end for file $(OBJ_DIR)/UnicodeFileHelpers.o

endif # (CFG=release)
