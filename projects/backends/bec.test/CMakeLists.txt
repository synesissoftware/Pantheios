
set(BEC_TEST_SRC_DIR ../../../src/backends)

file(GLOB BEC_TEST_SRCS
	${BEC_TEST_SRC_DIR}/bec.test.cpp
)

add_library(Pantheios.bec.test
	${BEC_TEST_SRCS}
)

target_link_STLSoft(Pantheios.bec.test)

define_target_compile_options(Pantheios.bec.test)

install(TARGETS Pantheios.bec.test
	EXPORT project-targets
)

install_file(backends bec.test.h)


# ############################## end of file ############################# #

