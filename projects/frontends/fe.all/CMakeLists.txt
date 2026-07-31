
set(FE_ALL_SRC_DIR ../../../src/frontends)

file(GLOB FE_ALL_SRCS
	${FE_ALL_SRC_DIR}/fe.all.c
)

add_library(Pantheios.fe.all
	${FE_ALL_SRCS}
)

target_link_STLSoft(Pantheios.fe.all)

define_target_compile_options(Pantheios.fe.all)

install(TARGETS Pantheios.fe.all
	EXPORT project-targets
)

install_file(frontends fe.all.h)


# ############################## end of file ############################# #

