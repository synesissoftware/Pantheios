
set(BE_FILE_SRC_DIR ../../../src/backends)

file(GLOB BE_FILE_SRCS
	${BE_FILE_SRC_DIR}/be/be.file.c
)

add_library(Pantheios.be.file
	${BE_FILE_SRCS}
)

target_link_STLSoft(Pantheios.be.file)

define_target_compile_options(Pantheios.be.file)

install(TARGETS Pantheios.be.file
	EXPORT project-targets
)


# ############################## end of file ############################# #

