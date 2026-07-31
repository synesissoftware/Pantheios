
set(BEL_TEST_SRC_DIR ../../../src/backends)

file(GLOB BEL_TEST_SRCS
	${BEL_TEST_SRC_DIR}/bel/bel.test.c
)

add_library(Pantheios.bel.test
	${BEL_TEST_SRCS}
)

target_link_STLSoft(Pantheios.bel.test)

define_target_compile_options(Pantheios.bel.test)

install(TARGETS Pantheios.bel.test
	EXPORT project-targets
)


# ############################## end of test ############################# #

