
add_executable(test.unit.levels.2
	test.unit.levels.2.cpp
)

target_link_libraries(test.unit.levels.2
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.levels.2
	PRIVATE
		xTests::xTests.core
)

target_compile_options(test.unit.levels.2 PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

