
set(UTIL_SRC_DIR ../../src/util)

file(GLOB UTIL_SRCS
    ${UTIL_SRC_DIR}/*.c
    ${UTIL_SRC_DIR}/*.cpp
)

add_library(Pantheios.util ${UTIL_SRCS})

target_compile_options(Pantheios.util PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-deprecated-copy-with-user-provided-copy
        #-Wno-missing-braces
        #-Wno-missing-field-initializers
        -Wno-unused-but-set-parameter
        #-Wno-unused-parameter
        #-Wno-unused-value
    >
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
        -Werror -Wall -Wextra -pedantic

        #-Wno-missing-braces
        #-Wno-missing-field-initializers
        #-Wno-unused-parameter
        #-Wno-unused-value
    >
    $<$<OR:$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        #-Wno-missing-braces
        #-Wno-missing-field-initializers
        #-Wno-unused-parameter
        #-Wno-unused-value
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

install(TARGETS Pantheios.util)


# ############################## end of file ############################# #

