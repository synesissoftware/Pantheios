
set(BEL_WINDOWSEVENTLOG_SRC_DIR ../../../src/backends/bel)

file(GLOB BEL_WINDOWSEVENTLOG_SRCS
	${BEL_WINDOWSEVENTLOG_SRC_DIR}/bel.WindowsEventLog.c
)

add_library(Pantheios.bel.WindowsEventLog
	${BEL_WINDOWSEVENTLOG_SRCS}
)

target_link_STLSoft(Pantheios.bel.WindowsEventLog)

define_target_compile_options(Pantheios.bel.WindowsEventLog)

install(TARGETS Pantheios.bel.WindowsEventLog
	EXPORT project-targets
)


# ############################## end of file ############################# #

