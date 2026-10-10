
set(BEL_COMERROROBJECT_SRC_DIR ../../../src/backends/bel)

file(GLOB BEL_COMERROROBJECT_SRCS
	${BEL_COMERROROBJECT_SRC_DIR}/bel.COMErrorObject.c
)

add_library(Pantheios.bel.COMErrorObject
	${BEL_COMERROROBJECT_SRCS}
)

target_link_STLSoft(Pantheios.bel.COMErrorObject)

define_target_compile_options(Pantheios.bel.COMErrorObject)

install(TARGETS Pantheios.bel.COMErrorObject
	EXPORT project-targets
)


# ############################## end of file ############################# #

