
add_executable(example.cpp.backends.callback
	example.cpp.backends.callback.cpp
)

target_link_libraries(example.cpp.backends.callback
	Pantheios.util
	Pantheios.core
)

target_link_libraries(example.cpp.backends.callback
	Pantheios.fe.simple
)

if (UNIX)

	target_link_libraries(example.cpp.backends.callback
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
	)
endif (UNIX)

if (WIN32)

	target_link_libraries(example.cpp.backends.callback
		Pantheios.be.WindowsConsole
		Pantheios.bec.WindowsConsole
	)
endif (WIN32)

target_compile_options(example.cpp.backends.callback PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

