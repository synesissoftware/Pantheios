
set(UTIL_SRC_DIR ../../src/util)

file(GLOB UTIL_SRCS
	${UTIL_SRC_DIR}/*.c
	${UTIL_SRC_DIR}/*.cpp
)

add_library(Pantheios.util
	${UTIL_SRCS}
)

target_link_STLSoft(Pantheios.util)

define_target_compile_options(Pantheios.util)

install(TARGETS Pantheios.util
	EXPORT project-targets
)


# ############################## end of file ############################# #

