
set(BER_ANSICONSOLE_SRC_DIR ../../../src/backends/ber)

file(GLOB BER_ANSICONSOLE_SRCS
	${BER_ANSICONSOLE_SRC_DIR}/ber.AnsiConsole.c
)

add_library(Pantheios.ber.AnsiConsole
	${BER_ANSICONSOLE_SRCS}
)

target_link_STLSoft(Pantheios.ber.AnsiConsole)

define_target_compile_options(Pantheios.ber.AnsiConsole)

install(TARGETS Pantheios.ber.AnsiConsole
	EXPORT project-targets
)


# ############################## end of file ############################# #

