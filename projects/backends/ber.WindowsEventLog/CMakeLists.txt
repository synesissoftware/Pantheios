
set(BER_WINDOWSEVENTLOG_SRC_DIR ../../../src/backends/ber)

file(GLOB BER_WINDOWSEVENTLOG_SRCS
	${BER_WINDOWSEVENTLOG_SRC_DIR}/ber.WindowsEventLog.c
)

add_library(Pantheios.ber.WindowsEventLog
	${BER_WINDOWSEVENTLOG_SRCS}
)

target_link_STLSoft(Pantheios.ber.WindowsEventLog)

define_target_compile_options(Pantheios.ber.WindowsEventLog)

install(TARGETS Pantheios.ber.WindowsEventLog
	EXPORT project-targets
)


# ############################## end of file ############################# #

