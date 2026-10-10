
set(BEC_WINDOWSEVENTLOG_SRC_DIR ../../../src/backends)

file(GLOB BEC_WINDOWSEVENTLOG_SRCS
	${BEC_WINDOWSEVENTLOG_SRC_DIR}/bec.WindowsEventLog.cpp
)

add_library(Pantheios.bec.WindowsEventLog
	${BEC_WINDOWSEVENTLOG_SRCS}
)

target_link_STLSoft(Pantheios.bec.WindowsEventLog)

define_target_compile_options(Pantheios.bec.WindowsEventLog)

install(TARGETS Pantheios.bec.WindowsEventLog
	EXPORT project-targets
)

install_file(backends bec.WindowsEventLog.h)


# ############################## end of file ############################# #

