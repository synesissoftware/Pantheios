
set(BER_ZMQ_SRC_DIR ../../../src/backends)

file(GLOB BER_ZMQ_SRCS
	${BER_ZMQ_SRC_DIR}/ber/ber.zmq.c
)

add_library(Pantheios.ber.zmq
	${BER_ZMQ_SRCS}
)

target_link_STLSoft(Pantheios.ber.zmq)

define_target_compile_options(Pantheios.ber.zmq)

install(TARGETS Pantheios.ber.zmq
	EXPORT project-targets
)


# ############################## end of file ############################# #
