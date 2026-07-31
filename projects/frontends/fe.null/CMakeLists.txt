
set(FE_NULL_SRC_DIR ../../../src/frontends)

file(GLOB FE_NULL_SRCS
	${FE_NULL_SRC_DIR}/fe.null.c
)

add_library(Pantheios.fe.null
	${FE_NULL_SRCS}
)

target_link_STLSoft(Pantheios.fe.null)

define_target_compile_options(Pantheios.fe.null)

install(TARGETS Pantheios.fe.null
	EXPORT project-targets
)

install_file(frontends fe.null.h)


# ############################## end of file ############################# #

