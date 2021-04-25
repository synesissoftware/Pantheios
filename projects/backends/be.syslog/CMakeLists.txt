
set(BE_SYSLOG_SRC_DIR ../../../src/backends)

file(GLOB BE_SYSLOG_SRCS
	${BE_SYSLOG_SRC_DIR}/be/be.syslog.c
)

add_library(pantheios_be_syslog
	${BE_SYSLOG_SRCS}
)

target_compile_options(pantheios_be_syslog PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
		#-Wno-missing-braces
		#-Wno-missing-field-initializers
		#-Wno-unused-parameter
		#-Wno-unused-value
    >
    $<$<CXX_COMPILER_ID:MSVC>:
	    /WX /W4
	>
)

install(TARGETS pantheios_be_syslog)


