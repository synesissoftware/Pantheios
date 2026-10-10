
set(BE_WINDOWSDEBUGGER_SRC_DIR ../../../src/backends/be)

file(GLOB BE_WINDOWSDEBUGGER_SRCS
	${BE_WINDOWSDEBUGGER_SRC_DIR}/be.WindowsDebugger.c
)

add_library(Pantheios.be.WindowsDebugger
	${BE_WINDOWSDEBUGGER_SRCS}
)

target_link_STLSoft(Pantheios.be.WindowsDebugger)

define_target_compile_options(Pantheios.be.WindowsDebugger)

install(TARGETS Pantheios.be.WindowsDebugger
	EXPORT project-targets
)


# ############################## end of file ############################# #

