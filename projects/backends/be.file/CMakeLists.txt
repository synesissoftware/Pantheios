
set(BE_FILE_SRC_DIR ../../../src/backends)

file(GLOB BE_FILE_SRCS
    ${BE_FILE_SRC_DIR}/be/be.file.c
)

add_library(Pantheios.be.file
    ${BE_FILE_SRCS}
)

target_compile_options(Pantheios.be.file PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

install(TARGETS Pantheios.be.file)


# ############################## end of file ############################# #

