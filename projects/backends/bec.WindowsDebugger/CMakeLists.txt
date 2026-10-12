
set(BEC_WINDOWSDEBUGGER_SRC_DIR ../../../src/backends)

file(GLOB BEC_WINDOWSDEBUGGER_SRCS
	${BEC_WINDOWSDEBUGGER_SRC_DIR}/bec.WindowsDebugger.cpp
)

add_library(Pantheios.bec.WindowsDebugger
	${BEC_WINDOWSDEBUGGER_SRCS}
)

target_link_STLSoft(Pantheios.bec.WindowsDebugger)

define_target_compile_options(Pantheios.bec.WindowsDebugger)

install(TARGETS Pantheios.bec.WindowsDebugger
	EXPORT project-targets
)

install_file(backends bec.WindowsDebugger.h)


# ############################## end of file ############################# #

