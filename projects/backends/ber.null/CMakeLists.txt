
set(BER_NULL_SRC_DIR ../../../src/backends)

file(GLOB BER_NULL_SRCS
	${BER_NULL_SRC_DIR}/ber/ber.null.c
)

add_library(Pantheios.ber.null
	${BER_NULL_SRCS}
)

target_link_STLSoft(Pantheios.ber.null)

define_target_compile_options(Pantheios.ber.null)

install(TARGETS Pantheios.ber.null
	EXPORT project-targets
)


# ############################## end of null ############################# #

