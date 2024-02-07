
add_executable(example.cpp.inserter.blob
    example.cpp.inserter.blob.cpp
)

target_link_libraries(example.cpp.inserter.blob
    Pantheios.util
    Pantheios.core
)

target_link_libraries(example.cpp.inserter.blob
    Pantheios.fe.simple
)

if (UNIX)

    target_link_libraries(example.cpp.inserter.blob
        Pantheios.be.fprintf
        Pantheios.bec.fprintf
    )
endif (UNIX)

if (WIN32)

    target_link_libraries(example.cpp.inserter.blob
        Pantheios.be.WindowsConsole
        Pantheios.bec.WindowsConsole
    )
endif (WIN32)

target_compile_options(example.cpp.inserter.blob PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

