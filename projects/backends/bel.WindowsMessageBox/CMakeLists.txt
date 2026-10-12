
set(BEL_WINDOWSMESSAGEBOX_SRC_DIR ../../../src/backends/bel)

file(GLOB BEL_WINDOWSMESSAGEBOX_SRCS
	${BEL_WINDOWSMESSAGEBOX_SRC_DIR}/bel.WindowsMessageBox.c
)

add_library(Pantheios.bel.WindowsMessageBox
	${BEL_WINDOWSMESSAGEBOX_SRCS}
)

target_link_STLSoft(Pantheios.bel.WindowsMessageBox)

define_target_compile_options(Pantheios.bel.WindowsMessageBox)

install(TARGETS Pantheios.bel.WindowsMessageBox
	EXPORT project-targets
)


# ############################## end of file ############################# #

