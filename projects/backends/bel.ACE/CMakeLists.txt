
set(BEL_ACE_SRC_DIR ../../../src/backends)

file(GLOB BEL_ACE_SRCS
	${BEL_ACE_SRC_DIR}/bel/bel.ACE.c
)

add_library(Pantheios.bel.ACE
	${BEL_ACE_SRCS}
)

target_link_STLSoft(Pantheios.bel.ACE)

define_target_compile_options(Pantheios.bel.ACE)

install(TARGETS Pantheios.bel.ACE
	EXPORT project-targets
)


# ############################## end of file ############################# #
