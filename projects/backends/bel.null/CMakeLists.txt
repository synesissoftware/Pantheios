
set(BEL_NULL_SRC_DIR ../../../src/backends)

file(GLOB BEL_NULL_SRCS
	${BEL_NULL_SRC_DIR}/bel/bel.null.c
)

add_library(Pantheios.bel.null
	${BEL_NULL_SRCS}
)

target_link_STLSoft(Pantheios.bel.null)

define_target_compile_options(Pantheios.bel.null)

install(TARGETS Pantheios.bel.null
	EXPORT project-targets
)


# ############################## end of null ############################# #

