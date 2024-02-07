
set(FE_ALL_SRC_DIR ../../../src/frontends)

file(GLOB FE_ALL_SRCS
    ${FE_ALL_SRC_DIR}/fe.all.c
)

add_library(Pantheios.fe.all
    ${FE_ALL_SRCS}
)

target_compile_options(Pantheios.fe.all PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

install(TARGETS Pantheios.fe.all)


# ############################## end of file ############################# #

