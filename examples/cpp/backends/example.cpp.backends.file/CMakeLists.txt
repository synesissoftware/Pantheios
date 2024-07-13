
add_executable(example.cpp.backends.file
	example.cpp.backends.file.cpp
)

target_link_libraries(example.cpp.backends.file
	Pantheios.util
	Pantheios.core
)

target_link_libraries(example.cpp.backends.file
	Pantheios.fe.simple
)

target_link_libraries(example.cpp.backends.file
	Pantheios.be.file
	Pantheios.bec.file
)

target_compile_options(example.cpp.backends.file PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)


# ############################## end of file ############################# #

