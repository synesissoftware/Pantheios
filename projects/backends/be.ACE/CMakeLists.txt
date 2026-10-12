
set(BE_ACE_SRC_DIR ../../../src/backends)

file(GLOB BE_ACE_SRCS
	${BE_ACE_SRC_DIR}/be/be.ACE.c
)

add_library(Pantheios.be.ACE
	${BE_ACE_SRCS}
)

target_link_STLSoft(Pantheios.be.ACE)

define_target_compile_options(Pantheios.be.ACE)

install(TARGETS Pantheios.be.ACE
	EXPORT project-targets
)


# ############################## end of file ############################# #
