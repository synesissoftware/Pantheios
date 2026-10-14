
set(BE_ZMQ_SRC_DIR ../../../src/backends)

file(GLOB BE_ZMQ_SRCS
	${BE_ZMQ_SRC_DIR}/be/be.zmq.c
)

add_library(Pantheios.be.zmq
	${BE_ZMQ_SRCS}
)

target_link_STLSoft(Pantheios.be.zmq)

define_target_compile_options(Pantheios.be.zmq)

install(TARGETS Pantheios.be.zmq
	EXPORT project-targets
)


# ############################## end of file ############################# #
