
set(BEL_FILE_SRC_DIR ../../../src/backends)

file(GLOB BEL_FILE_SRCS
	${BEL_FILE_SRC_DIR}/bel/bel.file.c
)

add_library(Pantheios.bel.file
	${BEL_FILE_SRCS}
)

target_link_STLSoft(Pantheios.bel.file)

define_target_compile_options(Pantheios.bel.file)

install(TARGETS Pantheios.bel.file
	EXPORT project-targets
)


# ############################## end of file ############################# #

