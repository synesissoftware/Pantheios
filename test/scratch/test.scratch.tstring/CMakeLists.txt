
add_executable(test.scratch.tstring
	test.scratch.tstring.cpp
)

target_link_libraries(test.scratch.tstring
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(test.scratch.tstring
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(test.scratch.tstring
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
)

target_compile_options(test.scratch.tstring PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

