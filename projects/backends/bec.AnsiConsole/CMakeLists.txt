
set(BEC_ANSICONSOLE_SRC_DIR ../../../src/backends)

file(GLOB BEC_ANSICONSOLE_SRCS
	${BEC_ANSICONSOLE_SRC_DIR}/bec.AnsiConsole.cpp
)

add_library(Pantheios.bec.AnsiConsole
	${BEC_ANSICONSOLE_SRCS}
)

target_link_STLSoft(Pantheios.bec.AnsiConsole)

list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED unused-parameter)
define_target_compile_options(Pantheios.bec.AnsiConsole)

install(TARGETS Pantheios.bec.AnsiConsole
	EXPORT project-targets
)

install_file(backends bec.AnsiConsole.h)


# ############################## end of file ############################# #

