
set(BEC_SYSLOG_SRC_DIR ../../../src/backends)

file(GLOB BEC_SYSLOG_SRCS
	${BEC_SYSLOG_SRC_DIR}/bec.syslog.c
    )

add_library(pantheios_bec_syslog
	${BEC_SYSLOG_SRCS}
	)

target_compile_options(pantheios_bec_syslog PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
    -Werror -Wall -Wextra -pedantic
    #-Wno-missing-braces
    #-Wno-missing-field-initializers
	#-Wno-unused-parameter
    #-Wno-unused-value
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
    )

install(TARGETS pantheios_bec_syslog)


