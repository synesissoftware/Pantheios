
set(BE_SYSLOG_SRC_DIR ../../../src/backends)

file(GLOB BE_SYSLOG_SRCS
    ${BE_SYSLOG_SRC_DIR}/be/be.syslog.c
)

add_library(Pantheios.be.syslog
    ${BE_SYSLOG_SRCS}
)

target_compile_options(Pantheios.be.syslog PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

install(TARGETS Pantheios.be.syslog)


# ############################## end of file ############################# #

