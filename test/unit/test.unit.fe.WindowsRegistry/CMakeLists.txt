
add_executable(test.unit.fe.WindowsRegistry
    test.unit.fe.WindowsRegistry.cpp
)

target_link_libraries(test.unit.fe.WindowsRegistry
    Pantheios.util
)

target_link_libraries(test.unit.fe.WindowsRegistry
    Pantheios.fe.WindowsRegistry
)

target_link_libraries(test.unit.fe.WindowsRegistry
    xTests::xTests.core
)

target_compile_options(test.unit.fe.WindowsRegistry PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

