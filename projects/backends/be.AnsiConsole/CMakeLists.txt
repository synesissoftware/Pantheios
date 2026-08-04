
set(BE_XXXX_SRC_DIR ../../../src/backends/be)

file(GLOB BE_XXXX_SRCS
	${BE_XXXX_SRC_DIR}/be.AnsiConsole.c
)

add_library(Pantheios.be.AnsiConsole
	${BE_XXXX_SRCS}
)

target_link_STLSoft(Pantheios.be.AnsiConsole)

define_target_compile_options(Pantheios.be.AnsiConsole)

install(TARGETS Pantheios.be.AnsiConsole
	EXPORT project-targets
)


# ############################## end of file ############################# #

