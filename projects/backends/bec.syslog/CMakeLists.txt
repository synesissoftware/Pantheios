
set(BEC_SYSLOG_SRC_DIR ../../../src/backends)

file(GLOB BEC_SYSLOG_SRCS
	${BEC_SYSLOG_SRC_DIR}/bec.syslog.c
)

add_library(Pantheios.bec.syslog
	${BEC_SYSLOG_SRCS}
)

target_link_STLSoft(Pantheios.bec.syslog)

define_target_compile_options(Pantheios.bec.syslog)

install(TARGETS Pantheios.bec.syslog
	EXPORT project-targets
)

install_file(backends bec.syslog.h)


# ############################## end of file ############################# #

