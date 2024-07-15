
add_executable(test.unit.fe.fail
	test.unit.fe.fail.c
)

target_link_libraries(test.unit.fe.fail
	PRIVATE
		Pantheios.fe.fail
)

target_link_libraries(test.unit.fe.fail
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.fe.fail
	PRIVATE
		STLSoft::STLSoft
		xTests::core
)

target_compile_options(test.unit.fe.fail PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

