
set(BER_WINDOWSDEBUGGER_SRC_DIR ../../../src/backends/ber)

file(GLOB BER_WINDOWSDEBUGGER_SRCS
	${BER_WINDOWSDEBUGGER_SRC_DIR}/ber.WindowsDebugger.c
)

add_library(Pantheios.ber.WindowsDebugger
	${BER_WINDOWSDEBUGGER_SRCS}
)

target_link_STLSoft(Pantheios.ber.WindowsDebugger)

define_target_compile_options(Pantheios.ber.WindowsDebugger)

install(TARGETS Pantheios.ber.WindowsDebugger
	EXPORT project-targets
)


# ############################## end of file ############################# #

