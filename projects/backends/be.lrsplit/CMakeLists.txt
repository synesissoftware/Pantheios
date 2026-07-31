
set(BE_LRSPLIT_SRC_DIR ../../../src/backends)

file(GLOB BE_LRSPLIT_SRCS
	${BE_LRSPLIT_SRC_DIR}/be.lrsplit.c
)

add_library(Pantheios.be.lrsplit
	${BE_LRSPLIT_SRCS}
)

target_link_STLSoft(Pantheios.be.lrsplit)

define_target_compile_options(Pantheios.be.lrsplit)

install(TARGETS Pantheios.be.lrsplit
	EXPORT project-targets
)

install_file("backends" "be.lrsplit.h")


# ############################## end of file ############################# #

