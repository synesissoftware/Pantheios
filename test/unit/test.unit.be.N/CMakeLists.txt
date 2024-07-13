
add_executable(test.unit.be.N
	test.unit.be.N.c
)

target_link_libraries(test.unit.be.N
	Pantheios.util
)

target_link_libraries(test.unit.be.N
	Pantheios.fe.simple
)

target_link_libraries(test.unit.be.N
	Pantheios.be.N
)

target_link_libraries(test.unit.be.N
	xTests::xTests.core
)

target_compile_options(test.unit.be.N PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-null-pointer-arithmetic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

