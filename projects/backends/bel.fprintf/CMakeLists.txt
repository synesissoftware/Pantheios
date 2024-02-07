
set(BEL_FPRINTF_SRC_DIR ../../../src/backends)

file(GLOB BEL_FPRINTF_SRCS
    ${BEL_FPRINTF_SRC_DIR}/bel/bel.fprintf.c
)

add_library(Pantheios.bel.fprintf
    ${BEL_FPRINTF_SRCS}
)

target_compile_options(Pantheios.bel.fprintf PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

install(TARGETS Pantheios.bel.fprintf)


# ############################## end of fprintf ############################# #

