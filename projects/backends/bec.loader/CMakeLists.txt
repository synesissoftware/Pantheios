
set(BEC_LOADER_SRC_DIR ../../../src/backends)

file(GLOB BEC_LOADER_SRCS
    ${BEC_LOADER_SRC_DIR}/bec.loader.cpp
)

add_library(Pantheios.bec.loader
    ${BEC_LOADER_SRCS}
)

target_compile_options(Pantheios.bec.loader PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

install(TARGETS Pantheios.bec.loader)


# ############################## end of file ############################# #

