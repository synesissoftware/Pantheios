
add_executable(test.unit.bec.fail
	test.unit.bec.fail.c
)

target_link_libraries(test.unit.bec.fail
	PRIVATE
		Pantheios.bec.fail
)

target_link_libraries(test.unit.bec.fail
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.bec.fail
	PRIVATE
		STLSoft::STLSoft
		xTests::core
)

target_compile_options(test.unit.bec.fail PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

