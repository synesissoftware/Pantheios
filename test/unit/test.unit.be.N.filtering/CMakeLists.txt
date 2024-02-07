
add_executable(test.unit.be.N.filtering
    test.unit.be.N.filtering.c
)

target_link_libraries(test.unit.be.N.filtering
    Pantheios.util
)

target_link_libraries(test.unit.be.N.filtering
    Pantheios.fe.all
)

target_link_libraries(test.unit.be.N.filtering
    Pantheios.be.N
)

target_link_libraries(test.unit.be.N.filtering
    xTests::xTests.core
)

target_compile_options(test.unit.be.N.filtering PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

