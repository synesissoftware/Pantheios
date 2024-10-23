
set(BEC_LOADER_SRC_DIR ../../../src/backends)

file(GLOB BEC_LOADER_SRCS
	${BEC_LOADER_SRC_DIR}/bec.loader.cpp
)

add_library(Pantheios.bec.loader
	${BEC_LOADER_SRCS}
)

define_target_compile_options(Pantheios.bec.loader)

install(TARGETS Pantheios.bec.loader)


# ############################## end of file ############################# #

