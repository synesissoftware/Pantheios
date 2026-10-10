
set(BEL_WINDOWSSYSLOG_SRC_DIR ../../../src/backends/bel)

file(GLOB BEL_WINDOWSSYSLOG_SRCS
	${BEL_WINDOWSSYSLOG_SRC_DIR}/bel.WindowsSyslog.c
)

add_library(Pantheios.bel.WindowsSyslog
	${BEL_WINDOWSSYSLOG_SRCS}
)

target_link_STLSoft(Pantheios.bel.WindowsSyslog)

define_target_compile_options(Pantheios.bel.WindowsSyslog)

install(TARGETS Pantheios.bel.WindowsSyslog
	EXPORT project-targets
)


# ############################## end of file ############################# #

