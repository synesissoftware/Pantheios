
set(BEC_COMERROROBJECT_SRC_DIR ../../../src/backends)

file(GLOB BEC_COMERROROBJECT_SRCS
	${BEC_COMERROROBJECT_SRC_DIR}/bec.COMErrorObject.cpp
)

add_library(Pantheios.bec.COMErrorObject
	${BEC_COMERROROBJECT_SRCS}
)

target_link_STLSoft(Pantheios.bec.COMErrorObject)

define_target_compile_options(Pantheios.bec.COMErrorObject)

install(TARGETS Pantheios.bec.COMErrorObject
	EXPORT project-targets
)

install_file(backends bec.COMErrorObject.h)


# ############################## end of file ############################# #

