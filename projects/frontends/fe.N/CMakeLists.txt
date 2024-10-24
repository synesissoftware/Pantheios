
set(FE_N_SRC_DIR ../../../src/frontends)

file(GLOB FE_N_SRCS
	${FE_N_SRC_DIR}/fe.N.c
)

add_library(Pantheios.fe.N
	${FE_N_SRCS}
)

target_link_STLSoft(Pantheios.fe.N)

define_target_compile_options(Pantheios.fe.N)

install(TARGETS Pantheios.fe.N
	EXPORT project-targets
)

install_file(frontends fe.N.h)


# ############################## end of file ############################# #

