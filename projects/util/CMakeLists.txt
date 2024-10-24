
set(UTIL_SRC_DIR ../../src/util)

file(GLOB UTIL_SRCS
	${UTIL_SRC_DIR}/*.c
	${UTIL_SRC_DIR}/*.cpp
)

add_library(Pantheios.util
	${UTIL_SRCS}
)

target_include_directories(Pantheios.util
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

target_link_STLSoft(Pantheios.util)

define_target_compile_options(Pantheios.util)

install(TARGETS Pantheios.util
	EXPORT project-targets
)

install(
	DIRECTORY ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/util/
	DESTINATION include/${PROJECT_NAME_LOWER}/util/
	FILES_MATCHING
	PATTERN "*.h*"
)


# ############################## end of file ############################# #

