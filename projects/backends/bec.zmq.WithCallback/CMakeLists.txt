
set(BEC_ZMQ_SRC_DIR ../../../src/backends)

file(GLOB BEC_ZMQ_SRCS
	${BEC_ZMQ_SRC_DIR}/bec.zmq.cpp
)

add_library(Pantheios.bec.zmq.WithCallback
	${BEC_ZMQ_SRCS}
)

target_link_STLSoft(Pantheios.bec.zmq.WithCallback)

target_link_ZeroMQ(Pantheios.bec.zmq.WithCallback)

list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED unused-parameter)
list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED unused-private-field)

target_compile_options(Pantheios.bec.zmq.WithCallback
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-DPANTHEIOS_BE_USE_CALLBACK
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4

			-DPANTHEIOS_BE_USE_CALLBACK
		>
)

install(TARGETS Pantheios.bec.zmq.WithCallback
	EXPORT project-targets
)


# ############################## end of file ############################# #
