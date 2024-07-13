
add_executable(test.unit.levels.dynamic_initialisation
	test.unit.levels.dynamic_initialisation.cpp
)

target_link_libraries(test.unit.levels.dynamic_initialisation
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.levels.dynamic_initialisation
	PRIVATE
		STLSoft::STLSoft
		xTests::xTests.core
)

target_compile_options(test.unit.levels.dynamic_initialisation PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

