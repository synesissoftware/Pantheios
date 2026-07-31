
set(BE_WINDOWSCONSOLE_SRC_DIR ../../../src/backends/be)

file(GLOB BE_WINDOWSCONSOLE_SRCS
	${BE_WINDOWSCONSOLE_SRC_DIR}/be.WindowsConsole.c
)

add_library(Pantheios.be.WindowsConsole
	${BE_WINDOWSCONSOLE_SRCS}
)

target_link_STLSoft(Pantheios.be.WindowsConsole)

define_target_compile_options(Pantheios.be.WindowsConsole)

install(TARGETS Pantheios.be.WindowsConsole
	EXPORT project-targets
)


# ############################## end of file ############################# #

