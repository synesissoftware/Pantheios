
set(BEC_WINDOWSSYSLOG_SRC_DIR ../../../src/backends)

file(GLOB BEC_WINDOWSSYSLOG_SRCS
	${BEC_WINDOWSSYSLOG_SRC_DIR}/bec.WindowsSyslog.cpp
)

add_library(Pantheios.bec.WindowsSyslog
	${BEC_WINDOWSSYSLOG_SRCS}
)

target_link_STLSoft(Pantheios.bec.WindowsSyslog)

define_target_compile_options(Pantheios.bec.WindowsSyslog)

install(TARGETS Pantheios.bec.WindowsSyslog
	EXPORT project-targets
)

install_file(backends bec.WindowsSyslog.h)


# ############################## end of file ############################# #

