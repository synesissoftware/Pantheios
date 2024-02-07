
set(BE_NULL_SRC_DIR ../../../src/backends)

file(GLOB BE_NULL_SRCS
    ${BE_NULL_SRC_DIR}/be/be.null.c
)

add_library(Pantheios.be.null
    ${BE_NULL_SRCS}
)

target_compile_options(Pantheios.be.null PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

install(TARGETS Pantheios.be.null)


