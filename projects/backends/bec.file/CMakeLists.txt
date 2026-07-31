
set(BEC_FILE_SRC_DIR ../../../src/backends)

file(GLOB BEC_FILE_SRCS
	${BEC_FILE_SRC_DIR}/bec.file.cpp
)

add_library(Pantheios.bec.file
	${BEC_FILE_SRCS}
)

target_link_STLSoft(Pantheios.bec.file)

define_target_compile_options(Pantheios.bec.file)

install(TARGETS Pantheios.bec.file
	EXPORT project-targets
)

install_file(backends bec.file.h)


# ############################## end of file ############################# #

