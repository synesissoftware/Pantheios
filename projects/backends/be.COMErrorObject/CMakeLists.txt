
set(BE_COMERROROBJECT_SRC_DIR ../../../src/backends/be)

file(GLOB BE_COMERROROBJECT_SRCS
	${BE_COMERROROBJECT_SRC_DIR}/be.COMErrorObject.c
)

add_library(Pantheios.be.COMErrorObject
	${BE_COMERROROBJECT_SRCS}
)

target_link_STLSoft(Pantheios.be.COMErrorObject)

define_target_compile_options(Pantheios.be.COMErrorObject)

install(TARGETS Pantheios.be.COMErrorObject
	EXPORT project-targets
)


# ############################## end of file ############################# #

