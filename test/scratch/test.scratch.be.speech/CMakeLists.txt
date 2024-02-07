
add_executable(test.scratch.be.speech
    test.scratch.be.speech.cpp
)

target_link_libraries(test.scratch.be.speech
    Pantheios.util
    Pantheios.core
)

target_link_libraries(test.scratch.be.speech
    Pantheios.fe.simple
)

target_link_libraries(test.scratch.be.speech
    Pantheios.be.speech
    Pantheios.bec.speech
)

target_compile_options(test.scratch.be.speech PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-null-pointer-arithmetic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

