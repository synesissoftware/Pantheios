
include_directories(${CMAKE_SOURCE_DIR}/include)

if(APPLE)

	message("-- -- adding '/usr/local/include' to include-directories for 'examples'")

	include_directories("/usr/local/include")

	include_directories("/usr/local/lib")
endif(APPLE)


if(WIN32)

	message(FATAL_ERROR "Use of CMake on Windows not currently supported")
endif(WIN32)

if(UNIX)

	add_definitions(-DUNIX)
	add_definitions(-Dunix)
endif(UNIX)


add_subdirectory(c)
add_subdirectory(cpp)


# ############################## end of file ############################# #

