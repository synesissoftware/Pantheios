
include_directories(${CMAKE_SOURCE_DIR}/include)

if(APPLE)

	message("-- -- adding '/usr/local/include' to include-directories for 'examples'")

	include_directories("/usr/local/include")

	include_directories("/usr/local/lib")
endif(APPLE)


if(WIN32)

	if(CMAKE_SIZEOF_VOID_P EQUAL 8)

		message (STATUS "Compiling for 64-bit Windows")

		add_definitions(-DWIN64)
	else()

		message (STATUS "Compiling for 32-bit Windows")

		add_definitions(-DWIN32)
	endif()
endif(WIN32)

if(UNIX)

	add_definitions(-DUNIX)
	add_definitions(-Dunix)
endif(UNIX)


add_subdirectory(c)
add_subdirectory(cpp)


# ############################## end of file ############################# #

