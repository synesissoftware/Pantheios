
set(BEC_ZMQ_SRC_DIR ../../../src/backends)

file(GLOB BEC_ZMQ_SRCS
	${BEC_ZMQ_SRC_DIR}/bec.zmq.cpp
)

add_library(Pantheios.bec.zmq
	${BEC_ZMQ_SRCS}
)

target_link_STLSoft(Pantheios.bec.zmq)

target_link_ZeroMQ(Pantheios.bec.zmq)

list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED unused-parameter)
list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED unused-private-field)
define_target_compile_options(Pantheios.bec.zmq)

install(TARGETS Pantheios.bec.zmq
	EXPORT project-targets
)

install_file(backends bec.zmq.h)


# ############################## end of file ############################# #
