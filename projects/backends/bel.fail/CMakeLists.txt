
set(BEL_FAIL_SRC_DIR ../../../src/backends)

file(GLOB BEL_FAIL_SRCS
	${BEL_FAIL_SRC_DIR}/bel/bel.fail.c
)

add_library(Pantheios.bel.fail
	${BEL_FAIL_SRCS}
)

target_link_STLSoft(Pantheios.bel.fail)

define_target_compile_options(Pantheios.bel.fail)

install(TARGETS Pantheios.bel.fail
	EXPORT project-targets
)


# ############################## end of fail ############################# #

