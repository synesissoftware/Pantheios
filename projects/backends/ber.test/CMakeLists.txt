
set(BER_TEST_SRC_DIR ../../../src/backends)

file(GLOB BER_TEST_SRCS
	${BER_TEST_SRC_DIR}/ber/ber.test.c
)

add_library(Pantheios.ber.test
	${BER_TEST_SRCS}
)

target_link_STLSoft(Pantheios.ber.test)

define_target_compile_options(Pantheios.ber.test)

install(TARGETS Pantheios.ber.test
	EXPORT project-targets
)


# ############################## end of test ############################# #

