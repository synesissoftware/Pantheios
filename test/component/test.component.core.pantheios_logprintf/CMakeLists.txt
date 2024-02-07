
add_executable(test.component.core.pantheios_logprintf
    test.component.core.pantheios_logprintf.cpp
)

target_link_libraries(test.component.core.pantheios_logprintf
    Pantheios.util
    Pantheios.core
)

target_link_libraries(test.component.core.pantheios_logprintf
    Pantheios.fe.simple
)

target_link_libraries(test.component.core.pantheios_logprintf
    Pantheios.be.test
    Pantheios.bec.test
)

target_link_libraries(test.component.core.pantheios_logprintf
    xTests::xTests.core
)

target_compile_options(test.component.core.pantheios_logprintf PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-null-pointer-arithmetic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

