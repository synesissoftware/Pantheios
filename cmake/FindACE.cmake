# FindACE.cmake
#
# Locates the ACE (Adaptive Communication Environment) headers and library.
#
# Sets:
#   ACE_FOUND
#   ACE_INCLUDE_DIRS
#   ACE_LIBRARIES
#   ACE_VERSION (when discoverable)
#
# Provides imported target:
#   ACE::ACE
#
# Search order for the ACE root (directory that contains `ace/ACE.h`, or
# `include/ace/ACE.h`):
#   1. CMake variable ACE
#   2. CMake variable ACE_ROOT
#   3. Environment variable ACE
#   4. Environment variable ACE_ROOT
#   5. Standard system locations (e.g. /usr/include via find_path)


set(_ACE_ROOT_CANDIDATES)

if(DEFINED ACE AND ACE)

	list(APPEND _ACE_ROOT_CANDIDATES "${ACE}")
endif()

if(DEFINED ACE_ROOT AND ACE_ROOT)

	list(APPEND _ACE_ROOT_CANDIDATES "${ACE_ROOT}")
endif()

if(DEFINED ENV{ACE} AND NOT "$ENV{ACE}" STREQUAL "")

	list(APPEND _ACE_ROOT_CANDIDATES "$ENV{ACE}")
endif()

if(DEFINED ENV{ACE_ROOT} AND NOT "$ENV{ACE_ROOT}" STREQUAL "")

	list(APPEND _ACE_ROOT_CANDIDATES "$ENV{ACE_ROOT}")
endif()

set(_ACE_INCLUDE_HINTS)
set(_ACE_LIBRARY_HINTS)

foreach(_ace_root IN LISTS _ACE_ROOT_CANDIDATES)

	get_filename_component(_ace_root_abs "${_ace_root}" ABSOLUTE)

	list(APPEND _ACE_INCLUDE_HINTS
		"${_ace_root_abs}"
		"${_ace_root_abs}/include"
	)
	list(APPEND _ACE_LIBRARY_HINTS
		"${_ace_root_abs}"
		"${_ace_root_abs}/lib"
		"${_ace_root_abs}/ace"
	)
endforeach()

find_path(ACE_INCLUDE_DIR
	NAMES
		ace/ACE.h
	HINTS
		${_ACE_INCLUDE_HINTS}
	PATHS
		/usr/include
		/usr/local/include
	DOC
		"Directory containing ace/ACE.h"
)

find_library(ACE_LIBRARY
	NAMES
		ACE
		ace
	HINTS
		${_ACE_LIBRARY_HINTS}
	PATHS
		/usr/lib
		/usr/local/lib
	DOC
		"ACE library"
)

unset(_ACE_ROOT_CANDIDATES)
unset(_ACE_INCLUDE_HINTS)
unset(_ACE_LIBRARY_HINTS)

set(ACE_VERSION)

if(ACE_INCLUDE_DIR AND EXISTS "${ACE_INCLUDE_DIR}/ace/Version.h")

	file(STRINGS "${ACE_INCLUDE_DIR}/ace/Version.h" _ACE_VERSION_LINE
		REGEX "^[ \t]*#define[ \t]+ACE_VERSION[ \t]+"
	)

	if(_ACE_VERSION_LINE)

		string(REGEX REPLACE "^.*ACE_VERSION[ \t]+\"([^\"]+)\".*$" "\\1"
			ACE_VERSION "${_ACE_VERSION_LINE}"
		)
	endif()

	unset(_ACE_VERSION_LINE)
endif()

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(ACE
	REQUIRED_VARS
		ACE_LIBRARY
		ACE_INCLUDE_DIR
	VERSION_VAR
		ACE_VERSION
)

if(ACE_FOUND)

	set(ACE_INCLUDE_DIRS "${ACE_INCLUDE_DIR}")
	set(ACE_LIBRARIES "${ACE_LIBRARY}")

	if(NOT TARGET ACE::ACE)

		add_library(ACE::ACE UNKNOWN IMPORTED)
		set_target_properties(ACE::ACE
			PROPERTIES
				IMPORTED_LOCATION "${ACE_LIBRARY}"
				INTERFACE_INCLUDE_DIRECTORIES "${ACE_INCLUDE_DIR}"
		)
	endif()
endif()

mark_as_advanced(ACE_INCLUDE_DIR ACE_LIBRARY)


# ############################## end of file ############################# #
