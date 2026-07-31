
set(FE_SIMPLE_SRC_DIR ../../../src/frontends)

file(GLOB FE_SIMPLE_SRCS
	${FE_SIMPLE_SRC_DIR}/fe.simple.c
)

add_library(Pantheios.fe.simple
	${FE_SIMPLE_SRCS}
)

target_link_STLSoft(Pantheios.fe.simple)

define_target_compile_options(Pantheios.fe.simple)

install(TARGETS Pantheios.fe.simple
	EXPORT project-targets
)

install_file(frontends fe.simple.h)


# ############################## end of file ############################# #

