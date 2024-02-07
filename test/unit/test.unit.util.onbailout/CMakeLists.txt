
add_executable(test.unit.util.onbailout
    test.unit.util.onbailout.cpp
)

target_link_libraries(test.unit.util.onbailout
    Pantheios.util
)

target_link_libraries(test.unit.util.onbailout
    shwild::shwild.core
    xTests::xTests.core
)

target_compile_options(test.unit.util.onbailout PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-unused-but-set-parameter
        -Wno-unused-parameter
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

