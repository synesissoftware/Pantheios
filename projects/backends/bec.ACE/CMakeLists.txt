
set(BEC_ACE_SRC_DIR ../../../src/backends)

file(GLOB BEC_ACE_SRCS
	${BEC_ACE_SRC_DIR}/bec.ACE.cpp
)

add_library(Pantheios.bec.ACE
	${BEC_ACE_SRCS}
)

target_link_STLSoft(Pantheios.bec.ACE)

target_link_ACE(Pantheios.bec.ACE)

define_target_compile_options(Pantheios.bec.ACE)

install(TARGETS Pantheios.bec.ACE
	EXPORT project-targets
)

install_file(backends bec.ACE.h)


# ############################## end of file ############################# #
