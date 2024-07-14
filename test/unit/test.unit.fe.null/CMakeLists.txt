
add_executable(test.unit.fe.null
	test.unit.fe.null.c
)

target_link_libraries(test.unit.fe.null
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.fe.null
	PRIVATE
		Pantheios.fe.null
)

target_link_libraries(test.unit.fe.null
	PRIVATE
		STLSoft::STLSoft
		xTests::core
)

target_compile_options(test.unit.fe.null PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

