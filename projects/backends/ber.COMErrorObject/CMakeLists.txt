
set(BER_COMERROROBJECT_SRC_DIR ../../../src/backends/ber)

file(GLOB BER_COMERROROBJECT_SRCS
	${BER_COMERROROBJECT_SRC_DIR}/ber.COMErrorObject.c
)

add_library(Pantheios.ber.COMErrorObject
	${BER_COMERROROBJECT_SRCS}
)

target_link_STLSoft(Pantheios.ber.COMErrorObject)

define_target_compile_options(Pantheios.ber.COMErrorObject)

install(TARGETS Pantheios.ber.COMErrorObject
	EXPORT project-targets
)


# ############################## end of file ############################# #

