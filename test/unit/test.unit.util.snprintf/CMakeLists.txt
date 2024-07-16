
add_executable(test.unit.util.snprintf
	test.unit.util.snprintf.cpp
)

target_link_libraries(test.unit.util.snprintf
	PRIVATE
		Pantheios.util
)

target_link_libraries(test.unit.util.snprintf
	PRIVATE
		STLSoft::STLSoft
		xTests::core
)

target_compile_options(test.unit.util.snprintf PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ############################## end of file ############################# #

