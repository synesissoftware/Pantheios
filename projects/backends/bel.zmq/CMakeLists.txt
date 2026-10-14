
set(BEL_ZMQ_SRC_DIR ../../../src/backends)

file(GLOB BEL_ZMQ_SRCS
	${BEL_ZMQ_SRC_DIR}/bel/bel.zmq.c
)

add_library(Pantheios.bel.zmq
	${BEL_ZMQ_SRCS}
)

target_link_STLSoft(Pantheios.bel.zmq)

define_target_compile_options(Pantheios.bel.zmq)

install(TARGETS Pantheios.bel.zmq
	EXPORT project-targets
)


# ############################## end of file ############################# #
