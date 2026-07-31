
set(BE_NULL_SRC_DIR ../../../src/backends)

file(GLOB BE_NULL_SRCS
	${BE_NULL_SRC_DIR}/be/be.null.c
)

add_library(Pantheios.be.null
	${BE_NULL_SRCS}
)

target_link_STLSoft(Pantheios.be.null)

define_target_compile_options(Pantheios.be.null)

install(TARGETS Pantheios.be.null
	EXPORT project-targets
)


# ############################## end of file ############################# #

