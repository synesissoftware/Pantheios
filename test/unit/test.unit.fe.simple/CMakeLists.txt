
add_executable(test.unit.fe.simple
	test.unit.fe.simple.c
)

target_link_libraries(test.unit.fe.simple
	PRIVATE
		Pantheios.fe.simple
)

target_link_libraries(test.unit.fe.simple
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.fe.simple
	PRIVATE
		STLSoft::STLSoft
		xTests::core
)

target_compile_options(test.unit.fe.simple PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

