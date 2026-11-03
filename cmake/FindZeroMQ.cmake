# FindZeroMQ.cmake
#
# Locates the ZeroMQ (aka 0MQ / libzmq) headers and library.
#
# Sets:
#   ZeroMQ_FOUND
#   ZeroMQ_INCLUDE_DIRS
#   ZeroMQ_LIBRARIES
#   ZeroMQ_VERSION (when discoverable)
#
# Provides imported target:
#   ZeroMQ::ZeroMQ
#
# Search order for hints:
#   1. CMake variable ZeroMQ_ROOT / ZEROMQ_ROOT / ZMQ_ROOT
#   2. Environment variable ZeroMQ_ROOT / ZEROMQ_ROOT / ZMQ_ROOT
#   3. Standard system locations (e.g. /usr/include via find_path)


set(_ZEROMQ_ROOT_CANDIDATES)

foreach(_zmq_root_var IN ITEMS ZeroMQ_ROOT ZEROMQ_ROOT ZMQ_ROOT)

	if(DEFINED ${_zmq_root_var} AND ${_zmq_root_var})

		list(APPEND _ZEROMQ_ROOT_CANDIDATES "${${_zmq_root_var}}")
	endif()

	if(DEFINED ENV{${_zmq_root_var}} AND NOT "$ENV{${_zmq_root_var}}" STREQUAL "")

		list(APPEND _ZEROMQ_ROOT_CANDIDATES "$ENV{${_zmq_root_var}}")
	endif()
endforeach()

set(_ZEROMQ_INCLUDE_HINTS)
set(_ZEROMQ_LIBRARY_HINTS)

foreach(_zmq_root IN LISTS _ZEROMQ_ROOT_CANDIDATES)

	get_filename_component(_zmq_root_abs "${_zmq_root}" ABSOLUTE)

	list(APPEND _ZEROMQ_INCLUDE_HINTS
		"${_zmq_root_abs}"
		"${_zmq_root_abs}/include"
	)
	list(APPEND _ZEROMQ_LIBRARY_HINTS
		"${_zmq_root_abs}"
		"${_zmq_root_abs}/lib"
		"${_zmq_root_abs}/lib64"
	)
endforeach()

find_path(ZeroMQ_INCLUDE_DIR
	NAMES
		zmq.h
	HINTS
		${_ZEROMQ_INCLUDE_HINTS}
	PATHS
		/usr/include
		/usr/local/include
	DOC
		"Directory containing zmq.h"
)

find_library(ZeroMQ_LIBRARY
	NAMES
		zmq
		libzmq
	HINTS
		${_ZEROMQ_LIBRARY_HINTS}
	PATHS
		/usr/lib
		/usr/local/lib
	DOC
		"ZeroMQ (libzmq) library"
)

unset(_ZEROMQ_ROOT_CANDIDATES)
unset(_ZEROMQ_INCLUDE_HINTS)
unset(_ZEROMQ_LIBRARY_HINTS)

set(ZeroMQ_VERSION)

if(ZeroMQ_INCLUDE_DIR AND EXISTS "${ZeroMQ_INCLUDE_DIR}/zmq.h")

	file(STRINGS "${ZeroMQ_INCLUDE_DIR}/zmq.h" _ZEROMQ_VERSION_MAJOR
		REGEX "^[ \t]*#define[ \t]+ZMQ_VERSION_MAJOR[ \t]+"
	)
	file(STRINGS "${ZeroMQ_INCLUDE_DIR}/zmq.h" _ZEROMQ_VERSION_MINOR
		REGEX "^[ \t]*#define[ \t]+ZMQ_VERSION_MINOR[ \t]+"
	)
	file(STRINGS "${ZeroMQ_INCLUDE_DIR}/zmq.h" _ZEROMQ_VERSION_PATCH
		REGEX "^[ \t]*#define[ \t]+ZMQ_VERSION_PATCH[ \t]+"
	)

	if(_ZEROMQ_VERSION_MAJOR AND _ZEROMQ_VERSION_MINOR AND _ZEROMQ_VERSION_PATCH)

		string(REGEX REPLACE "^.*ZMQ_VERSION_MAJOR[ \t]+([0-9]+).*$" "\\1"
			_ZEROMQ_MAJOR "${_ZEROMQ_VERSION_MAJOR}"
		)
		string(REGEX REPLACE "^.*ZMQ_VERSION_MINOR[ \t]+([0-9]+).*$" "\\1"
			_ZEROMQ_MINOR "${_ZEROMQ_VERSION_MINOR}"
		)
		string(REGEX REPLACE "^.*ZMQ_VERSION_PATCH[ \t]+([0-9]+).*$" "\\1"
			_ZEROMQ_PATCH "${_ZEROMQ_VERSION_PATCH}"
		)
		set(ZeroMQ_VERSION "${_ZEROMQ_MAJOR}.${_ZEROMQ_MINOR}.${_ZEROMQ_PATCH}")
		unset(_ZEROMQ_MAJOR)
		unset(_ZEROMQ_MINOR)
		unset(_ZEROMQ_PATCH)
	endif()

	unset(_ZEROMQ_VERSION_MAJOR)
	unset(_ZEROMQ_VERSION_MINOR)
	unset(_ZEROMQ_VERSION_PATCH)
endif()

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(ZeroMQ
	REQUIRED_VARS
		ZeroMQ_LIBRARY
		ZeroMQ_INCLUDE_DIR
	VERSION_VAR
		ZeroMQ_VERSION
)

if(ZeroMQ_FOUND)

	set(ZeroMQ_INCLUDE_DIRS "${ZeroMQ_INCLUDE_DIR}")
	set(ZeroMQ_LIBRARIES "${ZeroMQ_LIBRARY}")

	if(NOT TARGET ZeroMQ::ZeroMQ)

		add_library(ZeroMQ::ZeroMQ UNKNOWN IMPORTED)
		set_target_properties(ZeroMQ::ZeroMQ
			PROPERTIES
				IMPORTED_LOCATION "${ZeroMQ_LIBRARY}"
				INTERFACE_INCLUDE_DIRECTORIES "${ZeroMQ_INCLUDE_DIR}"
		)
	endif()
endif()

mark_as_advanced(ZeroMQ_INCLUDE_DIR ZeroMQ_LIBRARY)


# ############################## end of file ############################# #
