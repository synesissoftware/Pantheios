
set(BEC_SYSLOG_SRC_DIR ../../../src/backends)

file(GLOB BEC_SYSLOG_SRCS
	${BEC_SYSLOG_SRC_DIR}/bec.syslog.c
)

add_library(Pantheios.bec.syslog
	${BEC_SYSLOG_SRCS}
)

target_link_STLSoft(Pantheios.bec.syslog)

target_compile_options(Pantheios.bec.syslog
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-Wno-unused-parameter
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4
		>
)

install(TARGETS Pantheios.bec.syslog)


# ############################## end of file ############################# #

