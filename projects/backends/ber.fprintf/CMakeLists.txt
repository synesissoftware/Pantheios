
set(BER_FPRINTF_SRC_DIR ../../../src/backends)

file(GLOB BER_FPRINTF_SRCS
	${BER_FPRINTF_SRC_DIR}/ber/ber.fprintf.c
)

add_library(Pantheios.ber.fprintf
	${BER_FPRINTF_SRCS}
)

target_link_STLSoft(Pantheios.ber.fprintf)

define_target_compile_options(Pantheios.ber.fprintf)

install(TARGETS Pantheios.ber.fprintf
	EXPORT project-targets
)


# ############################## end of fprintf ############################# #

