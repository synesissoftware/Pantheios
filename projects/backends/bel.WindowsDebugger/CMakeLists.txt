
set(BEL_WINDOWSDEBUGGER_SRC_DIR ../../../src/backends/bel)

file(GLOB BEL_WINDOWSDEBUGGER_SRCS
	${BEL_WINDOWSDEBUGGER_SRC_DIR}/bel.WindowsDebugger.c
)

add_library(Pantheios.bel.WindowsDebugger
	${BEL_WINDOWSDEBUGGER_SRCS}
)

target_link_STLSoft(Pantheios.bel.WindowsDebugger)

define_target_compile_options(Pantheios.bel.WindowsDebugger)

install(TARGETS Pantheios.bel.WindowsDebugger
	EXPORT project-targets
)


# ############################## end of file ############################# #

