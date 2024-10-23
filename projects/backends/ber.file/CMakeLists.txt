
set(BER_FILE_SRC_DIR ../../../src/backends)

file(GLOB BER_FILE_SRCS
	${BER_FILE_SRC_DIR}/ber/ber.file.c
)

add_library(Pantheios.ber.file
	${BER_FILE_SRCS}
)

target_link_STLSoft(Pantheios.ber.file)

define_target_compile_options(Pantheios.ber.file)

install(TARGETS Pantheios.ber.file
	EXPORT project-targets
)


# ############################## end of file ############################# #

