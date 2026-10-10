
set(BER_WINDOWSMESSAGEBOX_SRC_DIR ../../../src/backends/ber)

file(GLOB BER_WINDOWSMESSAGEBOX_SRCS
	${BER_WINDOWSMESSAGEBOX_SRC_DIR}/ber.WindowsMessageBox.c
)

add_library(Pantheios.ber.WindowsMessageBox
	${BER_WINDOWSMESSAGEBOX_SRCS}
)

target_link_STLSoft(Pantheios.ber.WindowsMessageBox)

define_target_compile_options(Pantheios.ber.WindowsMessageBox)

install(TARGETS Pantheios.ber.WindowsMessageBox
	EXPORT project-targets
)


# ############################## end of file ############################# #

