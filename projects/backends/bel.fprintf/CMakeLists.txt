
set(BEL_FPRINTF_SRC_DIR ../../../src/backends)

file(GLOB BEL_FPRINTF_SRCS
	${BEL_FPRINTF_SRC_DIR}/bel/bel.fprintf.c
)

add_library(Pantheios.bel.fprintf
	${BEL_FPRINTF_SRCS}
)

target_link_STLSoft(Pantheios.bel.fprintf)

define_target_compile_options(Pantheios.bel.fprintf)

install(TARGETS Pantheios.bel.fprintf
	EXPORT project-targets
)


# ############################## end of fprintf ############################# #

