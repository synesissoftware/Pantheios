
set(BE_WINDOWSMESSAGEBOX_SRC_DIR ../../../src/backends/be)

file(GLOB BE_WINDOWSMESSAGEBOX_SRCS
	${BE_WINDOWSMESSAGEBOX_SRC_DIR}/be.WindowsMessageBox.c
)

add_library(Pantheios.be.WindowsMessageBox
	${BE_WINDOWSMESSAGEBOX_SRCS}
)

target_link_STLSoft(Pantheios.be.WindowsMessageBox)

define_target_compile_options(Pantheios.be.WindowsMessageBox)

install(TARGETS Pantheios.be.WindowsMessageBox
	EXPORT project-targets
)


# ############################## end of file ############################# #

