
add_executable(example.cpp.util.strdup
	example.cpp.util.strdup.cpp
)

target_link_libraries(example.cpp.util.strdup
	PRIVATE
		Pantheios.util
)

target_link_libraries(example.cpp.util.strdup
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(example.cpp.util.strdup PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

