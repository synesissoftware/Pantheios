
set(BEL_SYSLOG_SRC_DIR ../../../src/backends)

file(GLOB BEL_SYSLOG_SRCS
    ${BEL_SYSLOG_SRC_DIR}/bel/bel.syslog.c
)

add_library(Pantheios.bel.syslog
    ${BEL_SYSLOG_SRCS}
)

target_compile_options(Pantheios.bel.syslog PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

install(TARGETS Pantheios.bel.syslog)


# ############################## end of syslog ############################# #

