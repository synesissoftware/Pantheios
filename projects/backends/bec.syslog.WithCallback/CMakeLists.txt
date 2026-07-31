
set(BEC_SYSLOG_SRC_DIR ../../../src/backends)

file(GLOB BEC_SYSLOG_SRCS
	${BEC_SYSLOG_SRC_DIR}/bec.syslog.c
)

add_library(Pantheios.bec.syslog.WithCallback
	${BEC_SYSLOG_SRCS}
)

target_link_STLSoft(Pantheios.bec.syslog.WithCallback)

target_compile_options(Pantheios.bec.syslog.WithCallback
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-DPANTHEIOS_BE_USE_CALLBACK
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4

			-DPANTHEIOS_BE_USE_CALLBACK
		>
)

install(TARGETS Pantheios.bec.syslog.WithCallback
	EXPORT project-targets
)


# ############################## end of file ############################# #

