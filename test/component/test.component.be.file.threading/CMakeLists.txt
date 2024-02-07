
add_executable(test.component.be.file.threading
    test.component.be.file.threading.cpp
)

target_link_libraries(test.component.be.file.threading
    Pantheios.util
    Pantheios.core
)

target_link_libraries(test.component.be.file.threading
    Pantheios.fe.N
)

target_link_libraries(test.component.be.file.threading
    Pantheios.be.N
    Pantheios.bec.file
    Pantheios.bec.fprintf
)

target_link_libraries(test.component.be.file.threading
    xTests::xTests.core
)

target_compile_options(test.component.be.file.threading PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-missing-field-initializers
        -Wno-null-pointer-arithmetic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)


# ############################## end of file ############################# #

