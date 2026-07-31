
set(BE_N_SRC_DIR ../../../src/backends)

file(GLOB BE_N_SRCS
	${BE_N_SRC_DIR}/be.N.c
)

add_library(Pantheios.be.N
	${BE_N_SRCS}
)

target_link_STLSoft(Pantheios.be.N)

define_target_compile_options(Pantheios.be.N)

install(TARGETS Pantheios.be.N
	EXPORT project-targets
)

install_file("backends" "be.N.h")


# ############################## end of file ############################# #

