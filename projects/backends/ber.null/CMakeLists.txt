
set(BER_NULL_SRC_DIR ../../../src/backends)

file(GLOB BER_NULL_SRCS
    ${BER_NULL_SRC_DIR}/ber/ber.null.c
)

add_library(Pantheios.ber.null
    ${BER_NULL_SRCS}
)

target_compile_options(Pantheios.ber.null PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

install(TARGETS Pantheios.ber.null)


# ############################## end of null ############################# #

