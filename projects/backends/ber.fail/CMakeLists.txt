
set(BER_FAIL_SRC_DIR ../../../src/backends)

file(GLOB BER_FAIL_SRCS
	${BER_FAIL_SRC_DIR}/ber/ber.fail.c
)

add_library(Pantheios.ber.fail
	${BER_FAIL_SRCS}
)

target_link_STLSoft(Pantheios.ber.fail)

define_target_compile_options(Pantheios.ber.fail)

install(TARGETS Pantheios.ber.fail
	EXPORT project-targets
)


# ############################## end of fail ############################# #

