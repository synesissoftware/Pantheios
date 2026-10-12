
set(BEL_WINDOWSCONSOLE_SRC_DIR ../../../src/backends/bel)

file(GLOB BEL_WINDOWSCONSOLE_SRCS
	${BEL_WINDOWSCONSOLE_SRC_DIR}/bel.WindowsConsole.c
)

add_library(Pantheios.bel.WindowsConsole
	${BEL_WINDOWSCONSOLE_SRCS}
)

target_link_STLSoft(Pantheios.bel.WindowsConsole)

define_target_compile_options(Pantheios.bel.WindowsConsole)

install(TARGETS Pantheios.bel.WindowsConsole
	EXPORT project-targets
)


# ############################## end of file ############################# #

