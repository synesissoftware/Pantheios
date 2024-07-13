
add_executable(test.scratch.trace
	test.scratch.trace.cpp
)

target_link_libraries(test.scratch.trace
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(test.scratch.trace
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(test.scratch.trace
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
)

target_link_libraries(test.scratch.trace
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(test.scratch.trace PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

