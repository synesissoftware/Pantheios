
set(BEL_ANSICONSOLE_SRC_DIR ../../../src/backends/bel)

file(GLOB BEL_ANSICONSOLE_SRCS
	${BEL_ANSICONSOLE_SRC_DIR}/bel.AnsiConsole.c
)

add_library(Pantheios.bel.AnsiConsole
	${BEL_ANSICONSOLE_SRCS}
)

target_link_STLSoft(Pantheios.bel.AnsiConsole)

define_target_compile_options(Pantheios.bel.AnsiConsole)

install(TARGETS Pantheios.bel.AnsiConsole
	EXPORT project-targets
)


# ############################## end of file ############################# #

