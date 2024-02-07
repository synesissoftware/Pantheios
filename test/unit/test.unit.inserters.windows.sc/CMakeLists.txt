
add_executable(test.unit.inserters.windows.sc
    test.unit.inserters.windows.sc.cpp
)

target_link_libraries(test.unit.inserters.windows.sc
    Pantheios.util
    Pantheios.core
)

target_link_libraries(test.unit.inserters.windows.sc
    Pantheios.fe.null
)

target_link_libraries(test.unit.inserters.windows.sc
    Pantheios.be.null
    Pantheios.bec.null
)

target_link_libraries(test.unit.inserters.windows.sc
    xTests::xTests.core
)

target_compile_options(test.unit.inserters.windows.sc PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-null-pointer-arithmetic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

