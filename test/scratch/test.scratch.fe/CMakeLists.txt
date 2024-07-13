
add_executable(test.scratch.fe
	test.scratch.fe.cpp
)

target_link_libraries(test.scratch.fe
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_compile_options(test.scratch.fe PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

