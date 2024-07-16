
add_executable(test.unit.util.date_elements_to_string
	test.unit.util.date_elements_to_string.cpp
)

target_link_libraries(test.unit.util.date_elements_to_string
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.util.date_elements_to_string
	PRIVATE
		STLSoft::STLSoft
		shwild::core
		xTests::core
)

target_compile_options(test.unit.util.date_elements_to_string PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

