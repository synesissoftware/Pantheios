
set(BE_WINDOWSSYSLOG_SRC_DIR ../../../src/backends/be)

file(GLOB BE_WINDOWSSYSLOG_SRCS
	${BE_WINDOWSSYSLOG_SRC_DIR}/be.WindowsSyslog.c
)

add_library(Pantheios.be.WindowsSyslog
	${BE_WINDOWSSYSLOG_SRCS}
)

target_link_STLSoft(Pantheios.be.WindowsSyslog)

define_target_compile_options(Pantheios.be.WindowsSyslog)

install(TARGETS Pantheios.be.WindowsSyslog
	EXPORT project-targets
)


# ############################## end of file ############################# #

