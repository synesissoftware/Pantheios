
set(BEC_FPRINTF_SRC_DIR ../../../src/backends)

file(GLOB BEC_FPRINTF_SRCS
    ${BEC_FPRINTF_SRC_DIR}/bec.fprintf.cpp
)

add_library(Pantheios.bec.fprintf
    ${BEC_FPRINTF_SRCS}
)

target_compile_options(Pantheios.bec.fprintf PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

install(TARGETS Pantheios.bec.fprintf)


# ############################## end of file ############################# #

