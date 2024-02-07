
add_executable(test.unit.inserter.integer
    test.unit.inserter.integer.cpp
)

target_link_libraries(test.unit.inserter.integer
    Pantheios.util
    Pantheios.core
)

target_link_libraries(test.unit.inserter.integer
    xTests::xTests.core
)

target_compile_options(test.unit.inserter.integer PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

