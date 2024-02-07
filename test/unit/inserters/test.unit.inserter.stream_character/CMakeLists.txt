
add_executable(test.unit.inserter.stream_character
    test.unit.inserter.stream_character.cpp
)

target_link_libraries(test.unit.inserter.stream_character
    Pantheios.util
    Pantheios.core
)

target_link_libraries(test.unit.inserter.stream_character
    xTests::xTests.core
)

target_compile_options(test.unit.inserter.stream_character PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

