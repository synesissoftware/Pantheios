
set(BEC_WINDOWSMESSAGEBOX_SRC_DIR ../../../src/backends)

file(GLOB BEC_WINDOWSMESSAGEBOX_SRCS
	${BEC_WINDOWSMESSAGEBOX_SRC_DIR}/bec.WindowsMessageBox.cpp
)

add_library(Pantheios.bec.WindowsMessageBox
	${BEC_WINDOWSMESSAGEBOX_SRCS}
)

target_link_STLSoft(Pantheios.bec.WindowsMessageBox)

define_target_compile_options(Pantheios.bec.WindowsMessageBox)

install(TARGETS Pantheios.bec.WindowsMessageBox
	EXPORT project-targets
)

install_file(backends bec.WindowsMessageBox.h)


# ############################## end of file ############################# #

