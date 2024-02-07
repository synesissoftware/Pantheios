
add_executable(example.cpp.backends.file.callback
    example.cpp.backends.file.callback.cpp
)

target_link_libraries(example.cpp.backends.file.callback
    Pantheios.util
    Pantheios.core
)

target_link_libraries(example.cpp.backends.file.callback
    Pantheios.fe.simple
)

target_link_libraries(example.cpp.backends.file.callback
    Pantheios.be.file
    Pantheios.bec.file.WithCallback
)

target_compile_options(example.cpp.backends.file.callback PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

