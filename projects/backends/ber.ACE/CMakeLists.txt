
set(BER_ACE_SRC_DIR ../../../src/backends)

file(GLOB BER_ACE_SRCS
	${BER_ACE_SRC_DIR}/ber/ber.ACE.c
)

add_library(Pantheios.ber.ACE
	${BER_ACE_SRCS}
)

target_link_STLSoft(Pantheios.ber.ACE)

define_target_compile_options(Pantheios.ber.ACE)

install(TARGETS Pantheios.ber.ACE
	EXPORT project-targets
)


# ############################## end of file ############################# #
