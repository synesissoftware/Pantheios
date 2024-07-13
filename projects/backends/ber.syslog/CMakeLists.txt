
set(BER_SYSLOG_SRC_DIR ../../../src/backends)

file(GLOB BER_SYSLOG_SRCS
	${BER_SYSLOG_SRC_DIR}/ber/ber.syslog.c
)

add_library(Pantheios.ber.syslog
	${BER_SYSLOG_SRCS}
)

target_compile_options(Pantheios.ber.syslog PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

install(TARGETS Pantheios.ber.syslog)


# ############################## end of syslog ############################# #

