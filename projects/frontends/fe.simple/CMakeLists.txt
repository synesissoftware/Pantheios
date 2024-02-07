
set(FE_SIMPLE_SRC_DIR ../../../src/frontends)

file(GLOB FE_SIMPLE_SRCS
    ${FE_SIMPLE_SRC_DIR}/fe.simple.c
)

add_library(Pantheios.fe.simple
    ${FE_SIMPLE_SRCS}
)

target_compile_options(Pantheios.fe.simple PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

install(TARGETS Pantheios.fe.simple)


# ############################## end of file ############################# #

