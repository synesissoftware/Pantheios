
add_executable(test.unit.fe.N
	test.unit.fe.N.c
)

target_link_libraries(test.unit.fe.N
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.fe.N
	PRIVATE
		Pantheios.fe.N
)

target_link_libraries(test.unit.fe.N
	PRIVATE
		STLSoft::STLSoft
		xTests::xTests.core
)

target_compile_options(test.unit.fe.N PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

