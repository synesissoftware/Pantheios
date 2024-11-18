
set(BEC_FAIL_SRC_DIR ../../../src/backends)

file(GLOB BEC_FAIL_SRCS
	${BEC_FAIL_SRC_DIR}/bec.fail.c
)

add_library(Pantheios.bec.fail
	${BEC_FAIL_SRCS}
)

target_link_STLSoft(Pantheios.bec.fail)

define_target_compile_options(Pantheios.bec.fail)

install(TARGETS Pantheios.bec.fail
	EXPORT project-targets
)

install_file(backends bec.fail.h)


# ############################## end of file ############################# #

