
add_executable(test.component.custom_severity
    test.component.custom_severity.cpp
)

target_link_libraries(test.component.custom_severity
    Pantheios.util
    Pantheios.core
)

target_link_libraries(test.component.custom_severity
    Pantheios.fe.simple
)

target_link_libraries(test.component.custom_severity
    Pantheios.be.test
    Pantheios.bec.test
)

target_link_libraries(test.component.custom_severity
    xTests::xTests.core
)

target_compile_options(test.component.custom_severity PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-null-pointer-arithmetic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

