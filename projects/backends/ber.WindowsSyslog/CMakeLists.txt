
set(BER_WINDOWSSYSLOG_SRC_DIR ../../../src/backends/ber)

file(GLOB BER_WINDOWSSYSLOG_SRCS
	${BER_WINDOWSSYSLOG_SRC_DIR}/ber.WindowsSyslog.c
)

add_library(Pantheios.ber.WindowsSyslog
	${BER_WINDOWSSYSLOG_SRCS}
)

target_link_STLSoft(Pantheios.ber.WindowsSyslog)

define_target_compile_options(Pantheios.ber.WindowsSyslog)

install(TARGETS Pantheios.ber.WindowsSyslog
	EXPORT project-targets
)


# ############################## end of file ############################# #

