
set(BEC_NULL_SRC_DIR ../../../src/backends)

file(GLOB BEC_NULL_SRCS
	${BEC_NULL_SRC_DIR}/bec.null.c
)

add_library(Pantheios.bec.null
	${BEC_NULL_SRCS}
)

target_link_STLSoft(Pantheios.bec.null)

define_target_compile_options(Pantheios.bec.null)

install(TARGETS Pantheios.bec.null
	EXPORT project-targets
)

install_file(backends bec.null.h)


# ############################## end of file ############################# #

