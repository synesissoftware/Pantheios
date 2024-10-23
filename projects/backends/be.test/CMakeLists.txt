
set(BE_TEST_SRC_DIR ../../../src/backends/be)

file(GLOB BE_TEST_SRCS
	${BE_TEST_SRC_DIR}/be.test.c
)

add_library(Pantheios.be.test
	${BE_TEST_SRCS}
)

target_link_STLSoft(Pantheios.be.test)

define_target_compile_options(Pantheios.be.test)

install(TARGETS Pantheios.be.test
	EXPORT project-targets
)


# ############################## end of file ############################# #

