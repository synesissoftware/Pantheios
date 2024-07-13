
add_executable(test.scratch.showPlus.integer
	test.scratch.showPlus.integer.cpp
)

target_link_libraries(test.scratch.showPlus.integer
	PRIVATE
		Pantheios.util
		Pantheios.core
)

target_link_libraries(test.scratch.showPlus.integer
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(test.scratch.showPlus.integer
	PRIVATE
		Pantheios.be.fprintf
		Pantheios.bec.fprintf
)

target_link_libraries(test.scratch.showPlus.integer
	PRIVATE
		STLSoft::STLSoft
)

target_compile_options(test.scratch.showPlus.integer PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

