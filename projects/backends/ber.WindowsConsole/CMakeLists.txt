
set(BER_WINDOWSCONSOLE_SRC_DIR ../../../src/backends/ber)

file(GLOB BER_WINDOWSCONSOLE_SRCS
	${BER_WINDOWSCONSOLE_SRC_DIR}/ber.WindowsConsole.c
)

add_library(Pantheios.ber.WindowsConsole
	${BER_WINDOWSCONSOLE_SRCS}
)

target_link_STLSoft(Pantheios.ber.WindowsConsole)

define_target_compile_options(Pantheios.ber.WindowsConsole)

install(TARGETS Pantheios.ber.WindowsConsole
	EXPORT project-targets
)


# ############################## end of file ############################# #

