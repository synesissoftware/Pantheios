
add_executable(test.unit.levels.values
	test.unit.levels.values.c
)

target_link_libraries(test.unit.levels.values
	Pantheios.util
)

target_link_libraries(test.unit.levels.values
	xTests::xTests.core
)

target_compile_options(test.unit.levels.values PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

