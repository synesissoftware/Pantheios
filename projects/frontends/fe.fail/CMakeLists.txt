
set(FE_FAIL_SRC_DIR ../../../src/frontends)

file(GLOB FE_FAIL_SRCS
	${FE_FAIL_SRC_DIR}/fe.fail.c
)

add_library(Pantheios.fe.fail
	${FE_FAIL_SRCS}
)

target_link_STLSoft(Pantheios.fe.fail)

define_target_compile_options(Pantheios.fe.fail)

install(TARGETS Pantheios.fe.fail
	EXPORT project-targets
)

install_file(frontends fe.fail.h)


# ############################## end of file ############################# #

