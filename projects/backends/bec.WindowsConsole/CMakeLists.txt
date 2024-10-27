
set(BEC_WINDOWSCONSOLE_SRC_DIR ../../../src/backends)

file(GLOB BEC_WINDOWSCONSOLE_SRCS
	${BEC_WINDOWSCONSOLE_SRC_DIR}/bec.WindowsConsole.cpp
)

add_library(Pantheios.bec.WindowsConsole
	${BEC_WINDOWSCONSOLE_SRCS}
)

target_link_STLSoft(Pantheios.bec.WindowsConsole)

list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED unused-function)
define_target_compile_options(Pantheios.bec.WindowsConsole)

install(TARGETS Pantheios.bec.WindowsConsole
	EXPORT project-targets
)

install_file(backends bec.WindowsConsole.h)


# ############################## end of file ############################# #

