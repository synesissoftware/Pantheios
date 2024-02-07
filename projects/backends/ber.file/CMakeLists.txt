
set(BER_FILE_SRC_DIR ../../../src/backends)

file(GLOB BER_FILE_SRCS
    ${BER_FILE_SRC_DIR}/ber/ber.file.c
)

add_library(Pantheios.ber.file
    ${BER_FILE_SRCS}
)

target_compile_options(Pantheios.ber.file PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

install(TARGETS Pantheios.ber.file)


# ############################## end of file ############################# #

