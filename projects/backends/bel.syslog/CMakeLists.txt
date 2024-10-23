
set(BEL_SYSLOG_SRC_DIR ../../../src/backends)

file(GLOB BEL_SYSLOG_SRCS
	${BEL_SYSLOG_SRC_DIR}/bel/bel.syslog.c
)

add_library(Pantheios.bel.syslog
	${BEL_SYSLOG_SRCS}
)

target_link_STLSoft(Pantheios.bel.syslog)

define_target_compile_options(Pantheios.bel.syslog)

install(TARGETS Pantheios.bel.syslog
	EXPORT project-targets
)


# ############################## end of syslog ############################# #

