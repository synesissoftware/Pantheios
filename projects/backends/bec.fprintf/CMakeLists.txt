
set(BEC_FPRINTF_SRC_DIR ../../../src/backends)

file(GLOB BEC_FPRINTF_SRCS
	${BEC_FPRINTF_SRC_DIR}/bec.fprintf.cpp
)

add_library(Pantheios.bec.fprintf
	${BEC_FPRINTF_SRCS}
)

target_link_STLSoft(Pantheios.bec.fprintf)

define_target_compile_options(Pantheios.bec.fprintf)

install(TARGETS Pantheios.bec.fprintf
	EXPORT project-targets
)

install_file(backends bec.fprintf.h)


# ############################## end of file ############################# #

