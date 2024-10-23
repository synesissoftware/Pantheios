
set(BER_SYSLOG_SRC_DIR ../../../src/backends)

file(GLOB BER_SYSLOG_SRCS
	${BER_SYSLOG_SRC_DIR}/ber/ber.syslog.c
)

add_library(Pantheios.ber.syslog
	${BER_SYSLOG_SRCS}
)

target_link_STLSoft(Pantheios.ber.syslog)

define_target_compile_options(Pantheios.ber.syslog)

install(TARGETS Pantheios.ber.syslog
	EXPORT project-targets
)


# ############################## end of syslog ############################# #

