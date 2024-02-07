
add_executable(test.component.inserters.b64
    test.component.inserters.b64.cpp
)

target_link_libraries(test.component.inserters.b64
    Pantheios.util
    Pantheios.core
)

target_link_libraries(test.component.inserters.b64
Pantheios.fe.all
)

target_link_libraries(test.component.inserters.b64
Pantheios.be.test
Pantheios.bec.test
)

target_link_libraries(test.component.inserters.b64
    b64::b64
)

target_link_libraries(test.component.inserters.b64
    xTests::xTests.core
)

target_compile_options(test.component.inserters.b64 PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-null-pointer-arithmetic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

