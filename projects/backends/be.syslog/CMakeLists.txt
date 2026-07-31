
set(BE_SYSLOG_SRC_DIR ../../../src/backends)

file(GLOB BE_SYSLOG_SRCS
	${BE_SYSLOG_SRC_DIR}/be/be.syslog.c
)

add_library(Pantheios.be.syslog
	${BE_SYSLOG_SRCS}
)

target_link_STLSoft(Pantheios.be.syslog)

define_target_compile_options(Pantheios.be.syslog)

install(TARGETS Pantheios.be.syslog
	EXPORT project-targets
)


# ############################## end of file ############################# #

