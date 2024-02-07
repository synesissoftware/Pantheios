
add_executable(test.unit.fe.all
    test.unit.fe.all.c
)

target_link_libraries(test.unit.fe.all
    Pantheios.util
)

target_link_libraries(test.unit.fe.all
    Pantheios.fe.all
)

target_link_libraries(test.unit.fe.all
    xTests::xTests.core
)

target_compile_options(test.unit.fe.all PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

