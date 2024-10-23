
set(BE_FPRINTF_SRC_DIR ../../../src/backends)

file(GLOB BE_FPRINTF_SRCS
	${BE_FPRINTF_SRC_DIR}/be/be.fprintf.c
)

add_library(Pantheios.be.fprintf
	${BE_FPRINTF_SRCS}
)

target_link_STLSoft(Pantheios.be.fprintf)

define_target_compile_options(Pantheios.be.fprintf)

install(TARGETS Pantheios.be.fprintf
	EXPORT project-targets
)


# ############################## end of file ############################# #

