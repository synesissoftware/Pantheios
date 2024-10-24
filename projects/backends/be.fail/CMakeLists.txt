
set(BE_FAIL_SRC_DIR ../../../src/backends)

file(GLOB BE_FAIL_SRCS
	${BE_FAIL_SRC_DIR}/be/be.fail.c
)

add_library(Pantheios.be.fail
	${BE_FAIL_SRCS}
)

target_link_STLSoft(Pantheios.be.fail)

define_target_compile_options(Pantheios.be.fail)

install(TARGETS Pantheios.be.fail
	EXPORT project-targets
)


# ############################## end of file ############################# #

