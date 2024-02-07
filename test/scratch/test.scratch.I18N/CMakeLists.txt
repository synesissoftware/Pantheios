
add_executable(test.scratch.I18N
    test.scratch.I18N.cpp
)

target_link_libraries(test.scratch.I18N
    Pantheios.util
    Pantheios.core
)

target_link_libraries(test.scratch.I18N
    Pantheios.fe.simple
)

target_link_libraries(test.scratch.I18N
    Pantheios.be.fprintf
    Pantheios.bec.fprintf
)

target_compile_options(test.scratch.I18N PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-null-pointer-arithmetic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

