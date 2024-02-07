
add_executable(example.cpp.backends.mx.1
    example.cpp.backends.mx.1.cpp
)

target_link_libraries(example.cpp.backends.mx.1
    Pantheios.util
    Pantheios.core
)

target_link_libraries(example.cpp.backends.mx.1
    Pantheios.fe.simple
)

target_link_libraries(example.cpp.backends.mx.1
    Pantheios.be.N
)

if (UNIX)

    target_link_libraries(example.cpp.backends.mx.1
        Pantheios.bec.fprintf
        Pantheios.bec.syslog
    )
endif (UNIX)

if (WIN32)

    target_link_libraries(example.cpp.backends.mx.1
        Pantheios.bec.WindowsConsole
        Pantheios.bec.WindowsSyslog
    )
endif (WIN32)

target_compile_options(example.cpp.backends.mx.1 PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

