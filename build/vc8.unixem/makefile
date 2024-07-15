############################################################################
# File:	makefile
#
# Purpose:	Generated makefile for the Pantheios project,
#           for the Visual C++ 8.0 (UNIXem) compiler
#           on the UNIX platform
#
# Created:	15th February 2005
# Updated:	12th February 2021
#
############################################################################


############################################################################
# instructions (in no particular order)
#
# * to build without Base-64 support (which requires b64 source files),
#   make with the symbol PANTHEIOS_NO_B64 defined

############################################################################
# environment check
#

!ifndef STLSOFT
!error STLSOFT must be defined
!endif # !STLSOFT

!ifndef PTHREADS_WIN32
!error PTHREADS_WIN32 must be defined
!endif # !PTHREADS_WIN32

!ifndef UNIXEM
!error UNIXEM must be defined
!endif # !UNIXEM

############################################################################
# symbols

########################################
# project & compiler version

COMP_TAG			=	vc8
ARCH_TAG            =
OS_TAG				=   .unix
PROJ_TAG			=	pantheios
PROJ_VER_MAJOR		=	1
PROJ_TAG_VER		=	$(PROJ_TAG).$(PROJ_VER_MAJOR)
COMP_ARCH_OS_TAG	=	$(COMP_TAG)$(OS_TAG)$(ARCH_TAG)

!ifndef PANTHEIOS_NO_B64

B64_VER_MAJOR		=   1
B64_TAG_VER			=   b64.$(B64_VER_MAJOR)
!endif # !PANTHEIOS_NO_B64

SHWILD_VER_MAJOR    =   0
SHWILD_TAG_VER      =   shwild.$(SHWILD_VER_MAJOR)

XCONTRACT_VER_MAJOR =   0
XCONTRACT_TAG_VER   =   xcontract.$(XCONTRACT_VER_MAJOR)

XTESTS_VER_MAJOR    =   0
XTESTS_TAG_VER      =   xtests.$(XTESTS_VER_MAJOR)

UNIXEM_VER_MAJOR	=	1
UNIXEM_TAG_VER      =   unixem.$(UNIXEM_VER_MAJOR)

PROJ_MAKEFILE_NAME  =   makefile

NOTHING				=

########################################
# testing verbosity

!ifndef TEST_VERBOSITY
TEST_VERBOSITY      =   2
!endif # !TEST_VERBOSITY

########################################
# directories

PROJ_BASE_DIR			=	..\..
PROJ_BIN_DIR			=	$(PROJ_BASE_DIR)\bin
PROJ_INCLUDE_DIR		=	$(PROJ_BASE_DIR)\include
PROJ_LIB_DIR			=	$(PROJ_BASE_DIR)\lib
PROJ_OBJ_DIR			=	.
PROJ_SRC_DIR			=	$(PROJ_BASE_DIR)\src
PROJ_BACKENDS_DIR		=	$(PROJ_BASE_DIR)\backends
PROJ_FRONTENDS_DIR		=	$(PROJ_BASE_DIR)\frontends
PROJ_EXAMPLES_DIR		=	$(PROJ_BASE_DIR)\examples
PROJ_SAMPLES_DIR        =   $(PROJ_BASE_DIR)\samples
PROJ_TEST_ROOT_DIR		=	$(PROJ_BASE_DIR)\test
PROJ_TEST_COMPONENT_DIR	=	$(PROJ_TEST_ROOT_DIR)\component
PROJ_TEST_PERFORMANCE_DIR	=	$(PROJ_TEST_ROOT_DIR)\performance
PROJ_TEST_SCRATCH_DIR	=	$(PROJ_TEST_ROOT_DIR)\scratch
PROJ_TEST_UNIT_DIR		=	$(PROJ_TEST_ROOT_DIR)\unit

!ifndef PANTHEIOS_NO_B64

B64_PROJ_INCLUDE		=
!ifdef PANTHEIOS_B64_BASE_DIR
B64_INCLUDE_DIR			=   $(PANTHEIOS_B64_BASE_DIR)\include
B64_SRC_DIR				=   $(PANTHEIOS_B64_BASE_DIR)\src
B64_PROJ_INCLUDE		=	-I$(B64_INCLUDE_DIR)
!else
B64_INCLUDE_DIR			=   $(PROJ_BASE_DIR)\include
B64_SRC_DIR				=   $(PROJ_SRC_DIR)\b64
!endif # !PANTHEIOS_B64_BASE_DIR
!endif # !PANTHEIOS_NO_B64

SHWILD_PROJ_INCLUDE		=
!ifdef PANTHEIOS_SHWILD_BASE_DIR
SHWILD_INCLUDE_DIR		=   $(PANTHEIOS_SHWILD_BASE_DIR)\include
SHWILD_SRC_DIR			=   $(PANTHEIOS_SHWILD_BASE_DIR)\src
SHWILD_PROJ_INCLUDE		=	-I$(SHWILD_INCLUDE_DIR)
!else
SHWILD_INCLUDE_DIR		=   $(PROJ_BASE_DIR)\include
SHWILD_SRC_DIR			=   $(PROJ_SRC_DIR)\shwild
!endif # !PANTHEIOS_SHWILD_BASE_DIR

XCONTRACT_PROJ_INCLUDE	=
!ifdef PANTHEIOS_XCONTRACT_BASE_DIR
XCONTRACT_INCLUDE_DIR	=   $(PANTHEIOS_XCONTRACT_BASE_DIR)\include
XCONTRACT_SRC_DIR		=   $(PANTHEIOS_XCONTRACT_BASE_DIR)\src
XCONTRACT_PROJ_INCLUDE	=	-I$(XCONTRACT_INCLUDE_DIR)
!else
XCONTRACT_INCLUDE_DIR	=   $(PROJ_BASE_DIR)\include
XCONTRACT_SRC_DIR		=   $(PROJ_SRC_DIR)\xcontract
!endif # !PANTHEIOS_XCONTRACT_BASE_DIR

XTESTS_PROJ_INCLUDE		=
!ifdef PANTHEIOS_XTESTS_BASE_DIR
XTESTS_INCLUDE_DIR		=   $(PANTHEIOS_XTESTS_BASE_DIR)\include
XTESTS_SRC_DIR			=   $(PANTHEIOS_XTESTS_BASE_DIR)\src
XTESTS_PROJ_INCLUDE		=	-I$(XTESTS_INCLUDE_DIR)
!else
XTESTS_INCLUDE_DIR		=   $(PROJ_BASE_DIR)\include
XTESTS_SRC_DIR			=   $(PROJ_SRC_DIR)\xtests
!endif # !PANTHEIOS_XTESTS_BASE_DIR

STLSOFT_PROJ_INCLUDE	=	-I"$(STLSOFT)\include"

########################################
# tools

CC		=	cl
CPPC	=	cl
AR		=	lib
LD		=	link
RM		=	del /f
CP		=	copy
RC		=	rc

########################################
# include directory symbols

INCLUDES_LEADER	=

PROJ_INCLUDE		=	-I$(PROJ_INCLUDE_DIR)

ENV_INCLUDES	=

COMMON_INCLUDES	=	-I$(SYNESIS_DEV)/include -I$(SYNESIS_DEV)/libraries/include

CC_INCLUDES_BASE=\
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(B64_PROJ_INCLUDE)\
 $(SHWILD_PROJ_INCLUDE)\
 $(XCONTRACT_PROJ_INCLUDE)\
 $(XTESTS_PROJ_INCLUDE)\
 $(STLSOFT_PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 -I"$(PTHREADS_WIN32)\include"\
 -I"$(UNIXEM)\include"\
 $(ENV_INCLUDES)\
 \

CC_INCLUDES=\
 $(CC_INCLUDES_BASE)\
 \


!ifdef ACE
CC_INCLUDES_ACE=\
 $(CC_INCLUDES_BASE)\
 -I"$(ACE)"\
 \

!endif # ACE

CPPC_INCLUDES_BASE=\
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(B64_PROJ_INCLUDE)\
 $(SHWILD_PROJ_INCLUDE)\
 $(XCONTRACT_PROJ_INCLUDE)\
 $(XTESTS_PROJ_INCLUDE)\
 $(STLSOFT_PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 -I"$(PTHREADS_WIN32)\include"\
 -I"$(UNIXEM)\include"\
 $(ENV_INCLUDES)\
 \

CPPC_INCLUDES=\
 $(CPPC_INCLUDES_BASE)\
 \

!ifdef ACE
CPPC_INCLUDES_ACE=\
 $(CPPC_INCLUDES_BASE)\
 -I"$(ACE)"\
 \

!endif # ACE


# b64

!ifndef PANTHEIOS_NO_B64

CC_B64_INCLUDES_BASE =\
 $(CC_INCLUDES_BASE)\
 \

CC_B64_INCLUDES_UX_MT_D =\
 $(CC_B64_INCLUDES_BASE)\
 \

CC_B64_INCLUDES_UX_MT_R =\
 $(CC_B64_INCLUDES_BASE)\
 \


CPPC_B64_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_B64_INCLUDES_UX_MT_D =\
 $(CPPC_B64_INCLUDES_BASE)\
 \

CPPC_B64_INCLUDES_UX_MT_R =\
 $(CPPC_B64_INCLUDES_BASE)\
 \

!endif # !PANTHEIOS_NO_B64

# shwild

CC_SHWILD_INCLUDES_BASE =\
 $(CC_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_UX_MT_D =\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_UX_MT_R =\
 $(CC_SHWILD_INCLUDES_BASE)\
 \


CPPC_SHWILD_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_UX_MT_D =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_UX_MT_R =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \


# xContract

CC_XCONTRACT_INCLUDES_BASE =\
 $(CC_INCLUDES_BASE)\
 \

CPPC_XCONTRACT_INCLUDES_UX_MT_D =\
 $(CPPC_XCONTRACT_INCLUDES_BASE)\
 \

CPPC_XCONTRACT_INCLUDES_UX_MT_R =\
 $(CPPC_XCONTRACT_INCLUDES_BASE)\
 \


CPPC_XCONTRACT_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CC_XCONTRACT_INCLUDES_UX_MT_D =\
 $(CC_XCONTRACT_INCLUDES_BASE)\
 \

CC_XCONTRACT_INCLUDES_UX_MT_R =\
 $(CC_XCONTRACT_INCLUDES_BASE)\
 \


# xTests

CC_XTESTS_INCLUDES_BASE =\
 $(CC_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_UX_MT_D =\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_UX_MT_R =\
 $(CC_XTESTS_INCLUDES_BASE)\
 \


CPPC_XTESTS_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_UX_MT_D =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_UX_MT_R =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \




########################################
# library directory symbols

LIBS_LEADER		=

# lib paths

ENV_LIBPATHS		=
COMMON_LIBPATHS			=	-libpath:$(SYNESIS_DEV)/lib



LIBPATHS=\
 $(LIBS_LEADER)\
 -libpath:"$(PTHREADS_WIN32)\lib"\
 -libpath:"$(UNIXEM)\lib"\
 $(COMMON_LIBPATHS)\
 $(ENV_LIBPATHS)\
 \


########################################
# library names

TARGET_LIB_UX_MT_D	= pthreadVC.lib advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib version.lib wininet.lib ws2_32.lib
TARGET_LIB_UX_MT_R	= pthreadVC.lib advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib version.lib wininet.lib ws2_32.lib

########################################
# #defines
#
# - OS
# -

OS_DEFS				=	-DUNIX

COMMON_DEFS_		= \
 -DB64_NO_USE_XCONTRACT\
 -DB64_NO_USE_XCOVER\
 -DSHWILD_QUALITY_NO_USE_XCONTRACT\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 \

!ifdef PANTHEIOS_NO_B64

COMMON_DEFS_NO_b64	=	-DPANTHEIOS_NO_B64
!else

COMMON_DEFS_NO_b64	=
!endif # !PANTHEIOS_NO_B64

COMMON_DEFS			= \
 $(COMMON_DEFS_)\
 $(COMMON_DEFS_NO_b64)\
 \

CUSTOM_DEFS			=

CC_CUSTOM_DEFS		=	$(CUSTOM_DEFS)

CPPC_CUSTOM_DEFS	=	$(CUSTOM_DEFS)

CC_DEFS =\
 $(COMMON_DEFS)\
 $(OS_DEFS)\
 $(CC_CUSTOM_DEFS)\
 \

CPPC_DEFS =\
 $(COMMON_DEFS)\
 $(OS_DEFS)\
 $(CPPC_CUSTOM_DEFS)\
 \


# CC flags

CC_F_NOLOGO			=	-nologo
CC_F_COMPILE_ONLY		=	-c
CC_F_WARNING_MAX		=	-W4
CC_F_WARNING_ERR		=	-WX
CC_F_WARNINGS_LIMIT		=
CC_F_MINIMUM_SIZE		=	-O1
#CC_F_MAXIMUM_SPEED		=	-O2
CC_APP_F_WARNING_MAX	=	$(CC_F_WARNING_MAX)
CC_APP_F_WARNING_ERR	=	$(CC_F_WARNING_ERR)
CC_F_ADDITIONAL			=

# CPPC flags

CPPC_F_NOLOGO			=	-nologo
CPPC_F_COMPILE_ONLY	=	-c
CPPC_F_WARNING_MAX		=	-W4 -wd4996
CPPC_F_WARNING_ERR		=	-WX
CPPC_F_EXCEPTIONS_ON	=	-EHsc
CPPC_F_EXCEPTIONS_OFF	=	-wd4530
CPPC_F_EXCEPTIONS		=
CPPC_F_RTTI_ON			=	-GR
CPPC_F_RTTI_OFF		=	-GR-
CPPC_F_RTTI				=
CPPC_F_WARNINGS_LIMIT	=
CPPC_F_MINIMUM_SIZE	=	-O1
CPPC_F_MAXIMUM_SPEED	=	-O2
CPPC_F_OPTIMISED		=	$(CPPC_F_MAXIMUM_SPEED)
CPPC_APP_F_WARNING_MAX	=	$(CPPC_F_WARNING_MAX)
CPPC_APP_F_WARNING_ERR	=	$(CPPC_F_WARNING_ERR)
CPPC_F_ADDITIONAL		=



CC_TOOL_FLAGS		=

CPPC_TOOL_FLAGS	=



CC_FLAGS=\
 $(CC_TOOL_FLAGS)\
 $(CC_F_ADDITIONAL)\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 $(CC_F_WARNINGS_LIMIT)\
 $(CC_F_MINIMUM_SIZE)\
 \

CPPC_FLAGS=\
 $(CPPC_TOOL_FLAGS)\
 $(CPPC_F_ADDITIONAL)\
 $(CPPC_F_NOLOGO)\
 $(CPPC_F_COMPILE_ONLY)\
 $(CPPC_F_WARNING_MAX)\
 $(CPPC_F_WARNING_ERR)\
 $(CPPC_F_WARNINGS_LIMIT)\
 $(CPPC_F_EXCEPTIONS)\
 $(CPPC_F_RTTI)\
 \


# - App (base)
CC_APP_FLAGS=\
 $(CC_TOOL_FLAGS)\
 $(CC_F_ADDITIONAL)\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_APP_F_WARNING_MAX)\
 $(CC_APP_F_WARNING_ERR)\
 $(CC_F_WARNINGS_LIMIT)\
 $(CC_F_MINIMUM_SIZE)\
 \

CPPC_APP_FLAGS=\
 $(CPPC_TOOL_FLAGS)\
 $(CPPC_F_ADDITIONAL)\
 $(CPPC_F_NOLOGO)\
 $(CPPC_F_COMPILE_ONLY)\
 $(CPPC_APP_F_WARNING_MAX)\
 $(CPPC_APP_F_WARNING_ERR)\
 $(CPPC_F_WARNINGS_LIMIT)\
 $(CPPC_F_EXCEPTIONS)\
 $(CPPC_F_RTTI)\
 \


# - b64

!ifndef PANTHEIOS_NO_B64

CC_B64_FLAGS = $(CC_APP_FLAGS)

CPPC_B64_FLAGS = $(CPPC_APP_FLAGS)
!endif # !PANTHEIOS_NO_B64


# - shwild
CC_SHWILD_FLAGS = $(CC_APP_FLAGS)

CPPC_SHWILD_FLAGS = $(CPPC_APP_FLAGS)


# - xContract
CC_XCONTRACT_FLAGS = $(CC_APP_FLAGS)

CPPC_XCONTRACT_FLAGS = $(CPPC_APP_FLAGS)


# - xTests
CC_XTESTS_FLAGS = $(CC_APP_FLAGS)

CPPC_XTESTS_FLAGS = $(CPPC_APP_FLAGS)


# - Example
CC_EXAMPLE_FLAGS = $(CC_APP_FLAGS)

CPPC_EXAMPLE_FLAGS = $(CPPC_APP_FLAGS)


# - Test (Component)
CC_TEST_COMPONENT_FLAGS = $(CC_APP_FLAGS)

CPPC_TEST_COMPONENT_FLAGS = $(CPPC_APP_FLAGS)


# - Test (Scratch)
CC_TEST_SCRATCH_FLAGS = $(CC_APP_FLAGS)

CPPC_TEST_SCRATCH_FLAGS = $(CPPC_APP_FLAGS)


# - Test (Unit)
CC_TEST_UNIT_FLAGS = $(CC_APP_FLAGS)

CPPC_TEST_UNIT_FLAGS = $(CPPC_APP_FLAGS)


!ifdef ACE
# ACE additional arguments
CPPC_ACE_ADDITIONAL_ARGS	=

!endif # ACE
########################################
# arguments (= flags + defines + includes)

# - Libs
CC_LIB_ARGS_UX_MT_D			=	$(CC_FLAGS) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS) -DPANTHEIOS_NO_AUTO_INIT
CC_LIB_ARGS_UX_MT_R			=	$(CC_FLAGS) -MTd -DNDEBUG $(CC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS) -DPANTHEIOS_NO_AUTO_INIT

CPPC_LIB_ARGS_UX_MT_D		=	$(CPPC_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS) -DPANTHEIOS_NO_AUTO_INIT
CPPC_LIB_ARGS_UX_MT_R		=	$(CPPC_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS) -DPANTHEIOS_NO_AUTO_INIT


# - b64
!ifndef PANTHEIOS_NO_B64

CC_B64_ARGS_UX_MT_D			=	$(CC_B64_FLAGS) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)
CC_B64_ARGS_UX_MT_R			=	$(CC_B64_FLAGS) -MTd -DNDEBUG $(CC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)

CPPC_B64_ARGS_UX_MT_D		=	$(CPPC_B64_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)
CPPC_B64_ARGS_UX_MT_R		=	$(CPPC_B64_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)
!endif # !PANTHEIOS_NO_B64


# - shwild
CC_SHWILD_ARGS_UX_MT_D		=	$(CC_SHWILD_FLAGS) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)
CC_SHWILD_ARGS_UX_MT_R		=	$(CC_SHWILD_FLAGS) -MTd -DNDEBUG $(CC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)

CPPC_SHWILD_ARGS_UX_MT_D		=	$(CPPC_SHWILD_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)
CPPC_SHWILD_ARGS_UX_MT_R		=	$(CPPC_SHWILD_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)


# - xContract
CC_XCONTRACT_ARGS_UX_MT_D	=	$(CC_XCONTRACT_FLAGS) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)
CC_XCONTRACT_ARGS_UX_MT_R	=	$(CC_XCONTRACT_FLAGS) -MTd -DNDEBUG $(CC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)

CPPC_XCONTRACT_ARGS_UX_MT_D  =	$(CPPC_XCONTRACT_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)
CPPC_XCONTRACT_ARGS_UX_MT_R  =	$(CPPC_XCONTRACT_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)


# - xTests
CC_XTESTS_ARGS_UX_MT_D		=	$(CC_XTESTS_FLAGS) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)
CC_XTESTS_ARGS_UX_MT_R		=	$(CC_XTESTS_FLAGS) -MTd -DNDEBUG $(CC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)

CPPC_XTESTS_ARGS_UX_MT_D		=	$(CPPC_XTESTS_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)
CPPC_XTESTS_ARGS_UX_MT_R		=	$(CPPC_XTESTS_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)


# - Examples
CC_EXAMPLE_ARGS_UX_MT_D		=	$(CC_EXAMPLE_FLAGS) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)
CC_EXAMPLE_ARGS_UX_MT_R		=	$(CC_EXAMPLE_FLAGS) -MTd -DNDEBUG $(CC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)

CPPC_EXAMPLE_ARGS_UX_MT_D	=	$(CPPC_EXAMPLE_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)
CPPC_EXAMPLE_ARGS_UX_MT_R	=	$(CPPC_EXAMPLE_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)


# - Test (Component)
CC_TEST_COMPONENT_ARGS_UX_MT_D		=	$(CC_TEST_COMPONENT_FLAGS) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)
CC_TEST_COMPONENT_ARGS_UX_MT_R		=	$(CC_TEST_COMPONENT_FLAGS) -MTd -DNDEBUG $(CC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)

CPPC_TEST_COMPONENT_ARGS_UX_MT_D		=	$(CPPC_TEST_COMPONENT_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)
CPPC_TEST_COMPONENT_ARGS_UX_MT_R		=	$(CPPC_TEST_COMPONENT_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)


# - Test (Scratch)
CC_TEST_SCRATCH_ARGS_UX_MT_D			=	$(CC_TEST_SCRATCH_FLAGS) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)
CC_TEST_SCRATCH_ARGS_UX_MT_R			=	$(CC_TEST_SCRATCH_FLAGS) -MTd -DNDEBUG $(CC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)

CPPC_TEST_SCRATCH_ARGS_UX_MT_D		=	$(CPPC_TEST_SCRATCH_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)
CPPC_TEST_SCRATCH_ARGS_UX_MT_R		=	$(CPPC_TEST_SCRATCH_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)


# - Test (Unit)
CC_TEST_UNIT_ARGS_UX_MT_D			=	$(CC_TEST_UNIT_FLAGS) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)
CC_TEST_UNIT_ARGS_UX_MT_R			=	$(CC_TEST_UNIT_FLAGS) -MTd -DNDEBUG $(CC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CC_DEFS)

CPPC_TEST_UNIT_ARGS_UX_MT_D			=	$(CPPC_TEST_UNIT_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)
CPPC_TEST_UNIT_ARGS_UX_MT_R			=	$(CPPC_TEST_UNIT_FLAGS) $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.$(COMP_ARCH_OS_TAG).pdb  $(CPPC_DEFS)


# AR args

AR_ARGS			=	-nologo


# LD flags

LD_ARGS		=

LD_F_NOLOGO = -nologo

# LD args

LD_ARGS_UX_MT_D = libWinSysLog.$(COMP_TAG).mt.debug.lib unixem.1.$(COMP_TAG).mt.debug.lib -debug $(LD_ARGS) $(LD_F_NOLOGO) $(LIBPATHS) $(COMMON_LIB)
LD_ARGS_UX_MT_R = libWinSysLog.$(COMP_TAG).mt.lib unixem.1.$(COMP_TAG).mt.lib -release $(LD_ARGS) $(LD_F_NOLOGO) $(LIBPATHS) $(COMMON_LIB)

############################################################################
# headers

CORE_HEADERS=\
 \
 $(PROJ_INCLUDE_DIR)\pantheios\assert.h\
 $(PROJ_INCLUDE_DIR)\pantheios\backend.h\
 $(PROJ_INCLUDE_DIR)\pantheios\fileline.h\
 $(PROJ_INCLUDE_DIR)\pantheios\frontend.h\
 $(PROJ_INCLUDE_DIR)\pantheios\init_codes.h\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\pan.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\pantheios.h\
 $(PROJ_INCLUDE_DIR)\pantheios\pantheios.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\trace.h\
 \
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\args.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\b.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\b64.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\blob.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\boolean.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\ch.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\character.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\exception.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\fmt.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\hex_ptr.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\hostid.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\i.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\ids.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\integer.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\interval.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\m2t.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\m2w.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\p.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\pad.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\pointer.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\processid.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\real.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\slice.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\stream_character.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\threadid.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\w2m.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\w2t.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\xi.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\inserters\xp.hpp\
 \
 $(PROJ_INCLUDE_DIR)\pantheios\internal\initialiser.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\internal\lean.h\
 $(PROJ_INCLUDE_DIR)\pantheios\internal\nox.h\
 $(PROJ_INCLUDE_DIR)\pantheios\internal\safestr.h\
 $(PROJ_INCLUDE_DIR)\pantheios\internal\shim_declarations.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\internal\slice.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\internal\stock_levels.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\internal\string_encoding.h\
 $(PROJ_INCLUDE_DIR)\pantheios\internal\threading.h\
 $(PROJ_INCLUDE_DIR)\pantheios\internal\winlean.h\
 \
 $(PROJ_INCLUDE_DIR)\pantheios\quality\contract.h\
 \
 $(PROJ_INCLUDE_DIR)\pantheios\generated\log_dispatch_functions.h\
 $(PROJ_INCLUDE_DIR)\pantheios\generated\log_dispatch_functions.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\generated\log_functions.h\
 $(PROJ_INCLUDE_DIR)\pantheios\generated\log_functions.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\generated\log_sev_functions.hpp\
 \
 $(PROJ_INCLUDE_DIR)\pantheios\severity\levels.hpp\
 \
 $(PROJ_INCLUDE_DIR)\pantheios\shims\access\string\core\pan_severity_t.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\shims\access\string\core\pan_slice_t.hpp\
 \
 $(PROJ_INCLUDE_DIR)\pantheios\util\backends\arguments.h\
 $(PROJ_INCLUDE_DIR)\pantheios\util\backends\context.hpp\
 \
 $(PROJ_INCLUDE_DIR)\pantheios\util\core\apidefs.hpp\
 \
 $(PROJ_INCLUDE_DIR)\pantheios\util\memory\auto_buffer_selector.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\util\memory\inserters.hpp\
 $(PROJ_INCLUDE_DIR)\pantheios\util\memory\memcopy.h\
 \
 $(PROJ_INCLUDE_DIR)\pantheios\util\severity\ACE.h\
 $(PROJ_INCLUDE_DIR)\pantheios\util\severity\syslog.h\
 $(PROJ_INCLUDE_DIR)\pantheios\util\severity\WindowsEventLog.h\
 \
 $(PROJ_INCLUDE_DIR)\pantheios\util\string\date_elements_to_string.h\
 $(PROJ_INCLUDE_DIR)\pantheios\util\string\snprintf.h\
 $(PROJ_INCLUDE_DIR)\pantheios\util\string\strdup.h\
 $(PROJ_INCLUDE_DIR)\pantheios\util\string\strnlen.h\
 \
 $(PROJ_INCLUDE_DIR)\pantheios\util\system\hostname.h\
 $(PROJ_INCLUDE_DIR)\pantheios\util\system\processid.h\
 $(PROJ_INCLUDE_DIR)\pantheios\util\system\threadid.h\
 \
 $(PROJ_INCLUDE_DIR)\pantheios\util\time\currenttime.h\
 \
 \

BE_HEADERS=\
 $(PROJ_INCLUDE_DIR)\pantheios\pantheios.h \
 $(PROJ_INCLUDE_DIR)\pantheios\backend.h \
 \

FE_HEADERS=\
 $(PROJ_INCLUDE_DIR)\pantheios\pantheios.h \
 $(PROJ_INCLUDE_DIR)\pantheios\frontend.h \
 \

TEST_C_HEADERS=\
 $(PROJ_INCLUDE_DIR)\pantheios\backend.h\
 $(PROJ_INCLUDE_DIR)\pantheios\frontend.h\
 $(PROJ_INCLUDE_DIR)\pantheios\pantheios.h\
 \

TEST_CPP_HEADERS=\
 $(CORE_HEADERS)\
 $(PROJ_INCLUDE_DIR)\pantheios\backends\bec.test.h\
 \

!ifndef PANTHEIOS_NO_B64

B64_HEADERS=\
 $(B64_INCLUDE_DIR)\b64\b64.h\
 $(B64_INCLUDE_DIR)\b64\b64.hpp\
 \

!endif # !PANTHEIOS_NO_B64

SHWILD_HEADERS=\
 $(SHWILD_INCLUDE_DIR)\shwild\shwild.h\
 $(SHWILD_INCLUDE_DIR)\shwild\shwild.hpp\
 \

XCONTRACT_HEADERS=\
 $(XCONTRACT_INCLUDE_DIR)\xcontract\xcontract.h\
 \

XTESTS_HEADERS=\
 $(XTESTS_INCLUDE_DIR)\xtests\xtests.h\
 \

############################################################################
# names

############################################################
# targets

########################################
# libraries

#  util
LIB_UTIL_UX_MT_D				=   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).util.$(COMP_ARCH_OS_TAG).mt.debug.lib

#  appl
LIB_APPL_UX_MT_D				=   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).appl.$(COMP_ARCH_OS_TAG).mt.debug.lib

#  core
LIB_CORE_UX_MT_D				=   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).mt.debug.lib

#  front-end(s)
LIB_FE_ALL_UX_MT_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.all.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_FE_ALL_WC_UX_MT_D		=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.all.WithCallback.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_FE_FAIL_UX_MT_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.fail.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_FE_N_UX_MT_D				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.N.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_FE_N_WC_UX_MT_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.N.WithCallback.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_FE_NULL_UX_MT_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.null.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_FE_NULL_WC_UX_MT_D		=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.null.WithCallback.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_FE_SIMPLE_UX_MT_D		=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.simple.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_FE_SIMPLE_WC_UX_MT_D		=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.simple.WithCallback.$(COMP_ARCH_OS_TAG).mt.debug.lib

#  back-end(s)
LIB_BEC_STOCK_UX_MT_D				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.stock.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BEC_STOCK_WC_UX_MT_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.stock.WithCallback.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BE_LRSPLIT_UX_MT_D				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.lrsplit.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BE_N_UX_MT_D							=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.N.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BEC_TEST_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.test.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BE_TEST_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.test.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BEL_TEST_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bel.test.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BER_TEST_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).ber.test.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BEC_FAIL_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.fail.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BE_FAIL_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.fail.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BEL_FAIL_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bel.fail.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BER_FAIL_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).ber.fail.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BEC_FILE_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.file.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BEC_FILE_WC_UX_MT_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.file.WithCallback.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BE_FILE_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.file.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BEL_FILE_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bel.file.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BER_FILE_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).ber.file.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BEC_FPRINTF_UX_MT_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.fprintf.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BEC_FPRINTF_WC_UX_MT_D		=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.fprintf.WithCallback.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BE_FPRINTF_UX_MT_D				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.fprintf.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BEL_FPRINTF_UX_MT_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bel.fprintf.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BER_FPRINTF_UX_MT_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).ber.fprintf.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BEC_NULL_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.null.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BE_NULL_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.null.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BEL_NULL_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bel.null.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BER_NULL_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).ber.null.$(COMP_ARCH_OS_TAG).mt.debug.lib
!ifdef ACE
LIB_BEC_ACE_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.ACE.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BE_ACE_UX_MT_D						=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.ACE.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BEL_ACE_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bel.ACE.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BER_ACE_UX_MT_D					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).ber.ACE.$(COMP_ARCH_OS_TAG).mt.debug.lib
!endif # ACE
LIB_BEC_SYSLOG_UX_MT_D				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.syslog.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BEC_SYSLOGWC_UX_MT_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.syslog.WithCallback.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BE_SYSLOG_UX_MT_D				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.syslog.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_BER_SYSLOG_UX_MT_D				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).ber.syslog.$(COMP_ARCH_OS_TAG).mt.debug.lib

#  util
LIB_UTIL_UX_MT_R				=   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).util.$(COMP_ARCH_OS_TAG).mt.lib

#  appl
LIB_APPL_UX_MT_R				=   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).appl.$(COMP_ARCH_OS_TAG).mt.lib

#  core
LIB_CORE_UX_MT_R				=   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).mt.lib

#  front-end(s)
LIB_FE_ALL_UX_MT_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.all.$(COMP_ARCH_OS_TAG).mt.lib
LIB_FE_ALL_WC_UX_MT_R		=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.all.WithCallback.$(COMP_ARCH_OS_TAG).mt.lib
LIB_FE_FAIL_UX_MT_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.fail.$(COMP_ARCH_OS_TAG).mt.lib
LIB_FE_N_UX_MT_R				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.N.$(COMP_ARCH_OS_TAG).mt.lib
LIB_FE_N_WC_UX_MT_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.N.WithCallback.$(COMP_ARCH_OS_TAG).mt.lib
LIB_FE_NULL_UX_MT_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.null.$(COMP_ARCH_OS_TAG).mt.lib
LIB_FE_NULL_WC_UX_MT_R		=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.null.WithCallback.$(COMP_ARCH_OS_TAG).mt.lib
LIB_FE_SIMPLE_UX_MT_R		=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.simple.$(COMP_ARCH_OS_TAG).mt.lib
LIB_FE_SIMPLE_WC_UX_MT_R		=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).fe.simple.WithCallback.$(COMP_ARCH_OS_TAG).mt.lib

#  back-end(s)
LIB_BEC_STOCK_UX_MT_R				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.stock.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BEC_STOCK_WC_UX_MT_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.stock.WithCallback.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BE_LRSPLIT_UX_MT_R				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.lrsplit.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BE_N_UX_MT_R							=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.N.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BEC_TEST_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.test.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BE_TEST_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.test.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BEL_TEST_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bel.test.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BER_TEST_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).ber.test.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BEC_FAIL_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.fail.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BE_FAIL_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.fail.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BEL_FAIL_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bel.fail.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BER_FAIL_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).ber.fail.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BEC_FILE_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.file.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BEC_FILE_WC_UX_MT_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.file.WithCallback.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BE_FILE_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.file.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BEL_FILE_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bel.file.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BER_FILE_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).ber.file.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BEC_FPRINTF_UX_MT_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.fprintf.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BEC_FPRINTF_WC_UX_MT_R		=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.fprintf.WithCallback.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BE_FPRINTF_UX_MT_R				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.fprintf.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BEL_FPRINTF_UX_MT_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bel.fprintf.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BER_FPRINTF_UX_MT_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).ber.fprintf.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BEC_NULL_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.null.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BE_NULL_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.null.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BEL_NULL_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bel.null.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BER_NULL_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).ber.null.$(COMP_ARCH_OS_TAG).mt.lib
!ifdef ACE
LIB_BEC_ACE_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.ACE.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BE_ACE_UX_MT_R						=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.ACE.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BEL_ACE_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bel.ACE.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BER_ACE_UX_MT_R					=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).ber.ACE.$(COMP_ARCH_OS_TAG).mt.lib
!endif # ACE
LIB_BEC_SYSLOG_UX_MT_R				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.syslog.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BEC_SYSLOGWC_UX_MT_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).bec.syslog.WithCallback.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BE_SYSLOG_UX_MT_R				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).be.syslog.$(COMP_ARCH_OS_TAG).mt.lib
LIB_BER_SYSLOG_UX_MT_R				=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).ber.syslog.$(COMP_ARCH_OS_TAG).mt.lib

# core

# front-end(s)
PDB_FE_ALL_UX_MT_D						=	$(PROJ_OBJ_DIR)\fe.all.mt.debug.pdb
PDB_FE_FAIL_UX_MT_D					=	$(PROJ_OBJ_DIR)\fe.fail.mt.debug.pdb
PDB_FE_N_UX_MT_D							=	$(PROJ_OBJ_DIR)\fe.N.mt.debug.pdb
PDB_FE_NULL_UX_MT_D					=	$(PROJ_OBJ_DIR)\fe.null.mt.debug.pdb
PDB_FE_SIMPLE_UX_MT_D				=	$(PROJ_OBJ_DIR)\fe.simple.mt.debug.pdb

# back-end(s)
PDB_BE_LRSPLIT_UX_MT_D				=	$(PROJ_OBJ_DIR)\be.lrsplit.mt.debug.pdb
PDB_BE_N_UX_MT_D							=	$(PROJ_OBJ_DIR)\be.N.mt.debug.pdb
PDB_BEC_FAIL_UX_MT_D					=	$(PROJ_OBJ_DIR)\bec.fail.mt.debug.pdb
PDB_BE_FAIL_UX_MT_D					=	$(PROJ_OBJ_DIR)\be.fail.mt.debug.pdb
PDB_BEL_FAIL_UX_MT_D					=	$(PROJ_OBJ_DIR)\bel.fail.mt.debug.pdb
PDB_BER_FAIL_UX_MT_D					=	$(PROJ_OBJ_DIR)\ber.fail.mt.debug.pdb
PDB_BEC_FILE_UX_MT_D					=	$(PROJ_OBJ_DIR)\bec.file.mt.debug.pdb
PDB_BEC_FILE_WC_UX_MT_D			=	$(PROJ_OBJ_DIR)\bec.file.WithCallback.mt.debug.pdb
PDB_BE_FILE_UX_MT_D					=	$(PROJ_OBJ_DIR)\be.file.mt.debug.pdb
PDB_BEL_FILE_UX_MT_D					=	$(PROJ_OBJ_DIR)\bel.file.mt.debug.pdb
PDB_BER_FILE_UX_MT_D					=	$(PROJ_OBJ_DIR)\ber.file.mt.debug.pdb
PDB_BEC_FPRINTF_UX_MT_D			=	$(PROJ_OBJ_DIR)\bec.fprintf.mt.debug.pdb
PDB_BEC_FPRINTF_WC_UX_MT_D		=	$(PROJ_OBJ_DIR)\bec.fprintf.WithCallback.mt.debug.pdb
PDB_BE_FPRINTF_UX_MT_D				=	$(PROJ_OBJ_DIR)\be.fprintf.mt.debug.pdb
PDB_BEL_FPRINTF_UX_MT_D			=	$(PROJ_OBJ_DIR)\bel.fprintf.mt.debug.pdb
PDB_BER_FPRINTF_UX_MT_D			=	$(PROJ_OBJ_DIR)\ber.fprintf.mt.debug.pdb
PDB_BEC_NULL_UX_MT_D					=	$(PROJ_OBJ_DIR)\bec.null.mt.debug.pdb
PDB_BE_NULL_UX_MT_D					=	$(PROJ_OBJ_DIR)\be.null.mt.debug.pdb
PDB_BEL_NULL_UX_MT_D					=	$(PROJ_OBJ_DIR)\bel.null.mt.debug.pdb
PDB_BER_NULL_UX_MT_D					=	$(PROJ_OBJ_DIR)\ber.null.mt.debug.pdb
!ifdef ACE
PDB_BEC_ACE_UX_MT_D					=	$(PROJ_OBJ_DIR)\bec.ACE.mt.debug.pdb
PDB_BE_ACE_UX_MT_D						=	$(PROJ_OBJ_DIR)\be.ACE.mt.debug.pdb
PDB_BEL_ACE_UX_MT_D					=	$(PROJ_OBJ_DIR)\bel.ACE.mt.debug.pdb
PDB_BER_ACE_UX_MT_D					=	$(PROJ_OBJ_DIR)\ber.ACE.mt.debug.pdb
!endif # ACE
PDB_BEC_SYSLOG_UX_MT_D				=	$(PROJ_OBJ_DIR)\bec.syslog.mt.debug.pdb
PDB_BEC_SYSLOGWC_UX_MT_D			=	$(PROJ_OBJ_DIR)\bec.syslog.mt.debug.pdb
PDB_BE_SYSLOG_UX_MT_D				=	$(PROJ_OBJ_DIR)\be.syslog.mt.debug.pdb
PDB_BER_SYSLOG_UX_MT_D				=	$(PROJ_OBJ_DIR)\ber.syslog.mt.debug.pdb


# b64

!ifdef PANTHEIOS_NO_B64
LIB_B64_UX_MT_D			=
LIB_B64_UX_MT_R			=
!else
LIB_B64_UX_MT_D			=   $(PROJ_LIB_DIR)\$(B64_TAG_VER).pan.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_B64_UX_MT_R			=   $(PROJ_LIB_DIR)\$(B64_TAG_VER).pan.$(COMP_ARCH_OS_TAG).mt.lib
!endif # !PANTHEIOS_NO_B64

# shwild
LIB_SHWILD_UX_MT_D       =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).pan.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_SHWILD_UX_MT_R       =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).pan.$(COMP_ARCH_OS_TAG).mt.lib

# xContract
LIB_XCONTRACT_UX_MT_D    =   $(PROJ_LIB_DIR)\$(XCONTRACT_TAG_VER).pan.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_XCONTRACT_UX_MT_R    =   $(PROJ_LIB_DIR)\$(XCONTRACT_TAG_VER).pan.$(COMP_ARCH_OS_TAG).mt.lib

# xTests
LIB_XTESTS_UX_MT_D       =   $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).pan.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_XTESTS_UX_MT_R       =   $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).pan.$(COMP_ARCH_OS_TAG).mt.lib

########################################
# examples

TARG_EX_P_be_01_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.be.01.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_be_02_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.be.02.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_be_03_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.be.03.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_be_04_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.be.04.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_be_05_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.be.05.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_be_06_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.be.06.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_cp_01_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.cp.01.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_cp_02_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.cp.02.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_fm_01_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.fm.01.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_fm_02_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.fm.02.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_fm_03_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.fm.03.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_fe_01_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.fe.01.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_in_01_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.01.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_in_02_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.02.$(COMP_ARCH_OS_TAG).mt.debug.exe
!ifdef PANTHEIOS_NO_B64
TARG_EX_P_in_03_UX_MT_D	=
!else
TARG_EX_P_in_03_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.03.$(COMP_ARCH_OS_TAG).mt.debug.exe
!endif # PANTHEIOS_NO_B64
TARG_EX_P_in_04_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.04.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_in_05_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.05.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_in_06_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.06.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_in_07_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.07.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_in_08_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.08.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_in_09_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.09.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_in_10_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.10.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_in_11_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.11.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_in_12_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.12.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_in_13_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.13.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_in_14_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.14.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_in_15_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.15.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_in_16_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.16.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_in_17_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.17.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_ln_01_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ln.01.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_ms_01_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ms.01.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_ms_02_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ms.02.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_ms_03_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ms.03.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_ms_04_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ms.04.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_ms_05_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ms.05.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_ms_06_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ms.06.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_ut_01_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ut.01.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_C_0_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.0.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_C_1_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_C_2_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.2.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_C_3_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.3.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_C_4_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.4.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_C_5_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.5.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_C_6_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.6.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_C_7_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.7.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_P_be_01_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.be.01.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_be_02_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.be.02.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_be_03_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.be.03.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_be_04_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.be.04.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_be_05_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.be.05.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_be_06_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.be.06.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_cp_01_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.cp.01.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_cp_02_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.cp.02.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_fm_01_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.fm.01.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_fm_02_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.fm.02.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_fm_03_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.fm.03.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_fe_01_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.fe.01.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_in_01_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.01.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_in_02_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.02.$(COMP_ARCH_OS_TAG).mt.exe
!ifdef PANTHEIOS_NO_B64
TARG_EX_P_in_03_UX_MT_R	=
!else
TARG_EX_P_in_03_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.03.$(COMP_ARCH_OS_TAG).mt.exe
!endif # PANTHEIOS_NO_B64
TARG_EX_P_in_04_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.04.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_in_05_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.05.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_in_06_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.06.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_in_07_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.07.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_in_08_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.08.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_in_09_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.09.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_in_10_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.10.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_in_11_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.11.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_in_12_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.12.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_in_13_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.13.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_in_14_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.14.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_in_15_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.15.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_in_16_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.16.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_in_17_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.in.17.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_ln_01_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ln.01.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_ms_01_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ms.01.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_ms_02_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ms.02.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_ms_03_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ms.03.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_ms_04_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ms.04.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_ms_05_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ms.05.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_ms_06_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ms.06.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_P_ut_01_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.ut.01.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_C_0_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.0.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_C_1_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.1.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_C_2_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.2.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_C_3_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.3.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_C_4_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.4.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_C_5_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.5.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_C_6_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.6.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_C_7_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.7.$(COMP_ARCH_OS_TAG).mt.exe

########################################
# tests

##############################
# component tests

TARG_TEST_COMP_filemt_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.be.file.threading.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_bec_fprtf_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.bec.fprintf.$(COMP_ARCH_OS_TAG).mt.debug.exe
#### TODO: test.component.core.getProcessIdentity
TARG_TEST_COMP_core_initseq_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.core.init_sequence.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_pan_prtf_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.core.pan_logprintf.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_pan_puts_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.core.pan_logputs.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_custsev_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.custom_severity.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_ins_args_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.args.$(COMP_ARCH_OS_TAG).mt.debug.exe
!ifdef PANTHEIOS_NO_B64
TARG_TEST_COMP_ins_b64_UX_MT_D		=
!else
TARG_TEST_COMP_ins_b64_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.b64.$(COMP_ARCH_OS_TAG).mt.debug.exe
!endif # PANTHEIOS_NO_B64
TARG_TEST_COMP_ins_bool_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.boolean.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_ins_hostid_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.hostid.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_ins_int_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.integer.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_ins_pad_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.pad.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_ins_ptr_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.pointer.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_ins_prid_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.processid.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_ins_real_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.real.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_ins_slice_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.slice.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_ins_stm_ch_UX_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.stream_character.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_ins_thrid_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.threadid.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_ins_w2m_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.w2m.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_log_1_UX_MT_D			=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.log.1.$(COMP_ARCH_OS_TAG).mt.debug.exe
#### TODO: test.component.no_namespace
TARG_TEST_COMP_filemt_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.be.file.threading.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_bec_fprtf_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.bec.fprintf.$(COMP_ARCH_OS_TAG).mt.exe
#### TODO: test.component.core.getProcessIdentity
TARG_TEST_COMP_core_initseq_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.core.init_sequence.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_pan_prtf_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.core.pan_logprintf.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_pan_puts_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.core.pan_logputs.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_custsev_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.custom_severity.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_ins_args_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.args.$(COMP_ARCH_OS_TAG).mt.exe
!ifdef PANTHEIOS_NO_B64
TARG_TEST_COMP_ins_b64_UX_MT_R		=
!else
TARG_TEST_COMP_ins_b64_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.b64.$(COMP_ARCH_OS_TAG).mt.exe
!endif # PANTHEIOS_NO_B64
TARG_TEST_COMP_ins_bool_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.boolean.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_ins_hostid_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.hostid.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_ins_int_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.integer.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_ins_pad_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.pad.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_ins_ptr_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.pointer.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_ins_prid_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.processid.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_ins_real_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.real.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_ins_slice_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.slice.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_ins_stm_ch_UX_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.stream_character.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_ins_thrid_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.threadid.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_ins_w2m_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserters.w2m.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_log_1_UX_MT_R			=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.log.1.$(COMP_ARCH_OS_TAG).mt.exe
#### TODO: test.component.no_namespace

##############################
# performance tests

TARG_TEST_PERF_ins_w2m_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.w2m.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_PERF_dtel2s_UX_MT_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.util.date_elements_to_string.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_PERF_ins_w2m_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.inserter.w2m.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_PERF_dtel2s_UX_MT_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.performance.util.date_elements_to_string.$(COMP_ARCH_OS_TAG).mt.exe

##############################
# scratch tests

# test programs
#
# - be.ACE
# - be.fprintf
# - be.syslog / be.WindowsDebugger
#
# - be.lrsplit & fprintf + syslog / WindowsSyslog
#
# The strange naming conventions of these targets are to placate some
# make utilities, which have a limit to the identifier length.
!ifdef ACE
TARG_SCRT_ACE_UX_MT_D							=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.be.ACE.$(COMP_ARCH_OS_TAG).mt.debug.exe
!endif # ACE
TARG_SCRT_UX_MT_D_APIwBE_FPRINTF					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.be.fprintf.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_SCRT_BE_SYSLOG_UX_MT_D						=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.be.syslog.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_SCRT_BE_SYSLOGWC_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.be.syslog.WC.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_SCRT_UX_MT_D_APIwBELR_1_FPRINTF_SYSLOG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.l.fprintf-r.syslog.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_SCRT_FE_UX_MT_D								=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.fe.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_SCRT_BE_N_FAIL_UX_MT_D						=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.be.N.fail.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_SCRT_FE_SIMPLE_WC_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.fe.simple.WC.$(COMP_ARCH_OS_TAG).mt.debug.exe
!ifdef ACE
TARG_SCRT_ACE_UX_MT_R							=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.be.ACE.$(COMP_ARCH_OS_TAG).mt.exe
!endif # ACE
TARG_SCRT_UX_MT_R_APIwBE_FPRINTF					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.be.fprintf.$(COMP_ARCH_OS_TAG).mt.exe
TARG_SCRT_BE_SYSLOG_UX_MT_R						=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.be.syslog.$(COMP_ARCH_OS_TAG).mt.exe
TARG_SCRT_BE_SYSLOGWC_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.be.syslog.WC.$(COMP_ARCH_OS_TAG).mt.exe
TARG_SCRT_UX_MT_R_APIwBELR_1_FPRINTF_SYSLOG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.l.fprintf-r.syslog.$(COMP_ARCH_OS_TAG).mt.exe
TARG_SCRT_FE_UX_MT_R								=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.fe.$(COMP_ARCH_OS_TAG).mt.exe
TARG_SCRT_BE_N_FAIL_UX_MT_R						=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.be.N.fail.$(COMP_ARCH_OS_TAG).mt.exe
TARG_SCRT_FE_SIMPLE_WC_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.fe.simple.WC.$(COMP_ARCH_OS_TAG).mt.exe

##############################
# unit tests

TARG_TEST_UNIT_be_fail_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.be.fail.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_be_lrsplit_UX_MT_D				=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.be.lrsplit.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_be_N_UX_MT_D						=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.be.N.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_be_N_filt_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.be.N.filtering.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_bec_fail_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bec.fail.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_bec_file_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bec.file.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_bec_fprintf_UX_MT_D				=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bec.fprintf.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_fe_all_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.fe.all.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_fe_fail_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.fe.fail.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_fe_N_UX_MT_D						=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.fe.N.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_fe_null_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.fe.null.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_fe_simple_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.fe.simple.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_getversion_UX_MT_D				=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.getversion.$(COMP_ARCH_OS_TAG).mt.debug.exe
#### TODO: test.unit.levels.2
TARG_TEST_UNIT_lvls_dyninit_UX_MT_D				=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.levels.dynamic_init.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_lvls_vals_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.levels.values.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_dtel2s_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.util.dtel2s.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_getcurrtm_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.util.getcurrenttime.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_gethostname_UX_MT_D				=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.util.gethostname.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_onbailout_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.util.onbailout.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_snprintf_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.util.snprintf.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_strnlen_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.util.strnlen.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_be_fail_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.be.fail.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_be_lrsplit_UX_MT_R				=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.be.lrsplit.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_be_N_UX_MT_R						=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.be.N.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_be_N_filt_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.be.N.filtering.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_bec_fail_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bec.fail.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_bec_file_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bec.file.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_bec_fprintf_UX_MT_R				=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.bec.fprintf.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_fe_all_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.fe.all.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_fe_fail_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.fe.fail.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_fe_N_UX_MT_R						=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.fe.N.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_fe_null_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.fe.null.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_fe_simple_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.fe.simple.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_getversion_UX_MT_R				=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.getversion.$(COMP_ARCH_OS_TAG).mt.exe
#### TODO: test.unit.levels.2
TARG_TEST_UNIT_lvls_dyninit_UX_MT_R				=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.levels.dynamic_init.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_lvls_vals_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.levels.values.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_dtel2s_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.util.dtel2s.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_getcurrtm_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.util.getcurrenttime.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_gethostname_UX_MT_R				=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.util.gethostname.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_onbailout_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.util.onbailout.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_snprintf_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.util.snprintf.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_strnlen_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.util.strnlen.$(COMP_ARCH_OS_TAG).mt.exe

TARG_TEST_UNIT_ins_int_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserter.integer.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_ins_w2m_UX_MT_D					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserter.w2m.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_ins_stmc_UX_MT_D				=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserter.stream_character.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_ins_int_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserter.integer.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_ins_w2m_UX_MT_R					=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserter.w2m.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_ins_stmc_UX_MT_R				=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.inserter.stream_character.$(COMP_ARCH_OS_TAG).mt.exe

############################################################
# objects

########################################
# libraries

# util

OBJ_utl_api_exit_UX_MT_D				= $(PROJ_OBJ_DIR)\core.api.exitprocess.mt.debug.obj

OBJ_utl_bailout_UX_MT_D				= $(PROJ_OBJ_DIR)\util.bailout.mt.debug.obj
OBJ_utl_dtel2s_UX_MT_D					= $(PROJ_OBJ_DIR)\util.dtel2s.mt.debug.obj
OBJ_utl_init_code_strs_UX_MT_D	= $(PROJ_OBJ_DIR)\util.init_err_strings.mt.debug.obj
OBJ_utl_sev_strs_UX_MT_D				= $(PROJ_OBJ_DIR)\util.sev_strings.mt.debug.obj
OBJ_utl_snprintf_UX_MT_D				= $(PROJ_OBJ_DIR)\util.snprintf.mt.debug.obj
OBJ_utl_strdup_UX_MT_D					= $(PROJ_OBJ_DIR)\util.strdup.mt.debug.obj
OBJ_utl_procid_UX_MT_D					= $(PROJ_OBJ_DIR)\util.procid.mt.debug.obj
OBJ_utl_thread_UX_MT_D					= $(PROJ_OBJ_DIR)\util.thread.mt.debug.obj
OBJ_utl_be_context_UX_MT_D			= $(PROJ_OBJ_DIR)\util.be_context.mt.debug.obj
OBJ_utl_core_apidefs_UX_MT_D		= $(PROJ_OBJ_DIR)\util.core_apidefs.mt.debug.obj
OBJ_utl_be_parse_UX_MT_D				= $(PROJ_OBJ_DIR)\util.be_parse.mt.debug.obj
OBJ_utl_strnlen_UX_MT_D				= $(PROJ_OBJ_DIR)\util.strnlen.mt.debug.obj
OBJ_utl_strnlenp_UX_MT_D				= $(PROJ_OBJ_DIR)\util.strnlen.c++.mt.debug.obj
OBJ_utl_time_UX_MT_D						= $(PROJ_OBJ_DIR)\util.time.mt.debug.obj
OBJ_utl_host_name_UX_MT_D			= $(PROJ_OBJ_DIR)\util.host_name.mt.debug.obj

OBJ_UTIL_UX_MT_D=\
 $(OBJ_utl_api_exit_UX_MT_D)\
 \
 $(OBJ_utl_bailout_UX_MT_D)\
 $(OBJ_utl_dtel2s_UX_MT_D)\
 $(OBJ_utl_init_code_strs_UX_MT_D)\
 $(OBJ_utl_sev_strs_UX_MT_D)\
 $(OBJ_utl_snprintf_UX_MT_D)\
 $(OBJ_utl_strdup_UX_MT_D)\
 $(OBJ_utl_procid_UX_MT_D)\
 $(OBJ_utl_thread_UX_MT_D)\
 $(OBJ_utl_be_context_UX_MT_D)\
 $(OBJ_utl_core_apidefs_UX_MT_D)\
 $(OBJ_utl_be_parse_UX_MT_D)\
 $(OBJ_utl_strnlen_UX_MT_D)\
 $(OBJ_utl_strnlenp_UX_MT_D)\
 $(OBJ_utl_time_UX_MT_D)\
 $(OBJ_utl_host_name_UX_MT_D)\
 \

OBJ_UTIL_UX_MT_D_P=\
 +$(OBJ_utl_api_exit_UX_MT_D)\
 +$(OBJ_utl_bailout_UX_MT_D)\
 +$(OBJ_utl_dtel2s_UX_MT_D)\
 +$(OBJ_utl_init_code_strs_UX_MT_D)\
 +$(OBJ_utl_sev_strs_UX_MT_D)\
 +$(OBJ_utl_snprintf_UX_MT_D)\
 +$(OBJ_utl_strdup_UX_MT_D)\
 +$(OBJ_utl_procid_UX_MT_D)\
 +$(OBJ_utl_thread_UX_MT_D)\
 +$(OBJ_utl_be_context_UX_MT_D)\
 +$(OBJ_utl_core_apidefs_UX_MT_D)\
 +$(OBJ_utl_be_parse_UX_MT_D)\
 +$(OBJ_utl_strnlen_UX_MT_D)\
 +$(OBJ_utl_strnlenp_UX_MT_D)\
 +$(OBJ_utl_time_UX_MT_D)\
 +$(OBJ_utl_host_name_UX_MT_D)\
 \

PDB_utl_bailout_UX_MT_D				= $(PROJ_OBJ_DIR)\util.bailout.mt.debug.pdb
PDB_utl_init_code_strs_UX_MT_D	= $(PROJ_OBJ_DIR)\util.init_err_strings.mt.debug.pdb
PDB_utl_sev_strs_UX_MT_D				= $(PROJ_OBJ_DIR)\util.sev_strings.mt.debug.pdb
PDB_utl_snprintf_UX_MT_D				= $(PROJ_OBJ_DIR)\util.snprintf.mt.debug.pdb
PDB_utl_strdup_UX_MT_D					= $(PROJ_OBJ_DIR)\util.strdup.mt.debug.pdb
PDB_utl_procid_UX_MT_D					= $(PROJ_OBJ_DIR)\util.procid.mt.debug.pdb
PDB_utl_thread_UX_MT_D					= $(PROJ_OBJ_DIR)\util.thread.mt.debug.pdb
PDB_utl_be_context_UX_MT_D			= $(PROJ_OBJ_DIR)\util.be_context.mt.debug.pdb
PDB_utl_core_apidefs_UX_MT_D		= $(PROJ_OBJ_DIR)\util.core_apidefs.mt.debug.pdb
PDB_utl_be_parse_UX_MT_D				= $(PROJ_OBJ_DIR)\util.be_parse.mt.debug.pdb
PDB_utl_strnlen_UX_MT_D				= $(PROJ_OBJ_DIR)\util.strnlen.mt.debug.pdb
PDB_utl_time_UX_MT_D						= $(PROJ_OBJ_DIR)\util.time.mt.debug.pdb
PDB_utl_host_name_UX_MT_D			= $(PROJ_OBJ_DIR)\util.host_name.mt.debug.pdb

PDB_UTIL_UX_MT_D=\
 $(PDB_utl_bailout_UX_MT_D)\
 $(PDB_utl_init_code_strs_UX_MT_D)\
 $(PDB_utl_sev_strs_UX_MT_D)\
 $(PDB_utl_snprintf_UX_MT_D)\
 $(PDB_utl_strdup_UX_MT_D)\
 $(PDB_utl_procid_UX_MT_D)\
 $(PDB_utl_thread_UX_MT_D)\
 $(PDB_utl_be_context_UX_MT_D)\
 $(PDB_utl_core_apidefs_UX_MT_D)\
 $(PDB_utl_be_parse_UX_MT_D)\
 $(PDB_utl_strnlen_UX_MT_D)\
 $(PDB_utl_time_UX_MT_D)\
 $(PDB_utl_host_name_UX_MT_D)\
 \

OBJ_utl_api_exit_UX_MT_R				= $(PROJ_OBJ_DIR)\core.api.exitprocess.mt.obj

OBJ_utl_bailout_UX_MT_R				= $(PROJ_OBJ_DIR)\util.bailout.mt.obj
OBJ_utl_dtel2s_UX_MT_R					= $(PROJ_OBJ_DIR)\util.dtel2s.mt.obj
OBJ_utl_init_code_strs_UX_MT_R	= $(PROJ_OBJ_DIR)\util.init_err_strings.mt.obj
OBJ_utl_sev_strs_UX_MT_R				= $(PROJ_OBJ_DIR)\util.sev_strings.mt.obj
OBJ_utl_snprintf_UX_MT_R				= $(PROJ_OBJ_DIR)\util.snprintf.mt.obj
OBJ_utl_strdup_UX_MT_R					= $(PROJ_OBJ_DIR)\util.strdup.mt.obj
OBJ_utl_procid_UX_MT_R					= $(PROJ_OBJ_DIR)\util.procid.mt.obj
OBJ_utl_thread_UX_MT_R					= $(PROJ_OBJ_DIR)\util.thread.mt.obj
OBJ_utl_be_context_UX_MT_R			= $(PROJ_OBJ_DIR)\util.be_context.mt.obj
OBJ_utl_core_apidefs_UX_MT_R		= $(PROJ_OBJ_DIR)\util.core_apidefs.mt.obj
OBJ_utl_be_parse_UX_MT_R				= $(PROJ_OBJ_DIR)\util.be_parse.mt.obj
OBJ_utl_strnlen_UX_MT_R				= $(PROJ_OBJ_DIR)\util.strnlen.mt.obj
OBJ_utl_strnlenp_UX_MT_R				= $(PROJ_OBJ_DIR)\util.strnlen.c++.mt.obj
OBJ_utl_time_UX_MT_R						= $(PROJ_OBJ_DIR)\util.time.mt.obj
OBJ_utl_host_name_UX_MT_R			= $(PROJ_OBJ_DIR)\util.host_name.mt.obj

OBJ_UTIL_UX_MT_R=\
 $(OBJ_utl_api_exit_UX_MT_R)\
 \
 $(OBJ_utl_bailout_UX_MT_R)\
 $(OBJ_utl_dtel2s_UX_MT_R)\
 $(OBJ_utl_init_code_strs_UX_MT_R)\
 $(OBJ_utl_sev_strs_UX_MT_R)\
 $(OBJ_utl_snprintf_UX_MT_R)\
 $(OBJ_utl_strdup_UX_MT_R)\
 $(OBJ_utl_procid_UX_MT_R)\
 $(OBJ_utl_thread_UX_MT_R)\
 $(OBJ_utl_be_context_UX_MT_R)\
 $(OBJ_utl_core_apidefs_UX_MT_R)\
 $(OBJ_utl_be_parse_UX_MT_R)\
 $(OBJ_utl_strnlen_UX_MT_R)\
 $(OBJ_utl_strnlenp_UX_MT_R)\
 $(OBJ_utl_time_UX_MT_R)\
 $(OBJ_utl_host_name_UX_MT_R)\
 \

OBJ_UTIL_UX_MT_R_P=\
 +$(OBJ_utl_api_exit_UX_MT_R)\
 +$(OBJ_utl_bailout_UX_MT_R)\
 +$(OBJ_utl_dtel2s_UX_MT_R)\
 +$(OBJ_utl_init_code_strs_UX_MT_R)\
 +$(OBJ_utl_sev_strs_UX_MT_R)\
 +$(OBJ_utl_snprintf_UX_MT_R)\
 +$(OBJ_utl_strdup_UX_MT_R)\
 +$(OBJ_utl_procid_UX_MT_R)\
 +$(OBJ_utl_thread_UX_MT_R)\
 +$(OBJ_utl_be_context_UX_MT_R)\
 +$(OBJ_utl_core_apidefs_UX_MT_R)\
 +$(OBJ_utl_be_parse_UX_MT_R)\
 +$(OBJ_utl_strnlen_UX_MT_R)\
 +$(OBJ_utl_strnlenp_UX_MT_R)\
 +$(OBJ_utl_time_UX_MT_R)\
 +$(OBJ_utl_host_name_UX_MT_R)\
 \



# appl

!ifdef PANTHEIOS_NO_B64

OBJ_APPL_b64_UX_MT_D						=
OBJ_APPL_b64_UX_MT_D_P					=
OBJ_APPL_b64_UX_MT_D_PM					=
OBJ_APPL_b64_UX_MT_R						=
OBJ_APPL_b64_UX_MT_R_P					=
OBJ_APPL_b64_UX_MT_R_PM					=
!else
OBJ_ins_b64_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.b64.mt.debug.obj
OBJ_APPL_b64_UX_MT_D						= $(OBJ_ins_b64_UX_MT_D)
OBJ_APPL_b64_UX_MT_D_P					= +$(OBJ_ins_b64_UX_MT_D)
OBJ_APPL_b64_UX_MT_D_PM					= -+$(OBJ_ins_b64_UX_MT_D)
OBJ_ins_b64_UX_MT_R						= $(PROJ_OBJ_DIR)\inserters.b64.mt.obj
OBJ_APPL_b64_UX_MT_R						= $(OBJ_ins_b64_UX_MT_R)
OBJ_APPL_b64_UX_MT_R_P					= +$(OBJ_ins_b64_UX_MT_R)
OBJ_APPL_b64_UX_MT_R_PM					= -+$(OBJ_ins_b64_UX_MT_R)
!endif # !PANTHEIOS_NO_B64

OBJ_ins_args_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.args.mt.debug.obj
OBJ_ins_blob_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.blob.mt.debug.obj
OBJ_ins_bool_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.boolean.mt.debug.obj
OBJ_ins_excp_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.exception.mt.debug.obj
OBJ_ins_host_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.hostid.mt.debug.obj
OBJ_ins_int_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.integer.mt.debug.obj
OBJ_ins_ivl_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.interval.mt.debug.obj
OBJ_ins_ptr_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.pointer.mt.debug.obj
OBJ_ins_prid_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.processid.mt.debug.obj
OBJ_ins_real_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.real.mt.debug.obj
OBJ_ins_slice_UX_MT_D					= $(PROJ_OBJ_DIR)\inserters.slice.mt.debug.obj
OBJ_ins_thrid_UX_MT_D					= $(PROJ_OBJ_DIR)\inserters.threadid.mt.debug.obj
OBJ_ins_stm_ch_UX_MT_D					= $(PROJ_OBJ_DIR)\inserters.stream_character.mt.debug.obj
OBJ_ins_w2m_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.w2m.mt.debug.obj

OBJ_APPL_UX_MT_D=\
 $(OBJ_ins_args_UX_MT_D)\
 $(OBJ_APPL_b64_UX_MT_D)\
 $(OBJ_ins_blob_UX_MT_D)\
 $(OBJ_ins_bool_UX_MT_D)\
 $(OBJ_ins_excp_UX_MT_D)\
 $(OBJ_ins_host_UX_MT_D)\
 $(OBJ_ins_int_UX_MT_D)\
 $(OBJ_ins_ivl_UX_MT_D)\
 $(OBJ_ins_ptr_UX_MT_D)\
 $(OBJ_ins_prid_UX_MT_D)\
 $(OBJ_ins_real_UX_MT_D)\
 $(OBJ_ins_slice_UX_MT_D)\
 $(OBJ_ins_thrid_UX_MT_D)\
 $(OBJ_ins_stm_ch_UX_MT_D)\
 $(OBJ_ins_w2m_UX_MT_D)\
 \

OBJ_APPL_UX_MT_D_P=\
 +$(OBJ_ins_args_UX_MT_D)\
 $(OBJ_APPL_b64_UX_MT_D_P)\
 +$(OBJ_ins_blob_UX_MT_D)\
 +$(OBJ_ins_bool_UX_MT_D)\
 +$(OBJ_ins_excp_UX_MT_D)\
 +$(OBJ_ins_host_UX_MT_D)\
 +$(OBJ_ins_int_UX_MT_D)\
 +$(OBJ_ins_ivl_UX_MT_D)\
 +$(OBJ_ins_ptr_UX_MT_D)\
 +$(OBJ_ins_prid_UX_MT_D)\
 +$(OBJ_ins_real_UX_MT_D)\
 +$(OBJ_ins_slice_UX_MT_D)\
 +$(OBJ_ins_thrid_UX_MT_D)\
 +$(OBJ_ins_stm_ch_UX_MT_D)\
 +$(OBJ_ins_w2m_UX_MT_D)\
 \

PDB_ins_args_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.args.mt.debug.pdb
PDB_ins_b64_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.b64.mt.debug.pdb
PDB_ins_blob_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.blob.mt.debug.pdb
PDB_ins_bool_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.boolean.mt.debug.pdb
PDB_ins_excp_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.exception.mt.debug.pdb
PDB_ins_host_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.hostid.mt.debug.pdb
PDB_ins_int_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.integer.mt.debug.pdb
PDB_ins_ivl_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.interval.mt.debug.pdb
PDB_ins_ptr_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.pointer.mt.debug.pdb
PDB_ins_prid_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.processid.mt.debug.pdb
PDB_ins_real_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.real.mt.debug.pdb
PDB_ins_slice_UX_MT_D					= $(PROJ_OBJ_DIR)\inserters.slice.mt.debug.pdb
PDB_ins_thrid_UX_MT_D					= $(PROJ_OBJ_DIR)\inserters.threadid.mt.debug.pdb
PDB_ins_stm_ch_UX_MT_D					= $(PROJ_OBJ_DIR)\inserters.stream_character.mt.debug.pdb
PDB_ins_w2m_UX_MT_D						= $(PROJ_OBJ_DIR)\inserters.w2m.mt.debug.pdb

PDB_APPL_UX_MT_D=\
 $(PDB_cr_api_UX_MT_D)\
 $(PDB_cr_auto_UX_MT_D)\
 $(PDB_cr_logprintf_UX_MT_D)\
 $(PDB_ins_args_UX_MT_D)\
 $(PDB_ins_b64_UX_MT_D)\
 $(PDB_ins_blob_UX_MT_D)\
 $(PDB_ins_bool_UX_MT_D)\
 $(PDB_ins_excp_UX_MT_D)\
 $(PDB_ins_host_UX_MT_D)\
 $(PDB_ins_int_UX_MT_D)\
 $(PDB_ins_ivl_UX_MT_D)\
 $(PDB_ins_ptr_UX_MT_D)\
 $(PDB_ins_prid_UX_MT_D)\
 $(PDB_ins_real_UX_MT_D)\
 $(PDB_ins_slice_UX_MT_D)\
 $(PDB_ins_thrid_UX_MT_D)\
	$(PDB_ins_stm_ch_UX_MT_D)\
 $(PDB_ins_w2m_UX_MT_D)\
 \

OBJ_ins_args_UX_MT_R						= $(PROJ_OBJ_DIR)\inserters.args.mt.obj
OBJ_ins_blob_UX_MT_R						= $(PROJ_OBJ_DIR)\inserters.blob.mt.obj
OBJ_ins_bool_UX_MT_R						= $(PROJ_OBJ_DIR)\inserters.boolean.mt.obj
OBJ_ins_excp_UX_MT_R						= $(PROJ_OBJ_DIR)\inserters.exception.mt.obj
OBJ_ins_host_UX_MT_R						= $(PROJ_OBJ_DIR)\inserters.hostid.mt.obj
OBJ_ins_int_UX_MT_R						= $(PROJ_OBJ_DIR)\inserters.integer.mt.obj
OBJ_ins_ivl_UX_MT_R						= $(PROJ_OBJ_DIR)\inserters.interval.mt.obj
OBJ_ins_ptr_UX_MT_R						= $(PROJ_OBJ_DIR)\inserters.pointer.mt.obj
OBJ_ins_prid_UX_MT_R						= $(PROJ_OBJ_DIR)\inserters.processid.mt.obj
OBJ_ins_real_UX_MT_R						= $(PROJ_OBJ_DIR)\inserters.real.mt.obj
OBJ_ins_slice_UX_MT_R					= $(PROJ_OBJ_DIR)\inserters.slice.mt.obj
OBJ_ins_thrid_UX_MT_R					= $(PROJ_OBJ_DIR)\inserters.threadid.mt.obj
OBJ_ins_stm_ch_UX_MT_R					= $(PROJ_OBJ_DIR)\inserters.stream_character.mt.obj
OBJ_ins_w2m_UX_MT_R						= $(PROJ_OBJ_DIR)\inserters.w2m.mt.obj

OBJ_APPL_UX_MT_R=\
 $(OBJ_ins_args_UX_MT_R)\
 $(OBJ_APPL_b64_UX_MT_R)\
 $(OBJ_ins_blob_UX_MT_R)\
 $(OBJ_ins_bool_UX_MT_R)\
 $(OBJ_ins_excp_UX_MT_R)\
 $(OBJ_ins_host_UX_MT_R)\
 $(OBJ_ins_int_UX_MT_R)\
 $(OBJ_ins_ivl_UX_MT_R)\
 $(OBJ_ins_ptr_UX_MT_R)\
 $(OBJ_ins_prid_UX_MT_R)\
 $(OBJ_ins_real_UX_MT_R)\
 $(OBJ_ins_slice_UX_MT_R)\
 $(OBJ_ins_thrid_UX_MT_R)\
 $(OBJ_ins_stm_ch_UX_MT_R)\
 $(OBJ_ins_w2m_UX_MT_R)\
 \

OBJ_APPL_UX_MT_R_P=\
 +$(OBJ_ins_args_UX_MT_R)\
 $(OBJ_APPL_b64_UX_MT_R_P)\
 +$(OBJ_ins_blob_UX_MT_R)\
 +$(OBJ_ins_bool_UX_MT_R)\
 +$(OBJ_ins_excp_UX_MT_R)\
 +$(OBJ_ins_host_UX_MT_R)\
 +$(OBJ_ins_int_UX_MT_R)\
 +$(OBJ_ins_ivl_UX_MT_R)\
 +$(OBJ_ins_ptr_UX_MT_R)\
 +$(OBJ_ins_prid_UX_MT_R)\
 +$(OBJ_ins_real_UX_MT_R)\
 +$(OBJ_ins_slice_UX_MT_R)\
 +$(OBJ_ins_thrid_UX_MT_R)\
 +$(OBJ_ins_stm_ch_UX_MT_R)\
 +$(OBJ_ins_w2m_UX_MT_R)\
 \



# core

OBJ_cr_api_UX_MT_D							= $(PROJ_OBJ_DIR)\core.api.mt.debug.obj
OBJ_cr_api_dep_UX_MT_D					= $(PROJ_OBJ_DIR)\core.api.deprecated.mt.debug.obj
OBJ_cr_api_logprintf_UX_MT_D		= $(PROJ_OBJ_DIR)\core.api.logprintf.mt.debug.obj
OBJ_cr_api_logputs_UX_MT_D			= $(PROJ_OBJ_DIR)\core.api.logputs.mt.debug.obj
OBJ_cr_auto_UX_MT_D						= $(PROJ_OBJ_DIR)\core.auto.mt.debug.obj

OBJ_CORE_UX_MT_D=\
 $(OBJ_APPL_UX_MT_D)\
 $(OBJ_cr_api_UX_MT_D)\
 $(OBJ_cr_api_dep_UX_MT_D)\
 $(OBJ_cr_api_logprintf_UX_MT_D)\
 $(OBJ_cr_api_logputs_UX_MT_D)\
 $(OBJ_cr_auto_UX_MT_D)\
 \

OBJ_CORE_UX_MT_D_P=\
 $(OBJ_APPL_UX_MT_D_P)\
 +$(OBJ_cr_api_UX_MT_D)\
 +$(OBJ_cr_api_dep_UX_MT_D)\
 +$(OBJ_cr_api_logprintf_UX_MT_D)\
 +$(OBJ_cr_api_logputs_UX_MT_D)\
 +$(OBJ_cr_auto_UX_MT_D)\
 \

PDB_cr_api_UX_MT_D							= $(PROJ_OBJ_DIR)\core.api.mt.debug.pdb
PDB_cr_api_dep_UX_MT_D					= $(PROJ_OBJ_DIR)\core.api.deprecated.mt.debug.pdb
PDB_cr_api_logprintf_UX_MT_D		= $(PROJ_OBJ_DIR)\core.api.logprintf.mt.debug.pdb
PDB_cr_api_logputs_UX_MT_D			= $(PROJ_OBJ_DIR)\core.api.logputs.mt.debug.pdb
PDB_cr_auto_UX_MT_D						= $(PROJ_OBJ_DIR)\core.auto.mt.debug.pdb

PDB_CORE_UX_MT_D=\
 $(PDB_APPL_UX_MT_D)\
 $(PDB_cr_api_UX_MT_D)\
 $(PDB_cr_api_dep_UX_MT_D)\
 $(PDB_cr_api_logprintf_UX_MT_D)\
 $(PDB_cr_api_logputs_UX_MT_D)\
 $(PDB_cr_auto_UX_MT_D)\
 \

OBJ_cr_api_UX_MT_R							= $(PROJ_OBJ_DIR)\core.api.mt.obj
OBJ_cr_api_dep_UX_MT_R					= $(PROJ_OBJ_DIR)\core.api.deprecated.mt.obj
OBJ_cr_api_logprintf_UX_MT_R		= $(PROJ_OBJ_DIR)\core.api.logprintf.mt.obj
OBJ_cr_api_logputs_UX_MT_R			= $(PROJ_OBJ_DIR)\core.api.logputs.mt.obj
OBJ_cr_auto_UX_MT_R						= $(PROJ_OBJ_DIR)\core.auto.mt.obj

OBJ_CORE_UX_MT_R=\
 $(OBJ_APPL_UX_MT_R)\
 $(OBJ_cr_api_UX_MT_R)\
 $(OBJ_cr_api_dep_UX_MT_R)\
 $(OBJ_cr_api_logprintf_UX_MT_R)\
 $(OBJ_cr_api_logputs_UX_MT_R)\
 $(OBJ_cr_auto_UX_MT_R)\
 \

OBJ_CORE_UX_MT_R_P=\
 $(OBJ_APPL_UX_MT_R_P)\
 +$(OBJ_cr_api_UX_MT_R)\
 +$(OBJ_cr_api_dep_UX_MT_R)\
 +$(OBJ_cr_api_logprintf_UX_MT_R)\
 +$(OBJ_cr_api_logputs_UX_MT_R)\
 +$(OBJ_cr_auto_UX_MT_R)\
 \



# front-ends

OBJ_fe_all_UX_MT_D							= $(PROJ_OBJ_DIR)\fe.all.mt.debug.obj
OBJ_fe_all_WC_UX_MT_D					= $(PROJ_OBJ_DIR)\fe.all.WithCallback.mt.debug.obj
OBJ_fe_fail_UX_MT_D						= $(PROJ_OBJ_DIR)\fe.fail.mt.debug.obj
OBJ_fe_N_UX_MT_D								= $(PROJ_OBJ_DIR)\fe.N.mt.debug.obj
OBJ_fe_N_WC_UX_MT_D						= $(PROJ_OBJ_DIR)\fe.N.WithCallback.mt.debug.obj
OBJ_fe_null_UX_MT_D						= $(PROJ_OBJ_DIR)\fe.null.mt.debug.obj
OBJ_fe_null_WC_UX_MT_D					= $(PROJ_OBJ_DIR)\fe.null.WithCallback.mt.debug.obj
OBJ_fe_simple_UX_MT_D					= $(PROJ_OBJ_DIR)\fe.simple.mt.debug.obj
OBJ_fe_simple_WC_UX_MT_D				= $(PROJ_OBJ_DIR)\fe.simple.WithCallback.mt.debug.obj

OBJ_FE_ALL_UX_MT_D							= $(OBJ_fe_all_UX_MT_D)
OBJ_FE_ALL_WC_UX_MT_D					= $(OBJ_fe_all_WC_UX_MT_D)
OBJ_FE_FAIL_UX_MT_D						= $(OBJ_fe_fail_UX_MT_D)
OBJ_FE_N_UX_MT_D								= $(OBJ_fe_N_UX_MT_D)
OBJ_FE_N_WC_UX_MT_D						= $(OBJ_fe_N_WC_UX_MT_D)
OBJ_FE_NULL_UX_MT_D						= $(OBJ_fe_null_UX_MT_D)
OBJ_FE_NULL_WC_UX_MT_D					= $(OBJ_fe_null_WC_UX_MT_D)
OBJ_FE_SIMPLE_UX_MT_D					= $(OBJ_fe_simple_UX_MT_D)
OBJ_FE_SIMPLE_WC_UX_MT_D				= $(OBJ_fe_simple_WC_UX_MT_D)

OBJ_FE_ALL_UX_MT_D_P						= +$(OBJ_fe_all_UX_MT_D)
OBJ_FE_ALL_WC_UX_MT_D_P				= +$(OBJ_fe_all_WC_UX_MT_D)
OBJ_FE_FAIL_UX_MT_D_P					= +$(OBJ_fe_fail_UX_MT_D)
OBJ_FE_N_UX_MT_D_P							= +$(OBJ_fe_N_UX_MT_D)
OBJ_FE_N_WC_UX_MT_D_P					= +$(OBJ_fe_N_WC_UX_MT_D)
OBJ_FE_NULL_UX_MT_D_P					= +$(OBJ_fe_null_UX_MT_D)
OBJ_FE_NULL_WC_UX_MT_D_P				= +$(OBJ_fe_null_WC_UX_MT_D)
OBJ_FE_SIMPLE_UX_MT_D_P				= +$(OBJ_fe_simple_UX_MT_D)
OBJ_FE_SIMPLE_WC_UX_MT_D_P			= +$(OBJ_fe_simple_WC_UX_MT_D)


PDB_fe_all_UX_MT_D							= $(PROJ_OBJ_DIR)\fe.all.mt.debug.pdb
PDB_fe_all_WC_UX_MT_D					= $(PROJ_OBJ_DIR)\fe.all.WithCallback.mt.debug.pdb
PDB_fe_fail_UX_MT_D						= $(PROJ_OBJ_DIR)\fe.fail.mt.debug.pdb
PDB_fe_N_UX_MT_D								= $(PROJ_OBJ_DIR)\fe.N.mt.debug.pdb
PDB_fe_N_WC_UX_MT_D						= $(PROJ_OBJ_DIR)\fe.N.WithCallback.mt.debug.pdb
PDB_fe_null_UX_MT_D						= $(PROJ_OBJ_DIR)\fe.null.mt.debug.pdb
PDB_fe_null_WC_UX_MT_D					= $(PROJ_OBJ_DIR)\fe.null.WithCallback.mt.debug.pdb
PDB_fe_simple_UX_MT_D					= $(PROJ_OBJ_DIR)\fe.simple.mt.debug.pdb
PDB_fe_simple_WC_UX_MT_D				= $(PROJ_OBJ_DIR)\fe.simple.WithCallback.mt.debug.pdb

PDB_FE_UX_MT_D=\
 $(PDB_fe_all_UX_MT_D)\
 $(PDB_fe_all_WC_UX_MT_D)\
 $(PDB_fe_fai_UX_MT_D)\
 $(PDB_fe_N_UX_MT_D)\
 $(PDB_fe_N_WC_UX_MT_D)\
 $(PDB_fe_null_UX_MT_D)\
 $(PDB_fe_null_WC_UX_MT_D)\
 $(PDB_fe_simple_UX_MT_D)\
 $(PDB_fe_simple_WC_UX_MT_D)\
 \

OBJ_fe_all_UX_MT_R							= $(PROJ_OBJ_DIR)\fe.all.mt.obj
OBJ_fe_all_WC_UX_MT_R					= $(PROJ_OBJ_DIR)\fe.all.WithCallback.mt.obj
OBJ_fe_fail_UX_MT_R						= $(PROJ_OBJ_DIR)\fe.fail.mt.obj
OBJ_fe_N_UX_MT_R								= $(PROJ_OBJ_DIR)\fe.N.mt.obj
OBJ_fe_N_WC_UX_MT_R						= $(PROJ_OBJ_DIR)\fe.N.WithCallback.mt.obj
OBJ_fe_null_UX_MT_R						= $(PROJ_OBJ_DIR)\fe.null.mt.obj
OBJ_fe_null_WC_UX_MT_R					= $(PROJ_OBJ_DIR)\fe.null.WithCallback.mt.obj
OBJ_fe_simple_UX_MT_R					= $(PROJ_OBJ_DIR)\fe.simple.mt.obj
OBJ_fe_simple_WC_UX_MT_R				= $(PROJ_OBJ_DIR)\fe.simple.WithCallback.mt.obj

OBJ_FE_ALL_UX_MT_R							= $(OBJ_fe_all_UX_MT_R)
OBJ_FE_ALL_WC_UX_MT_R					= $(OBJ_fe_all_WC_UX_MT_R)
OBJ_FE_FAIL_UX_MT_R						= $(OBJ_fe_fail_UX_MT_R)
OBJ_FE_N_UX_MT_R								= $(OBJ_fe_N_UX_MT_R)
OBJ_FE_N_WC_UX_MT_R						= $(OBJ_fe_N_WC_UX_MT_R)
OBJ_FE_NULL_UX_MT_R						= $(OBJ_fe_null_UX_MT_R)
OBJ_FE_NULL_WC_UX_MT_R					= $(OBJ_fe_null_WC_UX_MT_R)
OBJ_FE_SIMPLE_UX_MT_R					= $(OBJ_fe_simple_UX_MT_R)
OBJ_FE_SIMPLE_WC_UX_MT_R				= $(OBJ_fe_simple_WC_UX_MT_R)

OBJ_FE_ALL_UX_MT_R_P						= +$(OBJ_fe_all_UX_MT_R)
OBJ_FE_ALL_WC_UX_MT_R_P				= +$(OBJ_fe_all_WC_UX_MT_R)
OBJ_FE_FAIL_UX_MT_R_P					= +$(OBJ_fe_fail_UX_MT_R)
OBJ_FE_N_UX_MT_R_P							= +$(OBJ_fe_N_UX_MT_R)
OBJ_FE_N_WC_UX_MT_R_P					= +$(OBJ_fe_N_WC_UX_MT_R)
OBJ_FE_NULL_UX_MT_R_P					= +$(OBJ_fe_null_UX_MT_R)
OBJ_FE_NULL_WC_UX_MT_R_P				= +$(OBJ_fe_null_WC_UX_MT_R)
OBJ_FE_SIMPLE_UX_MT_R_P				= +$(OBJ_fe_simple_UX_MT_R)
OBJ_FE_SIMPLE_WC_UX_MT_R_P			= +$(OBJ_fe_simple_WC_UX_MT_R)



# back-ends

OBJ_be_lrsplit_UX_MT_D					= $(PROJ_OBJ_DIR)\be.lrsplit.mt.debug.obj
OBJ_be_N_UX_MT_D								= $(PROJ_OBJ_DIR)\be.N.mt.debug.obj

OBJ_bec_fail_UX_MT_D						= $(PROJ_OBJ_DIR)\bec.fail.mt.debug.obj
OBJ_be_fail_UX_MT_D						= $(PROJ_OBJ_DIR)\be.fail.mt.debug.obj
OBJ_bel_fail_UX_MT_D						= $(PROJ_OBJ_DIR)\bel.fail.mt.debug.obj
OBJ_ber_fail_UX_MT_D						= $(PROJ_OBJ_DIR)\ber.fail.mt.debug.obj
OBJ_bec_file_UX_MT_D						= $(PROJ_OBJ_DIR)\bec.file.mt.debug.obj
OBJ_bec_file_WC_UX_MT_D				= $(PROJ_OBJ_DIR)\bec.file.WithCallback.mt.debug.obj
OBJ_be_file_UX_MT_D						= $(PROJ_OBJ_DIR)\be.file.mt.debug.obj
OBJ_bel_file_UX_MT_D						= $(PROJ_OBJ_DIR)\bel.file.mt.debug.obj
OBJ_ber_file_UX_MT_D						= $(PROJ_OBJ_DIR)\ber.file.mt.debug.obj
OBJ_bec_fprintf_UX_MT_D				= $(PROJ_OBJ_DIR)\bec.fprintf.mt.debug.obj
OBJ_bec_fprintf_WC_UX_MT_D			= $(PROJ_OBJ_DIR)\bec.fprintf.WithCallback.mt.debug.obj
OBJ_be_fprintf_UX_MT_D					= $(PROJ_OBJ_DIR)\be.fprintf.mt.debug.obj
OBJ_bel_fprintf_UX_MT_D				= $(PROJ_OBJ_DIR)\bel.fprintf.mt.debug.obj
OBJ_ber_fprintf_UX_MT_D				= $(PROJ_OBJ_DIR)\ber.fprintf.mt.debug.obj
OBJ_bec_null_UX_MT_D						= $(PROJ_OBJ_DIR)\bec.null.mt.debug.obj
OBJ_be_null_UX_MT_D						= $(PROJ_OBJ_DIR)\be.null.mt.debug.obj
OBJ_bel_null_UX_MT_D						= $(PROJ_OBJ_DIR)\bel.null.mt.debug.obj
OBJ_ber_null_UX_MT_D						= $(PROJ_OBJ_DIR)\ber.null.mt.debug.obj
OBJ_bec_test_UX_MT_D						= $(PROJ_OBJ_DIR)\bec.test.mt.debug.obj
OBJ_be_test_UX_MT_D						= $(PROJ_OBJ_DIR)\be.test.mt.debug.obj
OBJ_bel_test_UX_MT_D						= $(PROJ_OBJ_DIR)\bel.test.mt.debug.obj
OBJ_ber_test_UX_MT_D						= $(PROJ_OBJ_DIR)\ber.test.mt.debug.obj

!ifdef ACE
OBJ_bec_ACE_UX_MT_D						= $(PROJ_OBJ_DIR)\bec.ACE.mt.debug.obj
OBJ_be_ACE_UX_MT_D							= $(PROJ_OBJ_DIR)\be.ACE.mt.debug.obj
OBJ_bel_ACE_UX_MT_D						= $(PROJ_OBJ_DIR)\bel.ACE.mt.debug.obj
OBJ_ber_ACE_UX_MT_D						= $(PROJ_OBJ_DIR)\ber.ACE.mt.debug.obj
!endif # ACE
OBJ_bec_SYSLOG_UX_MT_D					= $(PROJ_OBJ_DIR)\bec.syslog.mt.debug.obj
OBJ_bec_SYSLOG_WC_UX_MT_D			= $(PROJ_OBJ_DIR)\bec.syslog.WithCallback.mt.debug.obj
OBJ_be_SYSLOG_UX_MT_D					= $(PROJ_OBJ_DIR)\be.syslog.mt.debug.obj
OBJ_ber_SYSLOG_UX_MT_D					= $(PROJ_OBJ_DIR)\ber.syslog.mt.debug.obj


OBJ_BE_LRSPLIT_UX_MT_D					= $(OBJ_be_lrsplit_UX_MT_D)
OBJ_BE_N_UX_MT_D								= $(OBJ_be_N_UX_MT_D)

OBJ_BEC_FAIL_UX_MT_D						= $(OBJ_bec_fail_UX_MT_D)
OBJ_BE_FAIL_UX_MT_D						= $(OBJ_be_fail_UX_MT_D)
OBJ_BEL_FAIL_UX_MT_D						= $(OBJ_bel_fail_UX_MT_D)
OBJ_BER_FAIL_UX_MT_D						= $(OBJ_ber_fail_UX_MT_D)
OBJ_BEC_FILE_UX_MT_D						= $(OBJ_bec_file_UX_MT_D)
OBJ_BEC_FILE_WC_UX_MT_D				= $(OBJ_bec_file_WC_UX_MT_D)
OBJ_BE_FILE_UX_MT_D						= $(OBJ_be_file_UX_MT_D)
OBJ_BEL_FILE_UX_MT_D						= $(OBJ_bel_file_UX_MT_D)
OBJ_BER_FILE_UX_MT_D						= $(OBJ_ber_file_UX_MT_D)
OBJ_BEC_FPRINTF_UX_MT_D				= $(OBJ_bec_fprintf_UX_MT_D)
OBJ_BEC_FPRINTF_WC_UX_MT_D			= $(OBJ_bec_fprintf_WC_UX_MT_D)
OBJ_BE_FPRINTF_UX_MT_D					= $(OBJ_be_fprintf_UX_MT_D)
OBJ_BEL_FPRINTF_UX_MT_D				= $(OBJ_bel_fprintf_UX_MT_D)
OBJ_BER_FPRINTF_UX_MT_D				= $(OBJ_ber_fprintf_UX_MT_D)
OBJ_BEC_NULL_UX_MT_D						= $(OBJ_bec_null_UX_MT_D)
OBJ_BE_NULL_UX_MT_D						= $(OBJ_be_null_UX_MT_D)
OBJ_BEL_NULL_UX_MT_D						= $(OBJ_bel_null_UX_MT_D)
OBJ_BER_NULL_UX_MT_D						= $(OBJ_ber_null_UX_MT_D)
OBJ_BEC_TEST_UX_MT_D						= $(OBJ_bec_test_UX_MT_D)
OBJ_BE_TEST_UX_MT_D						= $(OBJ_be_test_UX_MT_D)
OBJ_BEL_TEST_UX_MT_D						= $(OBJ_bel_test_UX_MT_D)
OBJ_BER_TEST_UX_MT_D						= $(OBJ_ber_test_UX_MT_D)


OBJ_BE_LRSPLIT_UX_MT_D_P				= +$(OBJ_be_lrsplit_UX_MT_D)
OBJ_BE_N_UX_MT_D_P							=	+$(OBJ_be_N_UX_MT_D)

OBJ_BEC_TEST_UX_MT_D_P					=	+$(OBJ_bec_test_UX_MT_D)
OBJ_BE_TEST_UX_MT_D_P					= +$(OBJ_be_test_UX_MT_D)
OBJ_BEL_TEST_UX_MT_D_P					= +$(OBJ_bel_test_UX_MT_D)
OBJ_BER_TEST_UX_MT_D_P					= +$(OBJ_ber_test_UX_MT_D)
OBJ_BEC_FAIL_UX_MT_D_P					= +$(OBJ_bec_fail_UX_MT_D)
OBJ_BE_FAIL_UX_MT_D_P					= +$(OBJ_be_fail_UX_MT_D)
OBJ_BEL_FAIL_UX_MT_D_P					= +$(OBJ_bel_fail_UX_MT_D)
OBJ_BER_FAIL_UX_MT_D_P					= +$(OBJ_ber_fail_UX_MT_D)
OBJ_BEC_FILE_UX_MT_D_P					= +$(OBJ_bec_file_UX_MT_D)
OBJ_BEC_FILE_WC_UX_MT_D_P			= +$(OBJ_bec_file_WC_UX_MT_D)
OBJ_BE_FILE_UX_MT_D_P					= +$(OBJ_be_file_UX_MT_D)
OBJ_BEL_FILE_UX_MT_D_P					= +$(OBJ_bel_file_UX_MT_D)
OBJ_BER_FILE_UX_MT_D_P					= +$(OBJ_ber_file_UX_MT_D)
OBJ_BEC_FPRINTF_UX_MT_D_P			= +$(OBJ_bec_fprintf_UX_MT_D)
OBJ_BEC_FPRINTF_WC_UX_MT_D_P		= +$(OBJ_bec_fprintf_WC_UX_MT_D)
OBJ_BE_FPRINTF_UX_MT_D_P				= +$(OBJ_be_fprintf_UX_MT_D)
OBJ_BEL_FPRINTF_UX_MT_D_P			= +$(OBJ_bel_fprintf_UX_MT_D)
OBJ_BER_FPRINTF_UX_MT_D_P			= +$(OBJ_ber_fprintf_UX_MT_D)
OBJ_BEC_NULL_UX_MT_D_P					= +$(OBJ_bec_null_UX_MT_D)
OBJ_BE_NULL_UX_MT_D_P					= +$(OBJ_be_null_UX_MT_D)
OBJ_BEL_NULL_UX_MT_D_P					= +$(OBJ_bel_null_UX_MT_D)
OBJ_BER_NULL_UX_MT_D_P					= +$(OBJ_ber_null_UX_MT_D)


!ifdef ACE
OBJ_BEC_ACE_UX_MT_D						= $(OBJ_bec_ACE_UX_MT_D)
OBJ_BE_ACE_UX_MT_D							= $(OBJ_be_ACE_UX_MT_D)
OBJ_BEL_ACE_UX_MT_D						= $(OBJ_bel_ACE_UX_MT_D)
OBJ_BER_ACE_UX_MT_D						= $(OBJ_ber_ACE_UX_MT_D)

OBJ_BEC_ACE_UX_MT_D_P					= +$(OBJ_bec_ACE_UX_MT_D)
OBJ_BE_ACE_UX_MT_D_P						= +$(OBJ_be_ACE_UX_MT_D)
OBJ_BEL_ACE_UX_MT_D_P					= +$(OBJ_bel_ACE_UX_MT_D)
OBJ_BER_ACE_UX_MT_D_P					= +$(OBJ_ber_ACE_UX_MT_D)

OBJ_BEC_ACE_UX_MT_D_PM					= -+$(OBJ_bec_ACE_UX_MT_D)
OBJ_BE_ACE_UX_MT_D_PM					= -+$(OBJ_be_ACE_UX_MT_D)
OBJ_BEL_ACE_UX_MT_D_PM					= -+$(OBJ_bel_ACE_UX_MT_D)
OBJ_BER_ACE_UX_MT_D_PM					= -+$(OBJ_ber_ACE_UX_MT_D)

!endif # ACE

OBJ_BEC_SYSLOG_UX_MT_D					= $(OBJ_bec_SYSLOG_UX_MT_D)
OBJ_BEC_SYSLOGWC_UX_MT_D				= $(OBJ_bec_SYSLOG_WC_UX_MT_D)
OBJ_BE_SYSLOG_UX_MT_D					= $(OBJ_be_SYSLOG_UX_MT_D)
OBJ_BER_SYSLOG_UX_MT_D					= $(OBJ_ber_SYSLOG_UX_MT_D)


OBJ_BEC_SYSLOG_UX_MT_D_P					= +$(OBJ_bec_SYSLOG_UX_MT_D)
OBJ_BEC_SYSLOGWC_UX_MT_D_P					= +$(OBJ_bec_SYSLOG_WC_UX_MT_D)
OBJ_BE_SYSLOG_UX_MT_D_P					= +$(OBJ_be_SYSLOG_UX_MT_D)
OBJ_BER_SYSLOG_UX_MT_D_P					= +$(OBJ_ber_SYSLOG_UX_MT_D)




OBJ_BEC_STOCK_UX_MT_D=\
 $(OBJ_bec_fail_UX_MT_D)\
 $(OBJ_bec_file_UX_MT_D)\
 $(OBJ_bec_fprintf_UX_MT_D)\
 $(OBJ_bec_null_UX_MT_D)\
 $(OBJ_bec_SYSLOG_UX_MT_D)\
 \

OBJ_BEC_STOCK_WC_UX_MT_D_P=\
 $(OBJ_bec_fail_UX_MT_D_P)\
 $(OBJ_bec_file_WC_UX_MT_D_P)\
 $(OBJ_bec_fprintf_WC_UX_MT_D_P)\
 $(OBJ_bec_null_UX_MT_D_P)\
 $(OBJ_bec_SYSLOG_WC_UX_MT_D_P)\
 \

OBJ_BEC_STOCK_WC_UX_MT_D=\
 $(OBJ_bec_fail_UX_MT_D)\
 $(OBJ_bec_file_WC_UX_MT_D)\
 $(OBJ_bec_fprintf_WC_UX_MT_D)\
 $(OBJ_bec_null_UX_MT_D)\
 $(OBJ_bec_SYSLOG_WC_UX_MT_D)\
 \

OBJ_BEC_STOCK_UX_MT_D_P=\
 $(OBJ_bec_fail_UX_MT_D_P)\
 $(OBJ_bec_file_UX_MT_D_P)\
 $(OBJ_bec_fprintf_UX_MT_D_P)\
 $(OBJ_bec_null_UX_MT_D_P)\
 $(OBJ_bec_SYSLOG_UX_MT_D_P)\
 \

PDB_be_lrsplit_UX_MT_D					= $(PROJ_OBJ_DIR)\be.lrsplit.mt.debug.pdb
PDB_be_N_UX_MT_D								= $(PROJ_OBJ_DIR)\be.N.mt.debug.pdb

PDB_bec_fail_UX_MT_D						= $(PROJ_OBJ_DIR)\bec.fail.mt.debug.pdb
PDB_be_fail_UX_MT_D						= $(PROJ_OBJ_DIR)\be.fail.mt.debug.pdb
PDB_bel_fail_UX_MT_D						= $(PROJ_OBJ_DIR)\bel.fail.mt.debug.pdb
PDB_ber_fail_UX_MT_D						= $(PROJ_OBJ_DIR)\ber.fail.mt.debug.pdb
PDB_bec_file_UX_MT_D						= $(PROJ_OBJ_DIR)\bec.file.mt.debug.pdb
PDB_bec_file_WC_UX_MT_D				= $(PROJ_OBJ_DIR)\bec.file.WithCallback.mt.debug.pdb
PDB_be_file_UX_MT_D						= $(PROJ_OBJ_DIR)\be.file.mt.debug.pdb
PDB_bel_file_UX_MT_D						= $(PROJ_OBJ_DIR)\bel.file.mt.debug.pdb
PDB_ber_file_UX_MT_D						= $(PROJ_OBJ_DIR)\ber.file.mt.debug.pdb
PDB_bec_fprintf_UX_MT_D				= $(PROJ_OBJ_DIR)\bec.fprintf.mt.debug.pdb
PDB_bec_fprintf_WC_UX_MT_D			= $(PROJ_OBJ_DIR)\bec.fprintf.WithCallback.mt.debug.pdb
PDB_be_fprintf_UX_MT_D					= $(PROJ_OBJ_DIR)\be.fprintf.mt.debug.pdb
PDB_bel_fprintf_UX_MT_D				= $(PROJ_OBJ_DIR)\bel.fprintf.mt.debug.pdb
PDB_ber_fprintf_UX_MT_D				= $(PROJ_OBJ_DIR)\ber.fprintf.mt.debug.pdb
PDB_bec_null_UX_MT_D						= $(PROJ_OBJ_DIR)\bec.null.mt.debug.pdb
PDB_be_null_UX_MT_D						= $(PROJ_OBJ_DIR)\be.null.mt.debug.pdb
PDB_bel_null_UX_MT_D						= $(PROJ_OBJ_DIR)\bel.null.mt.debug.pdb
PDB_ber_null_UX_MT_D						= $(PROJ_OBJ_DIR)\ber.null.mt.debug.pdb
PDB_bec_test_UX_MT_D						= $(PROJ_OBJ_DIR)\bec.test.mt.debug.pdb
PDB_be_test_UX_MT_D						= $(PROJ_OBJ_DIR)\be.test.mt.debug.pdb
PDB_bel_test_UX_MT_D						= $(PROJ_OBJ_DIR)\bel.test.mt.debug.pdb
PDB_ber_test_UX_MT_D						= $(PROJ_OBJ_DIR)\ber.test.mt.debug.pdb

!ifdef ACE
PDB_bec_ACE_UX_MT_D						= $(PROJ_OBJ_DIR)\bec.ACE.mt.debug.pdb
PDB_be_ACE_UX_MT_D							= $(PROJ_OBJ_DIR)\be.ACE.mt.debug.pdb
PDB_bel_ACE_UX_MT_D						= $(PROJ_OBJ_DIR)\bel.ACE.mt.debug.pdb
PDB_ber_ACE_UX_MT_D						= $(PROJ_OBJ_DIR)\ber.ACE.mt.debug.pdb
!endif # ACE

PDB_bec_SYSLOG_UX_MT_D					= $(PROJ_OBJ_DIR)\bec.syslog.mt.debug.pdb
PDB_bec_SYSLOG_WC_UX_MT_D			= $(PROJ_OBJ_DIR)\bec.syslog.WithCallback.mt.debug.pdb
PDB_be_SYSLOG_UX_MT_D					= $(PROJ_OBJ_DIR)\be.syslog.mt.debug.pdb
PDB_ber_SYSLOG_UX_MT_D					= $(PROJ_OBJ_DIR)\ber.syslog.mt.debug.pdb


PDB_BE_UX_MT_D=\
 $(PDB_be_lrsplit_UX_MT_D)\
 $(PDB_be_N_UX_MT_D)\
 \
 $(PDB_bec_fail_UX_MT_D)\
 $(PDB_be_fail_UX_MT_D)\
 $(PDB_bel_fail_UX_MT_D)\
 $(PDB_ber_fail_UX_MT_D)\
 $(PDB_bec_file_UX_MT_D)\
 $(PDB_bec_file_WC_UX_MT_D)\
 $(PDB_be_file_UX_MT_D)\
 $(PDB_bel_file_UX_MT_D)\
 $(PDB_ber_file_UX_MT_D)\
 $(PDB_bec_fprintf_UX_MT_D)\
 $(PDB_bec_fprintf_WC_UX_MT_D)\
 $(PDB_be_fprintf_UX_MT_D)\
 $(PDB_bel_fprintf_UX_MT_D)\
 $(PDB_ber_fprintf_UX_MT_D)\
 $(PDB_bec_null_UX_MT_D)\
 $(PDB_be_null_UX_MT_D)\
 $(PDB_bel_null_UX_MT_D)\
 $(PDB_ber_null_UX_MT_D)\
 $(PDB_bec_test_UX_MT_D)\
 $(PDB_be_test_UX_MT_D)\
 $(PDB_bel_test_UX_MT_D)\
 $(PDB_ber_test_UX_MT_D)\
!ifdef ACE
 $(PDB_bec_ACE_UX_MT_D)\
 $(PDB_be_ACE_UX_MT_D)\
 $(PDB_bel_ACE_UX_MT_D)\
 $(PDB_ber_ACE_UX_MT_D)\
!endif # ACE
 $(PDB_bec_SYSLOG_UX_MT_D)\
 $(PDB_bec_SYSLOG_WC_UX_MT_D)\
 $(PDB_be_SYSLOG_UX_MT_D)\
 $(PDB_ber_SYSLOG_UX_MT_D)\
 \

OBJ_be_lrsplit_UX_MT_R					= $(PROJ_OBJ_DIR)\be.lrsplit.mt.obj
OBJ_be_N_UX_MT_R								= $(PROJ_OBJ_DIR)\be.N.mt.obj

OBJ_bec_fail_UX_MT_R						= $(PROJ_OBJ_DIR)\bec.fail.mt.obj
OBJ_be_fail_UX_MT_R						= $(PROJ_OBJ_DIR)\be.fail.mt.obj
OBJ_bel_fail_UX_MT_R						= $(PROJ_OBJ_DIR)\bel.fail.mt.obj
OBJ_ber_fail_UX_MT_R						= $(PROJ_OBJ_DIR)\ber.fail.mt.obj
OBJ_bec_file_UX_MT_R						= $(PROJ_OBJ_DIR)\bec.file.mt.obj
OBJ_bec_file_WC_UX_MT_R				= $(PROJ_OBJ_DIR)\bec.file.WithCallback.mt.obj
OBJ_be_file_UX_MT_R						= $(PROJ_OBJ_DIR)\be.file.mt.obj
OBJ_bel_file_UX_MT_R						= $(PROJ_OBJ_DIR)\bel.file.mt.obj
OBJ_ber_file_UX_MT_R						= $(PROJ_OBJ_DIR)\ber.file.mt.obj
OBJ_bec_fprintf_UX_MT_R				= $(PROJ_OBJ_DIR)\bec.fprintf.mt.obj
OBJ_bec_fprintf_WC_UX_MT_R			= $(PROJ_OBJ_DIR)\bec.fprintf.WithCallback.mt.obj
OBJ_be_fprintf_UX_MT_R					= $(PROJ_OBJ_DIR)\be.fprintf.mt.obj
OBJ_bel_fprintf_UX_MT_R				= $(PROJ_OBJ_DIR)\bel.fprintf.mt.obj
OBJ_ber_fprintf_UX_MT_R				= $(PROJ_OBJ_DIR)\ber.fprintf.mt.obj
OBJ_bec_null_UX_MT_R						= $(PROJ_OBJ_DIR)\bec.null.mt.obj
OBJ_be_null_UX_MT_R						= $(PROJ_OBJ_DIR)\be.null.mt.obj
OBJ_bel_null_UX_MT_R						= $(PROJ_OBJ_DIR)\bel.null.mt.obj
OBJ_ber_null_UX_MT_R						= $(PROJ_OBJ_DIR)\ber.null.mt.obj
OBJ_bec_test_UX_MT_R						= $(PROJ_OBJ_DIR)\bec.test.mt.obj
OBJ_be_test_UX_MT_R						= $(PROJ_OBJ_DIR)\be.test.mt.obj
OBJ_bel_test_UX_MT_R						= $(PROJ_OBJ_DIR)\bel.test.mt.obj
OBJ_ber_test_UX_MT_R						= $(PROJ_OBJ_DIR)\ber.test.mt.obj

!ifdef ACE
OBJ_bec_ACE_UX_MT_R						= $(PROJ_OBJ_DIR)\bec.ACE.mt.obj
OBJ_be_ACE_UX_MT_R							= $(PROJ_OBJ_DIR)\be.ACE.mt.obj
OBJ_bel_ACE_UX_MT_R						= $(PROJ_OBJ_DIR)\bel.ACE.mt.obj
OBJ_ber_ACE_UX_MT_R						= $(PROJ_OBJ_DIR)\ber.ACE.mt.obj
!endif # ACE
OBJ_bec_SYSLOG_UX_MT_R					= $(PROJ_OBJ_DIR)\bec.syslog.mt.obj
OBJ_bec_SYSLOG_WC_UX_MT_R			= $(PROJ_OBJ_DIR)\bec.syslog.WithCallback.mt.obj
OBJ_be_SYSLOG_UX_MT_R					= $(PROJ_OBJ_DIR)\be.syslog.mt.obj
OBJ_ber_SYSLOG_UX_MT_R					= $(PROJ_OBJ_DIR)\ber.syslog.mt.obj


OBJ_BE_LRSPLIT_UX_MT_R					= $(OBJ_be_lrsplit_UX_MT_R)
OBJ_BE_N_UX_MT_R								= $(OBJ_be_N_UX_MT_R)

OBJ_BEC_FAIL_UX_MT_R						= $(OBJ_bec_fail_UX_MT_R)
OBJ_BE_FAIL_UX_MT_R						= $(OBJ_be_fail_UX_MT_R)
OBJ_BEL_FAIL_UX_MT_R						= $(OBJ_bel_fail_UX_MT_R)
OBJ_BER_FAIL_UX_MT_R						= $(OBJ_ber_fail_UX_MT_R)
OBJ_BEC_FILE_UX_MT_R						= $(OBJ_bec_file_UX_MT_R)
OBJ_BEC_FILE_WC_UX_MT_R				= $(OBJ_bec_file_WC_UX_MT_R)
OBJ_BE_FILE_UX_MT_R						= $(OBJ_be_file_UX_MT_R)
OBJ_BEL_FILE_UX_MT_R						= $(OBJ_bel_file_UX_MT_R)
OBJ_BER_FILE_UX_MT_R						= $(OBJ_ber_file_UX_MT_R)
OBJ_BEC_FPRINTF_UX_MT_R				= $(OBJ_bec_fprintf_UX_MT_R)
OBJ_BEC_FPRINTF_WC_UX_MT_R			= $(OBJ_bec_fprintf_WC_UX_MT_R)
OBJ_BE_FPRINTF_UX_MT_R					= $(OBJ_be_fprintf_UX_MT_R)
OBJ_BEL_FPRINTF_UX_MT_R				= $(OBJ_bel_fprintf_UX_MT_R)
OBJ_BER_FPRINTF_UX_MT_R				= $(OBJ_ber_fprintf_UX_MT_R)
OBJ_BEC_NULL_UX_MT_R						= $(OBJ_bec_null_UX_MT_R)
OBJ_BE_NULL_UX_MT_R						= $(OBJ_be_null_UX_MT_R)
OBJ_BEL_NULL_UX_MT_R						= $(OBJ_bel_null_UX_MT_R)
OBJ_BER_NULL_UX_MT_R						= $(OBJ_ber_null_UX_MT_R)
OBJ_BEC_TEST_UX_MT_R						= $(OBJ_bec_test_UX_MT_R)
OBJ_BE_TEST_UX_MT_R						= $(OBJ_be_test_UX_MT_R)
OBJ_BEL_TEST_UX_MT_R						= $(OBJ_bel_test_UX_MT_R)
OBJ_BER_TEST_UX_MT_R						= $(OBJ_ber_test_UX_MT_R)


OBJ_BE_LRSPLIT_UX_MT_R_P				= +$(OBJ_be_lrsplit_UX_MT_R)
OBJ_BE_N_UX_MT_R_P							=	+$(OBJ_be_N_UX_MT_R)

OBJ_BEC_TEST_UX_MT_R_P					=	+$(OBJ_bec_test_UX_MT_R)
OBJ_BE_TEST_UX_MT_R_P					= +$(OBJ_be_test_UX_MT_R)
OBJ_BEL_TEST_UX_MT_R_P					= +$(OBJ_bel_test_UX_MT_R)
OBJ_BER_TEST_UX_MT_R_P					= +$(OBJ_ber_test_UX_MT_R)
OBJ_BEC_FAIL_UX_MT_R_P					= +$(OBJ_bec_fail_UX_MT_R)
OBJ_BE_FAIL_UX_MT_R_P					= +$(OBJ_be_fail_UX_MT_R)
OBJ_BEL_FAIL_UX_MT_R_P					= +$(OBJ_bel_fail_UX_MT_R)
OBJ_BER_FAIL_UX_MT_R_P					= +$(OBJ_ber_fail_UX_MT_R)
OBJ_BEC_FILE_UX_MT_R_P					= +$(OBJ_bec_file_UX_MT_R)
OBJ_BEC_FILE_WC_UX_MT_R_P			= +$(OBJ_bec_file_WC_UX_MT_R)
OBJ_BE_FILE_UX_MT_R_P					= +$(OBJ_be_file_UX_MT_R)
OBJ_BEL_FILE_UX_MT_R_P					= +$(OBJ_bel_file_UX_MT_R)
OBJ_BER_FILE_UX_MT_R_P					= +$(OBJ_ber_file_UX_MT_R)
OBJ_BEC_FPRINTF_UX_MT_R_P			= +$(OBJ_bec_fprintf_UX_MT_R)
OBJ_BEC_FPRINTF_WC_UX_MT_R_P		= +$(OBJ_bec_fprintf_WC_UX_MT_R)
OBJ_BE_FPRINTF_UX_MT_R_P				= +$(OBJ_be_fprintf_UX_MT_R)
OBJ_BEL_FPRINTF_UX_MT_R_P			= +$(OBJ_bel_fprintf_UX_MT_R)
OBJ_BER_FPRINTF_UX_MT_R_P			= +$(OBJ_ber_fprintf_UX_MT_R)
OBJ_BEC_NULL_UX_MT_R_P					= +$(OBJ_bec_null_UX_MT_R)
OBJ_BE_NULL_UX_MT_R_P					= +$(OBJ_be_null_UX_MT_R)
OBJ_BEL_NULL_UX_MT_R_P					= +$(OBJ_bel_null_UX_MT_R)
OBJ_BER_NULL_UX_MT_R_P					= +$(OBJ_ber_null_UX_MT_R)


!ifdef ACE
OBJ_BEC_ACE_UX_MT_R						= $(OBJ_bec_ACE_UX_MT_R)
OBJ_BE_ACE_UX_MT_R							= $(OBJ_be_ACE_UX_MT_R)
OBJ_BEL_ACE_UX_MT_R						= $(OBJ_bel_ACE_UX_MT_R)
OBJ_BER_ACE_UX_MT_R						= $(OBJ_ber_ACE_UX_MT_R)

OBJ_BEC_ACE_UX_MT_R_P					= +$(OBJ_bec_ACE_UX_MT_R)
OBJ_BE_ACE_UX_MT_R_P						= +$(OBJ_be_ACE_UX_MT_R)
OBJ_BEL_ACE_UX_MT_R_P					= +$(OBJ_bel_ACE_UX_MT_R)
OBJ_BER_ACE_UX_MT_R_P					= +$(OBJ_ber_ACE_UX_MT_R)

OBJ_BEC_ACE_UX_MT_R_PM					= -+$(OBJ_bec_ACE_UX_MT_R)
OBJ_BE_ACE_UX_MT_R_PM					= -+$(OBJ_be_ACE_UX_MT_R)
OBJ_BEL_ACE_UX_MT_R_PM					= -+$(OBJ_bel_ACE_UX_MT_R)
OBJ_BER_ACE_UX_MT_R_PM					= -+$(OBJ_ber_ACE_UX_MT_R)

!endif # ACE

OBJ_BEC_SYSLOG_UX_MT_R					= $(OBJ_bec_SYSLOG_UX_MT_R)
OBJ_BEC_SYSLOGWC_UX_MT_R				= $(OBJ_bec_SYSLOG_WC_UX_MT_R)
OBJ_BE_SYSLOG_UX_MT_R					= $(OBJ_be_SYSLOG_UX_MT_R)
OBJ_BER_SYSLOG_UX_MT_R					= $(OBJ_ber_SYSLOG_UX_MT_R)


OBJ_BEC_SYSLOG_UX_MT_R_P					= +$(OBJ_bec_SYSLOG_UX_MT_R)
OBJ_BEC_SYSLOGWC_UX_MT_R_P					= +$(OBJ_bec_SYSLOG_WC_UX_MT_R)
OBJ_BE_SYSLOG_UX_MT_R_P					= +$(OBJ_be_SYSLOG_UX_MT_R)
OBJ_BER_SYSLOG_UX_MT_R_P					= +$(OBJ_ber_SYSLOG_UX_MT_R)




OBJ_BEC_STOCK_UX_MT_R=\
 $(OBJ_bec_fail_UX_MT_R)\
 $(OBJ_bec_file_UX_MT_R)\
 $(OBJ_bec_fprintf_UX_MT_R)\
 $(OBJ_bec_null_UX_MT_R)\
 $(OBJ_bec_SYSLOG_UX_MT_R)\
 \

OBJ_BEC_STOCK_WC_UX_MT_R_P=\
 $(OBJ_bec_fail_UX_MT_R_P)\
 $(OBJ_bec_file_WC_UX_MT_R_P)\
 $(OBJ_bec_fprintf_WC_UX_MT_R_P)\
 $(OBJ_bec_null_UX_MT_R_P)\
 $(OBJ_bec_SYSLOG_WC_UX_MT_R_P)\
 \

OBJ_BEC_STOCK_WC_UX_MT_R=\
 $(OBJ_bec_fail_UX_MT_R)\
 $(OBJ_bec_file_WC_UX_MT_R)\
 $(OBJ_bec_fprintf_WC_UX_MT_R)\
 $(OBJ_bec_null_UX_MT_R)\
 $(OBJ_bec_SYSLOG_WC_UX_MT_R)\
 \

OBJ_BEC_STOCK_UX_MT_R_P=\
 $(OBJ_bec_fail_UX_MT_R_P)\
 $(OBJ_bec_file_UX_MT_R_P)\
 $(OBJ_bec_fprintf_UX_MT_R_P)\
 $(OBJ_bec_null_UX_MT_R_P)\
 $(OBJ_bec_SYSLOG_UX_MT_R_P)\
 \



# b64

!ifndef PANTHEIOS_NO_B64

OBJ_b64_b64_UX_MT_D            = $(PROJ_OBJ_DIR)\b64.pan.b64.mt.debug.obj
PDB_b64_b64_UX_MT_D            = $(PROJ_OBJ_DIR)\b64.pan.b64.mt.debug.pdb

OBJ_B64_UX_MT_D=\
 $(OBJ_b64_b64_UX_MT_D)\
 \

PDB_SHWILD_UX_MT_D=\
 $(PDB_b64_b64_UX_MT_D)\
 \

OBJ_b64_b64_UX_MT_R            = $(PROJ_OBJ_DIR)\b64.pan.b64.mt.obj

OBJ_B64_UX_MT_R=\
 $(OBJ_b64_b64_UX_MT_R)\
 \

!endif # !PANTHEIOS_NO_B64

# shwild

OBJ_shw_api_UX_MT_D            = $(PROJ_OBJ_DIR)\shwild.pan.api.mt.debug.obj
OBJ_shw_matches_UX_MT_D        = $(PROJ_OBJ_DIR)\shwild.pan.matches.mt.debug.obj
OBJ_shw_pattern_UX_MT_D        = $(PROJ_OBJ_DIR)\shwild.pan.pattern.mt.debug.obj
PDB_shw_api_UX_MT_D            = $(PROJ_OBJ_DIR)\shwild.pan.api.mt.debug.pdb
PDB_shw_matches_UX_MT_D        = $(PROJ_OBJ_DIR)\shwild.pan.matches.mt.debug.pdb
PDB_shw_pattern_UX_MT_D        = $(PROJ_OBJ_DIR)\shwild.pan.pattern.mt.debug.pdb

OBJ_SHWILD_UX_MT_D=\
 $(OBJ_shw_api_UX_MT_D)\
 $(OBJ_shw_matches_UX_MT_D)\
 $(OBJ_shw_pattern_UX_MT_D)\
 \

PDB_SHWILD_UX_MT_D=\
 $(PDB_shw_api_UX_MT_D)\
 $(PDB_shw_matches_UX_MT_D)\
 $(PDB_shw_pattern_UX_MT_D)\
 \

OBJ_shw_api_UX_MT_R            = $(PROJ_OBJ_DIR)\shwild.pan.api.mt.obj
OBJ_shw_matches_UX_MT_R        = $(PROJ_OBJ_DIR)\shwild.pan.matches.mt.obj
OBJ_shw_pattern_UX_MT_R        = $(PROJ_OBJ_DIR)\shwild.pan.pattern.mt.obj

OBJ_SHWILD_UX_MT_R=\
 $(OBJ_shw_api_UX_MT_R)\
 $(OBJ_shw_matches_UX_MT_R)\
 $(OBJ_shw_pattern_UX_MT_R)\
 \


# xContract

OBJ_xct_core_UX_MT_D           = $(PROJ_OBJ_DIR)\xcontract.pan.core.api.mt.debug.obj
PDB_xct_core_UX_MT_D           = $(PROJ_OBJ_DIR)\xcontract.pan.core.api.mt.debug.pdb

OBJ_XCONTRACT_UX_MT_D=\
 $(OBJ_xct_core_UX_MT_D)\
 \

PDB_XCONTRACT_UX_MT_D=\
 $(PDB_xct_core_UX_MT_D)\
 \

OBJ_xct_core_UX_MT_R           = $(PROJ_OBJ_DIR)\xcontract.pan.core.api.mt.obj

OBJ_XCONTRACT_UX_MT_R=\
 $(OBJ_xct_core_UX_MT_R)\
 \


# xTests

OBJ_xts_core_UX_MT_D           = $(PROJ_OBJ_DIR)\xtests.pan.core.api.mt.debug.obj
PDB_xts_core_UX_MT_D           = $(PROJ_OBJ_DIR)\xtests.pan.core.api.mt.debug.pdb

OBJ_XTESTS_UX_MT_D=\
 $(OBJ_xts_core_UX_MT_D)\
 \

PDB_XTESTS_UX_MT_D=\
 $(PDB_xts_core_UX_MT_D)\
 \

OBJ_xts_core_UX_MT_R           = $(PROJ_OBJ_DIR)\xtests.pan.core.api.mt.obj

OBJ_XTESTS_UX_MT_R=\
 $(OBJ_xts_core_UX_MT_R)\
 \



########################################
# examples

OBJ_EX_P_be_01_UX_MT_D	=	.\ex.cpp.be.01.mt.debug.obj
OBJ_EX_P_be_02_UX_MT_D	=	.\ex.cpp.be.02.mt.debug.obj
OBJ_EX_P_be_03_UX_MT_D	=	.\ex.cpp.be.03.mt.debug.obj
OBJ_EX_P_be_04_UX_MT_D	=	.\ex.cpp.be.04.mt.debug.obj
OBJ_EX_P_be_05_UX_MT_D	=	.\ex.cpp.be.05.mt.debug.obj
OBJ_EX_P_be_06_UX_MT_D	=	.\ex.cpp.be.06.mt.debug.obj
OBJ_EX_P_cp_01_UX_MT_D	=	.\ex.cpp.cp.01.mt.debug.obj
OBJ_EX_P_cp_02_UX_MT_D	=	.\ex.cpp.cp.02.mt.debug.obj
OBJ_EX_P_fm_01_UX_MT_D	=	.\ex.cpp.fm.01.mt.debug.obj
OBJ_EX_P_fm_02_UX_MT_D	=	.\ex.cpp.fm.02.mt.debug.obj
OBJ_EX_P_fm_03_UX_MT_D	=	.\ex.cpp.fm.03.mt.debug.obj
OBJ_EX_P_fe_01_UX_MT_D	=	.\ex.cpp.fe.01.mt.debug.obj
OBJ_EX_P_in_01_UX_MT_D	=	.\ex.cpp.in.01.mt.debug.obj
OBJ_EX_P_in_02_UX_MT_D	=	.\ex.cpp.in.02.mt.debug.obj
OBJ_EX_P_in_03_UX_MT_D	=	.\ex.cpp.in.03.mt.debug.obj
OBJ_EX_P_in_04_UX_MT_D	=	.\ex.cpp.in.04.mt.debug.obj
OBJ_EX_P_in_05_UX_MT_D	=	.\ex.cpp.in.05.mt.debug.obj
OBJ_EX_P_in_06_UX_MT_D	=	.\ex.cpp.in.06.mt.debug.obj
OBJ_EX_P_in_07_UX_MT_D	=	.\ex.cpp.in.07.mt.debug.obj
OBJ_EX_P_in_08_UX_MT_D	=	.\ex.cpp.in.08.mt.debug.obj
OBJ_EX_P_in_09_UX_MT_D	=	.\ex.cpp.in.09.mt.debug.obj
OBJ_EX_P_in_10_UX_MT_D	=	.\ex.cpp.in.10.mt.debug.obj
OBJ_EX_P_in_11_UX_MT_D	=	.\ex.cpp.in.11.mt.debug.obj
OBJ_EX_P_in_12_UX_MT_D	=	.\ex.cpp.in.12.mt.debug.obj
OBJ_EX_P_in_13_UX_MT_D	=	.\ex.cpp.in.13.mt.debug.obj
OBJ_EX_P_in_14_UX_MT_D	=	.\ex.cpp.in.14.mt.debug.obj
OBJ_EX_P_in_15_UX_MT_D	=	.\ex.cpp.in.15.mt.debug.obj
OBJ_EX_P_in_16_UX_MT_D	=	.\ex.cpp.in.16.mt.debug.obj
OBJ_EX_P_in_17_UX_MT_D	=	.\ex.cpp.in.17.mt.debug.obj
OBJ_EX_P_ln_01_UX_MT_D	=	.\ex.cpp.ln.01.mt.debug.obj
OBJ_EX_P_ms_01_UX_MT_D	=	.\ex.cpp.m2.01.mt.debug.obj
OBJ_EX_P_ms_02_UX_MT_D	=	.\ex.cpp.m2.02.mt.debug.obj
OBJ_EX_P_ms_03_UX_MT_D	=	.\ex.cpp.m2.03.mt.debug.obj
OBJ_EX_P_ms_04_UX_MT_D	=	.\ex.cpp.m2.04.mt.debug.obj
OBJ_EX_P_ms_05_UX_MT_D	=	.\ex.cpp.m2.05.mt.debug.obj
OBJ_EX_P_ms_06_UX_MT_D	=	.\ex.cpp.ms.06.mt.debug.obj
OBJ_EX_P_ut_01_UX_MT_D	=	.\ex.cpp.ut.01.mt.debug.obj
OBJ_EX_C_0_UX_MT_D		=	.\ex.c.0.mt.debug.obj
OBJ_EX_C_1_UX_MT_D		=	.\ex.c.1.mt.debug.obj
OBJ_EX_C_2_UX_MT_D		=	.\ex.c.2.mt.debug.obj
OBJ_EX_C_3_UX_MT_D		=	.\ex.c.3.mt.debug.obj
OBJ_EX_C_4_UX_MT_D		=	.\ex.c.4.mt.debug.obj
OBJ_EX_C_5_UX_MT_D		=	.\ex.c.5.mt.debug.obj
OBJ_EX_C_6_UX_MT_D		=	.\ex.c.6.mt.debug.obj
OBJ_EX_C_7_UX_MT_D		=	.\ex.c.7.mt.debug.obj
OBJ_EX_P_be_01_UX_MT_R	=	.\ex.cpp.be.01.mt.obj
OBJ_EX_P_be_02_UX_MT_R	=	.\ex.cpp.be.02.mt.obj
OBJ_EX_P_be_03_UX_MT_R	=	.\ex.cpp.be.03.mt.obj
OBJ_EX_P_be_04_UX_MT_R	=	.\ex.cpp.be.04.mt.obj
OBJ_EX_P_be_05_UX_MT_R	=	.\ex.cpp.be.05.mt.obj
OBJ_EX_P_be_06_UX_MT_R	=	.\ex.cpp.be.06.mt.obj
OBJ_EX_P_cp_01_UX_MT_R	=	.\ex.cpp.cp.01.mt.obj
OBJ_EX_P_cp_02_UX_MT_R	=	.\ex.cpp.cp.02.mt.obj
OBJ_EX_P_fm_01_UX_MT_R	=	.\ex.cpp.fm.01.mt.obj
OBJ_EX_P_fm_02_UX_MT_R	=	.\ex.cpp.fm.02.mt.obj
OBJ_EX_P_fm_03_UX_MT_R	=	.\ex.cpp.fm.03.mt.obj
OBJ_EX_P_fe_01_UX_MT_R	=	.\ex.cpp.fe.01.mt.obj
OBJ_EX_P_in_01_UX_MT_R	=	.\ex.cpp.in.01.mt.obj
OBJ_EX_P_in_02_UX_MT_R	=	.\ex.cpp.in.02.mt.obj
OBJ_EX_P_in_03_UX_MT_R	=	.\ex.cpp.in.03.mt.obj
OBJ_EX_P_in_04_UX_MT_R	=	.\ex.cpp.in.04.mt.obj
OBJ_EX_P_in_05_UX_MT_R	=	.\ex.cpp.in.05.mt.obj
OBJ_EX_P_in_06_UX_MT_R	=	.\ex.cpp.in.06.mt.obj
OBJ_EX_P_in_07_UX_MT_R	=	.\ex.cpp.in.07.mt.obj
OBJ_EX_P_in_08_UX_MT_R	=	.\ex.cpp.in.08.mt.obj
OBJ_EX_P_in_09_UX_MT_R	=	.\ex.cpp.in.09.mt.obj
OBJ_EX_P_in_10_UX_MT_R	=	.\ex.cpp.in.10.mt.obj
OBJ_EX_P_in_11_UX_MT_R	=	.\ex.cpp.in.11.mt.obj
OBJ_EX_P_in_12_UX_MT_R	=	.\ex.cpp.in.12.mt.obj
OBJ_EX_P_in_13_UX_MT_R	=	.\ex.cpp.in.13.mt.obj
OBJ_EX_P_in_14_UX_MT_R	=	.\ex.cpp.in.14.mt.obj
OBJ_EX_P_in_15_UX_MT_R	=	.\ex.cpp.in.15.mt.obj
OBJ_EX_P_in_16_UX_MT_R	=	.\ex.cpp.in.16.mt.obj
OBJ_EX_P_in_17_UX_MT_R	=	.\ex.cpp.in.17.mt.obj
OBJ_EX_P_ln_01_UX_MT_R	=	.\ex.cpp.ln.01.mt.obj
OBJ_EX_P_ms_01_UX_MT_R	=	.\ex.cpp.m2.01.mt.obj
OBJ_EX_P_ms_02_UX_MT_R	=	.\ex.cpp.m2.02.mt.obj
OBJ_EX_P_ms_03_UX_MT_R	=	.\ex.cpp.m2.03.mt.obj
OBJ_EX_P_ms_04_UX_MT_R	=	.\ex.cpp.m2.04.mt.obj
OBJ_EX_P_ms_05_UX_MT_R	=	.\ex.cpp.m2.05.mt.obj
OBJ_EX_P_ms_06_UX_MT_R	=	.\ex.cpp.ms.06.mt.obj
OBJ_EX_P_ut_01_UX_MT_R	=	.\ex.cpp.ut.01.mt.obj
OBJ_EX_C_0_UX_MT_R		=	.\ex.c.0.mt.obj
OBJ_EX_C_1_UX_MT_R		=	.\ex.c.1.mt.obj
OBJ_EX_C_2_UX_MT_R		=	.\ex.c.2.mt.obj
OBJ_EX_C_3_UX_MT_R		=	.\ex.c.3.mt.obj
OBJ_EX_C_4_UX_MT_R		=	.\ex.c.4.mt.obj
OBJ_EX_C_5_UX_MT_R		=	.\ex.c.5.mt.obj
OBJ_EX_C_6_UX_MT_R		=	.\ex.c.6.mt.obj
OBJ_EX_C_7_UX_MT_R		=	.\ex.c.7.mt.obj

########################################
# tests

##############################
# component tests

OBJ_TEST_COMP_core_initseq_UX_MT_D	=	.\test.component.core.init_sequence.mt.debug.obj
OBJ_TEST_COMP_core_initseq_UX_MT_R	=	.\test.component.core.init_sequence.mt.obj
OBJ_TEST_COMP_custsev_UX_MT_D		=	.\test.component.custom_severity.mt.debug.obj
OBJ_TEST_COMP_custsev_UX_MT_R		=	.\test.component.custom_severity.mt.obj
OBJ_TEST_COMP_filemt_UX_MT_D			=	.\test.component.be.file.threading.mt.debug.obj
OBJ_TEST_COMP_filemt_UX_MT_R			=	.\test.component.be.file.threading.mt.obj
OBJ_TEST_COMP_bec_fprtf_UX_MT_D		=	.\test.component.bec.fprintf.mt.debug.obj
OBJ_TEST_COMP_bec_fprtf_UX_MT_R		=	.\test.component.bec.fprintf.mt.obj
OBJ_TEST_COMP_ins_args_UX_MT_D		=	.\test.component.inserters.args.mt.debug.obj
OBJ_TEST_COMP_ins_args_UX_MT_R		=	.\test.component.inserters.args.mt.obj
!ifndef PANTHEIOS_NO_B64
OBJ_TEST_COMP_ins_b64_UX_MT_D		=	.\test.component.inserters.b64.mt.debug.obj
OBJ_TEST_COMP_ins_b64_UX_MT_R		=	.\test.component.inserters.b64.mt.obj
!endif # !PANTHEIOS_NO_B64
OBJ_TEST_COMP_ins_bool_UX_MT_D		=	.\test.component.inserters.boolean.mt.debug.obj
OBJ_TEST_COMP_ins_bool_UX_MT_R		=	.\test.component.inserters.boolean.mt.obj
OBJ_TEST_COMP_ins_hostid_UX_MT_D		=	.\test.component.inserters.hostid.mt.debug.obj
OBJ_TEST_COMP_ins_hostid_UX_MT_R		=	.\test.component.inserters.hostid.mt.obj
OBJ_TEST_COMP_ins_int_UX_MT_D		=	.\test.component.inserters.integer.mt.debug.obj
OBJ_TEST_COMP_ins_int_UX_MT_R		=	.\test.component.inserters.integer.mt.obj
OBJ_TEST_COMP_ins_pad_UX_MT_D		=	.\test.component.inserters.pad.mt.debug.obj
OBJ_TEST_COMP_ins_pad_UX_MT_R		=	.\test.component.inserters.pad.mt.obj
OBJ_TEST_COMP_ins_ptr_UX_MT_D		=	.\test.component.inserters.pointer.mt.debug.obj
OBJ_TEST_COMP_ins_ptr_UX_MT_R		=	.\test.component.inserters.pointer.mt.obj
OBJ_TEST_COMP_ins_prid_UX_MT_D		=	.\test.component.inserters.processid.mt.debug.obj
OBJ_TEST_COMP_ins_prid_UX_MT_R		=	.\test.component.inserters.processid.mt.obj
OBJ_TEST_COMP_ins_real_UX_MT_D		=	.\test.component.inserters.real.mt.debug.obj
OBJ_TEST_COMP_ins_real_UX_MT_R		=	.\test.component.inserters.real.mt.obj
OBJ_TEST_COMP_ins_slice_UX_MT_D		=	.\test.component.inserters.slice.mt.debug.obj
OBJ_TEST_COMP_ins_slice_UX_MT_R		=	.\test.component.inserters.slice.mt.obj
OBJ_TEST_COMP_ins_stm_ch_UX_MT_D		=	.\test.component.inserters.stream_character.mt.debug.obj
OBJ_TEST_COMP_ins_stm_ch_UX_MT_R		=	.\test.component.inserters.stream_character.mt.obj
OBJ_TEST_COMP_ins_thrid_UX_MT_D		=	.\test.component.inserters.threadid.mt.debug.obj
OBJ_TEST_COMP_ins_thrid_UX_MT_R		=	.\test.component.inserters.threadid.mt.obj
OBJ_TEST_COMP_ins_w2m_UX_MT_D		=	.\test.component.inserters.w2m.mt.debug.obj
OBJ_TEST_COMP_ins_w2m_UX_MT_R		=	.\test.component.inserters.w2m.mt.obj
OBJ_TEST_COMP_log_1_UX_MT_D			=	.\test.component.log.1.mt.debug.obj
OBJ_TEST_COMP_log_1_UX_MT_R			=	.\test.component.log.1.mt.obj
OBJ_TEST_COMP_pan_puts_UX_MT_D		=	.\test.component.core.pan_logputs.mt.debug.obj
OBJ_TEST_COMP_pan_puts_UX_MT_R		=	.\test.component.core.pan_logputs.mt.obj
OBJ_TEST_COMP_pan_prtf_UX_MT_D		=	.\test.component.core.pan_logprintf.mt.debug.obj
OBJ_TEST_COMP_pan_prtf_UX_MT_R		=	.\test.component.core.pan_logprintf.mt.obj

##############################
# performance tests

OBJ_TEST_PERF_ins_w2m_UX_MT_D		=	.\test.performance.inserters.w2m.mt.debug.obj
OBJ_TEST_PERF_dtel2s_UX_MT_D			=	.\test.performance.util.date_elements_to_string.mt.debug.obj
OBJ_TEST_PERF_ins_w2m_UX_MT_R		=	.\test.performance.inserters.w2m.mt.obj
OBJ_TEST_PERF_dtel2s_UX_MT_R			=	.\test.performance.util.date_elements_to_string.mt.obj

##############################
# scratch tests

!ifdef ACE
OBJ_SCRT_ACE_UX_MT_D					=	.\test.scratch.be.ACE.mt.debug.obj
!endif # ACE
OBJ_SCRT_API_UX_MT_D					=	.\test.api.mt.debug.obj
OBJ_SCRT_FE_UX_MT_D					=	.\test.fe.mt.debug.obj
OBJ_SCRT_BE_N_UX_MT_D				=	.\test.be.N.fail.mt.debug.obj
OBJ_SCRT_FE_SIMPLE_WC_UX_MT_D		=	.\test.fe.simple.WithCallback.mt.debug.obj
OBJ_SCRT_BE_SYSLOG_UX_MT_D			=	.\test.scratch.be.syslog.mt.debug.obj
OBJ_SCRT_BE_SYSLOGWC_UX_MT_D			=	.\test.scratch.be.syslog.WithCallback.mt.debug.obj
!ifdef ACE
OBJ_SCRT_ACE_UX_MT_R					=	.\test.scratch.be.ACE.mt.obj
!endif # ACE
OBJ_SCRT_API_UX_MT_R					=	.\test.api.mt.obj
OBJ_SCRT_FE_UX_MT_R					=	.\test.fe.mt.obj
OBJ_SCRT_BE_N_UX_MT_R				=	.\test.be.N.fail.mt.obj
OBJ_SCRT_FE_SIMPLE_WC_UX_MT_R		=	.\test.fe.simple.WithCallback.mt.obj
OBJ_SCRT_BE_SYSLOG_UX_MT_R			=	.\test.scratch.be.syslog.mt.obj
OBJ_SCRT_BE_SYSLOGWC_UX_MT_R			=	.\test.scratch.be.syslog.WithCallback.mt.obj

##############################
# unit tests
#
# NOTE: some names are as names longer than 63 characters scare CodeWarrior's linker


OBJ_TEST_UNIT_be_fail_UX_MT_D		=	.\test.unit.be.fail.mt.debug.obj
OBJ_TEST_UNIT_be_lrsplit_UX_MT_D		=	.\test.unit.be.lrsplit.mt.debug.obj
OBJ_TEST_UNIT_be_N_UX_MT_D					=	.\test.unit.be.N.mt.debug.obj
OBJ_TEST_UNIT_be_N_filt_UX_MT_D		=	.\test.unit.be.N.filtering.mt.debug.obj
OBJ_TEST_UNIT_bec_fail_UX_MT_D		=	.\test.unit.bec.fail.mt.debug.obj
OBJ_TEST_UNIT_bec_file_UX_MT_D		=	.\test.unit.bec.file.mt.debug.obj
OBJ_TEST_UNIT_bec_fprintf_UX_MT_D	=	.\test.unit.bec.fprintf.mt.debug.obj
OBJ_TEST_UNIT_fe_all_UX_MT_D			=	.\test.unit.fe.all.mt.debug.obj
OBJ_TEST_UNIT_fe_fail_UX_MT_D		=	.\test.unit.fe.fail.mt.debug.obj
OBJ_TEST_UNIT_fe_N_UX_MT_D			=	.\test.unit.fe.N.mt.debug.obj
OBJ_TEST_UNIT_fe_null_UX_MT_D		=	.\test.unit.fe.null.mt.debug.obj
OBJ_TEST_UNIT_fe_simple_UX_MT_D		=	.\test.unit.fe.simple.mt.debug.obj
OBJ_TEST_UNIT_getversion_UX_MT_D		=	.\test.unit.getversion.mt.debug.obj
#### TODO: test.unit.levels.2
OBJ_TEST_UNIT_lvls_dyninit_UX_MT_D	=	.\test.unit.levels.dynamic_init.mt.debug.obj
OBJ_TEST_UNIT_lvls_vals_UX_MT_D		=	.\test.unit.levels.values.mt.debug.obj
OBJ_TEST_UNIT_dtel2s_UX_MT_D			=	.\test.unit.util.dtel2s.mt.debug.obj
OBJ_TEST_UNIT_getcurrtm_UX_MT_D		=	.\test.unit.util.getcurrenttime.mt.debug.obj
OBJ_TEST_UNIT_gethostname_UX_MT_D	=	.\test.unit.util.gethostname.mt.debug.obj
OBJ_TEST_UNIT_onbailout_UX_MT_D		=	.\test.unit.util.onbailout.mt.debug.obj
OBJ_TEST_UNIT_snprintf_UX_MT_D		=	.\test.unit.util.snprintf.mt.debug.obj
OBJ_TEST_UNIT_strnlen_UX_MT_D		=	.\test.unit.util.strnlen.mt.debug.obj

OBJ_TEST_UNIT_be_fail_UX_MT_R		=	.\test.unit.be.fail.mt.obj
OBJ_TEST_UNIT_be_lrsplit_UX_MT_R		=	.\test.unit.be.lrsplit.mt.obj
OBJ_TEST_UNIT_be_N_UX_MT_R					=	.\test.unit.be.N.mt.obj
OBJ_TEST_UNIT_be_N_filt_UX_MT_R		=	.\test.unit.be.N.filtering.mt.obj
OBJ_TEST_UNIT_bec_fail_UX_MT_R		=	.\test.unit.bec.fail.mt.obj
OBJ_TEST_UNIT_bec_file_UX_MT_R		=	.\test.unit.bec.file.mt.obj
OBJ_TEST_UNIT_bec_fprintf_UX_MT_R	=	.\test.unit.bec.fprintf.mt.obj
OBJ_TEST_UNIT_fe_all_UX_MT_R			=	.\test.unit.fe.all.mt.obj
OBJ_TEST_UNIT_fe_fail_UX_MT_R		=	.\test.unit.fe.fail.mt.obj
OBJ_TEST_UNIT_fe_N_UX_MT_R			=	.\test.unit.fe.N.mt.obj
OBJ_TEST_UNIT_fe_null_UX_MT_R		=	.\test.unit.fe.null.mt.obj
OBJ_TEST_UNIT_fe_simple_UX_MT_R		=	.\test.unit.fe.simple.mt.obj
OBJ_TEST_UNIT_getversion_UX_MT_R		=	.\test.unit.getversion.mt.obj
#### TODO: test.unit.levels.2
OBJ_TEST_UNIT_lvls_dyninit_UX_MT_R	=	.\test.unit.levels.dynamic_init.mt.obj
OBJ_TEST_UNIT_lvls_vals_UX_MT_R		=	.\test.unit.levels.values.mt.obj
OBJ_TEST_UNIT_dtel2s_UX_MT_R			=	.\test.unit.util.dtel2s.mt.obj
OBJ_TEST_UNIT_getcurrtm_UX_MT_R		=	.\test.unit.util.getcurrenttime.mt.obj
OBJ_TEST_UNIT_gethostname_UX_MT_R	=	.\test.unit.util.gethostname.mt.obj
OBJ_TEST_UNIT_onbailout_UX_MT_R		=	.\test.unit.util.onbailout.mt.obj
OBJ_TEST_UNIT_snprintf_UX_MT_R		=	.\test.unit.util.snprintf.mt.obj
OBJ_TEST_UNIT_strnlen_UX_MT_R		=	.\test.unit.util.strnlen.mt.obj

OBJ_TEST_UNIT_ins_int_UX_MT_D		=	.\test.unit.inserter.integer.mt.debug.obj
OBJ_TEST_UNIT_ins_w2m_UX_MT_D		=	.\test.unit.inserter.w2m.mt.debug.obj
OBJ_TEST_UNIT_ins_stmc_UX_MT_D		=	.\test.unit.inserter.stream_character.mt.debug.obj
OBJ_TEST_UNIT_ins_int_UX_MT_R		=	.\test.unit.inserter.integer.mt.obj
OBJ_TEST_UNIT_ins_w2m_UX_MT_R		=	.\test.unit.inserter.w2m.mt.obj
OBJ_TEST_UNIT_ins_stmc_UX_MT_R		=	.\test.unit.inserter.stream_character.mt.obj

##################################################
# target groups

########################################
# objects

# util

OBJS_UTIL=\
 $(OBJ_UTIL_UX_MT_D)\
 $(OBJ_UTIL_UX_MT_R)\
 \

# appl

OBJS_APPL=\
 $(OBJ_APPL_UX_MT_D)\
 $(OBJ_APPL_UX_MT_R)\
 \

# core

OBJS_CORE=\
 $(OBJ_CORE_UX_MT_D)\
 $(OBJ_CORE_UX_MT_R)\
 \

# front-ends

OBJS_FE=\
 $(OBJ_FE_ALL_UX_MT_D)\
 $(OBJ_FE_ALL_WC_UX_MT_D)\
 $(OBJ_FE_FAIL_UX_MT_D)\
 $(OBJ_FE_N_UX_MT_D)\
 $(OBJ_FE_N_WC_UX_MT_D)\
 $(OBJ_FE_NULL_UX_MT_D)\
 $(OBJ_FE_NULL_WC_UX_MT_D)\
 $(OBJ_FE_SIMPLE_UX_MT_D)\
 $(OBJ_FE_SIMPLE_WC_UX_MT_D)\
 $(OBJ_FE_ALL_UX_MT_R)\
 $(OBJ_FE_ALL_WC_UX_MT_R)\
 $(OBJ_FE_FAIL_UX_MT_R)\
 $(OBJ_FE_N_UX_MT_R)\
 $(OBJ_FE_N_WC_UX_MT_R)\
 $(OBJ_FE_NULL_UX_MT_R)\
 $(OBJ_FE_NULL_WC_UX_MT_R)\
 $(OBJ_FE_SIMPLE_UX_MT_R)\
 $(OBJ_FE_SIMPLE_WC_UX_MT_R)\
 \

# back-ends
OBJS_BE=\
 $(OBJ_BE_LRSPLIT_UX_MT_D)\
 $(OBJ_BE_N_UX_MT_D)\
 $(OBJ_BEC_TEST_UX_MT_D)\
 $(OBJ_BE_TEST_UX_MT_D)\
 $(OBJ_BEL_TEST_UX_MT_D)\
 $(OBJ_BER_TEST_UX_MT_D)\
 $(OBJ_BEC_FAIL_UX_MT_D)\
 $(OBJ_BE_FAIL_UX_MT_D)\
 $(OBJ_BEL_FAIL_UX_MT_D)\
 $(OBJ_BER_FAIL_UX_MT_D)\
 $(OBJ_BEC_FILE_UX_MT_D)\
 $(OBJ_BEC_FILE_WC_UX_MT_D)\
 $(OBJ_BE_FILE_UX_MT_D)\
 $(OBJ_BEL_FILE_UX_MT_D)\
 $(OBJ_BER_FILE_UX_MT_D)\
 $(OBJ_BEC_FPRINTF_UX_MT_D)\
 $(OBJ_BEC_FPRINTF_WC_UX_MT_D)\
 $(OBJ_BE_FPRINTF_UX_MT_D)\
 $(OBJ_BEL_FPRINTF_UX_MT_D)\
 $(OBJ_BER_FPRINTF_UX_MT_D)\
 $(OBJ_BEC_NULL_UX_MT_D)\
 $(OBJ_BE_NULL_UX_MT_D)\
 $(OBJ_BEL_NULL_UX_MT_D)\
 $(OBJ_BER_NULL_UX_MT_D)\
 $(OBJ_BEC_SYSLOG_UX_MT_D)\
 $(OBJ_BEC_SYSLOGWC_UX_MT_D)\
 $(OBJ_BE_SYSLOG_UX_MT_D)\
 $(OBJ_BER_SYSLOG_UX_MT_D)\
 $(OBJ_BE_LRSPLIT_UX_MT_R)\
 $(OBJ_BE_N_UX_MT_R)\
 $(OBJ_BEC_TEST_UX_MT_R)\
 $(OBJ_BE_TEST_UX_MT_R)\
 $(OBJ_BEL_TEST_UX_MT_R)\
 $(OBJ_BER_TEST_UX_MT_R)\
 $(OBJ_BEC_FAIL_UX_MT_R)\
 $(OBJ_BE_FAIL_UX_MT_R)\
 $(OBJ_BEL_FAIL_UX_MT_R)\
 $(OBJ_BER_FAIL_UX_MT_R)\
 $(OBJ_BEC_FILE_UX_MT_R)\
 $(OBJ_BEC_FILE_WC_UX_MT_R)\
 $(OBJ_BE_FILE_UX_MT_R)\
 $(OBJ_BEL_FILE_UX_MT_R)\
 $(OBJ_BER_FILE_UX_MT_R)\
 $(OBJ_BEC_FPRINTF_UX_MT_R)\
 $(OBJ_BEC_FPRINTF_WC_UX_MT_R)\
 $(OBJ_BE_FPRINTF_UX_MT_R)\
 $(OBJ_BEL_FPRINTF_UX_MT_R)\
 $(OBJ_BER_FPRINTF_UX_MT_R)\
 $(OBJ_BEC_NULL_UX_MT_R)\
 $(OBJ_BE_NULL_UX_MT_R)\
 $(OBJ_BEL_NULL_UX_MT_R)\
 $(OBJ_BER_NULL_UX_MT_R)\
 $(OBJ_BEC_SYSLOG_UX_MT_R)\
 $(OBJ_BEC_SYSLOGWC_UX_MT_R)\
 $(OBJ_BE_SYSLOG_UX_MT_R)\
 $(OBJ_BER_SYSLOG_UX_MT_R)\
 \


!ifdef ACE
OBJS_ACE=\
 $(OBJ_BEC_ACE_UX_MT_D)\
 $(OBJ_BE_ACE_UX_MT_D)\
 $(OBJ_BEL_ACE_UX_MT_D)\
 $(OBJ_BER_ACE_UX_MT_D)\
 $(OBJ_BEC_ACE_UX_MT_R)\
 $(OBJ_BE_ACE_UX_MT_R)\
 $(OBJ_BEL_ACE_UX_MT_R)\
 $(OBJ_BER_ACE_UX_MT_R)\
 \

!endif # ACE

# b64

!ifndef PANTHEIOS_NO_B64

OBJS_B64=\
 $(OBJ_B64_UX_MT_D)\
 $(OBJ_B64_UX_MT_R)\
 \

!endif # !PANTHEIOS_NO_B64

# shwild
OBJS_SHWILD=\
 $(OBJ_SHWILD_UX_MT_D)\
 $(OBJ_SHWILD_UX_MT_R)\
 \

# xContract
OBJS_XCONTRACT=\
 $(OBJ_XCONTRACT_UX_MT_D)\
 $(OBJ_XCONTRACT_UX_MT_R)\
 \

# xTests
OBJS_XTESTS=\
 $(OBJ_XTESTS_UX_MT_D)\
 $(OBJ_XTESTS_UX_MT_R)\
 \

# examples
OBJS_EXAMPLE_C=\
 $(OBJ_EX_C_0_UX_MT_D)\
 $(OBJ_EX_C_1_UX_MT_D)\
 $(OBJ_EX_C_2_UX_MT_D)\
 $(OBJ_EX_C_3_UX_MT_D)\
 $(OBJ_EX_C_4_UX_MT_D)\
 $(OBJ_EX_C_5_UX_MT_D)\
 $(OBJ_EX_C_6_UX_MT_D)\
 $(OBJ_EX_C_7_UX_MT_D)\
 $(OBJ_EX_C_0_UX_MT_R)\
 $(OBJ_EX_C_1_UX_MT_R)\
 $(OBJ_EX_C_2_UX_MT_R)\
 $(OBJ_EX_C_3_UX_MT_R)\
 $(OBJ_EX_C_4_UX_MT_R)\
 $(OBJ_EX_C_5_UX_MT_R)\
 $(OBJ_EX_C_6_UX_MT_R)\
 $(OBJ_EX_C_7_UX_MT_R)\
 \

OBJS_EXAMPLE_CPP=\
 $(OBJ_EX_P_be_01_UX_MT_D)\
 $(OBJ_EX_P_be_02_UX_MT_D)\
 $(OBJ_EX_P_be_03_UX_MT_D)\
 $(OBJ_EX_P_be_04_UX_MT_D)\
 $(OBJ_EX_P_be_05_UX_MT_D)\
 $(OBJ_EX_P_be_06_UX_MT_D)\
 $(OBJ_EX_P_cp_01_UX_MT_D)\
 $(OBJ_EX_P_cp_02_UX_MT_D)\
 $(OBJ_EX_P_fm_01_UX_MT_D)\
 $(OBJ_EX_P_fm_02_UX_MT_D)\
 $(OBJ_EX_P_fm_03_UX_MT_D)\
 $(OBJ_EX_P_fe_01_UX_MT_D)\
 $(OBJ_EX_P_in_01_UX_MT_D)\
 $(OBJ_EX_P_in_02_UX_MT_D)\
 $(OBJ_EX_P_in_03_UX_MT_D)\
 $(OBJ_EX_P_in_04_UX_MT_D)\
 $(OBJ_EX_P_in_05_UX_MT_D)\
 $(OBJ_EX_P_in_06_UX_MT_D)\
 $(OBJ_EX_P_in_07_UX_MT_D)\
 $(OBJ_EX_P_in_08_UX_MT_D)\
 $(OBJ_EX_P_in_09_UX_MT_D)\
 $(OBJ_EX_P_in_10_UX_MT_D)\
 $(OBJ_EX_P_in_11_UX_MT_D)\
 $(OBJ_EX_P_in_12_UX_MT_D)\
 $(OBJ_EX_P_in_13_UX_MT_D)\
 $(OBJ_EX_P_in_14_UX_MT_D)\
 $(OBJ_EX_P_in_15_UX_MT_D)\
 $(OBJ_EX_P_in_16_UX_MT_D)\
 $(OBJ_EX_P_in_17_UX_MT_D)\
 $(OBJ_EX_P_ln_01_UX_MT_D)\
 $(OBJ_EX_P_ms_01_UX_MT_D)\
 $(OBJ_EX_P_ms_02_UX_MT_D)\
 $(OBJ_EX_P_ms_03_UX_MT_D)\
 $(OBJ_EX_P_ms_04_UX_MT_D)\
 $(OBJ_EX_P_ms_05_UX_MT_D)\
 $(OBJ_EX_P_ms_06_UX_MT_D)\
 $(OBJ_EX_P_ut_01_UX_MT_D)\
 $(OBJ_EX_P_be_01_UX_MT_R)\
 $(OBJ_EX_P_be_02_UX_MT_R)\
 $(OBJ_EX_P_be_03_UX_MT_R)\
 $(OBJ_EX_P_be_04_UX_MT_R)\
 $(OBJ_EX_P_be_05_UX_MT_R)\
 $(OBJ_EX_P_be_06_UX_MT_R)\
 $(OBJ_EX_P_cp_01_UX_MT_R)\
 $(OBJ_EX_P_cp_02_UX_MT_R)\
 $(OBJ_EX_P_fm_01_UX_MT_R)\
 $(OBJ_EX_P_fm_02_UX_MT_R)\
 $(OBJ_EX_P_fm_03_UX_MT_R)\
 $(OBJ_EX_P_fe_01_UX_MT_R)\
 $(OBJ_EX_P_in_01_UX_MT_R)\
 $(OBJ_EX_P_in_02_UX_MT_R)\
 $(OBJ_EX_P_in_03_UX_MT_R)\
 $(OBJ_EX_P_in_04_UX_MT_R)\
 $(OBJ_EX_P_in_05_UX_MT_R)\
 $(OBJ_EX_P_in_06_UX_MT_R)\
 $(OBJ_EX_P_in_07_UX_MT_R)\
 $(OBJ_EX_P_in_08_UX_MT_R)\
 $(OBJ_EX_P_in_09_UX_MT_R)\
 $(OBJ_EX_P_in_10_UX_MT_R)\
 $(OBJ_EX_P_in_11_UX_MT_R)\
 $(OBJ_EX_P_in_12_UX_MT_R)\
 $(OBJ_EX_P_in_13_UX_MT_R)\
 $(OBJ_EX_P_in_14_UX_MT_R)\
 $(OBJ_EX_P_in_15_UX_MT_R)\
 $(OBJ_EX_P_in_16_UX_MT_R)\
 $(OBJ_EX_P_in_17_UX_MT_R)\
 $(OBJ_EX_P_ln_01_UX_MT_R)\
 $(OBJ_EX_P_ms_01_UX_MT_R)\
 $(OBJ_EX_P_ms_02_UX_MT_R)\
 $(OBJ_EX_P_ms_03_UX_MT_R)\
 $(OBJ_EX_P_ms_04_UX_MT_R)\
 $(OBJ_EX_P_ms_05_UX_MT_R)\
 $(OBJ_EX_P_ms_06_UX_MT_R)\
 $(OBJ_EX_P_ut_01_UX_MT_R)\
 \

OBJS_EXAMPLE=\
 $(OBJS_EXAMPLE_C)\
 $(OBJS_EXAMPLE_CPP)\
 \


# Component Tests
!ifdef PANTHEIOS_NO_B64

OBJS_TEST_COMPONENT_b64=
!else

OBJS_TEST_COMPONENT_b64=\
 $(OBJ_TEST_COMP_ins_b64_UX_MT_D)\
 $(OBJ_TEST_COMP_ins_b64_UX_MT_R)\
 \

!endif # !PANTHEIOS_NO_B64

OBJS_TEST_COMPONENT=\
 $(OBJ_TEST_COMP_core_initseq_UX_MT_D)\
 $(OBJ_TEST_COMP_custsev_UX_MT_D)\
 $(OBJ_TEST_COMP_filemt_UX_MT_D)\
 $(OBJ_TEST_COMP_bec_fprtf_UX_MT_D)\
 $(OBJ_TEST_COMP_ins_args_UX_MT_D)\
 $(OBJ_TEST_COMP_ins_bool_UX_MT_D)\
 $(OBJ_TEST_COMP_ins_hostid_UX_MT_D)\
 $(OBJ_TEST_COMP_ins_int_UX_MT_D)\
 $(OBJ_TEST_COMP_ins_pad_UX_MT_D)\
 $(OBJ_TEST_COMP_ins_ptr_UX_MT_D)\
 $(OBJ_TEST_COMP_ins_prid_UX_MT_D)\
 $(OBJ_TEST_COMP_ins_real_UX_MT_D)\
 $(OBJ_TEST_COMP_ins_slice_UX_MT_D)\
 $(OBJ_TEST_COMP_ins_stm_ch_UX_MT_D)\
 $(OBJ_TEST_COMP_ins_thrid_UX_MT_D)\
 $(OBJ_TEST_COMP_ins_w2m_UX_MT_D)\
 $(OBJ_TEST_COMP_log_1_UX_MT_D)\
 $(OBJ_TEST_COMP_pan_puts_UX_MT_D)\
 $(OBJ_TEST_COMP_pan_prtf_UX_MT_D)\
 $(OBJ_TEST_COMP_core_initseq_UX_MT_R)\
 $(OBJ_TEST_COMP_custsev_UX_MT_R)\
 $(OBJ_TEST_COMP_filemt_UX_MT_R)\
 $(OBJ_TEST_COMP_bec_fprtf_UX_MT_R)\
 $(OBJ_TEST_COMP_ins_args_UX_MT_R)\
 $(OBJ_TEST_COMP_ins_bool_UX_MT_R)\
 $(OBJ_TEST_COMP_ins_hostid_UX_MT_R)\
 $(OBJ_TEST_COMP_ins_int_UX_MT_R)\
 $(OBJ_TEST_COMP_ins_pad_UX_MT_R)\
 $(OBJ_TEST_COMP_ins_ptr_UX_MT_R)\
 $(OBJ_TEST_COMP_ins_prid_UX_MT_R)\
 $(OBJ_TEST_COMP_ins_real_UX_MT_R)\
 $(OBJ_TEST_COMP_ins_slice_UX_MT_R)\
 $(OBJ_TEST_COMP_ins_stm_ch_UX_MT_R)\
 $(OBJ_TEST_COMP_ins_thrid_UX_MT_R)\
 $(OBJ_TEST_COMP_ins_w2m_UX_MT_R)\
 $(OBJ_TEST_COMP_log_1_UX_MT_R)\
 $(OBJ_TEST_COMP_pan_puts_UX_MT_R)\
 $(OBJ_TEST_COMP_pan_prtf_UX_MT_R)\
 $(OBJS_TEST_COMPONENT_b64)\
 \

# Performance Tests
OBJS_TEST_PERFORMANCE=\
 $(OBJ_TEST_PERF_ins_w2m_UX_MT_D)\
 $(OBJ_TEST_PERF_dtel2s_UX_MT_D)\
 $(OBJ_TEST_PERF_ins_w2m_UX_MT_R)\
 $(OBJ_TEST_PERF_dtel2s_UX_MT_R)\
 \

# Scratch Tests
OBJS_TEST_SCRATCH=\
 $(OBJ_SCRT_API_UX_MT_D)\
 $(OBJ_SCRT_FE_UX_MT_D)\
 $(OBJ_SCRT_BE_N_UX_MT_D)\
 $(OBJ_SCRT_FE_SIMPLE_WC_UX_MT_D)\
 $(OBJ_SCRT_BE_SYSLOG_UX_MT_D)\
 $(OBJ_SCRT_BE_SYSLOGWC_UX_MT_D)\
 $(OBJ_SCRT_API_UX_MT_R)\
 $(OBJ_SCRT_FE_UX_MT_R)\
 $(OBJ_SCRT_BE_N_UX_MT_R)\
 $(OBJ_SCRT_FE_SIMPLE_WC_UX_MT_R)\
 $(OBJ_SCRT_BE_SYSLOG_UX_MT_R)\
 $(OBJ_SCRT_BE_SYSLOGWC_UX_MT_R)\
 \

# Unit Tests
OBJS_TEST_UNIT=\
 \
 $(OBJ_TEST_UNIT_be_fail_UX_MT_D)\
 $(OBJ_TEST_UNIT_be_lrsplit_UX_MT_D)\
 $(OBJ_TEST_UNIT_be_N_UX_MT_D)\
 $(OBJ_TEST_UNIT_be_N_filt_UX_MT_D)\
 $(OBJ_TEST_UNIT_bec_fail_UX_MT_D)\
 $(OBJ_TEST_UNIT_bec_file_UX_MT_D)\
 $(OBJ_TEST_UNIT_bec_fprintf_UX_MT_D)\
 $(OBJ_TEST_UNIT_fe_all_UX_MT_D)\
 $(OBJ_TEST_UNIT_fe_fail_UX_MT_D)\
 $(OBJ_TEST_UNIT_fe_N_UX_MT_D)\
 $(OBJ_TEST_UNIT_fe_null_UX_MT_D)\
 $(OBJ_TEST_UNIT_fe_simple_UX_MT_D)\
 $(OBJ_TEST_UNIT_getversion_UX_MT_D)\
 \
 $(OBJ_TEST_UNIT_lvls_dyninit_UX_MT_D)\
 $(OBJ_TEST_UNIT_lvls_vals_UX_MT_D)\
 $(OBJ_TEST_UNIT_dtel2s_UX_MT_D)\
 $(OBJ_TEST_UNIT_getcurrtm_UX_MT_D)\
 $(OBJ_TEST_UNIT_gethostname_UX_MT_D)\
 $(OBJ_TEST_UNIT_onbailout_UX_MT_D)\
 $(OBJ_TEST_UNIT_snprintf_UX_MT_D)\
 $(OBJ_TEST_UNIT_strnlen_UX_MT_D)\
 \
 $(OBJ_TEST_UNIT_ins_int_UX_MT_D)\
 $(OBJ_TEST_UNIT_ins_w2m_UX_MT_D)\
 $(OBJ_TEST_UNIT_ins_stmc_UX_MT_D)\
 \
 $(OBJ_TEST_UNIT_be_fail_UX_MT_R)\
 $(OBJ_TEST_UNIT_be_lrsplit_UX_MT_R)\
 $(OBJ_TEST_UNIT_be_N_UX_MT_R)\
 $(OBJ_TEST_UNIT_be_N_filt_UX_MT_R)\
 $(OBJ_TEST_UNIT_bec_fail_UX_MT_R)\
 $(OBJ_TEST_UNIT_bec_file_UX_MT_R)\
 $(OBJ_TEST_UNIT_bec_fprintf_UX_MT_R)\
 $(OBJ_TEST_UNIT_fe_all_UX_MT_R)\
 $(OBJ_TEST_UNIT_fe_fail_UX_MT_R)\
 $(OBJ_TEST_UNIT_fe_N_UX_MT_R)\
 $(OBJ_TEST_UNIT_fe_null_UX_MT_R)\
 $(OBJ_TEST_UNIT_fe_simple_UX_MT_R)\
 $(OBJ_TEST_UNIT_getversion_UX_MT_R)\
 \
 $(OBJ_TEST_UNIT_lvls_dyninit_UX_MT_R)\
 $(OBJ_TEST_UNIT_lvls_vals_UX_MT_R)\
 $(OBJ_TEST_UNIT_dtel2s_UX_MT_R)\
 $(OBJ_TEST_UNIT_getcurrtm_UX_MT_R)\
 $(OBJ_TEST_UNIT_gethostname_UX_MT_R)\
 $(OBJ_TEST_UNIT_onbailout_UX_MT_R)\
 $(OBJ_TEST_UNIT_snprintf_UX_MT_R)\
 $(OBJ_TEST_UNIT_strnlen_UX_MT_R)\
 \
 $(OBJ_TEST_UNIT_ins_int_UX_MT_R)\
 $(OBJ_TEST_UNIT_ins_w2m_UX_MT_R)\
 $(OBJ_TEST_UNIT_ins_stmc_UX_MT_R)\
 \

########################################
# libraries

# $(LIB_UTIL [ ` [ N a m e T a g ] ` ] )\

TARGETS_LIB_UTIL=\
 $(LIB_UTIL_UX_MT_D)\
 $(LIB_UTIL_UX_MT_R)\
 \

TARGETS_LIB_CORE=\
 $(LIB_CORE_UX_MT_D)\
 $(LIB_CORE_UX_MT_R)\
 \

TARGETS_LIB_APPL=\
 $(LIB_APPL_UX_MT_D)\
 $(LIB_APPL_UX_MT_R)\
 \

TARGETS_LIB_FE_CMN=\
 $(LIB_FE_ALL_UX_MT_D)\
 $(LIB_FE_ALL_WC_UX_MT_D)\
 $(LIB_FE_FAIL_UX_MT_D)\
 $(LIB_FE_N_UX_MT_D)\
 $(LIB_FE_N_WC_UX_MT_D)\
 $(LIB_FE_NULL_UX_MT_D)\
 $(LIB_FE_NULL_WC_UX_MT_D)\
 $(LIB_FE_SIMPLE_UX_MT_D)\
 $(LIB_FE_SIMPLE_WC_UX_MT_D)\
 $(LIB_FE_ALL_UX_MT_R)\
 $(LIB_FE_ALL_WC_UX_MT_R)\
 $(LIB_FE_FAIL_UX_MT_R)\
 $(LIB_FE_N_UX_MT_R)\
 $(LIB_FE_N_WC_UX_MT_R)\
 $(LIB_FE_NULL_UX_MT_R)\
 $(LIB_FE_NULL_WC_UX_MT_R)\
 $(LIB_FE_SIMPLE_UX_MT_R)\
 $(LIB_FE_SIMPLE_WC_UX_MT_R)\
 \

TARGETS_LIB_FE=\
 $(TARGETS_LIB_FE_CMN)\
 \

TARGETS_LIB_BE_CMN=\
 $(LIB_BEC_STOCK_UX_MT_D)\
 $(LIB_BEC_STOCK_WC_UX_MT_D)\
 \
 $(LIB_BE_LRSPLIT_UX_MT_D)\
 $(LIB_BE_N_UX_MT_D)\
 \
 $(LIB_BEC_FAIL_UX_MT_D)\
 $(LIB_BE_FAIL_UX_MT_D)\
 $(LIB_BEL_FAIL_UX_MT_D)\
 $(LIB_BER_FAIL_UX_MT_D)\
 $(LIB_BEC_FILE_UX_MT_D)\
 $(LIB_BEC_FILE_WC_UX_MT_D)\
 $(LIB_BE_FILE_UX_MT_D)\
 $(LIB_BEL_FILE_UX_MT_D)\
 $(LIB_BER_FILE_UX_MT_D)\
 $(LIB_BEC_FPRINTF_UX_MT_D)\
 $(LIB_BEC_FPRINTF_WC_UX_MT_D)\
 $(LIB_BE_FPRINTF_UX_MT_D)\
 $(LIB_BEL_FPRINTF_UX_MT_D)\
 $(LIB_BER_FPRINTF_UX_MT_D)\
 $(LIB_BEC_NULL_UX_MT_D)\
 $(LIB_BE_NULL_UX_MT_D)\
 $(LIB_BEL_NULL_UX_MT_D)\
 $(LIB_BER_NULL_UX_MT_D)\
 $(LIB_BEC_STOCK_UX_MT_R)\
 $(LIB_BEC_STOCK_WC_UX_MT_R)\
 \
 $(LIB_BE_LRSPLIT_UX_MT_R)\
 $(LIB_BE_N_UX_MT_R)\
 \
 $(LIB_BEC_FAIL_UX_MT_R)\
 $(LIB_BE_FAIL_UX_MT_R)\
 $(LIB_BEL_FAIL_UX_MT_R)\
 $(LIB_BER_FAIL_UX_MT_R)\
 $(LIB_BEC_FILE_UX_MT_R)\
 $(LIB_BEC_FILE_WC_UX_MT_R)\
 $(LIB_BE_FILE_UX_MT_R)\
 $(LIB_BEL_FILE_UX_MT_R)\
 $(LIB_BER_FILE_UX_MT_R)\
 $(LIB_BEC_FPRINTF_UX_MT_R)\
 $(LIB_BEC_FPRINTF_WC_UX_MT_R)\
 $(LIB_BE_FPRINTF_UX_MT_R)\
 $(LIB_BEL_FPRINTF_UX_MT_R)\
 $(LIB_BER_FPRINTF_UX_MT_R)\
 $(LIB_BEC_NULL_UX_MT_R)\
 $(LIB_BE_NULL_UX_MT_R)\
 $(LIB_BEL_NULL_UX_MT_R)\
 $(LIB_BER_NULL_UX_MT_R)\
 \

TARGETS_LIB_BE=\
 $(LIB_BEC_STOCK_UX_MT_D)\
 $(LIB_BEC_STOCK_WC_UX_MT_D)\
 \
 $(LIB_BE_LRSPLIT_UX_MT_D)\
 $(LIB_BE_N_UX_MT_D)\
 \
 $(LIB_BEC_TEST_UX_MT_D)\
 $(LIB_BE_TEST_UX_MT_D)\
 $(LIB_BEL_TEST_UX_MT_D)\
 $(LIB_BER_TEST_UX_MT_D)\
 $(LIB_BEC_FAIL_UX_MT_D)\
 $(LIB_BE_FAIL_UX_MT_D)\
 $(LIB_BEL_FAIL_UX_MT_D)\
 $(LIB_BER_FAIL_UX_MT_D)\
 $(LIB_BEC_FILE_UX_MT_D)\
 $(LIB_BEC_FILE_WC_UX_MT_D)\
 $(LIB_BE_FILE_UX_MT_D)\
 $(LIB_BEL_FILE_UX_MT_D)\
 $(LIB_BER_FILE_UX_MT_D)\
 $(LIB_BEC_FPRINTF_UX_MT_D)\
 $(LIB_BEC_FPRINTF_WC_UX_MT_D)\
 $(LIB_BE_FPRINTF_UX_MT_D)\
 $(LIB_BEL_FPRINTF_UX_MT_D)\
 $(LIB_BER_FPRINTF_UX_MT_D)\
 $(LIB_BEC_NULL_UX_MT_D)\
 $(LIB_BE_NULL_UX_MT_D)\
 $(LIB_BEL_NULL_UX_MT_D)\
 $(LIB_BER_NULL_UX_MT_D)\
 $(LIB_BEC_SYSLOG_UX_MT_D)\
 $(LIB_BEC_SYSLOGWC_UX_MT_D)\
 $(LIB_BE_SYSLOG_UX_MT_D)\
 $(LIB_BER_SYSLOG_UX_MT_D)\
 $(LIB_BEC_STOCK_UX_MT_R)\
 $(LIB_BEC_STOCK_WC_UX_MT_R)\
 \
 $(LIB_BE_LRSPLIT_UX_MT_R)\
 $(LIB_BE_N_UX_MT_R)\
 \
 $(LIB_BEC_TEST_UX_MT_R)\
 $(LIB_BE_TEST_UX_MT_R)\
 $(LIB_BEL_TEST_UX_MT_R)\
 $(LIB_BER_TEST_UX_MT_R)\
 $(LIB_BEC_FAIL_UX_MT_R)\
 $(LIB_BE_FAIL_UX_MT_R)\
 $(LIB_BEL_FAIL_UX_MT_R)\
 $(LIB_BER_FAIL_UX_MT_R)\
 $(LIB_BEC_FILE_UX_MT_R)\
 $(LIB_BEC_FILE_WC_UX_MT_R)\
 $(LIB_BE_FILE_UX_MT_R)\
 $(LIB_BEL_FILE_UX_MT_R)\
 $(LIB_BER_FILE_UX_MT_R)\
 $(LIB_BEC_FPRINTF_UX_MT_R)\
 $(LIB_BEC_FPRINTF_WC_UX_MT_R)\
 $(LIB_BE_FPRINTF_UX_MT_R)\
 $(LIB_BEL_FPRINTF_UX_MT_R)\
 $(LIB_BER_FPRINTF_UX_MT_R)\
 $(LIB_BEC_NULL_UX_MT_R)\
 $(LIB_BE_NULL_UX_MT_R)\
 $(LIB_BEL_NULL_UX_MT_R)\
 $(LIB_BER_NULL_UX_MT_R)\
 $(LIB_BEC_SYSLOG_UX_MT_R)\
 $(LIB_BEC_SYSLOGWC_UX_MT_R)\
 $(LIB_BE_SYSLOG_UX_MT_R)\
 $(LIB_BER_SYSLOG_UX_MT_R)\
 \

!ifdef ACE
TARGETS_LIB_ACE=\
 $(LIB_BEC_ACE_UX_MT_D)\
 $(LIB_BE_ACE_UX_MT_D)\
 $(LIB_BEL_ACE_UX_MT_D)\
 $(LIB_BER_ACE_UX_MT_D)\
 $(LIB_BEC_ACE_UX_MT_R)\
 $(LIB_BE_ACE_UX_MT_R)\
 $(LIB_BEL_ACE_UX_MT_R)\
 $(LIB_BER_ACE_UX_MT_R)\
 \

!else # ACE
TARGETS_LIB_ACE=

!endif # ACE
TARGETS_LIB_ALL=\
 $(TARGETS_LIB_UTIL)\
 $(TARGETS_LIB_CORE)\
 $(TARGETS_LIB_APPL)\
 $(TARGETS_LIB_FE)\
 $(TARGETS_LIB_BE)\
 $(TARGETS_LIB_ACE)\
 \

!ifdef PANTHEIOS_NO_B64
TARGETS_LIB_B64=
!else
TARGETS_LIB_B64=\
 $(LIB_B64_UX_MT_D)\
 $(LIB_B64_UX_MT_R)\
 \

!endif # !PANTHEIOS_NO_B64

TARGETS_LIB_SHWILD=\
 $(LIB_SHWILD_UX_MT_D)\
 $(LIB_SHWILD_UX_MT_R)\
 \

TARGETS_LIB_XCONTRACT=\
 $(LIB_XCONTRACT_UX_MT_D)\
 $(LIB_XCONTRACT_UX_MT_R)\
 \

TARGETS_LIB_XTESTS=\
 $(LIB_XTESTS_UX_MT_D)\
 $(LIB_XTESTS_UX_MT_R)\
 \

########################################
# programs

TARGETS_EXAMPLE_C=\
 $(TARG_EX_C_0_UX_MT_D)\
 $(TARG_EX_C_1_UX_MT_D)\
 $(TARG_EX_C_2_UX_MT_D)\
 $(TARG_EX_C_3_UX_MT_D)\
 $(TARG_EX_C_4_UX_MT_D)\
 $(TARG_EX_C_5_UX_MT_D)\
 $(TARG_EX_C_6_UX_MT_D)\
 $(TARG_EX_C_7_UX_MT_D)\
 $(TARG_EX_C_0_UX_MT_R)\
 $(TARG_EX_C_1_UX_MT_R)\
 $(TARG_EX_C_2_UX_MT_R)\
 $(TARG_EX_C_3_UX_MT_R)\
 $(TARG_EX_C_4_UX_MT_R)\
 $(TARG_EX_C_5_UX_MT_R)\
 $(TARG_EX_C_6_UX_MT_R)\
 $(TARG_EX_C_7_UX_MT_R)\
 \

TARGETS_EXAMPLE_CPP=\
 $(TARG_EX_P_be_01_UX_MT_D)\
 $(TARG_EX_P_be_02_UX_MT_D)\
 $(TARG_EX_P_be_03_UX_MT_D)\
 $(TARG_EX_P_be_04_UX_MT_D)\
 $(TARG_EX_P_be_05_UX_MT_D)\
 $(TARG_EX_P_be_06_UX_MT_D)\
 $(TARG_EX_P_cp_01_UX_MT_D)\
 $(TARG_EX_P_cp_02_UX_MT_D)\
 $(TARG_EX_P_fm_01_UX_MT_D)\
 $(TARG_EX_P_fm_02_UX_MT_D)\
 $(TARG_EX_P_fm_03_UX_MT_D)\
 $(TARG_EX_P_fe_01_UX_MT_D)\
 $(TARG_EX_P_in_01_UX_MT_D)\
 $(TARG_EX_P_in_02_UX_MT_D)\
 $(TARG_EX_P_in_03_UX_MT_D)\
 $(TARG_EX_P_in_04_UX_MT_D)\
 $(TARG_EX_P_in_05_UX_MT_D)\
 $(TARG_EX_P_in_06_UX_MT_D)\
 $(TARG_EX_P_in_07_UX_MT_D)\
 $(TARG_EX_P_in_08_UX_MT_D)\
 $(TARG_EX_P_in_09_UX_MT_D)\
 $(TARG_EX_P_in_10_UX_MT_D)\
 $(TARG_EX_P_in_11_UX_MT_D)\
 $(TARG_EX_P_in_12_UX_MT_D)\
 $(TARG_EX_P_in_13_UX_MT_D)\
 $(TARG_EX_P_in_14_UX_MT_D)\
 $(TARG_EX_P_in_15_UX_MT_D)\
 $(TARG_EX_P_in_16_UX_MT_D)\
 $(TARG_EX_P_in_17_UX_MT_D)\
 $(TARG_EX_P_ln_01_UX_MT_D)\
 $(TARG_EX_P_ms_01_UX_MT_D)\
 $(TARG_EX_P_ms_02_UX_MT_D)\
 $(TARG_EX_P_ms_03_UX_MT_D)\
 $(TARG_EX_P_ms_04_UX_MT_D)\
 $(TARG_EX_P_ms_05_UX_MT_D)\
 $(TARG_EX_P_ms_06_UX_MT_D)\
 $(TARG_EX_P_ut_01_UX_MT_D)\
 $(TARG_EX_P_be_01_UX_MT_R)\
 $(TARG_EX_P_be_02_UX_MT_R)\
 $(TARG_EX_P_be_03_UX_MT_R)\
 $(TARG_EX_P_be_04_UX_MT_R)\
 $(TARG_EX_P_be_05_UX_MT_R)\
 $(TARG_EX_P_be_06_UX_MT_R)\
 $(TARG_EX_P_cp_01_UX_MT_R)\
 $(TARG_EX_P_cp_02_UX_MT_R)\
 $(TARG_EX_P_fm_01_UX_MT_R)\
 $(TARG_EX_P_fm_02_UX_MT_R)\
 $(TARG_EX_P_fm_03_UX_MT_R)\
 $(TARG_EX_P_fe_01_UX_MT_R)\
 $(TARG_EX_P_in_01_UX_MT_R)\
 $(TARG_EX_P_in_02_UX_MT_R)\
 $(TARG_EX_P_in_03_UX_MT_R)\
 $(TARG_EX_P_in_04_UX_MT_R)\
 $(TARG_EX_P_in_05_UX_MT_R)\
 $(TARG_EX_P_in_06_UX_MT_R)\
 $(TARG_EX_P_in_07_UX_MT_R)\
 $(TARG_EX_P_in_08_UX_MT_R)\
 $(TARG_EX_P_in_09_UX_MT_R)\
 $(TARG_EX_P_in_10_UX_MT_R)\
 $(TARG_EX_P_in_11_UX_MT_R)\
 $(TARG_EX_P_in_12_UX_MT_R)\
 $(TARG_EX_P_in_13_UX_MT_R)\
 $(TARG_EX_P_in_14_UX_MT_R)\
 $(TARG_EX_P_in_15_UX_MT_R)\
 $(TARG_EX_P_in_16_UX_MT_R)\
 $(TARG_EX_P_in_17_UX_MT_R)\
 $(TARG_EX_P_ln_01_UX_MT_R)\
 $(TARG_EX_P_ms_01_UX_MT_R)\
 $(TARG_EX_P_ms_02_UX_MT_R)\
 $(TARG_EX_P_ms_03_UX_MT_R)\
 $(TARG_EX_P_ms_04_UX_MT_R)\
 $(TARG_EX_P_ms_05_UX_MT_R)\
 $(TARG_EX_P_ms_06_UX_MT_R)\
 $(TARG_EX_P_ut_01_UX_MT_R)\
 \

TARGETS_EXAMPLE=\
 $(TARGETS_EXAMPLE_C)\
 $(TARGETS_EXAMPLE_CPP)\
 \


TARGETS_SAMPLE=\
 \


TARGETS_TEST_COMPONENT=\
 $(TARG_TEST_COMP_core_initseq_UX_MT_D)\
 $(TARG_TEST_COMP_custsev_UX_MT_D)\
 $(TARG_TEST_COMP_filemt_UX_MT_D)\
 $(TARG_TEST_COMP_bec_fprtf_UX_MT_D)\
 $(TARG_TEST_COMP_ins_args_UX_MT_D)\
 $(TARG_TEST_COMP_ins_b64_UX_MT_D)\
 $(TARG_TEST_COMP_ins_bool_UX_MT_D)\
 $(TARG_TEST_COMP_ins_hostid_UX_MT_D)\
 $(TARG_TEST_COMP_ins_int_UX_MT_D)\
 $(TARG_TEST_COMP_ins_pad_UX_MT_D)\
 $(TARG_TEST_COMP_ins_ptr_UX_MT_D)\
 $(TARG_TEST_COMP_ins_prid_UX_MT_D)\
 $(TARG_TEST_COMP_ins_real_UX_MT_D)\
 $(TARG_TEST_COMP_ins_slice_UX_MT_D)\
 $(TARG_TEST_COMP_ins_stm_ch_UX_MT_D)\
 $(TARG_TEST_COMP_ins_thrid_UX_MT_D)\
 $(TARG_TEST_COMP_ins_w2m_UX_MT_D)\
 $(TARG_TEST_COMP_log_1_UX_MT_D)\
 $(TARG_TEST_COMP_pan_puts_UX_MT_D)\
 $(TARG_TEST_COMP_pan_prtf_UX_MT_D)\
 $(TARG_TEST_COMP_core_initseq_UX_MT_R)\
 $(TARG_TEST_COMP_custsev_UX_MT_R)\
 $(TARG_TEST_COMP_filemt_UX_MT_R)\
 $(TARG_TEST_COMP_bec_fprtf_UX_MT_R)\
 $(TARG_TEST_COMP_ins_args_UX_MT_R)\
 $(TARG_TEST_COMP_ins_b64_UX_MT_R)\
 $(TARG_TEST_COMP_ins_bool_UX_MT_R)\
 $(TARG_TEST_COMP_ins_hostid_UX_MT_R)\
 $(TARG_TEST_COMP_ins_int_UX_MT_R)\
 $(TARG_TEST_COMP_ins_pad_UX_MT_R)\
 $(TARG_TEST_COMP_ins_ptr_UX_MT_R)\
 $(TARG_TEST_COMP_ins_prid_UX_MT_R)\
 $(TARG_TEST_COMP_ins_real_UX_MT_R)\
 $(TARG_TEST_COMP_ins_slice_UX_MT_R)\
 $(TARG_TEST_COMP_ins_stm_ch_UX_MT_R)\
 $(TARG_TEST_COMP_ins_thrid_UX_MT_R)\
 $(TARG_TEST_COMP_ins_w2m_UX_MT_R)\
 $(TARG_TEST_COMP_log_1_UX_MT_R)\
 $(TARG_TEST_COMP_pan_puts_UX_MT_R)\
 $(TARG_TEST_COMP_pan_prtf_UX_MT_R)\
 \

TARGETS_TEST_PERFORMANCE=\
 $(TARG_TEST_PERF_ins_w2m_UX_MT_D)\
 $(TARG_TEST_PERF_dtel2s_UX_MT_D)\
 $(TARG_TEST_PERF_ins_w2m_UX_MT_R)\
 $(TARG_TEST_PERF_dtel2s_UX_MT_R)\
 \

TARGETS_TEST_SCRATCH_STD=\
 $(TARG_SCRT_UX_MT_D_APIwBE_FPRINTF)\
 $(TARG_SCRT_BE_SYSLOG_UX_MT_D)\
 $(TARG_SCRT_BE_SYSLOGWC_UX_MT_D)\
 $(TARG_SCRT_UX_MT_D_APIwBELR_1_FPRINTF_SYSLOG)\
 $(TARG_SCRT_FE_UX_MT_D)\
 $(TARG_SCRT_BE_N_FAIL_UX_MT_D)\
 $(TARG_SCRT_FE_SIMPLE_WC_UX_MT_D)\
 $(TARG_SCRT_UX_MT_R_APIwBE_FPRINTF)\
 $(TARG_SCRT_BE_SYSLOG_UX_MT_R)\
 $(TARG_SCRT_BE_SYSLOGWC_UX_MT_R)\
 $(TARG_SCRT_UX_MT_R_APIwBELR_1_FPRINTF_SYSLOG)\
 $(TARG_SCRT_FE_UX_MT_R)\
 $(TARG_SCRT_BE_N_FAIL_UX_MT_R)\
 $(TARG_SCRT_FE_SIMPLE_WC_UX_MT_R)\
 \

!ifdef ACE
TARGETS_TEST_SCRATCH_ACE=\
 $(TARG_SCRT_ACE_UX_MT_D)\
 $(TARG_SCRT_ACE_UX_MT_R)\
 \

!endif # ACE
TARGETS_TEST_SCRATCH=\
 $(TARGETS_TEST_SCRATCH_STD)\
 \
# $(TARG_SCRT_file_UX_MT_D)\
# $(TARG_SCRT_file_UX_MT_R)\
 \
# $(TARG_SCRT_file_UX_MT_D)\
# $(TARG_SCRT_file_UX_MT_R)\
 \

TARGETS_TEST_UNIT=\
 $(TARG_TEST_UNIT_be_fail_UX_MT_D)\
 $(TARG_TEST_UNIT_be_lrsplit_UX_MT_D)\
 $(TARG_TEST_UNIT_be_N_UX_MT_D)\
 $(TARG_TEST_UNIT_be_N_filt_UX_MT_D)\
 $(TARG_TEST_UNIT_bec_file_UX_MT_D)\
 $(TARG_TEST_UNIT_bec_fprintf_UX_MT_D)\
 $(TARG_TEST_UNIT_bec_fail_UX_MT_D)\
 $(TARG_TEST_UNIT_fe_all_UX_MT_D)\
 $(TARG_TEST_UNIT_fe_fail_UX_MT_D)\
 $(TARG_TEST_UNIT_fe_N_UX_MT_D)\
 $(TARG_TEST_UNIT_fe_null_UX_MT_D)\
 $(TARG_TEST_UNIT_fe_simple_UX_MT_D)\
 $(TARG_TEST_UNIT_getversion_UX_MT_D)\
 \
 $(TARG_TEST_UNIT_lvls_dyninit_UX_MT_D)\
 $(TARG_TEST_UNIT_lvls_vals_UX_MT_D)\
 $(TARG_TEST_UNIT_dtel2s_UX_MT_D)\
 $(TARG_TEST_UNIT_getcurrtm_UX_MT_D)\
 $(TARG_TEST_UNIT_gethostname_UX_MT_D)\
 $(TARG_TEST_UNIT_onbailout_UX_MT_D)\
 $(TARG_TEST_UNIT_snprintf_UX_MT_D)\
 $(TARG_TEST_UNIT_strnlen_UX_MT_D)\
 \
 $(TARG_TEST_UNIT_ins_int_UX_MT_D)\
 $(TARG_TEST_UNIT_ins_w2m_UX_MT_D)\
 $(TARG_TEST_UNIT_ins_stmc_UX_MT_D)\
 $(TARG_TEST_UNIT_be_fail_UX_MT_R)\
 $(TARG_TEST_UNIT_be_lrsplit_UX_MT_R)\
 $(TARG_TEST_UNIT_be_N_UX_MT_R)\
 $(TARG_TEST_UNIT_be_N_filt_UX_MT_R)\
 $(TARG_TEST_UNIT_bec_file_UX_MT_R)\
 $(TARG_TEST_UNIT_bec_fprintf_UX_MT_R)\
 $(TARG_TEST_UNIT_bec_fail_UX_MT_R)\
 $(TARG_TEST_UNIT_fe_all_UX_MT_R)\
 $(TARG_TEST_UNIT_fe_fail_UX_MT_R)\
 $(TARG_TEST_UNIT_fe_N_UX_MT_R)\
 $(TARG_TEST_UNIT_fe_null_UX_MT_R)\
 $(TARG_TEST_UNIT_fe_simple_UX_MT_R)\
 $(TARG_TEST_UNIT_getversion_UX_MT_R)\
 \
 $(TARG_TEST_UNIT_lvls_dyninit_UX_MT_R)\
 $(TARG_TEST_UNIT_lvls_vals_UX_MT_R)\
 $(TARG_TEST_UNIT_dtel2s_UX_MT_R)\
 $(TARG_TEST_UNIT_getcurrtm_UX_MT_R)\
 $(TARG_TEST_UNIT_gethostname_UX_MT_R)\
 $(TARG_TEST_UNIT_onbailout_UX_MT_R)\
 $(TARG_TEST_UNIT_snprintf_UX_MT_R)\
 $(TARG_TEST_UNIT_strnlen_UX_MT_R)\
 \
 $(TARG_TEST_UNIT_ins_int_UX_MT_R)\
 $(TARG_TEST_UNIT_ins_w2m_UX_MT_R)\
 $(TARG_TEST_UNIT_ins_stmc_UX_MT_R)\
 \

############################################################
# third-party libraries

!ifdef ACE
LIBS_3PTY_ACE					=	ace.lib
!endif # ACE
LIBS_3PTY_FPRINTF				=
LIBS_3PTY_SYSLOG				=
LIBS_3PTY_BE_N_FAIL				=
LIBS_3PTY_TEST_UNIT				=

############################################################################
# external targets (invokable by make)

# primary

_default:                   build

usage:
	@echo "make [usage | compile | build | test | clean | ace | prep] - default is 'build'"
	@echo "details:"
	@echo "    default(=build)"
	@echo "    compile.libs.util"
	@echo "    compile.libs.core"
	@echo "    compile.ace"
	@echo "    compile.examples"
	@echo "    compile.test"
	@echo "    compile(=compile.libs.util+compile.libs.core+compile.example+compile.test)"
	@echo "    compile.all(=compile.libs.util+compile.libs.core+compile.example+compile.test+compile.ace)"
	@echo "    build.libs.util"
	@echo "    build.libs.core"
	@echo "    build.libs.fe"
	@echo "    build.libs.be"
	@echo "    build.libs.ace"
	@echo "    build.libs(=build.libs.util+build.libs.core+build.libs.fe+build.libs.be)"
	@echo "    build.libs.all(=build.libs.util+build.libs.core+build.libs.fe+build.libs.be+build.libs.ace)"
	@echo "    build.examples"
	@echo "    build.test.std"
	@echo "    build.test.ace"
	@echo "    build.test(=build.test.std)"
	@echo "    build.test.all(=build.test.std+build.test.ace)"
	@echo "    build.util(=build.libs.util)"
	@echo "    build.core(=build.libs.core)"
	@echo "    build.std(=build.libs.util+build.libs.core+build.libs.fe+build.libs.be+build.test.std)"
	@echo "    build.ace(=build.libs.ace+build.test.ace)"
	@echo "    build(=build.libs+build.examples+build.samples+build.test)"
	@echo "    build.all(=build.libs.all+build.examples+build.samples+build.test.all)"
	@echo "    test.std"
	@echo "    test.ace"
	@echo "    test(=test.std)"
	@echo "    test.all(=test.std+test.ace)"
	@echo "    std=build.std+test.std"
	@echo "    ace=build.ace+test.ace"
	@echo "    all=core+std+ace"
	@echo "    prep: removes \r from all .h and .c files, on UNIX-only"


# infrastructure



prep.files.for.os:	$(PROJ_MAKEFILE_NAME)\
	\

prep:	prep.files.for.os


CHECK_FILE_lib_dir	=	$(PROJ_LIB_DIR)\.dir_exists
CHECK_FILE_bin_dir	=	$(PROJ_BIN_DIR)\.dir_exists

check.lib.dir:		$(PROJ_MAKEFILE_NAME) $(CHECK_FILE_lib_dir)

$(CHECK_FILE_lib_dir):
	@mkdir -p $(PROJ_LIB_DIR)
	@touch $(CHECK_FILE_lib_dir)

check.bin.dir:		$(PROJ_MAKEFILE_NAME) $(CHECK_FILE_bin_dir)

$(CHECK_FILE_bin_dir):
	@mkdir -p $(PROJ_BIN_DIR)
	@touch $(CHECK_FILE_bin_dir)


# compile targets

compile.libs.util:          $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_UTIL)

compile.libs.core:          $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_CORE)

compile.libs.fe:            $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_FE)

compile.libs.be:            $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_BE)

compile.libs: \
 compile.libs.util \
 compile.libs.core \
 compile.libs.fe \
 compile.libs.be \
 \

!ifdef PANTHEIOS_NO_B64
compile.libs.b64:           $(PROJ_MAKEFILE_NAME)   prep.files.for.os
!else
compile.libs.b64:           $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_B64)
!endif # !PANTHEIOS_NO_B64

compile.libs.shwild:        $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_SHWILD)

compile.libs.xcontract:     $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_XCONTRACT)

compile.libs.xtests:        $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_XTESTS)

compile.libs.3pty:	\
 compile.libs.b64 \
 compile.libs.shwild \
 compile.libs.xcontract \
 compile.libs.xtests

compile.libs.all: \
 compile.libs \
 compile.libs.3pty \
 \

!ifdef ACE
compile.ace:                $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_ACE)

!endif # ACE
compile.ex.c:               $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_EXAMPLE_C)

compile.ex.cpp:             $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_EXAMPLE_CPP)

compile.examples:           $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_EXAMPLE)

compile.samples:            $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_SAMPLE)

compile.test.component:     $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_TEST_COMPONENT)

compile.test.performance:   $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_TEST_PERFORMANCE)

compile.test.scratch:       $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_TEST_SCRATCH)

compile.test.unit:          $(PROJ_MAKEFILE_NAME)   prep.files.for.os   $(OBJS_TEST_UNIT)

compile.test:                                                           compile.test.unit compile.test.component

compile.test.all:                                                       compile.test.unit compile.test.component compile.test.performance compile.test.scratch

compile:                                                                compile.libs compile.libs.3pty compile.examples compile.test

!ifdef ACE
compile.all:                                                            compile.libs compile.examples compile.test compile.ace
!else # ACE
compile.all:                                                            compile.libs compile.examples compile.test
!endif # ACE


# build targets

build.libs.util:            check.lib.dir           prep.files.for.os   $(TARGETS_LIB_UTIL)

build.libs.core:            check.lib.dir           prep.files.for.os   $(TARGETS_LIB_CORE)

build.libs.appl:            check.lib.dir           prep.files.for.os   $(TARGETS_LIB_APPL)

build.libs.fe:              check.lib.dir           prep.files.for.os   $(TARGETS_LIB_FE)

build.libs.be:              check.lib.dir           prep.files.for.os   $(TARGETS_LIB_BE)

build.libs.fe.cmn:          check.lib.dir           prep.files.for.os   $(TARGETS_LIB_FE_CMN)

build.libs.be.cmn:          check.lib.dir           prep.files.for.os   $(TARGETS_LIB_BE_CMN)
!ifdef PANTHEIOS_NO_B64

build.libs.b64:             check.lib.dir           prep.files.for.os
!else

build.libs.b64:             check.lib.dir           prep.files.for.os   $(TARGETS_LIB_B64)
!endif # !PANTHEIOS_NO_B64

build.libs.shwild:          check.lib.dir           prep.files.for.os   $(TARGETS_LIB_SHWILD)

build.libs.xcontract:       check.lib.dir           prep.files.for.os   $(TARGETS_LIB_XCONTRACT)

build.libs.xtests:          check.lib.dir           prep.files.for.os   $(TARGETS_LIB_XTESTS)

build.libs.3pty:	\
 check.lib.dir \
 build.libs.b64 \
 build.libs.shwild \
 build.libs.xcontract \
 build.libs.xtests

# obsolete
build.libs.std:                                                         check.lib.dir build.libs.fe build.libs.be

!ifdef ACE
build.libs.ace:                                                         check.lib.dir $(TARGETS_LIB_ACE)

!endif # ACE
build.libs: \
 build.libs.util \
 build.libs.appl \
 build.libs.core \
 build.libs.fe \
 build.libs.be \
 \

!ifdef ACE
build.libs.all:                                                         build.libs build.libs.ace
!else # ACE
build.libs.all:                                                         build.libs
!endif # ACE

# These names - i.e. build.ex.?? - has to be short (rather than build.examples.??), otherwise GCC's
# make gets confused.
#
# Can't use C++ (or C++) because DMC++'s make can't handle it
build.ex.c:                 check.bin.dir           prep.files.for.os   $(TARGETS_EXAMPLE_C)

build.ex.cpp:               check.bin.dir           prep.files.for.os   $(TARGETS_EXAMPLE_CPP)

build.examples:             check.bin.dir           prep.files.for.os   $(TARGETS_EXAMPLE)

build.samples:              check.bin.dir           prep.files.for.os   $(TARGETS_SAMPLE)

build.test.component:       check.bin.dir           prep.files.for.os   $(TARGETS_TEST_COMPONENT)

build.test.performance:     check.bin.dir           prep.files.for.os   $(TARGETS_TEST_PERFORMANCE)

build.test.scratch:         check.bin.dir           prep.files.for.os   $(TARGETS_TEST_SCRATCH)

build.test.unit:            check.bin.dir           prep.files.for.os   $(TARGETS_TEST_UNIT)

build.test:                                                             build.test.unit build.test.component build.test.performance build.test.scratch

build.test.std:             check.bin.dir           prep.files.for.os   $(TARGETS_TEST_SCRATCH_STD)

!ifdef ACE
build.test.ace:             check.bin.dir           prep.files.for.os   $(TARGETS_TEST_SCRATCH_ACE)

!endif # ACE
build.test.std:             check.bin.dir           prep.files.for.os   $(TARGETS_TEST_SCRATCH_STD)

!ifdef ACE
build.test.ace:             check.bin.dir           prep.files.for.os   $(TARGETS_TEST_SCRATCH_ACE)

!endif # ACE
build.std:                                                              build.libs.util build.libs.core build.libs.appl build.libs.fe build.libs.be build.test.std

!ifdef ACE
build.test.all:                                                         build.test.std build.test.ace
!else # ACE
build.test.all:                                                         build.test.std
!endif # ACE


!ifdef ACE
build.ace:                                                              build.libs.ace build.test.ace

!endif # ACE
build:                                                                  build.libs build.examples build.samples build.test

build.cmn:                                                              build.libs.util build.libs.core build.libs.appl build.libs.fe.cmn build.libs.be.cmn

build.common:                                                           build.cmn

build.all:                                                              build.libs.all build.examples build.samples build.test.all


# test targets

test.component_:
	@echo Running Test:Component programs ...
	$(TARG_TEST_COMP_core_initseq_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_core_initseq_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_custsev_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_custsev_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_filemt_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_filemt_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_bec_fprtf_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_bec_fprtf_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_args_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_args_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
!ifndef PANTHEIOS_NO_B64
	$(TARG_TEST_COMP_ins_b64_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_b64_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
!endif # !PANTHEIOS_NO_B64
	$(TARG_TEST_COMP_ins_bool_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_bool_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_hostid_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_hostid_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_int_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_int_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_pad_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_pad_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_ptr_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_ptr_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_prid_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_prid_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_real_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_real_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_stm_ch_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_stm_ch_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_thrid_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_thrid_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_w2m_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_ins_w2m_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_log_1_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_log_1_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_pan_puts_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_pan_puts_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_pan_prtf_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_pan_prtf_UX_MT_R) --verbosity=$(TEST_VERBOSITY)

test.performance_:
	@echo Running Test:Performance programs ...
	$(TARG_TEST_PERF_ins_w2m_UX_MT_R) on
	$(TARG_TEST_PERF_ins_w2m_UX_MT_R) off
	$(TARG_TEST_PERF_dtel2s_UX_MT_R)

test.scratch_:
	@echo Running Test:Scratch programs ...
	$(TARG_SCRT_UX_MT_D_APIwBE_FPRINTF)
	$(TARG_SCRT_BE_SYSLOG_UX_MT_D)
	$(TARG_SCRT_BE_SYSLOGWC_UX_MT_D)
	$(TARG_SCRT_UX_MT_D_APIwBELR_1_FPRINTF_SYSLOG)
	$(TARG_SCRT_FE_UX_MT_D)
	$(TARG_SCRT_UX_MT_D_APIwBE_FPRINTF)
	$(TARG_SCRT_BE_N_FAIL_UX_MT_D)
	$(TARG_SCRT_FE_SIMPLE_WC_UX_MT_D)
	$(TARG_SCRT_UX_MT_R_APIwBE_FPRINTF)
	$(TARG_SCRT_BE_SYSLOG_UX_MT_R)
	$(TARG_SCRT_BE_SYSLOGWC_UX_MT_R)
	$(TARG_SCRT_UX_MT_R_APIwBELR_1_FPRINTF_SYSLOG)
	$(TARG_SCRT_FE_UX_MT_R)
	$(TARG_SCRT_UX_MT_R_APIwBE_FPRINTF)
	$(TARG_SCRT_BE_N_FAIL_UX_MT_R)
	$(TARG_SCRT_FE_SIMPLE_WC_UX_MT_R)

test.unit_:
	@echo Running Test:Unit programs ...
	$(TARG_TEST_UNIT_lvls_dyninit_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_lvls_dyninit_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_lvls_vals_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_lvls_vals_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_getcurrtm_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_getcurrtm_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_dtel2s_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_dtel2s_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_getversion_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_getversion_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_gethostname_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_gethostname_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_onbailout_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_onbailout_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snprintf_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_snprintf_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_strnlen_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_strnlen_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bec_file_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bec_file_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bec_fprintf_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bec_fprintf_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bec_fail_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_bec_fail_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_be_fail_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_be_fail_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_be_lrsplit_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_be_lrsplit_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_be_N_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_be_N_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_be_N_filt_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_be_N_filt_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fe_all_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fe_all_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fe_fail_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fe_fail_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fe_N_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fe_N_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fe_null_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fe_null_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fe_simple_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_fe_simple_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_int_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_int_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_w2m_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_stmc_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_w2m_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_ins_stmc_UX_MT_R) --verbosity=$(TEST_VERBOSITY)

test.examples_:
	@echo Running Example programs ...
	$(TARG_EX_C_0_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_C_1_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_C_2_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_C_3_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_C_4_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_C_5_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_C_7_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_C_0_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_C_1_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_C_2_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_C_3_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_C_4_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_C_5_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_C_7_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_be_01_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_be_02_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_be_03_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_be_04_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_be_05_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_be_06_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_cp_01_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_cp_02_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_fm_01_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_fm_02_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_fm_03_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_fe_01_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_01_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_02_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_03_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_04_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_05_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_06_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_07_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_08_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_09_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_10_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_11_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_13_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_14_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_15_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_16_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_17_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ln_01_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ms_01_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ms_02_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ms_03_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ms_04_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ms_05_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ms_06_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ut_01_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_be_01_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_be_02_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_be_03_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_be_04_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_be_05_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_be_06_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_cp_01_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_cp_02_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_fm_01_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_fm_02_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_fm_03_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_fe_01_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_01_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_02_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_03_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_04_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_05_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_06_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_07_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_08_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_09_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_10_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_11_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_13_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_14_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_15_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_16_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_in_17_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ln_01_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ms_01_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ms_02_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ms_03_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ms_04_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ms_05_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ms_06_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_EX_P_ut_01_UX_MT_R) --verbosity=$(TEST_VERBOSITY)

test.component:		build.test.component test.component_

test.performance:	build.test.performance test.performance_

test.scratch:		build.test.scratch test.scratch_

test.unit:			build.test.unit test.unit_

test.examples:		build.examples test.examples_

!ifdef ACE
test.ace:			build.libs.ace build.libs.core $(TARGETS_TEST_SCRATCH_ACE)
	$(TARG_SCRT_ACE_UX_MT_D)
	$(TARG_SCRT_ACE_UX_MT_R)

!endif # ACE
test:                       test.unit test.component

!ifdef ACE
test.all:                   test.scratch test.examples test.performance test.ace test
!else # ACE
test.all:                   test.scratch test.examples test.performance test
!endif # ACE


# clean targets

clean.libs.util:
	@echo Cleaning Util libraries ...
	@-$(RM) $(LIB_UTIL_UX_MT_D)
	@-$(RM) $(OBJ_UTIL_UX_MT_D)
	@-$(RM) $(PDB_UTIL_UX_MT_D)
	@-$(RM) $(LIB_UTIL_UX_MT_R)
	@-$(RM) $(OBJ_UTIL_UX_MT_R)

clean.libs.appl:
	@echo Cleaning Appl libraries ...
	@-$(RM) $(LIB_APPL_UX_MT_D)
	@-$(RM) $(OBJ_APPL_UX_MT_D)
	@-$(RM) $(PDB_APPL_UX_MT_D)
	@-$(RM) $(LIB_APPL_UX_MT_R)
	@-$(RM) $(OBJ_APPL_UX_MT_R)

clean.libs.core: clean.libs.appl
	@echo Cleaning Core libraries ...
	@-$(RM) $(LIB_CORE_UX_MT_D)
	@-$(RM) $(OBJ_CORE_UX_MT_D)
	@-$(RM) $(PDB_CORE_UX_MT_D)
	@-$(RM) $(LIB_CORE_UX_MT_R)
	@-$(RM) $(OBJ_CORE_UX_MT_R)

clean.libs.be:
	@echo Cleaning Back-end libraries ...
	@-$(RM) $(LIB_BEC_STOCK_UX_MT_D)
	@-$(RM) $(LIB_BEC_STOCK_WC_UX_MT_D)
	@-$(RM) $(LIB_BE_LRSPLIT_UX_MT_D)
	@-$(RM) $(LIB_BE_N_UX_MT_D)
	@-$(RM) $(LIB_BEC_TEST_UX_MT_D)
	@-$(RM) $(LIB_BE_TEST_UX_MT_D)
	@-$(RM) $(LIB_BEL_TEST_UX_MT_D)
	@-$(RM) $(LIB_BER_TEST_UX_MT_D)
	@-$(RM) $(LIB_BEC_FAIL_UX_MT_D)
	@-$(RM) $(LIB_BE_FAIL_UX_MT_D)
	@-$(RM) $(LIB_BEL_FAIL_UX_MT_D)
	@-$(RM) $(LIB_BER_FAIL_UX_MT_D)
	@-$(RM) $(LIB_BEC_FILE_UX_MT_D)
	@-$(RM) $(LIB_BEC_FILE_WC_UX_MT_D)
	@-$(RM) $(LIB_BE_FILE_UX_MT_D)
	@-$(RM) $(LIB_BEL_FILE_UX_MT_D)
	@-$(RM) $(LIB_BER_FILE_UX_MT_D)
	@-$(RM) $(LIB_BEC_FPRINTF_UX_MT_D)
	@-$(RM) $(LIB_BEC_FPRINTF_WC_UX_MT_D)
	@-$(RM) $(LIB_BE_FPRINTF_UX_MT_D)
	@-$(RM) $(LIB_BEL_FPRINTF_UX_MT_D)
	@-$(RM) $(LIB_BER_FPRINTF_UX_MT_D)
	@-$(RM) $(LIB_BEC_NULL_UX_MT_D)
	@-$(RM) $(LIB_BE_NULL_UX_MT_D)
	@-$(RM) $(LIB_BEL_NULL_UX_MT_D)
	@-$(RM) $(LIB_BER_NULL_UX_MT_D)
	@-$(RM) $(LIB_BEC_SYSLOG_UX_MT_D)
	@-$(RM) $(LIB_BEC_SYSLOGWC_UX_MT_D)
	@-$(RM) $(LIB_BE_SYSLOG_UX_MT_D)
	@-$(RM) $(LIB_BER_SYSLOG_UX_MT_D)
	@-$(RM) $(PDB_BE_LRSPLIT_UX_MT_D)
	@-$(RM) $(PDB_BE_N_UX_MT_D)
	@-$(RM) $(PDB_BEC_FAIL_UX_MT_D)
	@-$(RM) $(PDB_BE_FAIL_UX_MT_D)
	@-$(RM) $(PDB_BEL_FAIL_UX_MT_D)
	@-$(RM) $(PDB_BER_FAIL_UX_MT_D)
	@-$(RM) $(PDB_BEC_FILE_UX_MT_D)
	@-$(RM) $(PDB_BEC_FILE_WC_UX_MT_D)
	@-$(RM) $(PDB_BE_FILE_UX_MT_D)
	@-$(RM) $(PDB_BEL_FILE_UX_MT_D)
	@-$(RM) $(PDB_BER_FILE_UX_MT_D)
	@-$(RM) $(PDB_BEC_FPRINTF_UX_MT_D)
	@-$(RM) $(PDB_BEC_FPRINTF_WC_UX_MT_D)
	@-$(RM) $(PDB_BE_FPRINTF_UX_MT_D)
	@-$(RM) $(PDB_BEL_FPRINTF_UX_MT_D)
	@-$(RM) $(PDB_BER_FPRINTF_UX_MT_D)
	@-$(RM) $(PDB_BEC_NULL_UX_MT_D)
	@-$(RM) $(PDB_BE_NULL_UX_MT_D)
	@-$(RM) $(PDB_BEL_NULL_UX_MT_D)
	@-$(RM) $(PDB_BER_NULL_UX_MT_D)
	@-$(RM) $(PDB_BEC_SYSLOG_UX_MT_D)
	@-$(RM) $(PDB_BEC_SYSLOGWC_UX_MT_D)
	@-$(RM) $(PDB_BE_SYSLOG_UX_MT_D)
	@-$(RM) $(PDB_BER_SYSLOG_UX_MT_D)
	@-$(RM) $(OBJ_BE_LRSPLIT_UX_MT_D)
	@-$(RM) $(OBJ_BE_N_UX_MT_D)
	@-$(RM) $(OBJ_BEC_TEST_UX_MT_D)
	@-$(RM) $(OBJ_BE_TEST_UX_MT_D)
	@-$(RM) $(OBJ_BEL_TEST_UX_MT_D)
	@-$(RM) $(OBJ_BER_TEST_UX_MT_D)
	@-$(RM) $(OBJ_BEC_FAIL_UX_MT_D)
	@-$(RM) $(OBJ_BE_FAIL_UX_MT_D)
	@-$(RM) $(OBJ_BEL_FAIL_UX_MT_D)
	@-$(RM) $(OBJ_BER_FAIL_UX_MT_D)
	@-$(RM) $(OBJ_BEC_FILE_UX_MT_D)
	@-$(RM) $(OBJ_BEC_FILE_WC_UX_MT_D)
	@-$(RM) $(OBJ_BE_FILE_UX_MT_D)
	@-$(RM) $(OBJ_BEL_FILE_UX_MT_D)
	@-$(RM) $(OBJ_BER_FILE_UX_MT_D)
	@-$(RM) $(OBJ_BEC_FPRINTF_UX_MT_D)
	@-$(RM) $(OBJ_BEC_FPRINTF_WC_UX_MT_D)
	@-$(RM) $(OBJ_BE_FPRINTF_UX_MT_D)
	@-$(RM) $(OBJ_BEL_FPRINTF_UX_MT_D)
	@-$(RM) $(OBJ_BER_FPRINTF_UX_MT_D)
	@-$(RM) $(OBJ_BEC_NULL_UX_MT_D)
	@-$(RM) $(OBJ_BE_NULL_UX_MT_D)
	@-$(RM) $(OBJ_BEL_NULL_UX_MT_D)
	@-$(RM) $(OBJ_BER_NULL_UX_MT_D)
	@-$(RM) $(OBJ_BEC_SYSLOG_UX_MT_D)
	@-$(RM) $(OBJ_BEC_SYSLOGWC_UX_MT_D)
	@-$(RM) $(OBJ_BE_SYSLOG_UX_MT_D)
	@-$(RM) $(OBJ_BER_SYSLOG_UX_MT_D)
	@-$(RM) $(LIB_BEC_STOCK_UX_MT_R)
	@-$(RM) $(LIB_BEC_STOCK_WC_UX_MT_R)
	@-$(RM) $(LIB_BE_LRSPLIT_UX_MT_R)
	@-$(RM) $(LIB_BE_N_UX_MT_R)
	@-$(RM) $(LIB_BEC_TEST_UX_MT_R)
	@-$(RM) $(LIB_BE_TEST_UX_MT_R)
	@-$(RM) $(LIB_BEL_TEST_UX_MT_R)
	@-$(RM) $(LIB_BER_TEST_UX_MT_R)
	@-$(RM) $(LIB_BEC_FAIL_UX_MT_R)
	@-$(RM) $(LIB_BE_FAIL_UX_MT_R)
	@-$(RM) $(LIB_BEL_FAIL_UX_MT_R)
	@-$(RM) $(LIB_BER_FAIL_UX_MT_R)
	@-$(RM) $(LIB_BEC_FILE_UX_MT_R)
	@-$(RM) $(LIB_BEC_FILE_WC_UX_MT_R)
	@-$(RM) $(LIB_BE_FILE_UX_MT_R)
	@-$(RM) $(LIB_BEL_FILE_UX_MT_R)
	@-$(RM) $(LIB_BER_FILE_UX_MT_R)
	@-$(RM) $(LIB_BEC_FPRINTF_UX_MT_R)
	@-$(RM) $(LIB_BEC_FPRINTF_WC_UX_MT_R)
	@-$(RM) $(LIB_BE_FPRINTF_UX_MT_R)
	@-$(RM) $(LIB_BEL_FPRINTF_UX_MT_R)
	@-$(RM) $(LIB_BER_FPRINTF_UX_MT_R)
	@-$(RM) $(LIB_BEC_NULL_UX_MT_R)
	@-$(RM) $(LIB_BE_NULL_UX_MT_R)
	@-$(RM) $(LIB_BEL_NULL_UX_MT_R)
	@-$(RM) $(LIB_BER_NULL_UX_MT_R)
	@-$(RM) $(LIB_BEC_SYSLOG_UX_MT_R)
	@-$(RM) $(LIB_BEC_SYSLOGWC_UX_MT_R)
	@-$(RM) $(LIB_BE_SYSLOG_UX_MT_R)
	@-$(RM) $(LIB_BER_SYSLOG_UX_MT_R)
	@-$(RM) $(OBJ_BE_LRSPLIT_UX_MT_R)
	@-$(RM) $(OBJ_BE_N_UX_MT_R)
	@-$(RM) $(OBJ_BEC_TEST_UX_MT_R)
	@-$(RM) $(OBJ_BE_TEST_UX_MT_R)
	@-$(RM) $(OBJ_BEL_TEST_UX_MT_R)
	@-$(RM) $(OBJ_BER_TEST_UX_MT_R)
	@-$(RM) $(OBJ_BEC_FAIL_UX_MT_R)
	@-$(RM) $(OBJ_BE_FAIL_UX_MT_R)
	@-$(RM) $(OBJ_BEL_FAIL_UX_MT_R)
	@-$(RM) $(OBJ_BER_FAIL_UX_MT_R)
	@-$(RM) $(OBJ_BEC_FILE_UX_MT_R)
	@-$(RM) $(OBJ_BEC_FILE_WC_UX_MT_R)
	@-$(RM) $(OBJ_BE_FILE_UX_MT_R)
	@-$(RM) $(OBJ_BEL_FILE_UX_MT_R)
	@-$(RM) $(OBJ_BER_FILE_UX_MT_R)
	@-$(RM) $(OBJ_BEC_FPRINTF_UX_MT_R)
	@-$(RM) $(OBJ_BEC_FPRINTF_WC_UX_MT_R)
	@-$(RM) $(OBJ_BE_FPRINTF_UX_MT_R)
	@-$(RM) $(OBJ_BEL_FPRINTF_UX_MT_R)
	@-$(RM) $(OBJ_BER_FPRINTF_UX_MT_R)
	@-$(RM) $(OBJ_BEC_NULL_UX_MT_R)
	@-$(RM) $(OBJ_BE_NULL_UX_MT_R)
	@-$(RM) $(OBJ_BEL_NULL_UX_MT_R)
	@-$(RM) $(OBJ_BER_NULL_UX_MT_R)
	@-$(RM) $(OBJ_BEC_SYSLOG_UX_MT_R)
	@-$(RM) $(OBJ_BEC_SYSLOGWC_UX_MT_R)
	@-$(RM) $(OBJ_BE_SYSLOG_UX_MT_R)
	@-$(RM) $(OBJ_BER_SYSLOG_UX_MT_R)

clean.libs.fe:
	@echo Cleaning Front-end libraries ...
	@-$(RM) $(LIB_FE_ALL_UX_MT_D)
	@-$(RM) $(LIB_FE_ALL_WC_UX_MT_D)
	@-$(RM) $(LIB_FE_FAIL_UX_MT_D)
	@-$(RM) $(LIB_FE_N_UX_MT_D)
	@-$(RM) $(LIB_FE_N_WC_UX_MT_D)
	@-$(RM) $(LIB_FE_NULL_UX_MT_D)
	@-$(RM) $(LIB_FE_NULL_WC_UX_MT_D)
	@-$(RM) $(LIB_FE_SIMPLE_UX_MT_D)
	@-$(RM) $(LIB_FE_SIMPLE_WC_UX_MT_D)
	@-$(RM) $(OBJ_FE_ALL_UX_MT_D)
	@-$(RM) $(OBJ_FE_ALL_WC_UX_MT_D)
	@-$(RM) $(OBJ_FE_FAIL_UX_MT_D)
	@-$(RM) $(OBJ_FE_N_UX_MT_D)
	@-$(RM) $(OBJ_FE_N_WC_UX_MT_D)
	@-$(RM) $(OBJ_FE_NULL_UX_MT_D)
	@-$(RM) $(OBJ_FE_NULL_WC_UX_MT_D)
	@-$(RM) $(OBJ_FE_SIMPLE_UX_MT_D)
	@-$(RM) $(OBJ_FE_SIMPLE_WC_UX_MT_D)
	@-$(RM) $(PDB_FE_ALL_UX_MT_D)
	@-$(RM) $(PDB_FE_FAIL_UX_MT_D)
	@-$(RM) $(PDB_FE_N_UX_MT_D)
	@-$(RM) $(PDB_FE_NULL_UX_MT_D)
	@-$(RM) $(PDB_FE_SIMPLE_UX_MT_D)
	@-$(RM) $(LIB_FE_ALL_UX_MT_R)
	@-$(RM) $(LIB_FE_ALL_WC_UX_MT_R)
	@-$(RM) $(LIB_FE_FAIL_UX_MT_R)
	@-$(RM) $(LIB_FE_N_UX_MT_R)
	@-$(RM) $(LIB_FE_N_WC_UX_MT_R)
	@-$(RM) $(LIB_FE_NULL_UX_MT_R)
	@-$(RM) $(LIB_FE_NULL_WC_UX_MT_R)
	@-$(RM) $(LIB_FE_SIMPLE_UX_MT_R)
	@-$(RM) $(LIB_FE_SIMPLE_WC_UX_MT_R)
	@-$(RM) $(OBJ_FE_ALL_UX_MT_R)
	@-$(RM) $(OBJ_FE_ALL_WC_UX_MT_R)
	@-$(RM) $(OBJ_FE_FAIL_UX_MT_R)
	@-$(RM) $(OBJ_FE_N_UX_MT_R)
	@-$(RM) $(OBJ_FE_N_WC_UX_MT_R)
	@-$(RM) $(OBJ_FE_NULL_UX_MT_R)
	@-$(RM) $(OBJ_FE_NULL_WC_UX_MT_R)
	@-$(RM) $(OBJ_FE_SIMPLE_UX_MT_R)
	@-$(RM) $(OBJ_FE_SIMPLE_WC_UX_MT_R)
!ifdef PANTHEIOS_NO_B64

clean.libs.b64:
	@echo No b64 libraries to clean
!else

clean.libs.b64:
	@echo Cleaning b64 libraries ...
	@-$(RM) $(LIB_B64_UX_MT_D)
	@-$(RM) $(LIB_B64_UX_MT_R)
	@-$(RM) $(OBJ_B64_UX_MT_D)
	@-$(RM) $(PDB_B64_UX_MT_D)
	@-$(RM) $(OBJ_B64_UX_MT_R)
!endif # !PANTHEIOS_NO_B64

clean.libs.shwild:
	@echo Cleaning shwild libraries ...
	@-$(RM) $(LIB_SHWILD_UX_MT_D)
	@-$(RM) $(LIB_SHWILD_UX_MT_R)
	@-$(RM) $(OBJ_SHWILD_UX_MT_D)
	@-$(RM) $(PDB_SHWILD_UX_MT_D)
	@-$(RM) $(OBJ_SHWILD_UX_MT_R)

clean.libs.xcontract:
	@echo Cleaning xContract libraries ...
	@-$(RM) $(LIB_XCONTRACT_UX_MT_D)
	@-$(RM) $(LIB_XCONTRACT_UX_MT_R)
	@-$(RM) $(OBJ_XCONTRACT_UX_MT_D)
	@-$(RM) $(PDB_XCONTRACT_UX_MT_D)
	@-$(RM) $(OBJ_XCONTRACT_UX_MT_R)

clean.libs.xtests:
	@echo Cleaning xTests libraries ...
	@-$(RM) $(LIB_XTESTS_UX_MT_D)
	@-$(RM) $(LIB_XTESTS_UX_MT_R)
	@-$(RM) $(OBJ_XTESTS_UX_MT_D)
	@-$(RM) $(PDB_XTESTS_UX_MT_D)
	@-$(RM) $(OBJ_XTESTS_UX_MT_R)

!ifdef ACE
clean.libs.ace:
	@echo Cleaning ACE libraries ...
	@-$(RM) $(LIB_BEC_ACE_UX_MT_D)
	@-$(RM) $(LIB_BE_ACE_UX_MT_D)
	@-$(RM) $(LIB_BEL_ACE_UX_MT_D)
	@-$(RM) $(LIB_BER_ACE_UX_MT_D)
	@-$(RM) $(LIB_BEC_ACE_UX_MT_R)
	@-$(RM) $(LIB_BE_ACE_UX_MT_R)
	@-$(RM) $(LIB_BEL_ACE_UX_MT_R)
	@-$(RM) $(LIB_BER_ACE_UX_MT_R)
	@-$(RM) $(OBJ_BEC_ACE_UX_MT_D)
	@-$(RM) $(OBJ_BE_ACE_UX_MT_D)
	@-$(RM) $(OBJ_BEL_ACE_UX_MT_D)
	@-$(RM) $(OBJ_BER_ACE_UX_MT_D)
	@-$(RM) $(OBJ_BEC_ACE_UX_MT_R)
	@-$(RM) $(OBJ_BE_ACE_UX_MT_R)
	@-$(RM) $(OBJ_BEL_ACE_UX_MT_R)
	@-$(RM) $(OBJ_BER_ACE_UX_MT_R)
!endif # ACE

clean.examples:
	@echo Cleaning examples ...
	@-$(RM) $(TARG_EX_P_be_01_UX_MT_D)
	@-$(RM) $(TARG_EX_P_be_02_UX_MT_D)
	@-$(RM) $(TARG_EX_P_be_03_UX_MT_D)
	@-$(RM) $(TARG_EX_P_be_04_UX_MT_D)
	@-$(RM) $(TARG_EX_P_be_05_UX_MT_D)
	@-$(RM) $(TARG_EX_P_be_06_UX_MT_D)
	@-$(RM) $(TARG_EX_P_cp_01_UX_MT_D)
	@-$(RM) $(TARG_EX_P_cp_02_UX_MT_D)
	@-$(RM) $(TARG_EX_P_fm_01_UX_MT_D)
	@-$(RM) $(TARG_EX_P_fm_02_UX_MT_D)
	@-$(RM) $(TARG_EX_P_fm_03_UX_MT_D)
	@-$(RM) $(TARG_EX_P_fe_01_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_01_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_02_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_03_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_04_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_05_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_06_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_07_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_08_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_09_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_10_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_11_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_12_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_13_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_14_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_15_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_16_UX_MT_D)
	@-$(RM) $(TARG_EX_P_in_17_UX_MT_D)
	@-$(RM) $(TARG_EX_P_ln_01_UX_MT_D)
	@-$(RM) $(TARG_EX_P_ms_01_UX_MT_D)
	@-$(RM) $(TARG_EX_P_ms_02_UX_MT_D)
	@-$(RM) $(TARG_EX_P_ms_03_UX_MT_D)
	@-$(RM) $(TARG_EX_P_ms_04_UX_MT_D)
	@-$(RM) $(TARG_EX_P_ms_05_UX_MT_D)
	@-$(RM) $(TARG_EX_P_ms_06_UX_MT_D)
	@-$(RM) $(TARG_EX_P_ut_01_UX_MT_D)
	@-$(RM) $(TARG_EX_C_0_UX_MT_D)
	@-$(RM) $(TARG_EX_C_1_UX_MT_D)
	@-$(RM) $(TARG_EX_C_2_UX_MT_D)
	@-$(RM) $(TARG_EX_C_3_UX_MT_D)
	@-$(RM) $(TARG_EX_C_4_UX_MT_D)
	@-$(RM) $(TARG_EX_C_5_UX_MT_D)
	@-$(RM) $(TARG_EX_C_6_UX_MT_D)
	@-$(RM) $(TARG_EX_C_7_UX_MT_D)
	@-$(RM) $(TARG_EX_P_be_01_UX_MT_R)
	@-$(RM) $(TARG_EX_P_be_02_UX_MT_R)
	@-$(RM) $(TARG_EX_P_be_03_UX_MT_R)
	@-$(RM) $(TARG_EX_P_be_04_UX_MT_R)
	@-$(RM) $(TARG_EX_P_be_05_UX_MT_R)
	@-$(RM) $(TARG_EX_P_be_06_UX_MT_R)
	@-$(RM) $(TARG_EX_P_cp_01_UX_MT_R)
	@-$(RM) $(TARG_EX_P_cp_02_UX_MT_R)
	@-$(RM) $(TARG_EX_P_fm_01_UX_MT_R)
	@-$(RM) $(TARG_EX_P_fm_02_UX_MT_R)
	@-$(RM) $(TARG_EX_P_fm_03_UX_MT_R)
	@-$(RM) $(TARG_EX_P_fe_01_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_01_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_02_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_03_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_04_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_05_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_06_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_07_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_08_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_09_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_10_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_11_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_12_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_13_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_14_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_15_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_16_UX_MT_R)
	@-$(RM) $(TARG_EX_P_in_17_UX_MT_R)
	@-$(RM) $(TARG_EX_P_ln_01_UX_MT_R)
	@-$(RM) $(TARG_EX_P_ms_01_UX_MT_R)
	@-$(RM) $(TARG_EX_P_ms_02_UX_MT_R)
	@-$(RM) $(TARG_EX_P_ms_03_UX_MT_R)
	@-$(RM) $(TARG_EX_P_ms_04_UX_MT_R)
	@-$(RM) $(TARG_EX_P_ms_05_UX_MT_R)
	@-$(RM) $(TARG_EX_P_ms_06_UX_MT_R)
	@-$(RM) $(TARG_EX_P_ut_01_UX_MT_R)
	@-$(RM) $(TARG_EX_C_0_UX_MT_R)
	@-$(RM) $(TARG_EX_C_1_UX_MT_R)
	@-$(RM) $(TARG_EX_C_2_UX_MT_R)
	@-$(RM) $(TARG_EX_C_3_UX_MT_R)
	@-$(RM) $(TARG_EX_C_4_UX_MT_R)
	@-$(RM) $(TARG_EX_C_5_UX_MT_R)
	@-$(RM) $(TARG_EX_C_6_UX_MT_R)
	@-$(RM) $(TARG_EX_C_7_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_be_01_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_be_02_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_be_03_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_be_04_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_be_05_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_be_06_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_cp_01_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_cp_02_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_fm_01_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_fm_02_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_fm_03_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_fe_01_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_01_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_02_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_03_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_04_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_05_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_06_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_07_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_08_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_09_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_10_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_11_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_12_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_13_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_14_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_15_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_16_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_in_17_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_ln_01_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_ms_01_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_ms_02_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_ms_03_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_ms_04_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_ms_05_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_ms_06_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_ut_01_UX_MT_D)
	@-$(RM) $(OBJ_EX_C_0_UX_MT_D)
	@-$(RM) $(OBJ_EX_C_1_UX_MT_D)
	@-$(RM) $(OBJ_EX_C_2_UX_MT_D)
	@-$(RM) $(OBJ_EX_C_3_UX_MT_D)
	@-$(RM) $(OBJ_EX_C_4_UX_MT_D)
	@-$(RM) $(OBJ_EX_C_5_UX_MT_D)
	@-$(RM) $(OBJ_EX_C_6_UX_MT_D)
	@-$(RM) $(OBJ_EX_C_7_UX_MT_D)
	@-$(RM) $(OBJ_EX_P_be_01_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_be_02_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_be_03_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_be_04_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_be_05_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_be_06_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_cp_01_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_cp_02_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_fm_01_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_fm_02_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_fm_03_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_fe_01_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_01_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_02_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_03_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_04_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_05_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_06_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_07_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_08_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_09_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_10_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_11_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_12_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_13_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_14_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_15_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_16_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_in_17_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_ln_01_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_ms_01_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_ms_02_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_ms_03_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_ms_04_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_ms_05_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_ms_06_UX_MT_R)
	@-$(RM) $(OBJ_EX_P_ut_01_UX_MT_R)
	@-$(RM) $(OBJ_EX_C_0_UX_MT_R)
	@-$(RM) $(OBJ_EX_C_1_UX_MT_R)
	@-$(RM) $(OBJ_EX_C_2_UX_MT_R)
	@-$(RM) $(OBJ_EX_C_3_UX_MT_R)
	@-$(RM) $(OBJ_EX_C_4_UX_MT_R)
	@-$(RM) $(OBJ_EX_C_5_UX_MT_R)
	@-$(RM) $(OBJ_EX_C_6_UX_MT_R)
	@-$(RM) $(OBJ_EX_C_7_UX_MT_R)
	@-$(RM) ex.cpp.*.pdb
	@-$(RM) ex.c.*.pdb

clean.samples:
	@echo Cleaning samples ...

clean.samples.all:	clean.samples

#	@-$(RM) $(TARGETS_SAMPLE)

clean.test.unit:
	@echo Cleaning unit tests ...
	@-$(RM) $(TARG_TEST_UNIT_lvls_dyninit_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_lvls_vals_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_getcurrtm_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_dtel2s_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_getversion_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_gethostname_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_onbailout_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_snprintf_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_strnlen_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_bec_file_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_bec_fprintf_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_bec_fail_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_be_fail_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_be_lrsplit_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_be_N_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_be_N_filt_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_fe_all_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_fe_fail_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_fe_N_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_fe_null_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_fe_simple_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_ins_int_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_ins_w2m_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_ins_stmc_UX_MT_D)
	@-$(RM) $(TARG_TEST_UNIT_lvls_dyninit_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_lvls_vals_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_getcurrtm_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_dtel2s_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_getversion_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_gethostname_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_onbailout_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_snprintf_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_strnlen_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_bec_file_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_bec_fprintf_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_bec_fail_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_be_fail_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_be_lrsplit_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_be_N_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_be_N_filt_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_fe_all_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_fe_fail_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_fe_N_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_fe_null_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_fe_simple_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_ins_int_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_ins_w2m_UX_MT_R)
	@-$(RM) $(TARG_TEST_UNIT_ins_stmc_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_lvls_dyninit_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_lvls_vals_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_getcurrtm_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_dtel2s_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_getversion_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_gethostname_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_onbailout_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_snprintf_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_strnlen_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_bec_file_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_bec_fprintf_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_bec_fail_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_be_fail_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_be_lrsplit_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_be_N_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_be_N_filt_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_fe_all_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_fe_fail_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_fe_N_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_fe_null_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_fe_simple_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_ins_int_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_ins_w2m_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_ins_stmc_UX_MT_D)
	@-$(RM) $(OBJ_TEST_UNIT_lvls_dyninit_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_lvls_vals_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_getcurrtm_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_dtel2s_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_getversion_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_gethostname_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_onbailout_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_snprintf_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_strnlen_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_bec_file_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_bec_fprintf_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_bec_fail_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_be_fail_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_be_lrsplit_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_be_N_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_be_N_filt_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_fe_all_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_fe_fail_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_fe_N_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_fe_null_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_fe_simple_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_ins_int_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_ins_w2m_UX_MT_R)
	@-$(RM) $(OBJ_TEST_UNIT_ins_stmc_UX_MT_R)

clean.test.component:
	@echo Cleaning component tests ...
	@-$(RM) $(TARG_TEST_COMP_core_initseq_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_custsev_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_filemt_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_bec_fprtf_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_ins_args_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_ins_b64_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_ins_bool_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_ins_hostid_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_ins_int_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_ins_pad_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_ins_ptr_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_ins_prid_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_ins_real_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_ins_slice_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_ins_stm_ch_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_ins_thrid_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_ins_w2m_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_log_1_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_pan_puts_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_pan_prtf_UX_MT_D)
	@-$(RM) $(TARG_TEST_COMP_core_initseq_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_custsev_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_filemt_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_bec_fprtf_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_ins_args_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_ins_b64_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_ins_bool_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_ins_hostid_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_ins_int_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_ins_pad_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_ins_ptr_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_ins_prid_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_ins_real_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_ins_slice_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_ins_stm_ch_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_ins_thrid_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_ins_w2m_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_log_1_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_pan_puts_UX_MT_R)
	@-$(RM) $(TARG_TEST_COMP_pan_prtf_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_core_initseq_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_custsev_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_filemt_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_bec_fprtf_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_ins_args_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_ins_b64_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_ins_bool_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_ins_hostid_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_ins_int_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_ins_pad_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_ins_ptr_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_ins_prid_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_ins_real_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_ins_slice_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_ins_w2m_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_ins_stm_ch_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_ins_thrid_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_log_1_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_pan_puts_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_pan_prtf_UX_MT_D)
	@-$(RM) $(OBJ_TEST_COMP_core_initseq_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_custsev_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_filemt_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_bec_fprtf_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_ins_args_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_ins_b64_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_ins_bool_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_ins_hostid_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_ins_int_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_ins_pad_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_ins_ptr_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_ins_prid_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_ins_real_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_ins_slice_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_ins_w2m_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_ins_stm_ch_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_ins_thrid_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_log_1_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_pan_puts_UX_MT_R)
	@-$(RM) $(OBJ_TEST_COMP_pan_prtf_UX_MT_R)

clean.test.performance:
	@echo Cleaning performance tests ...
	@-$(RM) $(TARG_TEST_PERF_ins_w2m_UX_MT_D)
	@-$(RM) $(TARG_TEST_PERF_dtel2s_UX_MT_D)
	@-$(RM) $(TARG_TEST_PERF_ins_w2m_UX_MT_R)
	@-$(RM) $(TARG_TEST_PERF_dtel2s_UX_MT_R)
	@-$(RM) $(OBJ_TEST_PERF_ins_w2m_UX_MT_D)
	@-$(RM) $(OBJ_TEST_PERF_dtel2s_UX_MT_D)
	@-$(RM) $(OBJ_TEST_PERF_ins_w2m_UX_MT_R)
	@-$(RM) $(OBJ_TEST_PERF_dtel2s_UX_MT_R)

clean.test.scratch:
	@echo Cleaning scratch tests ...
	@-$(RM) $(TARG_SCRT_UX_MT_D_APIwBE_FPRINTF)
	@-$(RM) $(TARG_SCRT_BE_SYSLOG_UX_MT_D)
	@-$(RM) $(TARG_SCRT_BE_SYSLOGWC_UX_MT_D)
	@-$(RM) $(TARG_SCRT_UX_MT_D_APIwBELR_1_FPRINTF_SYSLOG)
	@-$(RM) $(TARG_SCRT_FE_UX_MT_D)
	@-$(RM) $(TARG_SCRT_BE_N_FAIL_UX_MT_D)
	@-$(RM) $(TARG_SCRT_FE_SIMPLE_WC_UX_MT_D)
	@-$(RM) $(TARG_SCRT_UX_MT_R_APIwBE_FPRINTF)
	@-$(RM) $(TARG_SCRT_BE_SYSLOG_UX_MT_R)
	@-$(RM) $(TARG_SCRT_BE_SYSLOGWC_UX_MT_R)
	@-$(RM) $(TARG_SCRT_UX_MT_R_APIwBELR_1_FPRINTF_SYSLOG)
	@-$(RM) $(TARG_SCRT_FE_UX_MT_R)
	@-$(RM) $(TARG_SCRT_BE_N_FAIL_UX_MT_R)
	@-$(RM) $(TARG_SCRT_FE_SIMPLE_WC_UX_MT_R)
	@-$(RM) $(OBJ_SCRT_UX_MT_D_APIwBE_FPRINTF)
	@-$(RM) $(OBJ_SCRT_BE_SYSLOG_UX_MT_D)
	@-$(RM) $(OBJ_SCRT_BE_SYSLOGWC_UX_MT_D)
	@-$(RM) $(OBJ_SCRT_UX_MT_D_APIwBELR_1_FPRINTF_SYSLOG)
	@-$(RM) $(OBJ_SCRT_FE_UX_MT_D)
	@-$(RM) $(OBJ_SCRT_BE_N_FAIL_UX_MT_D)
	@-$(RM) $(OBJ_SCRT_FE_SIMPLE_WC_UX_MT_D)
	@-$(RM) $(OBJ_SCRT_UX_MT_R_APIwBE_FPRINTF)
	@-$(RM) $(OBJ_SCRT_BE_SYSLOG_UX_MT_R)
	@-$(RM) $(OBJ_SCRT_BE_SYSLOGWC_UX_MT_R)
	@-$(RM) $(OBJ_SCRT_UX_MT_R_APIwBELR_1_FPRINTF_SYSLOG)
	@-$(RM) $(OBJ_SCRT_FE_UX_MT_R)
	@-$(RM) $(OBJ_SCRT_BE_N_FAIL_UX_MT_R)
	@-$(RM) $(OBJ_SCRT_FE_SIMPLE_WC_UX_MT_R)
	@-$(RM) test.scratch.api.mt.debug.obj
	@-$(RM) test.scratch.fe.mt.debug.obj
	@-$(RM) test.scratch.api.mt.debug.pdb
	@-$(RM) test.scratch.fe.mt.debug.pdb
	@-$(RM) test.scratch.api.mt.obj
	@-$(RM) test.scratch.fe.mt.obj
	@-$(RM) $(OBJ_SCRT_API_UX_MT_D)
	@-$(RM) $(OBJ_SCRT_FE_UX_MT_D)
	@-$(RM) $(OBJ_SCRT_BE_N_UX_MT_D)
	@-$(RM) $(OBJ_SCRT_FE_SIMPLE_WC_UX_MT_D)
	@-$(RM) $(OBJ_SCRT_API_UX_MT_R)
	@-$(RM) $(OBJ_SCRT_FE_UX_MT_R)
	@-$(RM) $(OBJ_SCRT_BE_N_UX_MT_R)
	@-$(RM) $(OBJ_SCRT_FE_SIMPLE_WC_UX_MT_R)

!ifdef ACE
clean.test.ace:
	@echo Cleaning ACE tests ...
	@-$(RM) $(TARG_SCRT_ACE_UX_MT_D)
	@-$(RM) $(TARG_SCRT_ACE_UX_MT_R)
!endif # ACE

clean.unittest.std:
	@echo Cleaning standard unittests ...

!ifdef ACE
clean.unittest.ace:
	@echo Cleaning ACE unittests ...
!endif # ACE


clean.libs:		\
 clean.libs.util \
 clean.libs.appl \
 clean.libs.core \
 clean.libs.fe \
 clean.libs.be \
 \

clean.libs.3pty:	\
 clean.libs.b64 \
 clean.libs.shwild \
 clean.libs.xcontract \
 clean.libs.xtests \
 \

clean.libs.all:	\
 clean.libs \
 clean.libs.3pty \
 \

clean.test:	\
 clean.test.unit \
 clean.test.component \
 clean.test.scratch \
 clean.test.performance \
 \

!ifdef ACE
clean.test.all:		clean.test clean.libs.3pty clean.test.ace
!else # ACE
clean.test.all:		clean.test clean.libs.3pty
!endif # ACE

clean.unittest:		clean.unittest.std

!ifdef ACE
clean.unittest.all:	clean.unittest.std clean.unittest.ace
!else # ACE
clean.unittest.all:	clean.unittest.std
!endif # ACE

clean.std:			clean.libs clean.test

!ifdef ACE
clean.ace:			clean.libs.ace clean.test.ace

!endif # ACE
clean.logs:
	@echo Cleaning any log files created in testing ...
	@-$(RM) *.log

clean:				clean.libs clean.libs.3pty clean.examples clean.samples clean.test clean.unittest clean.logs

clean.all:			clean.libs.all clean.examples clean.samples.all clean.test.all clean.unittest.all

# obsolete targets
target:				build.core

test-all:			test.all

############################################################################
# build targets

##################################################
# libraries

########################################
# Main library - 'pantheios.X.util.a'

$(LIB_UTIL_UX_MT_D): $(OBJ_UTIL_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_UTIL_UX_MT_D)

$(OBJ_utl_bailout_UX_MT_D): $(PROJ_SRC_DIR)\util\bailout.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\bailout.c
$(OBJ_utl_dtel2s_UX_MT_D): $(PROJ_SRC_DIR)\util\date_elements_to_string.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\date_elements_to_string.c
$(OBJ_utl_init_code_strs_UX_MT_D): $(PROJ_SRC_DIR)\util\init_code_strings.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\init_code_strings.c
$(OBJ_utl_sev_strs_UX_MT_D): $(PROJ_SRC_DIR)\util\severity_strings.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\severity_strings.c
$(OBJ_utl_time_UX_MT_D): $(PROJ_SRC_DIR)\util\time.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\time.cpp
$(OBJ_utl_host_name_UX_MT_D): $(PROJ_SRC_DIR)\util\hostname.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\hostname.c
$(OBJ_utl_snprintf_UX_MT_D): $(PROJ_SRC_DIR)\util\snprintf.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\snprintf.c
$(OBJ_utl_strdup_UX_MT_D): $(PROJ_SRC_DIR)\util\strdup.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\strdup.c
$(OBJ_utl_procid_UX_MT_D): $(PROJ_SRC_DIR)\util\processid.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\processid.c
$(OBJ_utl_thread_UX_MT_D): $(PROJ_SRC_DIR)\util\threadid.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\threadid.c
$(OBJ_utl_be_context_UX_MT_D): $(PROJ_SRC_DIR)\util\be.context.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\be.context.cpp
$(OBJ_utl_core_apidefs_UX_MT_D): $(PROJ_SRC_DIR)\util\core.apidefs.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\core.apidefs.cpp
$(OBJ_utl_be_parse_UX_MT_D): $(PROJ_SRC_DIR)\util\be.parse.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\be.parse.cpp
$(OBJ_utl_strnlenp_UX_MT_D): $(PROJ_SRC_DIR)\util\strnlen.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\strnlen.cpp
$(OBJ_utl_strnlen_UX_MT_D): $(PROJ_SRC_DIR)\util\util.strnlen.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\util.strnlen.c

$(LIB_UTIL_UX_MT_R): $(OBJ_UTIL_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_UTIL_UX_MT_R)

$(OBJ_utl_bailout_UX_MT_R): $(PROJ_SRC_DIR)\util\bailout.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\bailout.c
$(OBJ_utl_dtel2s_UX_MT_R): $(PROJ_SRC_DIR)\util\date_elements_to_string.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\date_elements_to_string.c
$(OBJ_utl_init_code_strs_UX_MT_R): $(PROJ_SRC_DIR)\util\init_code_strings.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\init_code_strings.c
$(OBJ_utl_sev_strs_UX_MT_R): $(PROJ_SRC_DIR)\util\severity_strings.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\severity_strings.c
$(OBJ_utl_time_UX_MT_R): $(PROJ_SRC_DIR)\util\time.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\time.cpp
$(OBJ_utl_host_name_UX_MT_R): $(PROJ_SRC_DIR)\util\hostname.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\hostname.c
$(OBJ_utl_snprintf_UX_MT_R): $(PROJ_SRC_DIR)\util\snprintf.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\snprintf.c
$(OBJ_utl_strdup_UX_MT_R): $(PROJ_SRC_DIR)\util\strdup.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\strdup.c
$(OBJ_utl_procid_UX_MT_R): $(PROJ_SRC_DIR)\util\processid.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\processid.c
$(OBJ_utl_thread_UX_MT_R): $(PROJ_SRC_DIR)\util\threadid.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\threadid.c
$(OBJ_utl_be_context_UX_MT_R): $(PROJ_SRC_DIR)\util\be.context.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\be.context.cpp
$(OBJ_utl_core_apidefs_UX_MT_R): $(PROJ_SRC_DIR)\util\core.apidefs.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\core.apidefs.cpp
$(OBJ_utl_be_parse_UX_MT_R): $(PROJ_SRC_DIR)\util\be.parse.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\be.parse.cpp
$(OBJ_utl_strnlenp_UX_MT_R): $(PROJ_SRC_DIR)\util\strnlen.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\strnlen.cpp
$(OBJ_utl_strnlen_UX_MT_R): $(PROJ_SRC_DIR)\util\util.strnlen.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\util\util.strnlen.c


########################################
# Main library - 'pantheios.X.core.a'

$(LIB_CORE_UX_MT_D): $(OBJ_CORE_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_UX_MT_D)

$(OBJ_cr_api_UX_MT_D): $(PROJ_SRC_DIR)\core\api.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\core\api.cpp
$(OBJ_cr_api_dep_UX_MT_D): $(PROJ_SRC_DIR)\core\api.deprecated.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\core\api.deprecated.c
$(OBJ_utl_api_exit_UX_MT_D): $(PROJ_SRC_DIR)\core\api.exitprocess.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\core\api.exitprocess.cpp
$(OBJ_cr_api_logprintf_UX_MT_D): $(PROJ_SRC_DIR)\core\logprintf.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\core\logprintf.c
$(OBJ_cr_api_logputs_UX_MT_D): $(PROJ_SRC_DIR)\core\api.logputs.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\core\api.logputs.cpp
$(OBJ_cr_auto_UX_MT_D): $(PROJ_SRC_DIR)\core\auto.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\core\auto.cpp

$(OBJ_ins_args_UX_MT_D): $(PROJ_SRC_DIR)\inserters\args.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\args.cpp
!ifndef PANTHEIOS_NO_B64
$(OBJ_ins_b64_UX_MT_D): $(PROJ_SRC_DIR)\inserters\b64.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\b64.cpp
!endif # !PANTHEIOS_NO_B64
$(OBJ_ins_blob_UX_MT_D): $(PROJ_SRC_DIR)\inserters\blob.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\blob.cpp
$(OBJ_ins_bool_UX_MT_D): $(PROJ_SRC_DIR)\inserters\boolean.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\boolean.cpp
$(OBJ_ins_excp_UX_MT_D): $(PROJ_SRC_DIR)\inserters\exception.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\exception.cpp
$(OBJ_ins_host_UX_MT_D): $(PROJ_SRC_DIR)\inserters\hostid.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\hostid.cpp
$(OBJ_ins_int_UX_MT_D): $(PROJ_SRC_DIR)\inserters\integer.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\integer.cpp
$(OBJ_ins_ivl_UX_MT_D): $(PROJ_SRC_DIR)\inserters\interval.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\interval.cpp
$(OBJ_ins_ptr_UX_MT_D): $(PROJ_SRC_DIR)\inserters\pointer.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\pointer.cpp
$(OBJ_ins_prid_UX_MT_D): $(PROJ_SRC_DIR)\inserters\processid.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\processid.cpp
$(OBJ_ins_real_UX_MT_D): $(PROJ_SRC_DIR)\inserters\real.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\real.cpp
$(OBJ_ins_slice_UX_MT_D): $(PROJ_SRC_DIR)\inserters\slice.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\slice.cpp
$(OBJ_ins_thrid_UX_MT_D): $(PROJ_SRC_DIR)\inserters\threadid.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\threadid.cpp
$(OBJ_ins_stm_ch_UX_MT_D): $(PROJ_SRC_DIR)\inserters\stream_character.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\stream_character.cpp
$(OBJ_ins_w2m_UX_MT_D): $(PROJ_SRC_DIR)\inserters\w2m.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\w2m.cpp

$(LIB_CORE_UX_MT_R): $(OBJ_CORE_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_UX_MT_R)

$(OBJ_cr_api_UX_MT_R): $(PROJ_SRC_DIR)\core\api.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\core\api.cpp
$(OBJ_cr_api_dep_UX_MT_R): $(PROJ_SRC_DIR)\core\api.deprecated.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\core\api.deprecated.c
$(OBJ_utl_api_exit_UX_MT_R): $(PROJ_SRC_DIR)\core\api.exitprocess.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\core\api.exitprocess.cpp
$(OBJ_cr_api_logprintf_UX_MT_R): $(PROJ_SRC_DIR)\core\logprintf.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\core\logprintf.c
$(OBJ_cr_api_logputs_UX_MT_R): $(PROJ_SRC_DIR)\core\api.logputs.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\core\api.logputs.cpp
$(OBJ_cr_auto_UX_MT_R): $(PROJ_SRC_DIR)\core\auto.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\core\auto.cpp

$(OBJ_ins_args_UX_MT_R): $(PROJ_SRC_DIR)\inserters\args.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\args.cpp
!ifndef PANTHEIOS_NO_B64
$(OBJ_ins_b64_UX_MT_R): $(PROJ_SRC_DIR)\inserters\b64.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\b64.cpp
!endif # !PANTHEIOS_NO_B64
$(OBJ_ins_blob_UX_MT_R): $(PROJ_SRC_DIR)\inserters\blob.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\blob.cpp
$(OBJ_ins_bool_UX_MT_R): $(PROJ_SRC_DIR)\inserters\boolean.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\boolean.cpp
$(OBJ_ins_excp_UX_MT_R): $(PROJ_SRC_DIR)\inserters\exception.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\exception.cpp
$(OBJ_ins_host_UX_MT_R): $(PROJ_SRC_DIR)\inserters\hostid.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\hostid.cpp
$(OBJ_ins_int_UX_MT_R): $(PROJ_SRC_DIR)\inserters\integer.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\integer.cpp
$(OBJ_ins_ivl_UX_MT_R): $(PROJ_SRC_DIR)\inserters\interval.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\interval.cpp
$(OBJ_ins_ptr_UX_MT_R): $(PROJ_SRC_DIR)\inserters\pointer.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\pointer.cpp
$(OBJ_ins_prid_UX_MT_R): $(PROJ_SRC_DIR)\inserters\processid.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\processid.cpp
$(OBJ_ins_real_UX_MT_R): $(PROJ_SRC_DIR)\inserters\real.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\real.cpp
$(OBJ_ins_slice_UX_MT_R): $(PROJ_SRC_DIR)\inserters\slice.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\slice.cpp
$(OBJ_ins_thrid_UX_MT_R): $(PROJ_SRC_DIR)\inserters\threadid.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\threadid.cpp
$(OBJ_ins_stm_ch_UX_MT_R): $(PROJ_SRC_DIR)\inserters\stream_character.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\stream_character.cpp
$(OBJ_ins_w2m_UX_MT_R): $(PROJ_SRC_DIR)\inserters\w2m.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\inserters\w2m.cpp

########################################
# Main library - 'pantheios.X.appl.a'

$(LIB_APPL_UX_MT_D): $(OBJ_APPL_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_APPL_UX_MT_D)

$(LIB_APPL_UX_MT_R): $(OBJ_APPL_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_APPL_UX_MT_R)

########################################
# backend util components

########################################
# Backend common stock library - 'pantheios.bec.stock.a'

$(LIB_BEC_STOCK_UX_MT_D): $(OBJ_BEC_STOCK_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_STOCK_UX_MT_D)

$(LIB_BEC_STOCK_WC_UX_MT_D): $(OBJ_BEC_STOCK_WC_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_STOCK_WC_UX_MT_D)

$(LIB_BEC_STOCK_UX_MT_R): $(OBJ_BEC_STOCK_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_STOCK_UX_MT_R)

$(LIB_BEC_STOCK_WC_UX_MT_R): $(OBJ_BEC_STOCK_WC_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_STOCK_WC_UX_MT_R)


########################################
# Backend library - 'pantheios.be.lrsplit.a'

$(LIB_BE_LRSPLIT_UX_MT_D): $(OBJ_BE_LRSPLIT_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_LRSPLIT_UX_MT_D)

$(OBJ_be_lrsplit_UX_MT_D): $(PROJ_SRC_DIR)\backends\be.lrsplit.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be.lrsplit.c

$(LIB_BE_LRSPLIT_UX_MT_R): $(OBJ_BE_LRSPLIT_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_LRSPLIT_UX_MT_R)

$(OBJ_be_lrsplit_UX_MT_R): $(PROJ_SRC_DIR)\backends\be.lrsplit.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be.lrsplit.c

########################################
# Backend library - 'pantheios.be.N.a'

$(LIB_BE_N_UX_MT_D): $(OBJ_BE_N_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_N_UX_MT_D)

$(OBJ_be_N_UX_MT_D): $(PROJ_SRC_DIR)\backends\be.N.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be.N.c

$(LIB_BE_N_UX_MT_R): $(OBJ_BE_N_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_N_UX_MT_R)

$(OBJ_be_N_UX_MT_R): $(PROJ_SRC_DIR)\backends\be.N.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be.N.c

########################################
# Back-end library - 'pantheios.bec.test.a'

$(LIB_BEC_TEST_UX_MT_D): $(OBJ_BEC_TEST_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_TEST_UX_MT_D)

$(OBJ_bec_test_UX_MT_D): $(PROJ_SRC_DIR)\backends\bec.test.cpp $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.test.cpp

$(LIB_BEC_TEST_UX_MT_R): $(OBJ_BEC_TEST_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_TEST_UX_MT_R)

$(OBJ_bec_test_UX_MT_R): $(PROJ_SRC_DIR)\backends\bec.test.cpp $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.test.cpp

########################################
# Back-end library - 'pantheios.be.test.a'

$(LIB_BE_TEST_UX_MT_D): $(OBJ_BE_TEST_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_TEST_UX_MT_D)

$(OBJ_be_test_UX_MT_D): $(PROJ_SRC_DIR)\backends\be\be.test.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be\be.test.c

$(LIB_BE_TEST_UX_MT_R): $(OBJ_BE_TEST_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_TEST_UX_MT_R)

$(OBJ_be_test_UX_MT_R): $(PROJ_SRC_DIR)\backends\be\be.test.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be\be.test.c

########################################
# Back-end library - 'pantheios.bel.test.a'

$(LIB_BEL_TEST_UX_MT_D): $(OBJ_BEL_TEST_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEL_TEST_UX_MT_D)

$(OBJ_bel_test_UX_MT_D): $(PROJ_SRC_DIR)\backends\bel\bel.test.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bel\bel.test.c

$(LIB_BEL_TEST_UX_MT_R): $(OBJ_BEL_TEST_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEL_TEST_UX_MT_R)

$(OBJ_bel_test_UX_MT_R): $(PROJ_SRC_DIR)\backends\bel\bel.test.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bel\bel.test.c

########################################
# Back-end library - 'pantheios.ber.test.a'

$(LIB_BER_TEST_UX_MT_D): $(OBJ_BER_TEST_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BER_TEST_UX_MT_D)

$(OBJ_ber_test_UX_MT_D): $(PROJ_SRC_DIR)\backends\ber\ber.test.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\ber\ber.test.c

$(LIB_BER_TEST_UX_MT_R): $(OBJ_BER_TEST_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BER_TEST_UX_MT_R)

$(OBJ_ber_test_UX_MT_R): $(PROJ_SRC_DIR)\backends\ber\ber.test.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\ber\ber.test.c

########################################
# Backend library - 'pantheios.bec.fail.a'

$(LIB_BEC_FAIL_UX_MT_D): $(OBJ_BEC_FAIL_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_FAIL_UX_MT_D)

$(OBJ_bec_fail_UX_MT_D): $(PROJ_SRC_DIR)\backends\bec.fail.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.fail.c

$(LIB_BEC_FAIL_UX_MT_R): $(OBJ_BEC_FAIL_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_FAIL_UX_MT_R)

$(OBJ_bec_fail_UX_MT_R): $(PROJ_SRC_DIR)\backends\bec.fail.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.fail.c


########################################
# Backend library - 'pantheios.be.fail.a'

$(LIB_BE_FAIL_UX_MT_D): $(OBJ_BE_FAIL_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_FAIL_UX_MT_D)

$(OBJ_be_fail_UX_MT_D): $(PROJ_SRC_DIR)\backends\be\be.fail.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be\be.fail.c

$(LIB_BE_FAIL_UX_MT_R): $(OBJ_BE_FAIL_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_FAIL_UX_MT_R)

$(OBJ_be_fail_UX_MT_R): $(PROJ_SRC_DIR)\backends\be\be.fail.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be\be.fail.c


########################################
# Backend library - 'pantheios.bel.fail.a'

$(LIB_BEL_FAIL_UX_MT_D): $(OBJ_BEL_FAIL_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEL_FAIL_UX_MT_D)

$(OBJ_bel_fail_UX_MT_D): $(PROJ_SRC_DIR)\backends\bel\bel.fail.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bel\bel.fail.c

$(LIB_BEL_FAIL_UX_MT_R): $(OBJ_BEL_FAIL_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEL_FAIL_UX_MT_R)

$(OBJ_bel_fail_UX_MT_R): $(PROJ_SRC_DIR)\backends\bel\bel.fail.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bel\bel.fail.c


########################################
# Backend library - 'pantheios.ber.fail.a'

$(LIB_BER_FAIL_UX_MT_D): $(OBJ_BER_FAIL_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BER_FAIL_UX_MT_D)

$(OBJ_ber_fail_UX_MT_D): $(PROJ_SRC_DIR)\backends\ber\ber.fail.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\ber\ber.fail.c

$(LIB_BER_FAIL_UX_MT_R): $(OBJ_BER_FAIL_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BER_FAIL_UX_MT_R)

$(OBJ_ber_fail_UX_MT_R): $(PROJ_SRC_DIR)\backends\ber\ber.fail.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\ber\ber.fail.c


########################################
# Backend library - 'pantheios.bec.file.a'

$(LIB_BEC_FILE_UX_MT_D): $(OBJ_BEC_FILE_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_FILE_UX_MT_D)

$(OBJ_bec_file_UX_MT_D): $(PROJ_SRC_DIR)\backends\bec.file.cpp $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.file.cpp

$(LIB_BEC_FILE_UX_MT_R): $(OBJ_BEC_FILE_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_FILE_UX_MT_R)

$(OBJ_bec_file_UX_MT_R): $(PROJ_SRC_DIR)\backends\bec.file.cpp $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.file.cpp


########################################
# Backend library - 'pantheios.bec.file.WithCallback.a'

$(LIB_BEC_FILE_WC_UX_MT_D): $(OBJ_BEC_FILE_WC_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_FILE_WC_UX_MT_D)

$(OBJ_bec_file_WC_UX_MT_D): $(PROJ_SRC_DIR)\backends\bec.file.cpp $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) -DPANTHEIOS_BE_USE_CALLBACK $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.file.cpp

$(LIB_BEC_FILE_WC_UX_MT_R): $(OBJ_BEC_FILE_WC_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_FILE_WC_UX_MT_R)

$(OBJ_bec_file_WC_UX_MT_R): $(PROJ_SRC_DIR)\backends\bec.file.cpp $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) -DPANTHEIOS_BE_USE_CALLBACK $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.file.cpp


########################################
# Backend library - 'pantheios.be.file.a'

$(LIB_BE_FILE_UX_MT_D): $(OBJ_BE_FILE_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_FILE_UX_MT_D)

$(OBJ_be_file_UX_MT_D): $(PROJ_SRC_DIR)\backends\be\be.file.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be\be.file.c

$(LIB_BE_FILE_UX_MT_R): $(OBJ_BE_FILE_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_FILE_UX_MT_R)

$(OBJ_be_file_UX_MT_R): $(PROJ_SRC_DIR)\backends\be\be.file.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be\be.file.c


########################################
# Backend library - 'pantheios.bel.file.a'

$(LIB_BEL_FILE_UX_MT_D): $(OBJ_BEL_FILE_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEL_FILE_UX_MT_D)

$(OBJ_bel_file_UX_MT_D): $(PROJ_SRC_DIR)\backends\bel\bel.file.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bel\bel.file.c

$(LIB_BEL_FILE_UX_MT_R): $(OBJ_BEL_FILE_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEL_FILE_UX_MT_R)

$(OBJ_bel_file_UX_MT_R): $(PROJ_SRC_DIR)\backends\bel\bel.file.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bel\bel.file.c


########################################
# Backend library - 'pantheios.ber.file.a'

$(LIB_BER_FILE_UX_MT_D): $(OBJ_BER_FILE_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BER_FILE_UX_MT_D)

$(OBJ_ber_file_UX_MT_D): $(PROJ_SRC_DIR)\backends\ber\ber.file.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\ber\ber.file.c

$(LIB_BER_FILE_UX_MT_R): $(OBJ_BER_FILE_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BER_FILE_UX_MT_R)

$(OBJ_ber_file_UX_MT_R): $(PROJ_SRC_DIR)\backends\ber\ber.file.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\ber\ber.file.c


########################################
# Backend library - 'pantheios.bec.fprintf.a'

$(LIB_BEC_FPRINTF_UX_MT_D): $(OBJ_BEC_FPRINTF_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_FPRINTF_UX_MT_D)

$(OBJ_bec_fprintf_UX_MT_D): $(PROJ_SRC_DIR)\backends\bec.fprintf.cpp $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.fprintf.cpp

$(LIB_BEC_FPRINTF_UX_MT_R): $(OBJ_BEC_FPRINTF_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_FPRINTF_UX_MT_R)

$(OBJ_bec_fprintf_UX_MT_R): $(PROJ_SRC_DIR)\backends\bec.fprintf.cpp $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.fprintf.cpp


########################################
# Backend library - 'pantheios.bec.fprintf.WithCallback.a'

$(LIB_BEC_FPRINTF_WC_UX_MT_D): $(OBJ_BEC_FPRINTF_WC_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_FPRINTF_WC_UX_MT_D)

$(OBJ_bec_fprintf_WC_UX_MT_D): $(PROJ_SRC_DIR)\backends\bec.fprintf.cpp $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) -DPANTHEIOS_BE_USE_CALLBACK $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.fprintf.cpp

$(LIB_BEC_FPRINTF_WC_UX_MT_R): $(OBJ_BEC_FPRINTF_WC_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_FPRINTF_WC_UX_MT_R)

$(OBJ_bec_fprintf_WC_UX_MT_R): $(PROJ_SRC_DIR)\backends\bec.fprintf.cpp $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) -DPANTHEIOS_BE_USE_CALLBACK $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.fprintf.cpp


########################################
# Backend library - 'pantheios.be.fprintf.a'

$(LIB_BE_FPRINTF_UX_MT_D): $(OBJ_BE_FPRINTF_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_FPRINTF_UX_MT_D)

$(OBJ_be_fprintf_UX_MT_D): $(PROJ_SRC_DIR)\backends\be\be.fprintf.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be\be.fprintf.c

$(LIB_BE_FPRINTF_UX_MT_R): $(OBJ_BE_FPRINTF_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_FPRINTF_UX_MT_R)

$(OBJ_be_fprintf_UX_MT_R): $(PROJ_SRC_DIR)\backends\be\be.fprintf.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be\be.fprintf.c


########################################
# Backend library - 'pantheios.bel.fprintf.a'

$(LIB_BEL_FPRINTF_UX_MT_D): $(OBJ_BEL_FPRINTF_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEL_FPRINTF_UX_MT_D)

$(OBJ_bel_fprintf_UX_MT_D): $(PROJ_SRC_DIR)\backends\bel\bel.fprintf.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bel\bel.fprintf.c

$(LIB_BEL_FPRINTF_UX_MT_R): $(OBJ_BEL_FPRINTF_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEL_FPRINTF_UX_MT_R)

$(OBJ_bel_fprintf_UX_MT_R): $(PROJ_SRC_DIR)\backends\bel\bel.fprintf.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bel\bel.fprintf.c


########################################
# Backend library - 'pantheios.ber.fprintf.a'

$(LIB_BER_FPRINTF_UX_MT_D): $(OBJ_BER_FPRINTF_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BER_FPRINTF_UX_MT_D)

$(OBJ_ber_fprintf_UX_MT_D): $(PROJ_SRC_DIR)\backends\ber\ber.fprintf.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\ber\ber.fprintf.c

$(LIB_BER_FPRINTF_UX_MT_R): $(OBJ_BER_FPRINTF_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BER_FPRINTF_UX_MT_R)

$(OBJ_ber_fprintf_UX_MT_R): $(PROJ_SRC_DIR)\backends\ber\ber.fprintf.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\ber\ber.fprintf.c


########################################
# Backend library - 'pantheios.bec.null.a'

$(LIB_BEC_NULL_UX_MT_D): $(OBJ_BEC_NULL_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_NULL_UX_MT_D)

$(OBJ_bec_null_UX_MT_D): $(PROJ_SRC_DIR)\backends\bec.null.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.null.c

$(LIB_BEC_NULL_UX_MT_R): $(OBJ_BEC_NULL_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_NULL_UX_MT_R)

$(OBJ_bec_null_UX_MT_R): $(PROJ_SRC_DIR)\backends\bec.null.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.null.c


########################################
# Backend library - 'pantheios.be.null.a'

$(LIB_BE_NULL_UX_MT_D): $(OBJ_BE_NULL_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_NULL_UX_MT_D)

$(OBJ_be_null_UX_MT_D): $(PROJ_SRC_DIR)\backends\be\be.null.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be\be.null.c

$(LIB_BE_NULL_UX_MT_R): $(OBJ_BE_NULL_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_NULL_UX_MT_R)

$(OBJ_be_null_UX_MT_R): $(PROJ_SRC_DIR)\backends\be\be.null.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be\be.null.c


########################################
# Backend library - 'pantheios.bel.null.a'

$(LIB_BEL_NULL_UX_MT_D): $(OBJ_BEL_NULL_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEL_NULL_UX_MT_D)

$(OBJ_bel_null_UX_MT_D): $(PROJ_SRC_DIR)\backends\bel\bel.null.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bel\bel.null.c

$(LIB_BEL_NULL_UX_MT_R): $(OBJ_BEL_NULL_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEL_NULL_UX_MT_R)

$(OBJ_bel_null_UX_MT_R): $(PROJ_SRC_DIR)\backends\bel\bel.null.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bel\bel.null.c


########################################
# Backend library - 'pantheios.ber.null.a'

$(LIB_BER_NULL_UX_MT_D): $(OBJ_BER_NULL_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BER_NULL_UX_MT_D)

$(OBJ_ber_null_UX_MT_D): $(PROJ_SRC_DIR)\backends\ber\ber.null.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\ber\ber.null.c

$(LIB_BER_NULL_UX_MT_R): $(OBJ_BER_NULL_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BER_NULL_UX_MT_R)

$(OBJ_ber_null_UX_MT_R): $(PROJ_SRC_DIR)\backends\ber\ber.null.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\ber\ber.null.c


!ifdef ACE
########################################
# Backend library - 'pantheios.bec.ACE.a'

$(LIB_BEC_ACE_UX_MT_D): $(OBJ_BEC_ACE_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_ACE_UX_MT_D)

$(OBJ_bec_ACE_UX_MT_D): $(PROJ_SRC_DIR)\backends\bec.ACE.cpp $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_D) $(CPPC_ACE_ADDITIONAL_ARGS) $(CPPC_INCLUDES_ACE) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.ACE.cpp

$(LIB_BEC_ACE_UX_MT_R): $(OBJ_BEC_ACE_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_ACE_UX_MT_R)

$(OBJ_bec_ACE_UX_MT_R): $(PROJ_SRC_DIR)\backends\bec.ACE.cpp $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_LIB_ARGS_UX_MT_R) $(CPPC_ACE_ADDITIONAL_ARGS) $(CPPC_INCLUDES_ACE) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.ACE.cpp


########################################
# Backend library - 'pantheios.be.ACE.a'

$(LIB_BE_ACE_UX_MT_D): $(OBJ_BE_ACE_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_ACE_UX_MT_D)

$(OBJ_be_ACE_UX_MT_D): $(PROJ_SRC_DIR)\backends\be\be.ACE.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_ARGS_ACE) $(CC_INCLUDES_ACE) -Fo$@ $(PROJ_SRC_DIR)\backends\be\be.ACE.c

$(LIB_BE_ACE_UX_MT_R): $(OBJ_BE_ACE_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_ACE_UX_MT_R)

$(OBJ_be_ACE_UX_MT_R): $(PROJ_SRC_DIR)\backends\be\be.ACE.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_ARGS_ACE) $(CC_INCLUDES_ACE) -Fo$@ $(PROJ_SRC_DIR)\backends\be\be.ACE.c


########################################
# Backend library - 'pantheios.bel.ACE.a'

$(LIB_BEL_ACE_UX_MT_D): $(OBJ_BEL_ACE_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEL_ACE_UX_MT_D)

$(OBJ_bel_ACE_UX_MT_D): $(PROJ_SRC_DIR)\backends\bel\bel.ACE.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_ARGS_ACE) $(CC_INCLUDES_ACE) -Fo$@ $(PROJ_SRC_DIR)\backends\bel\bel.ACE.c

$(LIB_BEL_ACE_UX_MT_R): $(OBJ_BEL_ACE_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEL_ACE_UX_MT_R)

$(OBJ_bel_ACE_UX_MT_R): $(PROJ_SRC_DIR)\backends\bel\bel.ACE.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_ARGS_ACE) $(CC_INCLUDES_ACE) -Fo$@ $(PROJ_SRC_DIR)\backends\bel\bel.ACE.c


########################################
# Backend library - 'pantheios.ber.ACE.a'

$(LIB_BER_ACE_UX_MT_D): $(OBJ_BER_ACE_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BER_ACE_UX_MT_D)

$(OBJ_ber_ACE_UX_MT_D): $(PROJ_SRC_DIR)\backends\ber\ber.ACE.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_ARGS_ACE) $(CC_INCLUDES_ACE) -Fo$@ $(PROJ_SRC_DIR)\backends\ber\ber.ACE.c

$(LIB_BER_ACE_UX_MT_R): $(OBJ_BER_ACE_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BER_ACE_UX_MT_R)

$(OBJ_ber_ACE_UX_MT_R): $(PROJ_SRC_DIR)\backends\ber\ber.ACE.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_ARGS_ACE) $(CC_INCLUDES_ACE) -Fo$@ $(PROJ_SRC_DIR)\backends\ber\ber.ACE.c


!endif # ACE
########################################
# Backend library - 'pantheios.bec.syslog.a'

$(LIB_BEC_SYSLOG_UX_MT_D): $(OBJ_BEC_SYSLOG_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_SYSLOG_UX_MT_D)

$(OBJ_bec_SYSLOG_UX_MT_D): $(PROJ_SRC_DIR)\backends\bec.syslog.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.syslog.c

$(LIB_BEC_SYSLOG_UX_MT_R): $(OBJ_BEC_SYSLOG_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_SYSLOG_UX_MT_R)

$(OBJ_bec_SYSLOG_UX_MT_R): $(PROJ_SRC_DIR)\backends\bec.syslog.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\bec.syslog.c


########################################
# Backend library - 'pantheios.bec.syslog.WithCallback.a'

$(LIB_BEC_SYSLOGWC_UX_MT_D): $(OBJ_BEC_SYSLOGWC_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_SYSLOGWC_UX_MT_D)

$(OBJ_bec_SYSLOG_WC_UX_MT_D): $(PROJ_SRC_DIR)\backends\bec.syslog.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -DPANTHEIOS_BE_USE_CALLBACK -Fo$@ $(PROJ_SRC_DIR)\backends\bec.syslog.c

$(LIB_BEC_SYSLOGWC_UX_MT_R): $(OBJ_BEC_SYSLOGWC_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BEC_SYSLOGWC_UX_MT_R)

$(OBJ_bec_SYSLOG_WC_UX_MT_R): $(PROJ_SRC_DIR)\backends\bec.syslog.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -DPANTHEIOS_BE_USE_CALLBACK -Fo$@ $(PROJ_SRC_DIR)\backends\bec.syslog.c


########################################
# Backend library - 'pantheios.be.syslog.a'

$(LIB_BE_SYSLOG_UX_MT_D): $(OBJ_BE_SYSLOG_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_SYSLOG_UX_MT_D)

$(OBJ_be_SYSLOG_UX_MT_D): $(PROJ_SRC_DIR)\backends\be\be.syslog.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be\be.syslog.c

$(LIB_BE_SYSLOG_UX_MT_R): $(OBJ_BE_SYSLOG_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BE_SYSLOG_UX_MT_R)

$(OBJ_be_SYSLOG_UX_MT_R): $(PROJ_SRC_DIR)\backends\be\be.syslog.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\be\be.syslog.c


########################################
# Backend library - 'pantheios.ber.syslog.a'

$(LIB_BER_SYSLOG_UX_MT_D): $(OBJ_BER_SYSLOG_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BER_SYSLOG_UX_MT_D)

$(OBJ_ber_SYSLOG_UX_MT_D): $(PROJ_SRC_DIR)\backends\ber\ber.syslog.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\ber\ber.syslog.c

$(LIB_BER_SYSLOG_UX_MT_R): $(OBJ_BER_SYSLOG_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_BER_SYSLOG_UX_MT_R)

$(OBJ_ber_SYSLOG_UX_MT_R): $(PROJ_SRC_DIR)\backends\ber\ber.syslog.c $(BE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\backends\ber\ber.syslog.c


########################################
# Front-end library - 'pantheios.fe.all.a'

$(LIB_FE_ALL_UX_MT_D): $(OBJ_FE_ALL_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_ALL_UX_MT_D)

$(OBJ_fe_all_UX_MT_D): $(PROJ_SRC_DIR)\frontends\fe.all.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.all.c

$(LIB_FE_ALL_UX_MT_R): $(OBJ_FE_ALL_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_ALL_UX_MT_R)

$(OBJ_fe_all_UX_MT_R): $(PROJ_SRC_DIR)\frontends\fe.all.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.all.c

########################################
# Front-end library - 'pantheios.fe.all.WithCallback.a'

$(LIB_FE_ALL_WC_UX_MT_D): $(OBJ_FE_ALL_WC_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_ALL_WC_UX_MT_D)

$(OBJ_fe_all_WC_UX_MT_D): $(PROJ_SRC_DIR)\frontends\fe.all.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) -DPANTHEIOS_BE_USE_CALLBACK $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.all.c

$(LIB_FE_ALL_WC_UX_MT_R): $(OBJ_FE_ALL_WC_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_ALL_WC_UX_MT_R)

$(OBJ_fe_all_WC_UX_MT_R): $(PROJ_SRC_DIR)\frontends\fe.all.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) -DPANTHEIOS_BE_USE_CALLBACK $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.all.c

########################################
# Front-end library - 'pantheios.fe.fail.a'

$(LIB_FE_FAIL_UX_MT_D): $(OBJ_FE_FAIL_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_FAIL_UX_MT_D)

$(OBJ_fe_fail_UX_MT_D): $(PROJ_SRC_DIR)\frontends\fe.fail.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.fail.c

$(LIB_FE_FAIL_UX_MT_R): $(OBJ_FE_FAIL_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_FAIL_UX_MT_R)

$(OBJ_fe_fail_UX_MT_R): $(PROJ_SRC_DIR)\frontends\fe.fail.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.fail.c

########################################
# Front-end library - 'pantheios.fe.N.a'

$(LIB_FE_N_UX_MT_D): $(OBJ_FE_N_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_N_UX_MT_D)

$(OBJ_fe_N_UX_MT_D): $(PROJ_SRC_DIR)\frontends\fe.N.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.N.c

$(LIB_FE_N_UX_MT_R): $(OBJ_FE_N_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_N_UX_MT_R)

$(OBJ_fe_N_UX_MT_R): $(PROJ_SRC_DIR)\frontends\fe.N.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.N.c

########################################
# Front-end library - 'pantheios.fe.N.WithCallback.a'

$(LIB_FE_N_WC_UX_MT_D): $(OBJ_FE_N_WC_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_N_WC_UX_MT_D)

$(OBJ_fe_N_WC_UX_MT_D): $(PROJ_SRC_DIR)\frontends\fe.N.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) -DPANTHEIOS_BE_USE_CALLBACK $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.N.c

$(LIB_FE_N_WC_UX_MT_R): $(OBJ_FE_N_WC_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_N_WC_UX_MT_R)

$(OBJ_fe_N_WC_UX_MT_R): $(PROJ_SRC_DIR)\frontends\fe.N.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) -DPANTHEIOS_BE_USE_CALLBACK $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.N.c

########################################
# Front-end library - 'pantheios.fe.null.a'

$(LIB_FE_NULL_UX_MT_D): $(OBJ_FE_NULL_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_NULL_UX_MT_D)

$(OBJ_fe_null_UX_MT_D): $(PROJ_SRC_DIR)\frontends\fe.null.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.null.c

$(LIB_FE_NULL_UX_MT_R): $(OBJ_FE_NULL_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_NULL_UX_MT_R)

$(OBJ_fe_null_UX_MT_R): $(PROJ_SRC_DIR)\frontends\fe.null.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.null.c

########################################
# Front-end library - 'pantheios.fe.null.WithCallback.a'

$(LIB_FE_NULL_WC_UX_MT_D): $(OBJ_FE_NULL_WC_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_NULL_WC_UX_MT_D)

$(OBJ_fe_null_WC_UX_MT_D): $(PROJ_SRC_DIR)\frontends\fe.null.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) -DPANTHEIOS_BE_USE_CALLBACK $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.null.c

$(LIB_FE_NULL_WC_UX_MT_R): $(OBJ_FE_NULL_WC_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_NULL_WC_UX_MT_R)

$(OBJ_fe_null_WC_UX_MT_R): $(PROJ_SRC_DIR)\frontends\fe.null.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) -DPANTHEIOS_BE_USE_CALLBACK $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.null.c

########################################
# Front-end library - 'pantheios.fe.simple.a'

$(LIB_FE_SIMPLE_UX_MT_D): $(OBJ_FE_SIMPLE_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_SIMPLE_UX_MT_D)

$(OBJ_fe_simple_UX_MT_D): $(PROJ_SRC_DIR)\frontends\fe.simple.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.simple.c

$(LIB_FE_SIMPLE_UX_MT_R): $(OBJ_FE_SIMPLE_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_SIMPLE_UX_MT_R)

$(OBJ_fe_simple_UX_MT_R): $(PROJ_SRC_DIR)\frontends\fe.simple.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.simple.c

########################################
# Front-end library - 'pantheios.fe.simple.WithCallback.a'

$(LIB_FE_SIMPLE_WC_UX_MT_D): $(OBJ_FE_SIMPLE_WC_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_SIMPLE_WC_UX_MT_D)

$(OBJ_fe_simple_WC_UX_MT_D): $(PROJ_SRC_DIR)\frontends\fe.simple.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_D) -DPANTHEIOS_BE_USE_CALLBACK $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.simple.c

$(LIB_FE_SIMPLE_WC_UX_MT_R): $(OBJ_FE_SIMPLE_WC_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_FE_SIMPLE_WC_UX_MT_R)

$(OBJ_fe_simple_WC_UX_MT_R): $(PROJ_SRC_DIR)\frontends\fe.simple.c $(FE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_LIB_ARGS_UX_MT_R) -DPANTHEIOS_BE_USE_CALLBACK $(CC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\frontends\fe.simple.c

########################################
# b64 library - 'b64.X.pan.core.a'

!ifndef PANTHEIOS_NO_B64

$(LIB_B64_UX_MT_D): $(OBJ_B64_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_B64_UX_MT_D)

$(OBJ_b64_b64_UX_MT_D): $(B64_SRC_DIR)\b64.c $(B64_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_B64_ARGS_UX_MT_D) $(CC_B64_INCLUDES_UX_MT_D) -Fo$@ $(B64_SRC_DIR)\b64.c

$(LIB_B64_UX_MT_R): $(OBJ_B64_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_B64_UX_MT_R)

$(OBJ_b64_b64_UX_MT_R): $(B64_SRC_DIR)\b64.c $(B64_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_B64_ARGS_UX_MT_R) $(CC_B64_INCLUDES_UX_MT_R) -Fo$@ $(B64_SRC_DIR)\b64.c

!endif # !PANTHEIOS_NO_B64
########################################
# shwild library - 'shwild.X.pan.core.a'

$(LIB_SHWILD_UX_MT_D): $(OBJ_SHWILD_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_UX_MT_D)

$(OBJ_shw_api_UX_MT_D): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_SHWILD_ARGS_UX_MT_D) $(CPPC_SHWILD_INCLUDES_UX_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_UX_MT_D): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_SHWILD_ARGS_UX_MT_D) $(CPPC_SHWILD_INCLUDES_UX_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_UX_MT_D): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_SHWILD_ARGS_UX_MT_D) $(CPPC_SHWILD_INCLUDES_UX_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_UX_MT_R): $(OBJ_SHWILD_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_UX_MT_R)

$(OBJ_shw_api_UX_MT_R): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_SHWILD_ARGS_UX_MT_R) $(CPPC_SHWILD_INCLUDES_UX_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_UX_MT_R): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_SHWILD_ARGS_UX_MT_R) $(CPPC_SHWILD_INCLUDES_UX_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_UX_MT_R): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_SHWILD_ARGS_UX_MT_R) $(CPPC_SHWILD_INCLUDES_UX_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

########################################
# xContract library - 'xcontract.X.pan.core.a'

$(LIB_XCONTRACT_UX_MT_D): $(OBJ_XCONTRACT_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XCONTRACT_UX_MT_D)

$(OBJ_xct_core_UX_MT_D): $(XCONTRACT_SRC_DIR)\xcontract.core.c $(XCONTRACT_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_XCONTRACT_ARGS_UX_MT_D) $(CC_XCONTRACT_INCLUDES_UX_MT_D) -Fo$@ $(XCONTRACT_SRC_DIR)\xcontract.core.c

$(LIB_XCONTRACT_UX_MT_R): $(OBJ_XCONTRACT_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XCONTRACT_UX_MT_R)

$(OBJ_xct_core_UX_MT_R): $(XCONTRACT_SRC_DIR)\xcontract.core.c $(XCONTRACT_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_XCONTRACT_ARGS_UX_MT_R) $(CC_XCONTRACT_INCLUDES_UX_MT_R) -Fo$@ $(XCONTRACT_SRC_DIR)\xcontract.core.c

########################################
# xTests library - 'xtests.X.pan.core.a'

$(LIB_XTESTS_UX_MT_D): $(OBJ_XTESTS_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_UX_MT_D)

$(OBJ_xts_core_UX_MT_D): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_XTESTS_ARGS_UX_MT_D) $(CPPC_XTESTS_INCLUDES_UX_MT_D) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_UX_MT_R): $(OBJ_XTESTS_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_UX_MT_R)

$(OBJ_xts_core_UX_MT_R): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_XTESTS_ARGS_UX_MT_R) $(CPPC_XTESTS_INCLUDES_UX_MT_R) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

##################################################
# examples

#  object files

$(OBJ_EX_P_be_01_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.callback\example.cpp.backends.callback.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.callback\example.cpp.backends.callback.cpp
$(OBJ_EX_P_be_02_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.file\example.cpp.backends.file.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.file\example.cpp.backends.file.cpp
$(OBJ_EX_P_be_03_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.file.callback\example.cpp.backends.file.callback.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.file.callback\example.cpp.backends.file.callback.cpp
$(OBJ_EX_P_be_04_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.file.lrsplit\example.cpp.backends.file.lrsplit.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.file.lrsplit\example.cpp.backends.file.lrsplit.cpp
$(OBJ_EX_P_be_05_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.mx.1\example.cpp.backends.mx.1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.mx.1\example.cpp.backends.mx.1.cpp
$(OBJ_EX_P_be_06_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.mx.2\example.cpp.backends.mx.2.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.mx.2\example.cpp.backends.mx.2.cpp
$(OBJ_EX_P_cp_01_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\contract\example.cpp.contract.PANTHEIOS_ASSERT\example.cpp.contract.PANTHEIOS_ASSERT.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\contract\example.cpp.contract.PANTHEIOS_ASSERT\example.cpp.contract.PANTHEIOS_ASSERT.cpp
$(OBJ_EX_P_cp_02_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\contract\example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT\example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\contract\example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT\example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT.cpp
$(OBJ_EX_P_fm_01_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\format\example.cpp.format.highres\example.cpp.format.highres.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\format\example.cpp.format.highres\example.cpp.format.highres.cpp
$(OBJ_EX_P_fm_02_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\format\example.cpp.format.lowres\example.cpp.format.lowres.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\format\example.cpp.format.lowres\example.cpp.format.lowres.cpp
$(OBJ_EX_P_fm_03_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\format\example.cpp.format.pad\example.cpp.format.pad.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\format\example.cpp.format.pad\example.cpp.format.pad.cpp
$(OBJ_EX_P_fe_01_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\frontends\example.cpp.frontends.custom\example.cpp.frontends.custom.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\frontends\example.cpp.frontends.custom\example.cpp.frontends.custom.cpp
$(OBJ_EX_P_in_01_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.args\example.cpp.inserter.args.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.args\example.cpp.inserter.args.cpp
$(OBJ_EX_P_in_02_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.b\example.cpp.inserter.b.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.b\example.cpp.inserter.b.cpp
!ifndef PANTHEIOS_NO_B64
$(OBJ_EX_P_in_03_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.b64\example.cpp.inserter.b64.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.b64\example.cpp.inserter.b64.cpp
!endif # !PANTHEIOS_NO_B64
$(OBJ_EX_P_in_04_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.blob\example.cpp.inserter.blob.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.blob\example.cpp.inserter.blob.cpp
$(OBJ_EX_P_in_05_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.character\example.cpp.inserter.character.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.character\example.cpp.inserter.character.cpp
$(OBJ_EX_P_in_06_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.hex_ptr\example.cpp.inserter.hex_ptr.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.hex_ptr\example.cpp.inserter.hex_ptr.cpp
$(OBJ_EX_P_in_07_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.hostid\example.cpp.inserter.hostid.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.hostid\example.cpp.inserter.hostid.cpp
$(OBJ_EX_P_in_08_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.i\example.cpp.inserter.i.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.i\example.cpp.inserter.i.cpp
$(OBJ_EX_P_in_09_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.integer\example.cpp.inserter.integer.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.integer\example.cpp.inserter.integer.cpp
$(OBJ_EX_P_in_10_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.p\example.cpp.inserter.p.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.p\example.cpp.inserter.p.cpp
$(OBJ_EX_P_in_11_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.pointer\example.cpp.inserter.pointer.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.pointer\example.cpp.inserter.pointer.cpp
$(OBJ_EX_P_in_12_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.processid\example.cpp.inserter.processid.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.processid\example.cpp.inserter.processid.cpp
$(OBJ_EX_P_in_13_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.real\example.cpp.inserter.real.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.real\example.cpp.inserter.real.cpp
$(OBJ_EX_P_in_14_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.threadid\example.cpp.inserter.threadid.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.threadid\example.cpp.inserter.threadid.cpp
$(OBJ_EX_P_in_15_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.xi\example.cpp.inserter.xi.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.xi\example.cpp.inserter.xi.cpp
$(OBJ_EX_P_in_16_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.xp\example.cpp.inserter.xp.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.xp\example.cpp.inserter.xp.cpp
$(OBJ_EX_P_in_17_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.w2m\example.cpp.inserter.w2m.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.w2m\example.cpp.inserter.w2m.cpp
$(OBJ_EX_P_ln_01_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\linking\example.cpp.linking.implicit_link_1\example.cpp.linking.implicit_link_1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\linking\example.cpp.linking.implicit_link_1\example.cpp.linking.implicit_link_1.cpp
$(OBJ_EX_P_ms_01_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.101\example.cpp.misc.101.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.101\example.cpp.misc.101.cpp
$(OBJ_EX_P_ms_02_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.custom_type_1\example.cpp.misc.custom_type_1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.custom_type_1\example.cpp.misc.custom_type_1.cpp
$(OBJ_EX_P_ms_03_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.hetero1\example.cpp.misc.hetero1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.hetero1\example.cpp.misc.hetero1.cpp
$(OBJ_EX_P_ms_04_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.no_namespace\example.cpp.misc.no_namespace.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.no_namespace\example.cpp.misc.no_namespace.cpp
$(OBJ_EX_P_ms_05_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.strings\example.cpp.misc.strings.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.strings\example.cpp.misc.strings.cpp
$(OBJ_EX_P_ms_06_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.extended_severity_information\example.cpp.misc.extended_severity_information.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.extended_severity_information\example.cpp.misc.extended_severity_information.cpp
$(OBJ_EX_P_ut_01_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\cpp\util\example.cpp.util.strdup\example.cpp.util.strdup.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\util\example.cpp.util.strdup\example.cpp.util.strdup.cpp
$(OBJ_EX_C_0_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\c\example.c.101\example.c.101.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.101\example.c.101.c
$(OBJ_EX_C_1_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\c\example.c.log_n\example.c.log_n.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.log_n\example.c.log_n.c
$(OBJ_EX_C_2_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\c\example.c.core.pantheios_logprintf\example.c.core.pantheios_logprintf.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.core.pantheios_logprintf\example.c.core.pantheios_logprintf.c
$(OBJ_EX_C_3_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\c\example.c.N\example.c.N.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.N\example.c.N.c
$(OBJ_EX_C_4_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\c\util\example.c.util.gethostname\example.c.util.gethostname.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\util\example.c.util.gethostname\example.c.util.gethostname.c
$(OBJ_EX_C_5_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\c\util\example.c.util.getcurrenttime\example.c.util.getcurrenttime.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\util\example.c.util.getcurrenttime\example.c.util.getcurrenttime.c
$(OBJ_EX_C_6_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\c\example.c.assert\example.c.assert.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.assert\example.c.assert.c
$(OBJ_EX_C_7_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\c\example.c.extended_severity\example.c.extended_severity.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.extended_severity\example.c.extended_severity.c

$(OBJ_EX_P_be_01_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.callback\example.cpp.backends.callback.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.callback\example.cpp.backends.callback.cpp
$(OBJ_EX_P_be_02_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.file\example.cpp.backends.file.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.file\example.cpp.backends.file.cpp
$(OBJ_EX_P_be_03_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.file.callback\example.cpp.backends.file.callback.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.file.callback\example.cpp.backends.file.callback.cpp
$(OBJ_EX_P_be_04_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.file.lrsplit\example.cpp.backends.file.lrsplit.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.file.lrsplit\example.cpp.backends.file.lrsplit.cpp
$(OBJ_EX_P_be_05_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.mx.1\example.cpp.backends.mx.1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.mx.1\example.cpp.backends.mx.1.cpp
$(OBJ_EX_P_be_06_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.mx.2\example.cpp.backends.mx.2.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\backends\example.cpp.backends.mx.2\example.cpp.backends.mx.2.cpp
$(OBJ_EX_P_cp_01_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\contract\example.cpp.contract.PANTHEIOS_ASSERT\example.cpp.contract.PANTHEIOS_ASSERT.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\contract\example.cpp.contract.PANTHEIOS_ASSERT\example.cpp.contract.PANTHEIOS_ASSERT.cpp
$(OBJ_EX_P_cp_02_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\contract\example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT\example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\contract\example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT\example.cpp.contract.PANTHEIOS_MESSAGE_ASSERT.cpp
$(OBJ_EX_P_fm_01_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\format\example.cpp.format.highres\example.cpp.format.highres.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\format\example.cpp.format.highres\example.cpp.format.highres.cpp
$(OBJ_EX_P_fm_02_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\format\example.cpp.format.lowres\example.cpp.format.lowres.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\format\example.cpp.format.lowres\example.cpp.format.lowres.cpp
$(OBJ_EX_P_fm_03_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\format\example.cpp.format.pad\example.cpp.format.pad.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\format\example.cpp.format.pad\example.cpp.format.pad.cpp
$(OBJ_EX_P_fe_01_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\frontends\example.cpp.frontends.custom\example.cpp.frontends.custom.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\frontends\example.cpp.frontends.custom\example.cpp.frontends.custom.cpp
$(OBJ_EX_P_in_01_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.args\example.cpp.inserter.args.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.args\example.cpp.inserter.args.cpp
$(OBJ_EX_P_in_02_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.b\example.cpp.inserter.b.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.b\example.cpp.inserter.b.cpp
!ifndef PANTHEIOS_NO_B64
$(OBJ_EX_P_in_03_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.b64\example.cpp.inserter.b64.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.b64\example.cpp.inserter.b64.cpp
!endif # !PANTHEIOS_NO_B64
$(OBJ_EX_P_in_04_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.blob\example.cpp.inserter.blob.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.blob\example.cpp.inserter.blob.cpp
$(OBJ_EX_P_in_05_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.character\example.cpp.inserter.character.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.character\example.cpp.inserter.character.cpp
$(OBJ_EX_P_in_06_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.hex_ptr\example.cpp.inserter.hex_ptr.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.hex_ptr\example.cpp.inserter.hex_ptr.cpp
$(OBJ_EX_P_in_07_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.hostid\example.cpp.inserter.hostid.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.hostid\example.cpp.inserter.hostid.cpp
$(OBJ_EX_P_in_08_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.i\example.cpp.inserter.i.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.i\example.cpp.inserter.i.cpp
$(OBJ_EX_P_in_09_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.integer\example.cpp.inserter.integer.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.integer\example.cpp.inserter.integer.cpp
$(OBJ_EX_P_in_10_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.p\example.cpp.inserter.p.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.p\example.cpp.inserter.p.cpp
$(OBJ_EX_P_in_11_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.pointer\example.cpp.inserter.pointer.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.pointer\example.cpp.inserter.pointer.cpp
$(OBJ_EX_P_in_12_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.processid\example.cpp.inserter.processid.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.processid\example.cpp.inserter.processid.cpp
$(OBJ_EX_P_in_13_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.real\example.cpp.inserter.real.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.real\example.cpp.inserter.real.cpp
$(OBJ_EX_P_in_14_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.threadid\example.cpp.inserter.threadid.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.threadid\example.cpp.inserter.threadid.cpp
$(OBJ_EX_P_in_15_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.xi\example.cpp.inserter.xi.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.xi\example.cpp.inserter.xi.cpp
$(OBJ_EX_P_in_16_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.xp\example.cpp.inserter.xp.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.xp\example.cpp.inserter.xp.cpp
$(OBJ_EX_P_in_17_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.w2m\example.cpp.inserter.w2m.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\inserters\example.cpp.inserter.w2m\example.cpp.inserter.w2m.cpp
$(OBJ_EX_P_ln_01_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\linking\example.cpp.linking.implicit_link_1\example.cpp.linking.implicit_link_1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\linking\example.cpp.linking.implicit_link_1\example.cpp.linking.implicit_link_1.cpp
$(OBJ_EX_P_ms_01_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.101\example.cpp.misc.101.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.101\example.cpp.misc.101.cpp
$(OBJ_EX_P_ms_02_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.custom_type_1\example.cpp.misc.custom_type_1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.custom_type_1\example.cpp.misc.custom_type_1.cpp
$(OBJ_EX_P_ms_03_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.hetero1\example.cpp.misc.hetero1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.hetero1\example.cpp.misc.hetero1.cpp
$(OBJ_EX_P_ms_04_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.no_namespace\example.cpp.misc.no_namespace.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.no_namespace\example.cpp.misc.no_namespace.cpp
$(OBJ_EX_P_ms_05_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.strings\example.cpp.misc.strings.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.strings\example.cpp.misc.strings.cpp
$(OBJ_EX_P_ms_06_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.extended_severity_information\example.cpp.misc.extended_severity_information.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\misc\example.cpp.misc.extended_severity_information\example.cpp.misc.extended_severity_information.cpp
$(OBJ_EX_P_ut_01_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\cpp\util\example.cpp.util.strdup\example.cpp.util.strdup.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_EXAMPLE_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\util\example.cpp.util.strdup\example.cpp.util.strdup.cpp
$(OBJ_EX_C_0_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\c\example.c.101\example.c.101.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.101\example.c.101.c
$(OBJ_EX_C_1_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\c\example.c.log_n\example.c.log_n.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.log_n\example.c.log_n.c
$(OBJ_EX_C_2_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\c\example.c.core.pantheios_logprintf\example.c.core.pantheios_logprintf.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.core.pantheios_logprintf\example.c.core.pantheios_logprintf.c
$(OBJ_EX_C_3_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\c\example.c.N\example.c.N.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.N\example.c.N.c
$(OBJ_EX_C_4_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\c\util\example.c.util.gethostname\example.c.util.gethostname.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\util\example.c.util.gethostname\example.c.util.gethostname.c
$(OBJ_EX_C_5_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\c\util\example.c.util.getcurrenttime\example.c.util.getcurrenttime.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\util\example.c.util.getcurrenttime\example.c.util.getcurrenttime.c
$(OBJ_EX_C_6_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\c\example.c.assert\example.c.assert.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.assert\example.c.assert.c
$(OBJ_EX_C_7_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\c\example.c.extended_severity\example.c.extended_severity.c $(TEST_C_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_EXAMPLE_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.extended_severity\example.c.extended_severity.c


# executables

$(TARG_EX_P_be_01_UX_MT_D): \
			$(OBJ_EX_P_be_01_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_be_01_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_SYSLOG_UX_MT_D)\
		$(LIB_BEC_SYSLOG_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_be_02_UX_MT_D): \
			$(OBJ_EX_P_be_02_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FILE_UX_MT_D)\
			$(LIB_BEC_FILE_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_be_02_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FILE_UX_MT_D)\
		$(LIB_BEC_FILE_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_be_03_UX_MT_D): \
			$(OBJ_EX_P_be_03_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FILE_UX_MT_D)\
			$(LIB_BEC_FILE_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_be_03_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FILE_UX_MT_D)\
		$(LIB_BEC_FILE_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_be_04_UX_MT_D): \
			$(OBJ_EX_P_be_04_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FILE_UX_MT_D)\
			$(LIB_BEC_FILE_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_be_04_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FILE_UX_MT_D)\
		$(LIB_BEC_FILE_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_be_05_UX_MT_D): \
			$(OBJ_EX_P_be_05_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_N_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_BEC_SYSLOG_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_be_05_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_N_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_BEC_SYSLOG_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_be_06_UX_MT_D): \
			$(OBJ_EX_P_be_06_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_N_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_BEC_SYSLOG_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_be_06_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_N_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_BEC_SYSLOG_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_cp_01_UX_MT_D): \
			$(OBJ_EX_P_cp_01_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_cp_01_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_cp_02_UX_MT_D): \
			$(OBJ_EX_P_cp_02_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_cp_02_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_ms_06_UX_MT_D): \
			$(OBJ_EX_P_ms_06_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_ms_06_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_fm_01_UX_MT_D): \
			$(OBJ_EX_P_fm_01_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_fm_01_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_fm_02_UX_MT_D): \
			$(OBJ_EX_P_fm_02_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_fm_02_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_fm_03_UX_MT_D): \
			$(OBJ_EX_P_fm_03_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_fm_03_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_fe_01_UX_MT_D): \
			$(OBJ_EX_P_fe_01_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_fe_01_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_in_01_UX_MT_D): \
			$(OBJ_EX_P_in_01_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_01_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_in_02_UX_MT_D): \
			$(OBJ_EX_P_in_02_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_02_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

!ifndef PANTHEIOS_NO_B64

$(TARG_EX_P_in_03_UX_MT_D): \
			$(OBJ_EX_P_in_03_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_03_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)
!endif # !PANTHEIOS_NO_B64

$(TARG_EX_P_in_04_UX_MT_D): \
			$(OBJ_EX_P_in_04_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_04_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_in_05_UX_MT_D): \
			$(OBJ_EX_P_in_05_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_05_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_in_06_UX_MT_D): \
			$(OBJ_EX_P_in_06_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_06_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_in_07_UX_MT_D): \
			$(OBJ_EX_P_in_07_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_07_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_in_08_UX_MT_D): \
			$(OBJ_EX_P_in_08_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_08_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_in_09_UX_MT_D): \
			$(OBJ_EX_P_in_09_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_09_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_in_10_UX_MT_D): \
			$(OBJ_EX_P_in_10_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_10_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_in_11_UX_MT_D): \
			$(OBJ_EX_P_in_11_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_11_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_in_12_UX_MT_D): \
			$(OBJ_EX_P_in_12_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_12_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_in_13_UX_MT_D): \
			$(OBJ_EX_P_in_13_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_13_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_in_14_UX_MT_D): \
			$(OBJ_EX_P_in_14_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_14_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_in_15_UX_MT_D): \
			$(OBJ_EX_P_in_15_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_15_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_in_16_UX_MT_D): \
			$(OBJ_EX_P_in_16_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_16_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_in_17_UX_MT_D): \
			$(OBJ_EX_P_in_17_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_in_17_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_ln_01_UX_MT_D): \
			$(OBJ_EX_P_ln_01_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ -libpath:$(PROJ_LIB_DIR)\
		$(OBJ_EX_P_ln_01_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_ms_01_UX_MT_D): \
			$(OBJ_EX_P_ms_01_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_ms_01_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_ms_02_UX_MT_D): \
			$(OBJ_EX_P_ms_02_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_ms_02_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_ms_03_UX_MT_D): \
			$(OBJ_EX_P_ms_03_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_ms_03_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_ms_04_UX_MT_D): \
			$(OBJ_EX_P_ms_04_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_ms_04_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_ms_05_UX_MT_D): \
			$(OBJ_EX_P_ms_05_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_ms_05_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_ut_01_UX_MT_D): \
			$(OBJ_EX_P_ut_01_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_P_ut_01_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_C_0_UX_MT_D): \
			$(OBJ_EX_C_0_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_C_0_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_C_1_UX_MT_D): \
			$(OBJ_EX_C_1_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_C_1_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_C_2_UX_MT_D): \
			$(OBJ_EX_C_2_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_C_2_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_C_3_UX_MT_D): \
			$(OBJ_EX_C_3_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_N_UX_MT_D)\
			$(LIB_BE_N_UX_MT_D)\
			$(LIB_BEC_FILE_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_BEC_NULL_UX_MT_D)\
			$(LIB_BEC_SYSLOG_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_C_3_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_N_UX_MT_D)\
		$(LIB_BE_N_UX_MT_D)\
		$(LIB_BEC_FILE_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_BEC_NULL_UX_MT_D)\
		$(LIB_BEC_SYSLOG_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_C_4_UX_MT_D): \
			$(OBJ_EX_C_4_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_C_4_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_C_5_UX_MT_D): \
			$(OBJ_EX_C_5_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_C_5_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_C_6_UX_MT_D): \
			$(OBJ_EX_C_6_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_C_6_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_C_7_UX_MT_D): \
			$(OBJ_EX_C_7_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_C_7_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_EX_P_be_01_UX_MT_R): \
			$(OBJ_EX_P_be_01_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_be_01_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_SYSLOG_UX_MT_R)\
		$(LIB_BEC_SYSLOG_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_be_02_UX_MT_R): \
			$(OBJ_EX_P_be_02_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FILE_UX_MT_R)\
			$(LIB_BEC_FILE_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_be_02_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FILE_UX_MT_R)\
		$(LIB_BEC_FILE_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_be_03_UX_MT_R): \
			$(OBJ_EX_P_be_03_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FILE_UX_MT_R)\
			$(LIB_BEC_FILE_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_be_03_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FILE_UX_MT_R)\
		$(LIB_BEC_FILE_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_be_04_UX_MT_R): \
			$(OBJ_EX_P_be_04_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FILE_UX_MT_R)\
			$(LIB_BEC_FILE_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_be_04_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FILE_UX_MT_R)\
		$(LIB_BEC_FILE_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_be_05_UX_MT_R): \
			$(OBJ_EX_P_be_05_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_N_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_BEC_SYSLOG_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_be_05_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_N_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_BEC_SYSLOG_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_be_06_UX_MT_R): \
			$(OBJ_EX_P_be_06_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_N_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_BEC_SYSLOG_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_be_06_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_N_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_BEC_SYSLOG_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_cp_01_UX_MT_R): \
			$(OBJ_EX_P_cp_01_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_cp_01_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_cp_02_UX_MT_R): \
			$(OBJ_EX_P_cp_02_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_cp_02_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_ms_06_UX_MT_R): \
			$(OBJ_EX_P_ms_06_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_ms_06_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_fm_01_UX_MT_R): \
			$(OBJ_EX_P_fm_01_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_fm_01_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_fm_02_UX_MT_R): \
			$(OBJ_EX_P_fm_02_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_fm_02_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_fm_03_UX_MT_R): \
			$(OBJ_EX_P_fm_03_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_fm_03_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_fe_01_UX_MT_R): \
			$(OBJ_EX_P_fe_01_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_fe_01_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_in_01_UX_MT_R): \
			$(OBJ_EX_P_in_01_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_01_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_in_02_UX_MT_R): \
			$(OBJ_EX_P_in_02_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_02_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

!ifndef PANTHEIOS_NO_B64

$(TARG_EX_P_in_03_UX_MT_R): \
			$(OBJ_EX_P_in_03_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_03_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)
!endif # !PANTHEIOS_NO_B64

$(TARG_EX_P_in_04_UX_MT_R): \
			$(OBJ_EX_P_in_04_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_04_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_in_05_UX_MT_R): \
			$(OBJ_EX_P_in_05_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_05_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_in_06_UX_MT_R): \
			$(OBJ_EX_P_in_06_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_06_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_in_07_UX_MT_R): \
			$(OBJ_EX_P_in_07_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_07_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_in_08_UX_MT_R): \
			$(OBJ_EX_P_in_08_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_08_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_in_09_UX_MT_R): \
			$(OBJ_EX_P_in_09_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_09_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_in_10_UX_MT_R): \
			$(OBJ_EX_P_in_10_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_10_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_in_11_UX_MT_R): \
			$(OBJ_EX_P_in_11_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_11_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_in_12_UX_MT_R): \
			$(OBJ_EX_P_in_12_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_12_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_in_13_UX_MT_R): \
			$(OBJ_EX_P_in_13_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_13_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_in_14_UX_MT_R): \
			$(OBJ_EX_P_in_14_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_14_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_in_15_UX_MT_R): \
			$(OBJ_EX_P_in_15_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_15_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_in_16_UX_MT_R): \
			$(OBJ_EX_P_in_16_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_16_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_in_17_UX_MT_R): \
			$(OBJ_EX_P_in_17_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_in_17_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_ln_01_UX_MT_R): \
			$(OBJ_EX_P_ln_01_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ -libpath:$(PROJ_LIB_DIR)\
		$(OBJ_EX_P_ln_01_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_ms_01_UX_MT_R): \
			$(OBJ_EX_P_ms_01_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_ms_01_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_ms_02_UX_MT_R): \
			$(OBJ_EX_P_ms_02_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_ms_02_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_ms_03_UX_MT_R): \
			$(OBJ_EX_P_ms_03_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_ms_03_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_ms_04_UX_MT_R): \
			$(OBJ_EX_P_ms_04_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_ms_04_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_ms_05_UX_MT_R): \
			$(OBJ_EX_P_ms_05_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_ms_05_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_P_ut_01_UX_MT_R): \
			$(OBJ_EX_P_ut_01_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_P_ut_01_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_C_0_UX_MT_R): \
			$(OBJ_EX_C_0_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_C_0_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_C_1_UX_MT_R): \
			$(OBJ_EX_C_1_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_C_1_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_C_2_UX_MT_R): \
			$(OBJ_EX_C_2_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_C_2_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_C_3_UX_MT_R): \
			$(OBJ_EX_C_3_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_N_UX_MT_R)\
			$(LIB_BE_N_UX_MT_R)\
			$(LIB_BEC_FILE_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_BEC_NULL_UX_MT_R)\
			$(LIB_BEC_SYSLOG_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_C_3_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_N_UX_MT_R)\
		$(LIB_BE_N_UX_MT_R)\
		$(LIB_BEC_FILE_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_BEC_NULL_UX_MT_R)\
		$(LIB_BEC_SYSLOG_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_C_4_UX_MT_R): \
			$(OBJ_EX_C_4_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_C_4_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_C_5_UX_MT_R): \
			$(OBJ_EX_C_5_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_C_5_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_C_6_UX_MT_R): \
			$(OBJ_EX_C_6_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_C_6_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_EX_C_7_UX_MT_R): \
			$(OBJ_EX_C_7_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_C_7_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)


##################################################
# tests

##############################
# component tests

LIBS_SYNSOFT_TEST_COMP_UX_MT_D=\
			$(LIB_SHWILD_UX_MT_D)\
			$(LIB_XCONTRACT_UX_MT_D)\
			$(LIB_XTESTS_UX_MT_D)\

LIBS_SYNSOFT_TEST_COMP_UX_MT_R=\
			$(LIB_SHWILD_UX_MT_R)\
			$(LIB_XCONTRACT_UX_MT_R)\
			$(LIB_XTESTS_UX_MT_R)\


$(TARG_TEST_COMP_core_initseq_UX_MT_D):	\
			$(OBJ_TEST_COMP_core_initseq_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_core_initseq_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_core_initseq_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.core.initialisation_sequence\test.component.core.initialisation_sequence.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.core.initialisation_sequence\test.component.core.initialisation_sequence.c

$(TARG_TEST_COMP_core_initseq_UX_MT_R):	\
			$(OBJ_TEST_COMP_core_initseq_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_core_initseq_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_core_initseq_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.core.initialisation_sequence\test.component.core.initialisation_sequence.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.core.initialisation_sequence\test.component.core.initialisation_sequence.c

$(TARG_TEST_COMP_custsev_UX_MT_D):	\
			$(OBJ_TEST_COMP_custsev_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_custsev_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_custsev_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.custom_severity\test.component.custom_severity.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.custom_severity\test.component.custom_severity.cpp

$(TARG_TEST_COMP_custsev_UX_MT_R):	\
			$(OBJ_TEST_COMP_custsev_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_custsev_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_custsev_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.custom_severity\test.component.custom_severity.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.custom_severity\test.component.custom_severity.cpp

$(TARG_TEST_COMP_filemt_UX_MT_D):	\
			$(OBJ_TEST_COMP_filemt_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_N_UX_MT_D)\
			$(LIB_BE_N_UX_MT_D)\
			$(LIB_BEC_FILE_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_filemt_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_N_UX_MT_D)\
		$(LIB_BE_N_UX_MT_D)\
		$(LIB_BEC_FILE_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_filemt_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.be.file.threading\test.component.be.file.threading.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.be.file.threading\test.component.be.file.threading.cpp

$(TARG_TEST_COMP_filemt_UX_MT_R):	\
			$(OBJ_TEST_COMP_filemt_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_N_UX_MT_R)\
			$(LIB_BE_N_UX_MT_R)\
			$(LIB_BEC_FILE_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_filemt_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_N_UX_MT_R)\
		$(LIB_BE_N_UX_MT_R)\
		$(LIB_BEC_FILE_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_filemt_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.be.file.threading\test.component.be.file.threading.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.be.file.threading\test.component.be.file.threading.cpp

$(TARG_TEST_COMP_bec_fprtf_UX_MT_D):	\
			$(OBJ_TEST_COMP_bec_fprtf_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_bec_fprtf_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_bec_fprtf_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.bec.fprintf\test.component.bec.fprintf.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.bec.fprintf\test.component.bec.fprintf.cpp

$(TARG_TEST_COMP_bec_fprtf_UX_MT_R):	\
			$(OBJ_TEST_COMP_bec_fprtf_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_bec_fprtf_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_bec_fprtf_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.bec.fprintf\test.component.bec.fprintf.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.bec.fprintf\test.component.bec.fprintf.cpp

$(TARG_TEST_COMP_ins_args_UX_MT_D):	\
			$(OBJ_TEST_COMP_ins_args_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_args_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_ins_args_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.args\test.component.inserters.args.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.args\test.component.inserters.args.cpp

$(TARG_TEST_COMP_ins_args_UX_MT_R):	\
			$(OBJ_TEST_COMP_ins_args_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_args_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_ins_args_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.args\test.component.inserters.args.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.args\test.component.inserters.args.cpp

!ifndef PANTHEIOS_NO_B64

$(TARG_TEST_COMP_ins_b64_UX_MT_D):	\
			$(OBJ_TEST_COMP_ins_b64_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(LIB_B64_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_b64_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_B64_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_ins_b64_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.b64\test.component.inserters.b64.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.b64\test.component.inserters.b64.cpp

$(TARG_TEST_COMP_ins_b64_UX_MT_R):	\
			$(OBJ_TEST_COMP_ins_b64_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(LIB_B64_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_b64_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_B64_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_ins_b64_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.b64\test.component.inserters.b64.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.b64\test.component.inserters.b64.cpp

!endif # !PANTHEIOS_NO_B64

$(TARG_TEST_COMP_ins_bool_UX_MT_D):	\
			$(OBJ_TEST_COMP_ins_bool_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_bool_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_ins_bool_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.boolean\test.component.inserters.boolean.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.boolean\test.component.inserters.boolean.cpp

$(TARG_TEST_COMP_ins_bool_UX_MT_R):	\
			$(OBJ_TEST_COMP_ins_bool_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_bool_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_ins_bool_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.boolean\test.component.inserters.boolean.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.boolean\test.component.inserters.boolean.cpp

$(TARG_TEST_COMP_ins_hostid_UX_MT_D):	\
			$(OBJ_TEST_COMP_ins_hostid_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_hostid_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_ins_hostid_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.hostid\test.component.inserters.hostid.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.hostid\test.component.inserters.hostid.cpp

$(TARG_TEST_COMP_ins_hostid_UX_MT_R):	\
			$(OBJ_TEST_COMP_ins_hostid_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_hostid_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_ins_hostid_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.hostid\test.component.inserters.hostid.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.hostid\test.component.inserters.hostid.cpp

$(TARG_TEST_COMP_ins_int_UX_MT_D):	\
			$(OBJ_TEST_COMP_ins_int_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_int_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_ins_int_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.integer\test.component.inserters.integer.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.integer\test.component.inserters.integer.cpp

$(TARG_TEST_COMP_ins_int_UX_MT_R):	\
			$(OBJ_TEST_COMP_ins_int_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_int_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_ins_int_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.integer\test.component.inserters.integer.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.integer\test.component.inserters.integer.cpp

$(TARG_TEST_COMP_ins_pad_UX_MT_D):	\
			$(OBJ_TEST_COMP_ins_pad_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_pad_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_ins_pad_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.pad\test.component.inserters.pad.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.pad\test.component.inserters.pad.cpp

$(TARG_TEST_COMP_ins_pad_UX_MT_R):	\
			$(OBJ_TEST_COMP_ins_pad_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_pad_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_ins_pad_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.pad\test.component.inserters.pad.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.pad\test.component.inserters.pad.cpp

$(TARG_TEST_COMP_ins_ptr_UX_MT_D):	\
			$(OBJ_TEST_COMP_ins_ptr_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_ptr_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_ins_ptr_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.pointer\test.component.inserters.pointer.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.pointer\test.component.inserters.pointer.cpp

$(TARG_TEST_COMP_ins_ptr_UX_MT_R):	\
			$(OBJ_TEST_COMP_ins_ptr_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_ptr_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_ins_ptr_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.pointer\test.component.inserters.pointer.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.pointer\test.component.inserters.pointer.cpp

$(TARG_TEST_COMP_ins_prid_UX_MT_D):	\
			$(OBJ_TEST_COMP_ins_prid_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_prid_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_ins_prid_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.processid\test.component.inserters.processid.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.processid\test.component.inserters.processid.cpp

$(TARG_TEST_COMP_ins_prid_UX_MT_R):	\
			$(OBJ_TEST_COMP_ins_prid_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_prid_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_ins_prid_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.processid\test.component.inserters.processid.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.processid\test.component.inserters.processid.cpp

$(TARG_TEST_COMP_ins_real_UX_MT_D):	\
			$(OBJ_TEST_COMP_ins_real_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_real_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_ins_real_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.real\test.component.inserters.real.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.real\test.component.inserters.real.cpp

$(TARG_TEST_COMP_ins_real_UX_MT_R):	\
			$(OBJ_TEST_COMP_ins_real_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_real_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_ins_real_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.real\test.component.inserters.real.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.real\test.component.inserters.real.cpp

$(TARG_TEST_COMP_ins_slice_UX_MT_D):	\
			$(OBJ_TEST_COMP_ins_slice_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_slice_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_ins_slice_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.slice\test.component.inserters.slice.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.slice\test.component.inserters.slice.cpp

$(TARG_TEST_COMP_ins_slice_UX_MT_R):	\
			$(OBJ_TEST_COMP_ins_slice_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_slice_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_ins_slice_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.slice\test.component.inserters.slice.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.slice\test.component.inserters.slice.cpp

$(TARG_TEST_COMP_ins_stm_ch_UX_MT_D):	\
			$(OBJ_TEST_COMP_ins_stm_ch_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_stm_ch_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_ins_stm_ch_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.stream_character\test.component.inserters.stream_character.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.stream_character\test.component.inserters.stream_character.cpp

$(TARG_TEST_COMP_ins_stm_ch_UX_MT_R):	\
			$(OBJ_TEST_COMP_ins_stm_ch_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_stm_ch_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_ins_stm_ch_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.stream_character\test.component.inserters.stream_character.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.stream_character\test.component.inserters.stream_character.cpp

$(TARG_TEST_COMP_ins_thrid_UX_MT_D):	\
			$(OBJ_TEST_COMP_ins_thrid_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_thrid_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_ins_thrid_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.threadid\test.component.inserters.threadid.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.threadid\test.component.inserters.threadid.cpp

$(TARG_TEST_COMP_ins_thrid_UX_MT_R):	\
			$(OBJ_TEST_COMP_ins_thrid_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_thrid_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_ins_thrid_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.threadid\test.component.inserters.threadid.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.threadid\test.component.inserters.threadid.cpp

$(TARG_TEST_COMP_ins_w2m_UX_MT_D):	\
			$(OBJ_TEST_COMP_ins_w2m_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_ins_w2m_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_ins_w2m_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.w2m\test.component.inserters.w2m.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.w2m\test.component.inserters.w2m.cpp

$(TARG_TEST_COMP_ins_w2m_UX_MT_R):	\
			$(OBJ_TEST_COMP_ins_w2m_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_ins_w2m_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_ins_w2m_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.w2m\test.component.inserters.w2m.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.inserters.w2m\test.component.inserters.w2m.cpp

$(TARG_TEST_COMP_log_1_UX_MT_D):	\
			$(OBJ_TEST_COMP_log_1_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_log_1_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_log_1_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.log.1\test.component.log.1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.log.1\test.component.log.1.cpp

$(TARG_TEST_COMP_log_1_UX_MT_R):	\
			$(OBJ_TEST_COMP_log_1_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_log_1_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_log_1_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.log.1\test.component.log.1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.log.1\test.component.log.1.cpp

$(TARG_TEST_COMP_pan_puts_UX_MT_D):	\
			$(OBJ_TEST_COMP_pan_puts_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_pan_puts_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_pan_puts_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.core.pantheios_logputs\test.component.core.pantheios_logputs.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.core.pantheios_logputs\test.component.core.pantheios_logputs.cpp

$(TARG_TEST_COMP_pan_puts_UX_MT_R):	\
			$(OBJ_TEST_COMP_pan_puts_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_pan_puts_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_pan_puts_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.core.pantheios_logputs\test.component.core.pantheios_logputs.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.core.pantheios_logputs\test.component.core.pantheios_logputs.cpp

$(TARG_TEST_COMP_pan_prtf_UX_MT_D):	\
			$(OBJ_TEST_COMP_pan_prtf_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIB_BE_TEST_UX_MT_D)\
			$(LIB_BEC_TEST_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_pan_prtf_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_BE_TEST_UX_MT_D)\
		$(LIB_BEC_TEST_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_COMP_pan_prtf_UX_MT_D):	$(PROJ_TEST_COMPONENT_DIR)\test.component.core.pantheios_logprintf\test.component.core.pantheios_logprintf.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.core.pantheios_logprintf\test.component.core.pantheios_logprintf.cpp

$(TARG_TEST_COMP_pan_prtf_UX_MT_R):	\
			$(OBJ_TEST_COMP_pan_prtf_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIB_BE_TEST_UX_MT_R)\
			$(LIB_BEC_TEST_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_pan_prtf_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_BE_TEST_UX_MT_R)\
		$(LIB_BEC_TEST_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_COMP_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_COMP_pan_prtf_UX_MT_R):	$(PROJ_TEST_COMPONENT_DIR)\test.component.core.pantheios_logprintf\test.component.core.pantheios_logprintf.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.core.pantheios_logprintf\test.component.core.pantheios_logprintf.cpp

##############################
# performance tests

$(TARG_TEST_PERF_ins_w2m_UX_MT_D):	\
			$(OBJ_TEST_PERF_ins_w2m_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_NULL_UX_MT_D)\
			$(LIB_BEC_NULL_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_PERF_ins_w2m_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_NULL_UX_MT_D)\
		$(LIB_BEC_NULL_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_PERF_ins_w2m_UX_MT_D):	$(PROJ_TEST_PERFORMANCE_DIR)\test.performance.inserters.w2m\test.performance.inserters.w2m.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.inserters.w2m\test.performance.inserters.w2m.cpp

$(TARG_TEST_PERF_ins_w2m_UX_MT_R):	\
			$(OBJ_TEST_PERF_ins_w2m_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_NULL_UX_MT_R)\
			$(LIB_BEC_NULL_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_PERF_ins_w2m_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_NULL_UX_MT_R)\
		$(LIB_BEC_NULL_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_PERF_ins_w2m_UX_MT_R):	$(PROJ_TEST_PERFORMANCE_DIR)\test.performance.inserters.w2m\test.performance.inserters.w2m.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.inserters.w2m\test.performance.inserters.w2m.cpp

$(TARG_TEST_PERF_dtel2s_UX_MT_D):	\
			$(OBJ_TEST_PERF_dtel2s_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_NULL_UX_MT_D)\
			$(LIB_BEC_NULL_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_PERF_dtel2s_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_NULL_UX_MT_D)\
		$(LIB_BEC_NULL_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_PERF_dtel2s_UX_MT_D):	$(PROJ_TEST_PERFORMANCE_DIR)\test.performance.util.date_elements_to_string\test.performance.util.date_elements_to_string.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.util.date_elements_to_string\test.performance.util.date_elements_to_string.cpp

$(TARG_TEST_PERF_dtel2s_UX_MT_R):	\
			$(OBJ_TEST_PERF_dtel2s_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_NULL_UX_MT_R)\
			$(LIB_BEC_NULL_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_PERF_dtel2s_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_NULL_UX_MT_R)\
		$(LIB_BEC_NULL_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_PERF_dtel2s_UX_MT_R):	$(PROJ_TEST_PERFORMANCE_DIR)\test.performance.util.date_elements_to_string\test.performance.util.date_elements_to_string.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_PERFORMANCE_DIR)\test.performance.util.date_elements_to_string\test.performance.util.date_elements_to_string.cpp

##############################
# scratch tests

#  object files

$(OBJ_SCRT_API_UX_MT_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.api\test.scratch.api.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_SCRATCH_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.api\test.scratch.api.cpp
$(OBJ_SCRT_API_UX_MT_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.api\test.scratch.api.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_SCRATCH_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.api\test.scratch.api.cpp

# executables

!ifdef ACE

$(TARG_SCRT_ACE_UX_MT_D):	\
			$(OBJ_SCRT_ACE_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_ACE_UX_MT_D)\
			$(LIB_BEC_ACE_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ -libpath:"$(ACE)\lib" -libpath:"$(ACE)\ace"\
		$(OBJ_SCRT_ACE_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_ACE_UX_MT_D)\
		$(LIB_BEC_ACE_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_ACE)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_SCRT_ACE_UX_MT_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.ACE\test.scratch.be.ACE.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_SCRATCH_ARGS_UX_MT_D) $(CPPC_ACE_ADDITIONAL_ARGS) $(CPPC_INCLUDES_ACE) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.ACE\test.scratch.be.ACE.cpp
!endif # ACE

$(TARG_SCRT_UX_MT_D_APIwBE_FPRINTF):	\
			$(OBJ_SCRT_API_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_SCRT_API_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_FPRINTF)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_SCRT_BE_SYSLOG_UX_MT_D):	\
			$(OBJ_SCRT_BE_SYSLOG_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_SYSLOG_UX_MT_D)\
			$(LIB_BEC_SYSLOG_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_SCRT_BE_SYSLOG_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_SYSLOG_UX_MT_D)\
		$(LIB_BEC_SYSLOG_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_SYSLOG)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_SCRT_BE_SYSLOG_UX_MT_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.syslog\test.scratch.be.syslog.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_SCRATCH_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.syslog\test.scratch.be.syslog.cpp

$(TARG_SCRT_BE_SYSLOGWC_UX_MT_D):	\
			$(OBJ_SCRT_BE_SYSLOGWC_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_SYSLOG_UX_MT_D)\
			$(LIB_BEC_SYSLOGWC_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_SCRT_BE_SYSLOGWC_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_SYSLOG_UX_MT_D)\
		$(LIB_BEC_SYSLOGWC_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_SYSLOG)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_SCRT_BE_SYSLOGWC_UX_MT_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.syslog.WithCallback\test.scratch.be.syslog.WithCallback.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_SCRATCH_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.syslog.WithCallback\test.scratch.be.syslog.WithCallback.cpp

$(TARG_SCRT_UX_MT_D_APIwBELR_1_FPRINTF_SYSLOG):	\
			$(OBJ_SCRT_API_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_LRSPLIT_UX_MT_D)\
			$(LIB_BEL_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_BER_SYSLOG_UX_MT_D)\
			$(LIB_BEC_SYSLOG_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_SCRT_API_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_LRSPLIT_UX_MT_D)\
		$(LIB_BEL_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_BER_SYSLOG_UX_MT_D)\
		$(LIB_BEC_SYSLOG_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(TARG_SCRT_FE_UX_MT_D): \
			$(OBJ_SCRT_FE_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_SCRT_FE_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_SCRT_FE_UX_MT_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.fe\test.scratch.fe.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_SCRATCH_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.fe\test.scratch.fe.cpp

$(TARG_SCRT_BE_N_FAIL_UX_MT_D):	\
			$(OBJ_SCRT_BE_N_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_N_UX_MT_D)\
			$(LIB_BE_N_UX_MT_D)\
			$(LIB_BEC_FAIL_UX_MT_D)\
			$(LIB_BEC_FILE_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_SCRT_BE_N_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_N_UX_MT_D)\
		$(LIB_BE_N_UX_MT_D)\
		$(LIB_BEC_FAIL_UX_MT_D)\
		$(LIB_BEC_FILE_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_SCRT_BE_N_UX_MT_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.N.fail\test.scratch.be.N.fail.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_SCRATCH_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.N.fail\test.scratch.be.N.fail.cpp

$(TARG_SCRT_FE_SIMPLE_WC_UX_MT_D):	\
			$(OBJ_SCRT_FE_SIMPLE_WC_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_SIMPLE_WC_UX_MT_D)\
			$(LIB_BE_FPRINTF_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_SCRT_FE_SIMPLE_WC_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_FE_SIMPLE_WC_UX_MT_D)\
		$(LIB_BE_FPRINTF_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_SCRT_FE_SIMPLE_WC_UX_MT_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.fe.simple.WithCallback\test.scratch.fe.simple.WithCallback.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_SCRATCH_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.fe.simple.WithCallback\test.scratch.fe.simple.WithCallback.cpp

!ifdef ACE

$(TARG_SCRT_ACE_UX_MT_R):	\
			$(OBJ_SCRT_ACE_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_ACE_UX_MT_R)\
			$(LIB_BEC_ACE_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ -libpath:"$(ACE)\lib" -libpath:"$(ACE)\ace"\
		$(OBJ_SCRT_ACE_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_ACE_UX_MT_R)\
		$(LIB_BEC_ACE_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_ACE)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_SCRT_ACE_UX_MT_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.ACE\test.scratch.be.ACE.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_SCRATCH_ARGS_UX_MT_R) $(CPPC_ACE_ADDITIONAL_ARGS) $(CPPC_INCLUDES_ACE) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.ACE\test.scratch.be.ACE.cpp
!endif # ACE

$(TARG_SCRT_UX_MT_R_APIwBE_FPRINTF):	\
			$(OBJ_SCRT_API_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_SCRT_API_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_FPRINTF)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_SCRT_BE_SYSLOG_UX_MT_R):	\
			$(OBJ_SCRT_BE_SYSLOG_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_SYSLOG_UX_MT_R)\
			$(LIB_BEC_SYSLOG_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_SCRT_BE_SYSLOG_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_SYSLOG_UX_MT_R)\
		$(LIB_BEC_SYSLOG_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_SYSLOG)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_SCRT_BE_SYSLOG_UX_MT_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.syslog\test.scratch.be.syslog.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_SCRATCH_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.syslog\test.scratch.be.syslog.cpp

$(TARG_SCRT_BE_SYSLOGWC_UX_MT_R):	\
			$(OBJ_SCRT_BE_SYSLOGWC_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_SYSLOG_UX_MT_R)\
			$(LIB_BEC_SYSLOGWC_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_SCRT_BE_SYSLOGWC_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_SYSLOG_UX_MT_R)\
		$(LIB_BEC_SYSLOGWC_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_SYSLOG)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_SCRT_BE_SYSLOGWC_UX_MT_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.syslog.WithCallback\test.scratch.be.syslog.WithCallback.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_SCRATCH_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.syslog.WithCallback\test.scratch.be.syslog.WithCallback.cpp

$(TARG_SCRT_UX_MT_R_APIwBELR_1_FPRINTF_SYSLOG):	\
			$(OBJ_SCRT_API_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_LRSPLIT_UX_MT_R)\
			$(LIB_BEL_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_BER_SYSLOG_UX_MT_R)\
			$(LIB_BEC_SYSLOG_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_SCRT_API_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_LRSPLIT_UX_MT_R)\
		$(LIB_BEL_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_BER_SYSLOG_UX_MT_R)\
		$(LIB_BEC_SYSLOG_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(TARG_SCRT_FE_UX_MT_R): \
			$(OBJ_SCRT_FE_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_SCRT_FE_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_SCRT_FE_UX_MT_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.fe\test.scratch.fe.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_SCRATCH_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.fe\test.scratch.fe.cpp

$(TARG_SCRT_BE_N_FAIL_UX_MT_R):	\
			$(OBJ_SCRT_BE_N_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_N_UX_MT_R)\
			$(LIB_BE_N_UX_MT_R)\
			$(LIB_BEC_FAIL_UX_MT_R)\
			$(LIB_BEC_FILE_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_SCRT_BE_N_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_N_UX_MT_R)\
		$(LIB_BE_N_UX_MT_R)\
		$(LIB_BEC_FAIL_UX_MT_R)\
		$(LIB_BEC_FILE_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_SCRT_BE_N_UX_MT_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.N.fail\test.scratch.be.N.fail.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_SCRATCH_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.be.N.fail\test.scratch.be.N.fail.cpp

$(TARG_SCRT_FE_SIMPLE_WC_UX_MT_R):	\
			$(OBJ_SCRT_FE_SIMPLE_WC_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_SIMPLE_WC_UX_MT_R)\
			$(LIB_BE_FPRINTF_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_SCRT_FE_SIMPLE_WC_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_FE_SIMPLE_WC_UX_MT_R)\
		$(LIB_BE_FPRINTF_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_3PTY_BE_N_FAIL)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_SCRT_FE_SIMPLE_WC_UX_MT_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.fe.simple.WithCallback\test.scratch.fe.simple.WithCallback.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_SCRATCH_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.fe.simple.WithCallback\test.scratch.fe.simple.WithCallback.cpp

##############################
# unit tests

LIBS_SYNSOFT_TEST_UNIT_UX_MT_D=\
			$(LIB_SHWILD_UX_MT_D)\
			$(LIB_XCONTRACT_UX_MT_D)\
			$(LIB_XTESTS_UX_MT_D)\

LIBS_SYNSOFT_TEST_UNIT_UX_MT_R=\
			$(LIB_SHWILD_UX_MT_R)\
			$(LIB_XCONTRACT_UX_MT_R)\
			$(LIB_XTESTS_UX_MT_R)\


$(TARG_TEST_UNIT_lvls_dyninit_UX_MT_D):	\
			$(OBJ_TEST_UNIT_lvls_dyninit_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_lvls_dyninit_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_lvls_dyninit_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.levels.dynamic_initialisation\test.unit.levels.dynamic_initialisation.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.levels.dynamic_initialisation\test.unit.levels.dynamic_initialisation.cpp

$(TARG_TEST_UNIT_lvls_dyninit_UX_MT_R):	\
			$(OBJ_TEST_UNIT_lvls_dyninit_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_lvls_dyninit_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_lvls_dyninit_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.levels.dynamic_initialisation\test.unit.levels.dynamic_initialisation.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.levels.dynamic_initialisation\test.unit.levels.dynamic_initialisation.cpp

$(TARG_TEST_UNIT_lvls_vals_UX_MT_D):	\
			$(OBJ_TEST_UNIT_lvls_vals_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_lvls_vals_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_lvls_vals_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.levels.values\test.unit.levels.values.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.levels.values\test.unit.levels.values.c

$(TARG_TEST_UNIT_lvls_vals_UX_MT_R):	\
			$(OBJ_TEST_UNIT_lvls_vals_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_lvls_vals_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_lvls_vals_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.levels.values\test.unit.levels.values.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.levels.values\test.unit.levels.values.c

$(TARG_TEST_UNIT_getcurrtm_UX_MT_D):	\
			$(OBJ_TEST_UNIT_getcurrtm_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_getcurrtm_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_getcurrtm_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.util.getcurrenttime\test.unit.util.getcurrenttime.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.util.getcurrenttime\test.unit.util.getcurrenttime.cpp

$(TARG_TEST_UNIT_getcurrtm_UX_MT_R):	\
			$(OBJ_TEST_UNIT_getcurrtm_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_getcurrtm_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_getcurrtm_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.util.getcurrenttime\test.unit.util.getcurrenttime.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.util.getcurrenttime\test.unit.util.getcurrenttime.cpp

$(TARG_TEST_UNIT_dtel2s_UX_MT_D):	\
			$(OBJ_TEST_UNIT_dtel2s_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_FAIL_UX_MT_D)\
			$(LIB_BE_FAIL_UX_MT_D)\
			$(LIB_BEC_FAIL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_dtel2s_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIB_FE_FAIL_UX_MT_D)\
		$(LIB_BE_FAIL_UX_MT_D)\
		$(LIB_BEC_FAIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_dtel2s_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.util.date_elements_to_string\test.unit.util.date_elements_to_string.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.util.date_elements_to_string\test.unit.util.date_elements_to_string.cpp

$(TARG_TEST_UNIT_dtel2s_UX_MT_R):	\
			$(OBJ_TEST_UNIT_dtel2s_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_FAIL_UX_MT_R)\
			$(LIB_BE_FAIL_UX_MT_R)\
			$(LIB_BEC_FAIL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_dtel2s_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIB_FE_FAIL_UX_MT_R)\
		$(LIB_BE_FAIL_UX_MT_R)\
		$(LIB_BEC_FAIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_dtel2s_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.util.date_elements_to_string\test.unit.util.date_elements_to_string.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.util.date_elements_to_string\test.unit.util.date_elements_to_string.cpp

$(TARG_TEST_UNIT_getversion_UX_MT_D):	\
			$(OBJ_TEST_UNIT_getversion_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_FAIL_UX_MT_D)\
			$(LIB_BE_FAIL_UX_MT_D)\
			$(LIB_BEC_FAIL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_getversion_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIB_FE_FAIL_UX_MT_D)\
		$(LIB_BE_FAIL_UX_MT_D)\
		$(LIB_BEC_FAIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_getversion_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.getversion\test.unit.getversion.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.getversion\test.unit.getversion.c

$(TARG_TEST_UNIT_getversion_UX_MT_R):	\
			$(OBJ_TEST_UNIT_getversion_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_FAIL_UX_MT_R)\
			$(LIB_BE_FAIL_UX_MT_R)\
			$(LIB_BEC_FAIL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_getversion_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIB_FE_FAIL_UX_MT_R)\
		$(LIB_BE_FAIL_UX_MT_R)\
		$(LIB_BEC_FAIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_getversion_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.getversion\test.unit.getversion.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.getversion\test.unit.getversion.c

$(TARG_TEST_UNIT_gethostname_UX_MT_D):	\
			$(OBJ_TEST_UNIT_gethostname_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_gethostname_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_gethostname_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.util.gethostname\test.unit.util.gethostname.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.util.gethostname\test.unit.util.gethostname.cpp

$(TARG_TEST_UNIT_gethostname_UX_MT_R):	\
			$(OBJ_TEST_UNIT_gethostname_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_gethostname_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_gethostname_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.util.gethostname\test.unit.util.gethostname.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.util.gethostname\test.unit.util.gethostname.cpp

$(TARG_TEST_UNIT_onbailout_UX_MT_D):	\
			$(OBJ_TEST_UNIT_onbailout_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_onbailout_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_onbailout_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.util.onbailout\test.unit.util.onbailout.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.util.onbailout\test.unit.util.onbailout.cpp

$(TARG_TEST_UNIT_onbailout_UX_MT_R):	\
			$(OBJ_TEST_UNIT_onbailout_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_onbailout_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_onbailout_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.util.onbailout\test.unit.util.onbailout.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.util.onbailout\test.unit.util.onbailout.cpp

$(TARG_TEST_UNIT_snprintf_UX_MT_D):	\
			$(OBJ_TEST_UNIT_snprintf_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_snprintf_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_snprintf_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.util.snprintf\test.unit.util.snprintf.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.util.snprintf\test.unit.util.snprintf.cpp

$(TARG_TEST_UNIT_snprintf_UX_MT_R):	\
			$(OBJ_TEST_UNIT_snprintf_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_snprintf_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_snprintf_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.util.snprintf\test.unit.util.snprintf.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.util.snprintf\test.unit.util.snprintf.cpp

$(TARG_TEST_UNIT_strnlen_UX_MT_D):	\
			$(OBJ_TEST_UNIT_strnlen_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_strnlen_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_strnlen_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.util.strnlen\test.unit.util.strnlen.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.util.strnlen\test.unit.util.strnlen.cpp

$(TARG_TEST_UNIT_strnlen_UX_MT_R):	\
			$(OBJ_TEST_UNIT_strnlen_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_strnlen_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_strnlen_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.util.strnlen\test.unit.util.strnlen.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.util.strnlen\test.unit.util.strnlen.cpp

$(TARG_TEST_UNIT_bec_file_UX_MT_D):	\
			$(OBJ_TEST_UNIT_bec_file_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_BEC_FILE_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_NULL_UX_MT_D)\
			$(LIB_BEC_NULL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_bec_file_UX_MT_D)\
		$(LIB_BEC_FILE_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_NULL_UX_MT_D)\
		$(LIB_BEC_NULL_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_bec_file_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.bec.file\test.unit.bec.file.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.bec.file\test.unit.bec.file.cpp

$(TARG_TEST_UNIT_bec_file_UX_MT_R):	\
			$(OBJ_TEST_UNIT_bec_file_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_BEC_FILE_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_NULL_UX_MT_R)\
			$(LIB_BEC_NULL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_bec_file_UX_MT_R)\
		$(LIB_BEC_FILE_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_NULL_UX_MT_R)\
		$(LIB_BEC_NULL_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_bec_file_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.bec.file\test.unit.bec.file.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.bec.file\test.unit.bec.file.cpp

$(TARG_TEST_UNIT_bec_fprintf_UX_MT_D):	\
			$(OBJ_TEST_UNIT_bec_fprintf_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_BEC_FPRINTF_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIB_BE_NULL_UX_MT_D)\
			$(LIB_BEC_NULL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_bec_fprintf_UX_MT_D)\
		$(LIB_BEC_FPRINTF_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIB_BE_NULL_UX_MT_D)\
		$(LIB_BEC_NULL_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_bec_fprintf_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.bec.fprintf\test.unit.bec.fprintf.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.bec.fprintf\test.unit.bec.fprintf.cpp

$(TARG_TEST_UNIT_bec_fprintf_UX_MT_R):	\
			$(OBJ_TEST_UNIT_bec_fprintf_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_BEC_FPRINTF_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIB_BE_NULL_UX_MT_R)\
			$(LIB_BEC_NULL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_bec_fprintf_UX_MT_R)\
		$(LIB_BEC_FPRINTF_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIB_BE_NULL_UX_MT_R)\
		$(LIB_BEC_NULL_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_bec_fprintf_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.bec.fprintf\test.unit.bec.fprintf.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.bec.fprintf\test.unit.bec.fprintf.cpp

$(TARG_TEST_UNIT_bec_fail_UX_MT_D):	\
			$(OBJ_TEST_UNIT_bec_fail_UX_MT_D)\
			$(LIB_BEC_FAIL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_bec_fail_UX_MT_D)\
		$(LIB_BEC_FAIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_bec_fail_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.bec.fail\test.unit.bec.fail.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.bec.fail\test.unit.bec.fail.c

$(TARG_TEST_UNIT_bec_fail_UX_MT_R):	\
			$(OBJ_TEST_UNIT_bec_fail_UX_MT_R)\
			$(LIB_BEC_FAIL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_bec_fail_UX_MT_R)\
		$(LIB_BEC_FAIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_bec_fail_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.bec.fail\test.unit.bec.fail.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.bec.fail\test.unit.bec.fail.c

$(TARG_TEST_UNIT_be_fail_UX_MT_D):	\
			$(OBJ_TEST_UNIT_be_fail_UX_MT_D)\
			$(LIB_BE_FAIL_UX_MT_D)\
			$(LIB_BEC_FAIL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_be_fail_UX_MT_D)\
		$(LIB_BE_FAIL_UX_MT_D)\
		$(LIB_BEC_FAIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_be_fail_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.be.fail\test.unit.be.fail.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.be.fail\test.unit.be.fail.c

$(TARG_TEST_UNIT_be_fail_UX_MT_R):	\
			$(OBJ_TEST_UNIT_be_fail_UX_MT_R)\
			$(LIB_BE_FAIL_UX_MT_R)\
			$(LIB_BEC_FAIL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_be_fail_UX_MT_R)\
		$(LIB_BE_FAIL_UX_MT_R)\
		$(LIB_BEC_FAIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_be_fail_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.be.fail\test.unit.be.fail.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.be.fail\test.unit.be.fail.c

#
$(TARG_TEST_UNIT_be_lrsplit_UX_MT_D):	\
			$(OBJ_TEST_UNIT_be_lrsplit_UX_MT_D)\
			$(LIB_BE_LRSPLIT_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_be_lrsplit_UX_MT_D)\
		$(LIB_BE_LRSPLIT_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_be_lrsplit_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.be.lrsplit\test.unit.be.lrsplit.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.be.lrsplit\test.unit.be.lrsplit.c

$(TARG_TEST_UNIT_be_lrsplit_UX_MT_R):	\
			$(OBJ_TEST_UNIT_be_lrsplit_UX_MT_R)\
			$(LIB_BE_LRSPLIT_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_be_lrsplit_UX_MT_R)\
		$(LIB_BE_LRSPLIT_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_be_lrsplit_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.be.lrsplit\test.unit.be.lrsplit.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.be.lrsplit\test.unit.be.lrsplit.c

$(TARG_TEST_UNIT_be_N_UX_MT_D):	\
			$(OBJ_TEST_UNIT_be_N_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_BE_N_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_be_N_UX_MT_D)\
		$(LIB_BE_N_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_be_N_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.be.N\test.unit.be.N.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.be.N\test.unit.be.N.c

$(TARG_TEST_UNIT_be_N_UX_MT_R):	\
			$(OBJ_TEST_UNIT_be_N_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_BE_N_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_be_N_UX_MT_R)\
		$(LIB_BE_N_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_be_N_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.be.N\test.unit.be.N.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.be.N\test.unit.be.N.c

$(TARG_TEST_UNIT_be_N_filt_UX_MT_D):	\
			$(OBJ_TEST_UNIT_be_N_filt_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_BE_N_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_be_N_filt_UX_MT_D)\
		$(LIB_BE_N_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_be_N_filt_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.be.N.filtering\test.unit.be.N.filtering.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.be.N.filtering\test.unit.be.N.filtering.c

$(TARG_TEST_UNIT_be_N_filt_UX_MT_R):	\
			$(OBJ_TEST_UNIT_be_N_filt_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_BE_N_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_be_N_filt_UX_MT_R)\
		$(LIB_BE_N_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_be_N_filt_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.be.N.filtering\test.unit.be.N.filtering.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.be.N.filtering\test.unit.be.N.filtering.c

$(TARG_TEST_UNIT_fe_all_UX_MT_D):	\
			$(OBJ_TEST_UNIT_fe_all_UX_MT_D)\
			$(LIB_FE_ALL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_fe_all_UX_MT_D)\
		$(LIB_FE_ALL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_fe_all_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.fe.all\test.unit.fe.all.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.fe.all\test.unit.fe.all.c

$(TARG_TEST_UNIT_fe_all_UX_MT_R):	\
			$(OBJ_TEST_UNIT_fe_all_UX_MT_R)\
			$(LIB_FE_ALL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_fe_all_UX_MT_R)\
		$(LIB_FE_ALL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_fe_all_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.fe.all\test.unit.fe.all.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.fe.all\test.unit.fe.all.c

$(TARG_TEST_UNIT_fe_fail_UX_MT_D):	\
			$(OBJ_TEST_UNIT_fe_fail_UX_MT_D)\
			$(LIB_FE_FAIL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_fe_fail_UX_MT_D)\
		$(LIB_FE_FAIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_fe_fail_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.fe.fail\test.unit.fe.fail.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.fe.fail\test.unit.fe.fail.c

$(TARG_TEST_UNIT_fe_fail_UX_MT_R):	\
			$(OBJ_TEST_UNIT_fe_fail_UX_MT_R)\
			$(LIB_FE_FAIL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_fe_fail_UX_MT_R)\
		$(LIB_FE_FAIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_fe_fail_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.fe.fail\test.unit.fe.fail.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.fe.fail\test.unit.fe.fail.c

$(TARG_TEST_UNIT_fe_N_UX_MT_D):	\
			$(OBJ_TEST_UNIT_fe_N_UX_MT_D)\
			$(LIB_FE_N_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_fe_N_UX_MT_D)\
		$(LIB_FE_N_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_fe_N_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.fe.N\test.unit.fe.N.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.fe.N\test.unit.fe.N.c

$(TARG_TEST_UNIT_fe_N_UX_MT_R):	\
			$(OBJ_TEST_UNIT_fe_N_UX_MT_R)\
			$(LIB_FE_N_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_fe_N_UX_MT_R)\
		$(LIB_FE_N_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_fe_N_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.fe.N\test.unit.fe.N.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.fe.N\test.unit.fe.N.c

$(TARG_TEST_UNIT_fe_null_UX_MT_D):	\
			$(OBJ_TEST_UNIT_fe_null_UX_MT_D)\
			$(LIB_FE_NULL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_fe_null_UX_MT_D)\
		$(LIB_FE_NULL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_fe_null_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.fe.null\test.unit.fe.null.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.fe.null\test.unit.fe.null.c

$(TARG_TEST_UNIT_fe_null_UX_MT_R):	\
			$(OBJ_TEST_UNIT_fe_null_UX_MT_R)\
			$(LIB_FE_NULL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_fe_null_UX_MT_R)\
		$(LIB_FE_NULL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_fe_null_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.fe.null\test.unit.fe.null.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.fe.null\test.unit.fe.null.c

$(TARG_TEST_UNIT_fe_simple_UX_MT_D):	\
			$(OBJ_TEST_UNIT_fe_simple_UX_MT_D)\
			$(LIB_FE_SIMPLE_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_fe_simple_UX_MT_D)\
		$(LIB_FE_SIMPLE_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_fe_simple_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\test.unit.fe.simple\test.unit.fe.simple.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.fe.simple\test.unit.fe.simple.c

$(TARG_TEST_UNIT_fe_simple_UX_MT_R):	\
			$(OBJ_TEST_UNIT_fe_simple_UX_MT_R)\
			$(LIB_FE_SIMPLE_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_fe_simple_UX_MT_R)\
		$(LIB_FE_SIMPLE_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_fe_simple_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\test.unit.fe.simple\test.unit.fe.simple.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_TEST_UNIT_ARGS_UX_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.fe.simple\test.unit.fe.simple.c

$(TARG_TEST_UNIT_ins_int_UX_MT_D):	\
			$(OBJ_TEST_UNIT_ins_int_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_ins_int_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_ins_int_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\inserters\test.unit.inserter.integer\test.unit.inserter.integer.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\inserters\test.unit.inserter.integer\test.unit.inserter.integer.cpp

$(TARG_TEST_UNIT_ins_int_UX_MT_R):	\
			$(OBJ_TEST_UNIT_ins_int_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_ins_int_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_ins_int_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\inserters\test.unit.inserter.integer\test.unit.inserter.integer.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\inserters\test.unit.inserter.integer\test.unit.inserter.integer.cpp

$(TARG_TEST_UNIT_ins_w2m_UX_MT_D):	\
			$(OBJ_TEST_UNIT_ins_w2m_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIB_FE_NULL_UX_MT_D)\
			$(LIB_BE_NULL_UX_MT_D)\
			$(LIB_BEC_NULL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_ins_w2m_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIB_FE_NULL_UX_MT_D)\
		$(LIB_BE_NULL_UX_MT_D)\
		$(LIB_BEC_NULL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_ins_w2m_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\inserters\test.unit.inserter.w2m\test.unit.inserter.w2m.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\inserters\test.unit.inserter.w2m\test.unit.inserter.w2m.cpp

$(TARG_TEST_UNIT_ins_w2m_UX_MT_R):	\
			$(OBJ_TEST_UNIT_ins_w2m_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIB_FE_NULL_UX_MT_R)\
			$(LIB_BE_NULL_UX_MT_R)\
			$(LIB_BEC_NULL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_ins_w2m_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIB_FE_NULL_UX_MT_R)\
		$(LIB_BE_NULL_UX_MT_R)\
		$(LIB_BEC_NULL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_ins_w2m_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\inserters\test.unit.inserter.w2m\test.unit.inserter.w2m.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\inserters\test.unit.inserter.w2m\test.unit.inserter.w2m.cpp

$(TARG_TEST_UNIT_ins_stmc_UX_MT_D):	\
			$(OBJ_TEST_UNIT_ins_stmc_UX_MT_D)\
			$(LIB_CORE_UX_MT_D)\
			$(LIB_UTIL_UX_MT_D)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_ins_stmc_UX_MT_D)\
		$(LIB_CORE_UX_MT_D)\
		$(LIB_UTIL_UX_MT_D)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_D)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_D)

$(OBJ_TEST_UNIT_ins_stmc_UX_MT_D):	$(PROJ_TEST_UNIT_DIR)\inserters\test.unit.inserter.stream_character\test.unit.inserter.stream_character.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\inserters\test.unit.inserter.stream_character\test.unit.inserter.stream_character.cpp

$(TARG_TEST_UNIT_ins_stmc_UX_MT_R):	\
			$(OBJ_TEST_UNIT_ins_stmc_UX_MT_R)\
			$(LIB_CORE_UX_MT_R)\
			$(LIB_UTIL_UX_MT_R)\
			$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_ins_stmc_UX_MT_R)\
		$(LIB_CORE_UX_MT_R)\
		$(LIB_UTIL_UX_MT_R)\
		$(LIBS_SYNSOFT_TEST_UNIT_UX_MT_R)\
		$(LIBS_3PTY_TEST_UNIT)\
		$(TARGET_LIB_UX_MT_R)

$(OBJ_TEST_UNIT_ins_stmc_UX_MT_R):	$(PROJ_TEST_UNIT_DIR)\inserters\test.unit.inserter.stream_character\test.unit.inserter.stream_character.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_TEST_UNIT_ARGS_UX_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_UNIT_DIR)\inserters\test.unit.inserter.stream_character\test.unit.inserter.stream_character.cpp

############################### end of file ################################
