
set(BE_WINDOWSEVENTLOG_SRC_DIR ../../../src/backends/be)

file(GLOB BE_WINDOWSEVENTLOG_SRCS
	${BE_WINDOWSEVENTLOG_SRC_DIR}/be.WindowsEventLog.c
)

add_library(Pantheios.be.WindowsEventLog
	${BE_WINDOWSEVENTLOG_SRCS}
)

target_link_STLSoft(Pantheios.be.WindowsEventLog)

define_target_compile_options(Pantheios.be.WindowsEventLog)

install(TARGETS Pantheios.be.WindowsEventLog
	EXPORT project-targets
)


# ############################## end of file ############################# #

